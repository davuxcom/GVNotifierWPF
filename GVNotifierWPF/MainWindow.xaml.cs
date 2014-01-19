using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using Microsoft.WindowsAPICodePack.Taskbar;
using DavuxLib2.Extensions;
using DavuxLib2;

namespace GVNotifier
{
    public partial class MainWindow : Window
    {
        private SessionModel model = null;
        private TaskbarManager windowsTaskbar = null;
        private List<GoogleVoice.Contact> FavJumpListContacts = new List<GoogleVoice.Contact>();
        private List<MessageWindow> Windows = new List<MessageWindow>();
        private ListView SelectedView = null;

        #region Window Events

        public MainWindow()
        {
            InitializeComponent();
            // TODO what the hell does this Tag do?
            Tag = "Main";

            Application.Current.DispatcherUnhandledException += new DispatcherUnhandledExceptionEventHandler(Current_DispatcherUnhandledException);
            AppDomain.CurrentDomain.UnhandledException += new UnhandledExceptionEventHandler(CurrentDomain_UnhandledException);
        }

        private void Window_Closing(object sender, CancelEventArgs e)
        {
            // TODO the sender != null call here has to do with ExitWindows(), but I'm not sure on the 
            // details.  I guess there is no sender if Windows asks us to quit.
            // I got reports about GVNotifier blocking shutdown, so definitely don't want to mess this up!
            if (sender != null && Settings.Get("ShowTrayIcon", false))
            {
                e.Cancel = true;

                this.Invoke(() => this.Try(() => Hide()));
            }
            else
            {
                if (model != null) model.Save();

                foreach (var w in Windows.ToArray())
                {
                    this.Try(() => w.Close());
                }

                ClearJumpList();

                // TODO is this really what we want to do?
                // it might be impossible to ensure without a doubt that all threads have quit
                // (even with a better controlled threading model) - so maybe as a last resort 
                // this is okay.
                new Thread(() => { Thread.Sleep(1500); Environment.Exit(0); }).Start();
            }
        }

