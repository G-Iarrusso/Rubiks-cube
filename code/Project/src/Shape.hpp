/*
 * Based On SimpleView Assignments
 */
#ifndef CSHAPE_H
#define CSHAPE_H

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Matrix.hpp"

using namespace std;

/*
 *  enumeration for Render option
 */
enum RenderMode {
  CONSTANT,
  WIRE,
  TEXTURE
};



/**
 * Shape
 * The common class that will be inherited by model object class
 */
class Shape {
protected:
	Matrix mc;   /* the Model coordinate system (X, Y, Z, 0) in WC, represent the position of the object in WC */
	Matrix *pmc; /* parent mc pointer if any */
	GLfloat s;   /* scale factor */
	GLint id;    /* used to identify object */

public:
	Shape();                 /* constructor */
	virtual ~Shape();        /* destructor  */
	Matrix getMC();          /* return Matrix object */
	void setParentMC(Matrix *pm); /* set parent mc if any */
	void ctmMultiply();      /* function to do the CTM * MC */
	void setScale (GLfloat x); /* set scale factor */
	void scaleChange (GLfloat x); /* set scale factor */
	void setId(GLint id);
	GLint getId();
	void translate(GLfloat tx, GLfloat ty, GLfloat tz); /* translate the MC origin by (tx, ty, tz) */
	void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);   /* rotate w.r.t. axis (0,0,0)+u(rx,ry,rz) WCS */
	void rotate(GLfloat x0, GLfloat  y0, GLfloat  z0, GLfloat  rx, GLfloat  ry, GLfloat rz, GLfloat  angle); /* rotate w.r.t. axis (x0,y0,z0)+u(rx,ry,yz) in WCS */
	void rotateOrigin(GLfloat x0, GLfloat  y0, GLfloat  z0, GLfloat  rx, GLfloat  ry, GLfloat rz, GLfloat  angle); /* rotate MCS origion w.r.t. axis (x0,y0,z0)+u(rx,ry,yz) in WCS */
	void reset();             /* a function that resets the shape transformation matrix */
	virtual void draw() = 0;  /* draw function must be overwritten */
};

#endif
