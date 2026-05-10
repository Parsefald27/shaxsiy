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
	public:
		Form^ Forma1;
		FilterInfoCollection^ videoDevices;
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

				String^ query = "SELECT ism, familiya, otasining_ismi, jshshir, manzil, parol FROM hisob WHERE login = @login";
				SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
				buyruq->Parameters->AddWithValue("@login", activeLogin);

				ulanish->Open();
				SqlDataReader^ oquvchi = buyruq->ExecuteReader();

				if (oquvchi->Read()) {
					this->hisobism->Text = oquvchi["ism"]->ToString();
					this->hisobfamilya->Text = oquvchi["familiya"]->ToString();
					this->hisobota->Text = oquvchi["otasining_ismi"]->ToString();
					this->hisobjshshir->Text = oquvchi["jshshir"]->ToString();
					this->hisobmanzil->Text = oquvchi["manzil"]->ToString();
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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ hisobjshshir;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ hisobfamilya;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ hisobmanzil;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
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
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private:
		// Socket
		SOCKET      m_socket = INVALID_SOCKET;
		bool        m_connected = false;
		bool        m_tanishAktiv = false;   // true = hali tanilmagan, yuborish davom etadi

		// Timer (har 3 soniyada rasm yuborish)
		System::Windows::Forms::Timer^ m_timer;

		// ── Socket ulanish ──────────────────────────────────────────
		bool SocketUlan() {
			WSADATA wsa;
			WSAStartup(MAKEWORD(2, 2), &wsa);

			m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (m_socket == INVALID_SOCKET) return false;

			sockaddr_in addr{};
			addr.sin_family = AF_INET;
			addr.sin_port = htons(9999);
			inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

			if (connect(m_socket, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
				closesocket(m_socket);
				m_socket = INVALID_SOCKET;
				return false;
			}
			m_connected = true;
			return true;
		}

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

		// ── Bitmap → JPEG baytlari va serverga yuborish ─────────────
		bool RasmYuborish(System::Drawing::Bitmap^ bmp) {
			if (!m_connected || bmp == nullptr) return false;
			try {
				// Bitmap → MemoryStream (JPEG)
				System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
				bmp->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
				array<Byte>^ imgArr = ms->ToArray();

				// 4 baytli header (big-endian)
				unsigned int sz = imgArr->Length;
				unsigned char hdr[4] = {
					(unsigned char)((sz >> 24) & 0xFF),
					(unsigned char)((sz >> 16) & 0xFF),
					(unsigned char)((sz >> 8) & 0xFF),
					(unsigned char)(sz & 0xFF)
				};
				send(m_socket, (char*)hdr, 4, 0);

				// Rasmni yuborish (pin memory orqali)
				pin_ptr<Byte> p = &imgArr[0];
				int sent = 0;
				while (sent < (int)sz) {
					int n = send(m_socket, (char*)(p + sent), sz - sent, 0);
					if (n <= 0) return false;
					sent += n;
				}
				return true;
			}
			catch (...) { return false; }
		}

		// ── Serverdan JSON javob olish ───────────────────────────────
		String^ JavobOlish() {
			String^ result = "";
			char ch;
			while (true) {
				int n = recv(m_socket, &ch, 1, 0);
				if (n <= 0) break;
				if (ch == '\n') break;
				result += (wchar_t)ch;
			}
			return result;
		}

		// ── JSON dan qiymat olish (oddiy parser) ─────────────────────
		String^ JsonQiymat(String^ json, String^ kalit) {
			String^ search = "\"" + kalit + "\"";
			int pos = json->IndexOf(search);
			if (pos < 0) return "";
			pos = json->IndexOf(":", pos);
			if (pos < 0) return "";
			pos++;
			while (pos < json->Length && (json[pos] == ' ' || json[pos] == '\t')) pos++;
			if (pos >= json->Length) return "";

			if (json[pos] == '"') {
				int end = json->IndexOf('"', pos + 1);
				if (end < 0) return "";
				return json->Substring(pos + 1, end - pos - 1);
			}
			// raqam yoki bool
			int endPos = json->IndexOfAny(gcnew array<wchar_t>{',', '}'}, pos);
			if (endPos < 0) endPos = json->Length;
			return json->Substring(pos, endPos - pos)->Trim();
		}

		// ── SQL dan JSHSHIR bo'yicha ma'lumot olish ──────────────────
		void MalumotKorsatish(String^ jshshir) {
			try {
				SqlConnection^ ulanish = gcnew SqlConnection(connString);
				// Mavjud hisob jadvalidagi ustunlar:
				// login, parol, ism, otasining_ismi, familiya, jshshir, manzil
				String^ query =
					"SELECT ism, familiya, otasining_ismi, jshshir, manzil "
					"FROM hisob WHERE jshshir = @jsh";

				SqlCommand^ cmd = gcnew SqlCommand(query, ulanish);
				cmd->Parameters->AddWithValue("@jsh", jshshir);

				ulanish->Open();
				SqlDataReader^ r = cmd->ExecuteReader();

				if (r->Read()) {
					// asosiytext maydoniga ma'lumotlarni chiqarish
					this->asosiytext->Clear();
					this->asosiytext->AppendText("─── SHAXS ANIQLANDI ───\r\n\r\n");
					this->asosiytext->AppendText("Ismi:       " + r["ism"]->ToString() + "\r\n");
					this->asosiytext->AppendText("Familyasi:  " + r["familiya"]->ToString() + "\r\n");
					this->asosiytext->AppendText("Otasi:      " + r["otasining_ismi"]->ToString() + "\r\n");
					this->asosiytext->AppendText("JShShIR:    " + r["jshshir"]->ToString() + "\r\n");
					this->asosiytext->AppendText("Manzil:     " + r["manzil"]->ToString() + "\r\n");
					this->asosiytext->AppendText("\r\n  Muvaffaqiyatli tanildi!");

					// Shaxs topildi → yuborishni to'xtatamiz
					m_tanishAktiv = false;
					m_timer->Stop();
					asosiylabel->Text = "✅ Shaxs aniqlandi: " + r["ism"]->ToString()
						+ " " + r["familiya"]->ToString();
				}
				else {
					// Python yuz topdi lekin SQL da yo'q
					this->asosiytext->AppendText("⚠ Yuz tanildi (JShShIR: "
						+ jshshir + ") lekin bazada topilmadi.\r\n");
				}
				ulanish->Close();
			}
			catch (Exception^ ex) {
				this->asosiytext->AppendText("SQL xato: " + ex->Message + "\r\n");
			}
		}

		// ── Timer tick: har 3 soniyada ishga tushadi ─────────────────
		System::Void TimerTick(System::Object^ sender, System::EventArgs^ e) {
			if (!m_tanishAktiv) return;

			System::Drawing::Image^ img = this->asosiypicture->Image;
			if (img == nullptr) return;

			System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(img);
			try {
				// 1) Rasmni serverga yuborish
				if (!RasmYuborish(bmp)) {
					this->asosiytext->Clear();
					this->asosiytext->AppendText("❌ Server bilan ulanishda xato!\r\n"
						"   face_server.py ishga tushganini tekshiring.\r\n");
					m_timer->Stop();
					m_tanishAktiv = false;
					return;
				}

				// 2) Python serverdan JSON javob olish
				//    Mumkin javoblar:
				//      {"status":"found",    "jshshir":"12345678901234", "confidence":0.92}
				//      {"status":"not_found","confidence":0.0}
				//      {"status":"error",    "message":"..."}
				String^ javob = JavobOlish();
				if (String::IsNullOrEmpty(javob)) return;

				String^ status = JsonQiymat(javob, "status");

				if (status == "found") {
					// ✅ Yuz tanildi — faqat JSHSHIR raqamini ajratib olamiz
					String^ jshshir = JsonQiymat(javob, "jshshir");
					String^ conf = JsonQiymat(javob, "confidence");

					if (!String::IsNullOrEmpty(jshshir)) {
						// UI threadida SQL so'rovi va natijani ko'rsatish
						this->Invoke(gcnew Action<String^>(
							this, &Forma4::MalumotKorsatish), jshshir);
					}
				}
				else if (status == "not_found") {
					// Hali tanilmadi — davom etamiz
					this->asosiytext->Clear();
					this->asosiytext->AppendText("  Yuz izlanmoqda...\r\n");
					asosiylabel->Text = L"Kamerada bir kishining yuzi ko'rinishini ta'minlang!";
				}
				else if (status == "error") {
					String^ msg = JsonQiymat(javob, "message");
					this->asosiytext->AppendText("  Server xato: " + msg + "\r\n");
				}
			}
			catch (Exception^) {
				// Timer to'xtab qolmasligi uchun xatoni yutamiz
			}
			finally {
				delete bmp;
			}
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
			this->panelhisob = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panelqoshish = (gcnew System::Windows::Forms::Panel());
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
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panelqoshish->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rasmqoshish))->BeginInit();
			this->panelmalumot->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
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
			this->panel1->Size = System::Drawing::Size(200, 787);
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
			this->chiqish->Location = System::Drawing::Point(0, 738);
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
			this->asosiypicture->Size = System::Drawing::Size(1405, 644);
			this->asosiypicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->asosiypicture->TabIndex = 1;
			this->asosiypicture->TabStop = false;
			// 
			// asosiytext
			// 
			this->asosiytext->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->asosiytext->BackColor = System::Drawing::Color::MintCream;
			this->asosiytext->Location = System::Drawing::Point(1423, 18);
			this->asosiytext->Multiline = true;
			this->asosiytext->Name = L"asosiytext";
			this->asosiytext->ReadOnly = true;
			this->asosiytext->Size = System::Drawing::Size(378, 602);
			this->asosiytext->TabIndex = 2;
			// 
			// asosiybatafsil
			// 
			this->asosiybatafsil->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->asosiybatafsil->Cursor = System::Windows::Forms::Cursors::Hand;
			this->asosiybatafsil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->asosiybatafsil->Location = System::Drawing::Point(1516, 622);
			this->asosiybatafsil->Name = L"asosiybatafsil";
			this->asosiybatafsil->Size = System::Drawing::Size(207, 40);
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
			this->asosiylabel->Location = System::Drawing::Point(447, 665);
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
			this->panel2->Size = System::Drawing::Size(1818, 69);
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
			this->boshlabel->Location = System::Drawing::Point(827, 17);
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
			this->hisob->Location = System::Drawing::Point(1706, 3);
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
			this->panelasosiy->Controls->Add(this->asosiybatafsil);
			this->panelasosiy->Location = System::Drawing::Point(0, 72);
			this->panelasosiy->Name = L"panelasosiy";
			this->panelasosiy->Size = System::Drawing::Size(1815, 712);
			this->panelasosiy->TabIndex = 6;
			// 
			// panelhisob
			// 
			this->panelhisob->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelhisob->Controls->Add(this->button2);
			this->panelhisob->Controls->Add(this->button1);
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
			this->panelhisob->Controls->Add(this->pictureBox1);
			this->panelhisob->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->panelhisob->Location = System::Drawing::Point(203, 72);
			this->panelhisob->Name = L"panelhisob";
			this->panelhisob->Size = System::Drawing::Size(1609, 712);
			this->panelhisob->TabIndex = 5;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button2->Location = System::Drawing::Point(1029, 534);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(139, 31);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Almashtirish";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Forma4::button2_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button1->Location = System::Drawing::Point(1029, 435);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 31);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Almashtirish";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Forma4::button1_Click);
			// 
			// hisobparol2
			// 
			this->hisobparol2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hisobparol2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->hisobparol2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->hisobparol2->Location = System::Drawing::Point(745, 534);
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
			this->hisobparol1->Location = System::Drawing::Point(443, 534);
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
			this->hisoblogin2->Location = System::Drawing::Point(745, 435);
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
			this->hisoblogin1->Location = System::Drawing::Point(443, 435);
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
			this->hisobmanzil->Location = System::Drawing::Point(802, 335);
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
			this->hisobjshshir->Location = System::Drawing::Point(802, 288);
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
			this->hisobota->Location = System::Drawing::Point(802, 243);
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
			this->hisobfamilya->Location = System::Drawing::Point(802, 199);
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
			this->hisobism->Location = System::Drawing::Point(802, 157);
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
			this->label7->Location = System::Drawing::Point(438, 489);
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
			this->label6->Location = System::Drawing::Point(438, 389);
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
			this->label5->Location = System::Drawing::Point(620, 338);
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
			this->label4->Location = System::Drawing::Point(689, 291);
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
			this->label3->Location = System::Drawing::Point(643, 246);
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
			this->label2->Location = System::Drawing::Point(687, 202);
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
			this->label1->Location = System::Drawing::Point(740, 160);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Ismi:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox1->Location = System::Drawing::Point(443, 127);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(168, 224);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// panelqoshish
			// 
			this->panelqoshish->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
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
			this->panelqoshish->Size = System::Drawing::Size(1815, 712);
			this->panelqoshish->TabIndex = 4;
			// 
			// rasmtanlash
			// 
			this->rasmtanlash->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->rasmtanlash->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->rasmtanlash->Location = System::Drawing::Point(452, 374);
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
			this->rasmqoshish->Location = System::Drawing::Point(452, 149);
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
			this->qoshishsaqlash->Location = System::Drawing::Point(968, 469);
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
			this->qoshishparol2->Location = System::Drawing::Point(885, 427);
			this->qoshishparol2->Name = L"qoshishparol2";
			this->qoshishparol2->Size = System::Drawing::Size(388, 31);
			this->qoshishparol2->TabIndex = 1;
			// 
			// qoshishparol1
			// 
			this->qoshishparol1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishparol1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishparol1->Location = System::Drawing::Point(885, 390);
			this->qoshishparol1->Name = L"qoshishparol1";
			this->qoshishparol1->Size = System::Drawing::Size(388, 31);
			this->qoshishparol1->TabIndex = 1;
			// 
			// qoshishlogin
			// 
			this->qoshishlogin->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishlogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishlogin->Location = System::Drawing::Point(885, 353);
			this->qoshishlogin->Name = L"qoshishlogin";
			this->qoshishlogin->Size = System::Drawing::Size(388, 31);
			this->qoshishlogin->TabIndex = 1;
			// 
			// qoshishmanzil
			// 
			this->qoshishmanzil->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishmanzil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishmanzil->Location = System::Drawing::Point(885, 316);
			this->qoshishmanzil->Name = L"qoshishmanzil";
			this->qoshishmanzil->Size = System::Drawing::Size(388, 31);
			this->qoshishmanzil->TabIndex = 1;
			// 
			// qoshishjshshir
			// 
			this->qoshishjshshir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishjshshir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishjshshir->Location = System::Drawing::Point(885, 279);
			this->qoshishjshshir->Name = L"qoshishjshshir";
			this->qoshishjshshir->Size = System::Drawing::Size(388, 31);
			this->qoshishjshshir->TabIndex = 1;
			// 
			// qoshishota
			// 
			this->qoshishota->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishota->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishota->Location = System::Drawing::Point(885, 242);
			this->qoshishota->Name = L"qoshishota";
			this->qoshishota->Size = System::Drawing::Size(388, 31);
			this->qoshishota->TabIndex = 1;
			// 
			// qoshishfamilya
			// 
			this->qoshishfamilya->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishfamilya->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishfamilya->Location = System::Drawing::Point(885, 205);
			this->qoshishfamilya->Name = L"qoshishfamilya";
			this->qoshishfamilya->Size = System::Drawing::Size(388, 31);
			this->qoshishfamilya->TabIndex = 1;
			// 
			// qoshishism
			// 
			this->qoshishism->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->qoshishism->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qoshishism->Location = System::Drawing::Point(885, 168);
			this->qoshishism->Name = L"qoshishism";
			this->qoshishism->Size = System::Drawing::Size(388, 31);
			this->qoshishism->TabIndex = 1;
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label15->Location = System::Drawing::Point(738, 430);
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
			this->label14->Location = System::Drawing::Point(805, 393);
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
			this->label13->Location = System::Drawing::Point(802, 356);
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
			this->label12->Location = System::Drawing::Point(687, 319);
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
			this->label11->Location = System::Drawing::Point(764, 282);
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
			this->label10->Location = System::Drawing::Point(711, 245);
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
			this->label9->Location = System::Drawing::Point(778, 208);
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
			this->label8->Location = System::Drawing::Point(824, 171);
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
			this->panelmalumot->Controls->Add(this->pictureBox2);
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
			this->panelmalumot->Size = System::Drawing::Size(1815, 712);
			this->panelmalumot->TabIndex = 5;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->pictureBox2->Location = System::Drawing::Point(537, 225);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(168, 224);
			this->pictureBox2->TabIndex = 20;
			this->pictureBox2->TabStop = false;
			// 
			// checkBox1
			// 
			this->checkBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->checkBox1->Location = System::Drawing::Point(1327, 457);
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
			this->malumotparol->Location = System::Drawing::Point(933, 447);
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
			this->malumotlogin->Location = System::Drawing::Point(933, 410);
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
			this->malumotmanzil->Location = System::Drawing::Point(933, 373);
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
			this->malumotjshshir->Location = System::Drawing::Point(933, 336);
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
			this->malumotota->Location = System::Drawing::Point(933, 299);
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
			this->malumotfamilya->Location = System::Drawing::Point(933, 262);
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
			this->malumotism->Location = System::Drawing::Point(933, 225);
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
			this->label18->Location = System::Drawing::Point(853, 450);
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
			this->label19->Location = System::Drawing::Point(850, 413);
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
			this->label20->Location = System::Drawing::Point(735, 376);
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
			this->label21->Location = System::Drawing::Point(812, 339);
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
			this->label22->Location = System::Drawing::Point(759, 302);
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
			this->label23->Location = System::Drawing::Point(826, 265);
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
			this->label24->Location = System::Drawing::Point(872, 228);
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
			this->tahrir->Location = System::Drawing::Point(1208, 491);
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
			this->malumotizlash->Location = System::Drawing::Point(1208, 173);
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
			this->jshshirizlash->Location = System::Drawing::Point(682, 173);
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
			this->label16->Location = System::Drawing::Point(561, 176);
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
			this->paneltahrir->Size = System::Drawing::Size(1815, 712);
			this->paneltahrir->TabIndex = 19;
			// 
			// saqlash
			// 
			this->saqlash->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->saqlash->Cursor = System::Windows::Forms::Cursors::Hand;
			this->saqlash->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->saqlash->Location = System::Drawing::Point(1082, 440);
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
			this->rasmtanlashtaxrir->Location = System::Drawing::Point(452, 370);
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
			this->rasmtahrir->Location = System::Drawing::Point(452, 145);
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
			this->tahrirmanzil->Location = System::Drawing::Point(936, 336);
			this->tahrirmanzil->Name = L"tahrirmanzil";
			this->tahrirmanzil->Size = System::Drawing::Size(388, 31);
			this->tahrirmanzil->TabIndex = 24;
			// 
			// tahrirjshshir
			// 
			this->tahrirjshshir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tahrirjshshir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tahrirjshshir->Location = System::Drawing::Point(936, 299);
			this->tahrirjshshir->Name = L"tahrirjshshir";
			this->tahrirjshshir->Size = System::Drawing::Size(388, 31);
			this->tahrirjshshir->TabIndex = 25;
			// 
			// tahrirota
			// 
			this->tahrirota->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tahrirota->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tahrirota->Location = System::Drawing::Point(936, 262);
			this->tahrirota->Name = L"tahrirota";
			this->tahrirota->Size = System::Drawing::Size(388, 31);
			this->tahrirota->TabIndex = 26;
			// 
			// tahrirfamilya
			// 
			this->tahrirfamilya->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tahrirfamilya->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tahrirfamilya->Location = System::Drawing::Point(936, 225);
			this->tahrirfamilya->Name = L"tahrirfamilya";
			this->tahrirfamilya->Size = System::Drawing::Size(388, 31);
			this->tahrirfamilya->TabIndex = 27;
			// 
			// tahrirism
			// 
			this->tahrirism->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tahrirism->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->tahrirism->Location = System::Drawing::Point(936, 188);
			this->tahrirism->Name = L"tahrirism";
			this->tahrirism->Size = System::Drawing::Size(388, 31);
			this->tahrirism->TabIndex = 28;
			// 
			// label25
			// 
			this->label25->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.74545F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label25->Location = System::Drawing::Point(738, 339);
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
			this->label26->Location = System::Drawing::Point(815, 302);
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
			this->label27->Location = System::Drawing::Point(762, 265);
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
			this->label28->Location = System::Drawing::Point(829, 228);
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
			this->label29->Location = System::Drawing::Point(875, 191);
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
			this->ClientSize = System::Drawing::Size(1819, 787);
			this->Controls->Add(this->menu);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panelmalumot);
			this->Controls->Add(this->panelqoshish);
			this->Controls->Add(this->panelasosiy);
			this->Controls->Add(this->panelhisob);
			this->Controls->Add(this->paneltahrir);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Forma4";
			this->Text = L"e";
			this->Load += gcnew System::EventHandler(this, &Forma4::Forma4_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->asosiypicture))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panelasosiy->ResumeLayout(false);
			this->panelasosiy->PerformLayout();
			this->panelhisob->ResumeLayout(false);
			this->panelhisob->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panelqoshish->ResumeLayout(false);
			this->panelqoshish->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rasmqoshish))->EndInit();
			this->panelmalumot->ResumeLayout(false);
			this->panelmalumot->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->paneltahrir->ResumeLayout(false);
			this->paneltahrir->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rasmtahrir))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Forma4_Load(System::Object^ sender, System::EventArgs^ e) {
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

		// ── Kamera ishga tushirish (mavjud kod) ──
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

		// ── YANGI: Python serverga ulanish va timerni boshlash ──
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
			m_timer->Interval = 3000;  // 3 soniya
			m_timer->Tick += gcnew System::EventHandler(this, &Forma4::TimerTick);
		}
		m_tanishAktiv = true;
		m_timer->Start();
	}
	private: System::Void chiqish_Click(System::Object^ sender, System::EventArgs^ e) {
		// Timer va socketni to'xtatish
		if (m_timer != nullptr && m_timer->Enabled) m_timer->Stop();
		m_tanishAktiv = false;
		SocketYop();

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
			rasmqoshish->Image = Image::FromFile(open->FileName);
		}
	}
	private: System::Void qoshish_Click(System::Object^ sender, System::EventArgs^ e) {
		menu->Size = System::Drawing::Size(48, 48);
		menu->Text = "";
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
			rasmtahrir->Image = Image::FromFile(open->FileName);
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
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		hisoblogin1->Text = L"	Joriy login";
		hisoblogin1->ForeColor = System::Drawing::Color::Gray;
		hisoblogin2->Text = L"	Yangi login";
		hisoblogin2->ForeColor = System::Drawing::Color::Gray;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		hisobparol1->Text = L"	Joriy parol";
		hisobparol1->ForeColor = System::Drawing::Color::Gray;
		hisobparol2->Text = L"	Yangi parol";
		hisobparol2->ForeColor = System::Drawing::Color::Gray;
	}
	private: System::Void saqlash_Click(System::Object^ sender, System::EventArgs^ e) {
		tahrirism->Clear();
		tahrirfamilya->Clear();
		tahrirota->Clear();
		tahrirmanzil->Clear();
		tahrirjshshir->Clear();
	}
	private: System::Void qoshishsaqlash_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			SqlConnection^ ulanish = gcnew SqlConnection(connString);
			ulanish->Open();
			String^ query = "INSERT INTO hisob (login, parol, ism, otasining_ismi, familiya, jshshir, manzil) " +
				"VALUES (@login, @parol, @ism, @otasining_ismi, @fam, @jsh, @manzil)";

			SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
			buyruq->Parameters->AddWithValue("@login", qoshishlogin->Text);
			buyruq->Parameters->AddWithValue("@parol", qoshishparol1->Text);
			buyruq->Parameters->AddWithValue("@ism", qoshishism->Text);
			buyruq->Parameters->AddWithValue("@otasining_ismi", qoshishota->Text);
			buyruq->Parameters->AddWithValue("@fam", qoshishfamilya->Text);
			buyruq->Parameters->AddWithValue("@jsh", qoshishjshshir->Text);
			buyruq->Parameters->AddWithValue("@manzil", qoshishmanzil->Text);

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
	private: System::Void malumotizlash_Click(System::Object^ sender, System::EventArgs^ e) {
		if (jshshirizlash->Text->Trim() == "") {
			MessageBox::Show("Iltimos, izlash uchun JShShIR raqamini kiriting!", "Ogohlantirish", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		String^ connString = "Server=.\\SQLEXPRESS; Database=shaxsiy; Trusted_Connection=True; TrustServerCertificate=True;";
		SqlConnection^ ulanish = gcnew SqlConnection(connString);

		String^ query = "SELECT login, ism, familiya, otasining_ismi, manzil FROM hisob WHERE jshshir = @jsh";

		SqlCommand^ buyruq = gcnew SqlCommand(query, ulanish);
		buyruq->Parameters->AddWithValue("@jsh", jshshirizlash->Text->Trim());

		try {
			ulanish->Open();
			SqlDataReader^ oquvchi = buyruq->ExecuteReader();
			if (oquvchi->Read()) {
				malumotlogin->Text = oquvchi["login"]->ToString();
				malumotparol->Text = oquvchi["parol"]->ToString();
				malumotism->Text = oquvchi["ism"]->ToString();
				malumotfamilya->Text = oquvchi["familiya"]->ToString();
				malumotjshshir->Text = oquvchi["jshshir"]->ToString();
				malumotota->Text = oquvchi["otasining_ismi"]->ToString();
				malumotmanzil->Text = oquvchi["manzil"]->ToString();
				MessageBox::Show("Ma'lumotlar topildi!", "Muvaffaqiyat", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
	private: System::Void asosiybatafsil_Click(System::Object^ sender, System::EventArgs^ e) {
		// Qayta izlashni boshlash
		this->asosiytext->Clear();
		this->asosiytext->AppendText("🔍 Qayta izlanmoqda...\r\n");
		asosiylabel->Text = "Kamerada bir kishining yuzi ko'rinishini ta'minlang!";
		m_tanishAktiv = true;
		if (m_timer != nullptr) m_timer->Start();
	}
	};
}