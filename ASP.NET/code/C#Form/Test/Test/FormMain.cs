using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Test
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        private void buttonDo_Click(object sender, EventArgs e)
        {
            //this.textBox1.Text = "99999999999999";
            // 每年追加的投资
            double x1 = 0;
            double x2 = 0;  // 投资的年收益率
            int x3 = 0;  // 投资的年数
            try
            {
                x1 = double.Parse(this.textBox2.Text.Trim());
                x2 = double.Parse(this.textBox3.Text.Trim());
                x3 = int.Parse(this.textBox4.Text.Trim());
            }
            catch (Exception ex)
            {
                MessageBox.Show(this, "出错啰！" + ex.Message, "友情提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
           
            double sum = x1; // 初始化
            for (int i = 0; i < x3; i++)  // 循环计算总收益
            {
                sum = (sum + x1) * (1 + x2/100);
            }

            this.textBox1.Text = sum.ToString("F2"); // 展示总收益
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }
    }
}
