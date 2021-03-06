#pragma once
#include <string>
#include <iostream>
#include <locale>
#include <ctype.h>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <msclr\marshal_cppstd.h>//for converting from System String to std string and vice versa
#include <math.h>//for unary functions
#include "History.h"
#include <fstream>



namespace ComplexCalc {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	bool lastCharDigit = true;
	deque<string> TokenEquation(1); //Contains the equation in tokenised infix form.
	deque<string> RPNEquation(0); //Contains the equation in tokenised RPN form.
	deque<string> OperatorStack(0); //Used as part of the Shunting Yard Algorithm
	deque<double> SolverStack(0); //Used to solve the RPN Equation.
	locale loc; //Used to verify digits

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
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button24;
	private: System::Windows::Forms::Button^  button25;
	private: System::Windows::Forms::Button^  button26;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewHistoryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->viewHistoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(11, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox1->Size = System::Drawing::Size(360, 61);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(13, 233);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(55, 55);
			this->button1->TabIndex = 2;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(73, 233);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(55, 55);
			this->button2->TabIndex = 4;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(134, 233);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(55, 55);
			this->button3->TabIndex = 6;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(12, 172);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(55, 55);
			this->button4->TabIndex = 8;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(134, 172);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(55, 55);
			this->button6->TabIndex = 12;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(12, 111);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(55, 55);
			this->button7->TabIndex = 13;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(73, 111);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(55, 55);
			this->button8->TabIndex = 15;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(134, 111);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(55, 55);
			this->button9->TabIndex = 17;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(73, 294);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(55, 55);
			this->button10->TabIndex = 19;
			this->button10->Text = L"0";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(12, 294);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(55, 55);
			this->button11->TabIndex = 21;
			this->button11->Text = L"C++";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(134, 294);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(55, 55);
			this->button12->TabIndex = 23;
			this->button12->Text = L"DEL";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(317, 287);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(55, 62);
			this->button13->TabIndex = 10;
			this->button13->Text = L"=";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(73, 172);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(55, 55);
			this->button5->TabIndex = 24;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(195, 111);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(55, 35);
			this->button14->TabIndex = 25;
			this->button14->Text = L"MC";
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(195, 193);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(115, 34);
			this->button15->TabIndex = 27;
			this->button15->Text = L"MR";
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button16
			// 
			this->button16->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->Location = System::Drawing::Point(256, 111);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(55, 35);
			this->button16->TabIndex = 29;
			this->button16->Text = L"M+";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button17->Location = System::Drawing::Point(195, 152);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(55, 35);
			this->button17->TabIndex = 31;
			this->button17->Text = L"MS";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button18
			// 
			this->button18->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button18->Location = System::Drawing::Point(255, 152);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(55, 35);
			this->button18->TabIndex = 33;
			this->button18->Text = L"M-";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button19
			// 
			this->button19->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button19->Location = System::Drawing::Point(316, 155);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(55, 38);
			this->button19->TabIndex = 34;
			this->button19->Text = L"x²";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// button20
			// 
			this->button20->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->Location = System::Drawing::Point(317, 111);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(55, 38);
			this->button20->TabIndex = 36;
			this->button20->Text = L"C";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// button21
			// 
			this->button21->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button21->Location = System::Drawing::Point(317, 199);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(55, 38);
			this->button21->TabIndex = 38;
			this->button21->Text = L"√";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// button22
			// 
			this->button22->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button22->Location = System::Drawing::Point(317, 243);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(55, 38);
			this->button22->TabIndex = 40;
			this->button22->Text = L"⅟x";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// button23
			// 
			this->button23->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button23->Location = System::Drawing::Point(195, 233);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(55, 55);
			this->button23->TabIndex = 41;
			this->button23->Text = L"+";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// button24
			// 
			this->button24->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button24->Location = System::Drawing::Point(256, 233);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(55, 55);
			this->button24->TabIndex = 43;
			this->button24->Text = L"*";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// button25
			// 
			this->button25->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button25->Location = System::Drawing::Point(195, 294);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(55, 55);
			this->button25->TabIndex = 44;
			this->button25->Text = L"-";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// button26
			// 
			this->button26->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button26->Location = System::Drawing::Point(255, 294);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(55, 55);
			this->button26->TabIndex = 46;
			this->button26->Text = L"/";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(105, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 13);
			this->label1->TabIndex = 47;
			this->label1->Text = L"Sprint Software Complex Calc 1.0";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->viewHistoryToolStripMenuItem });
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(384, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// viewHistoryToolStripMenuItem
			// 
			this->viewHistoryToolStripMenuItem->Name = L"viewHistoryToolStripMenuItem";
			this->viewHistoryToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->viewHistoryToolStripMenuItem->Text = L"View History";
			this->viewHistoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::viewHistoryToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 361);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"ComplexCalc";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	}
			 //this is number 0
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {

		if (this->textBox1->Text == "") { //print nothing if there is nothing
			this->textBox1->Text = "";
		}
		else { //add the text of the button to what's on the screen
			System::Windows::Forms::Button^ butt = (System::Windows::Forms::Button^)sender;
			this->textBox1->Text += butt->Text;
		}
	}
			 //this is the C++ button
	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->textBox1->Text == "") { //print nothing if there is nothing
			this->textBox1->Text = "";
		}
		else{ 
		System::String^ cplus = this->textBox1->Text; //get what is on the screen
		double c = System::Convert::ToDouble(cplus); // convert to double
		double result = c+c; //add its value to itself
		ConvertDoubleString(result); //convert back to System String and print
		}

	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button24_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
	}
			 //these are numbers 1-9
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::Button^ butt = (System::Windows::Forms::Button^)sender;
			this->textBox1->Text += butt->Text;		//add button text to whatever is on the screen
	}
			 //to the power of two
   private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
	   if (this->textBox1->Text == "") { //if nothing is on the screen, print nothing
		   this->textBox1->Text = "";
	   }
	   else{ 
	   System::String^ p = this->textBox1->Text; //get screen content
	   double po = System::Convert::ToDouble(p); //convert to double
	   double y = 2; //set variable 
	   double result = pow(po, y); //calculate
	   ConvertDoubleString(result); //convert back to System string and print
	   }
   }
			//this is the cancel 'c' button
	private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text = "";  //print nothing
		//enable access to power,square root, inverse and ++ functions
		this->button19->Enabled = true;
		this->button21->Enabled = true;
		this->button22->Enabled = true;
		this->button11->Enabled = true;
	}
			 //this is the square root function
	private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->textBox1->Text == "") {//print nothing if there is nothing
			this->textBox1->Text = "";
		}
		else { 
			System::String^ s = this->textBox1->Text; //get screen content
			double sq = System::Convert::ToDouble(s); //convert to double
			double result = sqrt(sq); //calculate
			ConvertDoubleString(result); // convert back and print
		}
			 }
			 //inverse function
	private: System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->textBox1->Text == "") {// print nothing if nothing is there
			this->textBox1->Text = "";
		}
		else {
			System::String^ i = this->textBox1->Text; //get screen content
			double in = System::Convert::ToDouble(i); //convert to double
			double c = 1; //set variable
			double result = c / in; // calaculate
			ConvertDoubleString(result); //covert back and print
		}
	}

			 //operators +-/*
	private: System::Void button23_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->textBox1->Text == "") { //print nothing if there is nothing
			this->textBox1->Text = "";
		}
		else {
			string String; //create an std string
			System::String^ p = this->textBox1->Text; //get screen content
			String = msclr::interop::marshal_as<std::string>(p); //convert to std string
			char x = String.back(); //get last character of string
			if (x == '+' || x == '-' || x == '/' || x == '*') { //if last char is one of these
				this->textBox1->Text; // nothing really happens
			}
			else {
				System::Windows::Forms::Button^ butt = (System::Windows::Forms::Button^)sender;
				this->textBox1->Text += butt->Text; //add button text to screen content
				//disable access to sqare root, inverse, ++, and power functions
				this->button19->Enabled = false;
				this->button21->Enabled = false;
				this->button22->Enabled = false;
				this->button11->Enabled = false;
			}
		}
	}
			 //DEL (delete last character)
	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (this->textBox1->Text == "") {//if there is nothing, print nothing
			this->textBox1->Text = "";
		}
		else{
		string String; //create std String
		System::String^ input = this->textBox1->Text; //get content
		String = msclr::interop::marshal_as<std::string>(input);// convert content to std string
		String.pop_back(); //take out the last element of the string
		System::String^ result; //create a new System String
		result = msclr::interop::marshal_as<System::String^>(String); //convert string (last element is missing)
		this->textBox1->Text = result; //print
		}
		
		
	}

			 //enter 'equals sign'
	private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->textBox1->Text == "") { //if empty, keep empty
			this->textBox1->Text = "";
		}
		else
		{
			result();
		}



	}
			 void result() {
				 
				 
				 lastCharDigit = true;
				 TokenEquation = deque<string>(1); //Contains the equation in tokenised infix form.
				 RPNEquation = deque<string>(0); //Contains the equation in tokenised RPN form.
				 OperatorStack = deque<string>(0); //Used as part of the Shunting Yard Algorithm
				 SolverStack = deque<double>(0); //Used to solve the RPN Equation.

				 string RawString; //create a std string
				 System::String^ input = this->textBox1->Text; //get content from screen
				 RawString = msclr::interop::marshal_as<std::string>(input); //convert to std string
				 char x = RawString.back(); //get last element of string
				 char y = RawString.at(0); //get first element of string
				 std::size_t found = RawString.find_first_of('.'); //find specific character of string
				 if (found != std::string::npos || y == '-' || y == '∞' || y == 'N') { //if specific character found or first element is one of these
					 this->textBox1->Text = ""; //print blank space
				 }
				 else if (x == '+' || x == '-' || x == '/' || x == '*') { //if last character is one of these
					 this->textBox1->Text; //print what is already there
				 }
				 else{ //procede with calculations
				 string newOperator;
				 tokeniser(RawString);
				 SYAlg();
				 OSProcess(newOperator);
				 }
				 
			 }

			 void tokeniser(string RawEquation)

			 {
				 int testCharPos = -1; // Initialise the index of the raw string
				 int tokenVectorPos = 0; // Initialise the token array position

				 for (int eLength = RawEquation.length(); eLength != 0; eLength--) // For each character in the Raw string...
				 {
					 testCharPos++; // Increment the char we're testing
					 char testChar = RawEquation.at(testCharPos); // Establish the current test char

					 if (isdigit(testChar, loc)) //If the testchar is a digit
					 {
						 if (lastCharDigit) //If the last character was a digit
						 {
							 TokenEquation[tokenVectorPos] += testChar; //Append the tested char to the current token array pos
						 }
						 if (!lastCharDigit) //If the last character was not a digit
						 {
							 TokenEquation.push_back(std::string(1, testChar)); //Establish a new element with the testchar in it.
							 tokenVectorPos++;
						 }
						 lastCharDigit = true;
					 }
					 if (!isdigit(testChar, loc))//If the testchar is not a digit
					 {
						 TokenEquation.push_back(std::string(1, testChar)); //Establish a new element with the testchar in it.
						 tokenVectorPos++;
						 lastCharDigit = false;
					 }
				 }
			 }
			 void SYAlg() //This function uses Shunting Yard Algorithm to convert the Infix tokens to RPN.
			 {
				 while (!TokenEquation.empty()) //For each token in the tokenised deque
				 {
					 if (!TokenEquation.empty() && isdigit(TokenEquation.front().at(0), loc)) //Check if it's a number
					 {
						 RPNEquation.push_back(TokenEquation.front()); //Add the first raw token to the RPN Equation
						 TokenEquation.pop_front(); //Pop the token from the deque
					 }
					 if (!TokenEquation.empty() && !isdigit(TokenEquation.front().at(0), loc))	//If it's an operator
					 {
						 OSProcess(TokenEquation.front()); //Run the SYAlg operator stack procedure. NB This will pop the front of the TokenEquation for you.
					 }
					 if (TokenEquation.empty())
					 {
						 while (!OperatorStack.empty())
						 {
							 RPNEquation.push_back(OperatorStack.back());
							 OperatorStack.pop_back();
						 }
					 }
				 }

				 /*Uncomment this to display the RPN tokens
				 cout << "The tokens of that RPN equation are:\n\n"; //Outputs the tokens for testing purposes.
				 int RPNPrintPos = 0;
				 for (int tokenLength = RPNEquation.size(); tokenLength != 0; tokenLength--)
				 {
				 cout << "     " << RPNEquation[RPNPrintPos];
				 cout << "\n";
				 RPNPrintPos++;
				 }
				 */
				 Solver();
			 }

			 void OSProcess(string newOperator) //This function processes the Operator Stack
			 {
				 bool PushedNewOperator = false;
				 //std::string newOpSTD = newOperator; //Creates an std::string version of the argument for easier comparison.
				 while (PushedNewOperator == false)
				 { //As long as the new operator is still waiting to go to the stack
					 if (!OperatorStack.empty()) //If there's already an operator on the stack
					 {
						 if (newOperator.compare("/") == 0 || newOperator.compare("*") == 0)
						 {
							 //std::string OSBackSTD = OperatorStack.back(); //Create an STD version of the back of the OpStack for comparison.
							 if (OperatorStack.back().compare("+") == 0 || OperatorStack.back().compare("-") == 0)
							 {
								 OperatorStack.push_back(newOperator); //Add the tested operator to the stack
								 TokenEquation.pop_front(); //And pop it from the token equation
								 PushedNewOperator = true; //Set the flag variable to true so we stop looping
							 }
							 else
							 {
								 RPNEquation.push_back(OperatorStack.back()); //Add the top of the operator stack to the equation
								 OperatorStack.pop_back(); //Pop this back
							 }
						 }
						 else
						 {
							 RPNEquation.push_back(OperatorStack.back()); //Add the top of the operator stack to the equation
							 OperatorStack.pop_back(); //Pop this back
						 }
					 }
					 if (OperatorStack.empty())
					 {
						 OperatorStack.push_back(newOperator); //Add the tested operator to the stack
						 if(!TokenEquation.empty())
							TokenEquation.pop_front(); //And pop it from the token equation
						 //else
							 //TokenEquation.push_back("");
						 PushedNewOperator = true; //Set the flag variable to true so we stop looping
					 }
				 }
				 //For each operator on the stack, until the following statement returns false...
				 //Check if the precedence of newOperator is less than or equal to the top operator.
			 }

			 void Solver() //This function solves the RPNEquation
			 {
				 double answer;
				 while (!RPNEquation.empty())//While there's still tokens in the RPN equation.
				 {
					 bool tokenProcessed = false; //Flag to ensure only one token gets processed per cycle of the parent while loop.
					 if (isdigit(RPNEquation.front().at(0)) && tokenProcessed == false) //If the front token is a number.
					 {
						 SolverStack.push_back(atof(RPNEquation.front().c_str())); //Pushed the numeric string, converted to an int, on to the solver.
						 RPNEquation.pop_front();
						 tokenProcessed = true;
					 }
					 if (!RPNEquation.empty() && tokenProcessed == false) //If the front token is not a number...
					 {
						 double secondOperand = SolverStack.back(); //These four lines pop out the right numbers from the stack to be processed.
						 SolverStack.pop_back();
						 double firstOperand = SolverStack.back();
						 SolverStack.pop_back();

						 if (tokenProcessed == false && RPNEquation.front().compare("+") == 0)
						 {
							 answer = firstOperand + secondOperand; //Solve, push to stack, pop old token and flag processing.
							 SolverStack.push_back(answer);
							 RPNEquation.pop_front();
							 tokenProcessed = true;
						 }
						 if (tokenProcessed == false && RPNEquation.front().compare("-") == 0)
						 {
							 answer = firstOperand - secondOperand; //Solve, push to stack, pop old token and flag processing.
							 SolverStack.push_back(answer);
							 RPNEquation.pop_front();
							 tokenProcessed = true;
						 }
						 if (tokenProcessed == false && RPNEquation.front().compare("*") == 0)
						 {
							 answer = firstOperand * secondOperand; //Solve, push to stack, pop old token and flag processing.
							 SolverStack.push_back(answer);
							 RPNEquation.pop_front();
							 tokenProcessed = true;
						 }
						 if (tokenProcessed == false && RPNEquation.front().compare("/") == 0)
						 {
							 answer = firstOperand / secondOperand; //Solve, push to stack, pop old token and flag processing.
							 SolverStack.push_back(answer);
							 RPNEquation.pop_front();
							 tokenProcessed = true;
						 }
					 }
				 }
				 double number = SolverStack.back(); //get last number on Stack
				 ConvertDoubleString(number); //convert to System string and print
				 // allow access to unary functions
				 this->button19->Enabled = true;
				 this->button21->Enabled = true;
				 this->button22->Enabled = true;
				 this->button11->Enabled = true;


			 }
			 void ConvertDoubleString(double doubleVal) {
				 
				 String^ Result; //create System String
				 Result = System::Convert::ToString(doubleVal); //convert from double
				 this->textBox1->Text = Result; //print
			 }

			
 

			 //textbox
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->textBox1->Text == "") {// if there is nothing in allow access to unary functions
		this->button19->Enabled = true;
		this->button21->Enabled = true;
		this->button22->Enabled = true;
		this->button11->Enabled = true;
	}
}
private: System::Void viewHistoryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	History^ h = gcnew History();
	h->ShowDialog();
}
}


 ; }








