//***********************************************************************//
//																		 //
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -		 //
//                                                                       //
//		$Program:		Color											 //
//																		 //
//		$Description:	Draws a colored triangle in OpenGL 4			 //
//																		 //
//***********************************************************************//
#include "stdafx.h"
#include <iostream>
#include "../Headers/Shader.h"							// References the Shader class definition and GLEW header


// This function loads a text file and returns the code for our shaders
std::string Shader::LoadShaderFile(std::string strFile)
{
	// Open the file passed in
	std::ifstream fin(strFile.c_str());

	// Make sure we opened the file correctly
	if ( !fin )
	{
		cout << "\nError opening shader file: " << strFile;
		return "";
	}
	std::string strLine = "";
	std::string strText = "";

	// Go through and store each line in the text file within a "string" object
	while ( getline(fin, strLine) )
	{
		strText = strText + "\n" + strLine;
	}

	// Close our file
	fin.close();

	// Return the text file's data
	return strText;
}


// This function loads a vertex and fragment shader file and creates them
void Shader::Initialize(std::string strVertexFile, std::string strFragmentFile)
{
//	timeValue =  (GLfloat) 1.0f;
//	greenValue = (GLfloat) 1.0f;
//	vertexColorLocation = (GLint) 1;

	// These will hold the shader's text file data
	std::string strVShader, strFShader;

	// Make sure the user passed in a vertex and fragment shader file
	if ( !strVertexFile.length() || !strFragmentFile.length() )
		return;

	// If any of our shader pointers are set, let's free them first
	if ( VertexShaderID || FragmentShaderID || ShaderProgramID )
		Destroy();

	// Reset the last OpenGL error so we can check if down below
	GLenum ErrorCheckValue = glGetError();

	// Here we get an Id to our vertex and fragment shaders
	VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

//	cout << "VertexShaderID:  " << VertexShaderID;
//	cout << "FragmentShaderID:  " << FragmentShaderID;

	// Now we load the shaders from the respective files and store it in a string
	strVShader = LoadShaderFile(strVertexFile.c_str());
	strFShader = LoadShaderFile(strFragmentFile.c_str());

//	cout << "strVShader:  " << strVShader;
//	cout << "strFShader: " << strFShader;

	// Do a quick switch so we can do a double pointer below
	const char *szVShader = strVShader.c_str();
	const char *szFShader = strFShader.c_str();

	// Now this assigns the shader text file to each shader pointer
	glShaderSource(VertexShaderID, 1, &szVShader, nullptr);
	glShaderSource(FragmentShaderID, 1, &szFShader, nullptr);

	// Now we actually compile the shader code
	glCompileShader(VertexShaderID);
	glCompileShader(FragmentShaderID);

	// Next we create a program object to represent our shaders
	ShaderProgramID = glCreateProgram();

	// We attach each shader we just loaded to our program object
	glAttachShader(ShaderProgramID, VertexShaderID);
	glAttachShader(ShaderProgramID, FragmentShaderID);

	// Our last init function is to link our program object with OpenGL
	glLinkProgram(ShaderProgramID);

	// Now check to see if any errors happened in this function
	ErrorCheckValue = glGetError();

	// If there was an error found, print it to the screen and close the OpenGL window.
	if ( ErrorCheckValue != GL_NO_ERROR )
	{
		// Use gluErrorString(ErrorCheckValue) if you want to get the string value of the
		// error, but I removed this since Mac OSX 10.9 (Mavericks) deprecated this function.
		fprintf(stderr, "ERROR: Could not create the shader program with error Id: %d\n", ErrorCheckValue);
		exit(-1);
	}

	// sets a time changing color scheme into our shader.
//	GLfloat timeValue = glfwGetTime();
//	GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
//	GLint vertexColorLocation = glGetUniformLocation(ShaderProgramID, "ourColor");
}

// This function returns a variable Id for a shader variable.  This is used
// when we need to pass in variables into a shader like numbers and matrices.
GLint Shader::GetVariable(std::string strVariable)
{
	// If we don't have an active program object, let's return -1
	if(!ShaderProgramID)
		return -1;

	// This returns the variable Id for a variable in a shader file
	return glGetUniformLocation(ShaderProgramID, strVariable.c_str());
}


// This function frees all of our shader data
void Shader::Destroy()
{
	// If our vertex shader pointer is valid, free it
	if(VertexShaderID)
	{
		glDetachShader(ShaderProgramID, VertexShaderID);
		glDeleteShader(VertexShaderID);
		VertexShaderID = 0;
	}

	// If our fragment shader pointer is valid, free it
	if(FragmentShaderID)
	{
		glDetachShader(ShaderProgramID, FragmentShaderID);
		glDeleteShader(FragmentShaderID);
		FragmentShaderID = 0;
	}

	// If our program object pointer is valid, free it
	if(ShaderProgramID)
	{
		glDeleteShader(ShaderProgramID);
		ShaderProgramID = 0;
	}
}