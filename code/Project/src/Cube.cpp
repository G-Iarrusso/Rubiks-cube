/*
 * Based On SimpleView Assignments
 */
#include "Cube.hpp"
#include <stdio.h>
extern Camera myCamera;
extern RenderMode renderMode;
Cube::Cube(int x, int y, int z)
{
	// set set cordinate vertexalues for all vertexertices
    // other faces
    r = 1.0;
    g = 1.0;
    b = 1.0;
    vertex[0][0] = -1.5+x; vertex[0][1] = -1.5+y; vertex[0][2] = -1.5+z;
	vertex[1][0] = -1.5+x; vertex[1][1] = -0.5+y; vertex[1][2] = -1.5+z;
	vertex[2][0] = -0.5+x; vertex[2][1] = -1.5+y; vertex[2][2] = -1.5+z;
	vertex[3][0] = -0.5+x; vertex[3][1] = -0.5+y; vertex[3][2] = -1.5+z;
	vertex[4][0] = -1.5+x; vertex[4][1] = -1.5+y; vertex[4][2] = -0.5+z;
	vertex[5][0] = -1.5+x; vertex[5][1] = -0.5+y; vertex[5][2] = -0.5+z;
	vertex[6][0] = -0.5+x; vertex[6][1] = -1.5+y; vertex[6][2] = -0.5+z;
	vertex[7][0] = -0.5+x; vertex[7][1] = -0.5+y; vertex[7][2] = -0.5+z;

	face[0][0] = 0; face[0][1] = 1; face[0][2] = 3; face[0][3] = 2; //bottom
	face[1][0] = 6; face[1][1] = 7; face[1][2] = 5; face[1][3] = 4; //top
	face[2][0] = 0; face[2][1] = 4; face[2][2] = 5; face[2][3] = 1; //back
	face[3][0] = 3; face[3][1] = 1; face[3][2] = 5; face[3][3] = 7; //right
	face[4][0] = 3; face[4][1] = 2; face[4][2] = 6; face[4][3] = 7; //front
	face[5][0] = 0; face[5][1] = 2; face[5][2] = 6; face[5][3] = 4; //left

	faceColor[0][0] = 1.0, faceColor[0][1] = 1.0; faceColor[0][2] = 0.0; //bottom
	faceColor[1][0] = 1.0, faceColor[1][1] = 1.0; faceColor[1][2] = 1.0; //top
	faceColor[2][0] = 0.0, faceColor[2][1] = 1.0; faceColor[2][2] = 0.0; //back
	faceColor[3][0] = 1.0, faceColor[3][1] = 0.5; faceColor[3][2] = 0.0; //right
	faceColor[4][0] = 0.0, faceColor[4][1] = 0.0; faceColor[4][2] = 1.0; //front
	faceColor[5][0] = 1.0, faceColor[5][1] = 0.0; faceColor[5][2] = 0.0; //left

	faceNormal[0][0] =  0.0, faceNormal[0][1] =  0.0, faceNormal[0][2] = -1.0,
	faceNormal[1][0] =  0.0, faceNormal[1][1] =  0.0, faceNormal[1][2] =  1.0;
	faceNormal[2][0] = -1.0, faceNormal[2][1] =  0.0, faceNormal[2][2] =  0.0;
	faceNormal[3][0] =  0.0, faceNormal[3][1] =  1.0, faceNormal[3][2] =  0.0;
	faceNormal[4][0] =  1.0, faceNormal[4][1] =  0.0, faceNormal[4][2] =  0.0;
	faceNormal[5][0] =  0.0, faceNormal[5][1] = -1.0, faceNormal[5][2] =  0.0;

	//bottom face displays
	display[0][0] = 1;display[0][1] = 0; display[1][0] = 1;display[1][1] = 2; display[2][0] = 1;display[2][1] = 5;
	display[3][0] = 2;display[3][1] = 0; display[4][0] = 2;display[4][1] = 5;
	display[5][0] = 3;display[5][1] = 0; display[6][0] = 3;display[6][1] = 5; display[7][0] = 3;display[7][1] = 4;
	display[8][0] = 4;display[8][1] = 0; display[9][0] = 4;display[9][1] = 2;
	display[10][0] = 5;display[10][1] = 0;
	display[11][0] = 6;display[11][1] = 0; display[12][0] = 6;display[12][1] = 4;
	display[13][0] = 7;display[13][1] = 0; display[14][0] = 7;display[14][1] = 2; display[15][0] = 7;display[15][1] = 3;
	display[16][0] = 8;display[16][1] = 0; display[17][0] = 8;display[17][1] = 3;
	display[18][0] = 9;display[18][1] = 0; display[19][0] = 9;display[19][1] = 3; display[20][0] = 9;display[20][1] = 4;

	//middle face displays
	display[21][0] = 10;display[21][1] = 2; display[22][0] = 10;display[22][1] = 5;
	display[23][0] = 11;display[23][1] = 5;
	display[24][0] = 12;display[24][1] = 5; display[25][0] = 12;display[25][1] = 4;
	display[26][0] = 13;display[26][1] = 2;
	display[27][0] = 15;display[27][1] = 4;
	display[28][0] = 16;display[28][1] = 3; display[29][0] = 16;display[29][1] = 2;
	display[30][0] = 17;display[30][1] = 3;
	display[31][0] = 18;display[31][1] = 3; display[32][0] = 18;display[32][1] = 4;

	//top face displays
	display[33][0] = 19;display[33][1] = 1; display[34][0] = 19;display[34][1] = 2; display[35][0] = 19;display[35][1] = 5;
	display[36][0] = 20;display[36][1] = 1; display[37][0] = 20;display[37][1] = 5;
	display[38][0] = 21;display[38][1] = 1; display[39][0] = 21;display[39][1] = 5; display[40][0] = 21;display[40][1] = 4;
	display[41][0] = 22;display[41][1] = 1; display[42][0] = 22;display[42][1] = 2;
	display[43][0] = 23;display[43][1] = 1;
	display[44][0] = 24;display[44][1] = 1; display[45][0] = 24;display[45][1] = 4;
	display[46][0] = 25;display[46][1] = 1; display[47][0] = 25;display[47][1] = 2; display[48][0] = 25;display[48][1] = 3;
	display[49][0] = 26;display[49][1] = 1; display[50][0] = 26;display[50][1] = 3;
	display[51][0] = 27;display[51][1] = 1; display[52][0] = 27;display[52][1] = 3; display[53][0] = 27;display[53][1] = 4;
}

