
#pragma once
#include "cellular_automaton.h"
#include "dequeue.h"
#include "exception.h"
//#include "stack.h"
#include "Form2.h"
Automaton* automaton=new Game_Life();
//MyStack<char**> stack,stack2;
Dequeue* deq=new Dequeue(50,20,20);


char state;
bool pen=false;
bool paint=false;
bool panel3move=false;
bool panel14move=false;
bool panelchose=false;
bool colorBrush=false;
/******************Корректность формулы**********************/
bool isopenqbracket=false;
bool isopenrbracket=false;
int countcommas=0;
int countropen=0,countrclose=0,countqopen=0,countqclose=0;
int zoom=1;
/************************************************************/
polishNotation notat=polishNotation();
//System::Drawing::Color col=Color::White;
namespace cellularautomaton {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	/// <summary>
	/// Summary for Form1
	/// </summary>

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton5;
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton6;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;

	private: System::Windows::Forms::ToolStripButton^  toolStripButton8;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel1;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton9;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Panel^  panel12;
	private: System::Windows::Forms::Panel^  panel11;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;

	public: 
	private: System::ComponentModel::IContainer^  components;
	private:
	private : Color col;
	public: int panel3clickX,panel3clickY,panel14clickX,panel14clickY;

	private: System::Windows::Forms::ToolStripButton^  toolStripButton7;
	private: System::Windows::Forms::Button^  button3;


	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Panel^  panel14;
	private: System::Windows::Forms::ComboBox^  comboBox2;

	private: System::Windows::Forms::Panel^  panel15;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton10;




	private: System::Windows::Forms::Panel^  panel13;


