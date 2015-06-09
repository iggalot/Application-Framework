
#include "stdafx.h"
#include <iostream>

//#include "../Headers/Volume.h"
#include "../Headers/Main.h"
#include "../Headers/Model.h"

using namespace std;

Model::Model()
{
	printf("Model constructor...");
}

void Model::Initialize()
{
	printf("\nCreating a model...");

	ModelTargetWindow = WINDOW_VIEWMODEL;

	//////////////
	// Test Cases
	//////////////
	// Create Volume #1 in Window1
	Volume *MyVolume[MAX_MODEL_VOLUMES];		// creates an array to store a volume

	MyVolume[0] = new Volume;
	MyVolume[0]->Initialize(VOLUME_RIGHT_PRISM);
	MemberVolume[0] = MyVolume[0];
	MemberVolume[0]->VolTargetWindow = WINDOW_VIEW1;

	MyVolume[1] = new Volume;
	MyVolume[1]->Initialize(VOLUME_AREA);
	MemberVolume[1] = MyVolume[1];
	MemberVolume[1]->VolTargetWindow = WINDOW_VIEW2;

	return;
	
}

void Model::RenderModel(AppWindow **WinID_array)
{
	printf("\nRendering a model...");

	GLFWwindow *Window;
	Window = (*(WinID_array+ModelTargetWindow))->GetWindow();

	// Make sure the window is valid, if not, throw an error.
	if ((Window == nullptr) || (ModelTargetWindow >= MAX_WINDOWS) )
	{
		fprintf(stderr, "\nInvalid Window found in ModelMesh.cpp RenderModel() function");
		return;
	}

	glfwMakeContextCurrent(Window); // Initialize GLEW 

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) 
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		return;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(Window, GLFW_STICKY_KEYS, GL_TRUE);

	// Render
	glClearColor(0.4f, 0.5f, 0.5f, 1.0f);		// Clear the colorbuffer
	glClear( GL_COLOR_BUFFER_BIT );				// Clear the screen

	while(!glfwWindowShouldClose(Window))
	{
		// Render the model members to the MODEL view (set by WINDOW_VIEWMODEL in Application.h).  Draws all members in Window #1
		for(int i=0;i<MAX_MODEL_VOLUMES;i++)
		{
			Window = (*(WinID_array+ModelTargetWindow))->GetWindow();

			// Make sure the window is valid, if not, throw an error.
			if ((Window == nullptr) || (ModelTargetWindow >= MAX_WINDOWS) )
			{
				fprintf(stderr, "\nInvalid Window found in ModelMesh.cpp RenderModel() function");
				return;
			}

			glfwMakeContextCurrent(Window); // Initialize GLEW 
			MemberVolume[i]->RenderVolume(ModelTargetWindow, WinID_array );
			cout << "\nRendering volume #: " << i << " to Window #: " << ModelTargetWindow;
		}

		// Then render the sub volumes out.  Draws volumes to their specified windows.
		for(int i=0;i<MAX_MODEL_VOLUMES;i++)
		{
			for (int j=0;j<MAX_WINDOWS;j++)
			{
				if (MemberVolume[i]->VolTargetWindow == j)
				{
					Window = (*(WinID_array+j))->GetWindow();

					// Make sure the window is valid, if not, throw an error.
					if ((Window == nullptr) || (ModelTargetWindow >= MAX_WINDOWS) )
					{
						fprintf(stderr, "\nInvalid Window found in ModelMesh.cpp RenderModel() function");
						return;
					}

					glfwMakeContextCurrent(Window); // Initialize GLEW 
					MemberVolume[i]->RenderVolume(MemberVolume[i]->VolTargetWindow, WinID_array );
					cout << "\nRendering volume #: " << i << " to SubWindow #: " << MemberVolume[i]->VolTargetWindow;
				} // end if
			}
		}
		// To swap the buffers...cycle through each of the AppWindows.
		for(int i=0;i<MAX_WINDOWS;i++)
		{
	//		cout << "Volume MemberMesh[" << i << "],  Type #: " << MemberMesh[i]->MeshType << " to TargetWindow #: " << TargetWindow;
			Window = (*(WinID_array+i))->GetWindow();
			glfwSwapBuffers(Window);
	//		getchar();
		}
		getchar();
	} // end while
	return;
	
}