#pragma once
namespace shaxsiy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Forma3
	/// </summary>
	public ref class Forma3 : public System::Windows::Forms::Form
	{
	public:
		Form^ Forma1;
		Forma3(Form^ forma1)
		{
			InitializeComponent();
			Forma1 = forma1;
		}

	protected:
		~Forma3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: String^ connString = "Server=.\\SQLEXPRESS; Database=shaxsiy; Trusted_Connection=True; TrustServerCertificate=True;";
	private: System::Windows::Forms::Button^ qaytish;
	protected:

	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::TextBox^ anonimjshshir;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ anonimizlash;

	private: System::Windows::Forms::TextBox^ malumotmanzil;
	private: System::Windows::Forms::TextBox^ malumotjshshir;
	private: System::Windows::Forms::TextBox^ malumotota;
	private: System::Windows::Forms::TextBox^ malumotfamilya;
	private: System::Windows::Forms::TextBox^ malumotism;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::PictureBox^ anonimrasm;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Forma3::typeid));
			this->qaytish = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->anonimjshshir = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->anonimizlash = (gcnew System::Windows::Forms::Button());
			this->malumotmanzil = (gcnew System::Windows::Forms::TextBox());
			this->malumotjshshir = (gcnew System::Windows::Forms::TextBox());
			this->malumotota = (gcnew System::Windows::Forms::TextBox());
			this->malumotfamilya = (gcnew System::Windows::Forms::TextBox());
			this->malumotism = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->anonimrasm = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->anonimrasm))->BeginInit();
			this->SuspendLayout();
			// 
			// qaytish
			// 
			this->qaytish->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->qaytish->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->qaytish->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.32727F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qaytish->Location = System::Drawing::Point(787, 454);
			this->qaytish->Name = L"qaytish";
			this->qaytish->Size = System::Drawing::Size(191, 50);
			this->qaytish->TabIndex = 1;
			this->qaytish->Text = L"ortga qaytish";
			this->qaytish->UseVisualStyleBackColor = false;
			this->qaytish->Click += gcnew System::EventHandler(this, &Forma3::qaytish_Click);
			// 
			// anonimjshshir
			// 
			this->anonimjshshir->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->anonimjshshir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->anonimjshshir->Location = System::Drawing::Point(272, 28);
			this->anonimjshshir->Name = L"anonimjshshir";
			this->anonimjshshir->Size = System::Drawing::Size(383, 31);
			this->anonimjshshir->TabIndex = 2;
			this->anonimjshshir->TextChanged += gcnew System::EventHandler(this, &Forma3::Jshshir_TextChanged);
			this->anonimjshshir->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma3::anonimjshshir_enter);
			this->anonimjshshir->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Forma3::FaqatRaqam_KeyPress);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.32727F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(134, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 32);
			this->label2->TabIndex = 3;
			this->label2->Text = L"JShShIR";
			// 
			// anonimizlash
			// 
			this->anonimizlash->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->anonimizlash->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->anonimizlash->Location = System::Drawing::Point(677, 27);
			this->anonimizlash->Name = L"anonimizlash";
			this->anonimizlash->Size = System::Drawing::Size(112, 31);
			this->anonimizlash->TabIndex = 4;
			this->anonimizlash->Text = L"Izlash";
			this->anonimizlash->UseVisualStyleBackColor = true;
			this->anonimizlash->Click += gcnew System::EventHandler(this, &Forma3::anonimizlash_Click);
			// 
			// malumotmanzil
			// 
			this->malumotmanzil->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotmanzil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotmanzil->Location = System::Drawing::Point(479, 273);
			this->malumotmanzil->Name = L"malumotmanzil";
			this->malumotmanzil->ReadOnly = true;
			this->malumotmanzil->Size = System::Drawing::Size(388, 31);
			this->malumotmanzil->TabIndex = 24;
			// 
			// malumotjshshir
			// 
			this->malumotjshshir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotjshshir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotjshshir->Location = System::Drawing::Point(479, 236);
			this->malumotjshshir->Name = L"malumotjshshir";
			this->malumotjshshir->ReadOnly = true;
			this->malumotjshshir->Size = System::Drawing::Size(388, 31);
			this->malumotjshshir->TabIndex = 25;
			// 
			// malumotota
			// 
			this->malumotota->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotota->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotota->Location = System::Drawing::Point(479, 199);
			this->malumotota->Name = L"malumotota";
			this->malumotota->ReadOnly = true;
			this->malumotota->Size = System::Drawing::Size(388, 31);
			this->malumotota->TabIndex = 26;
			// 
			// malumotfamilya
			// 
			this->malumotfamilya->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotfamilya->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotfamilya->Location = System::Drawing::Point(479, 162);
			this->malumotfamilya->Name = L"malumotfamilya";
			this->malumotfamilya->ReadOnly = true;
			this->malumotfamilya->Size = System::Drawing::Size(388, 31);
			this->malumotfamilya->TabIndex = 27;
			// 
			// malumotism
			// 
			this->malumotism->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotism->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotism->Location = System::Drawing::Point(479, 125);
			this->malumotism->Name = L"malumotism";
			this->malumotism->ReadOnly = true;
			this->malumotism->Size = System::Drawing::Size(388, 31);
			this->malumotism->TabIndex = 28;
			// 
			// label20
			// 
			this->label20->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label20->Location = System::Drawing::Point(281, 276);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(192, 25);
			this->label20->TabIndex = 19;
			this->label20->Text = L"Yashash manzili:";
			// 
			// label21
			// 
			this->label21->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label21->Location = System::Drawing::Point(358, 239);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(115, 25);
			this->label21->TabIndex = 20;
			this->label21->Text = L"JSHSHIR:";
			// 
			// label22
			// 
			this->label22->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label22->Location = System::Drawing::Point(305, 202);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(168, 25);
			this->label22->TabIndex = 21;
			this->label22->Text = L"Otasining ismi:";
			// 
			// label23
			// 
			this->label23->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label23->Location = System::Drawing::Point(372, 165);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(101, 25);
			this->label23->TabIndex = 22;
			this->label23->Text = L"Familya:";
			// 
			// label24
			// 
			this->label24->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label24->Location = System::Drawing::Point(418, 128);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(55, 25);
			this->label24->TabIndex = 23;
			this->label24->Text = L"Ism:";
			// 
			// anonimrasm
			// 
			this->anonimrasm->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->anonimrasm->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->anonimrasm->Location = System::Drawing::Point(74, 101);
			this->anonimrasm->Name = L"anonimrasm";
			this->anonimrasm->Size = System::Drawing::Size(168, 224);
			this->anonimrasm->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->anonimrasm->TabIndex = 29;
			this->anonimrasm->TabStop = false;
			// 
			// Forma3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1006, 516);
			this->Controls->Add(this->anonimrasm);
			this->Controls->Add(this->malumotmanzil);
			this->Controls->Add(this->malumotjshshir);
			this->Controls->Add(this->malumotota);
			this->Controls->Add(this->malumotfamilya);
			this->Controls->Add(this->malumotism);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->anonimizlash);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->anonimjshshir);
			this->Controls->Add(this->qaytish);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Forma3";
			this->Text = L"Anonim";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->anonimrasm))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String^ k;
