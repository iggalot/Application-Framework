#include "stdafx.h"
#include <iostream>
#include "../Headers/Main.h"							// Include our main header for the application..includes the necessary includes for the application
#include "../Headers/Mesh.h"							// Include our main header for the application..includes the necessary includes for the application

using namespace std;

class AppWindow;	// forward declaration?
class Mesh;			// forward declaration?

//Model g_Triangle;										// Our class to handle initializing and drawing our triangle


static void error_callback(int error, const char* description)  
{  
    fputs(description, stderr);  
    _fgetchar();  
}  
  
//Define the key input callback  
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)  
{  
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)  
    glfwSetWindowShouldClose(window, GL_TRUE);  
} 

// This initializes our window and creates the OpenGL context
int AppWindow::Initialize(int width, int height, std::string strTitle, bool bFullScreen, int x_pos, int y_pos)
{
	printf("\nCreating a window..");

	// This tries to first init the GLFW library and make sure it is available
	if ( !glfwInit() )
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	GLFWwindow* Window; 
//	Window = glfwCreateWindow(640, 480, "Test Window", NULL, NULL);

	// This tells OpenGL that we want a multisampling value of 4 (anti-aliasing)
	glfwWindowHint(GLFW_SAMPLES, 4);

	// Set our OpenGL version to 4 using the core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_DECORATED, GL_FALSE);

//	// Create a window either in fullscreen or not
	if( bFullScreen )
		Window = glfwCreateWindow(width, height, strTitle.c_str(), glfwGetPrimaryMonitor(), nullptr);
	else
		Window = glfwCreateWindow(width, height, strTitle.c_str(), nullptr, nullptr);
//		AppWindow.SetWindow = glfwCreateWindow(width, height, strTitle.c_str(), nullptr, nullptr);


	// Make sure the window is valid, if not, throw an error.
	if ( Window == nullptr )
	{
		fprintf(stderr, "Failed to create a GLFW window, you might need to download the latest drivers or change the OpenGL version to 3\n");
		Destroy();

		return -1;
	}
	SetWindow(Window); // Stores the pointer to each of the windows
//	cout << "\nWindow Reference test for AppWin: " << GetWindow() << endl;

	SetWindowPos(x_pos, y_pos); // Sets the windows position and relocates it.

	return 0;
}

void AppWindow::SetWindowPos(int x_pos, int y_pos)
{ 
	x_WindowPos = x_pos; 
	y_WindowPos = y_pos; 
	glfwSetWindowPos(GetWindow(),x_pos,y_pos);
}

// This can be used to free our resources in the window
void AppWindow::Destroy()
{
	cout << "\nDestroying Window ID: " << GetWindow();

	//Close openGL window
	glfwDestroyWindow(GetWindow()); 
}

int AppWindow::RenderWindow(GLFWwindow *pWindow, float background_color)
{
	cout << "\nRendering AppWindow .. not currently used...";
	return 0;
}




