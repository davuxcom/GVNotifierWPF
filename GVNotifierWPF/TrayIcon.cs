using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using DavuxLib2;
using System.Threading;
using System.Windows.Forms;

namespace GVNotifier
{
    public class TrayIcon
    {
        public static void Init()
        {
            if (Settings.Get("ShowTrayIcon", false))
            {
                var t = new Thread(() =>
                {
                    NotifyIcon ni = new NotifyIcon();
                    ni.Icon = GVNotifier.Properties.Resources.gv;
                    ni.Text = "GVNotifier";
                    ni.Visible = true;

                    ni.ContextMenu = new ContextMenu();

                    var m = new MenuItem();
                    m.Text = "About";
                    m.Click += (ss, ee) => SessionModel.ShowAbout();
                    ni.ContextMenu.MenuItems.Add(m);

                    m = new MenuItem();
                    m.Text = "Preferences";
                    m.Click += (ss, ee) => SessionModel.ShowPrefs();
                    ni.ContextMenu.MenuItems.Add(m);

                    ni.ContextMenu.MenuItems.Add(new MenuItem("-"));

                    m = new MenuItem();
                    m.Text = "Check for new messages";
                    m.Click += (ss, ee) => SessionModel.Check();
                    ni.ContextMenu.MenuItems.Add(m);

                    // TODO contact name sync won't work, and number sync
                    // won't work if the window has been opened in the session
                    // this comes together with the "switch to MVVM" change.
                    m = new MenuItem();
                    m.Text = "Sync Google Contacts Now";
                    m.Click += (ss, ee) => SessionModel.UpdateContacts();
                    ni.ContextMenu.MenuItems.Add(m);

                    ni.ContextMenu.MenuItems.Add(new MenuItem("-"));

                    m = new MenuItem();
                    m.Text = "Sign Out";
                    m.Click += (ss, ee) =>
                    {
                        ni.Visible = false;
                        SessionModel.SignOut();
                    };
                    ni.ContextMenu.MenuItems.Add(m);

                    m = new MenuItem();
                    m.Text = "Quit";
                    m.Click += (ss, ee) =>
                    {
                        ni.Visible = false;
                        SessionModel.CloseApp();
                    };
                    ni.ContextMenu.MenuItems.Add(m);

                    ni.DoubleClick += (_, __) => SessionModel.ShowMainWindow();
                    ni.MouseClick += (ss, ee) =>
                    {
                        if (ee.Button == MouseButtons.Left)
                        {
                            SessionModel.ShowMainWindow();
                        }
                    };

                    Application.Run();
                });
                // this worked without STA, but UI controls should always be STA
                t.SetApartmentState(ApartmentState.STA);
                t.Start();
            }
        }
    }
}
