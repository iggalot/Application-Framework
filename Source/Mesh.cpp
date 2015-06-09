#include "stdafx.h"
#include <iostream>
#include "../Headers/Main.h"
#include "../Headers/Mesh.h"
#include "../Headers/Shader.h"

using namespace std;

#include <fstream>
bool fexists(const std::string& filename) {
  ifstream ifile(filename.c_str());
  return ifile;
}

// A constructor for the mesh class.  Makes a simple triangle to ensure that the drawing buffer doesnt blow up unexpectedly.  We will
// use the RESERVE and RESIZE operators to modifiy to thecorrect sizes for different structures.
Mesh::Mesh()
{
	// declare a vertex buffer to contain 9 elements (a minimal triangle)
	g_vertex_buffer_data.reserve(9);

	MeshSize = 9;
	// Data for a simple triangle
	//1st node
	g_vertex_buffer_data.push_back(-1.0f);
	g_vertex_buffer_data.push_back(-1.0f);
	g_vertex_buffer_data.push_back(0.0f);
	//2nd node
	g_vertex_buffer_data.push_back(1.0f);
	g_vertex_buffer_data.push_back(-1.0f);
	g_vertex_buffer_data.push_back(0.0f);
	//3rd node
	g_vertex_buffer_data.push_back(0.0f);
	g_vertex_buffer_data.push_back(1.0f);
	g_vertex_buffer_data.push_back(0.0f);

	TargetWindow = WINDOW_VIEW1;  // Default to the main window.  See application.h for the declarations.
	MeshType = MESH_UNDEFINED;


}

void Mesh::CreateMesh(int WinNum, int mesh_type, GLfloat param1, GLfloat param2, GLfloat param3)
{
	float width = param1;
	float height = param2;
	float depth = param3;

	switch(mesh_type)
	{
		case MESH_TRIANGLE:
		{
			g_vertex_buffer_data.resize(0);			// delete the previous default buffer
			g_vertex_buffer_data.reserve(9);		// allocate 9 elements for a triangle
			MeshSize = 9;

			// Data for a simple triangle
			//1st node
			g_vertex_buffer_data.push_back((GLfloat)-width);
			g_vertex_buffer_data.push_back((GLfloat)height);
			g_vertex_buffer_data.push_back((GLfloat)depth);
			//2nd node
			g_vertex_buffer_data.push_back((GLfloat)width);
			g_vertex_buffer_data.push_back((GLfloat)height);
			g_vertex_buffer_data.push_back((GLfloat)depth);
			//3rd node
			g_vertex_buffer_data.push_back((GLfloat)0.0);
			g_vertex_buffer_data.push_back((GLfloat)-height);
			g_vertex_buffer_data.push_back((GLfloat)depth);
/*
			// Data for a simple triangle
			//1st node
			g_vertex_buffer_data.push_back(-1.0f);
			g_vertex_buffer_data.push_back(1.0f);
			g_vertex_buffer_data.push_back(0.0f);
			//2nd node
			g_vertex_buffer_data.push_back(1.0f);
			g_vertex_buffer_data.push_back(1.0f);
			g_vertex_buffer_data.push_back(0.0f);
			//3rd node
			g_vertex_buffer_data.push_back(0.0f);
			g_vertex_buffer_data.push_back(-1.0f);
			g_vertex_buffer_data.push_back(0.0f);
*/
			cout << "\nCreatingMesh() Triangle...";
			break;
		}
		case MESH_SQUARE:
		{
			g_vertex_buffer_data.resize(0);			// delete the previous default buffer
			g_vertex_buffer_data.reserve(18);		// allocate 18 elements for two triangle
			MeshSize=18;

			// Data for a simple triangle
			//1st node
			g_vertex_buffer_data.push_back((GLfloat)-0.5*width);
			g_vertex_buffer_data.push_back((GLfloat)-0.5*height);
			g_vertex_buffer_data.push_back((GLfloat)depth);
			//2nd node
			g_vertex_buffer_data.push_back((GLfloat)0.5*width);
			g_vertex_buffer_data.push_back((GLfloat)0.5*height);
			g_vertex_buffer_data.push_back((GLfloat)depth);
			//3rd node
			g_vertex_buffer_data.push_back((GLfloat)-0.5*width);
			g_vertex_buffer_data.push_back((GLfloat)0.5*height);
			g_vertex_buffer_data.push_back((GLfloat)depth);
			//4th vertex
			g_vertex_buffer_data.push_back((GLfloat)-0.5*width);
			g_vertex_buffer_data.push_back((GLfloat)-0.5*height);
			g_vertex_buffer_data.push_back((GLfloat)depth);
			//5th vertex
			g_vertex_buffer_data.push_back((GLfloat)0.5*width);
			g_vertex_buffer_data.push_back((GLfloat)-0.5*height);
			g_vertex_buffer_data.push_back((GLfloat)depth);
			//6th vertex
			g_vertex_buffer_data.push_back((GLfloat)0.5*width);
			g_vertex_buffer_data.push_back((GLfloat)0.5*height);
			g_vertex_buffer_data.push_back((GLfloat)depth);	

			/*
			// Data for a simple triangle
			//1st node
			g_vertex_buffer_data.push_back(-0.6f);
			g_vertex_buffer_data.push_back(-0.6f);
			g_vertex_buffer_data.push_back(0.0f);
			//2nd node
			g_vertex_buffer_data.push_back(0.6f);
			g_vertex_buffer_data.push_back(0.6f);
			g_vertex_buffer_data.push_back(0.0f);
			//3rd node
			g_vertex_buffer_data.push_back(-0.6f);
			g_vertex_buffer_data.push_back(0.6f);
			g_vertex_buffer_data.push_back(0.0f);
			//4th vertex
			g_vertex_buffer_data.push_back(-0.6f);
			g_vertex_buffer_data.push_back(-0.6f);
			g_vertex_buffer_data.push_back(0.0f);
			//5th vertex
			g_vertex_buffer_data.push_back(0.6f);
			g_vertex_buffer_data.push_back(-0.6f);
			g_vertex_buffer_data.push_back(0.0f);
			//6th vertex
			g_vertex_buffer_data.push_back(0.6f);
			g_vertex_buffer_data.push_back(0.6f);
			g_vertex_buffer_data.push_back(0.0f);	
			*/
			cout << "\nCreateMesh(): Square...";
			break;
		}
		default:  // uses the default constructor from Mesh::Mesh()
			break;
	}
	TargetWindow = WinNum;
	MeshType = mesh_type;
	cout << "\nMESH CREATED:  MeshType: " << MeshType << " targetting window #: " << TargetWindow << endl;
	return;
}
// Initialize the model with vertices, length, and the vertex and fragment shader files
//void Mesh::Initialize(Vertex3 vertices[], int length, std::string strVertex, std::string strFragment)
void Mesh::Initialize(AppWindow **p_array, Mesh **MemberMesh, int num_mesh )
{
/*
	printf("\nInitializing mesh...");
	GLFWwindow *Window;

// Probably need a malloc() call here instead.
	Mesh *MyMesh[3];				// A pointer to the Mesh class
	for(int mesh_count=0; mesh_count<num_mesh; mesh_count++)
	{
		MyMesh[mesh_count] = (*(MemberMesh+mesh_count));

		int i = MyMesh[mesh_count]->TargetWindow;
		cout << "\nTargetting window #: " << TargetWindow << endl;

		Window = (*(p_array+i))->GetWindow();

	// Make sure the window is valid, if not, throw an error.
		if ( Window == nullptr )
		{
			fprintf(stderr, "Failed to create a GLFW window, you might need to download the latest drivers or change the OpenGL version to 3\n");
			DestroyMesh();
			return;
		}
	}
*/

}

