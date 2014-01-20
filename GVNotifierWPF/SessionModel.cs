using DavuxLib2;
using GoogleVoice;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.IO.Pipes;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text.RegularExpressions;
using System.Threading;

namespace GVNotifier
{
    public interface IMessage
    {
        DateTime Time { get; }
        string Name { get; }
        string ImageLocation { get; }
        string Text { get; }
        Message.MessageType MessageType { get; }
        GoogleVoice.Contact Contact { get; }
        GoogleVoice.Message Message { get; }
    }
    public class VoiceMessage : IMessage, INotifyPropertyChanged
    {
        public string Name
        {
            get
            {
                return Contact.Name;
            }
        }

        public string ImageLocation
        {
            get
            {
                return Contact.ImageLocation;
            }
        }

        public DateTime Time
        {
            get
            {
                return msg.Time;
            }
        }

        public Message.MessageType MessageType
        {
            get
            {
                return Message.MessageType.Voicemail;
            }
        }

        public string Text
        {
            get
            {
                return msg.MessageText;
            }
        }

        public override string ToString()
        {
            return string.Format("voicemail from {1} at {2}", msg.Class, Contact.Name, Time.ToString());
        }

        public GoogleVoice.Contact Contact { get; private set; }
        public GoogleVoice.Message Message { get { return msg; } }
        GoogleVoice.VoiceMailMessage msg = null;

        public VoiceMessage(GoogleVoice.Contact Contact, GoogleVoice.VoiceMailMessage msg)
        {
            this.Contact = Contact;
            this.msg = msg;

            Contact.PropertyChanged += (oo, ee) =>
                {
                    if (ee.PropertyName == "ImageLocation" || ee.PropertyName == "Name")
                        if (PropertyChanged != null)
                            PropertyChanged(this, new PropertyChangedEventArgs(ee.PropertyName));
                };
        }

        public event PropertyChangedEventHandler PropertyChanged;

    }

    public class CallMessage : IMessage, INotifyPropertyChanged
    {
        public string Name
        {
            get
            {
                return Contact.Name;
            }
        }

        public string ImageLocation
        {
            get
            {
                return Contact.ImageLocation;
            }
        }

        public DateTime Time
        {
            get
            {
                return msg.Time;
            }
        }

        public string Text
        {
            get
            {
                return msg.MessageText;
            }
        }

        public GoogleVoice.Contact Contact { get; private set; }
        GoogleVoice.Message msg = null;
        public GoogleVoice.Message Message { get { return msg; } }

        public override string ToString()
        {
            return string.Format("{0} call from {1} at {2}", msg.Class, Contact.Name, Time.ToString());
        }

        public Message.MessageType MessageType
        {
            get
            {
                return msg.Class;
            }
        }

        public CallMessage(GoogleVoice.Contact Contact, GoogleVoice.Message msg)
        {
            this.Contact = Contact;
            this.msg = msg;

            Contact.PropertyChanged += (oo, ee) =>
            {
                if (ee.PropertyName == "ImageLocation" || ee.PropertyName == "Name")
                    if (PropertyChanged != null)
                        PropertyChanged(this, new PropertyChangedEventArgs(ee.PropertyName));
            };
        }

        public event PropertyChangedEventHandler PropertyChanged;

    }

    class SessionModel
    {
        public static event Action AppClosing;
        public static event Action ShowRequest;
        public static event Action PrefsRequest;
        //public static event Action CheckRequest;
        public static event Action AboutRequest;
        

        internal static void ShowAbout()
        {
            if (AboutRequest != null) AboutRequest();
        }

        internal static void ShowPrefs()
        {
            if (PrefsRequest != null) PrefsRequest();
        }

        internal static void Check()
        {
            Trace.WriteLine("Manual Message Check");
            if (Inst != null && Inst.account != null)
            {
                Inst.account.UpdateAsync();
            }
        }

        internal static void ShowMainWindow()
        {
            if (ShowRequest != null) ShowRequest();
        }