	public: 
		/// <summary>
		/// Required designer variable.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton10 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton8 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripButton9 = (gcnew System::Windows::Forms::ToolStripButton());
			this->panel1->SuspendLayout();
			this->panel14->SuspendLayout();
			this->panel3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Interval = 500;
			this->timer->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->panel1->Controls->Add(this->panel14);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(0, 47);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(923, 527);
			this->panel1->TabIndex = 8;
			// 
			// panel14
			// 
			this->panel14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel14->Controls->Add(this->comboBox2);
			this->panel14->Controls->Add(this->panel15);
			this->panel14->Location = System::Drawing::Point(114, 157);
			this->panel14->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(626, 100);
			this->panel14->TabIndex = 11;
			this->panel14->Visible = false;
			this->panel14->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel14_MouseDown);
			this->panel14->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel14_MouseMove);
			this->panel14->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel14_MouseUp);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"y[0,0]^((y[-1,0]&y[1,0])|(y[0,-1]&y[0,1]))", 
				L"(y[0,0]^((y[-1,0]&y[1,0])|(y[0,-1]&y[0,1])))^y[1,1]^y[1,-1]^y[-1,1]^y[-1,-1]", L"((y[0,0]^((y[-1,0]&y[1,0])|(y[0,-1]&y[0,1])))^y[1,1]^y[1,-1]^y[-1,1]^y[-1,-1])^y[" 
				L"2,0]^y[-2,0]^y[0,2]^y[0,-2]"});
			this->comboBox2->Location = System::Drawing::Point(14, 36);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(592, 24);
			this->comboBox2->TabIndex = 16;
			this->comboBox2->Text = L"y[0,0]^((y[-1,0]&y[1,0])|(y[0,-1]&y[0,1]))";
			this->comboBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::comboBox2_KeyPress);
			// 
			// panel15
			// 
			this->panel15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel15.BackgroundImage")));
			this->panel15->Location = System::Drawing::Point(605, -1);
			this->panel15->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(20, 20);
			this->panel15->TabIndex = 4;
			this->panel15->Click += gcnew System::EventHandler(this, &Form1::panel15_Click);
			// 
			// panel3
			// 
			this->panel3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->panel13);
			this->panel3->Controls->Add(this->groupBox1);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Location = System::Drawing::Point(161, 0);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(565, 100);
			this->panel3->TabIndex = 1;
			this->panel3->Visible = false;
			this->panel3->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::panel3_DragDrop);
			this->panel3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel3_MouseDown);
			this->panel3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel3_MouseMove);
			this->panel3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel3_MouseUp);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(472, 57);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Draw";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click_1);
			// 
			// panel13
			// 
			this->panel13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel13.BackgroundImage")));
			this->panel13->Location = System::Drawing::Point(544, -1);
			this->panel13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(20, 20);
			this->panel13->TabIndex = 4;
			this->panel13->Click += gcnew System::EventHandler(this, &Form1::panel13_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->panel12);
			this->groupBox1->Controls->Add(this->panel11);
			this->groupBox1->Controls->Add(this->panel10);
			this->groupBox1->Controls->Add(this->panel9);
			this->groupBox1->Controls->Add(this->panel8);
			this->groupBox1->Controls->Add(this->panel7);
			this->groupBox1->Controls->Add(this->panel6);
			this->groupBox1->Controls->Add(this->panel5);
			this->groupBox1->Location = System::Drawing::Point(135, 7);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(309, 79);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Choose colour";
			// 
			// panel12
			// 
			this->panel12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(204)), static_cast<System::Int32>(static_cast<System::Byte>(51)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel12->Cursor = System::Windows::Forms::Cursors::No;
			this->panel12->Location = System::Drawing::Point(241, 46);
			this->panel12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(58, 19);
			this->panel12->TabIndex = 7;
			this->panel12->DoubleClick += gcnew System::EventHandler(this, &Form1::panel12_DoubleClick);
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(102)), 
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel11->Cursor = System::Windows::Forms::Cursors::No;
			this->panel11->Location = System::Drawing::Point(241, 21);
			this->panel11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(58, 19);
			this->panel11->TabIndex = 6;
			this->panel11->DoubleClick += gcnew System::EventHandler(this, &Form1::panel11_DoubleClick);
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(153)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel10->Cursor = System::Windows::Forms::Cursors::No;
			this->panel10->Location = System::Drawing::Point(165, 46);
			this->panel10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(58, 19);
			this->panel10->TabIndex = 5;
			this->panel10->DoubleClick += gcnew System::EventHandler(this, &Form1::panel10_DoubleClick);
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel9->Cursor = System::Windows::Forms::Cursors::No;
			this->panel9->Location = System::Drawing::Point(165, 21);
			this->panel9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(58, 19);
			this->panel9->TabIndex = 4;
			this->panel9->DoubleClick += gcnew System::EventHandler(this, &Form1::panel9_DoubleClick);
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Cyan;
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel8->Cursor = System::Windows::Forms::Cursors::No;
			this->panel8->Location = System::Drawing::Point(91, 46);
			this->panel8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(58, 19);
			this->panel8->TabIndex = 3;
			this->panel8->DoubleClick += gcnew System::EventHandler(this, &Form1::panel8_DoubleClick);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(51)), 
				static_cast<System::Int32>(static_cast<System::Byte>(102)));
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Cursor = System::Windows::Forms::Cursors::No;
			this->panel7->Location = System::Drawing::Point(91, 21);
			this->panel7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(58, 19);
			this->panel7->TabIndex = 2;
			this->panel7->DoubleClick += gcnew System::EventHandler(this, &Form1::panel7_DoubleClick);
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Black;
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Location = System::Drawing::Point(15, 46);
			this->panel6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(58, 19);
			this->panel6->TabIndex = 1;
			this->panel6->DoubleClick += gcnew System::EventHandler(this, &Form1::panel6_DoubleClick);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Location = System::Drawing::Point(15, 21);
			this->panel5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(58, 19);
			this->panel5->TabIndex = 0;
			this->panel5->DoubleClick += gcnew System::EventHandler(this, &Form1::panel5_DoubleClick);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(37, 74);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 17);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Colour";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->ForeColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(12, 7);
			this->panel4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(102, 64);
			this->panel4->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(920, 516);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown_2);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove_1);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseUp_1);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(747, 44);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(175, 530);
			this->panel2->TabIndex = 1;
			this->panel2->Visible = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(22, 272);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(134, 27);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Edit formula";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->Location = System::Drawing::Point(22, 319);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Size = System::Drawing::Size(132, 76);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Field gereration";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(5, 48);
			this->radioButton2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(112, 21);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->Text = L"Random field";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(5, 21);
			this->radioButton1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(98, 21);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Empty field";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(22, 232);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(134, 27);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Change";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(24, 414);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(132, 48);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Create";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Aut. with special rule", L"Binary automaton", 
				L"Cyclical automaton", L"Game \"Life\""});
			this->comboBox1->Location = System::Drawing::Point(21, 30);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(132, 24);
			this->comboBox1->Sorted = true;
			this->comboBox1->TabIndex = 8;
			this->comboBox1->Text = L"Game \"Life\"";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 5);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 17);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Type";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(22, 204);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->MaxLength = 6;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(134, 22);
			this->textBox3->TabIndex = 6;
			this->textBox3->Text = L"1000";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 183);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 17);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Time interval";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 127);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Height:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 80);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Width:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(24, 148);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->MaxLength = 4;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(132, 22);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"20";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(24, 101);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->MaxLength = 4;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"20";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 63);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Field\'s size";
			// 
			// toolStrip1
			// 
			this->toolStrip1->AutoSize = false;
			this->toolStrip1->BackColor = System::Drawing::Color::SteelBlue;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(35, 35);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(14) {this->toolStripButton1, 
				this->toolStripButton2, this->toolStripButton3, this->toolStripButton4, this->toolStripButton5, this->toolStripButton6, this->toolStripSeparator1, 
				this->toolStripButton7, this->toolStripButton10, this->toolStripButton8, this->toolStripSeparator3, this->toolStripLabel1, this->toolStripTextBox1, 
				this->toolStripButton9});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(923, 44);
			this->toolStrip1->TabIndex = 10;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->AutoSize = false;
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(40, 41);
			this->toolStripButton1->Text = L"Prev";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->AutoSize = false;
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(40, 41);
			this->toolStripButton2->Text = L"Next";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->AutoSize = false;
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(40, 41);
			this->toolStripButton3->Text = L"Stop";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Form1::toolStripButton3_Click);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->AutoSize = false;
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(40, 41);
			this->toolStripButton4->Text = L"Pause";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &Form1::toolStripButton4_Click);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->AutoSize = false;
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(40, 41);
			this->toolStripButton5->Text = L"Play";
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &Form1::toolStripButton5_Click);
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolStripButton6->AutoSize = false;
			this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(40, 41);
			this->toolStripButton6->Text = L"Options";
			this->toolStripButton6->Click += gcnew System::EventHandler(this, &Form1::toolStripButton6_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 44);
			// 
			// toolStripButton7
			// 
			this->toolStripButton7->AutoSize = false;
			this->toolStripButton7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->toolStripButton7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton7.Image")));
			this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::MediumOrchid;
			this->toolStripButton7->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->toolStripButton7->Name = L"toolStripButton7";
			this->toolStripButton7->Size = System::Drawing::Size(50, 41);
			this->toolStripButton7->Text = L"Pen";
			this->toolStripButton7->Click += gcnew System::EventHandler(this, &Form1::toolStripButton7_Click_1);
			// 
			// toolStripButton10
			// 
			this->toolStripButton10->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton10->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton10.Image")));
			this->toolStripButton10->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton10->Name = L"toolStripButton10";
			this->toolStripButton10->Size = System::Drawing::Size(39, 41);
			this->toolStripButton10->Text = L"Zoom Out";
			this->toolStripButton10->Click += gcnew System::EventHandler(this, &Form1::toolStripButton10_Click);
			// 
			// toolStripButton8
			// 
			this->toolStripButton8->AutoSize = false;
			this->toolStripButton8->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton8.Image")));
			this->toolStripButton8->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton8->Name = L"toolStripButton8";
			this->toolStripButton8->Size = System::Drawing::Size(40, 41);
			this->toolStripButton8->Text = L"Zoom In";
			this->toolStripButton8->Click += gcnew System::EventHandler(this, &Form1::toolStripButton8_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Margin = System::Windows::Forms::Padding(10, 0, 30, 0);
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 44);
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(65, 41);
			this->toolStripLabel1->Text = L"Iteration";
			// 
			// toolStripTextBox1
			// 
			this->toolStripTextBox1->Enabled = false;
			this->toolStripTextBox1->Name = L"toolStripTextBox1";
			this->toolStripTextBox1->Size = System::Drawing::Size(100, 44);
			this->toolStripTextBox1->Text = L"0";
			this->toolStripTextBox1->TextBoxTextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// toolStripButton9
			// 
			this->toolStripButton9->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolStripButton9->AutoSize = false;
			this->toolStripButton9->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton9.Image")));
			this->toolStripButton9->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton9->Name = L"toolStripButton9";
			this->toolStripButton9->Size = System::Drawing::Size(40, 41);
			this->toolStripButton9->Text = L"FAQ";
			this->toolStripButton9->Click += gcnew System::EventHandler(this, &Form1::toolStripButton9_Click);
			// 
			// Form1
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(923, 574);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(890, 590);
			this->Name = L"Form1";
			this->Text = L"Cellular automation";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->panel1->ResumeLayout(false);
			this->panel14->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion		
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 automaton->NextStep();

				 automaton->Paint(panel1,pictureBox1,zoom);
				 automaton->step++;
				 toolStripTextBox1->Text=Convert::ToString(automaton->step);
				 deq->push(automaton->last);
				 //automaton->NextStep();
			 }
	private: System::Void toolStripButton5_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer->Enabled=true;
				 automaton->state=play;
				 automaton->Paint(panel1,pictureBox1,zoom);
			 }
	private: System::Void toolStripButton4_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer->Enabled=false;
				 automaton->state=pause;
			 }
	private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {
				 int a;
				int width=automaton->width,height=automaton->height;
				 if(panel1->Width/width>(panel1->Height)/height)
						a=(panel1->Height)/height;
					else
						a=panel1->Width/width;
					if(a<1)
					{
						a=1;
					}
					a*=zoom;
					pictureBox1->Top=0;
					pictureBox1->Left=0;
					panel1->AutoScroll=false;
					panel1->AutoScroll=true;
					pictureBox1->Height=height*a;
						 pictureBox1->Width=width*a;
						 pictureBox1->Left=(panel1->Width-pictureBox1->Width)/2;
						// if(pictureBox1->Left<0)
							// pictureBox1->Left=0;
						 pictureBox1->Top=(panel1->Height-pictureBox1->Height)/2;
						 //if(pictureBox1->Top<0)
							// pictureBox1->Top=0;
				 automaton->Paint(panel1,pictureBox1,zoom);
			 }
	private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer->Enabled=false;
				 toolStripButton5->Enabled=false;
				 automaton->state=stop;
			 }
	private: System::Void toolStripButton6_Click(System::Object^  sender, System::EventArgs^  e) {
				 pen=false;
				 button3->Text="Draw";
				 panel14->Visible=false;
				 panel2->Visible=(panel2->Visible+1)%2;
				 panel3->Visible=false;
				 automaton->Paint(panel1,pictureBox1,zoom);
				 panel3->Visible=false;
				 panel4->BackColor=Color::FromArgb(128,128, 128);
				 panelchose=false;
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 panel14->Visible=false;
				 try
				 {
					 timer->Enabled=false;
					 if(Convert::ToInt32(textBox3->Text)<1||Convert::ToInt32(textBox1->Text)<3||Convert::ToInt32(textBox1->Text)>1000||Convert::ToInt32(textBox2->Text)<3||Convert::ToInt32(textBox2->Text)>1000)
						 Convert::ToInt32("ghj");
					 timer->Interval=Convert::ToInt32(textBox3->Text);
					 if(comboBox1->Text=="Game \"Life\"")
					 {
						 automaton=new Game_Life(Convert::ToInt32(textBox1->Text),Convert::ToInt32(textBox2->Text),radioButton2->Checked);
						 colorBrush=false;
						 panel7->Cursor=Cursors::No;
						 panel8->Cursor=Cursors::No;
						 panel9->Cursor=Cursors::No;
						 panel10->Cursor=Cursors::No;
						 panel11->Cursor=Cursors::No;
						 panel12->Cursor=Cursors::No;
						 
					 }
					 if(comboBox1->Text=="Cyclical automaton")
					 {
						 automaton=new Cyclical_Automaton(Convert::ToInt32(textBox1->Text),Convert::ToInt32(textBox2->Text),radioButton2->Checked);
						colorBrush=true;
						 panel7->Cursor=Cursors::Default;
						 panel8->Cursor=Cursors::Default;
						 panel9->Cursor=Cursors::Default;
						 panel10->Cursor=Cursors::Default;
						 panel11->Cursor=Cursors::Default;
						 panel12->Cursor=Cursors::Default;
					 }
					 if(comboBox1->Text=="Binary automaton")
					 {
						 polishNotation notat;
						
							 if(notat.makeNotation(comboBox2->Text))
							 {
								 notat.TestCalculate();
								 automaton=new Binary_Automaton(Convert::ToInt32(textBox1->Text),Convert::ToInt32(textBox2->Text),comboBox2->Text,radioButton2->Checked);
								 colorBrush=false;
								 panel7->Cursor=Cursors::No;
						 panel8->Cursor=Cursors::No;
						 panel9->Cursor=Cursors::No;
						 panel10->Cursor=Cursors::No;
						 panel11->Cursor=Cursors::No;
						 panel12->Cursor=Cursors::No;
							 }
							 else	 
							 {
								 int i=-1;
								 throw i;
							 }
					 }
					  if(comboBox1->Text=="Aut. with special rule")
					 {
								 automaton=new AutomatonWithSpecialRule(Convert::ToInt32(textBox1->Text),Convert::ToInt32(textBox2->Text),radioButton2->Checked);
								 colorBrush=false;
								panel7->Cursor=Cursors::No;
						 panel8->Cursor=Cursors::No;
						 panel9->Cursor=Cursors::No;
						 panel10->Cursor=Cursors::No;
						 panel11->Cursor=Cursors::No;
						 panel12->Cursor=Cursors::No;
					 }
					 toolStripButton5->Enabled=true;
					 toolStripTextBox1->Text="0";
						 automaton->Paint(panel1,pictureBox1,zoom);
					 delete deq;
					 deq=new Dequeue(50,automaton->width,automaton->height);
					 int a;
				int width=automaton->width,height=automaton->height;
				 if(panel1->Width/width>(panel1->Height)/height)
						a=(panel1->Height)/height;
					else
						a=panel1->Width/width;
					if(a<1)
					{
						a=1;
					}
					a*=zoom;
					pictureBox1->Top=0;
					pictureBox1->Left=0;
					panel1->AutoScroll=false;
					panel1->AutoScroll=true;
					pictureBox1->Height=height*a;
						 pictureBox1->Width=width*a;
						 pictureBox1->Left=(panel1->Width-pictureBox1->Width)/2;
						// if(pictureBox1->Left<0)
							// pictureBox1->Left=0;
						 pictureBox1->Top=(panel1->Height-pictureBox1->Height)/2;
						 //if(pictureBox1->Top<0)
							// pictureBox1->Top=0;
				 automaton->Paint(panel1,pictureBox1,zoom);
				 automaton->ShowDescription();
				 }
				 catch(...)
				 {

					 MessageBox::Show( "An invalid argument was encountered", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 }
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 try
				 {

					 if(textBox3->Text!=""&& timer->Interval!=Convert::ToInt32(textBox3->Text)&&timer->Enabled==true)
					 {
						 timer->Enabled=false;
						 timer->Interval=Convert::ToInt32(textBox3->Text);
						 timer->Enabled=true;
					 }
					 else
					 {
						 timer->Interval=Convert::ToInt32(textBox3->Text);
					 }
				 }
				 catch(...)
				 {
					 MessageBox::Show( "An invalid argument was encountered", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 }
				 automaton->Paint(panel1,pictureBox1,zoom);
			 }
	private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) { 
if(timer->Enabled==false)
{
				 char **temp=deq->pop_front();
				 if(temp==NULL)
					 MessageBox::Show( "Dequeue is empty!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				 else
				 {
					 delete_array(automaton->now,automaton->height);
					 automaton->now=temp;
					 automaton->Paint(panel1,pictureBox1,zoom);
					 automaton->step--;
					 toolStripTextBox1->Text=Convert::ToString(automaton->step);
				 }
}

			 }
	private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(timer->Enabled==false)
				 {
				 automaton->NextStep();

				 automaton->Paint(panel1,pictureBox1,zoom);
				 automaton->step++;
				 toolStripTextBox1->Text=Convert::ToString(automaton->step);
				 deq->push(automaton->last);
				 }
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 int a;
				int width=automaton->width,height=automaton->height;
				 if(panel1->Width/width>(panel1->Height)/height)
						a=(panel1->Height)/height;
					else
						a=panel1->Width/width;
					if(a<1)
					{
						a=1;
					}
					a*=zoom;
					pictureBox1->Top=0;
					pictureBox1->Left=0;
					panel1->AutoScroll=false;
					panel1->AutoScroll=true;
					pictureBox1->Height=height*a;
						 pictureBox1->Width=width*a;
						 pictureBox1->Left=(panel1->Width-pictureBox1->Width)/2;
						// if(pictureBox1->Left<0)
							// pictureBox1->Left=0;
						 pictureBox1->Top=(panel1->Height-pictureBox1->Height)/2;
						 //if(pictureBox1->Top<0)
							// pictureBox1->Top=0;
				 automaton->Paint(panel1,pictureBox1,zoom);
			 }
	private: System::Void toolStripButton9_Click(System::Object^  sender, System::EventArgs^  e) {
				 Form2 ^ f=gcnew Form2();
				 f->ShowDialog();
			 }
	private: System::Void toolStripButton7_Click(System::Object^  sender, System::EventArgs^  e) {

				 pen=true;
				 col= Color::White;
				 panel4->BackColor=col;
				 state=1;

			 }
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
				 int a;
				 if(panel1->Width/automaton->width>(panel1->Height)/automaton->height)
					 a=(panel1->Height)/automaton->height;
				 else
					 a=panel1->Width/automaton->width;
				 if(a<1)
				 {
					 a=1;
				 }
				 //automaton->now[(e->Y)/a][(e->X)/a]=1;
				 //	automaton->Paint(panel1,pictureBox1);
				 SolidBrush ^blueBrush = gcnew SolidBrush(Color::Blue);
				 pictureBox1->CreateGraphics()->FillRectangle(blueBrush, 40,40,a, a);
			 }
	private: System::Void pictureBox1_MouseMove_1(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if(paint&&pen&&panelchose)
				 {
					 //col= Color::White;
					 int a;
					 if(panel1->Width/automaton->width>(panel1->Height)/automaton->height)
						 a=(panel1->Height)/automaton->height;
					 else
						 a=panel1->Width/automaton->width;
					 if(a<1)
					 {
						 a=1;
					 }
					 a*=zoom;
					 if((e->Y)/a>=0&&(e->Y)/a<automaton->height&&(e->X)/a>=0&&(e->X)/a<automaton->width)
						 automaton->now[(e->Y)/a][(e->X)/a]=state;
					 //	automaton->Paint(panel1,pictureBox1);

					 SolidBrush ^blueBrush = gcnew SolidBrush(col);
					 if(automaton->width<120 && automaton->height<120)
						 pictureBox1->CreateGraphics()->FillRectangle(blueBrush, ((e->X)/a)*a+1,((e->Y)/a)*a+1,a-1, a-1);
					 else
						 pictureBox1->CreateGraphics()->FillRectangle(blueBrush, ((e->X)/a)*a,((e->Y)/a)*a,a, a);
				 }
			 }
	private: System::Void pictureBox1_MouseDown_2(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if(pen&&panelchose&&timer->Enabled==false)
				 {
					 paint=true;

					 int a;
					 if(panel1->Width/automaton->width>(panel1->Height)/automaton->height)
						 a=(panel1->Height)/automaton->height;
					 else
						 a=panel1->Width/automaton->width;
					 if(a<1)
					 {
						 a=1;
					 }
					 a*=zoom;
					 automaton->now[(e->Y)/a][(e->X)/a]=state;
					 //	automaton->Paint(panel1,pictureBox1);
					 SolidBrush ^blueBrush = gcnew SolidBrush(col);
					 if(automaton->width<120 && automaton->height<120)
						 pictureBox1->CreateGraphics()->FillRectangle(blueBrush, ((e->X)/a)*a+1,((e->Y)/a)*a+1,a-1, a-1);
					 else
						 pictureBox1->CreateGraphics()->FillRectangle(blueBrush, ((e->X)/a)*a,((e->Y)/a)*a,a, a);
				 }

			 }
	private: System::Void pictureBox1_MouseUp_1(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 paint=false;
			 }
	private: System::Void panel3_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
				 panel3->Top=panel3->Top+4;
			 }
	private: System::Void panel5_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
				 panelchose=true;
				 col= Color::White;
				 panel4->BackColor=col;
				 state=1;
			 }

	private: System::Void panel6_DoubleClick(System::Object^  sender, System::EventArgs^  e) {

				 panelchose=true;
				 col= Color::Black;
				 panel4->BackColor=col;
				 state=0;
			 }
	private: System::Void panel3_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if(panel3move)
				 {
					 panel3->Top+=e->Y-panel3clickY;
					 panel3->Left+=e->X-panel3clickX;
				 }
			 }
	private: System::Void panel3_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 panel3move=true;
				 panel3clickX=e->X;
				 panel3clickY=e->Y;
			 }
	private: System::Void panel3_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 panel3move=false;
			 }
	private: System::Void paletteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 panel2->Visible=false;
				 panel3->Visible=true;
				 automaton->Paint(panel1,pictureBox1,zoom);
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 panel3->Visible=false;
			 }

	private: System::Void panel13_Click(System::Object^  sender, System::EventArgs^  e) {
				 panel3->Visible=false;
				 pen=false;
				 button3->Text="Draw";
				 panel4->BackColor=Color::FromArgb(128,128, 128);
				 panelchose=false;
			 }

	private: System::Void toolStripButton7_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 panel2->Visible=false;
				 panel3->Visible=true;
				 panel14->Visible=false;
				 automaton->Paint(panel1,pictureBox1,zoom);
			 }
	private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 if(panelchose)
				 {
				 if(pen)
				 {
					 pen=false;
					 button3->Text="Draw";
				 }
				 else
				 {
					 pen=true;
					 button3->Text="Cancel";
				 }
				 }
			 }
