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
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

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
		System::ComponentModel::Container^ components;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1006, 516);
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
			this->label4->Location = System::Drawing::Point(133, 9);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(630, 83);
			this->label4->TabIndex = 2;
			this->label4->Text = L"XUSH KELIBSIZ!";
			// 
			// panel2
			// 
			this->panel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->kirish);
			this->panel2->Controls->Add(this->anonim);
			this->panel2->Controls->Add(this->parol);
			this->panel2->Controls->Add(this->login);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(91, 125);
			this->panel2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(460, 308);
			this->panel2->TabIndex = 0;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Forma1::panel2_Paint);
			// 
			// checkBox1
			// 
			this->checkBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->checkBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->checkBox1->FlatAppearance->BorderSize = 0;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.12727F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkBox1->Location = System::Drawing::Point(150, 194);
			this->checkBox1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(181, 24);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->Text = L"parolni ko\'rsatish";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Forma1::checkBox1_CheckedChanged);
			// 
			// kirish
			// 
			this->kirish->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->kirish->BackColor = System::Drawing::Color::Transparent;
			this->kirish->FlatAppearance->BorderSize = 0;
			this->kirish->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->kirish->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->kirish->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->kirish->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->kirish->Location = System::Drawing::Point(278, 232);
			this->kirish->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->kirish->Name = L"kirish";
			this->kirish->Size = System::Drawing::Size(140, 33);
			this->kirish->TabIndex = 2;
			this->kirish->Text = L"KIRISH";
			this->kirish->UseVisualStyleBackColor = false;
			this->kirish->Click += gcnew System::EventHandler(this, &Forma1::kirish_Click);
			this->kirish->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Forma1::kirish_paint);
			this->kirish->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Forma1::kirish_MouseDown);
			this->kirish->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Forma1::kirish_MouseUp);
			// 
			// anonim
			// 
			this->anonim->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->anonim->BackColor = System::Drawing::Color::Transparent;
			this->anonim->FlatAppearance->BorderSize = 0;
			this->anonim->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->anonim->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->anonim->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->anonim->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->anonim->Location = System::Drawing::Point(56, 232);
			this->anonim->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->anonim->Name = L"anonim";
			this->anonim->Size = System::Drawing::Size(168, 33);
			this->anonim->TabIndex = 2;
			this->anonim->Text = L"ANONIM";
			this->anonim->UseVisualStyleBackColor = false;
			this->anonim->Click += gcnew System::EventHandler(this, &Forma1::anonim_Click);
			this->anonim->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Forma1::anonim_paint);
			this->anonim->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Forma1::anonim_MouseDown);
			this->anonim->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Forma1::anonim_MouseUp);
			// 
			// parol
			// 
			this->parol->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->parol->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->parol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->parol->Location = System::Drawing::Point(150, 156);
			this->parol->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->parol->Name = L"parol";
			this->parol->Size = System::Drawing::Size(266, 31);
			this->parol->TabIndex = 1;
			this->parol->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma1::parol_KeyDown);
			// 
			// login
			// 
			this->login->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->login->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->login->Location = System::Drawing::Point(150, 101);
			this->login->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->login->Name = L"login";
			this->login->Size = System::Drawing::Size(266, 31);
			this->login->TabIndex = 1;
			this->login->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma1::login_KeyDown);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.70909F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(45, 103);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"LOGIN:";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.70909F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(42, 158);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 29);
			this->label5->TabIndex = 0;
			this->label5->Text = L"PAROL:";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.29091F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(158, 19);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 39);
			this->label2->TabIndex = 0;
			this->label2->Text = L"KIRISH";
			// 
			// Forma1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1006, 516);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
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
		bool kirishPressed = false;
		bool anonimPressed = false;
		System::Void Forma1_Load(System::Object^ sender, System::EventArgs^ e)
		{

			// Tugmaning Tab orqali tanlanishini ham o'chiramiz
			anonim->TabStop = false;

			// Standart fokus ramkasini (dotted line) o'chirish
			anonim->FlatAppearance->BorderSize = 0;
			anonim->FlatAppearance->MouseDownBackColor = Color::Transparent;
			anonim->FlatAppearance->MouseOverBackColor = Color::Transparent;
			panel1->BackgroundImage = Image::FromFile("kirish.jpg");
			parol->UseSystemPasswordChar = true;
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
	private:System::Void parol_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		if (e->KeyCode == System::Windows::Forms::Keys::Enter)
		{
			this->kirish->PerformClick();
			e->Handled = true;
			e->SuppressKeyPress = true;
		}
	}