        internal static void CloseApp()
        {
            if (AppClosing != null) AppClosing();
        }

        internal static void UpdateContacts()
        {
            if (Inst != null && Inst.account != null)
            {
                Inst.account.UpdateContactsAync();
            }
        }

        internal static void SignOut()
        {
            Trace.WriteLine("Sign Out");
            Settings.Set("AutoLogin", false);
            if (AppClosing != null) AppClosing();
            System.Diagnostics.Process.Start(System.Windows.Forms.Application.ExecutablePath, "--no-mutex");
        }

        [System.STAThreadAttribute()]
        public static void Main(string[] args)
        {
            bool auto_login_disabled = false;
            try
            {
                System.Windows.Forms.Application.EnableVisualStyles();
            }
            catch { }

            if (args.Length > 0 && args[0].StartsWith("/"))
            {
                try
                {
                    using (NamedPipeClientStream pipeClient =
               new NamedPipeClientStream(".", "gvnotifier_wpf", PipeDirection.Out))
                    {

                        // Connect to the pipe or wait until the pipe is available.
                        Console.Write("Attempting to connect to pipe...");
                        pipeClient.Connect(1000);
                        using (StreamWriter sw = new StreamWriter(pipeClient))
                        {
                            sw.WriteLine(args[0]);
                            sw.Flush();
                            sw.Close();
                            Thread.Sleep(1000 * 2);
                        }
                        pipeClient.Close();
                    }
                    return;
                }
                catch (TimeoutException)
                {
                    // launch app.
                    auto_login_disabled = true;
                }
                catch (Exception ex)
                {
                    System.Windows.Forms.MessageBox.Show(ex.ToString());
                    return;
                }
            }


            
            try
            {
                DavuxLib2.App.Init("GVNotifierWPF");

                if (!args.Contains("--no-mutex"))
                {
                    if (DavuxLib2.App.IsAppAlreadyRunning())
                    {
                        try
                        {
                            using (NamedPipeClientStream pipeClient =
                       new NamedPipeClientStream(".", "gvnotifier_wpf", PipeDirection.Out))
                            {

                                // Connect to the pipe or wait until the pipe is available.
                                Console.Write("Attempting to connect to pipe...");
                                pipeClient.Connect(1000);
                                using (StreamWriter sw = new StreamWriter(pipeClient))
                                {
                                    sw.WriteLine("/show");
                                    sw.Flush();
                                    sw.Close();
                                    Thread.Sleep(1000 * 2);
                                }
                                pipeClient.Close();
                            }
                            return;
                        }
                        catch (TimeoutException)
                        {
                            // launch app.
                            auto_login_disabled = true;
                        }
                        catch (Exception ex)
                        {
                            System.Windows.Forms.MessageBox.Show(ex.ToString());
                            return;
                        }
                    }
                }

                DefaultSettings();

                if (auto_login_disabled)
                {
                    Settings.Set("AutoLogin", false);
                }

                new Thread(() =>
                {
                    Trace.WriteLine("Starting Pipe Server");
                    int t = 0;
                    while (true)
                    {
                        try
                        {
                            using (NamedPipeServerStream pipeServer =
                    new NamedPipeServerStream("gvnotifier_wpf", PipeDirection.In))
                            {
                                Trace.WriteLine("Waiting for pipe connection...");
                                pipeServer.WaitForConnection();

                                Trace.WriteLine("Client connected.");
                                try
                                {
                                    // Read user input and send that to the client process.
                                    using (StreamReader sr = new StreamReader
                                        (pipeServer))
                                    {
                                        string line = sr.ReadLine();
                                        Trace.WriteLine("PIPE: " + line);
                                        JumpListCommand(line);
                                        sr.Close();
                                    }
                                }
                                // Catch the IOException that is raised if the pipe is broken
                                // or disconnected.
                                catch (IOException e)
                                {
                                    Trace.WriteLine("Pipe ERROR: {0}", e.Message);
                                }
                            }
                        }
                        catch (Exception ex)
                        {
                            Trace.WriteLine("*** Pipe Server Crashed: " + ex.Message);
                            t++;
                            if (t > 1)
                            {
                                Trace.WriteLine("Pipe Server Crashed Max Times");
                                return;
                            }
                        }
                    }
                }).Start();

                TrayIcon.Init();

                try
                {

                    if (DavuxLib2.App.IsAllowedToExecute(LicensingMode.Free) != LicenseValidity.OK)
                    {
                        Trace.WriteLine("Info: Software could not be properly licensed.");
                    }
                }
                catch (Exception ex)
                {
                    Trace.WriteLine("IsAllowedToExecute: " + ex);
                }

                DavuxLib2.App.SubmitCrashReports();

                GVNotifier.App app = new GVNotifier.App();
                app.InitializeComponent();
                app.Run();
            }
            catch (Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.ToString());
            }
        }

