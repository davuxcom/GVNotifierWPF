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
using DavuxLib2;

namespace GVNotifier
{
    public partial class Welcome : Window
    {
        public Welcome()
        {
            InitializeComponent();
        }

        private void Hyperlink_RequestNavigate(object sender, System.Windows.Navigation.RequestNavigateEventArgs e)
        {
            this.Try(() => System.Diagnostics.Process.Start("http://daveamenta.com"));
        }

        private void Image_MouseDown(object sender, MouseButtonEventArgs e)
        {
            this.Try(() => System.Diagnostics.Process.Start("http://daveamenta.com/donate"));
        }

        private void btnOK_Click(object sender, RoutedEventArgs e)
        {
            Settings.Set("donate14", true);
            Close();
        }

        private void btnCancel_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}
