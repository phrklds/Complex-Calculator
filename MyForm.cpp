#include "MyForm.h"
#include <string>
#include <iostream>
#include <locale>
#include <ctype.h>
#include <vector>
#include <deque>
#include <stdlib.h>

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void Main(array<String^>^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ComplexCalc::MyForm form;
	Application::Run(%form);
}