void Cube::drawFace(int i)
{
	if(renderMode == CONSTANT)
	{
	   glColor3f(faceColor[i][0], faceColor[i][1], faceColor[i][2]);
	   glBegin(GL_POLYGON);
	   glVertex3fv(vertex[face[i][0]]);
	   glVertex3fv(vertex[face[i][1]]);
	   glVertex3fv(vertex[face[i][2]]);
	   glVertex3fv(vertex[face[i][3]]);
	   glEnd();
	   glColor3f(0,0,0);
	   glBegin(GL_LINE_LOOP);
	   glVertex3fv(vertex[face[i][0]]);
	   glVertex3fv(vertex[face[i][1]]);
	   glVertex3fv(vertex[face[i][2]]);
	   glVertex3fv(vertex[face[i][3]]);
	   glEnd();
	}
	else if(renderMode == WIRE){
	   glColor3f(faceColor[i][0], faceColor[i][1], faceColor[i][2]);
	   glBegin(GL_LINE_LOOP);
	   glVertex3fv(vertex[face[i][0]]);
	   glVertex3fv(vertex[face[i][2]]);
	   glVertex3fv(vertex[face[i][3]]);
	   glVertex3fv(vertex[face[i][1]]);
	   glVertex3fv(vertex[face[i][0]]);
	   glVertex3fv(vertex[face[i][1]]);
	   glVertex3fv(vertex[face[i][2]]);
	   glVertex3fv(vertex[face[i][3]]);
	   glEnd();
	}
	else{
	   glColor3f(faceColor[i][0], faceColor[i][1], faceColor[i][2]);
	   glEnable(GL_TEXTURE_2D);
	   glBindTexture(GL_TEXTURE_2D,1);
	   glBegin(GL_QUADS);
	   glTexCoord2f(0.0, 0.0); glVertex3fv(&vertex[face[i][0]][0]);
	   glTexCoord2f(1.0, 0.0); glVertex3fv(&vertex[face[i][1]][0]);
	   glTexCoord2f(1.0, 1.0); glVertex3fv(&vertex[face[i][2]][0]);
	   glTexCoord2f(0.0, 1.0); glVertex3fv(&vertex[face[i][3]][0]);
	   glEnd();
	   glDisable(GL_TEXTURE_2D);
	   glColor3f(0,0,0);
	   glBegin(GL_LINE_LOOP);
	   glVertex3fv(vertex[face[i][0]]);
	   glVertex3fv(vertex[face[i][1]]);
	   glVertex3fv(vertex[face[i][2]]);
	   glVertex3fv(vertex[face[i][3]]);
	   glEnd();
	}
}

void Cube::draw(){

	glPushMatrix();
	this->ctmMultiply();
	for (int i = 0; i < 6; i++) {
		if(in(id,i)){
			if (isFrontface(i, myCamera)){
					drawFace(i);
			}
		}
}
glPopMatrix();
}


bool Cube::isFrontface(int faceindex, Camera camera) {
	GLfloat v[4];
	v[0] = faceNormal[faceindex][0];
	v[1] = faceNormal[faceindex][1];
	v[2] = faceNormal[faceindex][2];
	v[3] = 0.0;
	mc.multiplyVector(v);
	if (pmc != NULL) {
		pmc->multiplyVector(v);
		return (pmc->mat[0][3] - camera.eye.x) * v[0] + (pmc->mat[1][3] - camera.eye.y) * v[1] + (pmc->mat[2][3] - camera.eye.z) * v[2] < 0;
	} else {
		return (mc.mat[0][3] - camera.eye.x) * v[0] + (mc.mat[1][3] - camera.eye.y) * v[1] + (mc.mat[2][3] - camera.eye.z) * v[2] < 0;
	}
}

bool Cube::in(GLint id, int face){
	for(int i = 0; i<54;i++){
		if(display[i][0]==id and display[i][1]==face){
			return 1;
		}
	}
	return 0;

}



