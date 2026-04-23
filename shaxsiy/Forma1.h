#pragma once
// forward declarations to avoid heavy includes in header
#include "Forma3.h"
#include "Forma4.h"
namespace shaxsiy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace AForge::Video;
	using namespace AForge::Video::DirectShow;
	using namespace System::Data;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Forma1
	/// </summary>
	public ref class Forma1 : public System::Windows::Forms::Form
	{
	public:
		
		Forma1(void)
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
		~Forma1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: String^ connString = "Server=.\\SQLEXPRESS; Database=shaxsiy; Trusted_Connection=True; TrustServerCertificate=True;";
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ anonim;
	private: System::Windows::Forms::TextBox^ parol;
	private: System::Windows::Forms::TextBox^ login;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ kirish;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label1;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Forma1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->kirish = (gcnew System::Windows::Forms::Button());
			this->anonim = (gcnew System::Windows::Forms::Button());
			this->parol = (gcnew System::Windows::Forms::TextBox());
			this->login = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(949, 544);
			this->panel1->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 47.78182F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(132, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(630, 83);
			this->label4->TabIndex = 2;
			this->label4->Text = L"XUSH KELIBSIZ!";
			// 
			// panel2
			// 
			this->panel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->kirish);
			this->panel2->Controls->Add(this->anonim);
			this->panel2->Controls->Add(this->parol);
			this->panel2->Controls->Add(this->login);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(73, 124);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(394, 308);
			this->panel2->TabIndex = 0;
			// 
			// checkBox1
			// 
			this->checkBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.12727F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->checkBox1->Location = System::Drawing::Point(129, 194);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(155, 24);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->Text = L"parolni ko\'rsatish";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Forma1::checkBox1_CheckedChanged);
			// 
			// kirish
			// 
			this->kirish->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->kirish->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->kirish->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->kirish->Location = System::Drawing::Point(238, 232);
			this->kirish->Name = L"kirish";
			this->kirish->Size = System::Drawing::Size(120, 33);
			this->kirish->TabIndex = 2;
			this->kirish->Text = L"KIRISH";
			this->kirish->UseVisualStyleBackColor = false;
			this->kirish->Click += gcnew System::EventHandler(this, &Forma1::kirish_Click);
			// 
			// anonim
			// 
			this->anonim->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->anonim->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->anonim->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->anonim->Location = System::Drawing::Point(48, 232);
			this->anonim->Name = L"anonim";
			this->anonim->Size = System::Drawing::Size(144, 33);
			this->anonim->TabIndex = 2;
			this->anonim->Text = L"ANONIM";
			this->anonim->UseVisualStyleBackColor = false;
			this->anonim->Click += gcnew System::EventHandler(this, &Forma1::royhatdanotish_Click);
			// 
			// parol
			// 
			this->parol->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->parol->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->parol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->parol->Location = System::Drawing::Point(129, 156);
			this->parol->Name = L"parol";
			this->parol->Size = System::Drawing::Size(229, 31);
			this->parol->TabIndex = 1;
			this->parol->TextChanged += gcnew System::EventHandler(this, &Forma1::parol_TextChanged);
			// 
			// login
			// 
			this->login->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->login->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->login->Location = System::Drawing::Point(129, 101);
			this->login->Name = L"login";
			this->login->Size = System::Drawing::Size(229, 31);
			this->login->TabIndex = 1;
			this->login->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma1::login_KeyDown);
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(22, 156);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(102, 29);
			this->label5->TabIndex = 0;
			this->label5->Text = L"PAROL";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(138, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 29);
			this->label2->TabIndex = 0;
			this->label2->Text = L"KIRISH";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(21, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"LOGIN";
			// 
			// Forma1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(949, 544);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Forma1";
			this->Text = L"Kirish";
			this->Load += gcnew System::EventHandler(this, &Forma1::Forma1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void parol_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
        parol->UseSystemPasswordChar = true;
		}

	System::Void Forma1_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->ActiveControl = this->login;
		this->login->Select();
	}

	System::Void login_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
			this->parol->Focus();
			e->Handled = true;
			e->SuppressKeyPress = true;
		}
	}

  private: System::Void kirish_Click(System::Object^ sender, System::EventArgs^ e) {
	  String^ connString = "Server=.\\SQLEXPRESS; Database=shaxsiy; Trusted_Connection=True; TrustServerCertificate=True;";
	  SqlConnection^ ulanish = gcnew SqlConnection(connString);
	  String^ query = "SELECT login FROM hisob WHERE login = @login AND parol = @parol";
	  SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
	  buyruq->Parameters->AddWithValue("@login", login->Text->Trim());
	  buyruq->Parameters->AddWithValue("@parol", parol->Text->Trim());

	  try {
		  ulanish->Open();

		  SqlDataReader^ oquvchi = buyruq->ExecuteReader();

		  if (oquvchi->Read()) {
			  String^ log = oquvchi["login"]->ToString();

			  Forma4^ forma4 = gcnew Forma4(log, this);
			  this->Hide();
			  forma4->Show();
			  login->Clear();
			  parol->Clear();
		  }
		  else {
			  anonim->BackColor = System::Drawing::Color::Red;
		  }
	  }
	  catch (Exception^ ex) {
		  MessageBox::Show("Tizimda xatolik: " + ex->Message);
	  }
	  finally {
		  ulanish->Close();
	  }
	}

	private: System::Void royhatdanotish_Click(System::Object^ sender, System::EventArgs^ e) {
		Forma3^ forma3 = gcnew Forma3(this);
		forma3->Show();
		this->Hide();
	}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	parol->UseSystemPasswordChar = !checkBox1->Checked;
}
};
}
