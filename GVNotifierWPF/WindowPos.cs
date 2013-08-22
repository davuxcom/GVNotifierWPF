using System;
using System.Diagnostics;
using System.Globalization;
using System.ComponentModel;
using System.Windows;
using System.Windows.Markup;
using System.Runtime.InteropServices;
using System.Windows.Interop;
using DavuxLib2;

namespace GVNotifier
{
    // TODO some people complained that this didn't work, and I didn't investigate
    // so I just pulled it out, I think.  Probably all dead code.

    /// <summary>
    /// Persists a Window's Size, Location and WindowState to UserScopeSettings 
    /// </summary>
    public class WindowPos
    {
        // RECT structure required by WINDOWPLACEMENT structure
        [Serializable]
        [StructLayout(LayoutKind.Sequential)]
        public struct RECT
        {
            public int Left;
            public int Top;
            public int Right;
            public int Bottom;

            public RECT(int left, int top, int right, int bottom)
            {
                this.Left = left;
                this.Top = top;
                this.Right = right;
                this.Bottom = bottom;
            }
        }

        // POINT structure required by WINDOWPLACEMENT structure
        [Serializable]
        [StructLayout(LayoutKind.Sequential)]
        public struct POINT
        {
            public int X;
            public int Y;

            public POINT(int x, int y)
            {
                this.X = x;
                this.Y = y;
            }
        }

        // WINDOWPLACEMENT stores the position, size, and state of a window
        [Serializable]
        [StructLayout(LayoutKind.Sequential)]
        public struct WINDOWPLACEMENT
        {
            public int length;
            public int flags;
            public int showCmd;
            public POINT minPosition;
            public POINT maxPosition;
            public RECT normalPosition;
        }

        #region Win32 API declarations to set and get window placement
        [DllImport("user32.dll")]
        static extern bool SetWindowPlacement(IntPtr hWnd, [In] ref WINDOWPLACEMENT lpwndpl);

        [DllImport("user32.dll")]
        static extern bool GetWindowPlacement(IntPtr hWnd, out WINDOWPLACEMENT lpwndpl);

        const int SW_SHOWNORMAL = 1;
        const int SW_SHOWMINIMIZED = 2;
        #endregion
        /*
        #region WindowApplicationSettings Helper Class
        public class WindowApplicationSettings : ApplicationSettingsBase
        {
            private WindowPos windowSettings;

            private string UID = "";

            public WindowApplicationSettings(WindowPos windowSettings)
                : base(windowSettings.window.Tag.ToString())
            {
                this.windowSettings = windowSettings;
                this.UID = windowSettings.window.Tag.ToString();
            }

            [UserScopedSetting]
            public WINDOWPLACEMENT Location
            {
                get
                {
                    if (this["Location"] != null)
                    {
                        return ((WINDOWPLACEMENT)this["Location"]);
                    }
                    return new WINDOWPLACEMENT();
                }
                set
                {
                    this["Location"] = value;
                }
            }

            [UserScopedSetting]
            public WindowState WindowState
            {
                get
                {
                    if (this["WindowState"] != null)
                    {
                        return (WindowState)this["WindowState"];
                    }
                    return WindowState.Normal;
                }
                set
                {
                    this["WindowState"] = value;
                }
            }

        }
        #endregion
        */

        #region Constructor
        private Window window = null;

        public WindowPos(Window window)
        {
            this.window = window;
        }

        #endregion

        #region Attached "Save" Property Implementation
        /// <summary>
        /// Register the "Save" attached property and the "OnSaveInvalidated" callback 
        /// </summary>
        public static readonly DependencyProperty SaveProperty
           = DependencyProperty.RegisterAttached("Save", typeof(bool), typeof(WindowPos),
                new FrameworkPropertyMetadata(new PropertyChangedCallback(OnSaveInvalidated)));

        public static void SetSave(DependencyObject dependencyObject, bool enabled)
        {
            dependencyObject.SetValue(SaveProperty, enabled);
        }

