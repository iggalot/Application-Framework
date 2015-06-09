#include "../Headers/Main.h"

class AppWindow
{
public:
	GLuint AppWindowID;					// stores the window ID

	// The width and height of the application
	static const int ScreenWidth = 1024;
	static const int ScreenHeight = 768;

	// Create a default constructor and deconstructor which cleans up
	AppWindow() {}
	~AppWindow() { Destroy(); }

	GLFWwindow *GetWindow() {return Window; }
	void SetWindow(GLFWwindow *pAppWindow) { Window = pAppWindow; }

	void SetWindowPos(int x_WindowPos, int y_WindowPos); 

	int Initialize(int width, int height, std::string strTitle, bool bFullScreen, int x_pos, int y_pos);			// Initializes the window settings

	int RenderWindow(GLFWwindow *pWindow, float color); 									// Controls the drawing of window information 
	void Resize() {}																		// Controls the resizing of a window
	void Move() {}																			// Controls the movement of a window
	void Destroy();																			// Destroys the windows

protected:
	GLFWwindow *Window;
	int x_WindowPos;
	int y_WindowPos;
};