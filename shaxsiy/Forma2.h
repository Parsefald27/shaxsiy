#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace AForge::Video;
using namespace AForge::Video::DirectShow;

namespace shaxsiy {

	/// <summary>
	/// Summary for Forma2
	/// </summary>
	public ref class Forma2 : public System::Windows::Forms::Form
	{
	public:;
		  Form^ Forma4;
		Forma2(Form^forma4)
		{
			Forma4=forma4;
          InitializeComponent();
			// Load image at runtime (do not call Application::StartupPath from InitializeComponent - designer breaks)
			{
				System::String^ imgPath = System::IO::Path::Combine(Application::StartupPath, "kamera.png");
				if (System::IO::File::Exists(imgPath)) {
					this->pictureBox1->Image = System::Drawing::Image::FromFile(imgPath);
				}
			}
          // Initialize AForge video capture
			try {
				videoDevices = gcnew FilterInfoCollection(FilterCategory::VideoInputDevice);
				if (videoDevices != nullptr && videoDevices->Count > 0) {
					videoSource = gcnew VideoCaptureDevice(videoDevices[0]->MonikerString);
					videoSource->NewFrame += gcnew NewFrameEventHandler(this, &Forma2::video_NewFrame);
					videoSource->Start();
				} else {
					MessageBox::Show("Video kamera topilmadi", "kamera", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message, "kamera xatosi", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Forma2()
		{
     // stop and clean up video source
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
			// ignore
		}
		if (components)
		{
			delete components;
		}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::PictureBox^ pictureBox1;


	// AForge video members
	private: FilterInfoCollection^ videoDevices;
	private: VideoCaptureDevice^ videoSource;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Button^ kirish;
	private: System::Windows::Forms::Button^ qaytish;





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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->qaytish = (gcnew System::Windows::Forms::Button());
			this->kirish = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1006, 544);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::Color::Black;
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel2->Controls->Add(this->textBox1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(506, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 83.27138F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.72862F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(497, 538);
			this->tableLayoutPanel2->TabIndex = 0;
			this->tableLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Forma2::tableLayoutPanel2_Paint);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::InfoText;
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.78182F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::Window;
			this->textBox1->Location = System::Drawing::Point(3, 3);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(491, 442);
			this->textBox1->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->qaytish, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->kirish, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 451);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(491, 84);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// qaytish
			// 
			this->qaytish->BackColor = System::Drawing::Color::Black;
			this->qaytish->Dock = System::Windows::Forms::DockStyle::Fill;
			this->qaytish->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->qaytish->ForeColor = System::Drawing::SystemColors::Control;
			this->qaytish->Location = System::Drawing::Point(248, 3);
			this->qaytish->Name = L"qaytish";
			this->qaytish->Size = System::Drawing::Size(240, 78);
			this->qaytish->TabIndex = 1;
			this->qaytish->Text = L"Ortga";
			this->qaytish->UseVisualStyleBackColor = false;
			this->qaytish->Click += gcnew System::EventHandler(this, &Forma2::qaytish_Click);
			// 
			// kirish
			// 
			this->kirish->BackColor = System::Drawing::Color::Black;
			this->kirish->Dock = System::Windows::Forms::DockStyle::Fill;
			this->kirish->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.70909F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->kirish->ForeColor = System::Drawing::SystemColors::Control;
			this->kirish->Location = System::Drawing::Point(3, 3);
			this->kirish->Name = L"kirish";
			this->kirish->Size = System::Drawing::Size(239, 78);
			this->kirish->TabIndex = 0;
			this->kirish->Text = L"Kirish";
			this->kirish->UseVisualStyleBackColor = false;
			this->kirish->Click += gcnew System::EventHandler(this, &Forma2::kirish_Click_1);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(497, 538);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Forma2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1006, 544);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Forma2";
			this->Text = L"Forma2";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	// AForge frame handler and helper
	private: void video_NewFrame(System::Object^ sender, NewFrameEventArgs^ eventArgs)
	{
		// Clone the frame and dispatch to UI thread
		System::Drawing::Bitmap^ frame = safe_cast<System::Drawing::Bitmap^>(eventArgs->Frame->Clone());
		if (this->pictureBox1->InvokeRequired) {
			this->pictureBox1->BeginInvoke(gcnew System::Action<System::Drawing::Bitmap^>(this, &Forma2::SetNewImage), frame);
		} else {
			SetNewImage(frame);
		}
	}

	private: void SetNewImage(System::Drawing::Bitmap^ bmp)
	{
		// Dispose previous image to avoid memory leak
		if (this->pictureBox1->Image != nullptr) {
			try { delete this->pictureBox1->Image; } catch(...) {}
		}
		this->pictureBox1->Image = bmp;
	}
	
	private: System::Void tableLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

private: System::Void kirish_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void qaytish_Click(System::Object^ sender, System::EventArgs^ e) {
	Forma4->Show();
	this->Hide();
}
};
}