// This is the function that will actually render the model to the backbuffer, usually every frame
// if called in the GameLoop() function in Main.cpp.  **p_array is a pointer to the Windows stored in AppWindow.
//void Mesh::RenderMesh(AppWindow **WinID_array, Mesh **MemberMesh, int num_mesh, int num_VAO, int num_VBO)
void Mesh::RenderMesh(Mesh **MemberMesh)
{
	printf("\nRender the mesh...");

//// Probably need a malloc() call here instead.
	Mesh *MyMesh;				// A pointer to the Mesh class
	MyMesh = (*(MemberMesh));

	/////////////////////////////////////////////////////
	//  Shader Stuff.  Currently all meshes use the same shader located in the /Shaders/ folder
	// given by the strVertexFile and strFragmentFile
	/////////////////////////////////////////////////////
	strVertexFile = "Shaders/Shader.vertex";				// the vertex shader file location
	strFragmentFile = "Shaders/Shader.fragment";			// the fragment shader file location
	
	//Test if the vertex shader file exists
	if (!fexists(strVertexFile))
		cout << "\nVertex shader file does not exist.  Check the file name in: " << strVertexFile;

	//Test is the fragment shader file exists
	if (!fexists(strFragmentFile))
		cout << "\nFragment shader file does not exist.  Check the file name in: " << strFragmentFile;

	Shader.Initialize(strVertexFile, strFragmentFile);			// initialize the shades.  StrVertexFile is the name of the vertex shader, strFragmentFile is the name of the fragment shader. 
	////////////////////////////////////////////////
	//  End Shader programs Loading and Binding
	////////////////////////////////////////////////

	int num_VAO = 1;							// establishes 1 VAO (qty of VAO variables) -- Change this for multiple shaders if necessary
	int num_VBO	= 1;							// establishes 1 VBO (qty of VBO variables) -- Change this for multiple buffers if necessary
	GLuint VertexArrayID[1];				// declare the VAO array
	GLuint VertexBufferID[1];				// declare the VBO array
			
	// Setup the VAO and VBO for the mesh
	// current sets up 1 VAO or VBO -- might need more
	glGenVertexArrays(num_VAO, VertexArrayID);					// Create the VAO
	glGenBuffers(num_VBO, VertexBufferID);						// Create the VBO
	
	for (int VAO_count=0;VAO_count<num_VAO;VAO_count++)
	{
		int VBO_count = VAO_count;  // A counter for the number of VBO arrays.  Assumed the same as VAO count

		// Stores the VAO and VBO data into their respective arrays
		glBindVertexArray(VertexArrayID[VAO_count]);						
		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID[VBO_count]);
		glBufferData(GL_ARRAY_BUFFER, (MyMesh->MeshSize)*sizeof(GLfloat), &(MyMesh->g_vertex_buffer_data).front(), GL_STATIC_DRAW);
		glVertexAttribPointer
		(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);	

		////////////////////////////////////////////////////////
		//  Drawing the VAO with shaders etc.
		////////////////////////////////////////////////////////
		// Draw the first array object (will need an array for multiple objects)
		// Now when we want to draw the first array object, we use the appropriate fragment shader	

		Shader.TurnOn();											// turns on the shader.
		
		// sets a time changing color scheme into our shader.
		GLfloat timeValue = (GLfloat)glfwGetTime();
		cout << "\nTime value: " << timeValue;
		GLfloat greenValue = (GLfloat)((sin(timeValue) / 2) + 0.5);
		cout << "\ngreenValue: " << greenValue;
		GLint vertexColorLocation = Shader.GetVariable("ourColor");
//			glGetUniformLocation(Shader.ShaderProgramID, "ourColor");

		cout << "\nvertexColorLocation: " << vertexColorLocation << "    greenvalue: " << greenValue;
//		glUniform4f(vertexColorLocation, 0.0f, Shader.greenValue, 0.0f, 1.0f); // passes the variables to the shader program

		glBindVertexArray(VertexArrayID[VAO_count]);	
		glDrawArrays(GL_TRIANGLES, 0, (MyMesh->MeshSize / 3) ); 	// Draw the shape ! 3 indices per triangle starting at 0 -> 1 triangle
		glBindVertexArray(0);										// clear the VBO
		glDisableVertexAttribArray(0);								// clear the VAO
		Shader.TurnOff();											// turns off the current shader so subsequent renders don't utilize a wrong shader.
	}  // end for loop


	return;



