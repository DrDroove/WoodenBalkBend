
#include <math.h>
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include"RK4_method.h"


namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

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
	private: ZedGraph::ZedGraphControl^ zedGraphControl1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ I;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ F_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ F_2;
	private: System::Windows::Forms::Label^ label_x_min;
	private: System::Windows::Forms::TextBox^ textBox_x_min;
	private: System::Windows::Forms::Label^ label_u0;

	private: System::Windows::Forms::Label^ label_h;
	private: System::Windows::Forms::TextBox^ textBox_h;






	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::Label^ label_u_shtrix_0;

	private: System::Windows::Forms::TextBox^ textBox_x_max;

	private: System::Windows::Forms::Label^ label_x_max;
	private: System::Windows::Forms::TextBox^ textBox_P;

	private: System::Windows::Forms::Label^ label_alpha;
	private: System::Windows::Forms::TextBox^ textBox_EI;

	private: System::Windows::Forms::Label^ label_betta;
	private: System::Windows::Forms::TextBox^ textBox__max_h;
	private: System::Windows::Forms::Label^ label_max_h;
	private: System::Windows::Forms::TextBox^ textBox__granica;
	private: System::Windows::Forms::Label^ label_granica;
	private: System::Windows::Forms::TextBox^ textBox__loc_pogr;
	private: System::Windows::Forms::Label^ label_loc_pogr;










	private: System::Windows::Forms::Label^ label_info;

	private: System::Windows::Forms::Label^ label_Info_zada;













	private: System::Windows::Forms::ComboBox^ comboBox_additional;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ adaptive_switch;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;