        private void Window_ContentRendered(object sender, EventArgs e)
        {
            this.Try(() => {
                    // NOTE!  When we depoy with ClickOnce, we will be assigned an AppID!
                    // do NOT attempt to set one manually, because it will break and cause a LOT
                    // of confusion!
                    // TaskbarManager.Instance.ApplicationId = "GVNotifier.1";
                    windowsTaskbar = TaskbarManager.Instance;
                    Debug.WriteLine("AppUserModelID: " + windowsTaskbar.ApplicationId);
                });
            try
            {
                ResetJumpList();

                if (chkAutoLogin.IsChecked == true && txtPassword.Password != string.Empty)
                {
                    btnLogin_Click(null, null);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine("Content rendering: " + ex);
            }
        }

        private void Window_SourceInitialized(object sender, EventArgs e)
        {
            try
            {
                //DavuxLib2.Platform.DwmApi.DwmExtendFrameIntoClientArea (this, new Thickness(0, gLoginTop.ActualHeight * this.GetDPI(), 0, 0));

                SessionModel.AppClosing += () => this.Invoke(() => Window_Closing(null, null));
                SessionModel.PrefsRequest += () => this.Invoke(() =>
                {
                    Preferences p = new Preferences();
                    p.Show();
                    p.Activate();
                });
                SessionModel.AboutRequest += () => this.Invoke(() =>
                {
                    var p = new About();
                    p.Show();
                    p.Activate();
                });
                SessionModel.ShowRequest += () => this.InvokeDelay(200, () =>
                {
                    // TODO this is another instance that might crash on Windows XP?
                    this.Try( () => ShowActivated = true);
                    Show();
                    Activate();
                    Topmost = true;
                    this.InvokeDelay(200, () => Topmost = false);
                });

                vm_init();
            }

            catch (Exception ex)
            {
                Debug.WriteLine("MainWindow_SourceInitialized: " + ex);
            }
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            try
            {
                GoogleVoice.Contact.MaxIconSize = Settings.Get("SmallIcons", false) == true ? 16 : 32;
                txtUserName.Text = Settings.Get("UserName", "");
                txtPassword.Password = Settings.GetSecure("Password", "", SessionModel.KEY).ToStringUnSecure();
                chkAutoLogin.IsChecked = Settings.Get("AutoLogin", false);
                chkSave.IsChecked = Settings.Get("SavePassword", false);
                lsvNameCol.Width = 300;
            }
            catch (Exception ex)
            {
                Trace.Write("MainWindow_Loaded: " + ex);
            }

            HwndSource src = HwndSource.FromHwnd(new WindowInteropHelper(this).Handle); 
            src.AddHook(new HwndSourceHook(WndProc));
        }

        public IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
        {
            /*
            const int WM_DWMNCRENDERINGCHANGED = 0x031E;
            if (msg == WM_DWMNCRENDERINGCHANGED)
            {
                DavuxLib2.Platform.DwmApi.DwmExtendFrameIntoClientArea(this, new Thickness(0, gLoginTop.ActualHeight * this.GetDPI(), 0, 1 + (bottomPanel.ActualHeight * this.GetDPI())));
            }
            */
            return IntPtr.Zero;
        }

        #endregion

        public MessageWindow WindowForContact(GoogleVoice.Contact contact)
        {
            try
            {
                var win = Windows.FirstOrDefault(c => c.Contact == contact);
                if (win != null) return win;

                win = Windows.FirstOrDefault(c => c.Contact.HasNumber(contact.Phones[0].Number));
                if (win != null) return win;

                win = new MessageWindow(contact);
                Windows.Add(win);
                return win;
            }
            catch (Exception ex)
            {
                Debug.WriteLine("Main/WindowForContact *** " + ex);
                return null;
            }
        }

        void ConfigureListView()
        {
            CollectionView myView = (CollectionView)CollectionViewSource.GetDefaultView(lsvContacts.ItemsSource);
            PropertyGroupDescription groupDescription = new PropertyGroupDescription("Group");
            myView.GroupDescriptions.Add(groupDescription);
            SortDescription sg = new SortDescription("Group", ListSortDirection.Ascending);
            SortDescription sd = new SortDescription("Name", ListSortDirection.Ascending);
            myView.SortDescriptions.Add(sg);
            myView.SortDescriptions.Add(sd);
        }

        private void btnLogin_Click(object sender, RoutedEventArgs e)
        {
            this.FadeToTransparent (grdLoginInfo.Name);
            this.FadeToOpaque(lblStatus.Name);

            Settings.Set("SavePassword", chkSave.IsChecked == true);
            Settings.Set("AutoLogin", chkAutoLogin.IsChecked == true);
            if ((bool)chkSave.IsChecked) Settings.SetSecure("Password", txtPassword.Password.ToSecureString(), SessionModel.KEY);
            Settings.Set("UserName", txtUserName.Text);
            Settings.Save();
            
            this.Try (() => windowsTaskbar.SetProgressState(TaskbarProgressBarState.Indeterminate));

            model = new SessionModel(txtUserName.Text, txtPassword.Password);
            
            model.OnLoginFailure += () =>
            {
                this.Invoke(() =>
                    {
                        this.FadeToTransparent(lblStatus.Name);
                        this.FadeToOpaque(grdLoginInfo.Name);
                        windowsTaskbar.SetProgressState(TaskbarProgressBarState.NoProgress);
                        // gpLoginBox.Header = "Invalid Username or Password";
                    });
            };
            model.OnLoginSuccess += () =>
            {
                this.Invoke(() =>
                {
                    Settings.Set("LoginCount", Settings.Get("LoginCount", 1) + 1);
                    int loginCount = Settings.Get("LoginCount", 0);
                    Debug.WriteLine("Login Count: " + loginCount);

                    if (loginCount > 5)
                    {
                        if (!Settings.Get("donate14", false))
                        {
                            Debug.WriteLine("Welcome Open");
                            Welcome w = new Welcome();
                            w.Show();
                        }
                    }

                    Title = "GVNotifier";
                    LoggedInPage.Visibility = System.Windows.Visibility.Visible;
                    LoginPage.Visibility = System.Windows.Visibility.Hidden;
                    this.FadeToTransparent(LoginPage.Name);
                    this.FadeToOpaque(LoggedInPage.Name);
                    txtSearch.Focus();

                    lsvContacts.ItemsSource = model.Contacts;
                    ConfigureListView();
                    SyncContactsJumpList();

                    this.Try(() => windowsTaskbar.SetProgressState(TaskbarProgressBarState.Normal));

                    SelectedView = lsvContacts;
                    //DavuxLib2.Platform.DwmApi.DwmExtendFrameIntoClientArea(this, new Thickness(0, gLoginTop.ActualHeight * this.GetDPI(), 0, 1 + (bottomPanel.ActualHeight * this.GetDPI())));

                    model.account.Ready += () => this.Invoke(() => FitColumn(lsvVM, lsvNameColVM));
                });
            };
            model.OnLoginMessage += (s) =>
            {
                this.Invoke(() => lblStatus.Text = s);
            };

            model.account.ContactsManager.ContactsLoadingUpdate += (v, max) =>
            {
                if (windowsTaskbar != null)
                {
                    this.Try(() => windowsTaskbar.SetProgressState(TaskbarProgressBarState.Normal));
                    this.Invoke(() => TaskbarManager.Instance.SetProgressValue(v, max));
                }
            };

            model.Login();

            model.OnMessage += new Action<GoogleVoice.Message,GoogleVoice.Contact>(model_OnMessage);
            model.OnContactsUpdated += () =>
            {
                this.Invoke(() => 
                {
                    if (windowsTaskbar != null)
                    {
                        this.Try(() => windowsTaskbar.SetProgressState(TaskbarProgressBarState.NoProgress));
                    }
                        Debug.WriteLine("Reloading Contacts View");
                    ResizeGridViewColumn(lsvNameCol);
                    SyncContactsJumpList();
                });
            };

            lblStatus.Text = "Waiting...";
            lblStatus.Visibility = System.Windows.Visibility.Visible;
            // gpLoginBox.Header = "";

            // TODO still not right for loading a window above
            model.OnJumpListContact += (c) =>
            {
                this.Invoke(() =>
                {
                    var mw = WindowForContact(c);
                    mw.Show();
                    this.InvokeDelay(100, () =>
                    {
                        mw.Activate();
                        mw.Focus();
                    });
                });
            };
        }

        private void DoHide()
        {
            if (SessionModel.Inst != null)
            {
                if (Settings.Get("ShowTrayIcon", false))
                {
                    Hide();
                }
                else
                {
                    WindowState = System.Windows.WindowState.Minimized;
                }
                txtSearch.Text = "";
            }
        }

        void SyncContactsJumpList()
        {
            
            foreach (var c in model.Contacts.ToArray())
            {
                if (c.Group == "Favorites")
                    if (!FavJumpListContacts.Contains(c))
                        FavJumpListContacts.Add(c);

                if (c.Group != "Favorites" && FavJumpListContacts.Contains(c))
                    FavJumpListContacts.Remove(c);
            }

            try
            {
                JumpList jumpList = JumpList.CreateJumpList();
                jumpList.JumpListItemsRemoved += (ss, ee) =>
                {
                    // NOTE:  You must call this to ensure that the developer respects user choice.
                    // There is a lot of painful irony that I'm not handling it, so...
                    // TODO let's actually handle this. :)
                };
                foreach (var x in jumpList.RemovedDestinations)
                {
                    // NOTE: see note above.
                }

                OnlineJumpList(ref jumpList);
                OfflineJumpList(ref jumpList);
                jumpList.Refresh();
            }
            catch (Exception ex)
            {
                Trace.Write("JumpList Error: " + ex);
            }
        }

        private void OnlineJumpList(ref JumpList jumpList)
        {
            var f = new JumpListCustomCategory("Favorite Contacts");
            foreach (var c in FavJumpListContacts)
            {
                var x = new JumpListLink(System.Windows.Forms.Application.ExecutablePath, c.Name);
                x.Arguments = "\"/jump:" + c.ID.GetHashCode() + "\"";
                //this.Try(() =>x.IconReference = new Microsoft.WindowsAPICodePack.Shell.IconReference(System.Windows.Forms.Application.ExecutablePath, 0));
                f.AddJumpListItems(x);
            }
            jumpList.AddCustomCategories(f);

            //var task = new JumpListLink(System.Windows.Forms.Application.ExecutablePath, "Show Contact List");
            //task.Arguments = "/show";
            //jumpList.AddUserTasks(task);

            var task = new JumpListLink(System.Windows.Forms.Application.ExecutablePath, "Check for new Messages");
            task.Arguments = "/check";
            //this.Try(() => task.IconReference = new Microsoft.WindowsAPICodePack.Shell.IconReference(System.Windows.Forms.Application.ExecutablePath, 5));
            jumpList.AddUserTasks(task);

            task = new JumpListLink(System.Windows.Forms.Application.ExecutablePath, "Sync Google Contacts Now");
            task.Arguments = "/update_contacts";
            //this.Try(() => task.IconReference = new Microsoft.WindowsAPICodePack.Shell.IconReference(System.Windows.Forms.Application.ExecutablePath, 5));
            jumpList.AddUserTasks(task);
        }

        private void OfflineJumpList(ref JumpList jumpList)
        {
            var task = new JumpListLink(System.Windows.Forms.Application.ExecutablePath, "About GVNotifier...");
            task.Arguments = "/about";
            //this.Try(() => task.IconReference = new Microsoft.WindowsAPICodePack.Shell.IconReference(System.Windows.Forms.Application.ExecutablePath, 0));
            jumpList.AddUserTasks(task);

            task = new JumpListLink(System.Windows.Forms.Application.ExecutablePath, "Preferences...");
            task.Arguments = "/prefs";
            //this.Try(() =>task.IconReference = new Microsoft.WindowsAPICodePack.Shell.IconReference( System.Windows.Forms.Application.ExecutablePath, 1));
            jumpList.AddUserTasks(task);


            task = new JumpListLink(System.Windows.Forms.Application.ExecutablePath, "Open Google Voice Website");
            task.Arguments = "/gv";
            //this.Try(() =>task.IconReference = new Microsoft.WindowsAPICodePack.Shell.IconReference(System.Windows.Forms.Application.ExecutablePath, 2));
            jumpList.AddUserTasks(task);

            if (SessionModel.Inst != null)
            {
                jumpList.AddUserTasks(new JumpListSeparator());

                task = new JumpListLink(System.Windows.Forms.Application.ExecutablePath, "Sign Out");
                task.Arguments = "/signout";
                //this.Try(() =>task.IconReference = new Microsoft.WindowsAPICodePack.Shell.IconReference(System.Windows.Forms.Application.ExecutablePath, 4));
                jumpList.AddUserTasks(task);
            }

            jumpList.AddUserTasks(new JumpListSeparator());

            task = new JumpListLink(System.Windows.Forms.Application.ExecutablePath, "Quit");
            task.Arguments = "/quit";
            //this.Try(() => task.IconReference = new Microsoft.WindowsAPICodePack.Shell.IconReference(System.Windows.Forms.Application.ExecutablePath, 3));
            jumpList.AddUserTasks(task);
        }

        private void ResetJumpList()
        {
            try
            {
                JumpList jumpList = JumpList.CreateJumpList();
                jumpList.JumpListItemsRemoved += (ss, ee) =>
                    {
                        
                    };
                foreach (var x in jumpList.RemovedDestinations)
                {

                }

                OfflineJumpList(ref jumpList);
                jumpList.Refresh();
            }
            catch (Exception ex)
            {
                Trace.Write("jumplist Error: " + ex);
            }
        }

        private void ClearJumpList()
        {
            
            try
            {
                JumpList jumpList = JumpList.CreateJumpList();
                jumpList.JumpListItemsRemoved += (ss, ee) =>
                {

                };
                foreach (var x in jumpList.RemovedDestinations)
                {

                }
                jumpList.Refresh();
            }
            catch (Exception ex)
            {
                Trace.Write("JumpList Error: " + ex);
            }
        }

        private void ResizeGridViewColumn(GridViewColumn column)
        {
            // TODO:  I guess I changed this because there were too many
            // sizing factors that this didn't take into account (or perhaps there
            // was glitching as the size changed)
            // either way, I'm not convinced this is right but it probably isn't doing 
            // any harm.

            //column.Width = double.MaxValue;
            /*
            if (double.IsNaN(column.Width))
            {
                    column.Width = column.ActualWidth;
            }
            column.Width = double.NaN;
            */
            column.Width = 9999;
        }

        void model_OnMessage(GoogleVoice.Message msg, GoogleVoice.Contact contact)
        {
            bool did_add = false;
            GoogleVoice.SMS sms = msg as GoogleVoice.SMS;
            if (sms != null)
            {
                if (!sms.Self)
                {
                    did_add = true;
                }
            }
            if (!did_add) return;

            this.Invoke(() =>
            {
                var mw = WindowForContact(contact);
                this.Try( () => mw.ShowActivated = false);
                 // crashes on xp?? TODO FIXME: what?
                if (!mw.Ready)
                    mw.Show();
                mw.AddMessage(msg);
            });
        }

        #region Message Click

        private void Contact_Click(object sender, MouseButtonEventArgs e)
        {
            try
            {
                GoogleVoice.Contact ct = lsvContacts.SelectedItem as GoogleVoice.Contact;
                if (ct == null) return;
                var mw = WindowForContact(ct);

                this.InvokeDelay(100, () =>
                {

                        this.Try( () =>mw.ShowActivated = true);

                    mw.Show();
                    mw.Activate();
                });
                lsvContacts.SelectedIndex = -1;
                txtSearch.Focus();
                if (Settings.Get("HideAfterSelect", false)) DoHide();

            }
            catch (Exception ex)
            {
                Debug.WriteLine("Main/Contact_Click *** " + ex);
            }
        }

        private void Call_Click(object sender, MouseButtonEventArgs e)
        {
            try
            {
                CallMessage ct = lsvCalls.SelectedItem as CallMessage;
                Debug.Assert(ct != null);
                var mw = WindowForContact(ct.Contact);

                this.InvokeDelay(100, () =>
                {
                    this.Try( () => mw.ShowActivated = true);
                    mw.Show();
                    mw.Activate();
                });
                if (Settings.Get("HideAfterSelect", false)) DoHide();
            }
            catch (Exception ex)
            {
                Debug.WriteLine("Main/Call_Click *** " + ex);
            }
        }

        private void Voicemail_Click(object sender, MouseButtonEventArgs e)
        {
            try
            {
                VoiceMessage ct = lsvVM.SelectedItem as VoiceMessage;
                Debug.Assert(ct != null);
                var mw = WindowForContact(ct.Contact);

                this.InvokeDelay(100, () =>
                {
                    this.Try( () => mw.ShowActivated = true);
                    mw.Show();
                    mw.Activate();
                });
                if (Settings.Get("HideAfterSelect", false)) DoHide();
            }
            catch (Exception ex)
            {
                Debug.WriteLine("Main/Voicemail_Click *** " + ex);
            }
        }

        #endregion

        #region Search

        int search_int = 0;
        bool search_updating = false;

        private void txtSearch_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (string.IsNullOrEmpty(txtSearch.Text))
            {
                txtSearchPrompt.Visibility = System.Windows.Visibility.Visible;
            }
            else
            {
                txtSearchPrompt.Visibility = System.Windows.Visibility.Hidden;
            }

            search_int = 20;
            if (search_updating) return;
            search_updating = true;
            ThreadPool.QueueUserWorkItem((o) =>
                {
                    while (search_int > 0)
                    {
                        Thread.Sleep(10);
                        search_int--;
                    }
                    this.Invoke(() =>
                    {
                        if (string.IsNullOrEmpty(txtSearch.Text))
                        {
                            lsvContacts.ItemsSource = model.Contacts;
                            lsvCalls.ItemsSource = model.Calls;
                            lsvVM.ItemsSource = model.Voicemails;
                        }
                        else
                        {
                            if (SelectedView == lsvContacts)
                            {
                                //ICollectionView view = CollectionViewSource.GetDefaultView(lsvContacts.ItemsSource);

                                //view.Filter = x => (x as GoogleVoice.Contact).Name.ToUpper().Contains(txtSearch.Text.ToUpper());


                                model.Search_Contacts(txtSearch.Text);
                                lsvContacts.ItemsSource = model.SearchContacts;
                                this.InvokeDelay(500, () => ResizeGridViewColumn(lsvNameCol));
                            }
                            else if (SelectedView == lsvCalls)
                            {
                                model.Search_Calls(txtSearch.Text);
                                lsvCalls.ItemsSource = model.SearchCalls;
                                this.InvokeDelay(500, () => ResizeGridViewColumn(lsvNameColCalls));
                            }
                            else if (SelectedView == lsvVM)
                            {
                                model.Search_Voicemail(txtSearch.Text);
                                lsvVM.ItemsSource = model.SearchVoicemail;
                                this.InvokeDelay(500, () => FitColumn(lsvVM, lsvNameColVM));
                            }
                        }
                        search_updating = false;
                    });
                });
        }