        private static void DefaultSettings()
        {
            Settings.Get("ViewFontSize", 35); // 35px

            Settings.Get("HideFocusLost", false);
            Settings.Get("HideStartup", false); // NOT ENABLED
            Settings.Get("HideAfterSelect", false);

            // People on Windows 7/8+ won't get the tray icon by default.
            Settings.Get("ShowTrayIcon", IsLegacyWindows());

            Settings.Get("FlashWindow", true);
            Settings.Get("PlaySound", true);
            Settings.Get("SoundRepeat", false);
                     
            Settings.Get("SoundRepeatDuration", 2);
            Settings.Get("SoundRepeeatNumber", 5);

            Settings.Get("ShowAcceptedCall", false);
            Settings.Get("ShowMissedCall", true);
            Settings.Get("ShowPlacedCall", false);

            try
            {
                // We ship the chime sound with the software, but it gets copied into
                // the AppData directory so the user can change it if they like.
                if (!File.Exists(DavuxLib2.App.DataDirectory + "\\new.wav"))
                {
                    File.Copy("new.wav", DavuxLib2.App.DataDirectory + "\\new.wav");
                }
            }
            catch (Exception ex)
            {
                Trace.WriteLine("Couldn't copy new.wav: " + ex.Message);
            }
        }

        // Legacy Windows is Windows < 6.1 (Windows 7)
        private static bool IsLegacyWindows()
        {
            if (Environment.OSVersion.Version.Major > 6)
            {
                return false; // Future NT7
            }
            else if (Environment.OSVersion.Version.Major == 6 &&
                Environment.OSVersion.Version.Minor > 0)
            {
                // Not Windows Vista aka 6.0
                return false;
            }
            else
            {
                // Windows XP/Vista
                return true;
            }
        }

        private static void JumpListCommand(string line)
        {
            try
            {
                if (Inst != null && line.StartsWith("/jump:"))
                {
                    line = line.Substring("/jump:".Length);
                    int code = int.Parse(line);

                    if (Inst.OnJumpListContact != null)
                    {
                        Inst.OnJumpListContact(Inst.Contacts.First(
                            c => c.ID.GetHashCode() == code));
                    }
                }
                else if (line.Trim() == "/prefs")
                {
                    Trace.WriteLine("Open Prefs");
                    if (PrefsRequest != null) PrefsRequest();
                }
                else if (line.Trim() == "/gv")
                {
                    Trace.WriteLine("Open Google Voice");
                    System.Diagnostics.Process.Start("http://voice.google.com/");
                }
                else if (line.Trim() == "/signout")
                {
                    SignOut();
                }
                else if (line.Trim() == "/check")
                {
                    Trace.WriteLine("Manual Message Check");
                    if (Inst != null && Inst.account != null)
                    {
                        Inst.account.UpdateAsync();
                    }
                }
                else if (line.Trim() == "/quit")
                {
                    Trace.WriteLine("Quit App");
                    if (AppClosing != null) AppClosing();
                }
                else if (line.Trim() == "/show")
                {
                    Trace.WriteLine("Show App");
                    if (ShowRequest != null) ShowRequest();
                }
                else if (line.Trim() == "/about")
                {
                    Trace.WriteLine("Show About");
                    ShowAbout();
                }
                else if (line.Trim() == "/update_contacts")
                {
                    Trace.WriteLine("Update Contacts");
                    UpdateContacts();
                }
                else
                {
                    Debug.Assert(false);
                }
            }
            catch (Exception ex)
            {
                Trace.WriteLine("open contact failed : " + ex);
            }
        }

