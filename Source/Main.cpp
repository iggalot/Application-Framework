#include "stdafx.h"
#include <iostream>
#include <string.h>

#include "../Headers/Model.h"							// Include our model header for the application
#include "../Headers/Main.h"							// Include our main header for the application

using namespace std;
class AppWindow;			// forward declaration
class Mesh;				// forward declaration
class Model;			// forward declaration
class Volume;			// forward declaration

char str[80];			// an array to hold small text strings (like titles of windows)

// A constructor for the Application.
Application::Application(void)
{
	NumMesh = 0;		// at startup, the application does not contain a model.
	for (int i=0; i<MAX_WINDOWS; i++)
	{
//		SetWindowPos(i,0,0);	// Sets the initial coordinates of the window
	}
}	


// This is our own main() function which abstracts the required main() function to run this application.
int Application::Main()
{
	printf("\nCalling into GLMain()...starting main loop");
	// This calls our Initialize() function below which creates the window and triangle
	Initialize();

	// This is our main game loop which will run until we close the application 
	AppLoop();

	getchar();
	// Once we hit Escape this will clean up the application's resources.
//	Destroy();

	printf("\nEnding Program");
	getchar();
	return 0;
}

// This function initializes the window, the shaders and the triangle vertex data.
void Application::Initialize()
{
	printf("\nInitializing Application");

	// Make sure the window manager is initialized prior to calling this and creates the OpenGL context
//	if ( !WindowManager || WindowManager->Initialize(ScreenWidth, ScreenHeight, "I Beam Sketcher - GameTutorials - Matrices", false) != 0 )
//	{
		// Quit the application if the window couldn't be created with an OpenGL context
//		exit(-1);
//	}

	// Creating the application windows
	AppWindow *MyWin[MAX_WINDOWS];

	//Create the primary model window
	sprintf_s(str,"\nMain Model Window #%d", 1);
	MyWin[0] = new AppWindow;
	MyWin[0]->Initialize(600,500, str, NULL, 200, 125);
	SetWindowID(0, MyWin[0]);

	//Create the subwindow viewports
	if(MAX_WINDOWS > 1)
	{
		for (int i=1;i<MAX_WINDOWS;i++)
		{
			sprintf_s(str, "\nTest Window #%d",i);
			MyWin[i] = new AppWindow;
			MyWin[i]->Initialize(300,250, str, NULL, 800, 125+(i-1
				)*250);
			SetWindowID(i, MyWin[i]);		
//			MyWin[i]->RenderMesh(GetWindowID(i)->GetWindow(), float(1.0-(float (i)/ float (MAX_WINDOWS))));
//			cout << "*MyWin[" << i << "]:" << *MyWin[i] << endl;
//			cout << "MyWin[" << i << "]:" << MyWin[i] << endl;
		}
	}

	Model *MyModel;			// creates an array to store the model
	MyModel = new Model;
	MyModel->Initialize();

	MyModel->RenderModel(MyWin);	// renders the model



	// Creating and testing Mesh ID storage structures in Application.h
//	Mesh *MyMesh[MAX_MESH_QTY];
//	for (int i=0;i<5;i++)
//	{
//		MyMesh[i] = new Mesh;
//		SetMeshID(i, MyMesh[i]);
//		cout << "SetMeshID(i) = " << i << endl;
//	}
//	cout << "===================================" << endl;
//	cout << "Model size: " << Model.size() << endl;
//	for (int i=0;i<5;i++)
//	{

		//GetMeshID(i);
//		cout << "GetMeshID(i) = " << Model[i] << endl;
//	}


/*	Mesh *Model[MAX_MESH_QTY];
	for (int i=0;i<MAX_MESH_QTY;i++)
	{
		printf("\nCreating Meshes...");
		Model[i] = new Mesh;

	}
*/

	// Creating a general RENDER routine for the application that will render all of the windows owned by the application
	RenderApplication(MyWin);


}
// A method to set a Mesh ID into a model array
void Application::SetMeshID(int counter, Mesh *pMesh)
{
	printf("\nSetMeshID into the Application Model array");
//	Model.reserve(Model.size()+1);
//	Model.push_back(counter);
//	Model[counter] = pMesh;
}

void Application::RenderApplication(AppWindow **p_array)
{
	// Loop through all the windows owned by the application
	for (int i=0;i<MAX_WINDOWS;i++)
	{
//		cout << "======================================" << endl;
//		cout << "Array [" << i << "]:                  " << (*(p_array+i))->GetWindow() << endl;
//		cout << "GetWindowID(" << i << ")->GetWindow():" << GetWindowID(i)->GetWindow() << endl;

/*
// This chunk works...do not delete...references the **p_array format
		// Test function: This will render blue shades to the windows created by the application
		// Replace this line with a corrected call for rendering.
		(*(p_array+i))->RenderWindow((*(p_array+i))->GetWindow(), float(1.0-(float (i)/ float (MAX_WINDOWS))));
*/
	}
}
// This is our main loop where all the magic happens every frame
void Application::AppLoop()
{
	printf("\nStarting Application Loop");
}

// This can be used to free all of our resources in the application.
void Application::Destroy()
{
	printf("\nDestroying Application");

	// First destroy all of the windows in the application
	for (int i=0;i<MAX_WINDOWS;i++)
	{
//		cout << "======================================" << endl;
//		cout << "Array [" << i << "]:                  " << (*(p_array+i))->GetWindow() << endl;
//		cout << "GetWindowID(" << i << ")->GetWindow():" << GetWindowID(i)->GetWindow() << endl;
		
		// cout << "GetWindowID(" << i << ")->GetWindow():" << GetWindowID(i)->GetWindow() << endl;

		GetWindowID(i)->Destroy();
	}

    //Finalize and clean up GLFW  
    glfwTerminate();  

}