
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Step;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ V_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ V2_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Vi_V2i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ OLP;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Hi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ C1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ C2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ui;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ui_Vi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dUdxi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dUdx_2i;
	private: System::Windows::Forms::ComboBox^ comboBox_additional;
	private: System::Windows::Forms::Label^ label1;
















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
			this->Step = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->V_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->V2_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Vi_V2i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OLP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Hi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Ui = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Ui_Vi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dUdxi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dUdx_2i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(548, 58);
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
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(13) {
				this->Step, this->X_i,
					this->V_i, this->V2_i, this->Vi_V2i, this->OLP, this->Hi, this->C1, this->C2, this->Ui, this->Ui_Vi, this->dUdxi, this->dUdx_2i
			});
			this->dataGridView1->Location = System::Drawing::Point(1624, 57);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->Size = System::Drawing::Size(798, 629);
			this->dataGridView1->TabIndex = 2;
			// 
			// Step
			// 
			this->Step->HeaderText = L"i";
			this->Step->MinimumWidth = 10;
			this->Step->Name = L"Step";
			this->Step->Width = 200;
			// 
			// X_i
			// 
			this->X_i->HeaderText = L"X_i";
			this->X_i->MinimumWidth = 10;
			this->X_i->Name = L"X_i";
			this->X_i->ReadOnly = true;
			this->X_i->Width = 200;
			// 
			// V_i
			// 
			this->V_i->HeaderText = L"V_i";
			this->V_i->MinimumWidth = 10;
			this->V_i->Name = L"V_i";
			this->V_i->ReadOnly = true;
			this->V_i->Width = 200;
			// 
			// V2_i
			// 
			this->V2_i->HeaderText = L"V2_i";
			this->V2_i->MinimumWidth = 10;
			this->V2_i->Name = L"V2_i";
			this->V2_i->Width = 200;
			// 
			// Vi_V2i
			// 
			this->Vi_V2i->HeaderText = L"V_i-V2_i";
			this->Vi_V2i->MinimumWidth = 10;
			this->Vi_V2i->Name = L"Vi_V2i";
			this->Vi_V2i->ReadOnly = true;
			this->Vi_V2i->Width = 200;
			// 
			// OLP
			// 
			this->OLP->HeaderText = L"ОЛП";
			this->OLP->MinimumWidth = 10;
			this->OLP->Name = L"OLP";
			this->OLP->ReadOnly = true;
			this->OLP->Width = 200;
			// 
			// Hi
			// 
			this->Hi->HeaderText = L"h_i";
			this->Hi->MinimumWidth = 10;
			this->Hi->Name = L"Hi";
			this->Hi->Width = 200;
			// 
			// C1
			// 
			this->C1->HeaderText = L"C1";
			this->C1->MinimumWidth = 10;
			this->C1->Name = L"C1";
			this->C1->ReadOnly = true;
			this->C1->Width = 200;
			// 
			// C2
			// 
			this->C2->HeaderText = L"C2";
			this->C2->MinimumWidth = 10;
			this->C2->Name = L"C2";
			this->C2->ReadOnly = true;
			this->C2->Width = 200;
			// 
			// Ui
			// 
			this->Ui->HeaderText = L"ui";
			this->Ui->MinimumWidth = 10;
			this->Ui->Name = L"Ui";
			this->Ui->Width = 200;
			// 
			// Ui_Vi
			// 
			this->Ui_Vi->HeaderText = L"|ui-vi|";
			this->Ui_Vi->MinimumWidth = 10;
			this->Ui_Vi->Name = L"Ui_Vi";
			this->Ui_Vi->Width = 200;
			// 
			// dUdxi
			// 
			this->dUdxi->HeaderText = L"(dU/dx)i";
			this->dUdxi->MinimumWidth = 10;
			this->dUdxi->Name = L"dUdxi";
			this->dUdxi->ReadOnly = true;
			this->dUdxi->Width = 200;
			// 
			// dUdx_2i
			// 
			this->dUdx_2i->HeaderText = L"(dUdx_2)i";
			this->dUdx_2i->MinimumWidth = 10;
			this->dUdx_2i->Name = L"dUdx_2i";
			this->dUdx_2i->ReadOnly = true;
			this->dUdx_2i->Width = 200;
			// 
			// label_x_min
			// 
			this->label_x_min->AutoSize = true;
			this->label_x_min->Location = System::Drawing::Point(32, 719);
			this->label_x_min->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_x_min->Name = L"label_x_min";
			this->label_x_min->Size = System::Drawing::Size(69, 25);
			this->label_x_min->TabIndex = 3;
			this->label_x_min->Text = L"x_min";
			// 
			// textBox_x_min
			// 
			this->textBox_x_min->Location = System::Drawing::Point(112, 712);
			this->textBox_x_min->Margin = System::Windows::Forms::Padding(6);
			this->textBox_x_min->Name = L"textBox_x_min";
			this->textBox_x_min->Size = System::Drawing::Size(92, 31);
			this->textBox_x_min->TabIndex = 4;
			this->textBox_x_min->Text = L"0";
			// 
			// label_u0
			// 
			this->label_u0->AutoSize = true;
			this->label_u0->Location = System::Drawing::Point(65, 333);
			this->label_u0->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_u0->Name = L"label_u0";
			this->label_u0->Size = System::Drawing::Size(86, 25);
			this->label_u0->TabIndex = 5;
			this->label_u0->Text = L"u(0) = 0";
			// 
			// label_h
			// 
			this->label_h->AutoSize = true;
			this->label_h->Location = System::Drawing::Point(340, 717);
			this->label_h->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_h->Name = L"label_h";
			this->label_h->Size = System::Drawing::Size(24, 25);
			this->label_h->TabIndex = 7;
			this->label_h->Text = L"h";
			// 
			// textBox_h
			// 
			this->textBox_h->Location = System::Drawing::Point(382, 712);
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
			this->label_u_shtrix_0->Location = System::Drawing::Point(65, 386);
			this->label_u_shtrix_0->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_u_shtrix_0->Name = L"label_u_shtrix_0";
			this->label_u_shtrix_0->Size = System::Drawing::Size(90, 25);
			this->label_u_shtrix_0->TabIndex = 12;
			this->label_u_shtrix_0->Text = L"u\'(0) = 0";
			// 
			// textBox_x_max
			// 
			this->textBox_x_max->Location = System::Drawing::Point(112, 762);
			this->textBox_x_max->Margin = System::Windows::Forms::Padding(6);
			this->textBox_x_max->Name = L"textBox_x_max";
			this->textBox_x_max->Size = System::Drawing::Size(92, 31);
			this->textBox_x_max->TabIndex = 11;
			this->textBox_x_max->Text = L"1";
			// 
			// label_x_max
			// 
			this->label_x_max->AutoSize = true;
			this->label_x_max->Location = System::Drawing::Point(70, 768);
			this->label_x_max->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_x_max->Name = L"label_x_max";
			this->label_x_max->Size = System::Drawing::Size(24, 25);
			this->label_x_max->TabIndex = 10;
			this->label_x_max->Text = L"L";
			// 
			// textBox_P
			// 
			this->textBox_P->Location = System::Drawing::Point(112, 818);
			this->textBox_P->Margin = System::Windows::Forms::Padding(6);
			this->textBox_P->Name = L"textBox_P";
			this->textBox_P->Size = System::Drawing::Size(118, 31);
			this->textBox_P->TabIndex = 15;
			this->textBox_P->Text = L"0.1";
			// 
			// label_alpha
			// 
			this->label_alpha->AutoSize = true;
			this->label_alpha->Location = System::Drawing::Point(68, 824);
			this->label_alpha->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_alpha->Name = L"label_alpha";
			this->label_alpha->Size = System::Drawing::Size(26, 25);
			this->label_alpha->TabIndex = 14;
			this->label_alpha->Text = L"P";
			// 
			// textBox_EI
			// 
			this->textBox_EI->Location = System::Drawing::Point(112, 883);
			this->textBox_EI->Margin = System::Windows::Forms::Padding(6);
			this->textBox_EI->Name = L"textBox_EI";
			this->textBox_EI->Size = System::Drawing::Size(118, 31);
			this->textBox_EI->TabIndex = 17;
			this->textBox_EI->Text = L"0.1";
			// 
			// label_betta
			// 
			this->label_betta->AutoSize = true;
			this->label_betta->Location = System::Drawing::Point(63, 886);
			this->label_betta->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_betta->Name = L"label_betta";
			this->label_betta->Size = System::Drawing::Size(31, 25);
			this->label_betta->TabIndex = 16;
			this->label_betta->Text = L"EI";
			// 
			// textBox__max_h
			// 
			this->textBox__max_h->Location = System::Drawing::Point(980, 840);
			this->textBox__max_h->Margin = System::Windows::Forms::Padding(6);
			this->textBox__max_h->Name = L"textBox__max_h";
			this->textBox__max_h->Size = System::Drawing::Size(118, 31);
			this->textBox__max_h->TabIndex = 23;
			this->textBox__max_h->Text = L"1000";
			// 
			// label_max_h
			// 
			this->label_max_h->AutoSize = true;
			this->label_max_h->Location = System::Drawing::Point(754, 848);
			this->label_max_h->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_max_h->Name = L"label_max_h";
			this->label_max_h->Size = System::Drawing::Size(207, 25);
			this->label_max_h->TabIndex = 22;
			this->label_max_h->Text = L"Макс. кол-во шагов";
			// 
			// textBox__granica
			// 
			this->textBox__granica->Location = System::Drawing::Point(980, 783);
			this->textBox__granica->Margin = System::Windows::Forms::Padding(6);
			this->textBox__granica->Name = L"textBox__granica";
			this->textBox__granica->Size = System::Drawing::Size(118, 31);
			this->textBox__granica->TabIndex = 21;
			this->textBox__granica->Text = L"1e-7";
			// 
			// label_granica
			// 
			this->label_granica->AutoSize = true;
			this->label_granica->Location = System::Drawing::Point(656, 788);
			this->label_granica->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_granica->Name = L"label_granica";
			this->label_granica->Size = System::Drawing::Size(305, 25);
			this->label_granica->TabIndex = 20;
			this->label_granica->Text = L"Параметр выхода за границу";
			// 
			// textBox__loc_pogr
			// 
			this->textBox__loc_pogr->Location = System::Drawing::Point(980, 712);
			this->textBox__loc_pogr->Margin = System::Windows::Forms::Padding(6);
			this->textBox__loc_pogr->Name = L"textBox__loc_pogr";
			this->textBox__loc_pogr->Size = System::Drawing::Size(118, 31);
			this->textBox__loc_pogr->TabIndex = 19;
			this->textBox__loc_pogr->Text = L"1e-7";
			// 
			// label_loc_pogr
			// 
			this->label_loc_pogr->AutoSize = true;
			this->label_loc_pogr->Location = System::Drawing::Point(708, 717);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2514, 962);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox_additional);
			this->Controls->Add(this->label_Info_zada);
			this->Controls->Add(this->label_info);
			this->Controls->Add(this->textBox__max_h);
			this->Controls->Add(this->label_max_h);
			this->Controls->Add(this->textBox__granica);
			this->Controls->Add(this->label_granica);
			this->Controls->Add(this->textBox__loc_pogr);
			this->Controls->Add(this->label_loc_pogr);
			this->Controls->Add(this->textBox_EI);
			this->Controls->Add(this->label_betta);
			this->Controls->Add(this->textBox_P);
			this->Controls->Add(this->label_alpha);
			this->Controls->Add(this->label_u_shtrix_0);
			this->Controls->Add(this->textBox_x_max);
			this->Controls->Add(this->label_x_max);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox_h);
			this->Controls->Add(this->label_h);
			this->Controls->Add(this->label_u0);
			this->Controls->Add(this->textBox_x_min);
			this->Controls->Add(this->label_x_min);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zedGraphControl1);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
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


			double eps = Convert::ToDouble(textBox__loc_pogr->Text);
			std::vector<RK4_stepdata> table = RK4_solve(L, P, EI, eps, barier, x0, u0, du0, h, L, smax);

			int steps_count = table.size();
			double distance_to_boundary = L - table.back().xi;

			double x_at_maxh = 0.0;
			double x_at_minh = 0.0;
			double h_min = 1000000;
			double h_max = 0.0;
			int count_C1 = 0;
			int count_C2 = 0;

			for (const auto& row : table) {
				if (row.hi < h_min) { h_min = row.hi; x_at_minh = row.xi; };
				if (row.hi > h_max) { h_max = row.hi;  x_at_maxh = row.xi; };
				if (row.c1 > 0) count_C1 += row.c1;
				if (row.c2 > 0) count_C2 += row.c2;
			}
			//Выводим инфу в lable

			label_info->Text = "Количество шагов = " + steps_count +
				"\nРасстояние до границы = " + distance_to_boundary.ToString("F8") +
				"\n\nМинимальный шаг h_min = " + h_min.ToString("F8") +
				" при x = " + x_at_minh.ToString("F8") +
				"\nМаксимальный шаг h_max = " + h_max.ToString("F8") +
				" при x = " + x_at_maxh.ToString("F8") +
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
				dataGridView1->Rows[row]->Cells[1]->Value = step.xi.ToString("F8");
				dataGridView1->Rows[row]->Cells[2]->Value = step.v1i.ToString("F8");
				dataGridView1->Rows[row]->Cells[3]->Value = step.v1_2i.ToString("F8");
				dataGridView1->Rows[row]->Cells[4]->Value = step.v1i_v1_2i.ToString("F8");
				dataGridView1->Rows[row]->Cells[5]->Value = step.error.ToString("F8");
				dataGridView1->Rows[row]->Cells[6]->Value = step.hi.ToString("F8");
				dataGridView1->Rows[row]->Cells[7]->Value = step.c1;
				dataGridView1->Rows[row]->Cells[8]->Value = step.c2;
				dataGridView1->Rows[row]->Cells[11]->Value = step.v2i;
				dataGridView1->Rows[row]->Cells[12]->Value = step.v2_2i;
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
			panel->AddCurve("Приближенное решение", f_list, Color::Red, SymbolType::Circle);
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
	};
}