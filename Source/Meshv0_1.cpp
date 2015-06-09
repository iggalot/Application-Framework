#include "stdafx.h"
#include <iostream>
#include "../Headers/Main.h"
#include "../Headers/Mesh.h"

using namespace std;

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

void Mesh::CreateMesh(int WinNum, int mesh_type)
{
	switch(mesh_type)
	{
		case MESH_TRIANGLE:
		{
			g_vertex_buffer_data.resize(0);			// delete the previous default buffer
			g_vertex_buffer_data.reserve(9);		// allocate 9 elements for a triangle
			MeshSize = 9;

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

			break;
		}
		case MESH_SQUARE:
		{
			g_vertex_buffer_data.resize(0);			// delete the previous default buffer
			g_vertex_buffer_data.reserve(18);		// allocate 18 elements for two triangle
			MeshSize=18;

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
void Mesh::Initialize(int mesh_type)

{
	printf("\nInitializing mesh...");
	
	


/*
	GLfloat g_vertex_buffer_data[9] = { 
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 0.0f,  1.0f, 0.0f,
	};
*/

/*
	// Create and compile our GLSL vertex and fragment shaders from the shader text files
//	Shader.Initialize(strVertex, strFragment);

	// Store the list of vertices and the length in our member variables
	Vertices = vertices;
	VerticesLength = length;

	// Reset the errors before we check again below
	GLenum ErrorCheckValue = glGetError();

	// Create the Vertex Array Object (VAO)
	glGenVertexArrays(1, &VertexArrayObjectId);
	glBindVertexArray(VertexArrayObjectId);

	// Create the Vertex Buffer Object (VBO)
	glGenBuffers(1, &VertexBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferId);

	// Store the vertices in the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices[0]) * length, Vertices, GL_STATIC_DRAW);

	// Here is where we tell OpenGL what the format each vertex is within our buffer.  
	glVertexAttribPointer(kVertexIndex, 3, GL_FLOAT, GL_FALSE, sizeof(Vertices[0]), 0);

	// Add the color attributes to our Vertex Array Object and Vertex Buffer Object
	glVertexAttribPointer(kColorIndex, 4, GL_FLOAT, GL_FALSE, sizeof(Vertices[0]), (GLvoid*)sizeof(Vertices[0].xyz));

	// Now check to see if any errors happened in this function
	ErrorCheckValue = glGetError();

	// If there was an error found, print it to the screen and close the OpenGL window.
	if (ErrorCheckValue != GL_NO_ERROR)
	{
		// Use gluErrorString(ErrorCheckValue) if you want to get the string value of the
		// error, but I removed this since Mac OSX 10.9 (Mavericks) deprecated this function.
		fprintf(stderr, "ERROR: Could not create a VAO and VBO with error Id: %d\n", ErrorCheckValue);
		exit(-1);
	}
*/

}


// This is the function that will actually render the model to the backbuffer, usually every frame
// if called in the GameLoop() function in Main.cpp.  **p_array is a pointer to the Windows stored in AppWindow.
void Mesh::RenderMesh(AppWindow **p_array, Mesh **MemberMesh, int num_mesh )
{
	GLFWwindow *Window;
	printf("\nRendering the mesh...");

// Probably need a malloc() call here instead.
	Mesh *MyMesh[3];				// A pointer to the Mesh class
	for(int mesh_count=0; mesh_count<num_mesh; mesh_count++)
	{
		MyMesh[mesh_count] = (*(MemberMesh+mesh_count));
//	for (int i=0;i<num_mesh;i++)
//		MyMesh[i] = (*(MemberMesh+i));

//	MyMesh[0] = *MemberMesh[0];
//	MyMesh[1] = *MemberMesh[1];
/*
// A test routine for a simple triangle drawn to one of the windows.
	MyMesh = new Mesh;			// and then create a new mesh object.
	//Create a Triangle in Window #1
	MyMesh->CreateMesh((int) WINDOW_VIEW2, MESH_TRIANGLE);
*/

//	cout << "\n=================================================================\n";
//	for (int i=0;i<MyMesh->MeshSize;i++)
//		cout << "g_vertex_buffer_data[" << i << "]: " << MyMesh->g_vertex_buffer_data[i] << endl;
//	cout << "=================================================================\n";
//	cout << "\nsize of array: " << MyMesh->g_vertex_buffer_data.size() << endl;

		int i = MyMesh[mesh_count]->TargetWindow;
		cout << "\nTargetting window #: " << TargetWindow << endl;
//		int i=0;
//		i = (*(MyMesh+i))->TargetWindow;
		Window = (*(p_array+i))->GetWindow();
	//	cout << "\n========================";
	//	cout << "\ni: " << i << endl;

	// Make sure the window is valid, if not, throw an error.
		if ( Window == nullptr )
		{
			fprintf(stderr, "Failed to create a GLFW window, you might need to download the latest drivers or change the OpenGL version to 3\n");
			Destroy();

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

		// Color the background background
		glClearColor(0.0f, 0.0f, 1.0f, 0.0f);


//////////////////////////////////////////////////////////////////////////
// MOVE TO INITIALIZE MODEL
//////////////////////////////////////////////////////////////////////////
		GLuint VertexArrayID;
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);

//		// Create and compile our GLSL program from the shaders
//		GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

		GLuint vertexbuffer;
		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(MyMesh->g_vertex_buffer_data), MyMesh->g_vertex_buffer_data, GL_STATIC_DRAW);
//		glBufferData(GL_ARRAY_BUFFER, (MyMesh->g_vertex_buffer_data.size())*sizeof(GLfloat), &(MyMesh->g_vertex_buffer_data).front(), GL_STATIC_DRAW);
//		glBufferData(GL_ARRAY_BUFFER, (MyMesh->MeshSize)*sizeof(GLfloat), &(MyMesh->g_vertex_buffer_data).front(), GL_STATIC_DRAW);
		glBufferData(GL_ARRAY_BUFFER, (MyMesh[mesh_count]->MeshSize)*sizeof(GLfloat), &(MyMesh[mesh_count]->g_vertex_buffer_data).front(), GL_STATIC_DRAW);

//		do{
			// Clear the screen
			glClear( GL_COLOR_BUFFER_BIT );

			// Use our shader
//			glUseProgram(programID);

			// 1rst attribute buffer : vertices
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glVertexAttribPointer(
				0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset
			);

/////////////////////////////////////////////////////////////////////////////////////////
// End of MOVE PORTION TO INITIALIZE
/////////////////////////////////////////////////////////////////////////////////////////



			// Draw the shape !
//			glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
			glDrawArrays(GL_TRIANGLES, 0, (MyMesh[mesh_count]->MeshSize / 3) ); // 3 indices per triangle starting at 0 -> 1 triangle

			glDisableVertexAttribArray(0);
	
			// Swap buffers
			glfwSwapBuffers(Window);
			glfwPollEvents();

//		} // Check if the ESC key was pressed or the window was closed
//		while( glfwGetKey(Window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
//		   glfwWindowShouldClose(Window) == 0 );

		// Cleanup VBO
		glDeleteBuffers(1, &vertexbuffer);				// deletes the VBO
		glDeleteVertexArrays(1, &VertexArrayID);		// Deletes the VAO
//		glDeleteProgram(programID);						// Deletes the shader program
	}
	return;
}


// This handles all the cleanup for our model, like the VBO/VAO buffers and shaders.
void Mesh::Destroy()
{
	printf("\nDestroying mesh...");

	// If we have a valid vertex buffer, reset it's binding, delete it and clear the property
	if (VertexBufferId)
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &VertexBufferId);
		VertexBufferId = 0;
	}

	// If we have a valid vertex array, reset it's binding, delete it and clear the property
	if (VertexArrayObjectId)
	{
		glBindVertexArray(0);
		glDeleteVertexArrays(1, &VertexArrayObjectId);
		VertexArrayObjectId = 0;
	}


	//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

	// Be sure to stop pointing to the camera object
//	Camera = nullptr;

	//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////


	// Release the memory for the compiled shaders
//	Shader.Destroy();
}