        private void txtSearch_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Down)
            {
                SelectedView.Focus();
                SelectedView.SelectedIndex = 0;
            }
            /*
            if (e.Key == Key.Escape)
                Hide();
            */
        }


        #endregion

        #region Pinning

        private void mnuContactsList_ContextMenuOpening(object sender, ContextMenuEventArgs e)
        {
            GoogleVoice.Contact c = lsvContacts.SelectedItem as GoogleVoice.Contact;
            if (c != null)
            {
                if (c.Group == "Favorites")
                {
                    mnuPinUnpin.Header = "Unpin " + c.Name;
                }
                else if (c.Group == "Dial")
                {
                    e.Handled = true;
                    return;
                }
                else
                {
                    mnuPinUnpin.Header = "Pin " + c.Name;
                }
                return;
            }
            e.Handled = true; // dont show otherwise
        }

        private void mnuPinUnpin_Click(object sender, RoutedEventArgs e)
        {
            GoogleVoice.Contact c = lsvContacts.SelectedItem as GoogleVoice.Contact;
            if (c != null)
            {
                if (c.Group == "Favorites")
                {
                    c.Group = "Other Contacts";
                }
                else
                {
                    c.Group = "Favorites";
                }

                lsvContacts.ItemsSource = model.Contacts;
                txtSearch.Text = "";

                SyncContactsJumpList();
                this.InvokeDelay(100, () =>
                {
                    CollectionView myView = (CollectionView)CollectionViewSource.GetDefaultView(lsvContacts.ItemsSource);
                    myView.Refresh();
                });
            }
        }

        #endregion


        #region Application Crash handling
        delegate void ProcessUnhandledExceptionDelegate(Exception ex);

        static void Current_DispatcherUnhandledException(object sender, DispatcherUnhandledExceptionEventArgs e)
        {
            Debug.WriteLine("Unhandled dispatcher ex " + e.Exception);
            // some of the exceptions being thrown by the CAG appear to be coming from separate threads so we'll protect ourselves
            if (!Application.Current.Dispatcher.CheckAccess())
            {
                // Unhandled exceptions on worker threads will halt the application. We want to
                // use our global exception handler(s), so dispatch or "forward" to the UI thread.
                Application.Current.Dispatcher.Invoke(DispatcherPriority.Normal, new ProcessUnhandledExceptionDelegate(ProcessUnhandledException), e.Exception);
            }
            else
            {
                ProcessUnhandledException(e.Exception);  // Already on UI thread; just rethrow the exception to global handlers
            }
            e.Handled = true;
        }

        private static void ProcessUnhandledException(Exception ex)
        {
            // TODO these should be auto-submitting, so this message probably isn't needed.
            // might make people feel like they're helpful or something, though.

            // MessageBox.Show("Send this info to Dave (Ctrl+C this window), you have found a bug!:  " + ex);
        }

        private static void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
        {
            Debug.WriteLine("Unhandled exception: " + e.ExceptionObject);
            // some of the exceptions being thrown by the CAG appear to be coming from separate threads so we'll protect ourselves
            if (!Application.Current.Dispatcher.CheckAccess())
            {
                // Unhandled exceptions on worker threads will halt the application. We want to
                // use our global exception handler(s), so dispatch or "forward" to the UI thread.
                Application.Current.Dispatcher.Invoke(DispatcherPriority.Normal, new ProcessUnhandledExceptionDelegate(ProcessUnhandledException), (Exception)e.ExceptionObject);
            }
            else
            {
                ProcessUnhandledException((Exception)e.ExceptionObject);  // Already on UI thread; just rethrow the exception to global handlers
            }

        }

        #endregion

        // TODO refactor the 3 methods below to use a Action<T> pattern.

        private void ListViewItem_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            // I believe this code makes it such that you can type in the search box, and hit the
            // down arrow key to get down (free), but also the up arrow key to jump back up
            if (lsvContacts.SelectedIndex == 0)
            {
                if (e.Key == Key.Up)
                {
                    txtSearch.Focus();
                }
            }

            if (e.Key == Key.Enter) Contact_Click(null, null);
        }

        private void Calls_ListViewItem_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            if (lsvCalls.SelectedIndex == 0)
            {
                if (e.Key == Key.Up)
                {
                    txtSearch.Focus();
                }
            }

            if (e.Key == Key.Enter) Call_Click(null, null);
        }

        private void Voicemail_ListViewItem_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            if (lsvVM.SelectedIndex == 0)
            {
                if (e.Key == Key.Up)
                {
                    txtSearch.Focus();
                }
            }

            if (e.Key == Key.Enter) Voicemail_Click(null, null);
        }

        #region Tab Click

        private void btnContactsView_Click(object sender, RoutedEventArgs e)
        {
            lsvVM.Visibility = System.Windows.Visibility.Collapsed;
            lsvContacts.Visibility = System.Windows.Visibility.Visible;
            lsvCalls.Visibility = System.Windows.Visibility.Collapsed;
            btnCallView.FontWeight = FontWeights.Normal;
            btnContactsView.FontWeight = FontWeights.Bold;
            btnVoicemailView.FontWeight = FontWeights.Normal;
            btnCallView.Tag = "Inactive";
            btnContactsView.Tag = "Active";
            btnVoicemailView.Tag = "Inactive";
            txtSearchPrompt.Text = "Search Contacts and Numbers";
            ResizeGridViewColumn(lsvNameCol);
            SelectedView = lsvContacts;
            txtSearch.Text = "";
            txtSearch.Focus();
            lsvContacts.SelectedIndex = -1;
        }

        private void btnVoicemailView_Click(object sender, RoutedEventArgs e)
        {
            lsvVM.Visibility = System.Windows.Visibility.Visible;
            lsvContacts.Visibility = System.Windows.Visibility.Collapsed;
            lsvCalls.Visibility = System.Windows.Visibility.Collapsed;
            btnCallView.FontWeight = FontWeights.Normal;
            btnContactsView.FontWeight = FontWeights.Normal;
            btnVoicemailView.FontWeight = FontWeights.Bold;
            btnCallView.Tag = "Inactive";
            btnContactsView.Tag = "Inactive";
            btnVoicemailView.Tag = "Active";
            lsvVM.ItemsSource = model.Voicemails;
            txtSearchPrompt.Text = "Search Voicemail";
            this.InvokeDelay(500, () => FitColumn(lsvVM, lsvNameColVM));
            SelectedView = lsvVM;
            txtSearch.Text = "";
            txtSearch.Focus();
            lsvVM.SelectedIndex = -1;
        }

        private void btnCallView_Click(object sender, RoutedEventArgs e)
        {
            lsvVM.Visibility = System.Windows.Visibility.Collapsed;
            lsvContacts.Visibility = System.Windows.Visibility.Collapsed;
            lsvCalls.Visibility = System.Windows.Visibility.Visible;
            btnCallView.FontWeight = FontWeights.Bold;
            btnContactsView.FontWeight = FontWeights.Normal;
            btnVoicemailView.FontWeight = FontWeights.Normal;
            btnCallView.Tag = "Active";
            btnContactsView.Tag = "Inactive";
            btnVoicemailView.Tag = "Inactive";
            lsvCalls.ItemsSource = model.Calls;
            txtSearchPrompt.Text = "Search Call History";
            ResizeGridViewColumn(lsvNameColCalls);
            SelectedView = lsvCalls;
            txtSearch.Text = "";
            txtSearch.Focus();
            lsvCalls.SelectedIndex = -1;
        }

        #endregion

        private void FitColumn(ListView view, GridViewColumn col)
        {
            GridView gd = view.View as GridView;
            if (view.ActualWidth == 0) return;

            double w = 0;
            foreach (var c in gd.Columns)
            {
                if (c == col) break;
                w += c.ActualWidth;
            }
            col.Width = view.ActualWidth - SystemParameters.VerticalScrollBarWidth - w;
        }

        private void Hyperlink_RequestNavigate(object sender, System.Windows.Navigation.RequestNavigateEventArgs e)
        {
            this.Try(() => System.Diagnostics.Process.Start("http://daveamenta.com"));
        }

        private Button lastPlayButton = null;

        private void PlayPause_Click(object sender, RoutedEventArgs e)
        {

            Button c = sender as Button;
            lastPlayButton = c;
            var vm = c.Tag as VoiceMessage;

            if (c.Content.ToString() == "Play")
            {
                if (VmPlayer.Length == 0)
                {
                    string file = model.account.Cache_Dir + "\\" + vm.Message.ID + ".mp3";
                    try
                    {
                        if (File.Exists(file))
                        {
                            VmPlayer.Play(file);
                        }
                        else
                        {
                            // TODO somehow we get here without actually having the mp3 file.  
                            // we'll need to ask the GVLib to download it.
                            throw new FileNotFoundException("Cannot find file on disk");
                        }
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("Cannot play mp3 file: " + ex.Message + "\n\nCheck the file: " + file);
                    }
                }
                else
                {
                    VmPlayer.Resume();
                }
                c.Content = "Pause";
            }
            else
            {
                VmPlayer.Pause();
                c.Content = "Play";
            }
        }

        private void vmProgress_MouseDown(object sender, MouseButtonEventArgs e)
        {
            // TODO why is seeking disabled?  I thought this worked

            //var p = sender as ProgressBar;
            //Debug.WriteLine("Seek: " + p.Value + " of " + VmPlayer.Length);
            //VmPlayer.Seek((int)p.Value);
        }

        private void lsvVM_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            VmPlayer.Stop();

            if (lastPlayButton != null)
                lastPlayButton.Content = "Play";
            VmPlayerString = "";
        }


        private AudioPlayer VmPlayer = new AudioPlayer();

        public int VmPlayerPosition
        {
            get { return (int)GetValue(VmPlayerPositionProperty); }
            set { SetValue(VmPlayerPositionProperty, value); }
        }

        // Using a DependencyProperty as the backing store for VmPlayerPosition.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty VmPlayerPositionProperty =
            DependencyProperty.Register("VmPlayerPosition", typeof(int), typeof(MainWindow), new UIPropertyMetadata(0));



        public int VmPlayerMax
        {
            get { return (int)GetValue(VmPlayerMaxProperty); }
            set { SetValue(VmPlayerMaxProperty, value); }
        }

        // Using a DependencyProperty as the backing store for VmPlayerMax.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty VmPlayerMaxProperty =
            DependencyProperty.Register("VmPlayerMax", typeof(int), typeof(MainWindow), new UIPropertyMetadata(0));



        public string VmPlayerString
        {
            get { return (string)GetValue(VmPlayerStringProperty); }
            set { SetValue(VmPlayerStringProperty, value); }
        }

        // Using a DependencyProperty as the backing store for VmPlayerString.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty VmPlayerStringProperty =
            DependencyProperty.Register("VmPlayerString", typeof(string), typeof(MainWindow), new UIPropertyMetadata(""));


        private void vm_init()
        {
            VmPlayerMax = 100;
            VmPlayerPosition = 0;
            VmPlayer.PlayingProgressChanged += (v, m) =>
            {
                VmPlayerMax = m;
                VmPlayerPosition = v;


                VmPlayerString = TimeSpan.FromMilliseconds(v).Minutes.ToString() + string.Format(":{0:00}", TimeSpan.FromMilliseconds(v).Seconds)
                    + " of " + TimeSpan.FromMilliseconds(m).Minutes.ToString() + string.Format(":{0:00}", TimeSpan.FromMilliseconds(m).Seconds);
            };
            VmPlayer.PlayingCompleted += () =>
            {
                VmPlayerPosition = 0;
                if (lastPlayButton != null)
                    lastPlayButton.Content = "Play";
                VmPlayerString = "";
            };
        }

        private void Hyperlink_RequestNavigate_1(object sender, System.Windows.Navigation.RequestNavigateEventArgs e)
        {
            Preferences p = new Preferences();
            p.Show();
        }

        private void Window_LostFocus(object sender, RoutedEventArgs e)
        {
            
        }

        private void Window_Deactivated(object sender, EventArgs e)
        {
            if (Settings.Get("HideFocusLost", false)) DoHide();
        }

        private void lsvVM_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            FitColumn(lsvVM,lsvNameColVM);
        }

        private void selfwin_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Escape)
                DoHide();
        }


    }

    #region Value Converters
    public sealed class ImageConverter : IValueConverter
    {
        public object Convert(object value, Type targetType,
                              object parameter, CultureInfo culture)
        {
            if (string.IsNullOrEmpty((string)value)) return new BitmapImage(new Uri("pack://application:,,,/GVNotifier.net;component/Images/blank.png"));
            try
            {
                return new BitmapImage(new Uri((string)value));
            }
            catch
            {
                return new BitmapImage(new Uri("pack://application:,,,/GVNotifier.net;component/Images/blank.png"));
            }
        }

        public object ConvertBack(object value, Type targetType,
                                  object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }

    // BooleanToVisibilityConverter

    public sealed class BooleanToVisibilityConverter : IValueConverter
    {
        public object Convert(object value, Type targetType,
                              object parameter, CultureInfo culture)
        {
            bool? IsSelected = value as bool?;

            if (IsSelected == true)
                return Visibility.Visible;
            else
                return Visibility.Collapsed;
        }

        public object ConvertBack(object value, Type targetType,
                                  object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }

    public sealed class CallTypeTextConverter : IValueConverter
    {
        public object Convert(object value, Type targetType,
                              object parameter, CultureInfo culture)
        {
            switch ((GoogleVoice.Message.MessageType)value)
            {
                case GoogleVoice.Message.MessageType.Missed:
                    return "Missed";
                case GoogleVoice.Message.MessageType.Placed:
                    return "Placed";
                case GoogleVoice.Message.MessageType.Received:
                    return "Received";
            }
            return "Error";
        }

        public object ConvertBack(object value, Type targetType,
                                  object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }

    public sealed class CallTypeColorConverter : IValueConverter
    {
        public object Convert(object value, Type targetType,
                              object parameter, CultureInfo culture)
        {
            switch ((GoogleVoice.Message.MessageType)value)
            {
                case GoogleVoice.Message.MessageType.Missed:
                    return "red";
                case GoogleVoice.Message.MessageType.Placed:
                    return "green";
                case GoogleVoice.Message.MessageType.Received:
                    return "blue";
            }
            return "black";
        }

        public object ConvertBack(object value, Type targetType,
                                  object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }

    [ValueConversion(typeof(DateTime), typeof(string))]
    public class FriendlyTimeDescription : IValueConverter
    {
        public object Convert(
            object value,
            Type targetType,
            object parameter,
            CultureInfo culture)
        {
            var time = System.Convert.ToDateTime(value);
            return Describe(DateTime.Now - time);
        }

        static readonly string[] NAMES = {
                                         "day",
                                         "hour",
                                         "minute",
                                         "second"
                                     };

        public static string Describe(TimeSpan t)
        {
            int[] ints = {
                         t.Days,
                         t.Hours,
                         t.Minutes,
                         t.Seconds
                     };

            double[] doubles = {
                               t.TotalDays,
                               t.TotalHours,
                               t.TotalMinutes,
                               t.TotalSeconds
                           };

            var firstNonZero = ints
                .Select((value, index) => new { value, index })
                .FirstOrDefault(x => x.value != 0);
            if (firstNonZero == null)
            {
                return "now";
            }
            int i = firstNonZero.index;
            string prefix = ""; //  (i >= 3) ? "" : "about ";
            int quantity = (int)Math.Round(doubles[i]);
            return prefix + Tense(quantity, NAMES[i]) + " ago";
        }

        public static string Tense(int quantity, string noun)
        {
            return quantity == 1
                ? "1 " + noun
                : string.Format("{0} {1}s", quantity, noun);
        }

        public object ConvertBack(
            object value,
            Type targetType,
            object parameter,
            CultureInfo culture)
        {
            return Binding.DoNothing;
        }
    }
    #endregion
}
