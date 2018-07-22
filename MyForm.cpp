#include "MyForm.h"
#include "windows.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	Histogram::MyForm form;
	Application::Run(%form);
}
