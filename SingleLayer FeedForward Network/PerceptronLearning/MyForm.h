#pragma once

#include <iostream> 
#include <stdlib.h>  
#include <stdio.h>  
#include <time.h>
#include <math.h>

#define PICTURE_BOX_HEIGHT 350
#define PICTURE_BOX_WIDTH  350
#define EPSILON            0.1
#define NORM_SIZE          20

#define x3   (-1)

namespace PerceptronLearning {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
		
			dimension = 0;
			class_size = 0;
			classPtr = NULL;
			size = NULL;
			label = NULL;
			weight = NULL;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		int dimension;      // dimesion
		int class_size;     // class number
		double **classPtr;  // class
		double **label;     // desired output
		double **weight;    // weight
		double c;           // learning contant
		int *size;
		int minx, miny, maxx, maxy;
		int **line;





	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;


	private: System::Windows::Forms::Label^  label8;



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel3;







			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->panel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 45);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"label3";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(350, 350);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::click_process);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::coordinate_paint);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 32);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"label5";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(284, 74);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"label8";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(179, 46);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Random";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button_Random);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(278, 46);
			this->button2->Name = L"button2";
			this->button2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Process";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button_Process);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(91, 53);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(70, 21);
			this->comboBox1->TabIndex = 20;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(91, 3);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(42, 20);
			this->numericUpDown1->TabIndex = 21;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label13->Location = System::Drawing::Point(3, 7);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(72, 16);
			this->label13->TabIndex = 22;
			this->label13->Text = L"Dimension";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label14->Location = System::Drawing::Point(3, 31);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(42, 16);
			this->label14->TabIndex = 23;
			this->label14->Text = L"Class";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(91, 27);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(42, 20);
			this->numericUpDown2->TabIndex = 24;
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2_ValueChanged);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->numericUpDown2);
			this->panel2->Controls->Add(this->numericUpDown1);
			this->panel2->Controls->Add(this->label14);
			this->panel2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel2->Location = System::Drawing::Point(353, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(360, 97);
			this->panel2->TabIndex = 25;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(180, 73);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(89, 17);
			this->checkBox1->TabIndex = 27;
			this->checkBox1->Text = L"Normalization";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(179, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(172, 40);
			this->groupBox1->TabIndex = 26;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Function";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(88, 17);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(78, 17);
			this->radioButton2->TabIndex = 26;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Continuous";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(1, 17);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(64, 17);
			this->radioButton1->TabIndex = 25;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Discrete";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(359, 105);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(103, 247);
			this->panel1->TabIndex = 26;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Location = System::Drawing::Point(472, 105);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(232, 247);
			this->panel3->TabIndex = 27;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(715, 357);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void click_process(System::Object^  sender, System::EventArgs^  e) {
		
		MouseEventArgs ^ m = (MouseEventArgs^)e;
		int id = comboBox1->SelectedIndex;

		if (classPtr[id] == NULL)
		{
			size[id] += dimension + 1;
			classPtr[id] = new double[size[id]];
		#if 1
			classPtr[id][size[id] - 3] = (double)((m->X) - PICTURE_BOX_WIDTH / 2);
			classPtr[id][size[id] - 2] = (double)(PICTURE_BOX_HEIGHT / 2 - (m->Y));
			classPtr[id][size[id] - 1] = (double)x3;
			
		#else		
			for (int i = 0; i < dimension + 1; i++)
				classPtr[0][size[0] - (dimension + 1 - i)] = i;
		#endif
		}
		else
		{
			double *t = new double[size[id]];
			int t1 = size[id];
			for (int i = 0; i < t1; i++)
				t[i] = classPtr[id][i];
			delete[]classPtr[id];
			size[id] += dimension + 1;
			classPtr[id] = new double[size[id]];
			for (int i = 0; i < t1; i++)
				classPtr[id][i] = t[i];
			delete[]t;

			#if 1
				classPtr[id][size[id] - 3] = (double)((m->X) - PICTURE_BOX_WIDTH / 2);
				classPtr[id][size[id] - 2] = (double)(PICTURE_BOX_HEIGHT / 2 - (m->Y));
				classPtr[id][size[id] - 1] = x3;

			#else		
				for (int i = 0; i < dimension + 1; i++)
					classPtr[0][size[0] - (dimension + 1 - i)] = i;
			#endif
		}
		pictureBox1->Refresh();

		label1->Text = "X: " + ((m->X) - PICTURE_BOX_WIDTH / 2).ToString();
		label2->Text = "Y: " + (PICTURE_BOX_HEIGHT / 2 - (m->Y)).ToString();

		label3->Text = "";
		for (int i = 0; i < class_size; i++)
			label3->Text += "Size" + (i + 1).ToString() + ": " + (size[i] / 3).ToString() + "\n";
	}

	private: System::Void coordinate_paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			
			Graphics^ g = e->Graphics;
			Pen^ pen = gcnew Pen(Color::Black, 2);
			// x line
			g->DrawLine(pen, PICTURE_BOX_WIDTH, PICTURE_BOX_HEIGHT / 2, 0, PICTURE_BOX_HEIGHT / 2);
			// x <- ->
			g->DrawLine(pen, 0, 175, 10, 170);
			g->DrawLine(pen, 0, 175, 10, 180);
			g->DrawLine(pen, 350, 175, 340, 170);
			g->DrawLine(pen, 350, 175, 340, 180);
			// y line
			g->DrawLine(pen, PICTURE_BOX_WIDTH / 2, PICTURE_BOX_HEIGHT, PICTURE_BOX_WIDTH / 2, 0);
			// y <- ->
			g->DrawLine(pen, 170, 10, 175, 0);
			g->DrawLine(pen, 180, 10, 175, 0);
			g->DrawLine(pen, 175, 350, 170, 340);
			g->DrawLine(pen, 175, 350, 180, 340);
			
			Pen^ p1 = gcnew Pen(Color::Black, 1);

			for (int i = 0; i < class_size; i++)
			{
				if (i == 0)
					p1->Color = Color::Red;
				else if(i == 1)
					p1->Color = Color::Green;
				else if(i == 2)
					p1->Color = Color::Blue;
				else if (i == 3)
					p1->Color = Color::Purple;
				else if (i == 4)
					p1->Color = Color::Yellow;
				else if (i == 5)
					p1->Color = Color::Cyan;

				if (checkBox1->Checked) {
					for (int j = 0; j < size[i]; j += dimension + 1)
					{
						int x = NORM_SIZE  * classPtr[i][j];
						x = (x + PICTURE_BOX_WIDTH / 2);
						int y = NORM_SIZE * classPtr[i][j + 1];
						y = (PICTURE_BOX_HEIGHT / 2 - y);
						g->DrawLine(p1, x + 3, y, x - 3, y);
						g->DrawLine(p1, x, y + 3, x, y - 3);
					}
				}
				else
				{
					for (int j = 0; j < size[i]; j += dimension + 1)
					{
						int x = classPtr[i][j];
						x = (x + PICTURE_BOX_WIDTH / 2);
						int y = classPtr[i][j + 1];
						y = (PICTURE_BOX_HEIGHT / 2 - y);
						g->DrawLine(p1, x + 3, y, x - 3, y);
						g->DrawLine(p1, x, y + 3, x, y - 3);
					}
				}
				
			}
			
			for (int i = 0; i < class_size; i++)
			{
				if (i == 0)
					p1->Color = Color::Red;
				else if (i == 1)
					p1->Color = Color::Green;
				else if (i == 2)
					p1->Color = Color::Blue;
				else if (i == 3)
					p1->Color = Color::Purple;
				else if (i == 4)
					p1->Color = Color::Yellow;
				else if (i == 5)
					p1->Color = Color::Cyan;
			}

			Pen^ p2 = gcnew Pen(Color::Blue, 2);
			if (class_size == 2) {
				
				g->DrawLine(p2, line[0][0] + PICTURE_BOX_WIDTH / 2, PICTURE_BOX_HEIGHT / 2 - line[0][1], line[0][2] + PICTURE_BOX_WIDTH / 2, PICTURE_BOX_HEIGHT / 2 - line[0][3]);
			}
			else if (class_size > 2) {

				for (int i = 0; i < class_size; i++)
				{
					if (i == 0)
						p2->Color = Color::Red;
					else if (i == 1)
						p2->Color = Color::Green;
					else if (i == 2)
						p2->Color = Color::Blue;
					else if (i == 3)
						p2->Color = Color::Purple;
					else if (i == 4)
						p2->Color = Color::Yellow;
					else if (i == 5)
						p2->Color = Color::Cyan;
					
					g->DrawLine(p2, line[i][0] + PICTURE_BOX_WIDTH / 2, PICTURE_BOX_HEIGHT / 2 - line[i][1], line[i][2] + PICTURE_BOX_WIDTH / 2, PICTURE_BOX_HEIGHT / 2 - line[i][3]);
				}
			}
	}			
	private: System::Void button_Random(System::Object^  sender, System::EventArgs^  e) {

		srand((unsigned int)time(NULL));

		c = (double)rand() / RAND_MAX;
		label4->Text = "c = " + c.ToString();

		label5->Text = "";
		if (class_size == 2) {
			for (int i = 0; i < dimension + 1; i++) {
				weight[0][i] = (double)rand() / RAND_MAX;
				label5->Text += "w" + (i+1).ToString() + "= " + weight[0][i].ToString() + "\n";
			}
			line[0][0] = PICTURE_BOX_WIDTH / -2;                                                        // minx
			line[0][1] = -(weight[0][0] * PICTURE_BOX_WIDTH / -2 + x3 * weight[0][2]) / weight[0][1];   // miny
			line[0][2] = PICTURE_BOX_WIDTH / 2;														    // maxx
			line[0][3] = -(weight[0][0] * PICTURE_BOX_WIDTH / 2 + x3 * weight[0][2]) / weight[0][1];	// maxy
		}

		else if (class_size > 2)
		{
			for (int i = 0; i < class_size; i++)
			{
				for (int j = 0; j < dimension + 1; j++) {
					weight[i][j] = (double)rand() / RAND_MAX;
					label5->Text += "w" + (i + 1).ToString() + (j + 1).ToString() + "= " + weight[0][j].ToString() + "\n";
				}
				line[i][0] = PICTURE_BOX_WIDTH / -2;                                                        // minx
				line[i][1] = -(weight[i][0] * PICTURE_BOX_WIDTH / -2 + x3 * weight[i][2]) / weight[i][1];   // miny
				line[i][2] = PICTURE_BOX_WIDTH / 2;														    // maxx
				line[i][3] = -(weight[i][0] * PICTURE_BOX_WIDTH / 2 + x3 * weight[i][2]) / weight[i][1];	// maxy
			}

		}

		pictureBox1->Refresh();

	}

	private: System::Void button_Process(System::Object^  sender, System::EventArgs^  e) 
	{
		double error;
		int cycle = 0;
		
		if (class_size == 2)
		{
			label[0] = new double(1.0);
			label[1] = new double(-1.0);
			while (true)
			{
				error = 0.0;
				for (int i = 0; i < class_size; i++)
				{

					for (int j = 0; j < size[i]; j += (dimension + 1))
					{

						double net = 0;
						double output = 0;
						double *delta_weight = new double[dimension + 1];

						for (int k = 0; k < dimension + 1; k++) {
							delta_weight[k] = 0;
							net += weight[0][k] * classPtr[i][j + k];
						}

						// bipolar binary sign function
						if (radioButton1->Checked)
						{
							if (net >= 0.0)
								output = 1.0;
							else
								output = -1.0;

							for (int k = 0; k < dimension + 1; k++) {
								delta_weight[k] = c * (label[i][0] - output) * classPtr[i][j + k];
								weight[0][k] += delta_weight[k];
							}

						}
						// bipolar continous sigmoid function
						else if (radioButton2->Checked)
						{
							output = (2.0 / (1.0 + exp(-1.0 * net))) - 1.0;
							double derivative = (1 - pow(output, 2)) / 2.0;
							for (int k = 0; k < dimension + 1; k++) {
								delta_weight[k] = c * (label[i][0] - output) * derivative * classPtr[i][j + k];
								weight[0][k] += delta_weight[k];
							}
						}
						delete[] delta_weight;

						if (checkBox1->Checked)
						{
							// g(x) = w1x1 + w2x2 + x3w3
							line[0][0] = PICTURE_BOX_WIDTH / -2;
							line[0][1] = -(weight[0][0] * PICTURE_BOX_WIDTH / -2 + x3 * weight[0][2] * NORM_SIZE) / weight[0][1];
							line[0][2] = PICTURE_BOX_WIDTH / 2;
							line[0][3] = -(weight[0][0] * PICTURE_BOX_WIDTH / 2 + x3 * weight[0][2] * NORM_SIZE) / weight[0][1];
						}
						else
						{
							line[0][0] = PICTURE_BOX_WIDTH / -2;
							line[0][1] = -(weight[0][0] * PICTURE_BOX_WIDTH / -2 + x3 * weight[0][2]) / weight[0][1];
							line[0][2] = PICTURE_BOX_WIDTH / 2;
							line[0][3] = -(weight[0][0] * PICTURE_BOX_WIDTH / 2 + x3 * weight[0][2]) / weight[0][1];
						}

						label5->Text = "";
						for (int i = 0; i < dimension + 1; i++)		
							label5->Text += "w" + (i + 1).ToString() + "= " + weight[0][i].ToString() + "\n";

						pictureBox1->Refresh();
					
						// bipolar binary function
						if (radioButton1->Checked) {
							error += abs(label[i][0] - output) / 2.0;
						}

						// bipolar continous sigmoid function
						else if (radioButton2->Checked)
						{
							error += pow(label[i][0] - output, 2) / 2.0;
						}
					}
				}
				cycle++;
				label8->Text = "Cycle: " + cycle.ToString();
				label8->Refresh();

				// bipolar binary function
				if (radioButton1->Checked) {
					if (error == 0)
						break;
				}

				// bipolar continous sigmoid function
				else if (radioButton2->Checked)
				{
					if (error < EPSILON)
						break;
				}
			}
		}
		else if (class_size > 2)
		{
			for (int i = 0; i < class_size; i++)
			{
				label[i] = new double[class_size];
				for (int j = 0; j < class_size; j++)
				{
					if (j == i)
						label[i][j] = +1.0;
					else
						label[i][j] = -1.0;
				}
			}
			
			double *output = NULL;
			while (true)
			{
				error = 0.0;
				for (int i = 0; i < class_size; i++)
				{
					for (int j = 0; j < size[i]; j += (dimension + 1))
					{
						output = new double[class_size];
						for (int l = 0; l < class_size; l++)
						{
							output[l] = 0;
							for (int k = 0; k < dimension + 1; k++) {
								output[l] += weight[l][k] * classPtr[i][j + k];
							}
							// bipolar binary sign function
							if (radioButton1->Checked)
							{
								if (output[l] >= 0)
									output[l] = 1.0;
								else
									output[l] = -1.0;
							}
							// bipolar continous sigmoid function
							else if (radioButton2->Checked)
							{
								output[l] = (2.0 / (1.0 + exp(-1.0 * output[l]))) - 1.0;
							}
						}

						for (int l = 0; l < class_size; l++)
						{
							if (radioButton1->Checked)
							{
								error += 0.5 * pow(label[i][l] - output[l], 2);
								for (int k = 0; k < dimension + 1; k++) {
									weight[l][k] += (c / 2) * (label[i][l] - output[l]) * classPtr[i][j + k];
								}
							}
							else if (radioButton2->Checked)
							{
								error += 0.5 * pow(label[i][l] - output[l], 2);
								double turev = (1 - pow(output[l], 2)) / 2;
								for (int k = 0; k < dimension + 1; k++) {
									weight[l][k] += (c / 2) * (label[i][l] - output[l]) * turev * classPtr[i][j + k];
								}
							}
							
						}
						delete[]output;

					}
				}
				cycle++;
				label8->Text = "Cycle: " + cycle.ToString();
				label8->Refresh();

				for (int i = 0; i < class_size; i++)
				{
					if (checkBox1->Checked)
					{
						line[i][0] = PICTURE_BOX_WIDTH / -2;                                                                    // minx
						line[i][1] = -(weight[i][0] * PICTURE_BOX_WIDTH / -2 + x3 * weight[i][2] * NORM_SIZE) / weight[i][1];   // miny
						line[i][2] = PICTURE_BOX_WIDTH / 2;														                // maxx
						line[i][3] = -(weight[i][0] * PICTURE_BOX_WIDTH / 2 + x3 * weight[i][2] * NORM_SIZE) / weight[i][1];	// maxy
					}
					else
					{
						line[i][0] = PICTURE_BOX_WIDTH / -2;                                                        // minx
						line[i][1] = -(weight[i][0] * PICTURE_BOX_WIDTH / -2 + x3 * weight[i][2]) / weight[i][1];   // miny
						line[i][2] = PICTURE_BOX_WIDTH / 2;														    // maxx
						line[i][3] = -(weight[i][0] * PICTURE_BOX_WIDTH / 2 + x3 * weight[i][2]) / weight[i][1];	// maxy
					}

					pictureBox1->Refresh();
				}
				if (radioButton1->Checked)
				{
					if (error == 0)
						break;
				}	
				else if (radioButton2->Checked)
				{
					if (error < EPSILON)
						break;
				}	
			}
		}
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		dimension = (int)numericUpDown1->Value;
	}
	private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

		class_size = (int)numericUpDown2->Value;

		classPtr = new double*[class_size];
		label = new double*[class_size];
		size = new int[class_size];
		

		if (class_size == 2) {
			line = new int*[1];
			line[0] = new int[4];
			weight    = new double*[1];
			weight[0] = new double[3];
			for (int i = 0; i < dimension + 1; i++)
				weight[0][i] = 0;
		}
		else if (class_size > 2) {
			weight = new double*[class_size];
			line = new int*[class_size];
			for (int i = 0; i < class_size; i++) {
				line[i] = new int[4];
				weight[i] = new double[3];
				for (int j = 0; j < dimension + 1; j++)
					weight[i][j] = 0;
			}	
		}

		comboBox1->Items->Clear();
		for (int i = 0; i < class_size; i++)
		{		
			comboBox1->Items->Add("Class " + (i + 1));
			classPtr[i] = NULL;
			size[i] = 0;
		}
		
	}

	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		
		double sumX = 0, sumY = 0, sum2X = 0, sum2Y = 0;
		double averageX = 0, averageY = 0;
		double varianceX = 0, varianceY = 0;
		int pointNum = 0;

		for (int i = 0; i < class_size; i++)
		{
			for (int j = 0; j < size[i]; j += (dimension + 1))
			{
				sumX += classPtr[i][j];
				sumY += classPtr[i][j + 1];
			}
			pointNum += size[i] / 3;

		}
		averageX = sumX / pointNum;
		averageY = sumY / pointNum;
		
		for (int i = 0; i < class_size; i++)
		{
			for (int j = 0; j < size[i]; j += dimension + 1)
			{
				sum2X += pow(averageX - classPtr[i][j], 2);
				sum2Y += pow(averageY - classPtr[i][j + 1], 2);
			}
		}
		varianceX = sqrt(sum2X / pointNum - 1);
		varianceY = sqrt(sum2Y / pointNum - 1);

		for (int i = 0; i < class_size; i++)
		{
			for (int j = 0; j < size[i]; j += dimension + 1)
			{
				classPtr[i][j]   = (classPtr[i][j]   - averageX) / varianceX;
				classPtr[i][j+1] = (classPtr[i][j+1] - averageY) / varianceY;
			}	
		}

		pictureBox1->Refresh();
	}

};
}