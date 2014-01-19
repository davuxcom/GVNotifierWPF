using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using DavuxLib2.Extensions;
using System.Windows.Threading;
using System.Threading;
using System.Text.RegularExpressions;
using System.Diagnostics;
using Microsoft.WindowsAPICodePack.Taskbar;
using System.Windows.Interop;
using DavuxLib2;


namespace GVNotifier
{
    /// <summary>
    /// Interaction logic for MessageWindow.xaml
    /// </summary>
    public partial class MessageWindow : Window
    {
        public GoogleVoice.Contact Contact = null;

        public bool Ready = false;

        static event Action OnZoomChanged;

        public MessageWindow(GoogleVoice.Contact Contact)
        {
            InitializeComponent();
            this.Contact = Contact;
            Title = Contact.Name;
            Tag = Contact.Name + Contact.ID;

            System.Windows.Forms.Application.EnableVisualStyles();
            
            // FIXME: maybe windows should start minimzed normally.
            ContentRendered += (s, e) => this.Topmost = false;
            Initialized += (s, e) => this.Topmost = true;

            OnZoomChanged += () => this.Invoke(() => SetHTMLFont());

            PreviewMouseDown += (ss, ee) => 
                {
                    this.Try(() => ClearNotify());
                };

            Loaded += (_, __) =>
                {
                    // 5/5/12: Open links in default browser
                    ((SHDocVw.DWebBrowserEvents2_Event)web.ActiveXInstance).NewWindow3 += web_NewWindow3;
                };
        }

        private void web_NewWindow3(ref object ppDisp, ref bool Cancel, uint dwFlags, string bstrUrlContext, string bstrUrl)
        {
            ProcessStartInfo psi = new ProcessStartInfo();

            psi.FileName = bstrUrl;
            psi.UseShellExecute = true;

            if (bstrUrl.StartsWith("http://") ||
                bstrUrl.StartsWith("https://"))
            {
                try
                {
                    Process.Start(bstrUrl);
                }
                catch (Exception wex)
                {
                    Trace.WriteLine(wex);
                    // MessageBox.Show(wex.Message, this.Title, MessageBoxButton.OK, MessageBoxImage.Error);
                }
                finally
                {
                    Cancel = true;
                }
            }
            else
            {
                Trace.WriteLine("URL is not valid: " + bstrUrl);
            }
        }


        public void AddMessage(GoogleVoice.Message msg)
        {
            this.Invoke(() =>
            {
                foreach (var item in cboNumbers.Items)
                {
                    GoogleVoice.Phone ph = item as GoogleVoice.Phone;
                    if (ph != null)
                    {
                        if (ph.Number == msg.Number)
                        {
                            cboNumbers.SelectedItem = item;
                            lblNumber.Content = cboNumbers.Text;
                            return;
                        }
                    }
                }
            });
            bool did_add = false;
            GoogleVoice.SMS sms = msg as GoogleVoice.SMS;
            if (sms != null)
            {
                if (!sms.Self)
                {
                    AddMessage(Contact.Name, sms.Text);
                    did_add = true;
                }
            }
            else
            {
                switch (msg.Class)
                {
                    case GoogleVoice.Message.MessageType.Missed:
                        if (Settings.Get("ShowMissedCall", false))
                        {
                            AddMessage(Contact.Name, "<strong>Missed Call</strong>");
                            did_add = true;
                        }
                        break;
                    case GoogleVoice.Message.MessageType.Placed:
                        if (Settings.Get("ShowPlacedCall", false))
                        {
                            AddMessage(Contact.Name, "<strong>Placed Call</strong>");
                            did_add = true;
                        }
                        break;
                    case GoogleVoice.Message.MessageType.Received:
                        if (Settings.Get("ShowAcceptedCall", false))
                        {
                            AddMessage(Contact.Name, "<strong>Received Call</strong>");
                            did_add = true;
                        }
                        break;
                    default:
                        AddMessage(Contact.Name, "<strong>" + msg.Class + "</strong>: " + msg.MessageText);
                        did_add = true;
                        break;
                }

            }
            if (did_add)
            {
                if (WindowState != System.Windows.WindowState.Minimized)
                    Show();
            }
        }

