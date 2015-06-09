#ifndef _Application_H
#define _Application_H

#include <vector>
using namespace std;

#include "../Headers/Main.h"

#include <string>										// Used for our STL string objects
#include <fstream>										// Used for fprintf and stderr									
//#include "glfw3\include\GLFW\glfw3.h"					// Used to reference the GLFW library
#include "WindowManager.h"								// Used to reference the abstract base class

#define WINDOW_VIEW_UNDEFINED -1						// Used for initialization of the Volume classes only...
#define WINDOW_VIEWMODEL 0								// Counters for the main model windows of the application
#define WINDOW_VIEW1 1									// Counters for the subwindows of the application
#define WINDOW_VIEW2 2									// Counters for the subwindows of the application
#define MAX_WINDOWS 3									// Counter for the number of windows in the application.  Must be greater than the highest WINDOW_VIEW# defined above.

// default MESH primitives
#define MESH_UNDEFINED -1								// for an undeclared or undefined mesh primitive type (used for intialization)
#define MESH_TRIANGLE	0								// for a simple 2D Triangle
#define MESH_SQUARE		1								// for a simple 2D Square
#define MESH_OTHER_2D	2								// for another 2D Shape
#define MAX_MESH_TYPES	3								// should be one greater than the last MESH type defined above

// default volume shapes for mesh construction rules
#define VOLUME_UNDEFINED		-1						// an undeclared or undefined region (used for intialization)
#define VOLUME_PLANAR_REGION	0						// for a planar region
#define VOLUME_AREA				1						// for a defined 2D area such as triangle or square
#define VOLUME_RIGHT_PRISM		2						// for a right prism
#define VOLUME_PYRAMID			3						// for a pyramid
#define VOLUME_CONE				4						// for a cone
#define VOLUME_TETRAHEDRON		5						// for a tetrahedron
#define VOLUME_SPHERE			6						// for a sphere
#define VOLUME_SPIRAL			7						// for a spiral shape
#define VOLUME_OTHER_3D			8						// for other shapes
#define MAX_VOLUME_QTY			9						// Number of differents defined known by the application.  Used as a parameter for the MODEL array/

class AppWindow;  // Forward declaration
class Mesh;		  // Forward declaration

// This is our main application class that handles orchestrating the init, main loop and cleanup
class Application
{
public:
	GLuint AppID;				// the ApplicationID

	// The width and height of the application
//	static const int ScreenWidth = 1024;
//	static const int ScreenHeight = 768;

	// Create a default constructor and deconstructor which cleans up
	Application();

	//	~Application() { Destroy(); }

	// This is the main function for our application, which is called by the main() function
	// in the WindowManager.cpp file.  This helps abstract out the environments entry point.
	int Main();

	// This gets and sets the window manager for the application.  This should be set right
	// after the GLApplication is created in the main() function.
//	WindowManager *GetWindowManager() { return WindowManager; }
//	void SetWindowManager(WindowManager *pWindowManager) { WindowManager = pWindowManager; }

	// This gets and sets a specified window within the application.  This will be used right after a window is crating to allow the application
	// to know the handles of each of the windows...to be used in identifying a rendering target when the time comes.
	AppWindow *GetWindowID(int counter) {return Window[counter]; }
	void SetWindowID(int counter, AppWindow *pAppWindow) { Window[counter] = pAppWindow; }
	
//	vector<int> *AppModel;		// An array to store the pointers to meshes in the application.  This will include a counter to tell a particular window where the Mesh is to be drawn.
//	Mesh *GetMeshID(int counter) {return Model[counter]; }
//	void SetMeshID(int counter, Mesh *pMesh) { Model->g_vertex_buffer_data.push_back(pMesh); }
	void SetMeshID(int counter, Mesh *pMesh);
//	Mesh *GetMeshID(int counter) { return Model[counter]; }

//	vector<Mesh> Model;  // to store the meshes in the application.  This will include a counter to tell a particular window where the Mesh is to be drawn.
	int NumMesh;		// The number of meshes known by the Application.
	
	// This initializes the application
	void Initialize();
	void RenderApplication(AppWindow **pAppWindow);
	// This runs the game loop and only quits when the user hits Escape or closes the window
	void AppLoop();

	// This cleans up the application and tells other objects to also cleanup
	void Destroy();

protected:
	// Our abstract window manager to create the window and manage input, which should be
	// environment agnostic.  Our main application shouldn't know if it's Win32 or GLFW.
	// This is instantiated and set in GLFWManager.cpp in the main() function.

//	WindowManager *WindowManager;
	AppWindow *Window[MAX_WINDOWS];			// An array to store the pointers to each of the windows of the application
};

#endif