        /// <summary>
        /// Called when Save is changed on an object.
        /// </summary>
        private static void OnSaveInvalidated(DependencyObject dependencyObject, DependencyPropertyChangedEventArgs e)
        {
            Window window = dependencyObject as Window;
            if (window != null)
            {
                if ((bool)e.NewValue)
                {
                    WindowPos settings = new WindowPos(window);
                    settings.Attach();
                }
            }
        }

        #endregion

        #region Protected Methods
        /// <summary>
        /// Load the Window Size Location and State from the settings object
        /// </summary>
        protected virtual void LoadWindowState()
        {
            //this.Settings.Reload();



            try
            {
                // Load window placement details for previous application session from application settings
                // Note - if window was closed on a monitor that is now disconnected from the computer,
                //        SetWindowPlacement will place the window onto a visible monitor.
                WINDOWPLACEMENT wp = (WINDOWPLACEMENT)Settings.Get<WINDOWPLACEMENT>(window.Tag.ToString() + "_Placement", new WINDOWPLACEMENT(){ length =0});
                if (wp.length == 0)
                {
                    return;
                }
                wp.length = Marshal.SizeOf(typeof(WINDOWPLACEMENT));
                wp.flags = 0;
                wp.showCmd = (wp.showCmd == SW_SHOWMINIMIZED ? SW_SHOWNORMAL : wp.showCmd);
                IntPtr hwnd = new WindowInteropHelper(this.window).Handle;
                SetWindowPlacement(hwnd, ref wp);
            }
            catch { }



            /*
            if (this.Settings.Location != Rect.Empty)
            {
                this.window
                this.window.Left = this.Settings.Location.Left;
                this.window.Top = this.Settings.Location.Top;
                this.window.Width = this.Settings.Location.Width;
                this.window.Height = this.Settings.Location.Height;
            }

            if (this.Settings.WindowState != WindowState.Maximized)
            {
                this.window.WindowState = this.Settings.WindowState;
            }
            */
        }


        /// <summary>
        /// Save the Window Size, Location and State to the settings object
        /// </summary>
        protected virtual void SaveWindowState()
        {
            // FIXME: window state
            //this.Settings.WindowState = this.window.WindowState;
            //this.Settings.Location = this.window.RestoreBounds;

            // Persist window placement details to application settings
            WINDOWPLACEMENT wp = new WINDOWPLACEMENT();
            IntPtr hwnd = new WindowInteropHelper(this.window).Handle;
            GetWindowPlacement(hwnd, out wp);
            /*
            Properties.Settings.Default.WindowPlacement = wp;
            Properties.Settings.Default.Save();
            */
            Settings.Set<WINDOWPLACEMENT>(window.Tag.ToString() + "_Placement", wp);
        }
        #endregion

        #region Private Methods

        private void Attach()
        {
            if (this.window != null)
            {
                this.window.Closing += new CancelEventHandler(window_Closing);
                this.window.Initialized += new EventHandler(window_Initialized);
                this.window.Loaded += new RoutedEventHandler(window_Loaded);
            }
        }

        private void window_Loaded(object sender, RoutedEventArgs e)
        {
            LoadWindowState();
            /*
             * FIXME: no window state
            if (this.Settings.WindowState == WindowState.Maximized)
            {
                this.window.WindowState = this.Settings.WindowState;
            }
            */
        }

        private void window_Initialized(object sender, EventArgs e)
        {

        }

        private void window_Closing(object sender, CancelEventArgs e)
        {
            SaveWindowState();
        }
        #endregion
        /*
        #region Settings Property Implementation
        private WindowApplicationSettings windowApplicationSettings = null;

        protected virtual WindowApplicationSettings CreateWindowApplicationSettingsInstance()
        {
            return new WindowApplicationSettings(this);
        }

        [Browsable(false)]
        public WindowApplicationSettings Settings
        {
            get
            {
                if (windowApplicationSettings == null)
                {
                    this.windowApplicationSettings = CreateWindowApplicationSettingsInstance();
                }
                return this.windowApplicationSettings;
            }
        }
        #endregion
        */
    }
}