        private void Window_SourceInitialized(object sender, EventArgs e)
        {
           // DavuxLib2.Platform.DwmApi.DwmExtendFrameIntoClientArea (this, new Thickness(0, 0, 0, 26 * this.GetDPI()));

            web.AllowWebBrowserDrop = false;
            
            web.Navigated += (ee, ss) =>
            {
                //web.Document.Body.InnerHtml = "<span style='font-family: " + Settings.Get("ViewFontFamily", "Verdana") + "; font-size: " + Settings.Get("ViewFontSize", 10) + "pt;'>";
                SetHTMLFont();
            };
            web.Navigate("about:blank");
            web.Document.ContextMenuShowing += (ss, ee) =>
                {
                    //web.ContextMenu.Show(web, ee.ClientMousePosition);
                    ContextMenu menu = new System.Windows.Controls.ContextMenu();
                    MenuItem mp = new MenuItem();
                    mp.Header = "Copy";
                    mp.Click += (sss, eee) => this.Try(() => web.Document.ExecCommand("Copy", false, null));
                    menu.Items.Add(mp);
                    mp = new MenuItem();
                    mp.Header = "Select All";
                    mp.Click += (sss, eee) => this.Try(() => web.Document.ExecCommand("SelectAll", false, null));
                    menu.Items.Add(mp);
                    menu.Items.Add(new Separator());
                    mp = new MenuItem();
                    mp.Header = "Increase Font Size";
                    mp.Click += (sss, eee) => ZoomIn();
                    menu.Items.Add(mp);

                    mp = new MenuItem();
                    mp.Header = "Decrease Font Size";
                    mp.Click += (sss, eee) => ZoomOut();
                    menu.Items.Add(mp);

                    menu.Placement = System.Windows.Controls.Primitives.PlacementMode.MousePoint;
                    menu.IsOpen = true;
                    ee.ReturnValue = false;
                };


            foreach (var p in Contact.Phones) cboNumbers.Items.Add(p);

            // NOTE (4/26/11): no longer block 406 numbers:
            //    if (!Regex.IsMatch(p.Number, ".*?406\\d{3}\\d{4}"))
                    



            lblNumber.Content = cboNumbers.Text = cboNumbers.Items[0].ToString();
            PopulateStatusBar();

            if (Contact.Note != null)
                txtInput.IsEnabled = !Contact.Note.ToLower().Contains("nosms");

            Ready = true;

            // so we get messages to WndProc
            HwndSource src = HwndSource.FromHwnd(new WindowInteropHelper(this).Handle);
            src.AddHook(new HwndSourceHook(WndProc));
        }

        public IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
        {
            /*
            if (msg == 0x031E)  // WM_DWMCOMPOSITIONCHANGED 
            {
                DavuxLib2.Platform.DwmApi.DwmExtendFrameIntoClientArea(this, new Thickness(0, 0, 0, 26 * this.GetDPI()));
            }
            */
            return IntPtr.Zero;
        }

        void PopulateStatusBar()
        {
            this.InvokeDelay(1000 * 10, () => PopulateStatusBar());

            var msg = SessionModel.Inst.All.FirstOrDefault(m => m.Contact == Contact);
            if (msg == null) return;

            grdTopColor.Visibility = System.Windows.Visibility.Visible;
            switch(msg.MessageType)
                {
                    case GoogleVoice.Message.MessageType.Missed:
                        lblTop.Content = "Missed Call:  " + msg.Time.ToTimeAgo();
                        grdTopColor.Background = Brushes.DarkRed;
                        break;
                    case GoogleVoice.Message.MessageType.Placed:
                        lblTop.Content = "You Called:  " + msg.Time.ToTimeAgo();
                        grdTopColor.Background = Brushes.LimeGreen;
                        break;
                    case GoogleVoice.Message.MessageType.Received:
                        lblTop.Content = "Received Call:  " + msg.Time.ToTimeAgo();
                        grdTopColor.Background = Brushes.LimeGreen;
                        break;
                    case GoogleVoice.Message.MessageType.Voicemail:
                        lblTop.Content = "Voicemail:  " + msg.Time.ToTimeAgo();
                        grdTopColor.Background = Brushes.DarkBlue;
                        break;
                }
        }

        void ScrollDown()
        {
            try
            {
                if (web.Document != null && web.Document.Body != null)
                {
                    web.Document.Body.ScrollTop = 110000;
                }
            }
            catch (Exception) { }
        }

        int isLastSenderMe = 0;
        private void AddLocalMessage(string msg)
        {
            // inject skin

            if (isLastSenderMe != 1)
            {
                // print header
                AppendMessage("<strong>Me</strong><br />");
            }

            if (string.IsNullOrEmpty(msg))
            {
                msg = "(Empty Message)";
            }

            AppendMessage(time(DateTime.Now.ToShortTimeString()) + msg.Replace("\n", "<br />") + "<br />");
            isLastSenderMe = 1;
        }