///// TEST CODE FOR DRAWING TWO OBJECTS TO ONE SCREEN. WORKS!!
/*
	    // Set up vertex data (and buffer(s)) and attribute pointers
    // We add a new set of vertices to form a second triangle (a total of 6 vertices); the vertex attribute configuration remains the same (still one 3-float position vector per vertex)
    GLfloat firstTriangle[] = {
        -0.9f, -0.5f, 0.0f,  // Left 
        -0.0f, -0.5f, 0.0f,  // Right
        -0.45f, 0.5f, 0.0f,  // Top 
    };
    GLfloat secondTriangle[] = {
         0.0f, -0.5f, 0.0f,  // Left
         0.9f, -0.5f, 0.0f,  // Right
         0.45f, 0.5f, 0.0f   // Top 
    };
    GLuint VBOs[2], VAOs[2];
    glGenVertexArrays(2, VAOs); // We can also generate multiple VAOs or buffers at the same time
    glGenBuffers(2, VBOs);
    // ================================
    // First Triangle setup
    // ===============================
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);	// Vertex attributes stay the same
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    // ================================
    // Second Triangle setup
    // ===============================
    glBindVertexArray(VAOs[1]);	// Note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);	// And a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0); // Because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out.
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    // Game loop
//    while (!glfwWindowShouldClose(window))
//    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Activate shader (same shader for both triangles)
 //       glUseProgram(shaderProgram);
        // Draw first triangle using the data from the first VAO
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // Then we draw the second triangle using the data from the second VAO
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        // Swap the screen buffers
        glfwSwapBuffers(Window);
getchar();
//    }
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    // Terminate GLFW, clearing any resources allocated by GLFW.
//    glfwTerminate();
*/
}


// This handles all the cleanup for our model, like the VBO/VAO buffers and shaders.
void Mesh::DestroyMesh()
{
	printf("\nDestroying mesh...");

	// If we have a valid vertex buffer, reset it's binding, delete it and clear the property
	if (VertexBufferID)
	{
		printf("\nDestroying VertexBuffer...");
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &VertexBufferID);		// deletes the VBO
		VertexBufferID = 0;
	}

	// If we have a valid vertex array, reset it's binding, delete it and clear the property
	if (VertexArrayID)
	{
		printf("\nDestroying VertexArray...");
		glBindVertexArray(0);
		glDeleteVertexArrays(1, &VertexArrayID);	// Deletes the VAO
		VertexArrayID = 0;
	}

//	// If we have a valid shader program, delete it
//	if (programID)
//	{
//		printf("\nDestroying VertexArray...");
//		glDeleteProgram(programID);						// Deletes the shader program
//		programID = 0;
//	}
	
	// Be sure to stop pointing to the camera object
//	Camera = nullptr;

	// Release the memory for the compiled shaders
//	Shader.Destroy();
}