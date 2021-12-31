/*
 * Based On SimpleView Assignments
 */
#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Cube.hpp"
#include <stdio.h>
#include <windows.h>  // for playing sound
#include <mmsystem.h> //

extern World myWorld;
extern Camera myCamera;
extern GLint transType, camType, xbegin;
extern GLint csType;
extern RenderMode renderMode;

Shape* selectObj1;
Shape* selectObj2;
Shape* selectObj3;
Shape* selectObj4;
Shape* selectObj5;
Shape* selectObj6;
Shape* selectObj7;
Shape* selectObj8;
Shape* selectObj9;

void menu() {

	GLint Rotate_Menu = glutCreateMenu(RotateFaceMenu);
	glutAddMenuEntry("(Z)Rotate top", 1);
	glutAddMenuEntry("(X)Rotate bottom", 2);
	glutAddMenuEntry("(C)Rotate left", 3);
	glutAddMenuEntry("(V)Rotate right", 4);
	glutAddMenuEntry("(B)Rotate front", 5);
	glutAddMenuEntry("(N)Rotate back", 6);

	GLint Move_Menu = glutCreateMenu(MoveMenu);
	glutAddMenuEntry("Rotate x", 1);
	glutAddMenuEntry("Rotate y", 2);
	glutAddMenuEntry("Rotate z", 3);

	GLint Shading_Menu = glutCreateMenu(shadeMenu);
	glutAddMenuEntry("Wire Blocks", 1);
	glutAddMenuEntry("Constant Blocks", 2);
	glutAddMenuEntry("Monkey", 3);

	glutCreateMenu(mainMenu);
	glutAddMenuEntry("Reset", 1);
	glutAddMenuEntry("Scramble", 3);
	glutAddSubMenu("Shading", Shading_Menu);
	glutAddSubMenu("Camera Movement", Move_Menu);
	glutAddSubMenu("Rotate", Rotate_Menu);
	glutAddMenuEntry("Quit", 2);
}

void mainMenu(GLint option) {
	switch (option){
		case 1:
			myWorld.reset();
			myCamera.reset();
			break;
		case 2:
			exit(0);
			break;
		case 3:
			PlaySound((LPCSTR) "Beep.wav", NULL, SND_FILENAME | SND_ASYNC);
			for(int i=0; i <30; i++){
				int rotate_num = rand() % 6 + 1;
				RotateMenu(rotate_num);
			}
			break;
	}
	glutPostRedisplay();
}
//Menus
void MoveMenu(GLint transOption) {
	csType = 1;
	camType = transOption;
	glutPostRedisplay();
}

void RotateFaceMenu(GLint transOption) {
	transType = transOption;
	glutPostRedisplay();
	RotateMenu(transType);
}

//Rotation Functions
void RotateMenu(GLint transType) {
	//Top = 19-27
	//middle = 10-18
	//bottom = 1-9
	PlaySound((LPCSTR) "Slide.wav", NULL, SND_FILENAME | SND_ASYNC);
	Shape* cubes_list[9];
	int k = 0;
	if(transType==1){
		for(int i = 0; i<3; i++){
			for(int j=0; j<3; j++){
				cubes_list[k] = myWorld.searchById(myWorld.cube[j][i][2]);
				k++;
			}
		}
		for(int i = 0; i<k; i++){
			cubes_list[i]->rotate(0, 0, 0, 0, 0, 1, 90);
		}
		  myWorld.rotate_cube(2,2);

	}
	else if(transType == 2){
		for(int i = 0; i<3; i++){
			for(int j=0; j<3; j++){
				cubes_list[k] = myWorld.searchById(myWorld.cube[j][i][0]);
				k++;
			}
		}
		for(int i = 0; i<k; i++){
			cubes_list[i]->rotate(0, 0, 0, 0, 0, 1, 90);
		}
		  myWorld.rotate_cube(2,0);

	}
	else if(transType == 3){
			for(int i = 0; i<3; i++){
				for(int j=2; j>=0; j--){
					cubes_list[k] = myWorld.searchById(myWorld.cube[i][0][j]);
					k++;
				}
			}
			for(int i = 0; i<k; i++){
				cubes_list[i]->rotate(0, 0, 0, 0, 1, 0, 90);
			}
		  myWorld.rotate_cube(0,0);
	}
	else if(transType == 4){
		for(int i = 0; i<3; i++){
			for(int j=2; j>=0; j--){
				cubes_list[k] = myWorld.searchById(myWorld.cube[i][2][j]);
				k++;
			}
		}
		for(int i = 0; i<k; i++){
			cubes_list[i]->rotate(0, 0, 0, 0, 1, 0, 90);
		}
		  	myWorld.rotate_cube(0,2);
	}
	else if(transType == 5){
		for(int i = 0; i<3; i++){
			for(int j=2; j>=0; j--){
				cubes_list[k] = myWorld.searchById(myWorld.cube[2][i][j]);
				k++;
			}
		}
		for(int i = 0; i<k; i++){
			cubes_list[i]->rotate(0, 0, 0, 1, 0, 0, -90);
		}
		  	myWorld.rotate_cube(1,2);
	}
	else if(transType == 6){
		for(int i = 0; i<3; i++){
			for(int j=2; j>=0; j--){
				cubes_list[k] = myWorld.searchById(myWorld.cube[0][i][j]);
				k++;
			}
		}
		for(int i = 0; i<k; i++){
			cubes_list[i]->rotate(0, 0, 0, 1, 0, 0, -90);
		}
		  	myWorld.rotate_cube(1,0);
	}
	glutPostRedisplay();
	if(myWorld.win()){
	              PlaySound((LPCSTR) "Win.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
}


void Rotate_Camera(GLint x){
	//printf("xbegin:%d\n",xbegin);
	GLfloat theta = (xbegin - x > 0) ? 1 : -1;
	//printf("Move menu\n");
	if (camType == 1) {  //eye rotate x
		//printf("in x\n");
		myCamera.rotate(1.0, 0.0, 0.0, theta*0.5);
	}
	else if (camType == 2) { // eye rotate y
		//printf("in y\n");
		myCamera.rotate(0.0, 1.0, 0.0, theta*0.5);
	}
	else if(camType == 3){ //eye rotate z
		//printf("in z\n");
		myCamera.rotate(0.0, 0.0, 1.0, theta*0.5);
	}
}

void shadeMenu(GLint option) {
	switch (option){
	  case 1:
		renderMode = WIRE;
		break;
	  case 2:
		renderMode = CONSTANT;
		break;
	  case 3:
		renderMode = TEXTURE;
		break;
	}
	glutPostRedisplay();
}
