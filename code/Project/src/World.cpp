/*
 * Based On SimpleView Assignments
*/
#include "World.hpp"
#include "Cube.hpp"
#include <stdio.h>

using namespace std;

World::World() {
/* add Cube into the world object list */
	Shape *obj = NULL;
	obj = new Cube(0,0,0); obj->setId(1); objlist.push_back(obj); cube[0][0][0] = obj->getId();
	obj = new Cube(1,0,0); obj->setId(2); objlist.push_back(obj); cube[1][0][0] = obj->getId();
	obj = new Cube(2,0,0); obj->setId(3); objlist.push_back(obj); cube[2][0][0] = obj->getId();

	obj = new Cube(0,1,0); obj->setId(4); objlist.push_back(obj); cube[0][1][0] = obj->getId();
	obj = new Cube(1,1,0); obj->setId(5); objlist.push_back(obj); cube[1][1][0] = obj->getId();
	obj = new Cube(2,1,0); obj->setId(6); objlist.push_back(obj); cube[2][1][0] = obj->getId();

	obj = new Cube(0,2,0); obj->setId(7); objlist.push_back(obj); cube[0][2][0] = obj->getId();
	obj = new Cube(1,2,0); obj->setId(8); objlist.push_back(obj); cube[1][2][0] = obj->getId();
	obj = new Cube(2,2,0); obj->setId(9); objlist.push_back(obj); cube[2][2][0] = obj->getId();

	obj = new Cube(0,0,1); obj->setId(10); objlist.push_back(obj); cube[0][0][1] = obj->getId();
	obj = new Cube(1,0,1); obj->setId(11); objlist.push_back(obj); cube[1][0][1] = obj->getId();
	obj = new Cube(2,0,1); obj->setId(12); objlist.push_back(obj); cube[2][0][1] = obj->getId();

	obj = new Cube(0,1,1); obj->setId(13); objlist.push_back(obj); cube[0][1][1] = obj->getId();
	obj = new Cube(1,1,1); obj->setId(14); objlist.push_back(obj); cube[1][1][1] = obj->getId();
	obj = new Cube(2,1,1); obj->setId(15); objlist.push_back(obj); cube[2][1][1] = obj->getId();

	obj = new Cube(0,2,1); obj->setId(16); objlist.push_back(obj); cube[0][2][1] = obj->getId();
	obj = new Cube(1,2,1); obj->setId(17); objlist.push_back(obj); cube[1][2][1] = obj->getId();
	obj = new Cube(2,2,1); obj->setId(18); objlist.push_back(obj); cube[2][2][1] = obj->getId();

	obj = new Cube(0,0,2); obj->setId(19); objlist.push_back(obj); cube[0][0][2] = obj->getId();
	obj = new Cube(1,0,2); obj->setId(20); objlist.push_back(obj); cube[1][0][2] = obj->getId();
	obj = new Cube(2,0,2); obj->setId(21); objlist.push_back(obj); cube[2][0][2] = obj->getId();

	obj = new Cube(0,1,2); obj->setId(22); objlist.push_back(obj); cube[0][1][2] = obj->getId();
	obj = new Cube(1,1,2); obj->setId(23); objlist.push_back(obj); cube[1][1][2] = obj->getId();
	obj = new Cube(2,1,2); obj->setId(24); objlist.push_back(obj); cube[2][1][2] = obj->getId();

	obj = new Cube(0,2,2); obj->setId(25); objlist.push_back(obj); cube[0][2][2] = obj->getId();
	obj = new Cube(1,2,2); obj->setId(26); objlist.push_back(obj); cube[1][2][2] = obj->getId();
	obj = new Cube(2,2,2); obj->setId(27); objlist.push_back(obj); cube[2][2][2] = obj->getId();
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			for(int k = 0; k<3; k++){
				cube_start[i][j][k] = cube[i][j][k];
			}
		}
	}

}

World::~World(){
	Shape *obj;
	while (!objlist.empty()) {
		obj = objlist.front();
		objlist.pop_front();
		free(obj);
	}
}

void World::draw() {

	std::list<Shape*>::iterator it;
	//printf("In world draw\n");
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
	  (*it)->draw();
    }
}

void World::reset(){
	//printf("In world reset\n");
	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
	  (*it)->reset();
    }
	for(int i = 0; i<3; i++){
			for(int j = 0; j<3; j++){
				for(int k = 0; k<3; k++){
					cube[i][j][k] = cube_start[i][j][k];
				}
			}
		}
}
void World::rotate_cube(GLint side, GLint layer){
	GLint temp;
	if (side == 0) {
		temp = cube[0][layer][1];
		cube[0][layer][1] = cube[1][layer][0];
		cube[1][layer][0] = temp;

		temp = cube[0][layer][2];
		cube[0][layer][2] = cube[2][layer][0];
		cube[2][layer][0] = temp;

		temp = cube[2][layer][1];
		cube[2][layer][1] = cube[1][layer][2];
		cube[1][layer][2] = temp;
		for (int i = 0; i<3; i++){
			temp = cube[i][layer][0];
			cube[i][layer][0] = cube[i][layer][2];
			cube[i][layer][2] = temp;
		}

	}
	if (side == 1) {
	    for (int i = 0; i < 3; i++) {
	        for (int j = 0; j < 3; j++) {
	            printf("%d ", cube[layer][i][j]);
	        }
	        printf("\n");
	    }
		temp = cube[layer][0][1];
		cube[layer][0][1] = cube[layer][1][0];
		cube[layer][1][0] = temp;

		temp = cube[layer][2][0];
		cube[layer][2][0] = cube[layer][0][2];
		cube[layer][0][2] = temp;

		temp = cube[layer][1][2];
		cube[layer][1][2] = cube[layer][2][1];
		cube[layer][2][1] = temp;

		for (int i = 0; i<3; i++){
			temp = cube[layer][i][0];
			cube[layer][i][0] = cube[layer][i][2];
			cube[layer][i][2] = temp;
		}
	    for (int i = 0; i < 3; i++) {
	        for (int j = 0; j < 3; j++) {
	            printf("%d ", cube[layer][i][j]);
	        }
	        printf("\n");
	    }
	}
	if (side == 2) {
		temp = cube[0][1][layer];
		cube[0][1][layer] = cube[1][0][layer];
		cube[1][0][layer] = temp;
		temp = cube[2][0][layer];
		cube[2][0][layer] = cube[0][2][layer];
		cube[0][2][layer] = temp;
		temp = cube[2][1][layer];
		cube[2][1][layer] = cube[1][2][layer];
		cube[1][2][layer] = temp;
		for (int i = 0; i<3; i++){
			temp = cube[0][i][layer];
			cube[0][i][layer] = cube[2][i][layer];
			cube[2][i][layer] = temp;
		}

	}
}
Shape* World::searchById(GLint i) {
	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
	  if ((*it)->getId() == i) return *it;
    }
	return NULL;
}

bool World::win(){
	for(int i = 0; i<3; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(cube[i][j][k] != cube_start[i][j][k]){
					return 0;
				}
			}
		}
	}
	return 1;
}
