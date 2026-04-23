#pragma once


namespace shaxsiy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelmain;
	private: System::Windows::Forms::Button^ btnprogramming;
	private: System::Windows::Forms::Panel^ panellogomenu;
	private: System::Windows::Forms::Panel^ panelprogrammsubmenu;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ paneldeutschsubmenu;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ btndeutsch;
	private: System::Windows::Forms::Panel^ panelmathsubmenu;
	private: System::Windows::Forms::Button^ btntheory;
	private: System::Windows::Forms::Button^ btncalcul;
	private: System::Windows::Forms::Button^ btngraph;
	private: System::Windows::Forms::Button^ btnmath;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::ColorDialog^ colorDialog2;
	private: System::Windows::Forms::Button^ btnuserinfo;
	private: System::Windows::Forms::Label^ lblUserinfo;
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
			this->panelmain = (gcnew System::Windows::Forms::Panel());
			this->btnuserinfo = (gcnew System::Windows::Forms::Button());
			this->paneldeutschsubmenu = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->btndeutsch = (gcnew System::Windows::Forms::Button());
			this->panelmathsubmenu = (gcnew System::Windows::Forms::Panel());
			this->btntheory = (gcnew System::Windows::Forms::Button());
			this->btncalcul = (gcnew System::Windows::Forms::Button());
			this->btngraph = (gcnew System::Windows::Forms::Button());
			this->btnmath = (gcnew System::Windows::Forms::Button());
			this->panelprogrammsubmenu = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnprogramming = (gcnew System::Windows::Forms::Button());
			this->panellogomenu = (gcnew System::Windows::Forms::Panel());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->colorDialog2 = (gcnew System::Windows::Forms::ColorDialog());
			this->lblUserinfo = (gcnew System::Windows::Forms::Label());
			this->panelmain->SuspendLayout();
			this->paneldeutschsubmenu->SuspendLayout();
			this->panelmathsubmenu->SuspendLayout();
			this->panelprogrammsubmenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelmain
			// 
			this->panelmain->AutoScroll = true;
			this->panelmain->BackColor = System::Drawing::SystemColors::Desktop;
			this->panelmain->Controls->Add(this->btnuserinfo);
			this->panelmain->Controls->Add(this->paneldeutschsubmenu);
			this->panelmain->Controls->Add(this->btndeutsch);
			this->panelmain->Controls->Add(this->panelmathsubmenu);
			this->panelmain->Controls->Add(this->btnmath);
			this->panelmain->Controls->Add(this->panelprogrammsubmenu);
			this->panelmain->Controls->Add(this->btnprogramming);
			this->panelmain->Controls->Add(this->panellogomenu);
			this->panelmain->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelmain->Location = System::Drawing::Point(0, 0);
			this->panelmain->Name = L"panelmain";
			this->panelmain->Size = System::Drawing::Size(253, 636);
			this->panelmain->TabIndex = 0;
			this->panelmain->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panelsidemenu_Paint);
			// 
			// btnuserinfo
			// 
			this->btnuserinfo->BackColor = System::Drawing::SystemColors::ControlDark;
			this->btnuserinfo->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->btnuserinfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnuserinfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnuserinfo->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnuserinfo->Location = System::Drawing::Point(0, 613);
			this->btnuserinfo->Name = L"btnuserinfo";
			this->btnuserinfo->Size = System::Drawing::Size(253, 23);
			this->btnuserinfo->TabIndex = 7;
			this->btnuserinfo->Text = L"UserInfo";
			this->btnuserinfo->UseVisualStyleBackColor = false;
			this->btnuserinfo->Click += gcnew System::EventHandler(this, &MainForm::btnuserinfo_Click);
			// 
			// paneldeutschsubmenu
			// 
			this->paneldeutschsubmenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->paneldeutschsubmenu->Controls->Add(this->button1);
			this->paneldeutschsubmenu->Controls->Add(this->button6);
			this->paneldeutschsubmenu->Controls->Add(this->button7);
			this->paneldeutschsubmenu->Dock = System::Windows::Forms::DockStyle::Top;
			this->paneldeutschsubmenu->Location = System::Drawing::Point(0, 479);
			this->paneldeutschsubmenu->Name = L"paneldeutschsubmenu";
			this->paneldeutschsubmenu->Size = System::Drawing::Size(253, 118);
			this->paneldeutschsubmenu->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Gainsboro;
			this->button1->Location = System::Drawing::Point(0, 80);
			this->button1->Name = L"button1";
			this->button1->Padding = System::Windows::Forms::Padding(35, 0, 0, 0);
			this->button1->Size = System::Drawing::Size(253, 40);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Theory";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Dock = System::Windows::Forms::DockStyle::Top;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->ForeColor = System::Drawing::Color::Gainsboro;
			this->button6->Location = System::Drawing::Point(0, 40);
			this->button6->Name = L"button6";
			this->button6->Padding = System::Windows::Forms::Padding(35, 0, 0, 0);
			this->button6->Size = System::Drawing::Size(253, 40);
			this->button6->TabIndex = 1;
			this->button6->Text = L"Claculator";
			this->button6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Dock = System::Windows::Forms::DockStyle::Top;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->ForeColor = System::Drawing::Color::Gainsboro;
			this->button7->Location = System::Drawing::Point(0, 0);
			this->button7->Name = L"button7";
			this->button7->Padding = System::Windows::Forms::Padding(35, 0, 0, 0);
			this->button7->Size = System::Drawing::Size(253, 40);
			this->button7->TabIndex = 0;
			this->button7->Text = L"Graphics";
			this->button7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->UseVisualStyleBackColor = true;
			// 
			// btndeutsch
			// 
			this->btndeutsch->Dock = System::Windows::Forms::DockStyle::Top;
			this->btndeutsch->FlatAppearance->BorderSize = 0;
			this->btndeutsch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btndeutsch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btndeutsch->ForeColor = System::Drawing::Color::Gainsboro;
			this->btndeutsch->Location = System::Drawing::Point(0, 434);
			this->btndeutsch->Name = L"btndeutsch";
			this->btndeutsch->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btndeutsch->Size = System::Drawing::Size(253, 45);
			this->btndeutsch->TabIndex = 5;
			this->btndeutsch->Text = L"Deutsch";
			this->btndeutsch->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btndeutsch->UseVisualStyleBackColor = true;
			this->btndeutsch->Click += gcnew System::EventHandler(this, &MainForm::btndeutsch_Click);
			// 
			// panelmathsubmenu
			// 
			this->panelmathsubmenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panelmathsubmenu->Controls->Add(this->btntheory);
			this->panelmathsubmenu->Controls->Add(this->btncalcul);
			this->panelmathsubmenu->Controls->Add(this->btngraph);
			this->panelmathsubmenu->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelmathsubmenu->Location = System::Drawing::Point(0, 293);
			this->panelmathsubmenu->Name = L"panelmathsubmenu";
			this->panelmathsubmenu->Size = System::Drawing::Size(253, 141);
			this->panelmathsubmenu->TabIndex = 4;
			// 
			// btntheory
			// 
			this->btntheory->Dock = System::Windows::Forms::DockStyle::Top;
			this->btntheory->FlatAppearance->BorderSize = 0;
			this->btntheory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btntheory->ForeColor = System::Drawing::Color::Gainsboro;
			this->btntheory->Location = System::Drawing::Point(0, 80);
			this->btntheory->Name = L"btntheory";
			this->btntheory->Padding = System::Windows::Forms::Padding(35, 0, 0, 0);
			this->btntheory->Size = System::Drawing::Size(253, 40);
			this->btntheory->TabIndex = 2;
			this->btntheory->Text = L"Theory";
			this->btntheory->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btntheory->UseVisualStyleBackColor = true;
			// 
			// btncalcul
			// 
			this->btncalcul->Dock = System::Windows::Forms::DockStyle::Top;
			this->btncalcul->FlatAppearance->BorderSize = 0;
			this->btncalcul->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btncalcul->ForeColor = System::Drawing::Color::Gainsboro;
			this->btncalcul->Location = System::Drawing::Point(0, 40);
			this->btncalcul->Name = L"btncalcul";
			this->btncalcul->Padding = System::Windows::Forms::Padding(35, 0, 0, 0);
			this->btncalcul->Size = System::Drawing::Size(253, 40);
			this->btncalcul->TabIndex = 1;
			this->btncalcul->Text = L"Claculator";
			this->btncalcul->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btncalcul->UseVisualStyleBackColor = true;
			// 
			// btngraph
			// 
			this->btngraph->Dock = System::Windows::Forms::DockStyle::Top;
			this->btngraph->FlatAppearance->BorderSize = 0;
			this->btngraph->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btngraph->ForeColor = System::Drawing::Color::Gainsboro;
			this->btngraph->Location = System::Drawing::Point(0, 0);
			this->btngraph->Name = L"btngraph";
			this->btngraph->Padding = System::Windows::Forms::Padding(35, 0, 0, 0);
			this->btngraph->Size = System::Drawing::Size(253, 40);
			this->btngraph->TabIndex = 0;
			this->btngraph->Text = L"Graphics";
			this->btngraph->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btngraph->UseVisualStyleBackColor = true;
			// 
			// btnmath
			// 
			this->btnmath->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnmath->FlatAppearance->BorderSize = 0;
			this->btnmath->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnmath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnmath->ForeColor = System::Drawing::Color::Gainsboro;
			this->btnmath->Location = System::Drawing::Point(0, 248);
			this->btnmath->Name = L"btnmath";
			this->btnmath->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnmath->Size = System::Drawing::Size(253, 45);
			this->btnmath->TabIndex = 3;
			this->btnmath->Text = L"Math";
			this->btnmath->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnmath->UseVisualStyleBackColor = true;
			this->btnmath->Click += gcnew System::EventHandler(this, &MainForm::btnmath_Click);
			// 
			// panelprogrammsubmenu
			// 
			this->panelprogrammsubmenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panelprogrammsubmenu->Controls->Add(this->button5);
			this->panelprogrammsubmenu->Controls->Add(this->button4);
			this->panelprogrammsubmenu->Controls->Add(this->button3);
			this->panelprogrammsubmenu->Controls->Add(this->button2);
			this->panelprogrammsubmenu->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelprogrammsubmenu->Location = System::Drawing::Point(0, 90);
			this->panelprogrammsubmenu->Name = L"panelprogrammsubmenu";
			this->panelprogrammsubmenu->Size = System::Drawing::Size(253, 158);
			this->panelprogrammsubmenu->TabIndex = 2;
			// 
			// button5
			// 
			this->button5->Dock = System::Windows::Forms::DockStyle::Top;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->ForeColor = System::Drawing::Color::LightGray;
			this->button5->Location = System::Drawing::Point(0, 120);
			this->button5->Name = L"button5";
			this->button5->Padding = System::Windows::Forms::Padding(35, 0, 0, 0);
			this->button5->Size = System::Drawing::Size(253, 34);
			this->button5->TabIndex = 3;
			this->button5->Text = L"button5";
			this->button5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// button4
			// 
			this->button4->Dock = System::Windows::Forms::DockStyle::Top;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->ForeColor = System::Drawing::Color::Gainsboro;
			this->button4->Location = System::Drawing::Point(0, 80);
			this->button4->Name = L"button4";
			this->button4->Padding = System::Windows::Forms::Padding(35, 0, 0, 0);
			this->button4->Size = System::Drawing::Size(253, 40);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Testlar";
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Dock = System::Windows::Forms::DockStyle::Top;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::Color::Gainsboro;
			this->button3->Location = System::Drawing::Point(0, 40);
			this->button3->Name = L"button3";
			this->button3->Padding = System::Windows::Forms::Padding(35, 0, 0, 0);
			this->button3->Size = System::Drawing::Size(253, 40);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Dastur kodlari";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Dock = System::Windows::Forms::DockStyle::Top;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::Color::Gainsboro;
			this->button2->Location = System::Drawing::Point(0, 0);
			this->button2->Name = L"button2";
			this->button2->Padding = System::Windows::Forms::Padding(35, 0, 0, 0);
			this->button2->Size = System::Drawing::Size(253, 40);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Mavzular";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// btnprogramming
			// 
			this->btnprogramming->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnprogramming->FlatAppearance->BorderSize = 0;
			this->btnprogramming->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnprogramming->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnprogramming->ForeColor = System::Drawing::Color::Gainsboro;
			this->btnprogramming->Location = System::Drawing::Point(0, 45);
			this->btnprogramming->Name = L"btnprogramming";
			this->btnprogramming->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnprogramming->Size = System::Drawing::Size(253, 45);
			this->btnprogramming->TabIndex = 1;
			this->btnprogramming->Text = L"Programming";
			this->btnprogramming->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnprogramming->UseVisualStyleBackColor = true;
			this->btnprogramming->Click += gcnew System::EventHandler(this, &MainForm::btnprogramming_Click);
			// 
			// panellogomenu
			// 
			this->panellogomenu->Dock = System::Windows::Forms::DockStyle::Top;
			this->panellogomenu->Location = System::Drawing::Point(0, 0);
			this->panellogomenu->Name = L"panellogomenu";
			this->panellogomenu->Size = System::Drawing::Size(253, 45);
			this->panellogomenu->TabIndex = 0;
			// 
			// lblUserinfo
			// 
			this->lblUserinfo->AutoSize = true;
			this->lblUserinfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblUserinfo->Location = System::Drawing::Point(431, 170);
			this->lblUserinfo->Name = L"lblUserinfo";
			this->lblUserinfo->Size = System::Drawing::Size(98, 32);
			this->lblUserinfo->TabIndex = 1;
			this->lblUserinfo->Text = L"label1";
			this->lblUserinfo->Visible = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1004, 636);
			this->Controls->Add(this->lblUserinfo);
			this->Controls->Add(this->panelmain);
			this->MinimumSize = System::Drawing::Size(950, 600);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->panelmain->ResumeLayout(false);
			this->paneldeutschsubmenu->ResumeLayout(false);
			this->panelmathsubmenu->ResumeLayout(false);
			this->panelprogrammsubmenu->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panelsidemenu_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void CustomizeDesign() {
		   paneldeutschsubmenu->Visible = false;
		   panelmathsubmenu->Visible = false;
		   panelprogrammsubmenu->Visible = false;
		
	   }
