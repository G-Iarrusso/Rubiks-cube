/*
 * Based On SimpleView Assignments
 */
#include <windows.h>  // for playing sound
#include <mmsystem.h> //
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "pixmap/RGBpixmap.h"

GLint winWidth = 1000, winHeight = 900;
GLint isInMove = 0,
	  xbegin = 0,
	  transType = 4,
	  camType= 1,
	  csType = 1;

Shape *selectObj = NULL;  // pointer to select object
RenderMode renderMode = CONSTANT;
World myWorld;
Camera myCamera;
RGBpixmap pix[1];

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	myWorld.draw();
	glFlush();
	glutSwapBuffers();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

void init(void) {
	PlaySound((LPCSTR) "Beep.wav", NULL, SND_FILENAME | SND_ASYNC);
	pix[0].readBMPFile("mandrill.bmp");
	pix[0].setTexture(1);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	selectObj = myWorld.searchById(14);
}

void mouseActionFcn(int button, int state, int xMouse, int yMouse) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		isInMove = 1;
		xbegin = xMouse;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		isInMove = 0;
	}
}

void mouseMotionFcn(GLint xMouse, GLint yMouse) {
	if (isInMove) {
		if (csType == 1){
			Rotate_Camera(xMouse);
		}
	}
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
	//allow for keyboard inputs for rotation
	if(key=='r')
	{
		RotateMenu(transType);
		glutPostRedisplay();
	}
	else if(key=='z')
    {
        RotateMenu(1);
        glutPostRedisplay();
    }
    else if(key=='x')
    {
        RotateMenu(2);
        glutPostRedisplay();
    }
    else if(key=='c')
    {
        RotateMenu(3);
        glutPostRedisplay();
    }
    else if(key=='v')
    {
        RotateMenu(4);
        glutPostRedisplay();
    }
    else if(key=='b')
    {
        RotateMenu(5);
        glutPostRedisplay();
    }
    else if(key=='n')
    {
        RotateMenu(6);
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Rubix Cube");
	init();
	menu();
	glutDisplayFunc(display);
	glutMouseFunc(mouseActionFcn);
	glutMotionFunc(mouseMotionFcn);
	glutKeyboardFunc(keyboard);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
