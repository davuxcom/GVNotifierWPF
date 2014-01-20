using DavuxLib2;
using DavuxLib2.Extensions;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Input;

namespace GVNotifier
{
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
            catch (Exception)
            {
                Trace.WriteLine("Prefs numeric error: Bad Value");
                SoundRepeeatNumber.Text = "1";
                SoundRepeatDuration.Text = "1";
            }

            Hide();

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

            Settings.Save();
            Close();
        }
        
        private void btnCancel_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void Hyperlink_RequestNavigate(object sender, System.Windows.Navigation.RequestNavigateEventArgs e)
        {
           this.Try(() => System.Diagnostics.Process.Start(DavuxLib2.App.DataDirectory));
        }

        private void Window_SourceInitialized(object sender, EventArgs e)
        {
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
        }
    }
}