private: System::Void kirish_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ connString = "Server=.\\SQLEXPRESS; Database=shaxsiy; Trusted_Connection=True; TrustServerCertificate=True;";
	SqlConnection^ ulanish = gcnew SqlConnection(connString);

	String^ query = "SELECT id, login, jshshir FROM hisob WHERE login = @login AND parol = @parol";
	SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
	buyruq->Parameters->AddWithValue("@login", login->Text->Trim());
	buyruq->Parameters->AddWithValue("@parol", parol->Text->Trim());

	try {
		ulanish->Open();
		SqlDataReader^ oquvchi = buyruq->ExecuteReader();

		if (oquvchi->Read()) {

			String^ log = oquvchi["login"]->ToString();
			Object^ id = oquvchi["id"];
			Object^ jshshir = oquvchi["jshshir"];

			// 🔴 Reader yopamiz (MUHIM!)
			oquvchi->Close();

			// Forma ochish
			Forma4^ forma4 = gcnew Forma4(log, this);
			forma4->StartPosition = FormStartPosition::Manual;
			forma4->Location = this->Location;
			forma4->Size = this->Size;
			this->Hide();
			forma4->Show();

			login->Clear();
			parol->Clear();
			anonim->BackColor = System::Drawing::Color::White;

			// 🔥 STATISTIKA YOZISH
			String^ query2 = "INSERT INTO HarakatlarStatistikasi (shaxs_id, jshshir, turi, izoh) VALUES (@id, @jsh, 'KIRISH', @log)";
			SqlCommand^ cmd = gcnew SqlCommand(query2, ulanish);

			cmd->Parameters->AddWithValue("@id", id);
			cmd->Parameters->AddWithValue("@jsh", jshshir);
			cmd->Parameters->AddWithValue("@log", "Tizimga kirdi");

			cmd->ExecuteNonQuery();
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

	private: System::Void anonim_Click(System::Object^ sender, System::EventArgs^ e) {
		anonim->BackColor = System::Drawing::Color::White;
		Forma3^ forma3 = gcnew Forma3(this);
		forma3->StartPosition = FormStartPosition::Manual;
		forma3->Location = this->Location;
		forma3->Size = this->Size;
		forma3->Show();
		this->Hide();
		this->ActiveControl = nullptr;
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		parol->UseSystemPasswordChar = !checkBox1->Checked;
	}
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->SmoothingMode = SmoothingMode::AntiAlias;

		// Shaffof oq rangli cho'tka
		SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(40, 255, 255, 255));

		// Yumaloq to'rtburchak chizish (Rectangle radius bilan)
		int r = 25; // Burchak radiusi
		GraphicsPath^ path = gcnew GraphicsPath();
		path->AddArc(0, 0, r, r, 180, 90);
		path->AddArc(panel2->Width - r, 0, r, r, 270, 90);
		path->AddArc(panel2->Width - r, panel2->Height - r, r, r, 0, 90);
		path->AddArc(0, panel2->Height - r, r, r, 90, 90);
		path->CloseAllFigures();

		g->FillPath(brush, path);

		// Panel chegarasini nozik oq chiziq bilan chizish (Elegant ko'rinish beradi)
		Pen^ pen = gcnew Pen(Color::FromArgb(80, 255, 255, 255), 1);
		g->DrawPath(pen, path);
	}
		   // --- KIRISH TUGMASI ---
private: System::Void kirish_paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ g = e->Graphics;
	g->SmoothingMode = SmoothingMode::AntiAlias;

	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, kirish->Width, kirish->Height);
	int r = 25;

	GraphicsPath^ path = gcnew GraphicsPath();
	path->AddArc(0, 0, r, r, 180, 90);
	path->AddArc(rect.Width - r, 0, r, r, 270, 90);
	path->AddArc(rect.Width - r, rect.Height - r, r, r, 0, 90);
	path->AddArc(0, rect.Height - r, r, r, 90, 90);
	path->CloseAllFigures();

	// Bosilgan bo'lsa to'qroq, bo'lmasa oddiy rang
	Color c1 = kirishPressed ? Color::FromArgb(0, 80, 200) : Color::FromArgb(0, 180, 255);
	Color c2 = kirishPressed ? Color::FromArgb(0, 40, 100) : Color::FromArgb(0, 80, 200);

	LinearGradientBrush^ lgb = gcnew LinearGradientBrush(rect, c1, c2, LinearGradientMode::Vertical);
	g->FillPath(lgb, path);

	TextRenderer::DrawText(g, "KIRISH", kirish->Font, rect, Color::White,
		TextFormatFlags::HorizontalCenter | TextFormatFlags::VerticalCenter);
}

	   // --- ANONIM TUGMASI ---
private: System::Void anonim_paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ g = e->Graphics;
	g->SmoothingMode = SmoothingMode::AntiAlias;

	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, anonim->Width, anonim->Height);
	int r = 25;

	GraphicsPath^ path = gcnew GraphicsPath();
	path->AddArc(0, 0, r, r, 180, 90);
	path->AddArc(rect.Width - r, 0, r, r, 270, 90);
	path->AddArc(rect.Width - r, rect.Height - r, r, r, 0, 90);
	path->AddArc(0, rect.Height - r, r, r, 90, 90);
	path->CloseAllFigures();

	// MUHIM: Tugma shaklini mana shu yumaloq yo'lakka qarab kesamiz
	// Bu orqali 2-rasmdagi oq to'rtburchak fon paydo bo'lishining oldi olinadi
	anonim->Region = gcnew System::Drawing::Region(path);

	// Rang mantiqi
	int alpha1 = anonimPressed ? 180 : 100;
	int alpha2 = anonimPressed ? 120 : 50;

	LinearGradientBrush^ lgb = gcnew LinearGradientBrush(
		rect,
		Color::FromArgb(alpha1, 255, 255, 255),
		Color::FromArgb(alpha2, 255, 255, 255),
		LinearGradientMode::Vertical);

	g->FillPath(lgb, path);

	// Matnni chizish (Rasmda matn konturi ko'rinyapti, shuning uchun oq rangda chizamiz)
	TextRenderer::DrawText(g, "ANONIM", anonim->Font, rect, Color::Gray,
		TextFormatFlags::HorizontalCenter | TextFormatFlags::VerticalCenter);
}
	   // KIRISH tugmasi uchun
private: System::Void kirish_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	kirishPressed = true;
	kirish->Invalidate(); // Tugmani qayta chizishga majburlash
}
private: System::Void kirish_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	kirishPressed = false;
	kirish->Invalidate();
}

	   // ANONIM tugmasi uchun
private: System::Void anonim_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	anonimPressed = true;
	anonim->Invalidate();
}
private: System::Void anonim_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	anonimPressed = false;
	anonim->Invalidate();
}
};
}