        public void AddMessage(string name, string msg)
        {
            if (isLastSenderMe != 2)
            {
                // print header
                AppendMessage("<strong><span style='color: darkblue'>" + name + "</span></strong><br />");
            }
            // skin injection
            AppendMessage(time(DateTime.Now.ToShortTimeString()) + msg + "<br />");
            isLastSenderMe = 2;

            this.Invoke(() =>
            {
                if (Settings.Get("FlashWindow", false))
                {
                    DavuxLib2.Platform.FlashWindow.Flash(this);
                }
                if (Settings.Get("PlaySound", false))
                {
                    try
                    {
                        System.Media.SoundPlayer s = new System.Media.SoundPlayer(DavuxLib2.App.DataDirectory + @"\new.wav");
                        s.Play();
                    }
                    catch (Exception ex)
                    {
                        Trace.WriteLine("Error Playing Audio: " + ex);
                    }
                }
                if (!IsFocused) SetNotify();
            });
        }

        Thread notifyThread = null;
        int notifyTimes = 0;
        void SetNotify()
        {
            if (Settings.Get("SoundRepeat", false))
            {
                notifyTimes = Settings.Get("SoundRepeeatNumber", 0);
                if (notifyThread == null)
                {
                    notifyThread = new Thread(() =>
                    {
                        int sleepInt = Settings.Get("SoundRepeatDuration", 1);
                        if (sleepInt <= 0) sleepInt = 1;
                        while (notifyTimes > 0)
                        {
                            Thread.Sleep(1000 * 60 * sleepInt);
                            try
                            {
                                notifyTimes--;
                                System.Media.SoundPlayer s = new System.Media.SoundPlayer(DavuxLib2.App.DataDirectory + @"\new.wav");
                                s.Play();
                            }
                            catch (ThreadAbortException)
                            {
                                // no need to log this, since it will happen
                                // on ClearNotify (user interaction)
                                return;
                            }
                            catch (Exception ex)
                            {
                                Trace.WriteLine("Error Playing Audio: " + ex);
                            }
                        }
                        notifyThread = null;
                    });
                    notifyThread.Start();
                }
            }
        }

        void ClearNotify()
        {
            if (notifyThread != null)
            {
                try
                {
                    notifyThread.Abort();
                }
                catch (Exception) { }
                finally
                {
                    notifyThread = null;
                }
            }
            notifyTimes = 0;
        }


        private string time(string t)
        {
            return "<span style='color: gray'>" + t + "</span>&nbsp;&nbsp;&nbsp;";
        }

        private string ConvertUrlsToLinks(string msg)
        {
            string regex = @"((www\.|(http|https|ftp|news|file)+\:\/\/)[&#95;.a-z0-9-]+\.[a-z0-9\/&#95;:@=.+?,##%&~-]*[^.|\'|\# |!|\(|?|,| |>|<|;|\)])";
            Regex r = new Regex(regex, RegexOptions.IgnoreCase);
            return r.Replace(msg, "<a href=\"$1\" title=\"Click to open in a new window or tab\" target=\"&#95;blank\">$1</a>").Replace("href=\"www", "href=\"http://www");
        }

        private void AppendMessage(string msg)
        {
            msg = ConvertUrlsToLinks(msg);
            //msg = "<span style='font-family: " + Settings.Get("ViewFontFamily", "Verdana") + "; font-size: " + Settings.Get("ViewFontSize", 10) + "pt;'>" + msg + "</span>";
            this.Invoke( () =>
            {
                web.Document.Body.InnerHtml += msg;
            });

            // TODO: remove this, do it in javascript
            this.InvokeDelay(200, () => ScrollDown());
        }

        bool update_ip = false;
        private void txtInput_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter &&
                 (Keyboard.Modifiers == ModifierKeys.Control ||
                 Keyboard.Modifiers == ModifierKeys.Shift))
            {
                // do nothing to insert newline
            }
            else if (e.Key == Key.Enter)
            {
                btnSend_Click(null, null);
            }
            else if (e.Key == Key.N && Keyboard.Modifiers == ModifierKeys.Control)
            {
                // clear
                web.Document.Body.InnerHtml = ""; // "<span style='font-family: " + Settings.Get("ViewFontFamily", "Verdana") + "; font-size: " + Settings.Get("ViewFontSize", 10) + "pt;'><script>function clear() { document.body.innerHTML = ''; }</script>";
                isLastSenderMe = 0;
            }
            else if (e.Key == Key.T && Keyboard.Modifiers == ModifierKeys.Control)
            {
                AddMessage("Test Name", "This is a test message for use in development and testing of GVNotifier.");
            }
            else if (e.Key == Key.R && Keyboard.Modifiers == ModifierKeys.Control)
            {
                // TODO switch to async pattern
                if (!update_ip)
                {
                    update_ip = true;
                    new Thread(() =>
                        {
                            Trace.WriteLine("Updating Account...");
                            SessionModel.Inst.account.Update();
                            Trace.WriteLine("Update Complete");
                            update_ip = false;
                        }).Start();
                }
            }
            else if (e.Key == Key.Escape)
            {
                Hide();
            }

