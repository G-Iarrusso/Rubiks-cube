/*
 * Based On SimpleView Assignments
 */
#ifndef CWORLD_HPP
#define CWORLD_HPP

#include <iostream>
#include <list>
#include <vector>
#include "Shape.hpp"

class World {
private:
	std::list<Shape*> objlist;  /* C++ std::list data structure to store world object */
public:
	World();
	~World();
	void draw();   /* draw all objects in the world */
	void reset();  /* resets all objects */
	Shape *searchById(GLint i); /* find object pointer by id, used by select Object */
	GLint cube[3][3][3];
	void rotate_cube(GLint side, GLint layer);//Rotate the cube based on side(0=x,1=y,2=z) and layer(0 or 2)
	//For x [i][layer][j]
	//For y [layer][i][j]
	//For z [i][j][layer]
	GLint cube_start[3][3][3];
	bool win();
};

#endif
