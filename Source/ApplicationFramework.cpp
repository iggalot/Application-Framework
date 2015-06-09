// Git test
// ApplicationFramework.cpp : main project file.
#include "stdafx.h"
#include "../Headers/Main.h"							// Include our main header for the application..includes the necessary includes for the application

using namespace System;


int main(array<System::String ^> ^args)
{
	Application application;
    //Console::WriteLine(L"Hello World");			// alternate technique to write to the console
    return application.Main();						// Launches into the main application routine
}
