using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FormApplication
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // 1
        private void button2_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "1";
        }
        
        // 2
        private void button9_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "2";
        }

        // 3
        private void button6_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "3";
        }
        
        // 4
        private void button1_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "4";
        }
        
        // 5
        private void button8_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "5";
        }

        // 6
        private void button5_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "6";
        }

        // 7
        private void button3_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "7";
        }
       
        // 8
        private void button7_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "8";
        }

        // 9
        private void button4_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "9";
        }

        // 0
        private void button13_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "0";
        }

        // .
        private void button12_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + ".";
        }

        // =
        private void button11_Click(object sender, EventArgs e)
        {
            // 第一个操作数
            string sub1 = this.textBox1.Lines[0].ToString();
            string nor = this.textBox1.Lines[1].ToString(); // 运算符
            string sub2 = this.textBox1.Lines[2].ToString(); // 第二个操作数

            double x1 = 0, x2 = 0, y = 0;
            try
            {
                x1 = double.Parse(sub1);
                x2 = double.Parse(sub2);   
            }
            catch (Exception ex)
            {
                MessageBox.Show(this, "出错了\n" + ex.Message, "友情提示", MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
                return;
            }
            if (nor == "+")
            {
                y = x1 + x2;
            }
            if (nor == "-")
            {
                y = x1 - x2;
            }
            if (nor == "*")
            {
                y = x1 * x2;
            }
            if (nor == "/")
            {
                if (x2 == 0)
                {
                    MessageBox.Show(this, "出错了\n", "友情提示: 除数不能为0, 请重新输入！", MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
                    this.textBox1.Text = "";
                    return;
                }
                y = x1 / x2;
            }
            this.textBox1.Text = this.textBox1.Text + "\r\n=\r\n" + y.ToString("F2");
        }

        // +
        private void button10_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "\r\n+\r\n";
        }

        // -
        private void button16_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "\r\n-\r\n";
        }

        // *
        private void button15_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "\r\n*\r\n";
        }

        // /
        private void button14_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = this.textBox1.Text + "\r\n/\r\n";
        }

        // 清空
        private void button17_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = "";
        }

      

       

    }
}
