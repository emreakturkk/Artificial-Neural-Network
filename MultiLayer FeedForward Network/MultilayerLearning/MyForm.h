#pragma once

#include <iostream> 
#include <stdlib.h>  
#include <stdio.h>  
#include <time.h>
#include <math.h>
#include <windows.h>

#define PICTURE_BOX_HEIGHT 350
#define PICTURE_BOX_WIDTH  350
#define EPSILON            0.1
#define NORM_SIZE          50
#define BIAS               1.0

namespace MultilayerLearning {

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
			//TODO: Add the constructor code here
			// init variables
			dimension = 2;
			classSize = 0;
			classPtr = NULL;
			hiddenNeuron = 0;
			V = NULL;
			W = NULL;
			size = NULL;
			label = NULL;
			c1 = c2 = m = 0;

			averageX = 0.0;
			averageY = 0.0;
			varianceX = 0.0; 
			varianceY = 0.0;
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

		int dimension;       // Giriþ Uzayý Boyutu
		int classSize;       // Sýnýf Sayýsý
		int *size;			 // Sýnýflarýn Örnek Sayýlarý
		int hiddenNeuron;    // Ara Katman Nöron Sayýsý
		double **classPtr;   // Sýnýflarýn Örneklerini Tutan Pointer
		double **label;      // Ýstenilen Çýkýþ Etiketi
		double **V;          // Ara Katman Aðýrlýklarý
		double **W;          // Çýkýþ Katman Aðýrlýklarý
		double c1, c2;       // Öðrenme Katsayýlarý
		double m;            // Moment Katsayýsý
		double averageX, averageY;
		double varianceX, varianceY;

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
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Label^  label7;
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
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->panel2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 57);
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
			this->label4->Location = System::Drawing::Point(129, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(316, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"label5";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(10, 120);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"label8";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(276, 39);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Random";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button_Random);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(276, 68);
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
			this->comboBox1->Location = System::Drawing::Point(79, 61);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(70, 21);
			this->comboBox1->TabIndex = 20;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label14->Location = System::Drawing::Point(5, 33);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(42, 16);
			this->label14->TabIndex = 23;
			this->label14->Text = L"Class";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(107, 33);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(42, 20);
			this->numericUpDown2->TabIndex = 24;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->numericUpDown3);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->numericUpDown2);
			this->panel2->Controls->Add(this->label14);
			this->panel2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel2->Location = System::Drawing::Point(353, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(361, 149);
			this->panel2->TabIndex = 25;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(10, 95);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"label7";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton4);
			this->groupBox2->Controls->Add(this->radioButton3);
			this->groupBox2->Location = System::Drawing::Point(159, 77);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(112, 69);
			this->groupBox2->TabIndex = 33;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Method";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(7, 39);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(77, 17);
			this->radioButton4->TabIndex = 1;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Momentum";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(7, 16);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(48, 17);
			this->radioButton3->TabIndex = 0;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"SDG";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(159, 7);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(112, 64);
			this->groupBox1->TabIndex = 32;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Function";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(7, 39);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(60, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"sigmoid";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(7, 15);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(46, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"tanh";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(276, 10);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Set Values";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button_SetValue);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(276, 97);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 31;
			this->button3->Text = L"Test";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button_Test);
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(107, 7);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(42, 20);
			this->numericUpDown3->TabIndex = 30;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->Location = System::Drawing::Point(5, 7);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(99, 16);
			this->label6->TabIndex = 29;
			this->label6->Text = L"Hidden Neuron";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Location = System::Drawing::Point(353, 157);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(642, 369);
			this->panel3->TabIndex = 27;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1045, 563);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button_SetValue(System::Object^  sender, System::EventArgs^  e) {

		classSize    = (int)numericUpDown2->Value;
		hiddenNeuron = (int)numericUpDown3->Value;

		classPtr = new double*[classSize];
		label = new double*[classSize];
		size = new int[classSize];
		V = new double *[hiddenNeuron];
		line = new int*[hiddenNeuron];

		for (int i = 0; i < hiddenNeuron; i++) {
			line[i] = new int[4];
			V[i] = new double[dimension + 1];
		}

		if (classSize == 2) {
			W = new double*[classSize - 1];
			W[0] = new double[hiddenNeuron + 1];
		}
		else if (classSize > 2) {
			W = new double*[classSize];
			for (int i = 0; i < classSize; i++)
				W[i] = new double[hiddenNeuron + 1];
		}

		comboBox1->Items->Clear();
		for (int i = 0; i < classSize; i++)
		{
			comboBox1->Items->Add("Class " + (i + 1));
			classPtr[i] = NULL;
			size[i] = 0;
		}

	}
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
			classPtr[id][size[id] - 1] = (double)BIAS;
			
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
				classPtr[id][size[id] - 1] = BIAS;

			#else		
				for (int i = 0; i < dimension + 1; i++)
					classPtr[0][size[0] - (dimension + 1 - i)] = i;
			#endif
		}
		pictureBox1->Refresh();

		label1->Text = "X: " + ((m->X) - PICTURE_BOX_WIDTH / 2).ToString();
		label2->Text = "Y: " + (PICTURE_BOX_HEIGHT / 2 - (m->Y)).ToString();

		label3->Text = "";
		for (int i = 0; i < classSize; i++)
			label3->Text += "Size" + (i + 1).ToString() + ": " + (size[i] / 3).ToString() + "\n";
	}

	private: System::Void button_Random(System::Object^  sender, System::EventArgs^  e) 
	{
		srand((unsigned int)time(NULL));

		c1 = (double)rand() / RAND_MAX;
		c2 = (double)rand() / RAND_MAX;
		m =  (double)rand() / RAND_MAX;

		label4->Text = "c1 : " + c1.ToString() + "\n" + "c2 : " + c2.ToString() + "\n" + "m : " + m.ToString();

		for (int i = 0; i < hiddenNeuron; i++) 
		{
			for (int j = 0; j < dimension + 1; j++) {
				if(j == dimension)
					V[i][j] = BIAS * (double)rand() / RAND_MAX;
				else
					V[i][j] = (double)rand() / RAND_MAX;
			}
			
			line[i][0] = PICTURE_BOX_WIDTH / -2;                                          // minx
			line[i][1] = -(V[i][0] * PICTURE_BOX_WIDTH / -2 + BIAS * V[i][2]) / V[i][1];  // miny
			line[i][2] = PICTURE_BOX_WIDTH / 2;											  // maxx
			line[i][3] = -(V[i][0] * PICTURE_BOX_WIDTH /  2 + BIAS * V[i][2]) / V[i][1];  // maxy
		}
		/*
		label5->Text = "";
		for (int i = 0; i < hiddenNeuron; i++)
				for (int j = 0; j < dimension + 1; j++)
					label5->Text += "V" + (i + 1).ToString() + (j + 1).ToString() + "= " + V[i][j].ToString() + "\n";
		*/

		if (classSize == 2) {
			for (int i = 0; i < hiddenNeuron + 1; i++) {
				if (i == hiddenNeuron)
					W[0][i] = BIAS * (double)rand() / RAND_MAX;
				else
					W[0][i] = (double)rand() / RAND_MAX;
			}
		}
		else if (classSize > 2)
		{
			for (int i = 0; i < classSize; i++)
			{
				for (int j = 0; j < hiddenNeuron + 1; j++) {
					if (j == hiddenNeuron)
						W[i][j] = BIAS * (double)rand() / RAND_MAX;
					else
						W[i][j] = (double)rand() / RAND_MAX;
				}
			}
		}
		/*
		//for (int i = 0; i < classSize; i++)
			for (int j = 0; j < hiddenNeuron + 1; j++)
				label5->Text += "W" + (0 + 1).ToString() + (j + 1).ToString() + "= " + W[0][j].ToString() + "\n";
		*/
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
			
			Pen^ p1 = gcnew Pen(Color::Black, 2);

			for (int i = 0; i < classSize; i++)
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
					p1->Color = Color::Cyan;
				else if (i == 5)
					p1->Color = Color::Yellow;

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

#if 0
			Pen^ p2 = gcnew Pen(Color::Black, 2);
			for (int i = 0; i < hiddenNeuron; i++)
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
#endif
	}			

	private: System::Void button_Process(System::Object^  sender, System::EventArgs^  e) 
	{

		// Normalizasyon
		double sumX = 0, sumY = 0, sum2X = 0, sum2Y = 0;
		int pointNum = 0;

		for (int i = 0; i < classSize; i++)
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

		for (int i = 0; i < classSize; i++)
		{
			for (int j = 0; j < size[i]; j += (dimension + 1))
			{
				sum2X += pow(averageX - classPtr[i][j], 2);
				sum2Y += pow(averageY - classPtr[i][j + 1], 2);
			}
		}

		varianceX = sqrt(sum2X / pointNum - 1);
		varianceY = sqrt(sum2Y / pointNum - 1);
		
		// Process
		int cycle = 0;
		int I = dimension + 1;
		int J = hiddenNeuron;
		int K;

		if (classSize == 2) {
			K = 1;
			label[0] = new double(1.0);
			label[1] = new double(-1.0);
		}		
		else {
			K = classSize;

			for (int i = 0; i < classSize; i++)
			{
				label[i] = new double[classSize];
				for (int j = 0; j < classSize; j++)
				{
					if (j == i)
						label[i][j] =  1.0;
					else
						label[i][j] = -1.0;
				}
			}
		}

		double** tempW = new double*[K];
		double** tempV = new double*[J];

		for (int k = 0; k < K; k++)
			tempW[k] = new double[J + 1];

		for (int j = 0; j < J; j++)
			tempV[j] = new double[I];

		double error;
		double *net, *y;
		double* net1, *output;
		double* point;
		int flag = 0;

		while (true)
		{
			error = 0.0;
			// Cycle Baþlangýcý
			
			for (int m = 0; m < classSize; m++)
			{
				for (int n = 0; n < size[m]; n += I)
				{
					point = new double[I];
					point[0] = (classPtr[m][n]   - averageX) / varianceX;
					point[1] = (classPtr[m][n+1] - averageY) / varianceY;
					point[2] = BIAS;

					// Step Baþlangýcý

					/** Forward Phase **/

					net = new double[J];
					y   = new double[J + 1];

					for (int j = 0; j < J; j++)
					{
						net[j] = 0;
						for (int i = 0; i < I; i++)
							net[j] += V[j][i] * point[i];
						if(radioButton1->Checked)
							y[j] = tanh(net[j]);
						else if (radioButton2->Checked)
							y[j] = (2.0 / (1.0 + exp(-1.0 * net[j]))) - 1.0;
					}
					y[J] = BIAS;

					net1 = new double[K];
					output = new double[K];

					for (int k = 0; k < K; k++)
					{
						net1[k] = 0;
						for (int j = 0; j < J + 1; j++)
							net1[k] += W[k][j] * y[j];
						if (radioButton1->Checked)
							output[k] = tanh(net1[k]);
						else if(radioButton2->Checked)
							output[k] = (2.0 / (1.0 + exp(-1.0 * net1[k]))) - 1.0;
					}

					// Hata Hesaplama
					double sum = 0;
					for (int k = 0; k < K; k++) 
						sum += pow(label[m][k] - output[k], 2);
					error += 0.5 * sum;

					/** Backward Phase **/

					/** SGD Method **/
					if (radioButton3->Checked)
					{
						// Çýkýþ Katmaný Güncelleme
						for (int k = 0; k < K; k++)
							for (int j = 0; j < J + 1; j++) {
								if (radioButton1)
									W[k][j] += (c1 * (label[m][k] - output[k]) * (1.0 - pow(tanh(net1[k]), 2.0)) * y[j]);
								else if (radioButton2)
									W[k][j] += (c1 * (label[m][k] - output[k]) * (0.5 * (1.0 - pow(output[k], 2.0))) * y[j]);
							}	

						// Ara Katmaný Güncelleme
						for (int j = 0; j < J; j++)
						{
							double sum1 = 0;
							for (int k = 0; k < K; k++) {
								if (radioButton1)
									sum1 += (label[m][k] - output[k]) * (1.0 - pow(tanh(net1[k]), 2.0)) * W[k][j];
								else if(radioButton2)
									sum1 += (label[m][k] - output[k]) * (0.5 * (1.0 - pow(output[k], 2.0))) * W[k][j];
							}
							for (int i = 0; i < I; i++) {
								if (radioButton1)
									V[j][i] += (c2 * (1.0 - pow(tanh(net[j]), 2.0)) * point[i] * sum1);
								else if (radioButton2)
									V[j][i] += (c2 * (0.5 * (1.0 - pow(y[j], 2.0))) * point[i] * sum1);
							}			
						}
					}
					/** Momentum Method **/
					else if(radioButton4->Checked)
					{
						if (!flag) 
						{
							// Çýkýþ Katmaný Güncelleme
							for (int k = 0; k < K; k++)
								for (int j = 0; j < J + 1; j++) {
									double t;
									if (radioButton1->Checked) {
										t = (c1 * (label[m][k] - output[k]) * (1.0 - pow(tanh(net1[k]), 2.0)) * y[j]);
										W[k][j] += t;
										tempW[k][j] = t;
									}
									else if (radioButton2->Checked)
									{
										t = (c1 * (label[m][k] - output[k]) * (0.5 * (1.0 - pow(output[k], 2.0))) * y[j]);
										W[k][j] += t;
										tempW[k][j] = t;
									}
								}
							// Ara Katmaný Güncelleme
							for (int j = 0; j < J; j++)
							{
								double sum1 = 0;
								for (int k = 0; k < K; k++) {
									if (radioButton1->Checked)
										sum1 += (label[m][k] - output[k]) * (1.0 - pow(tanh(net1[k]), 2.0)) * W[k][j];
									else if (radioButton2->Checked)
										sum1 += (label[m][k] - output[k]) * (0.5 * (1.0 - pow(output[k], 2.0))) * W[k][j];
								}
								for (int i = 0; i < I; i++) 
								{
									double t;
									if (radioButton1->Checked)
									{
										t = (c2 * (1.0 - pow(tanh(net[j]), 2.0)) * point[i] * sum1);
										V[j][i] += t;
										tempV[j][i] = t;
									}
									else if (radioButton2->Checked)
									{
										t = (c2 * (0.5 * (1.0 - pow(y[j], 2.0))) * point[i] * sum1);
										V[j][i] += t;
										tempV[j][i] = t;
									}
								}	
							}
							flag = 1;
						}
						else {
							// Çýkýþ Katmaný Güncelleme
							for (int k = 0; k < K; k++)
								for (int j = 0; j < J + 1; j++) {
									double t;
									if (radioButton1->Checked) {
										t = (c1 * (label[m][k] - output[k]) * (1.0 - pow(tanh(net1[k]), 2.0)) * y[j]);
										W[k][j] += (t + m * tempW[k][j]);
										tempW[k][j] = (t + m * tempW[k][j]);
									}
									else if (radioButton2->Checked)
									{
										t = (c1 * (label[m][k] - output[k]) * (0.5 * (1.0 - pow(output[k], 2.0))) * y[j]);
										W[k][j] += (t + m * tempW[k][j]);
										tempW[k][j] = (t + m * tempW[k][j]);
									}
								}
							// Ara Katmaný Güncelleme
							for (int j = 0; j < J; j++)
							{
								double sum1 = 0;
								for (int k = 0; k < K; k++) {
									if (radioButton1->Checked)
										sum1 += (label[m][k] - output[k]) * (1.0 - pow(tanh(net1[k]), 2.0)) * W[k][j];
									else if (radioButton2->Checked)
										sum1 += (label[m][k] - output[k]) * (0.5 * (1.0 - pow(output[k], 2.0))) * W[k][j];
								}
								for (int i = 0; i < I; i++)
								{
									double t;
									if (radioButton1->Checked)
									{
										t = (c2 * (1.0 - pow(tanh(net[j]), 2.0)) * point[i] * sum1);
										V[j][i] += t;
										tempV[j][i] = t;
									}
									else if (radioButton2->Checked)
									{
										t = (c2 * (0.5 * (1.0 - pow(y[j], 2.0))) * point[i] * sum1);
										V[j][i] += (t + m * tempV[j][i]);
										tempV[j][i] = (t + m * tempV[j][i]);
									}
								}

							}
						}
					}
#if 0
					for (int j = 0; j < J; j++)
					{
						line[j][0] = PICTURE_BOX_WIDTH / -2;
						line[j][1] = -(V[j][0] * PICTURE_BOX_WIDTH / -2 + BIAS * V[j][2] * NORM_SIZE) / V[j][1];
						line[j][2] = PICTURE_BOX_WIDTH / 2;
						line[j][3] = -(V[j][0] * PICTURE_BOX_WIDTH /  2 + BIAS * V[j][2] * NORM_SIZE) / V[j][1];

					}
					pictureBox1->Refresh();
#endif
				}	
			}
			cycle++;
			label7->Text = "Cycle: " + cycle.ToString();
			label8->Text = "Error: " + error.ToString();
			label7->Refresh();
			label8->Refresh();

			delete net;
			delete net1;
			delete y;
			delete output;
			delete point;

			/*
			label5->Text = "";
			for (int i = 0; i < hiddenNeuron; i++)
				for (int j = 0; j < dimension + 1; j++)
					label5->Text += "V" + (i + 1).ToString() + (j + 1).ToString() + "= " + V[i][j].ToString() + "\n";
			//for (int i = 0; i < classSize; i++)
				for (int j = 0; j < hiddenNeuron + 1; j++)
					label5->Text += "W" + (0 + 1).ToString() + (j + 1).ToString() + "= " + W[0][j].ToString() + "\n";

			label5->Refresh();
			*/

			if (error < EPSILON || cycle > 5000)
			{
				/*for (int k = 0; k < K; k++)
					delete tempW[k];
				for (int j = 0; j < J; j++)
					delete tempV[j];*/

				break;
			}

		}
	}private: System::Void button_Test(System::Object^  sender, System::EventArgs^  e) {

		int I = dimension + 1;
		int J = hiddenNeuron;
		int K;

		if (classSize == 2)
			K = 1;
		else
			K = classSize;

		Bitmap^ draw = gcnew Bitmap(PICTURE_BOX_WIDTH, PICTURE_BOX_HEIGHT);
		pictureBox1->Image = draw;
		Color c = Color::Black;
		
		double *net, *y;
		double* net1, *output;
		double* point;

		for (int m = 0; m < PICTURE_BOX_HEIGHT; m+=2)
		{
			for (int n = 0; n < PICTURE_BOX_WIDTH; n+=2)
			{
				double x1 = n - PICTURE_BOX_WIDTH / 2;
				double y1 = PICTURE_BOX_HEIGHT / 2 - m;

				point = new double[I];
				point[0] = (x1 - averageX) / varianceX;
				point[1] = (y1 - averageY) / varianceY;
				point[2] = BIAS;

				net = new double[J];
				y = new double[J + 1];

				for (int j = 0; j < J; j++)
				{
					net[j] = 0;
					for (int i = 0; i < I; i++)
						net[j] += V[j][i] * point[i];

					if (radioButton1->Checked)
						y[j] = tanh(net[j]);
					else if (radioButton2->Checked)
						y[j] = (2.0 / (1.0 + exp(-1.0 * net[j]))) - 1.0;
				}
				y[J] = BIAS;

				double max = -9999;
				int flag = -1;

				net1 = new double[K];
				output = new double[K];

				for (int k = 0; k < K; k++)
				{
					net1[k] = 0;
					for (int j = 0; j < J + 1; j++)
						net1[k] += W[k][j] * y[j];

					if (radioButton1->Checked)
						output[k] = tanh(net1[k]);
					else if (radioButton2->Checked)
						output[k] = (2.0 / (1.0 + exp(-1.0 * net1[k]))) - 1.0;

					if (K == 1) {
						if(output[k] > 0)
							c = Color::Red;
						else
							c = Color::Green;
					}
					else {
						if (max <= output[k]) {
							max = output[k];
							flag = k;
						}
					}
				}

				if (K != 1) {
					if (flag == 0)
						c = Color::Red;
					else if (flag == 1)
						c = Color::Green;
					else if (flag == 2)
						c = Color::Blue;
					else if (flag == 3)
						c = Color::Purple;
					else if (flag == 4)
						c = Color::Cyan;
					else if (flag == 5)
						c = Color::Yellow;
				}
				
				draw->SetPixel(n, m, c);

				delete net;
				delete net1;
				delete y;
				delete output;
				delete point;
				
			}
		}
	}
};
}