private: System::Void panel7_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 if(colorBrush)
			 {
			 panelchose=true;
				 col= Color::FromArgb(102,51,102);
				 panel4->BackColor=col;
				 state=2;
			 }
		 }
private: System::Void panel8_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 if(colorBrush)
			 {
			 panelchose=true;
				 col= Color::FromArgb(0,255,255);
				 panel4->BackColor=col;
				 state=3;
			 }
		 }
private: System::Void panel9_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	if(colorBrush)
	{
			 panelchose=true;
				 col= Color::FromArgb(255, 0, 204);
				 panel4->BackColor=col;
				 state=4;
	}
		 }
private: System::Void panel10_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 if(colorBrush)
			 {
				 panelchose=true;
				 col= Color::FromArgb(255, 153, 0);
				 panel4->BackColor=col;
				 state=5;
			 }
		 }
private: System::Void panel11_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			if(colorBrush)
			{
				 panelchose=true;
				 col= Color::FromArgb(0,102, 204);
				 panel4->BackColor=col;
				 state=6;
			}
		 }
private: System::Void panel12_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 if(colorBrush)
			 {
			 panelchose=true;
				 col= Color::FromArgb(204, 51, 0);
				 panel4->BackColor=col;
				 state=7;
			 }
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel14->Visible=(panel14->Visible+1)%2;
		 }
