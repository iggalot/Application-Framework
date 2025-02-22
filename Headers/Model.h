#ifndef _Model_H
#define _Model_H

#include "../Headers/Main.h"
#include "../Headers/Volume.h"

#include <stdio.h>										// Used for fprintf and stderr
#include <stdlib.h>										// Used for the exit() function
//#include <GL\glew.h>									// Used for the OpenGL types like GLuint
#include <glm\glm.hpp>									// Used for the GLM math library
#include <glm/gtc/matrix_transform.hpp>					// Used for the GLM math library
#include <glm/gtx/transform2.hpp>						// Used for the GLM math library
#include "Shader.h"										// Used for loading and running our shaders
//#include "Camera.h"										// *NEW* Used to get access to the view and projection matrices

#define MAX_MODEL_VOLUMES 2				// defines the maximum number of volumes a given model can hold

// The Model class to handle initializing, rendering and destroying of a 3D object
class Model
{
public:
	GLuint ModelID;						// the model ID
	GLuint ModelType;						// the type of model (not currently used)
	Volume *MemberVolume[MAX_MODEL_VOLUMES];			// array to store the volumes in the model (better to cast this into a std::vector container in the future)
	GLuint ModelTargetWindow;					// an array to declare which window to draw the meshes in (currently unused)

	Model();							// a constructor for the model class
	~Model() {};						// a destructor for the model class
	
	void Initialize();					// initializes the model
	void RenderModel(AppWindow **p_array);				// renders the known model


	// These are created to standardize the index properties used for vertex properties.
	static const GLuint kVertexIndex = 0;				// This is for the x,y,z vertices
	static const GLuint kColorIndex = 1;				// This is for the r,g,b,a colors
	static const GLuint kTextureIndex = 2;				// This is for the u,v texture coordinates
	static const GLuint kNormalIndex = 3;				// This is for the x,y,z normals
	
/*
	// Set the scale of our model to 100% by default
	Model()		{ Scale = vec3(1.0f, 1.0f, 1.0f); }
	~Model()	{ Destroy(); }

	// Takes in a list of x,y,z vertices and vertex length to create the VBO and VAO's from,
	// as well as the text file locations for the vertex and fragment shaders to load.
	void Initialize(Vertex3 vertices[], int length, std::string strVertex, std::string strFragment);

	// This draws the Model to the backbuffer
	void Render();

	// Create the getter and setters for the model's position
	vec3 GetPosition() { return Position; }
	void SetPosition(vec3 position) { Position = position; }

	// Create the getter and setters for the model's rotation
	vec3 GetRotation() { return Rotation; }
	void SetRotation(vec3 rotation) { Rotation = rotation; }

	// Create the getter and setters for the model's scale
	vec3 GetScale() { return Scale; }
	void SetScale(vec3 scale) { Scale = scale; }

	// This cleans up the VBO and VAO's
	void Destroy();
*/

// protected:

//  Vertex3 *Vertices;									// The list of the vertices
//	GLint VerticesLength;								// The length of the vertices
//	GLuint VertexBufferId;								// The VBO Id stored by the VAO
//	GLuint VertexArrayObjectId;							// The VAO Id to bind when drawing

//	vec3 Position;										// The model's position
//	vec3 Rotation;										// The model's rotation
//	vec3 Scale;											// The model's scale

};

#endif