private: System:: Void hideSubMenu() {
		   if (paneldeutschsubmenu->Visible == true)
			   paneldeutschsubmenu->Visible = false;
		   if (panelmathsubmenu->Visible == true)
			   panelmathsubmenu->Visible = false;
		   if (panelprogrammsubmenu->Visible == true)
			   panelprogrammsubmenu->Visible = false;
}

	private: System::Void showSubMenu(Panel^ subMenu) {
		if (subMenu->Visible == false) {
			hideSubMenu();
			subMenu->Visible = true;
		}
		else
			subMenu->Visible = false;
	}	

private: System::Void btnprogramming_Click(System::Object^ sender, System::EventArgs^ e) {
	lblUserinfo->Visible = false;
		showSubMenu(panelprogrammsubmenu);
}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//My code
	
	hideSubMenu();

}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//My code
	
	hideSubMenu();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	//My code
	
	hideSubMenu();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	//My code
	hideSubMenu();
}
private: System::Void btnmath_Click(System::Object^ sender, System::EventArgs^ e) {
	showSubMenu(panelmathsubmenu);
	lblUserinfo->Visible = false;
}
private: System::Void btndeutsch_Click(System::Object^ sender, System::EventArgs^ e) {
	showSubMenu(paneldeutschsubmenu);
	lblUserinfo->Visible = false;
}
private: System::Void btnuserinfo_Click(System::Object^ sender, System::EventArgs^ e) {
	// User^ user; lblUserinfo->Text = "ID: " + user->id + "\nName: " + user->name + "\nEmail: " + user->email + "\nPhone: " +user->phone + "\nAddress: " + user->address;
}
};
}
