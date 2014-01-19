using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;

namespace GVNotifier
{
    // TODO I guess I used WinMM because everything else was a dependency that I didn't
    // want to take, but I'm really not sure why there isn't something better
    // this should be investigated.
    public class AudioPlayer : System.Windows.Forms.NativeWindow
    {
        public event Action PlayingCompleted;
        public event Action<int, int> PlayingProgressChanged;

        System.Windows.Forms.CreateParams cp = new System.Windows.Forms.CreateParams();

        private const int MM_MCINOTIFY = 953;

        [DllImport("winmm.dll")]
        private static extern long mciSendString(string strCommand, StringBuilder strReturn, int iReturnLength, IntPtr hwndCallback);

        public int Length = 0;
        private System.Windows.Forms.Timer timer = new System.Windows.Forms.Timer();

        public AudioPlayer()
        {
            this.CreateHandle(cp);

            timer.Tick += (ss, ee) =>
            {
                StringBuilder sb = new StringBuilder(255);
                mciSendString("status MediaFile position", sb, 255, Handle);
                int currentPosition = int.Parse(sb.ToString());
                if (PlayingProgressChanged != null)
                    PlayingProgressChanged(currentPosition, Length);
            };
        }


        public void Play(string mp3file)
        {
            Stop();
            mciSendString("open \"" + mp3file + "\" type mpegvideo alias MediaFile", null, 0, Handle);
            mciSendString("set MediaFile time format milliseconds", null, 0, Handle);

            StringBuilder sb = new StringBuilder(255);
            mciSendString("status MediaFile length", sb, 255, Handle);
            Length = int.Parse(sb.ToString());

            mciSendString("play MediaFile notify", null, 0, Handle);
            timer.Start();
        }

        public void Stop()
        {
            mciSendString("close MediaFile", null, 0, Handle);
            Length = 0;
            timer.Stop();
        }

        public void Pause()
        {
            mciSendString("pause MediaFile", null, 0, Handle);
        }

        public void Resume()
        {
            mciSendString("resume MediaFile", null, 0, Handle);
        }

        bool seeking = false;
        public void Seek(int pos)
        {
            seeking = true;
            Trace.WriteLine(mciSendString("seek MediaFile to " + pos, null, 0, Handle));
            Trace.WriteLine(mciSendString("play MediaFile notify", null, 0, Handle));
        }

        protected override void WndProc(ref System.Windows.Forms.Message m)
        {
            if (m.Msg == MM_MCINOTIFY)
            {
                if (seeking)
                {
                    seeking = false;
                    return;
                }
                if (PlayingCompleted != null)
                    PlayingCompleted();
                timer.Stop();
                Length = 0;
            }
            else
            {
                base.WndProc(ref m);
            }
        }
    }

}
