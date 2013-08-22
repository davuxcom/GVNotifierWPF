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

namespace GVNotifier
{
    /// <summary>
    /// Interaction logic for GetPin.xaml
    /// </summary>
    public partial class GetPin : Window
    {
        public GetPin()
        {
            InitializeComponent();

            Topmost = true;

            // NOTE: always call this on it's own UI thread
            Closed += (__, _) => Dispatcher.InvokeShutdown();
        }

        public string PIN
        {
            get
            {
                return txtPIN.Text;
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}
