#pragma once
#include<iostream>
#include<Windows.h>
#include<math.h>
#include<atlstr.h>
#include"imge.h"

namespace Histogram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::ToolStripMenuItem^  showIntensityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showPictureToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  consulationToolStripMenuItem;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		BYTE * Buffer;
		long Size;
		int Width;
		int Height;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  histogramToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::ToolStripMenuItem^  historizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  thresholdingToolStripMenuItem;





			 /// </summary>
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
				 System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
				 System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->showIntensityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->showPictureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->histogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->historizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->thresholdingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->consulationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
				 this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
				 this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
				 this->menuStrip1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
					 this->fileToolStripMenuItem,
						 this->processToolStripMenuItem, this->consulationToolStripMenuItem
				 });
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(1143, 24);
				 this->menuStrip1->TabIndex = 0;
				 this->menuStrip1->Text = L"menuStrip1";
				 this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
				 // 
				 // fileToolStripMenuItem
				 // 
				 this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
					 this->openToolStripMenuItem,
						 this->showIntensityToolStripMenuItem, this->showPictureToolStripMenuItem
				 });
				 this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
				 this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
				 this->fileToolStripMenuItem->Text = L"file";
				 this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fileToolStripMenuItem_Click);
				 // 
				 // openToolStripMenuItem
				 // 
				 this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
				 this->openToolStripMenuItem->Size = System::Drawing::Size(148, 22);
				 this->openToolStripMenuItem->Text = L"open";
				 this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
				 // 
				 // showIntensityToolStripMenuItem
				 // 
				 this->showIntensityToolStripMenuItem->Name = L"showIntensityToolStripMenuItem";
				 this->showIntensityToolStripMenuItem->Size = System::Drawing::Size(148, 22);
				 this->showIntensityToolStripMenuItem->Text = L"ShowIntensity";
				 this->showIntensityToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showIntensityToolStripMenuItem_Click);
				 // 
				 // showPictureToolStripMenuItem
				 // 
				 this->showPictureToolStripMenuItem->Name = L"showPictureToolStripMenuItem";
				 this->showPictureToolStripMenuItem->Size = System::Drawing::Size(148, 22);
				 this->showPictureToolStripMenuItem->Text = L"ShowPicture";
				 // 
				 // processToolStripMenuItem
				 // 
				 this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
					 this->histogramToolStripMenuItem,
						 this->historizeToolStripMenuItem, this->thresholdingToolStripMenuItem
				 });
				 this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
				 this->processToolStripMenuItem->Size = System::Drawing::Size(59, 20);
				 this->processToolStripMenuItem->Text = L"process";
				 // 
				 // histogramToolStripMenuItem
				 // 
				 this->histogramToolStripMenuItem->Name = L"histogramToolStripMenuItem";
				 this->histogramToolStripMenuItem->Size = System::Drawing::Size(180, 22);
				 this->histogramToolStripMenuItem->Text = L"Histogram";
				 this->histogramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::histogramToolStripMenuItem_Click);
				 // 
				 // historizeToolStripMenuItem
				 // 
				 this->historizeToolStripMenuItem->Name = L"historizeToolStripMenuItem";
				 this->historizeToolStripMenuItem->Size = System::Drawing::Size(180, 22);
				 this->historizeToolStripMenuItem->Text = L"historize";
				 this->historizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::historizeToolStripMenuItem_Click_1);
				 // 
				 // thresholdingToolStripMenuItem
				 // 
				 this->thresholdingToolStripMenuItem->Name = L"thresholdingToolStripMenuItem";
				 this->thresholdingToolStripMenuItem->Size = System::Drawing::Size(180, 22);
				 this->thresholdingToolStripMenuItem->Text = L"Thresholding";
				 this->thresholdingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::thresholdingToolStripMenuItem_Click);
				 // 
				 // consulationToolStripMenuItem
				 // 
				 this->consulationToolStripMenuItem->Name = L"consulationToolStripMenuItem";
				 this->consulationToolStripMenuItem->Size = System::Drawing::Size(81, 20);
				 this->consulationToolStripMenuItem->Text = L"consulation";
				 this->consulationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::consulationToolStripMenuItem_Click);
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Location = System::Drawing::Point(12, 55);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(341, 317);
				 this->pictureBox1->TabIndex = 1;
				 this->pictureBox1->TabStop = false;
				 this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
				 // 
				 // pictureBox2
				 // 
				 this->pictureBox2->Location = System::Drawing::Point(359, 55);
				 this->pictureBox2->Name = L"pictureBox2";
				 this->pictureBox2->Size = System::Drawing::Size(405, 320);
				 this->pictureBox2->TabIndex = 2;
				 this->pictureBox2->TabStop = false;
				 // 
				 // chart1
				 // 
				 chartArea1->Name = L"ChartArea1";
				 this->chart1->ChartAreas->Add(chartArea1);
				 legend1->Name = L"Legend1";
				 this->chart1->Legends->Add(legend1);
				 this->chart1->Location = System::Drawing::Point(777, 52);
				 this->chart1->Name = L"chart1";
				 series1->ChartArea = L"ChartArea1";
				 series1->Legend = L"Legend1";
				 series1->Name = L"Series1";
				 this->chart1->Series->Add(series1);
				 this->chart1->Size = System::Drawing::Size(354, 320);
				 this->chart1->TabIndex = 3;
				 this->chart1->Text = L"chart1";
				 this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1143, 496);
				 this->Controls->Add(this->chart1);
				 this->Controls->Add(this->pictureBox2);
				 this->Controls->Add(this->pictureBox1);
				 this->Controls->Add(this->menuStrip1);
				 this->MainMenuStrip = this->menuStrip1;
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		LPCTSTR input;
		CString  str;
		//delete[] Buffer;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//pictureBox1->ImageLocation = openFileDialog1->FileName;
			str = openFileDialog1->FileName;
			input = (LPCTSTR)str;
			Buffer = LoadBMP(Width, Height, Size, input);

			pictureBox1->Width = Width;
			pictureBox1->Height = Height;

	
			this->pictureBox1->ImageLocation = openFileDialog1->FileName;

		}

	}