        string UserName = "";
        string Password = "";

        public Account account = null;

        public static SessionModel Inst = null;

        public delegate void ContactEvent(GoogleVoice.Contact contact);
        public event ContactEvent OnJumpListContact;

        public ObservableCollection<GoogleVoice.Contact> Contacts 
       {
            get
            {
                return account.ContactsManager.Contacts ?? new ObservableCollection<Contact>();
            }
        }
        public ObservableCollectionEx<GoogleVoice.Contact> SearchContacts { get; private set; }
        public ObservableCollectionEx<VoiceMessage> SearchVoicemail { get; private set; }
        public ObservableCollectionEx<VoiceMessage> Voicemails { get; private set; }
        public ObservableCollectionEx<CallMessage> Calls { get; private set; }
        public ObservableCollectionEx<CallMessage> SearchCalls { get; private set; }

        public ObservableCollectionEx<IMessage> All
        {
            get
            {
                var c = new ObservableCollectionEx<IMessage>();
                c.AddRange(Calls.ToArray());
                c.AddRange(Voicemails.ToArray());
                c.Sort(new MessageComparer<IMessage>());
                return c;
            }
        }


        public event Action<GoogleVoice.Message,GoogleVoice.Contact> OnMessage;
        public event Action OnContactsUpdated;
        public event Action<string> OnLoginMessage;
        public event Action OnLoginSuccess;
        public event Action OnLoginFailure;
        public static string KEY = "ENC_DAVE_GVN_WPF_%%345!@#%#!$";

        public void Search_Contacts(string text)
        {
            ThreadPool.QueueUserWorkItem((o) =>
            {
                try
                {
                    text = text.ToLower();
                    SearchContacts.Clear();
                    foreach (var c in Contacts)
                    {
                        // FIXME: also search phone numbers
                        if (c.Name.ToLower().IndexOf(text) > -1)
                        {
                            SearchContacts.Add(c);
                            continue;
                        }
                        foreach (var p in c.Phones)
                        {
                            if (p.Number.IndexOf(text) > -1)
                            {
                                SearchContacts.Add(c);
                                break;
                            }
                        }
                    }
                    if (Regex.IsMatch(GoogleVoice.Util.StripNumber(text), "^[0-9|\\+]+$"))
                    {
                        text = GoogleVoice.Util.StripNumber(text);
                        Contact c = new Contact { Name = GoogleVoice.Util.FormatNumber(text) };
                        c.Group = "Dial";
                        c.Phones.Add(new Phone { Number = text, Type = "Unknown" });
                        SearchContacts.Add(c);
                    }
                }
                catch (Exception ex)
                {
                    Trace.WriteLine("Contacts search: " + ex);
                }
            });
        }

        public void Search_Calls(string text)
        {
            ThreadPool.QueueUserWorkItem((o) =>
            {
                try
                {
                    text = text.ToLower();
                    SearchCalls.Clear();
                    foreach (var c in Calls)
                    {
                        if (c.Name.ToLower().IndexOf(text) > -1)
                        {
                            SearchCalls.Add(c);
                            continue;
                        }
                        foreach (var p in c.Contact.Phones)
                        {
                            if (p.Number.IndexOf(text) > -1)
                            {
                                SearchCalls.Add(c);
                                break;
                            }
                        }
                    }
                    SearchCalls.Sort(new MessageComparer<CallMessage>());
                }
                catch (Exception ex)
                {
                    Trace.WriteLine("Call Search Error: " + ex);
                }
            });
        }

