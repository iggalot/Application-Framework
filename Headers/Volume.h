#ifndef _Volume_H
#define _Volume_H

#define MAX_VOL_MESHES 4			// the number of member meshes to hold in each volume

#include "../Headers/Main.h"

class Volume
{
public:
	GLuint VolumeID;							// stores the Volume ID
	GLuint VolumeType;							// stores the type of Volume as defined in Application.h
	Mesh *MemberMesh[MAX_VOL_MESHES];			// array to hold pointers to the meshes used to create a volume (better to cast this into a std::vector container in the future)
	int NumMeshes;								// stores the number of meshes in this volume
	int NumVAO;									// stores the number of VAO needed by OpenGL
	int NumVBO;									// stores the number of VBO needed by OpenGL
	GLuint VolTargetWindow;						// stores the window # (as defined in Application.h) where this volume (and its meshes) will be drawn

	Volume();									// a constructor for the volume class
	~Volume() {};								// a destructor for the volume class

	void Initialize(int shape_code);			// Initialize the class using a simple shape parameter defined in application.h

//	void RenderVolume(AppWindow **p_array, GLuint **VolVBO_ID, GLuint **VolVAO_ID);		// Render the mesh members of the volume to the appropriate windows
	void RenderVolume(int target_window, AppWindow **WinID_array);		// Render the mesh members of the volume to the appropriate windows

	void Destroy();								// Destroys the member data

protected:
	GLuint *VolVBO_ID[MAX_VOL_MESHES];								// The VBO Id stored by the VAO
	GLuint *VolVAO_ID[MAX_VOL_MESHES];							// The VAO Id to bind when drawing

};

#endif