private: System::Void fileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void showIntensityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		BYTE* intensity = ConvertBMPToIntensity(Buffer, Width, Height);
		Bitmap^ surface = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
		Color c;
		int temp;
		for (int row = 0; row < Height; row++) {
			for (int column = 0; column < Width; column++) {
				temp = row * Width + column;
			    c=Color::FromArgb(intensity[temp], intensity[temp], intensity[temp]);
				surface->SetPixel(column, row, c);
			}
			pictureBox2->Image = surface;
		}
	}	

private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {}
private: System::Void histogramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


	BYTE* intensity = ConvertBMPToIntensity(Buffer, Width, Height);
	int* histogram = HistogramFunc(intensity, Width, Height);
	for (int i = 0; i < 256; i++)
	{
		this->chart1->Series["Series1"]->Points->AddXY(i, histogram[i]);
	}
	this->chart1->Visible = true;
}

private: System::Void historizeToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e) {

	BYTE* intensity = ConvertBMPToIntensity(Buffer, Width, Height);
	BYTE* buffer= historize(intensity, Width, Height);

	Bitmap^ surface = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
	Color c;
	int temp;
	for (int row = 0; row < Height; row++) {
		for (int column = 0; column < Width; column++) {
			temp = row * Width + column;
			c = Color::FromArgb(buffer[temp], buffer[temp], buffer
				[temp]);
			surface->SetPixel(column, row, c);
		}
		pictureBox2->Image = surface;
	}

}

private: System::Void thresholdingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	BYTE* intensity = ConvertBMPToIntensity(Buffer, Width, Height);
	BYTE* buff = thresholding(intensity, Width, Height);

	Bitmap^ surface = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
	Color c;
	int temp;
	for (int row = 0; row < Height; row++) {
		for (int column = 0; column < Width; column++) {
			temp = row * Width + column;
			c = Color::FromArgb(buff[temp], buff[temp], buff[temp]);
			surface->SetPixel(column, row, c);
		}
		pictureBox2->Image = surface;
	}
}


private: System::Void noiseFilterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}


private: System::Void consulationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}