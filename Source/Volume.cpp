#include "stdafx.h"
#include <iostream>
#include "../Headers/Main.h"
#include "../Headers/Mesh.h"
#include "../Headers/Volume.h"

class Volume;		// forward declaration

// A constructor for our volume class
Volume::Volume()
{
	NumMeshes = 0;
	VolumeType = VOLUME_UNDEFINED;
	VolTargetWindow = 0;
	printf("\nVolume constructor...");
}

void Volume::Initialize(int shape_code)
{
	printf("\nInitializing the volume...");

	VolTargetWindow = WINDOW_VIEW_UNDEFINED;

	switch(shape_code)
	{
		case VOLUME_UNDEFINED:
		{

			break;
		}
		case VOLUME_RIGHT_PRISM:
		{
			MemberMesh[0] = new Mesh;
			MemberMesh[0]->CreateMesh(WINDOW_VIEW1, MESH_TRIANGLE, (GLfloat)0.25, (GLfloat)-1.0, (GLfloat)1.0);
			MemberMesh[1] = new Mesh;
			MemberMesh[1]->CreateMesh(WINDOW_VIEW1, MESH_SQUARE, (GLfloat)1.50, (GLfloat)0.25, (GLfloat)1.0);
			NumMeshes = 2; 
			break;
		}

		case VOLUME_AREA:
		{

			// A right prism volume will require six mesh surfaces (two ends and four sides)

//			Mesh *MyMeshTest[6];		// creates an array to store a volume
//			MyMeshTest[0] = new Mesh;
//			MyMeshTest[0]->Initialize(MESH_SQUARE);
//
//			// store in the volume
//			MemberMesh[0] = MyMeshTest[0];

			//Create the Mesh (test)
			MemberMesh[0] = new Mesh;
			MemberMesh[0]->CreateMesh(WINDOW_VIEW1, MESH_TRIANGLE, 1.5, 0.5, 0.0);
			MemberMesh[1] = new Mesh;
			MemberMesh[1]->CreateMesh(WINDOW_VIEW1, MESH_TRIANGLE, 0.5, 1.0, 0.0);
			MemberMesh[2] = new Mesh;
			MemberMesh[2]->CreateMesh(WINDOW_VIEW2, MESH_TRIANGLE, 0.5, 0.5, 0.0);
			MemberMesh[3] = new Mesh;
			MemberMesh[3]->CreateMesh(WINDOW_VIEW2, MESH_TRIANGLE, 0.75, -0.5, 0.0);
			NumMeshes = 4;
			break;
		}
		default:
		{
			printf("\nUnkown volume type...");
			NumMeshes = -1;
			break;
		}
	}
	NumVAO = NumMeshes;
	NumVBO = NumMeshes;
	return;
}

void Volume::RenderVolume(int target_window, AppWindow **WinID_array)
//void Volume::RenderVolume(AppWindow **p_array, GLuint **VolVBO_ID, GLuint **VolVAO_ID)
{
	printf("\nRendering the volume...");

//	GLFWwindow *Window;

	// search for windows belonging to a target window
	for (int j=0; j< MAX_WINDOWS; j++)
	{
		int i=0;
		cout << "\n======================================================";
		cout << "\n Window #: " << j << endl;
		for (i=0;i<NumMeshes;i++)
		{
			// if the current window is the same as the TargetWindow draw it
			if (target_window == j)
			{
				/*
				Window = (*(WinID_array+j))->GetWindow();

				// Make sure the window is valid, if not, throw an error.
				if ((Window == nullptr) || (target_window >= MAX_WINDOWS) )
				{
					fprintf(stderr, "\nInvalid Window found in ModelMesh.cpp RenderModel() function");
					return;
				}
				*/

				cout << "\nFound a window " << target_window;
				MemberMesh[i]->RenderMesh(&MemberMesh[i]);							// the Mesh array to be parsed
				//TempMesh[count] = MemberMesh[i];		
//				cout << "\ni: " << i << " -- j: " << j << " -- Match #: " << count << " found...adding to TempMesh[]..";
//				cout << "\nMemberMesh[" << count << "] -- MeshType: " << MemberMesh[count]->MeshType << endl;
			}
//		MemberMesh[i]->RenderMesh(p_array, MemberMesh, NumMeshes );
		}
		cout << "\n=======================================================";
		
/*
		if (!(count < 1))  // if at least one mesh matched, 
		{
			for (int i=0;i<count;i++)
			{
				cout << "\nPassing " << (count) << " meshes to RenderMesh() function";
				//TempMesh[0]->RenderMesh(
				//	WinID_array,							// the WindowID array
				//	MemberMesh,							// the Mesh array to be parsed
				//	count,							// Mesh qty to render	
				//	2,									// Number of VAO's used per window
				//	2									// Number of VBO's used per window
				//);

//				MemberMesh[0]->RenderMesh(&MemberMesh[0]);							// the Mesh array to be parsed

			}
		}
		*/
	}

/*
	// To swap the buffers...cycle through each of the AppWindows.
	for(int i=0;i<MAX_WINDOWS;i++)
	{
//		TargetWindow = MemberMesh[i]->TargetWindow;
//		cout << "Volume MemberMesh[" << i << "],  Type #: " << MemberMesh[i]->MeshType << " to TargetWindow #: " << TargetWindow;
		Window = (*(WinID_array+i))->GetWindow();
getchar();

		glfwSwapBuffers(Window);
//		getchar();
	}
*/
//	for(int i=0;i<NumMeshes;i++)
//	{
//		MemberMesh[i]->DestroyMesh();
////		MemberMesh[i]->RenderMesh(p_array, MemberMesh, NumMeshes );
//	}
}