        public void Search_Voicemail(string text)
        {
            ThreadPool.QueueUserWorkItem((o) =>
            {
                try
                {
                    text = text.ToLower();
                    SearchVoicemail.Clear();
                    foreach (var c in Voicemails)
                    {
                        bool add = false;
                        if (c.Name.ToLower().IndexOf(text) > -1)
                        {
                            SearchVoicemail.Add(c);
                            add = true;
                            continue;
                        }
                        foreach (var p in c.Contact.Phones)
                        {
                            if (p.Number.IndexOf(text) > -1)
                            {
                                SearchVoicemail.Add(c);
                                add = true;
                                break;
                            }
                        }
                        if (add) continue;
                        if (c.Text.ToLower().IndexOf(text) > -1)
                        {
                            SearchVoicemail.Add(c);
                            break;
                        }
                    }
                }
                catch (Exception ex)
                {
                    Trace.WriteLine("VM Search Error: " + ex);
                }
            });
        }

        public SessionModel(string UserName, string Password)
        {
            this.UserName = UserName;
            this.Password = Password;
            Inst = this;
            SearchContacts = new ObservableCollectionEx<Contact>();
            Voicemails = new ObservableCollectionEx<VoiceMessage>();
            SearchVoicemail = new ObservableCollectionEx<VoiceMessage>();
            Calls = new ObservableCollectionEx<CallMessage>();
            SearchCalls = new ObservableCollectionEx<CallMessage>();
            try
            {
                if (!Directory.Exists(DavuxLib2.App.DataDirectory + @"\cache\"))
                {
                    Directory.CreateDirectory(DavuxLib2.App.DataDirectory + @"\cache\");
                }
            }
            catch (Exception ex)
            {
                Trace.WriteLine("SessionModel/SessionModel Create Cache Dir *** " + ex);
            }
            account = new Account(UserName, Password, DavuxLib2.Settings.Get<GVCookie>("SMSV", null), DavuxLib2.App.DataDirectory + @"\cache\");

            account.OnMessage +=new Action<Message>(account_OnMessage);
            // account.OnPreInitMessage += new Action<Message>(account_OnPreInitMessage);
            account.OnLoginMessage += (s) =>
            {
                if (OnLoginMessage != null)
                    OnLoginMessage(s);
            };
            account.ContactsManager.OnContactsUpdated += () =>
            {
                Trace.WriteLine("Saving Contacts");
                account.ContactsManager.Save();
            };
            account.SMSVCookieUpdated += cookie =>
            {
                Trace.WriteLine("SMSV Cookie Updated: " + cookie);
                DavuxLib2.Settings.Set<GVCookie>("SMSV", cookie);
                DavuxLib2.Settings.Save();
            };
            account.GetSMSPinFromUser += () =>
            {
                Trace.WriteLine("Requesting PIN from user...");
                // this user has 2-step verification, and we need to get a PIN from them
                string PIN = "";
                Thread t = new Thread(() =>
                {
                    GetPin pinWindow = new GetPin();
                    pinWindow.Show();
                    System.Windows.Threading.Dispatcher.Run();
                    PIN = pinWindow.PIN;
                });
                t.SetApartmentState(ApartmentState.STA);
                t.Start();
                t.Join();
                Trace.WriteLine("Got PIN: " + PIN);
                return PIN;
            };
        }

        void account_OnPreInitMessage(Message m)
        {
            if (m.Class == Message.MessageType.SMS)
            {
                // drop SMS's
                return;
            }
            if (OnMessage != null)
                OnMessage(m, account.ContactForNumber(m.Number));
        }

        public void Save()
        {
            if (account != null) account.ContactsManager.Save();
            Settings.Save();
        }

        void account_OnMessage(Message m)
        {
            if (OnMessage != null)
                OnMessage(m, account.ContactForNumber(m.Number));
        }

        public void Login()
        {
            // Change the polling to 10s from 20s in 1.4.3.180
            if (Settings.Get("NewPolling_1.4.3", false) == false)
            {
                Settings.Set("UpdateFreq", 10);
                Settings.Set("NewPolling_1.4.3", true);
            }

            new Thread(() =>
                {
                    retry:
                    try
                    {
                        account.Login();
                        try
                        {
                            account.ContactsManager.OnContactsUpdated += () =>
                            {
                                if (OnContactsUpdated != null)
                                    OnContactsUpdated();
                            };
                        }
                        catch (Exception ex)
                        {
                            Trace.WriteLine("Error in contacts assoc " + ex);
                        }

                        account.Ready += () =>
                            {
                                foreach (var m in account.VoiceMailFeed.Messages.ToArray().Reverse())
                                {
                                    if (Voicemails.Any(vm => vm.Message == m)) continue;
                                    Voicemails.Add(
                                        new VoiceMessage(account.ContactForNumber(m.Number),
                                          (GoogleVoice.VoiceMailMessage)   m));
                                }
                                foreach (var m in account.PlacedCalls.Messages.ToArray())
                                {
                                    if (Calls.Any(cm => cm.Message == m)) continue;
                                    Calls.Add(
                                        new CallMessage(account.ContactForNumber(m.Number),
                                          (GoogleVoice.Message)m));
                                }
                                foreach (var m in account.MissedCalls.Messages.ToArray())
                                {
                                    if (Calls.Any(cm => cm.Message == m)) continue;
                                    Calls.Add(
                                        new CallMessage(account.ContactForNumber(m.Number),
                                          (GoogleVoice.Message)m));
                                }
                                foreach (var m in account.ReceivedCalls.Messages.ToArray())
                                {
                                    if (Calls.Any(cm => cm.Message == m)) continue;
                                    Calls.Add(
                                        new CallMessage(account.ContactForNumber(m.Number),
                                          (GoogleVoice.Message)m));
                                }
                                Calls.Sort(new MessageComparer<CallMessage>());
                                Voicemails.Sort(new MessageComparer<VoiceMessage>());
                            };

                        account.OnMessage += (m) =>
                            {
                                if (m.Class == Message.MessageType.Voicemail)
                                {
                                    Trace.Write("Adding vm: " + m);
                                    Voicemails.Insert(0,
                                        new VoiceMessage(account.ContactForNumber(m.Number),
                                          (GoogleVoice.VoiceMailMessage)m));
                                }
                                if (m.Class == Message.MessageType.Missed ||
                                    m.Class == Message.MessageType.Placed ||
                                    m.Class == Message.MessageType.Received)
                                {
                                    Trace.Write("Adding call: " + m);
                                    Calls.Add(
                                        new CallMessage(account.ContactForNumber(m.Number),
                                          (GoogleVoice.Message)m));
                                    Calls.Sort(new MessageComparer<CallMessage>());
                                }
                            };

                        new Thread(() =>
                        {
                            while (true)
                            {
                                int updateFreq = Settings.Get("UpdateFreq", 10);
                                if (updateFreq == -1) return;
                                if (updateFreq < 5) updateFreq = 5;
                                Thread.Sleep(1000 * updateFreq);
                                account.UpdateAsync();
                            }
                        }).Start();

                        if (OnLoginSuccess != null)
                            OnLoginSuccess();
                    }
                    catch (GVLoginException ex)
                    {
                        Trace.WriteLine("Login Failed: " + ex);
                        // bad password
                        if (OnLoginFailure != null)
                            OnLoginFailure();
                    }
                    catch (Exception ex)
                    {
                        Trace.WriteLine("Login Failed: " + ex);
                        if (OnLoginMessage != null)
                            OnLoginMessage("No Internet Connection, retrying in 10 seconds.");
                        Thread.Sleep(1000 * 10);
                        goto retry;
                    }
                }).Start();
        }

        class MessageComparer<T> : IComparer<T>
        {
            public int Compare(T c1, T c2)
            {
                var d1 = c1 as IMessage;
                var d2 = c2 as IMessage;
                int returnValue = 1;
                if (d1 != null && d2 != null)
                {
                    returnValue = d2.Time.CompareTo(d1.Time);
                }
                return returnValue;
            }
        }
    }
}
