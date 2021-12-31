/*
 * Based On SimpleView Assignments
 */
#ifndef CCUBE_H
#define CCUBE_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"
#include "Camera.hpp"

class Cube: public Shape {
protected:
    GLfloat vertex[8][3];  /* 2D array to store cube vertices */
    GLint face[6][4];      /* 2D array to store faces */
    GLfloat faceColor[6][3];
    GLfloat faceNormal[6][3];
    GLfloat r, g, b;       /* color cube */
    GLfloat display[54][2];
public:
    Cube(int,int,int);
    void draw();
    void drawFace(int);
    bool isFrontface(int, Camera);
    bool in(GLint,int);
};

#endif