private: System::Void Jshshir_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	TextBox^ tb = (TextBox^)sender;

	int cursorPos = tb->SelectionStart;

	// faqat raqam qoldiramiz
	String^ filtered = "";
	for each (wchar_t c in tb->Text)
	{
		if (c >= '0' && c <= '9')
			filtered += c;
	}

	// 14 tadan oshirmaymiz
	if (filtered->Length > 14)
		filtered = filtered->Substring(0, 14);

	// agar o'zgarsa qayta yozamiz
	if (tb->Text != filtered)
	{
		tb->Text = filtered;

		// kursorni to'g'ri joyga qaytarish
		tb->SelectionStart = cursorPos > tb->Text->Length ? tb->Text->Length : cursorPos;
	}

	// rang boshqarish
	if (tb->Text->Length == 14)
		tb->BackColor = System::Drawing::Color::White;
	else
		tb->BackColor = System::Drawing::Color::LightCoral;
}
	private: System::Void FaqatRaqam_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		// faqat raqam va Backspace ruxsat
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8)
		{
			e->Handled = true;
		}
	}
	private: System::Void qaytish_Click(System::Object^ sender, System::EventArgs^ e) {
				Forma1->Show();
				Forma1->StartPosition = FormStartPosition::Manual;
				Forma1->Location = this->Location;
				Forma1->Size = this->Size;
				this->Hide();
	}
private: System::Void anonimizlash_Click(System::Object^ sender, System::EventArgs^ e) {
	if (anonimjshshir->Text->Trim() == "") {
		MessageBox::Show("Iltimos, izlash uchun JShShIR raqamini kiriting!", "Ogohlantirish", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	String^ connString = "Server=.\\SQLEXPRESS; Database=shaxsiy; Trusted_Connection=True; TrustServerCertificate=True;";
	SqlConnection^ ulanish = gcnew SqlConnection(connString);

	String^ query = "SELECT login, ism, familiya, otasining_ismi, manzil,rasm FROM hisob WHERE jshshir = @jsh";

	SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
	buyruq->Parameters->AddWithValue("@jsh", anonimjshshir->Text->Trim());

	try {
		ulanish->Open();
		SqlDataReader^ oquvchi = buyruq->ExecuteReader();
		if (oquvchi->Read()) {
			k = oquvchi["ism"]->ToString(); k = k->Replace("|", "'");
			malumotism->Text = k;
			k = oquvchi["familiya"]->ToString(); k = k->Replace("|", "'");
			malumotfamilya->Text =k;
			k = oquvchi["otasining_ismi"]->ToString(); k = k->Replace("|", "'");
			malumotota->Text = k;
			malumotjshshir->Text = anonimjshshir->Text;
			k = oquvchi["manzil"]->ToString(); k = k->Replace("|", "'");
			malumotmanzil->Text = k;
			k = oquvchi["rasm"]->ToString();
			anonimrasm->Image = Image::FromFile(k);
		}
		else {
			MessageBox::Show("Bunday JShShIR bilan foydalanuvchi topilmadi.", "Natija", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			malumotism->Text = "";
			malumotfamilya->Text = "";
			malumotota->Text = "";
			malumotmanzil->Text = "";
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Xatolik yuz berdi: " + ex->Message);
	}
	finally {
		ulanish->Close();
	}
}
private: System::Void anonimjshshir_enter(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == System::Windows::Forms::Keys::Enter)
	{
		this->anonimizlash->PerformClick();
		e->Handled = true;
		e->SuppressKeyPress = true;
	}
}
};
}