private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Step;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ X_i;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Hi;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ V_i;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ V2_i;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Vi_V2i;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dUdxi;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dUdx_2i;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ OLP;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ C1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ C2;




















































































	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
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
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label_x_min = (gcnew System::Windows::Forms::Label());
			this->textBox_x_min = (gcnew System::Windows::Forms::TextBox());
			this->label_u0 = (gcnew System::Windows::Forms::Label());
			this->label_h = (gcnew System::Windows::Forms::Label());
			this->textBox_h = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label_u_shtrix_0 = (gcnew System::Windows::Forms::Label());
			this->textBox_x_max = (gcnew System::Windows::Forms::TextBox());
			this->label_x_max = (gcnew System::Windows::Forms::Label());
			this->textBox_P = (gcnew System::Windows::Forms::TextBox());
			this->label_alpha = (gcnew System::Windows::Forms::Label());
			this->textBox_EI = (gcnew System::Windows::Forms::TextBox());
			this->label_betta = (gcnew System::Windows::Forms::Label());
			this->textBox__max_h = (gcnew System::Windows::Forms::TextBox());
			this->label_max_h = (gcnew System::Windows::Forms::Label());
			this->textBox__granica = (gcnew System::Windows::Forms::TextBox());
			this->label_granica = (gcnew System::Windows::Forms::Label());
			this->textBox__loc_pogr = (gcnew System::Windows::Forms::TextBox());
			this->label_loc_pogr = (gcnew System::Windows::Forms::Label());
			this->label_info = (gcnew System::Windows::Forms::Label());
			this->label_Info_zada = (gcnew System::Windows::Forms::Label());
			this->comboBox_additional = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->adaptive_switch = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Step = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Hi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->V_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->V2_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Vi_V2i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dUdxi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dUdx_2i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OLP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(589, 34);
			this->zedGraphControl1->Margin = System::Windows::Forms::Padding(12);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(1002, 629);
			this->zedGraphControl1->TabIndex = 0;
			this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1266, 742);
			this->button1->Margin = System::Windows::Forms::Padding(6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(284, 56);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Нарисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeight = 50;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {
				this->Step, this->X_i,
					this->Hi, this->V_i, this->V2_i, this->Vi_V2i, this->dUdxi, this->dUdx_2i, this->OLP, this->C1, this->C2
			});
			this->dataGridView1->Location = System::Drawing::Point(1622, 34);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->Size = System::Drawing::Size(1189, 600);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// label_x_min
			// 
			this->label_x_min->AutoSize = true;
			this->label_x_min->Location = System::Drawing::Point(27, 63);
			this->label_x_min->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_x_min->Name = L"label_x_min";
			this->label_x_min->Size = System::Drawing::Size(69, 25);
			this->label_x_min->TabIndex = 3;
			this->label_x_min->Text = L"x_min";
			// 
			// textBox_x_min
			// 
			this->textBox_x_min->Location = System::Drawing::Point(146, 63);
			this->textBox_x_min->Margin = System::Windows::Forms::Padding(6);
			this->textBox_x_min->Name = L"textBox_x_min";
			this->textBox_x_min->Size = System::Drawing::Size(92, 31);
			this->textBox_x_min->TabIndex = 4;
			this->textBox_x_min->Text = L"0";
			// 
			// label_u0
			// 
			this->label_u0->AutoSize = true;
			this->label_u0->Location = System::Drawing::Point(3, 71);
			this->label_u0->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_u0->Name = L"label_u0";
			this->label_u0->Size = System::Drawing::Size(86, 25);
			this->label_u0->TabIndex = 5;
			this->label_u0->Text = L"u(0) = 0";
			// 
			// label_h
			// 
			this->label_h->AutoSize = true;
			this->label_h->Location = System::Drawing::Point(49, 63);
			this->label_h->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_h->Name = L"label_h";
			this->label_h->Size = System::Drawing::Size(24, 25);
			this->label_h->TabIndex = 7;
			this->label_h->Text = L"h";
			// 
			// textBox_h
			// 
			this->textBox_h->Location = System::Drawing::Point(96, 57);
			this->textBox_h->Margin = System::Windows::Forms::Padding(6);
			this->textBox_h->Name = L"textBox_h";
			this->textBox_h->Size = System::Drawing::Size(118, 31);
			this->textBox_h->TabIndex = 8;
			this->textBox_h->Text = L"0.01";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1266, 840);
			this->button2->Margin = System::Windows::Forms::Padding(6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(284, 56);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Увеличить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label_u_shtrix_0
			// 
			this->label_u_shtrix_0->AutoSize = true;
			this->label_u_shtrix_0->Location = System::Drawing::Point(3, 110);
			this->label_u_shtrix_0->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_u_shtrix_0->Name = L"label_u_shtrix_0";
			this->label_u_shtrix_0->Size = System::Drawing::Size(90, 25);
			this->label_u_shtrix_0->TabIndex = 12;
			this->label_u_shtrix_0->Text = L"u\'(0) = 0";
			// 
			// textBox_x_max
			// 
			this->textBox_x_max->Location = System::Drawing::Point(146, 114);
			this->textBox_x_max->Margin = System::Windows::Forms::Padding(6);
			this->textBox_x_max->Name = L"textBox_x_max";
			this->textBox_x_max->Size = System::Drawing::Size(92, 31);
			this->textBox_x_max->TabIndex = 11;
			this->textBox_x_max->Text = L"1.0";
			// 
			// label_x_max
			// 
			this->label_x_max->AutoSize = true;
			this->label_x_max->Location = System::Drawing::Point(72, 114);
			this->label_x_max->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_x_max->Name = L"label_x_max";
			this->label_x_max->Size = System::Drawing::Size(24, 25);
			this->label_x_max->TabIndex = 10;
			this->label_x_max->Text = L"L";
			// 
			// textBox_P
			// 
			this->textBox_P->Location = System::Drawing::Point(146, 175);
			this->textBox_P->Margin = System::Windows::Forms::Padding(6);
			this->textBox_P->Name = L"textBox_P";
			this->textBox_P->Size = System::Drawing::Size(92, 31);
			this->textBox_P->TabIndex = 15;
			this->textBox_P->Text = L"1.0";
			// 
			// label_alpha
			// 
			this->label_alpha->AutoSize = true;
			this->label_alpha->Location = System::Drawing::Point(70, 175);
			this->label_alpha->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_alpha->Name = L"label_alpha";
			this->label_alpha->Size = System::Drawing::Size(26, 25);
			this->label_alpha->TabIndex = 14;
			this->label_alpha->Text = L"P";
			// 
			// textBox_EI
			// 
			this->textBox_EI->Location = System::Drawing::Point(146, 224);
			this->textBox_EI->Margin = System::Windows::Forms::Padding(6);
			this->textBox_EI->Name = L"textBox_EI";
			this->textBox_EI->Size = System::Drawing::Size(92, 31);
			this->textBox_EI->TabIndex = 17;
			this->textBox_EI->Text = L"1.0";
			// 
			// label_betta
			// 
			this->label_betta->AutoSize = true;
			this->label_betta->Location = System::Drawing::Point(65, 224);
			this->label_betta->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_betta->Name = L"label_betta";
			this->label_betta->Size = System::Drawing::Size(31, 25);
			this->label_betta->TabIndex = 16;
			this->label_betta->Text = L"EI";
			// 
			// textBox__max_h
			// 
			this->textBox__max_h->Location = System::Drawing::Point(555, 231);
			this->textBox__max_h->Margin = System::Windows::Forms::Padding(6);
			this->textBox__max_h->Name = L"textBox__max_h";
			this->textBox__max_h->Size = System::Drawing::Size(118, 31);
			this->textBox__max_h->TabIndex = 23;
			this->textBox__max_h->Text = L"1000";
			// 
			// label_max_h
			// 
			this->label_max_h->AutoSize = true;
			this->label_max_h->Location = System::Drawing::Point(312, 234);
			this->label_max_h->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_max_h->Name = L"label_max_h";
			this->label_max_h->Size = System::Drawing::Size(207, 25);
			this->label_max_h->TabIndex = 22;
			this->label_max_h->Text = L"Макс. кол-во шагов";
			// 
			// textBox__granica
			// 
			this->textBox__granica->Location = System::Drawing::Point(555, 175);
			this->textBox__granica->Margin = System::Windows::Forms::Padding(6);
			this->textBox__granica->Name = L"textBox__granica";
			this->textBox__granica->Size = System::Drawing::Size(118, 31);
			this->textBox__granica->TabIndex = 21;
			this->textBox__granica->Text = L"1e-7";
			// 
			// label_granica
			// 
			this->label_granica->AutoSize = true;
			this->label_granica->Location = System::Drawing::Point(226, 181);
			this->label_granica->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_granica->Name = L"label_granica";
			this->label_granica->Size = System::Drawing::Size(305, 25);
			this->label_granica->TabIndex = 20;
			this->label_granica->Text = L"Параметр выхода за границу";
			// 
			// textBox__loc_pogr
			// 
			this->textBox__loc_pogr->Location = System::Drawing::Point(555, 60);
			this->textBox__loc_pogr->Margin = System::Windows::Forms::Padding(6);
			this->textBox__loc_pogr->Name = L"textBox__loc_pogr";
			this->textBox__loc_pogr->Size = System::Drawing::Size(118, 31);
			this->textBox__loc_pogr->TabIndex = 19;
			this->textBox__loc_pogr->Text = L"1e-7";
			// 
			// label_loc_pogr
			// 
			this->label_loc_pogr->AutoSize = true;
			this->label_loc_pogr->Location = System::Drawing::Point(267, 63);
			this->label_loc_pogr->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_loc_pogr->Name = L"label_loc_pogr";
			this->label_loc_pogr->Size = System::Drawing::Size(252, 25);
			this->label_loc_pogr->TabIndex = 18;
			this->label_loc_pogr->Text = L"Параметр контроля Л.П";
			// 
			// label_info
			// 
			this->label_info->AutoSize = true;
			this->label_info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_info->Location = System::Drawing::Point(1650, 692);
			this->label_info->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_info->Name = L"label_info";
			this->label_info->Size = System::Drawing::Size(0, 30);
			this->label_info->TabIndex = 25;
			// 
			// label_Info_zada
			// 
			this->label_Info_zada->AutoSize = true;
			this->label_Info_zada->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Info_zada->Location = System::Drawing::Point(32, 222);
			this->label_Info_zada->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_Info_zada->Name = L"label_Info_zada";
			this->label_Info_zada->Size = System::Drawing::Size(0, 30);
			this->label_Info_zada->TabIndex = 28;
			// 
			// comboBox_additional
			// 
			this->comboBox_additional->FormattingEnabled = true;
			this->comboBox_additional->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"U - x", L"dU/dx - x", L"U - dU/dx(Фаз. портрет)" });
			this->comboBox_additional->Location = System::Drawing::Point(37, 86);
			this->comboBox_additional->Name = L"comboBox_additional";
			this->comboBox_additional->Size = System::Drawing::Size(237, 33);
			this->comboBox_additional->TabIndex = 29;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 42);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 25);
			this->label1->TabIndex = 30;
			this->label1->Text = L"График";
			// 
			// adaptive_switch
			// 
			this->adaptive_switch->AutoSize = true;
			this->adaptive_switch->Location = System::Drawing::Point(482, 117);
			this->adaptive_switch->Name = L"adaptive_switch";
			this->adaptive_switch->Size = System::Drawing::Size(191, 29);
			this->adaptive_switch->TabIndex = 31;
			this->adaptive_switch->Text = L"Контроль ОЛП";
			this->adaptive_switch->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(552, 50);
			this->label2->TabIndex = 32;
			this->label2->Text = L"Постановка задачи:\r\nu\'\' [1 + (u\')^2 ]^{ -3/2} = (L^{-1} – x L^{-2} ) PL^2 [ EI ]^"
				L"{ -1}\r\n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(209, 25);
			this->label3->TabIndex = 33;
			this->label3->Text = L"Параметры задачи:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(22, 17);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(332, 25);
			this->label4->TabIndex = 34;
			this->label4->Text = L"Параметры численного метода:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->Controls->Add(this->label_x_min);
			this->panel1->Controls->Add(this->textBox_x_min);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label_x_max);
			this->panel1->Controls->Add(this->textBox_x_max);
			this->panel1->Controls->Add(this->label_alpha);
			this->panel1->Controls->Add(this->textBox_P);
			this->panel1->Controls->Add(this->label_betta);
			this->panel1->Controls->Add(this->textBox_EI);
			this->panel1->Location = System::Drawing::Point(26, 678);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(286, 281);
			this->panel1->TabIndex = 35;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label_h);
			this->panel2->Controls->Add(this->textBox_h);
			this->panel2->Controls->Add(this->label_loc_pogr);
			this->panel2->Controls->Add(this->adaptive_switch);
			this->panel2->Controls->Add(this->textBox__loc_pogr);
			this->panel2->Controls->Add(this->textBox__granica);
			this->panel2->Controls->Add(this->label_granica);
			this->panel2->Controls->Add(this->label_max_h);
			this->panel2->Controls->Add(this->textBox__max_h);
			this->panel2->Location = System::Drawing::Point(538, 678);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(706, 281);
			this->panel2->TabIndex = 36;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->label_u0);
			this->panel3->Controls->Add(this->label_u_shtrix_0);
			this->panel3->Location = System::Drawing::Point(12, 142);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(569, 250);
			this->panel3->TabIndex = 37;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 183);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(423, 50);
			this->label5->TabIndex = 33;
			this->label5->Text = L"Используется евклидова норма вектора \r\nоценки локальной погрешности";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 142);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(331, 25);
			this->label6->TabIndex = 34;
			this->label6->Text = L"Используется явный метод РК4";
			// 
			// Step
			// 
			this->Step->HeaderText = L"i";
			this->Step->MinimumWidth = 10;
			this->Step->Name = L"Step";
			this->Step->Width = 40;
			// 
			// X_i
			// 
			this->X_i->HeaderText = L"X_i";
			this->X_i->MinimumWidth = 10;
			this->X_i->Name = L"X_i";
			this->X_i->ReadOnly = true;
			// 
			// Hi
			// 
			this->Hi->HeaderText = L"Шаг(h_i)";
			this->Hi->MinimumWidth = 10;
			this->Hi->Name = L"Hi";
			// 
			// V_i
			// 
			this->V_i->HeaderText = L"Численое решение(v_i)";
			this->V_i->MinimumWidth = 10;
			this->V_i->Name = L"V_i";
			this->V_i->ReadOnly = true;
			// 
			// V2_i
			// 
			this->V2_i->HeaderText = L"Числ. реш. с пол. шагом(v_2i)";
			this->V2_i->MinimumWidth = 10;
			this->V2_i->Name = L"V2_i";
			// 
			// Vi_V2i
			// 
			this->Vi_V2i->HeaderText = L"v_i-v_2i";
			this->Vi_V2i->MinimumWidth = 10;
			this->Vi_V2i->Name = L"Vi_V2i";
			this->Vi_V2i->ReadOnly = true;
			// 
			// dUdxi
			// 
			this->dUdxi->HeaderText = L"(dU/dx)_i";
			this->dUdxi->MinimumWidth = 10;
			this->dUdxi->Name = L"dUdxi";
			this->dUdxi->ReadOnly = true;
			// 
			// dUdx_2i
			// 
			this->dUdx_2i->HeaderText = L"(dU/dx)_2i";
			this->dUdx_2i->MinimumWidth = 10;
			this->dUdx_2i->Name = L"dUdx_2i";
			this->dUdx_2i->ReadOnly = true;
			// 
			// OLP
			// 
			this->OLP->HeaderText = L"ОЛП";
			this->OLP->MinimumWidth = 10;
			this->OLP->Name = L"OLP";
			this->OLP->ReadOnly = true;
			// 
			// C1
			// 
			this->C1->HeaderText = L"C1";
			this->C1->MinimumWidth = 10;
			this->C1->Name = L"C1";
			this->C1->ReadOnly = true;
			this->C1->Width = 40;
			// 
			// C2
			// 
			this->C2->HeaderText = L"C2";
			this->C2->MinimumWidth = 10;
			this->C2->Name = L"C2";
			this->C2->ReadOnly = true;
			this->C2->Width = 40;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2843, 1879);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox_additional);
			this->Controls->Add(this->label_Info_zada);
			this->Controls->Add(this->label_info);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zedGraphControl1);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MyForm";
			this->Text = L"Задача 11 в.6 Осадчий";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:



		//Тут прописано все для тестовой задачи
		void SolveTaskTest() {}

		//Решение Основной задачи 1
		void SolveTaskMain1() {}

		void SolveTaskMain2() {
			GraphPane^ panel = zedGraphControl1->GraphPane;
			panel->CurveList->Clear();
			PointPairList^ f_list = gcnew PointPairList();

			// Считываем нужные нам данные для решения задачи
			// Тут мы не используем alpha betta и v' так как это для 2ой задачи
			double x0 = Convert::ToDouble(textBox_x_min->Text);
			double L = Convert::ToDouble(textBox_x_max->Text);
			double u0 = 0;
			double du0 = 0;
			double h = Convert::ToDouble(textBox_h->Text);
			int smax = Convert::ToInt32(textBox__max_h->Text);
			double barier = Convert::ToDouble(textBox__granica->Text);
			double P = Convert::ToDouble(textBox_P->Text);
			double EI = Convert::ToDouble(textBox_EI->Text);
			std::vector<RK4_stepdata> table;
			if (adaptive_switch->Checked) {
				double eps = Convert::ToDouble(textBox__loc_pogr->Text);
				table = RK4_solve_adaptive(L, P, EI, eps, barier, x0, u0, du0, h, L, smax);
			}
			else {
				double eps = 0.0;
				table = RK4_solve_const(L, P, EI, eps, barier, x0, u0, du0, h, L, smax);
			}

			int steps_count = table.size();
			double distance_to_boundary = L - table.back().xi;

			double x_at_maxh = 0.0;
			double x_at_minh = 0.0;
			double h_min = 1000000;
			double h_max = 0.0;
			int count_C1 = 0;
			int count_C2 = 0;
			double err_min = 10000000000;
			double err_max = 0.0;
			double x_at_max_err = 0.0;
			double x_at_min_err = 0.0;

			for (const auto& row : table) {
				if (row.hi < h_min) { h_min = row.hi; x_at_minh = row.xi; };
				if (row.hi > h_max) { h_max = row.hi;  x_at_maxh = row.xi; };
				if (row.error > err_max) { err_max =  row.error;  x_at_max_err = row.xi; };
				if ((row.error < err_min)&&(row.i!=0)) { err_min = row.error;  x_at_min_err = row.xi; };
				if (row.c1 > 0) count_C1 += row.c1;
				if (row.c2 > 0) count_C2 += row.c2;
			}
			//Выводим инфу в lable

			label_info->Text = "Количество шагов = " + steps_count +
				"\nРасстояние до границы = " + distance_to_boundary.ToString("F8") +
				"\n\nМинимальный шаг h_min = " + h_min.ToString() +
				" при x = " + x_at_minh.ToString() +
				"\nМаксимальный шаг h_max = " + h_max.ToString("F8") +
				" при x = " + x_at_maxh.ToString("F8") +
				"\nМаксимальная ОЛП = " + err_max.ToString() +
				" при x = " + x_at_max_err.ToString("F8") +
				"\nМинимальная ОЛП = " + err_min.ToString() +
				" при x = " + x_at_min_err.ToString("F8")+
				"\nКоличество увеличений шага = " + count_C1 +
				"\nКоличество уменьшений шага = " + count_C2;



			// Заполняем DataGridView и список для графика
			dataGridView1->Rows->Clear();
			int row = 0;
			double v1imin = std::pow(10, 8);
			double v1imax = 0.0;
			for (auto& step : table)
			{
				if (step.v1i < v1imin) { v1imin = step.v1i; }
				else if (step.v1i > v1imax) { v1imax = step.v1i; }
				// DataGridView
				dataGridView1->Rows->Add();
				dataGridView1->Rows[row]->Cells[0]->Value = (step.i);
				dataGridView1->Rows[row]->Cells[1]->Value = step.xi.ToString();
				dataGridView1->Rows[row]->Cells[3]->Value = step.v1i.ToString();
				dataGridView1->Rows[row]->Cells[4]->Value = step.v1_2i.ToString();
				dataGridView1->Rows[row]->Cells[5]->Value = step.v1i_v1_2i.ToString();
				dataGridView1->Rows[row]->Cells[8]->Value = (step.error).ToString();
				dataGridView1->Rows[row]->Cells[2]->Value = step.hi.ToString();
				dataGridView1->Rows[row]->Cells[9]->Value = step.c1;
				dataGridView1->Rows[row]->Cells[10]->Value = step.c2;
				dataGridView1->Rows[row]->Cells[6]->Value = step.v2i;
				dataGridView1->Rows[row]->Cells[7]->Value = step.v2_2i;
				row++;

				// График (например, метод с текущим шагом vi)
				if (comboBox_additional->SelectedIndex == 0) {
					f_list->Add(step.xi, step.v1i);
				}
				else if (comboBox_additional->SelectedIndex == 1) {
					f_list->Add(step.xi, step.v2i);
				}
				else if (comboBox_additional->SelectedIndex == 2) {
					f_list->Add(step.v1i, step.v2i);
				}
			}

			// добавляем кривые на график
			panel->AddCurve("Численное решение", f_list, Color::Red, SymbolType::Circle);
			if (comboBox_additional->SelectedIndex == 0) {
				panel->XAxis->Scale->Min = x0 - 0.1;
				panel->XAxis->Scale->Max = L + 0.1;
				panel->YAxis->Title->Text = "u(x)";
				panel->XAxis->Title->Text = "x";
			}
			else if (comboBox_additional->SelectedIndex == 1) {
				panel->XAxis->Scale->Min = x0 - 0.1;
				panel->XAxis->Scale->Max = L + 0.1;
				panel->YAxis->Title->Text = "du/dx(x)";
				panel->XAxis->Title->Text = "x";
			}
			else if (comboBox_additional->SelectedIndex == 2) {
				panel->XAxis->Scale->Min = v1imin - 0.1;
				panel->XAxis->Scale->Max = v1imax + 0.1;
				panel->YAxis->Title->Text = "du/dx(x)";
				panel->XAxis->Title->Text = "u{x}";
			}

			zedGraphControl1->AxisChange();
			zedGraphControl1->Invalidate();

		}

	

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		SolveTaskMain2();
	}
	private: System::Void zedGraphControl1_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// конопка увеличения графика
		GraphPane^ panel = zedGraphControl1->GraphPane;
		double xmin = Convert::ToDouble(textBox_x_min->Text);
		double xmax = Convert::ToDouble(textBox_x_max->Text);
		// Устанавливаем интересующий нас интервал по оси X
		panel->XAxis->Scale->Min = xmin;
		panel->XAxis->Scale->Max = xmax;

		// Вызываем метод AxisChange (), чтобы обновить данные об осях. 
		// В противном случае на рисунке будет показана только часть графика, 
		// которая умещается в интервалы по осям, установленные по умолчанию
		zedGraphControl1->AxisChange();
		// Обновляем график
		zedGraphControl1->Invalidate();

	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}