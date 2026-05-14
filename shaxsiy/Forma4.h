#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h> // Winsock dan oldin buni yuklash tartibni saqlaydi
#include "Forma2.h"
// 14-qator: using namespace System::Data::SqlClient;
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

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
	public ref class Forma4 : public System::Windows::Forms::Form
	{
		String^ id;
	public:
		Form^ Forma1;
		FilterInfoCollection^ videoDevices;
	private: System::Windows::Forms::Button^ qayta;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	public:

	public:
		String^ activeLogin;

		Forma4(String^ login, Form^ forma1)
		{
			InitializeComponent();
			this->activeLogin = login;
			this->Forma1 = forma1;
			this->YuklashMalumotlar();
		}
	public:
		Forma4()
		{

			InitializeComponent();

		}
	public:
		void YuklashMalumotlar()
		{
			try {
				if (String::IsNullOrEmpty(activeLogin)) return;

				String^ connString = "Server=.\\SQLEXPRESS; Database=shaxsiy; Trusted_Connection=True; TrustServerCertificate=True;";
				SqlConnection^ ulanish = gcnew SqlConnection(connString);

				String^ query = "SELECT ism, familiya, otasining_ismi, jshshir, manzil, parol,rasm FROM hisob WHERE login = @login";
				SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
				buyruq->Parameters->AddWithValue("@login", activeLogin);

				ulanish->Open();
				SqlDataReader^ oquvchi = buyruq->ExecuteReader();
				String^ k;
				if (oquvchi->Read()) {
					
					k = oquvchi["ism"]->ToString();k = k->Replace("|", "'");
					this->hisobism->Text = k;
					k = oquvchi["familiya"]->ToString();k = k->Replace("|", "'");
					this->hisobfamilya->Text = k;
					k = oquvchi["otasining_ismi"]->ToString();k = k->Replace("|", "'");
					this->hisobota->Text = k;
					k = oquvchi["jshshir"]->ToString();k = k->Replace("|", "'");
					this->hisobjshshir->Text = k;
					k = oquvchi["manzil"]->ToString();k = k->Replace("|", "'");
					this->hisobmanzil->Text = k;
					k = oquvchi["rasm"]->ToString();
					hisobrasm->Image = Image::FromFile(k);
				}
				ulanish->Close();
			}
			catch (Exception^ ex) {
				System::Windows::Forms::MessageBox::Show("Xato: " + ex->Message);
			}
		}
	private: System::Windows::Forms::Button^ asosiybatafsil;
	private: System::Windows::Forms::Label^ asosiylabel;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ hisob;
	private: System::Windows::Forms::Label^ boshlabel;
	private: System::Windows::Forms::Panel^ panelasosiy;
	private: System::Windows::Forms::Panel^ panelhisob;
	private: System::Windows::Forms::TextBox^ hisobota;

	private: System::Windows::Forms::TextBox^ hisobism;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ hisobrasm;

	private: System::Windows::Forms::TextBox^ hisobjshshir;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ hisobfamilya;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ hisobmanzil;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ parolalmashtir;

	private: System::Windows::Forms::Button^ loginalmashtir;

	private: System::Windows::Forms::TextBox^ hisobparol2;
	private: System::Windows::Forms::TextBox^ hisobparol1;
	private: System::Windows::Forms::TextBox^ hisoblogin2;
	private: System::Windows::Forms::TextBox^ hisoblogin1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panelqoshish;
	private: System::Windows::Forms::TextBox^ qoshishism;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ qoshishfamilya;
	private: System::Windows::Forms::TextBox^ qoshishlogin;
	private: System::Windows::Forms::TextBox^ qoshishmanzil;
	private: System::Windows::Forms::TextBox^ qoshishjshshir;
	private: System::Windows::Forms::TextBox^ qoshishota;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ qoshishparol1;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Button^ qoshishsaqlash;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ rasmtanlash;
	private: System::Windows::Forms::PictureBox^ rasmqoshish;
	private: System::Windows::Forms::TextBox^ qoshishparol2;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Panel^ panelmalumot;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ malumotparol;
	private: System::Windows::Forms::TextBox^ malumotlogin;
	private: System::Windows::Forms::TextBox^ malumotmanzil;
	private: System::Windows::Forms::TextBox^ malumotjshshir;
	private: System::Windows::Forms::TextBox^ malumotota;
	private: System::Windows::Forms::TextBox^ malumotfamilya;
	private: System::Windows::Forms::TextBox^ malumotism;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Button^ tahrir;
	private: System::Windows::Forms::Button^ malumotizlash;
	private: System::Windows::Forms::TextBox^ jshshirizlash;
	private: System::Windows::Forms::Panel^ paneltahrir;
	private: System::Windows::Forms::TextBox^ tahrirmanzil;
	private: System::Windows::Forms::TextBox^ tahrirjshshir;
	private: System::Windows::Forms::TextBox^ tahrirota;
	private: System::Windows::Forms::TextBox^ tahrirfamilya;
	private: System::Windows::Forms::TextBox^ tahrirism;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Button^ saqlash;
	private: System::Windows::Forms::Button^ rasmtanlashtaxrir;
	private: System::Windows::Forms::PictureBox^ rasmtahrir;
	private: System::Windows::Forms::CheckBox^ checkBox1;
private: System::Windows::Forms::PictureBox^ malumotrasm;

	private:
		SOCKET     m_socket = INVALID_SOCKET;
		bool       m_connected = false;
		bool       m_tanishAktiv = false;
		System::Windows::Forms::Timer^ m_timer;

		// Serverga ulanish
		bool SocketUlan() {
			WSADATA wsa;
			if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return false;
			m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (m_socket == INVALID_SOCKET) { WSACleanup(); return false; }
			DWORD timeout = 15000;
			setsockopt(m_socket, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));
			sockaddr_in addr{};
			addr.sin_family = AF_INET;
			addr.sin_port = htons(9999);
			inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
			if (connect(m_socket, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
				closesocket(m_socket); m_socket = INVALID_SOCKET; WSACleanup(); return false;
			}
			m_connected = true;
			return true;
		}

		// Ulanishni yopish
		void SocketYop() {
			if (m_socket != INVALID_SOCKET) {
				unsigned char zero[4] = { 0,0,0,0 };
				send(m_socket, (char*)zero, 4, 0);
				closesocket(m_socket);
				m_socket = INVALID_SOCKET;
			}
			m_connected = false;
			WSACleanup();
		}

		// Bitmap JPEG formatida serverga yuborish
		bool RasmYuborish(System::Drawing::Bitmap^ bmp) {
			if (!m_connected || bmp == nullptr) return false;
			try {
				System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
				bmp->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
				array<Byte>^ buf = ms->ToArray();
				unsigned int sz = (unsigned int)buf->Length;
				unsigned char hdr[4] = {
					(unsigned char)((sz >> 24) & 0xFF),
					(unsigned char)((sz >> 16) & 0xFF),
					(unsigned char)((sz >> 8) & 0xFF),
					(unsigned char)(sz & 0xFF)
				};
				if (send(m_socket, (char*)hdr, 4, 0) != 4) return false;
				pin_ptr<Byte> p = &buf[0];
				int sent = 0;
				while (sent < (int)sz) {
					int n = send(m_socket, (char*)(p + sent), (int)sz - sent, 0);
					if (n <= 0) return false;
					sent += n;
				}
				return true;
			}
			catch (...) { return false; }

		}

		// Serverdan JSHSHIR qatorini olish ("12345678901234\n" yoki "\n")
		String^ JavobOlish() {
			String^ result = "";
			char ch;

			// Serverdan belgi-belgi qilib to '\n' (yangi qator) kelguncha o'qiymiz
			while (true) {
				int n = recv(m_socket, &ch, 1, 0); // Haqiqiy socketdan o'qish
				if (n <= 0) break;                 // Aloqa uzilsa chiqish
				if (ch == '\n') break;             // Satr tugasa chiqish
				result += (wchar_t)ch;
			}

			// Endi olingan "123456789_Ism" matnidan ID ni ajratamiz
			if (!String::IsNullOrEmpty(result)) {
				int ajratkich = result->IndexOf('_');
				if (ajratkich > 0) {
					return result->Substring(0, ajratkich); // Faqat "123456789" qismini qaytaradi
				}
			}

			return result;
		}
		// SQL: id boyicha malumot olish (faqat UI threadida)
		void MalumotKorsatish(String^ idStr) {
			id = idStr;
			m_tanishAktiv = false;
			m_timer->Stop();
			SqlConnection^ ulanish = gcnew SqlConnection(connString);
			try {
				SqlCommand^ cmd = gcnew SqlCommand(
					"SELECT ism, familiya, otasining_ismi, jshshir, manzil "
					"FROM hisob WHERE id = @id", ulanish);
				cmd->Parameters->AddWithValue("@id", int::Parse(idStr));
				ulanish->Open();
				SqlDataReader^ r = cmd->ExecuteReader();
				this->asosiytext->Clear();
				if (r->Read()) {
					this->asosiytext->AppendText("SHAXS ANIQLANDI\r\n\r\n");
					this->asosiytext->AppendText("Ismi:      " + r["ism"]->ToString() + "\r\n");
					this->asosiytext->AppendText("Familyasi: " + r["familiya"]->ToString() + "\r\n");
					this->asosiytext->AppendText("Otasi:     " + r["otasining_ismi"]->ToString() + "\r\n");
					this->asosiytext->AppendText("JShShIR:   " + r["jshshir"]->ToString() + "\r\n");
					this->asosiytext->AppendText("Manzil:    " + r["manzil"]->ToString() + "\r\n");
					asosiylabel->Text = r["ism"]->ToString() + " " + r["familiya"]->ToString();
				}
				else {
					this->asosiytext->AppendText("Yuz tanildi, bazada topilmadi.\r\nJShShIR: ");
					asosiylabel->Text = L"Bazada topilmadi";
				}
				r->Close();
			}
			catch (Exception^ ex) { this->asosiytext->AppendText("SQL xato: " + ex->Message); }
			finally {
				if (ulanish->State == System::Data::ConnectionState::Open) ulanish->Close();
			}
		}

		// Timer tick: tarmoq ishini threadga beradi, UI qotmaydi
		System::Void TimerTick(System::Object^ sender, System::EventArgs^ e) {
			if (!m_tanishAktiv || !m_connected) return;
			System::Drawing::Image^ img = this->asosiypicture->Image;
			if (img == nullptr) return;
			System::Drawing::Bitmap^ bmp = nullptr;
			try { bmp = gcnew System::Drawing::Bitmap(img); }
			catch (...) { return; }
			m_timer->Stop();
			System::Threading::ThreadPool::QueueUserWorkItem(
				gcnew System::Threading::WaitCallback(this, &Forma4::TanishThread), bmp);
		}

		// Tarmoq thread: yuborish + olish + UI ga xabar
		void TanishThread(Object^ state) {
			System::Drawing::Bitmap^ bmp = safe_cast<System::Drawing::Bitmap^>(state);
			try {
				if (!RasmYuborish(bmp)) {
					this->BeginInvoke(gcnew System::Action(this, &Forma4::XatoKorsatish));
					return;
				}
				// Python "3_IvanIvanov\n" yoki "\n" yuboradi
				// Birinchi '_' belgisigacha bo'lgan qism = SQL id
				String^ javob = JavobOlish();
				if (!String::IsNullOrEmpty(javob)) {
					int ajratkich = javob->IndexOf('_');
					String^ idStr = ajratkich > 0 ? javob->Substring(0, ajratkich) : javob;
					this->BeginInvoke(gcnew Action<String^>(this, &Forma4::MalumotKorsatish), idStr);
				}
				else {
					if (this->IsHandleCreated)
						this->BeginInvoke(gcnew System::Action(this, &Forma4::TimerDavom));
				}
			}
			catch (...) { this->BeginInvoke(gcnew System::Action(this, &Forma4::XatoKorsatish)); }
			finally { delete bmp; }
		}

		void TimerDavom() { if (m_tanishAktiv && m_connected) m_timer->Start(); }

		void XatoKorsatish() {
			m_timer->Stop(); m_tanishAktiv = false; m_connected = false;
			this->asosiytext->Clear();
			this->asosiytext->AppendText(
				"Server bilan ulanish uzildi.\r\n"
				"face_server.py ni ishga tushiring,\r\n"
				"keyin 'Asosiy' tugmasini bosing.");
			asosiylabel->Text = L"Ulanish xatosi";
		}



		VideoCaptureDevice^ videoSource;
	public:
		Forma4(Form^ forma1)
		{
			Forma1 = forma1;
			InitializeComponent();
		}



	protected:
		~Forma4()
		{
			try {
				if (videoSource != nullptr) {
					if (videoSource->IsRunning) {
						videoSource->SignalToStop();
						videoSource->WaitForStop();
					}
					videoSource = nullptr;
				}
			}
			catch (...) {

			}
			if (components)
			{
				delete components;
			}
		}
	private: String^ connString = "Server=.\\SQLEXPRESS; Database=shaxsiy; Trusted_Connection=True; TrustServerCertificate=True;";
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ menu;
	private: System::Windows::Forms::Button^ qoshish;
	private: System::Windows::Forms::Button^ malumot;
	private: System::Windows::Forms::Button^ bosh;
	private: System::Windows::Forms::Button^ chiqish;
	private: System::Windows::Forms::PictureBox^ asosiypicture;
	private: System::Windows::Forms::TextBox^ asosiytext;
	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Forma4::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->chiqish = (gcnew System::Windows::Forms::Button());
			this->qoshish = (gcnew System::Windows::Forms::Button());
			this->malumot = (gcnew System::Windows::Forms::Button());
			this->bosh = (gcnew System::Windows::Forms::Button());
			this->menu = (gcnew System::Windows::Forms::Button());
			this->asosiypicture = (gcnew System::Windows::Forms::PictureBox());
			this->asosiytext = (gcnew System::Windows::Forms::TextBox());
			this->asosiybatafsil = (gcnew System::Windows::Forms::Button());
			this->asosiylabel = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->boshlabel = (gcnew System::Windows::Forms::Label());
			this->hisob = (gcnew System::Windows::Forms::Button());
			this->panelasosiy = (gcnew System::Windows::Forms::Panel());
			this->qayta = (gcnew System::Windows::Forms::Button());
			this->panelhisob = (gcnew System::Windows::Forms::Panel());
			this->parolalmashtir = (gcnew System::Windows::Forms::Button());
			this->loginalmashtir = (gcnew System::Windows::Forms::Button());
			this->hisobparol2 = (gcnew System::Windows::Forms::TextBox());
			this->hisobparol1 = (gcnew System::Windows::Forms::TextBox());
			this->hisoblogin2 = (gcnew System::Windows::Forms::TextBox());
			this->hisoblogin1 = (gcnew System::Windows::Forms::TextBox());
			this->hisobmanzil = (gcnew System::Windows::Forms::TextBox());
			this->hisobjshshir = (gcnew System::Windows::Forms::TextBox());
			this->hisobota = (gcnew System::Windows::Forms::TextBox());
			this->hisobfamilya = (gcnew System::Windows::Forms::TextBox());
			this->hisobism = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->hisobrasm = (gcnew System::Windows::Forms::PictureBox());
			this->panelqoshish = (gcnew System::Windows::Forms::Panel());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->rasmtanlash = (gcnew System::Windows::Forms::Button());
			this->rasmqoshish = (gcnew System::Windows::Forms::PictureBox());
			this->qoshishsaqlash = (gcnew System::Windows::Forms::Button());
			this->qoshishparol2 = (gcnew System::Windows::Forms::TextBox());
			this->qoshishparol1 = (gcnew System::Windows::Forms::TextBox());
			this->qoshishlogin = (gcnew System::Windows::Forms::TextBox());
			this->qoshishmanzil = (gcnew System::Windows::Forms::TextBox());
			this->qoshishjshshir = (gcnew System::Windows::Forms::TextBox());
			this->qoshishota = (gcnew System::Windows::Forms::TextBox());
			this->qoshishfamilya = (gcnew System::Windows::Forms::TextBox());
			this->qoshishism = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panelmalumot = (gcnew System::Windows::Forms::Panel());
			this->malumotrasm = (gcnew System::Windows::Forms::PictureBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->malumotparol = (gcnew System::Windows::Forms::TextBox());
			this->malumotlogin = (gcnew System::Windows::Forms::TextBox());
			this->malumotmanzil = (gcnew System::Windows::Forms::TextBox());
			this->malumotjshshir = (gcnew System::Windows::Forms::TextBox());
			this->malumotota = (gcnew System::Windows::Forms::TextBox());
			this->malumotfamilya = (gcnew System::Windows::Forms::TextBox());
			this->malumotism = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->tahrir = (gcnew System::Windows::Forms::Button());
			this->malumotizlash = (gcnew System::Windows::Forms::Button());
			this->jshshirizlash = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->paneltahrir = (gcnew System::Windows::Forms::Panel());
			this->saqlash = (gcnew System::Windows::Forms::Button());
			this->rasmtanlashtaxrir = (gcnew System::Windows::Forms::Button());
			this->rasmtahrir = (gcnew System::Windows::Forms::PictureBox());
			this->tahrirmanzil = (gcnew System::Windows::Forms::TextBox());
			this->tahrirjshshir = (gcnew System::Windows::Forms::TextBox());
			this->tahrirota = (gcnew System::Windows::Forms::TextBox());
			this->tahrirfamilya = (gcnew System::Windows::Forms::TextBox());
			this->tahrirism = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->asosiypicture))->BeginInit();
			this->panel2->SuspendLayout();
			this->panelasosiy->SuspendLayout();
			this->panelhisob->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hisobrasm))->BeginInit();
			this->panelqoshish->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rasmqoshish))->BeginInit();
			this->panelmalumot->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->malumotrasm))->BeginInit();
			this->paneltahrir->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rasmtahrir))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel1->Controls->Add(this->chiqish);
			this->panel1->Controls->Add(this->qoshish);
			this->panel1->Controls->Add(this->malumot);
			this->panel1->Controls->Add(this->bosh);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 516);
			this->panel1->TabIndex = 0;
			// 
			// chiqish
			// 
			this->chiqish->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->chiqish->Cursor = System::Windows::Forms::Cursors::Hand;
			this->chiqish->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->chiqish->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->chiqish->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->chiqish->Location = System::Drawing::Point(0, 467);
			this->chiqish->Name = L"chiqish";
			this->chiqish->Size = System::Drawing::Size(197, 49);
			this->chiqish->TabIndex = 0;
			this->chiqish->Text = L"Chiqish";
			this->chiqish->UseVisualStyleBackColor = true;
			this->chiqish->Click += gcnew System::EventHandler(this, &Forma4::chiqish_Click);
			// 
			// qoshish
			// 
			this->qoshish->Cursor = System::Windows::Forms::Cursors::Hand;
			this->qoshish->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshish->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->qoshish->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->qoshish->Location = System::Drawing::Point(0, 168);
			this->qoshish->Name = L"qoshish";
			this->qoshish->Size = System::Drawing::Size(197, 49);
			this->qoshish->TabIndex = 0;
			this->qoshish->Text = L"Qo\'shish";
			this->qoshish->UseVisualStyleBackColor = true;
			this->qoshish->Click += gcnew System::EventHandler(this, &Forma4::qoshish_Click);
			// 
			// malumot
			// 
			this->malumot->Cursor = System::Windows::Forms::Cursors::Hand;
			this->malumot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumot->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->malumot->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->malumot->Location = System::Drawing::Point(0, 113);
			this->malumot->Name = L"malumot";
			this->malumot->Size = System::Drawing::Size(197, 49);
			this->malumot->TabIndex = 0;
			this->malumot->Text = L"Ma\'lumotlar";
			this->malumot->UseVisualStyleBackColor = true;
			this->malumot->Click += gcnew System::EventHandler(this, &Forma4::malumot_Click);
			// 
			// bosh
			// 
			this->bosh->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bosh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->bosh->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->bosh->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->bosh->Location = System::Drawing::Point(0, 58);
			this->bosh->Name = L"bosh";
			this->bosh->Size = System::Drawing::Size(197, 49);
			this->bosh->TabIndex = 0;
			this->bosh->Text = L"Asosiy";
			this->bosh->UseVisualStyleBackColor = true;
			this->bosh->Click += gcnew System::EventHandler(this, &Forma4::bosh_Click);
			// 
			// menu
			// 
			this->menu->Cursor = System::Windows::Forms::Cursors::Hand;
			this->menu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->menu->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->menu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu.Image")));
			this->menu->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->menu->Location = System::Drawing::Point(3, 3);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(197, 49);
			this->menu->TabIndex = 0;
			this->menu->Text = L"   Menu";
			this->menu->UseVisualStyleBackColor = true;
			this->menu->Click += gcnew System::EventHandler(this, &Forma4::menu_Click);
			this->menu->MouseEnter += gcnew System::EventHandler(this, &Forma4::menu_MouseEnter);
			// 
			// asosiypicture
			// 
			this->asosiypicture->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->asosiypicture->Location = System::Drawing::Point(12, 18);
			this->asosiypicture->Name = L"asosiypicture";
			this->asosiypicture->Size = System::Drawing::Size(592, 373);
			this->asosiypicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->asosiypicture->TabIndex = 1;
			this->asosiypicture->TabStop = false;
			// 
			// asosiytext
			// 
			this->asosiytext->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->asosiytext->BackColor = System::Drawing::Color::MintCream;
			this->asosiytext->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->asosiytext->Location = System::Drawing::Point(610, 18);
			this->asosiytext->Multiline = true;
			this->asosiytext->Name = L"asosiytext";
			this->asosiytext->ReadOnly = true;
			this->asosiytext->Size = System::Drawing::Size(378, 331);
			this->asosiytext->TabIndex = 2;
			// 
			// asosiybatafsil
			// 
			this->asosiybatafsil->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->asosiybatafsil->Cursor = System::Windows::Forms::Cursors::Hand;
			this->asosiybatafsil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->asosiybatafsil->Location = System::Drawing::Point(802, 351);
			this->asosiybatafsil->Name = L"asosiybatafsil";
			this->asosiybatafsil->Size = System::Drawing::Size(186, 40);
			this->asosiybatafsil->TabIndex = 3;
			this->asosiybatafsil->Text = L"Batafsil";
			this->asosiybatafsil->UseVisualStyleBackColor = true;
			this->asosiybatafsil->Click += gcnew System::EventHandler(this, &Forma4::asosiybatafsil_Click);
			// 
			// asosiylabel
			// 
			this->asosiylabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->asosiylabel->AutoSize = true;
			this->asosiylabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->asosiylabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->asosiylabel->Location = System::Drawing::Point(41, 394);
			this->asosiylabel->Name = L"asosiylabel";
			this->asosiylabel->Size = System::Drawing::Size(597, 29);
			this->asosiylabel->TabIndex = 4;
			this->asosiylabel->Text = L"Kamerada bir kishining yuzi ko\'rinishini ta\'minlang!";
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel2->Controls->Add(this->boshlabel);
			this->panel2->Controls->Add(this->hisob);
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1005, 69);
			this->panel2->TabIndex = 5;
			// 
			// boshlabel
			// 
			this->boshlabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->boshlabel->AutoSize = true;
			this->boshlabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->boshlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->boshlabel->Location = System::Drawing::Point(420, 17);
			this->boshlabel->Name = L"boshlabel";
			this->boshlabel->Size = System::Drawing::Size(148, 29);
			this->boshlabel->TabIndex = 2;
			this->boshlabel->Text = L"Bosh sahifa";
			// 
			// hisob
			// 
			this->hisob->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->hisob->BackColor = System::Drawing::SystemColors::Window;
			this->hisob->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hisob.BackgroundImage")));
			this->hisob->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->hisob->Cursor = System::Windows::Forms::Cursors::Hand;
			this->hisob->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.12727F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->hisob->Location = System::Drawing::Point(893, 3);
			this->hisob->Name = L"hisob";
			this->hisob->Size = System::Drawing::Size(109, 63);
			this->hisob->TabIndex = 0;
			this->hisob->Text = L"      Hisob";
			this->hisob->UseVisualStyleBackColor = false;
			this->hisob->Click += gcnew System::EventHandler(this, &Forma4::hisob_Click);
			// 
			// panelasosiy
			// 
			this->panelasosiy->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelasosiy->Controls->Add(this->asosiytext);
			this->panelasosiy->Controls->Add(this->asosiypicture);
			this->panelasosiy->Controls->Add(this->asosiylabel);
			this->panelasosiy->Controls->Add(this->qayta);
			this->panelasosiy->Controls->Add(this->asosiybatafsil);
			this->panelasosiy->Location = System::Drawing::Point(0, 72);
			this->panelasosiy->Name = L"panelasosiy";
			this->panelasosiy->Size = System::Drawing::Size(1002, 441);
			this->panelasosiy->TabIndex = 6;
			// 
			// qayta
			// 
			this->qayta->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->qayta->Cursor = System::Windows::Forms::Cursors::Hand;
			this->qayta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qayta->Location = System::Drawing::Point(610, 351);
			this->qayta->Name = L"qayta";
			this->qayta->Size = System::Drawing::Size(186, 40);
			this->qayta->TabIndex = 3;
			this->qayta->Text = L"Qayta";
			this->qayta->UseVisualStyleBackColor = true;
			this->qayta->Click += gcnew System::EventHandler(this, &Forma4::qayta_Click);
			// 
			// panelhisob
			// 
			this->panelhisob->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelhisob->Controls->Add(this->parolalmashtir);
			this->panelhisob->Controls->Add(this->loginalmashtir);
			this->panelhisob->Controls->Add(this->hisobparol2);
			this->panelhisob->Controls->Add(this->hisobparol1);
			this->panelhisob->Controls->Add(this->hisoblogin2);
			this->panelhisob->Controls->Add(this->hisoblogin1);
			this->panelhisob->Controls->Add(this->hisobmanzil);
			this->panelhisob->Controls->Add(this->hisobjshshir);
			this->panelhisob->Controls->Add(this->hisobota);
			this->panelhisob->Controls->Add(this->hisobfamilya);
			this->panelhisob->Controls->Add(this->hisobism);
			this->panelhisob->Controls->Add(this->label7);
			this->panelhisob->Controls->Add(this->label6);
			this->panelhisob->Controls->Add(this->label5);
			this->panelhisob->Controls->Add(this->label4);
			this->panelhisob->Controls->Add(this->label3);
			this->panelhisob->Controls->Add(this->label2);
			this->panelhisob->Controls->Add(this->label1);
			this->panelhisob->Controls->Add(this->hisobrasm);
			this->panelhisob->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->panelhisob->Location = System::Drawing::Point(203, 72);
			this->panelhisob->Name = L"panelhisob";
			this->panelhisob->Size = System::Drawing::Size(796, 441);
			this->panelhisob->TabIndex = 5;
			// 
			// parolalmashtir
			// 
			this->parolalmashtir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->parolalmashtir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->parolalmashtir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->parolalmashtir->Location = System::Drawing::Point(623, 398);
			this->parolalmashtir->Name = L"parolalmashtir";
			this->parolalmashtir->Size = System::Drawing::Size(139, 31);
			this->parolalmashtir->TabIndex = 3;
			this->parolalmashtir->Text = L"Almashtirish";
			this->parolalmashtir->UseVisualStyleBackColor = true;
			this->parolalmashtir->Click += gcnew System::EventHandler(this, &Forma4::parolalmashtir_Click);
			// 
			// loginalmashtir
			// 
			this->loginalmashtir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->loginalmashtir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->loginalmashtir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->loginalmashtir->Location = System::Drawing::Point(623, 299);
			this->loginalmashtir->Name = L"loginalmashtir";
			this->loginalmashtir->Size = System::Drawing::Size(139, 31);
			this->loginalmashtir->TabIndex = 3;
			this->loginalmashtir->Text = L"Almashtirish";
			this->loginalmashtir->UseVisualStyleBackColor = true;
			this->loginalmashtir->Click += gcnew System::EventHandler(this, &Forma4::loginalmashtir_Click);
			// 
			// hisobparol2
			// 
			this->hisobparol2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hisobparol2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->hisobparol2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->hisobparol2->Location = System::Drawing::Point(339, 398);
			this->hisobparol2->Name = L"hisobparol2";
			this->hisobparol2->Size = System::Drawing::Size(278, 31);
			this->hisobparol2->TabIndex = 2;
			this->hisobparol2->Enter += gcnew System::EventHandler(this, &Forma4::hisobparol2_Enter);
			this->hisobparol2->Leave += gcnew System::EventHandler(this, &Forma4::hisoblogin2_Leave);
			// 
			// hisobparol1
			// 
			this->hisobparol1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hisobparol1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->hisobparol1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->hisobparol1->Location = System::Drawing::Point(37, 398);
			this->hisobparol1->Name = L"hisobparol1";
			this->hisobparol1->Size = System::Drawing::Size(278, 31);
			this->hisobparol1->TabIndex = 2;
			this->hisobparol1->Enter += gcnew System::EventHandler(this, &Forma4::hisobparol1_Enter);
			this->hisobparol1->Leave += gcnew System::EventHandler(this, &Forma4::hisobparol1_Leave);
			// 
			// hisoblogin2
			// 
			this->hisoblogin2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hisoblogin2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->hisoblogin2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->hisoblogin2->Location = System::Drawing::Point(339, 299);
			this->hisoblogin2->Name = L"hisoblogin2";
			this->hisoblogin2->Size = System::Drawing::Size(278, 31);
			this->hisoblogin2->TabIndex = 2;
			this->hisoblogin2->Enter += gcnew System::EventHandler(this, &Forma4::hisoblogin2_Enter);
			this->hisoblogin2->Leave += gcnew System::EventHandler(this, &Forma4::hisoblogin2_Leave);
			// 
			// hisoblogin1
			// 
			this->hisoblogin1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hisoblogin1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->hisoblogin1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->hisoblogin1->Location = System::Drawing::Point(37, 299);
			this->hisoblogin1->Name = L"hisoblogin1";
			this->hisoblogin1->Size = System::Drawing::Size(278, 31);
			this->hisoblogin1->TabIndex = 2;
			this->hisoblogin1->Enter += gcnew System::EventHandler(this, &Forma4::hisoblogin1_Enter);
			this->hisoblogin1->Leave += gcnew System::EventHandler(this, &Forma4::hisoblogin1_Leave);
			// 
			// hisobmanzil
			// 
			this->hisobmanzil->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hisobmanzil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->hisobmanzil->Location = System::Drawing::Point(396, 199);
			this->hisobmanzil->Name = L"hisobmanzil";
			this->hisobmanzil->ReadOnly = true;
			this->hisobmanzil->Size = System::Drawing::Size(278, 31);
			this->hisobmanzil->TabIndex = 2;
			// 
			// hisobjshshir
			// 
			this->hisobjshshir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hisobjshshir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->hisobjshshir->Location = System::Drawing::Point(396, 152);
			this->hisobjshshir->Name = L"hisobjshshir";
			this->hisobjshshir->ReadOnly = true;
			this->hisobjshshir->Size = System::Drawing::Size(278, 31);
			this->hisobjshshir->TabIndex = 2;
			// 
			// hisobota
			// 
			this->hisobota->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hisobota->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->hisobota->Location = System::Drawing::Point(396, 107);
			this->hisobota->Name = L"hisobota";
			this->hisobota->ReadOnly = true;
			this->hisobota->Size = System::Drawing::Size(278, 31);
			this->hisobota->TabIndex = 2;
			// 
			// hisobfamilya
			// 
			this->hisobfamilya->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hisobfamilya->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->hisobfamilya->Location = System::Drawing::Point(396, 63);
			this->hisobfamilya->Name = L"hisobfamilya";
			this->hisobfamilya->ReadOnly = true;
			this->hisobfamilya->Size = System::Drawing::Size(278, 31);
			this->hisobfamilya->TabIndex = 2;
			// 
			// hisobism
			// 
			this->hisobism->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hisobism->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->hisobism->Location = System::Drawing::Point(396, 21);
			this->hisobism->Name = L"hisobism";
			this->hisobism->ReadOnly = true;
			this->hisobism->Size = System::Drawing::Size(278, 31);
			this->hisobism->TabIndex = 2;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label7->Location = System::Drawing::Point(32, 353);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(204, 25);
			this->label7->TabIndex = 1;
			this->label7->Text = L"parolni almashtirish:";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->Location = System::Drawing::Point(32, 253);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(202, 25);
			this->label6->TabIndex = 1;
			this->label6->Text = L"loginni almashtirish:";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->Location = System::Drawing::Point(214, 202);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(176, 25);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Yashash manzili:";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->Location = System::Drawing::Point(283, 155);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(107, 25);
			this->label4->TabIndex = 1;
			this->label4->Text = L"JSHSHIR:";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->Location = System::Drawing::Point(237, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 25);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Otasining ismi:";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(281, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Familyasi:";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(334, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Ismi:";
			// 
			// hisobrasm
			// 
			this->hisobrasm->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hisobrasm->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->hisobrasm->Location = System::Drawing::Point(37, -9);
			this->hisobrasm->Name = L"hisobrasm";
			this->hisobrasm->Size = System::Drawing::Size(168, 224);
			this->hisobrasm->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->hisobrasm->TabIndex = 0;
			this->hisobrasm->TabStop = false;
			// 
			// panelqoshish
			// 
			this->panelqoshish->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelqoshish->Controls->Add(this->checkBox2);
			this->panelqoshish->Controls->Add(this->rasmtanlash);
			this->panelqoshish->Controls->Add(this->rasmqoshish);
			this->panelqoshish->Controls->Add(this->qoshishsaqlash);
			this->panelqoshish->Controls->Add(this->qoshishparol2);
			this->panelqoshish->Controls->Add(this->qoshishparol1);
			this->panelqoshish->Controls->Add(this->qoshishlogin);
			this->panelqoshish->Controls->Add(this->qoshishmanzil);
			this->panelqoshish->Controls->Add(this->qoshishjshshir);
			this->panelqoshish->Controls->Add(this->qoshishota);
			this->panelqoshish->Controls->Add(this->qoshishfamilya);
			this->panelqoshish->Controls->Add(this->qoshishism);
			this->panelqoshish->Controls->Add(this->label15);
			this->panelqoshish->Controls->Add(this->label14);
			this->panelqoshish->Controls->Add(this->label13);
			this->panelqoshish->Controls->Add(this->label12);
			this->panelqoshish->Controls->Add(this->label11);
			this->panelqoshish->Controls->Add(this->label10);
			this->panelqoshish->Controls->Add(this->label9);
			this->panelqoshish->Controls->Add(this->label8);
			this->panelqoshish->Location = System::Drawing::Point(0, 75);
			this->panelqoshish->Name = L"panelqoshish";
			this->panelqoshish->Size = System::Drawing::Size(1002, 441);
			this->panelqoshish->TabIndex = 4;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->checkBox2->Location = System::Drawing::Point(491, 31);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(249, 29);
			this->checkBox2->TabIndex = 5;
			this->checkBox2->Text = L"Admin qilib tayinlash";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Forma4::checkBox2_CheckedChanged);
			// 
			// rasmtanlash
			// 
			this->rasmtanlash->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->rasmtanlash->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->rasmtanlash->Location = System::Drawing::Point(46, 238);
			this->rasmtanlash->Name = L"rasmtanlash";
			this->rasmtanlash->Size = System::Drawing::Size(168, 34);
			this->rasmtanlash->TabIndex = 4;
			this->rasmtanlash->Text = L"Rasm tanlash:";
			this->rasmtanlash->UseVisualStyleBackColor = true;
			this->rasmtanlash->Click += gcnew System::EventHandler(this, &Forma4::rasmtanlash_Click);
			// 
			// rasmqoshish
			// 
			this->rasmqoshish->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->rasmqoshish->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->rasmqoshish->Location = System::Drawing::Point(46, 13);
			this->rasmqoshish->Name = L"rasmqoshish";
			this->rasmqoshish->Size = System::Drawing::Size(168, 224);
			this->rasmqoshish->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->rasmqoshish->TabIndex = 3;
			this->rasmqoshish->TabStop = false;
			// 
			// qoshishsaqlash
			// 
			this->qoshishsaqlash->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishsaqlash->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishsaqlash->Location = System::Drawing::Point(557, 375);
			this->qoshishsaqlash->Name = L"qoshishsaqlash";
			this->qoshishsaqlash->Size = System::Drawing::Size(258, 34);
			this->qoshishsaqlash->TabIndex = 2;
			this->qoshishsaqlash->Text = L"Saqlash";
			this->qoshishsaqlash->UseVisualStyleBackColor = true;
			this->qoshishsaqlash->Click += gcnew System::EventHandler(this, &Forma4::qoshishsaqlash_Click);
			// 
			// qoshishparol2
			// 
			this->qoshishparol2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishparol2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishparol2->Location = System::Drawing::Point(479, 333);
			this->qoshishparol2->Name = L"qoshishparol2";
			this->qoshishparol2->Size = System::Drawing::Size(388, 31);
			this->qoshishparol2->TabIndex = 1;
			this->qoshishparol2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::QoshishEnterMove);
			// 
			// qoshishparol1
			// 
			this->qoshishparol1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishparol1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishparol1->Location = System::Drawing::Point(479, 296);
			this->qoshishparol1->Name = L"qoshishparol1";
			this->qoshishparol1->Size = System::Drawing::Size(388, 31);
			this->qoshishparol1->TabIndex = 1;
			this->qoshishparol1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::QoshishEnterMove);
			// 
			// qoshishlogin
			// 
			this->qoshishlogin->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishlogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishlogin->Location = System::Drawing::Point(479, 259);
			this->qoshishlogin->Name = L"qoshishlogin";
			this->qoshishlogin->Size = System::Drawing::Size(388, 31);
			this->qoshishlogin->TabIndex = 1;
			this->qoshishlogin->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::QoshishEnterMove);
			// 
			// qoshishmanzil
			// 
			this->qoshishmanzil->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishmanzil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishmanzil->Location = System::Drawing::Point(479, 222);
			this->qoshishmanzil->Name = L"qoshishmanzil";
			this->qoshishmanzil->Size = System::Drawing::Size(388, 31);
			this->qoshishmanzil->TabIndex = 1;
			this->qoshishmanzil->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::QoshishEnterMove);
			// 
			// qoshishjshshir
			// 
			this->qoshishjshshir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishjshshir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishjshshir->Location = System::Drawing::Point(479, 185);
			this->qoshishjshshir->Name = L"qoshishjshshir";
			this->qoshishjshshir->Size = System::Drawing::Size(388, 31);
			this->qoshishjshshir->TabIndex = 1;
			this->qoshishjshshir->TextChanged += gcnew System::EventHandler(this, &Forma4::Jshshir_TextChanged);
			this->qoshishjshshir->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::QoshishEnterMove);
			this->qoshishjshshir->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Forma4::jshshir_KeyPress);
			// 
			// qoshishota
			// 
			this->qoshishota->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishota->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishota->Location = System::Drawing::Point(479, 148);
			this->qoshishota->Name = L"qoshishota";
			this->qoshishota->Size = System::Drawing::Size(388, 31);
			this->qoshishota->TabIndex = 1;
			this->qoshishota->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::QoshishEnterMove);
			// 
			// qoshishfamilya
			// 
			this->qoshishfamilya->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishfamilya->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishfamilya->Location = System::Drawing::Point(479, 111);
			this->qoshishfamilya->Name = L"qoshishfamilya";
			this->qoshishfamilya->Size = System::Drawing::Size(388, 31);
			this->qoshishfamilya->TabIndex = 1;
			this->qoshishfamilya->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::QoshishEnterMove);
			// 
			// qoshishism
			// 
			this->qoshishism->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishism->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishism->Location = System::Drawing::Point(479, 74);
			this->qoshishism->Name = L"qoshishism";
			this->qoshishism->Size = System::Drawing::Size(388, 31);
			this->qoshishism->TabIndex = 1;
			this->qoshishism->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::QoshishEnterMove);
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label15->Location = System::Drawing::Point(332, 336);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(141, 25);
			this->label15->TabIndex = 0;
			this->label15->Text = L"Qayta parol:";
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label14->Location = System::Drawing::Point(399, 299);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(74, 25);
			this->label14->TabIndex = 0;
			this->label14->Text = L"Parol:";
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label13->Location = System::Drawing::Point(396, 262);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(77, 25);
			this->label13->TabIndex = 0;
			this->label13->Text = L"Login:";
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label12->Location = System::Drawing::Point(281, 225);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(192, 25);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Yashash manzili:";
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label11->Location = System::Drawing::Point(358, 188);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(115, 25);
			this->label11->TabIndex = 0;
			this->label11->Text = L"JSHSHIR:";
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label10->Location = System::Drawing::Point(305, 151);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(168, 25);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Otasining ismi:";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label9->Location = System::Drawing::Point(372, 114);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(101, 25);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Familya:";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label8->Location = System::Drawing::Point(418, 77);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 25);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Ism:";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// panelmalumot
			// 
			this->panelmalumot->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelmalumot->Controls->Add(this->malumotrasm);
			this->panelmalumot->Controls->Add(this->checkBox1);
			this->panelmalumot->Controls->Add(this->malumotparol);
			this->panelmalumot->Controls->Add(this->malumotlogin);
			this->panelmalumot->Controls->Add(this->malumotmanzil);
			this->panelmalumot->Controls->Add(this->malumotjshshir);
			this->panelmalumot->Controls->Add(this->malumotota);
			this->panelmalumot->Controls->Add(this->malumotfamilya);
			this->panelmalumot->Controls->Add(this->malumotism);
			this->panelmalumot->Controls->Add(this->label18);
			this->panelmalumot->Controls->Add(this->label19);
			this->panelmalumot->Controls->Add(this->label20);
			this->panelmalumot->Controls->Add(this->label21);
			this->panelmalumot->Controls->Add(this->label22);
			this->panelmalumot->Controls->Add(this->label23);
			this->panelmalumot->Controls->Add(this->label24);
			this->panelmalumot->Controls->Add(this->tahrir);
			this->panelmalumot->Controls->Add(this->malumotizlash);
			this->panelmalumot->Controls->Add(this->jshshirizlash);
			this->panelmalumot->Controls->Add(this->label16);
			this->panelmalumot->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panelmalumot->Location = System::Drawing::Point(0, 72);
			this->panelmalumot->Name = L"panelmalumot";
			this->panelmalumot->Size = System::Drawing::Size(1002, 441);
			this->panelmalumot->TabIndex = 5;
			// 
			// malumotrasm
			// 
			this->malumotrasm->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotrasm->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->malumotrasm->Location = System::Drawing::Point(131, 89);
			this->malumotrasm->Name = L"malumotrasm";
			this->malumotrasm->Size = System::Drawing::Size(168, 224);
			this->malumotrasm->TabIndex = 20;
			this->malumotrasm->TabStop = false;
			// 
			// checkBox1
			// 
			this->checkBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->checkBox1->Location = System::Drawing::Point(921, 321);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 19;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// malumotparol
			// 
			this->malumotparol->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotparol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotparol->Location = System::Drawing::Point(527, 311);
			this->malumotparol->Name = L"malumotparol";
			this->malumotparol->PasswordChar = '*';
			this->malumotparol->ReadOnly = true;
			this->malumotparol->Size = System::Drawing::Size(388, 31);
			this->malumotparol->TabIndex = 12;
			// 
			// malumotlogin
			// 
			this->malumotlogin->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotlogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotlogin->Location = System::Drawing::Point(527, 274);
			this->malumotlogin->Name = L"malumotlogin";
			this->malumotlogin->ReadOnly = true;
			this->malumotlogin->Size = System::Drawing::Size(388, 31);
			this->malumotlogin->TabIndex = 13;
			// 
			// malumotmanzil
			// 
			this->malumotmanzil->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotmanzil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotmanzil->Location = System::Drawing::Point(527, 237);
			this->malumotmanzil->Name = L"malumotmanzil";
			this->malumotmanzil->ReadOnly = true;
			this->malumotmanzil->Size = System::Drawing::Size(388, 31);
			this->malumotmanzil->TabIndex = 14;
			// 
			// malumotjshshir
			// 
			this->malumotjshshir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotjshshir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotjshshir->Location = System::Drawing::Point(527, 200);
			this->malumotjshshir->Name = L"malumotjshshir";
			this->malumotjshshir->ReadOnly = true;
			this->malumotjshshir->Size = System::Drawing::Size(388, 31);
			this->malumotjshshir->TabIndex = 15;
			// 
			// malumotota
			// 
			this->malumotota->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotota->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotota->Location = System::Drawing::Point(527, 163);
			this->malumotota->Name = L"malumotota";
			this->malumotota->ReadOnly = true;
			this->malumotota->Size = System::Drawing::Size(388, 31);
			this->malumotota->TabIndex = 16;
			// 
			// malumotfamilya
			// 
			this->malumotfamilya->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotfamilya->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotfamilya->Location = System::Drawing::Point(527, 126);
			this->malumotfamilya->Name = L"malumotfamilya";
			this->malumotfamilya->ReadOnly = true;
			this->malumotfamilya->Size = System::Drawing::Size(388, 31);
			this->malumotfamilya->TabIndex = 17;
			// 
			// malumotism
			// 
			this->malumotism->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotism->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotism->Location = System::Drawing::Point(527, 89);
			this->malumotism->Name = L"malumotism";
			this->malumotism->ReadOnly = true;
			this->malumotism->Size = System::Drawing::Size(388, 31);
			this->malumotism->TabIndex = 18;
			// 
			// label18
			// 
			this->label18->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label18->Location = System::Drawing::Point(447, 314);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(74, 25);
			this->label18->TabIndex = 4;
			this->label18->Text = L"Parol:";
			// 
			// label19
			// 
			this->label19->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label19->Location = System::Drawing::Point(444, 277);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(77, 25);
			this->label19->TabIndex = 5;
			this->label19->Text = L"Login:";
			// 
			// label20
			// 
			this->label20->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label20->Location = System::Drawing::Point(329, 240);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(192, 25);
			this->label20->TabIndex = 6;
			this->label20->Text = L"Yashash manzili:";
			// 
			// label21
			// 
			this->label21->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label21->Location = System::Drawing::Point(406, 203);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(115, 25);
			this->label21->TabIndex = 7;
			this->label21->Text = L"JSHSHIR:";
			// 
			// label22
			// 
			this->label22->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label22->Location = System::Drawing::Point(353, 166);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(168, 25);
			this->label22->TabIndex = 8;
			this->label22->Text = L"Otasining ismi:";
			// 
			// label23
			// 
			this->label23->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label23->Location = System::Drawing::Point(420, 129);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(101, 25);
			this->label23->TabIndex = 9;
			this->label23->Text = L"Familya:";
			// 
			// label24
			// 
			this->label24->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label24->Location = System::Drawing::Point(466, 92);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(55, 25);
			this->label24->TabIndex = 10;
			this->label24->Text = L"Ism:";
			// 
			// tahrir
			// 
			this->tahrir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tahrir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->tahrir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tahrir->Location = System::Drawing::Point(802, 355);
			this->tahrir->Name = L"tahrir";
			this->tahrir->Size = System::Drawing::Size(111, 31);
			this->tahrir->TabIndex = 2;
			this->tahrir->Text = L"Tahrirlash";
			this->tahrir->UseVisualStyleBackColor = true;
			this->tahrir->Click += gcnew System::EventHandler(this, &Forma4::tahrir_Click);
			// 
			// malumotizlash
			// 
			this->malumotizlash->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->malumotizlash->Cursor = System::Windows::Forms::Cursors::Hand;
			this->malumotizlash->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->malumotizlash->Location = System::Drawing::Point(802, 37);
			this->malumotizlash->Name = L"malumotizlash";
			this->malumotizlash->Size = System::Drawing::Size(111, 31);
			this->malumotizlash->TabIndex = 2;
			this->malumotizlash->Text = L"Izlash";
			this->malumotizlash->UseVisualStyleBackColor = true;
			this->malumotizlash->Click += gcnew System::EventHandler(this, &Forma4::malumotizlash_Click);
			// 
			// jshshirizlash
			// 
			this->jshshirizlash->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->jshshirizlash->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->jshshirizlash->Location = System::Drawing::Point(276, 41);
			this->jshshirizlash->Name = L"jshshirizlash";
			this->jshshirizlash->Size = System::Drawing::Size(497, 31);
			this->jshshirizlash->TabIndex = 1;
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label16->Location = System::Drawing::Point(155, 40);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(115, 25);
			this->label16->TabIndex = 0;
			this->label16->Text = L"JSHSHIR:";
			// 
			// paneltahrir
			// 
			this->paneltahrir->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->paneltahrir->Controls->Add(this->saqlash);
			this->paneltahrir->Controls->Add(this->rasmtanlashtaxrir);
			this->paneltahrir->Controls->Add(this->rasmtahrir);
			this->paneltahrir->Controls->Add(this->tahrirmanzil);
			this->paneltahrir->Controls->Add(this->tahrirjshshir);
			this->paneltahrir->Controls->Add(this->tahrirota);
			this->paneltahrir->Controls->Add(this->tahrirfamilya);
			this->paneltahrir->Controls->Add(this->tahrirism);
			this->paneltahrir->Controls->Add(this->label25);
			this->paneltahrir->Controls->Add(this->label26);
			this->paneltahrir->Controls->Add(this->label27);
			this->paneltahrir->Controls->Add(this->label28);
			this->paneltahrir->Controls->Add(this->label29);
			this->paneltahrir->Location = System::Drawing::Point(0, 72);
			this->paneltahrir->Name = L"paneltahrir";
			this->paneltahrir->Size = System::Drawing::Size(1002, 441);
			this->paneltahrir->TabIndex = 19;
			// 
			// saqlash
			// 
			this->saqlash->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->saqlash->Cursor = System::Windows::Forms::Cursors::Hand;
			this->saqlash->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->saqlash->Location = System::Drawing::Point(676, 304);
			this->saqlash->Name = L"saqlash";
			this->saqlash->Size = System::Drawing::Size(189, 34);
			this->saqlash->TabIndex = 30;
			this->saqlash->Text = L"saqlash";
			this->saqlash->UseVisualStyleBackColor = true;
			this->saqlash->Click += gcnew System::EventHandler(this, &Forma4::saqlash_Click);
			// 
			// rasmtanlashtaxrir
			// 
			this->rasmtanlashtaxrir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->rasmtanlashtaxrir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->rasmtanlashtaxrir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->rasmtanlashtaxrir->Location = System::Drawing::Point(46, 234);
			this->rasmtanlashtaxrir->Name = L"rasmtanlashtaxrir";
			this->rasmtanlashtaxrir->Size = System::Drawing::Size(189, 34);
			this->rasmtanlashtaxrir->TabIndex = 30;
			this->rasmtanlashtaxrir->Text = L"Rasm tanlash:";
			this->rasmtanlashtaxrir->UseVisualStyleBackColor = true;
			this->rasmtanlashtaxrir->Click += gcnew System::EventHandler(this, &Forma4::rasmtanlashtaxrir_Click);
			// 
			// rasmtahrir
			// 
			this->rasmtahrir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->rasmtahrir->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->rasmtahrir->Location = System::Drawing::Point(46, 9);
			this->rasmtahrir->Name = L"rasmtahrir";
			this->rasmtahrir->Size = System::Drawing::Size(189, 219);
			this->rasmtahrir->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->rasmtahrir->TabIndex = 29;
			this->rasmtahrir->TabStop = false;
			// 
			// tahrirmanzil
			// 
			this->tahrirmanzil->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tahrirmanzil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tahrirmanzil->Location = System::Drawing::Point(530, 200);
			this->tahrirmanzil->Name = L"tahrirmanzil";
			this->tahrirmanzil->Size = System::Drawing::Size(388, 31);
			this->tahrirmanzil->TabIndex = 24;
			this->tahrirmanzil->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::TahrirEnterMove);
			// 
			// tahrirjshshir
			// 
			this->tahrirjshshir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tahrirjshshir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tahrirjshshir->Location = System::Drawing::Point(530, 163);
			this->tahrirjshshir->Name = L"tahrirjshshir";
			this->tahrirjshshir->Size = System::Drawing::Size(388, 31);
			this->tahrirjshshir->TabIndex = 25;
			this->tahrirjshshir->TextChanged += gcnew System::EventHandler(this, &Forma4::Jshshir_TextChanged);
			this->tahrirjshshir->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::TahrirEnterMove);
			this->tahrirjshshir->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Forma4::jshshir_KeyPress);
			// 
			// tahrirota
			// 
			this->tahrirota->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tahrirota->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tahrirota->Location = System::Drawing::Point(530, 126);
			this->tahrirota->Name = L"tahrirota";
			this->tahrirota->Size = System::Drawing::Size(388, 31);
			this->tahrirota->TabIndex = 26;
			this->tahrirota->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::TahrirEnterMove);
			// 
			// tahrirfamilya
			// 
			this->tahrirfamilya->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tahrirfamilya->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tahrirfamilya->Location = System::Drawing::Point(530, 89);
			this->tahrirfamilya->Name = L"tahrirfamilya";
			this->tahrirfamilya->Size = System::Drawing::Size(388, 31);
			this->tahrirfamilya->TabIndex = 27;
			this->tahrirfamilya->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::TahrirEnterMove);
			// 
			// tahrirism
			// 
			this->tahrirism->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tahrirism->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tahrirism->Location = System::Drawing::Point(530, 52);
			this->tahrirism->Name = L"tahrirism";
			this->tahrirism->Size = System::Drawing::Size(388, 31);
			this->tahrirism->TabIndex = 28;
			this->tahrirism->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Forma4::TahrirEnterMove);
			// 
			// label25
			// 
			this->label25->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label25->Location = System::Drawing::Point(332, 203);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(192, 25);
			this->label25->TabIndex = 19;
			this->label25->Text = L"Yashash manzili:";
			// 
			// label26
			// 
			this->label26->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label26->Location = System::Drawing::Point(409, 166);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(115, 25);
			this->label26->TabIndex = 20;
			this->label26->Text = L"JSHSHIR:";
			// 
			// label27
			// 
			this->label27->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label27->Location = System::Drawing::Point(356, 129);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(168, 25);
			this->label27->TabIndex = 21;
			this->label27->Text = L"Otasining ismi:";
			// 
			// label28
			// 
			this->label28->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label28->Location = System::Drawing::Point(423, 92);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(101, 25);
			this->label28->TabIndex = 22;
			this->label28->Text = L"Familya:";
			// 
			// label29
			// 
			this->label29->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label29->Location = System::Drawing::Point(469, 55);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(55, 25);
			this->label29->TabIndex = 23;
			this->label29->Text = L"Ism:";
			// 
			// Forma4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1006, 516);
			this->Controls->Add(this->menu);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panelqoshish);
			this->Controls->Add(this->panelasosiy);
			this->Controls->Add(this->panelhisob);
			this->Controls->Add(this->paneltahrir);
			this->Controls->Add(this->panelmalumot);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Forma4";
			this->Text = L"Asosiy";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Forma4::Forma4_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Forma4::Forma4_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->asosiypicture))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panelasosiy->ResumeLayout(false);
			this->panelasosiy->PerformLayout();
			this->panelhisob->ResumeLayout(false);
			this->panelhisob->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hisobrasm))->EndInit();
			this->panelqoshish->ResumeLayout(false);
			this->panelqoshish->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rasmqoshish))->EndInit();
			this->panelmalumot->ResumeLayout(false);
			this->panelmalumot->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->malumotrasm))->EndInit();
			this->paneltahrir->ResumeLayout(false);
			this->paneltahrir->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rasmtahrir))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		String^ rasm;
		String^ eskijshshir;
	private: System::Void hisoblogin1_Enter(System::Object^ sender, System::EventArgs^ e) {

				if (hisoblogin1->ForeColor == System::Drawing::Color::Gray) {
					hisoblogin1->Text = L"";
					hisoblogin1->ForeColor = System::Drawing::Color::Black;
				}
				hisoblogin1->SelectAll();
			}
	private: System::Void hisoblogin2_Enter(System::Object^ sender, System::EventArgs^ e) {

		if (hisoblogin2->ForeColor == System::Drawing::Color::Gray) {
			hisoblogin2->Text = L"";
			hisoblogin2->ForeColor = System::Drawing::Color::Black;
		}
		hisoblogin2->SelectAll();
	}
	private: System::Void hisobparol1_Enter(System::Object^ sender, System::EventArgs^ e) {

		if (hisobparol1->ForeColor == System::Drawing::Color::Gray) {
			hisobparol1->Text = L"";
			hisobparol1->ForeColor = System::Drawing::Color::Black;
		}
		hisobparol1->SelectAll();
	}
	private: System::Void hisobparol2_Enter(System::Object^ sender, System::EventArgs^ e) {

		if (hisobparol2->ForeColor == System::Drawing::Color::Gray) {
			hisobparol2->Text = L"";
			hisobparol2->ForeColor = System::Drawing::Color::Black;
		}
		hisobparol2->SelectAll();
	}
	private: System::Void hisoblogin1_Leave(System::Object^ sender, System::EventArgs^ e) {

		if (hisoblogin1->Text->Trim() == L"") {
			hisoblogin1->Text = L"	Joriy login";
			hisoblogin1->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::Void hisoblogin2_Leave(System::Object^ sender, System::EventArgs^ e) {

		if (hisoblogin2->Text->Trim() == L"") {
			hisoblogin2->Text = L"	Yangi login";
			hisoblogin2->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::Void hisobparol1_Leave(System::Object^ sender, System::EventArgs^ e) {

		if (hisobparol1->Text->Trim() == L"") {
			hisobparol1->Text = L"	Joriy parol";
			hisobparol1->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::Void hisobparol2_Leave(System::Object^ sender, System::EventArgs^ e) {

		if (hisobparol2->Text->Trim() == L"") {
			hisobparol2->Text = L"	Yangi parol";
			hisobparol2->ForeColor = System::Drawing::Color::Gray;
		}
	}
private: System::Void TahrirEnterMove(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode != System::Windows::Forms::Keys::Enter)
		return;

	if (sender == tahrirism)
		this->tahrirfamilya->Focus();

	else if (sender == tahrirfamilya)
		this->tahrirota->Focus();

	else if (sender == tahrirota)
		this->tahrirjshshir->Focus();

	else if (sender == tahrirjshshir)
		this->tahrirmanzil->Focus();

	else if (sender == tahrirmanzil)
		this->saqlash->PerformClick();

	e->Handled = true;
	e->SuppressKeyPress = true;
}
	private: System::Void QoshishEnterMove(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		if (e->KeyCode != System::Windows::Forms::Keys::Enter)
			return;

		if (sender == qoshishism)
			this->qoshishfamilya->Focus();

		else if (sender == qoshishfamilya)
			this->qoshishota->Focus();

		else if (sender == qoshishota)
			this->qoshishjshshir->Focus();

		else if (sender == qoshishjshshir)
			this->qoshishmanzil->Focus();

		else if (sender ==qoshishmanzil )
			this->qoshishlogin->Focus();

		else if (sender == qoshishlogin)
			this->qoshishparol1->Focus();

		else if (sender == qoshishparol1)
			this->qoshishparol2->Focus();

		else if (sender == qoshishparol2)
			this->qoshishsaqlash->PerformClick();

		e->Handled = true;
		e->SuppressKeyPress = true;
	}
	private: System::Void jshshir_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8)
		{
			e->Handled = true;
		}
	}
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
	private: System::Void Forma4_Load(System::Object^ sender, System::EventArgs^ e) {
		BackgroundImage = Image::FromFile("asosiy.jpg");
		menu->Size = System::Drawing::Size(48, 48);
		menu->Text = "";
		paneltahrir->Visible = false;
		panelmalumot->Visible = false;
		panel1->Visible = false;
		panelasosiy->Visible = false;
		panelhisob->Visible = false;
		panelqoshish->Visible = false;
	}
	private: void video_NewFrame(System::Object^ sender, NewFrameEventArgs^ eventArgs)
	{
		System::Drawing::Bitmap^ frame = safe_cast<System::Drawing::Bitmap^>(eventArgs->Frame->Clone());
		if (this->asosiypicture->InvokeRequired) {
			this->asosiypicture->BeginInvoke(gcnew System::Action<System::Drawing::Bitmap^>(this, &Forma4::SetNewImage), frame);
		}
		else {
			SetNewImage(frame);
		}
	}

	private: void SetNewImage(System::Drawing::Bitmap^ bmp)
	{
		if (this->asosiypicture->Image != nullptr) {
			try { delete this->asosiypicture->Image; }
			catch (...) {}
		}
		this->asosiypicture->Image = bmp;
	}
	private: System::Void menu_Click(System::Object^ sender, System::EventArgs^ e) {
		if (panel1->Visible == false)
		{
			menu->Text = L"   Menu";
			menu->Size = System::Drawing::Size(197, 49);
			panel1->Visible = true;

		}
		else
		{
			menu->Size = System::Drawing::Size(48, 48);
			menu->Text = "";
			panel1->Visible = false;
		}
	}
	private: System::Void menu_MouseEnter(System::Object^ sender, System::EventArgs^ e)
	{
		this->menu->Text = L"   Menu";
		this->menu->Size = System::Drawing::Size(197, 49);
		this->panel1->Visible = true;
	}
	private: System::Void bosh_Click(System::Object^ sender, System::EventArgs^ e) {
		menu->Size = System::Drawing::Size(48, 48);
		menu->Text = "";
		if (paneltahrir->Visible)  paneltahrir->Visible = false;
		if (panelmalumot->Visible) panelmalumot->Visible = false;
		if (panel1->Visible)       panel1->Visible = false;
		if (panelhisob->Visible)   panelhisob->Visible = false;
		panelasosiy->Visible = true;
		if (panelqoshish->Visible) panelqoshish->Visible = false;
		boshlabel->Text = L"Asosiy";

		try {
			videoDevices = gcnew FilterInfoCollection(FilterCategory::VideoInputDevice);
			if (videoDevices != nullptr && videoDevices->Count > 0) {
				videoSource = gcnew VideoCaptureDevice(videoDevices[0]->MonikerString);
				videoSource->NewFrame += gcnew NewFrameEventHandler(
					this, &Forma4::video_NewFrame);
				videoSource->Start();
			}
		}
		catch (Exception^ ex) {
			this->asosiytext->AppendText("Kamera xato: " + ex->Message + "\r\n");
		}

		this->asosiytext->Clear();
		if (!m_connected) {
			if (SocketUlan()) {
				this->asosiytext->AppendText("Python server bilan ulandi\r\n");
			}
			else {
				this->asosiytext->AppendText("Python server topilmadi!\r\n"
					"   face_server.py ni ishga tushiring.\r\n");
				return;
			}
		}

		// Timer sozlash
		if (m_timer == nullptr) {
			m_timer = gcnew System::Windows::Forms::Timer();
			m_timer->Interval = 2000;  // 2 soniya
			m_timer->Tick += gcnew System::EventHandler(this, &Forma4::TimerTick);
		}
		m_tanishAktiv = true;
		m_timer->Start();
	}
	private: System::Void chiqish_Click(System::Object^ sender, System::EventArgs^ e) {

		if (videoSource != nullptr && videoSource->IsRunning) videoSource->Stop();


		this->Close();
		this->Forma1->StartPosition = FormStartPosition::Manual;
		this->Forma1->Location = this->Location;
		this->Forma1->Size = this->Size;
		this->Forma1->Show();

	}

	private: System::Void hisob_Click(System::Object^ sender, System::EventArgs^ e) {
		hisoblogin1->Text = L"	Joriy login";
		hisoblogin1->ForeColor = System::Drawing::Color::Gray;
		hisoblogin2->Text = L"	Yangi login";
		hisoblogin2->ForeColor = System::Drawing::Color::Gray;
		hisobparol1->Text = L"	Joriy parol";
		hisobparol1->ForeColor = System::Drawing::Color::Gray;
		hisobparol2->Text = L"	Yangi parol";
		hisobparol2->ForeColor = System::Drawing::Color::Gray;
		panelhisob->Visible = true;
		if (paneltahrir->Visible == true) paneltahrir->Visible = false;
		if (panelmalumot->Visible == true) panelmalumot->Visible = false;
		if (panelasosiy->Visible == true) panelasosiy->Visible = false;
		if (panelqoshish->Visible == true) panelqoshish->Visible = false;
		boshlabel->Text = L"Hisob";
		menu->Text = L"   Menu";
		menu->Size = System::Drawing::Size(197, 49);
		panel1->Visible = true;
		if (videoSource != nullptr && videoSource->IsRunning)
		{
			videoSource->Stop();
		}
	}
	private: System::Void rasmtanlash_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ open = gcnew OpenFileDialog();

		open->Filter = "Image Files|*.jpg;*.png;*.jpeg";

		if (open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			rasm = open->FileName;
			rasmtahrir->Image = Image::FromFile(rasm);
		}
	}
	private: System::Void qoshish_Click(System::Object^ sender, System::EventArgs^ e) {
		menu->Size = System::Drawing::Size(48, 48);
		menu->Text = "";
		label13->Visible = false;
		label14->Visible = false;
		label15->Visible = false;
		qoshishlogin->Visible = false;
		qoshishparol1->Visible = false;
		qoshishparol2->Visible = false;
		if (paneltahrir->Visible == true) paneltahrir->Visible = false;
		if (panelmalumot->Visible == true) panelmalumot->Visible = false;
		if (panel1->Visible == true) panel1->Visible = false;
		if (panelhisob->Visible == true) panelhisob->Visible = false;
		if (panelasosiy->Visible == true) panelasosiy->Visible = false;
		panelqoshish->Visible = true;
		boshlabel->Text = L"Qo\'shish";
		if (videoSource != nullptr && videoSource->IsRunning)
		{
			videoSource->Stop();
		}
	}
	private: System::Void malumot_Click(System::Object^ sender, System::EventArgs^ e) {
		menu->Size = System::Drawing::Size(48, 48);
		menu->Text = "";
		panelmalumot->Visible = true;
		if (paneltahrir->Visible == true) paneltahrir->Visible = false;
		if (panel1->Visible == true) panel1->Visible = false;
		if (panelhisob->Visible == true) panelhisob->Visible = false;
		if (panelasosiy->Visible == true) panelasosiy->Visible = false;
		if (panelqoshish->Visible == true) panelqoshish->Visible = false;
		boshlabel->Text = L"Qo\'shish";
		if (videoSource != nullptr && videoSource->IsRunning)
		{
			videoSource->Stop();
		}
	}
	private: System::Void rasmtanlashtaxrir_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ open = gcnew OpenFileDialog();

		open->Filter = "Image Files|*.jpg;*.png;*.jpeg";

		if (open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			rasm = open->FileName;
			rasmtahrir->Image = Image::FromFile(rasm);
		}
	}
	private: System::Void tahrir_Click(System::Object^ sender, System::EventArgs^ e) {
		menu->Size = System::Drawing::Size(48, 48);
		menu->Text = "";
		paneltahrir->Visible = true;
		if (panelmalumot->Visible == true) panelmalumot->Visible = false;
		if (panel1->Visible == true) panel1->Visible = false;
		if (panelhisob->Visible == true) panelhisob->Visible = false;
		if (panelasosiy->Visible == true) panelasosiy->Visible = false;
		if (panelqoshish->Visible == true) panelqoshish->Visible = false;
		boshlabel->Text = L"Qo\'shish";
		if (videoSource != nullptr && videoSource->IsRunning)
		{
			videoSource->Stop();
		}
		tahrirism->Text = malumotism->Text;
		tahrirfamilya->Text = malumotfamilya->Text;
		tahrirota->Text = malumotota->Text;
		tahrirjshshir->Text = malumotjshshir->Text;
		tahrirmanzil->Text = malumotmanzil->Text;
		rasmtahrir->Image = malumotrasm->Image;
	}
	private: System::Void loginalmashtir_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			String^ joriy = hisoblogin1->Text->Trim();
			String^ yangi = hisoblogin2->Text->Trim();

			if (String::IsNullOrEmpty(joriy) || String::IsNullOrEmpty(yangi))
			{
				hisoblogin1->BackColor = System::Drawing::Color::LightCoral;
				hisoblogin2->BackColor = System::Drawing::Color::LightCoral;
			}

			// 🔴 ENG MUHIM TEKSHIRUV
			if (joriy != activeLogin)
			{
				MessageBox::Show("Joriy login noto'g'ri!");
				return;
			}

			String^ connString = "Server=.\\SQLEXPRESS; Database=shaxsiy; Trusted_Connection=True; TrustServerCertificate=True;";
			SqlConnection^ ulanish = gcnew SqlConnection(connString);

			String^ query = "UPDATE hisob SET login = @yangiLogin WHERE login = @eskiLogin";

			SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
			buyruq->Parameters->AddWithValue("@yangiLogin", yangi);
			buyruq->Parameters->AddWithValue("@eskiLogin", activeLogin);

			ulanish->Open();
			int natija = buyruq->ExecuteNonQuery();
			ulanish->Close();

			if (natija > 0)
			{
				MessageBox::Show("Login muvaffaqiyatli o'zgartirildi!");
				hisoblogin1->Text = L"	Joriy login";
				hisoblogin1->ForeColor = System::Drawing::Color::Gray;
				hisoblogin2->Text = L"	Yangi login";
				hisoblogin2->ForeColor = System::Drawing::Color::Gray;
				// active loginni ham yangilaymiz
				activeLogin = yangi;

				YuklashMalumotlar(); // qayta yuklash
			}
			else
			{
				MessageBox::Show("Xatolik yuz berdi!");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Xato: " + ex->Message);
		}
	}
	private: System::Void parolalmashtir_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			String^ joriy = hisobparol1->Text->Trim();
			String^ yangi = hisobparol2->Text->Trim();

			if (String::IsNullOrEmpty(joriy) || String::IsNullOrEmpty(yangi))
			{
				MessageBox::Show("Barcha maydonlarni to'ldiring!");
				return;
			}

			String^ connString = "Server=.\\SQLEXPRESS; Database=shaxsiy; Trusted_Connection=True; TrustServerCertificate=True;";
			SqlConnection^ ulanish = gcnew SqlConnection(connString);

			// 1️⃣ DB dan eski parolni olish
			String^ query = "SELECT parol FROM hisob WHERE login = @login";
			SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
			buyruq->Parameters->AddWithValue("@login", activeLogin);

			ulanish->Open();
			Object^ natija = buyruq->ExecuteScalar();

			String^ dbParol = natija->ToString();

			// 2️⃣ Solishtirish
			if (joriy != dbParol)
			{
				MessageBox::Show("Joriy parol noto'g'ri!");
				ulanish->Close();
				return;
			}

			// 3️⃣ Update qilish
			String^ update = "UPDATE hisob SET parol = @yangiParol WHERE login = @login";
			SqlCommand^ updateCmd = gcnew SqlCommand(update, ulanish);
			updateCmd->Parameters->AddWithValue("@yangiParol", yangi);
			updateCmd->Parameters->AddWithValue("@login", activeLogin);

			updateCmd->ExecuteNonQuery();
			ulanish->Close();
			MessageBox::Show("Parol muvaffaqiyatli o'zgartirildi!");
			hisobparol1->Text = L"	Joriy parol";
			hisobparol1->ForeColor = System::Drawing::Color::Gray;
			hisobparol2->Text = L"	Yangi parol";
			hisobparol2->ForeColor = System::Drawing::Color::Gray;

		}
		catch (Exception^ ex) {
			MessageBox::Show("Xato: " + ex->Message);
		}
	}
	private: System::Void saqlash_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ malumot;
			SqlConnection^ ulanish = gcnew SqlConnection(connString);
			ulanish->Open();
			String^ query = "UPDATE hisob SET ism=@ism, familiya=@familya, otasining_ismi=@otasining_ismi, jshshir=@jshshir, manzil=@manzil, rasm=@rasm WHERE jshshir=@eskijshshir";
			SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
			malumot = tahrirism->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@ism", malumot);
			malumot = tahrirfamilya->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@familya", malumot);
			malumot = tahrirota->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@otasining_ismi", malumot);
			malumot = tahrirjshshir->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@jshshir", malumot);
			malumot = tahrirmanzil->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@manzil", malumot);
			buyruq->Parameters->AddWithValue("@rasm", rasm);
			rasm = nullptr;
			buyruq->ExecuteNonQuery();
			ulanish->Close();
			MessageBox::Show("Ma'lumotlar yangilandi!");
		}
		catch (SqlException^ ex) {
			MessageBox::Show("Tizim xatosi: " + ex->Message);
		}
		tahrirism->Clear();
		tahrirfamilya->Clear();
		tahrirota->Clear();
		tahrirmanzil->Clear();
		tahrirjshshir->Clear();
		rasmtahrir->Image = nullptr;
	}
	private: System::Void qoshishsaqlash_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ malumot;
			SqlConnection^ ulanish = gcnew SqlConnection(connString);
			ulanish->Open();
			String^ query = "INSERT INTO hisob (login, parol, ism, otasining_ismi, familiya, jshshir, manzil, rasm) " +
				"VALUES (@login, @parol, @ism, @familya, @otasining_ismi, @jshshir, @manzil, @rasm)";

			SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
			malumot = qoshishlogin->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@login", malumot);
			malumot = qoshishparol1->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@parol", malumot);
			malumot = qoshishism->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@ism", malumot);
			malumot = qoshishota->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@otasining_ismi", malumot);
			malumot = qoshishfamilya->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@familya", malumot);
			malumot = qoshishjshshir->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@jshshir", malumot);
			malumot = qoshishmanzil->Text; malumot = malumot->Replace("'", "|");
			buyruq->Parameters->AddWithValue("@manzil", malumot);
			buyruq->Parameters->AddWithValue("@rasm", rasm);
			rasm = nullptr;
			buyruq->ExecuteNonQuery();
			ulanish->Close();

			MessageBox::Show("Ma'lumotlar saqlandi!");
		}
		catch (SqlException^ ex) {
			if (ex->Number == 2627) {
				MessageBox::Show("Xato: Bunday Login yoki JShShIR allaqachon mavjud!");
			}
			else {
				MessageBox::Show("Tizim xatosi: " + ex->Message);
			}
		}
		qoshishism->Clear();
		qoshishfamilya->Clear();
		qoshishota->Clear();
		qoshishjshshir->Clear();
		qoshishlogin->Clear();
		qoshishmanzil->Clear();
		qoshishparol1->Clear();
		qoshishparol2->Clear();
		rasmqoshish->Image = nullptr;
	}

	private: System::Void malumotizlash_Click(System::Object^ sender, System::EventArgs^ e) {
		if (jshshirizlash->Text->Trim() == "") {
			MessageBox::Show("Iltimos, izlash uchun JShShIR raqamini kiriting!", "Ogohlantirish", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		String^ connString = "Server=.\\SQLEXPRESS; Database=shaxsiy; Trusted_Connection=True; TrustServerCertificate=True;";
		SqlConnection^ ulanish = gcnew SqlConnection(connString);

		String^ query = "SELECT login, ism, familiya, otasining_ismi, manzil FROM hisob WHERE jshshir = @jshshir";

		SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
		buyruq->Parameters->AddWithValue("@jshshir", jshshirizlash->Text->Trim());

		try {
			ulanish->Open();
			SqlDataReader^ oquvchi = buyruq->ExecuteReader();
			String^ k;
			if (oquvchi->Read()) {
				eskijshshir = oquvchi["jshshir"]->ToString();
				k = oquvchi["ism"]->ToString();k = k->Replace("|", "'");
				this->malumotism->Text = k;
				k = oquvchi["familiya"]->ToString();k = k->Replace("|", "'");
				this->malumotfamilya->Text = k;
				k = oquvchi["otasining_ismi"]->ToString();k = k->Replace("|", "'");
				this->malumotota->Text = k;
				k = oquvchi["jshshir"]->ToString();k = k->Replace("|", "'");
				this->malumotjshshir->Text = k;
				k = oquvchi["manzil"]->ToString();k = k->Replace("|", "'");
				this->malumotmanzil->Text = k;
			}
			else {
				MessageBox::Show("Bunday JShShIR bilan foydalanuvchi topilmadi.", "Natija", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				malumotlogin->Text = "";
				malumotparol->Text = "";
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
		private:System::Void qayta_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!m_connected) { bosh_Click(sender, e); return; }
			this->asosiytext->Clear();
			this->asosiytext->AppendText("Qayta izlanmoqda...\r\n");
			asosiylabel->Text = L"Yuz izlanmoqda...";
			m_tanishAktiv = true;
			if (m_timer != nullptr) m_timer->Start();
		}
	private: System::Void Forma4_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		
	}
	private: System::Void asosiybatafsil_Click(System::Object^ sender, System::EventArgs^ e) {
		panelasosiy->Visible = false;
		panelmalumot->Visible = true;
		boshlabel->Text = L"Batafsil ma'lumot";
		label16->Visible = false;
		jshshirizlash->Visible = false;
		malumotizlash->Visible = false;
		malumotlogin->Visible = false;
		malumotparol->Visible=false;
		label18->Visible = true;
		label19->Visible = true;
		checkBox1->Visible = true;
		SqlConnection^ ulanish = gcnew SqlConnection(connString);
		try {
			SqlCommand^ cmd = gcnew SqlCommand(
				"SELECT login, parol, ism, familiya, otasining_ismi, jshshir, manzil, rasm "
				"FROM hisob WHERE id = @id", ulanish);
			cmd->Parameters->AddWithValue("@id", int::Parse(id));
			ulanish->Open();
			SqlDataReader^ r = cmd->ExecuteReader();
			this->asosiytext->Clear();
			if (r->Read())
			{
				malumotism->Text = r["ism"]->ToString();
				malumotfamilya->Text = r["familiya"]->ToString();
				malumotota->Text = r["otasining_ismi"]->ToString();
				malumotjshshir->Text = r["jshshir"]->ToString();
				malumotmanzil->Text = r["manzil"]->ToString();

				if (r["login"] != DBNull::Value && r["login"]->ToString() != "" && r["parol"] != DBNull::Value && r["parol"]->ToString() != "")
				{
					label18->Visible = true;
					label19->Visible = true;
					checkBox1->Visible = true;
					malumotlogin->Visible = true;
					malumotparol->Visible = true;
					malumotlogin->Text = r["login"]->ToString();
					malumotparol->Text = r["parol"]->ToString();
				}
			}
			else {
				this->asosiytext->AppendText("Yuz tanildi, bazada topilmadi.");
			}
			r->Close();
		}
		catch (Exception^ ex) { this->asosiytext->AppendText("SQL xato: " + ex->Message); }
	}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox2->Checked)
	{
		label13->Visible = true;
		label14->Visible = true;
		label15->Visible = true;
		qoshishlogin->Visible = true;
		qoshishparol1->Visible = true;
		qoshishparol2->Visible = true;
	}
	else
	{
		label13->Visible = false;
		label14->Visible = false;
		label15->Visible = false;
		qoshishlogin->Visible = false;
		qoshishparol1->Visible = false;
		qoshishparol2->Visible = false;
	}
}

};
}