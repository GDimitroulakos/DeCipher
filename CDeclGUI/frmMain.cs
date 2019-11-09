using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace CDeclGUI
{
    public partial class frmMain : Form
    {
        // Set the newline variable;
        private static string nl = Environment.NewLine;

        // Get the exe path and the exe folder path.
        private static string m_ExePath = Application.ExecutablePath;
        private static string m_ExeDirPath = Path.GetDirectoryName(Application.ExecutablePath);

        // Execute an application
        private string m_executionDataExitCode = "";
        private string m_executionDataCmdOutput = "";
        private void runExeFile(string exeFile, string arguments)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = exeFile;
            startInfo.Arguments = arguments;
            startInfo.CreateNoWindow = true;
            startInfo.UseShellExecute = false;
            startInfo.RedirectStandardOutput = true;

            using (Process exeProcess = Process.Start(startInfo))
            {
                using (StreamReader reader = exeProcess.StandardOutput)
                {
                    exeProcess.WaitForExit();

                    string result = reader.ReadToEnd();

                    m_executionDataExitCode = exeProcess.ExitCode.ToString();
                    m_executionDataCmdOutput = result;
                }
            }
        }

        // ===========================================================================================================
        // ===========================================================================================================
        // ===========================================================================================================
        // ===========================================================================================================

        public frmMain()
        {
            InitializeComponent();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {

        }

        private void btnRun_Click(object sender, EventArgs e)
        {
            try
            {
                string inputCcode = txtInputCode.Text;
                string executable = m_ExeDirPath + @"\..\..\..\Debug\deCipher.exe";
                string input_file = m_ExeDirPath + "\\input_declarations.c";

                if (inputCcode == "")
                {
                    throw new ApplicationException("Please type some C code first.");
                }

                StreamWriter streamWriter = new StreamWriter(input_file);
                streamWriter.Write(inputCcode);
                streamWriter.Close();
                if (!File.Exists(input_file))
                {
                    throw new ApplicationException("Could not produce an input C file.");
                }

                string arguments = "\"" + input_file + "\"";
                runExeFile(executable, arguments);

                txtOutput.Text = m_executionDataCmdOutput;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Exception");
                //toolStripStatusLabel1.Text = "Run Process failed!";
                return;
            }

        }

        private void btnShowAbout_Click(object sender, EventArgs e)
        {
            frmAbout formAbout = new frmAbout();
            //formAbout.MdiParent = this;
            //formAbout.Show(this);
            formAbout.ShowDialog(); //Show the form as a Modal

            //Another way to show a form
            //formAbout.Visible = true;
        }
    }
}
