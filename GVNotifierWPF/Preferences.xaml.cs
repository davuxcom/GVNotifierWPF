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
using System.Text.RegularExpressions;
using DavuxLib2.Extensions;
using DavuxLib2;
using System.IO;
using System.Diagnostics;
using System.Threading;

namespace GVNotifier
{
    /// <summary>
    /// Interaction logic for Preferences.xaml
    /// </summary>
    public partial class Preferences : Window
    {
        public Preferences()
        {
            InitializeComponent();
        }

        private void Numeric_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            //Regex regex = new Regex("^[0-9|\\+]+$"); //regex that matches disallowed text
            //e.Handled = regex.IsMatch(e.);
        }

        private void btnOK_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                SoundRepeatDuration.Text = int.Parse(SoundRepeatDuration.Text).ToString();
                SoundRepeeatNumber.Text = int.Parse(SoundRepeeatNumber.Text).ToString();
            }
            catch (Exception ex)
            {
                Debug.WriteLine("Prefs numeric error: Bad Value");
                SoundRepeeatNumber.Text = "1";
                SoundRepeatDuration.Text = "1";
            }

            Thread.Sleep(0);

            Settings.Set("HideFocusLost", (bool)HideFocusLost.IsChecked);
            Settings.Set("SmallIcons", (bool)SmallIcons.IsChecked);
            Settings.Set("HideAfterSelect", (bool)HideAfterSelect.IsChecked);
            Settings.Set("ShowTrayIcon", (bool)ShowTrayIcon.IsChecked);

            Settings.Set("FlashWindow", (bool)FlashWindow.IsChecked);
            Settings.Set("PlaySound", (bool)PlaySound.IsChecked);
            Settings.Set("SoundRepeat", (bool)SoundRepeat.IsChecked);

            Settings.Set("SoundRepeatDuration", SoundRepeatDuration.Text);
            Settings.Set("SoundRepeeatNumber", SoundRepeeatNumber.Text);

            Settings.Set("ShowAcceptedCall", (bool)ShowAcceptedCall.IsChecked);
            Settings.Set("ShowMissedCall", (bool)ShowMissedCall.IsChecked);
            Settings.Set("ShowPlacedCall", (bool)ShowPlacedCall.IsChecked);



            //Settings.Set("RunAtWindowsStartup", RunAtWindowsStartup.IsChecked);

            // handle startup
            /*
            try
            {
                string startupPath = Environment.GetFolderPath(Environment.SpecialFolder.Startup);
                startupPath = Path.Combine(startupPath, "GVNotifier") + ".lnk";
                if (Settings.Get("RunAtWindowsStartup", false))
                {
                    using (ShellLink shortcut = new ShellLink())
                    {
                        shortcut.Target = "http://www.daveamenta.com/gvnotifier/GVNotifier.net.application";
                        shortcut.Description = "GVNotifier";
                        shortcut.DisplayMode = ShellLink.LinkDisplayMode.edmNormal;
                        shortcut.Save(startupPath);
                    }
                }
                else
                {
                    File.Delete(startupPath);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine("run at startup error: " + ex);
            }
            */
            Settings.Save();
            Close();
        }
        /*
        public static void AddShortcutToStartupGroup(string productName, string contents, bool delete)
        {
            string startupPath = Environment.GetFolderPath(Environment.SpecialFolder.Startup);

            startupPath = Path.Combine(startupPath, productName) + ".appref-ms";
            try
            {
                if (delete)
                {
                    File.Delete(startupPath);
                }
                else
                {
                    File.WriteAllText(startupPath, contents);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine("Error adding item to startup: " + ex);
            }
        }
        */
        private void btnCancel_Click(object sender, RoutedEventArgs e)
        {
            // cancel
            Close();
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            // cancel
        }

        private void Hyperlink_RequestNavigate(object sender, System.Windows.Navigation.RequestNavigateEventArgs e)
        {
            this.Try(() => System.Diagnostics.Process.Start("http://daveamenta.com"));
        }

        private void Window_SourceInitialized(object sender, EventArgs e)
        {
            // load settings

            HideFocusLost.IsChecked = Settings.Get("HideFocusLost", false);
            SmallIcons.IsChecked = Settings.Get("SmallIcons", false);
            HideAfterSelect.IsChecked = Settings.Get("HideAfterSelect", false);
            ShowTrayIcon.IsChecked = Settings.Get("ShowTrayIcon", false);

            FlashWindow.IsChecked = Settings.Get("FlashWindow", false);
            PlaySound.IsChecked = Settings.Get("PlaySound", false);
            SoundRepeat.IsChecked = Settings.Get("SoundRepeat", false);
            SoundRepeatDuration.Text = Settings.Get("SoundRepeatDuration", 2).ToString();
            SoundRepeeatNumber.Text = Settings.Get("SoundRepeeatNumber", 2).ToString();

            ShowAcceptedCall.IsChecked = Settings.Get("ShowAcceptedCall", false);
            ShowMissedCall.IsChecked = Settings.Get("ShowMissedCall", false);
            ShowPlacedCall.IsChecked = Settings.Get("ShowPlacedCall", false);

            //RunAtWindowsStartup.IsChecked = Settings.Get("RunAtWindowsStartup", false);
        }
    }
}