private: System::Void panel15_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel14->Visible=false;
		 }
private: System::Void comboBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if(!IsMySymbol(e->KeyChar))
			 {
				 e->Handled = true;
				 return;
			 }
		 }
private: System::Void panel14_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(panel14move)
				 {
					 panel14->Top+=e->Y-panel14clickY;
					 panel14->Left+=e->X-panel14clickX;
				 }
			  panel14move=true;
				 panel14clickX=e->X;
				 panel14clickY=e->Y;
		 }
private: System::Void panel14_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(panel14move)
				 {
					 panel14->Top+=e->Y-panel14clickY;
					 panel14->Left+=e->X-panel14clickX;
				 }
		 }
private: System::Void panel14_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			  panel14move=false;
		 }
private: System::Void toolStripButton8_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(zoom<3)
			 {
			 zoom++;
			 int a;
				int width=automaton->width,height=automaton->height;
				 if(this->Width/width>(this->Height-100)/height)
						a=(this->Height-100)/height;
					else
						a=this->Width/width;
					if(a<1)
					{
						a=1;
					}
					a*=zoom;
					pictureBox1->Top=0;
					pictureBox1->Left=0;
					panel1->AutoScroll=false;
					panel1->AutoScroll=true;
					pictureBox1->Height=height*a;
						 pictureBox1->Width=width*a;
						 pictureBox1->Left=(panel1->Width-pictureBox1->Width)/2;
						 if(pictureBox1->Left<0)
							 pictureBox1->Left=0;
						 pictureBox1->Top=(panel1->Height-pictureBox1->Height)/2;
						 if(pictureBox1->Top<0)
							 pictureBox1->Top=0;
				 automaton->Paint(panel1,pictureBox1,zoom);
			 }

		 }
private: System::Void toolStripButton10_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(zoom>1)
			 {

			 zoom--;
			 int a;
				int width=automaton->width,height=automaton->height;
				 if(panel1->Width/width>(panel1->Height)/height)
						a=(panel1->Height)/height;
					else
						a=panel1->Width/width;
					if(a<1)
					{
						a=1;
					}
					a*=zoom;
					pictureBox1->Top=0;
					pictureBox1->Left=0;
					panel1->AutoScroll=false;
					panel1->AutoScroll=true;
					pictureBox1->Height=height*a;
						 pictureBox1->Width=width*a;
						 pictureBox1->Left=(panel1->Width-pictureBox1->Width)/2;
						// if(pictureBox1->Left<0)
							// pictureBox1->Left=0;
						 pictureBox1->Top=(panel1->Height-pictureBox1->Height)/2;
						 //if(pictureBox1->Top<0)
							// pictureBox1->Top=0;
				 automaton->Paint(panel1,pictureBox1,zoom);
			 }
		 }
};
}

