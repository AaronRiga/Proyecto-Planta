using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;


namespace ServoP
{
    public partial class Form1: Form
    {
        SerialPort serialPort;
        public Form1()
        {
            InitializeComponent();
            serialPort = new SerialPort("COM3", 9600); // Ajusta COM según tu Arduino
            serialPort.Open();
            label4.Visible = true;
            label4.Text = "El servomotor está a 0°";
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            string valor = trackBar1.Value.ToString();
            serialPort.Write(valor); // Enviar valor al Arduino
            if (trackBar1.Value == 0) {
                label4.Visible = true;
                label4.Text = "El servomotor está a 0°";
            }

            else if (trackBar1.Value == 1)
            {
                label4.Visible = true;
                label4.Text = "El servomotor está a 45°";
                
            }
                
            else if (trackBar1.Value == 2)
            {
                label4.Visible = true;
                label4.Text = "El servomotor está a 90°";
            }
               
            else if (trackBar1.Value == 3)
            {
                label4.Visible = true;
                label4.Text = "El servomotor está a 180°";
            }
                
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (serialPort.IsOpen)
                serialPort.Close();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