            ClearNotify();
        }

        private void txtInput_TextChanged(object sender, TextChangedEventArgs e)
        {
            int v = txtInput.Text.Length;
            
            if (v < 140)
                pgrSMS.Foreground = Brushes.Green;
            else if (v <= 160)
                pgrSMS.Foreground = Brushes.Yellow;
            else
                pgrSMS.Foreground = Brushes.Red;

            pgrSMS.Visibility = v > 0 ? System.Windows.Visibility.Visible : System.Windows.Visibility.Collapsed;

            int num_additional_messages = v / 160;
            if (num_additional_messages > 0)
            {
                v -= 160 * num_additional_messages;
            }

            pgrSMS.Value = v;
            string msg = num_additional_messages == 0 ?
                v.ToString() : num_additional_messages + "+" + v;

            btnSend.IsEnabled = txtInput.Text.Length > 0;
            btnSend.Content = txtInput.Text.Length == 0 ? "Send" : "Send (" + msg + ")";
        }

        private void Label_MouseEnter(object sender, MouseEventArgs e)
        {
            if (cboNumbers.Items.Count > 1)
            {
                lblNumber.Visibility = System.Windows.Visibility.Hidden;
                cboNumbers.Visibility = System.Windows.Visibility.Visible;
            }
        }

        private void cboNumbers_MouseLeave(object sender, MouseEventArgs e)
        {
            lblNumber.Visibility = System.Windows.Visibility.Visible;
            cboNumbers.Visibility = System.Windows.Visibility.Hidden;
            lblNumber.Content = cboNumbers.Text;
        }

        private void btnSend_Click(object sender, RoutedEventArgs e)
        {
            // TODO ok how is this situation even possible?
            if (!btnSend.IsEnabled) return;

            string msg = txtInput.Text.Trim();

            // TODO same with this one
            if (string.IsNullOrEmpty(msg)) return;

            var ph = cboNumbers.SelectedItem as GoogleVoice.Phone;

            txtInput.IsEnabled = false;

            new Thread(() =>
            {
                try
                {
                    SessionModel.Inst.account.SendSMS(ph.Number, msg);
                    this.Invoke(() => 
                    {
                        btnSend.IsEnabled = true;
                        txtInput.Text = "";
                        txtInput.IsEnabled = true;
                        txtInput.Focus();
                        AddLocalMessage(msg);
                    });
                }
                catch (Exception ex)
                {
                    Trace.WriteLine("Send Error: " + ex);
                    this.Invoke(() => 
                    {
                        btnSend.IsEnabled = true;
                        txtInput.IsEnabled = true;
                        btnSend.Content = "Retry Send";
                        txtInput.Focus();
                    });
                }
            }).Start();
        }

        private void Window_Activated(object sender, EventArgs e)
        {
            txtInput.Focus();
            ClearNotify();
        }

        private void btnCall_Click(object sender, RoutedEventArgs e)
        {
            Button b = sender as Button;

            b.ContextMenu = new System.Windows.Controls.ContextMenu();

            foreach (var p in SessionModel.Inst.account.ForwardingPhones)
            {
                MenuItem mp = new MenuItem();
                mp.Header = "Call using " + p.ToString();
                mp.Tag = p;
                mp.Click += new RoutedEventHandler(mp_Click);
                b.ContextMenu.Items.Add(mp);
            }

            MenuItem mx = new MenuItem();
            mx.Header = "Cancel Call";
            mx.Tag = null;
            mx.Click += new RoutedEventHandler(mp_Click);
            b.ContextMenu.Items.Add(mx);

            b.ContextMenu.PlacementTarget = b;
            b.ContextMenu.Placement = System.Windows.Controls.Primitives.PlacementMode.Bottom;
            ContextMenuService.SetPlacement(b, System.Windows.Controls.Primitives.PlacementMode.Bottom);
            b.ContextMenu.IsOpen = true;
        }

        // TODO terrible name
        void mp_Click(object sender, RoutedEventArgs e)
        {
            var ph = cboNumbers.SelectedItem as GoogleVoice.Phone;
            MenuItem mi = sender as MenuItem;
            var phone = mi.Tag as GoogleVoice.ForwardingPhone;
            new Thread(() =>
            {
                try
                {
                    if (phone == null)
                    {
                        SessionModel.Inst.account.CancelCall();
                        AddLocalMessage("<strong>Canceled Call</strong>");
                    }
                    else
                    {
                        SessionModel.Inst.account.Call(ph.Number, phone);
                        AddLocalMessage("Calling <strong>" + ph.Number + "</strong> from " + phone.Label);
                    }
                }
                catch (Exception ex)
                {
                    AddLocalMessage("Error attempting call action: " + ex.Message);
                }
            }).Start();
        }

        private void Window_MouseLeave(object sender, MouseEventArgs e)
        {
            lblNumber.Visibility = System.Windows.Visibility.Visible;
            cboNumbers.Visibility = System.Windows.Visibility.Hidden;
            lblNumber.Content = cboNumbers.Text;
        }

        private void txtInput_MouseEnter(object sender, MouseEventArgs e)
        {
            lblNumber.Visibility = System.Windows.Visibility.Visible;
            cboNumbers.Visibility = System.Windows.Visibility.Hidden;
            lblNumber.Content = cboNumbers.Text;
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            e.Cancel = true;

            // seriously what the heck is this?

            //Hide();
            Application.Current.Dispatcher.BeginInvoke(DispatcherPriority.Background, (DispatcherOperationCallback)delegate(object o)
            {
                this.Try(() => Hide());
                return null;
            }, null);
            ClearNotify();
        }

        private void Window_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            // TODO is thie the only call needed?
            if (e.Key == Key.Escape)
            {
                Hide();
            }
            webHost_PreviewKeyDown(sender, e);
        }

        // oh wow, this was neat!
        private void lblTop_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            Label b = sender as Label;

            b.ContextMenu = new System.Windows.Controls.ContextMenu();

            foreach (var p in SessionModel.Inst.All.Where(m => m.Contact == Contact).Take(20))
            {
                MenuItem mp = new MenuItem();
                mp.Header = p.MessageType.ToString() + " " + p.Time.ToTimeAgo();
                mp.Tag = p;

                b.ContextMenu.Items.Add(mp);
            }

            b.ContextMenu.PlacementTarget = b;
            b.ContextMenu.Placement = System.Windows.Controls.Primitives.PlacementMode.Bottom;
            ContextMenuService.SetPlacement(b, System.Windows.Controls.Primitives.PlacementMode.Bottom);
            b.ContextMenu.IsOpen = true;
        }

        private void webHost_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            if ((e.Key == Key.Add || e.Key == Key.OemPlus) && Keyboard.Modifiers == ModifierKeys.Control)
            {
                ZoomIn();
            }
            else if ((e.Key == Key.Subtract || e.Key == Key.OemMinus) && Keyboard.Modifiers == ModifierKeys.Control)
            {
                ZoomOut();
            }
            ClearNotify();
        }

        private void ZoomIn()
        {
            Trace.WriteLine("Zoom In");
            int size = Settings.Get("ViewFontSize", 10);
            Settings.Set("ViewFontSize", ++size);
            SetHTMLFont();
            OnZoomChanged();
        }

        private void ZoomOut()
        {
            Trace.WriteLine("Zoom Out");
            int size = Settings.Get("ViewFontSize", 10);
            Settings.Set("ViewFontSize", --size);
            SetHTMLFont();
            OnZoomChanged();
        }

        private void SetHTMLFont()
        {
            if (Settings.Get("ViewFontSize", 14) < 10)
            {
                Settings.Set("ViewFontSize", 10);
            }
            web.Document.Body.Style = "font-family: " + Settings.Get("ViewFontFamily", "Segoe UI, Verdana") + "; font-size: " + Settings.Get("ViewFontSize", 10) + "px;";
            Trace.WriteLine("font-family: " + Settings.Get("ViewFontFamily", "Segoe UI, Verdana") + "; font-size: " + Settings.Get("ViewFontSize", 10) + "px;");
            Trace.WriteLine(web.Document.Body.Style);

            int size = Settings.Get("ViewFontSize", 14);
            txtInput.FontSize = size / this.GetDPI(); // (size / (96 / (96 * this.GetDPI()))); 
        }

        private void Window_GotFocus(object sender, RoutedEventArgs e)
        {
            // TODO this and activated and typeing and more?
            ClearNotify();
        }
    }

    
}
