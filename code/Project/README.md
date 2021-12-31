## SimpleView Reference Design

Author: HBF

Date: 2021-10-06

## What's about

This is a reference design to A2Q3 SimpleView1 program. You are allowed to design and implement your SimpleView1 program based on this reference design. 


## Working plan


1. Try the provided execugtable sample program, to see what your SimpleView1should look like at runtime. Import the SimpleView_reference_design.zip into Eclipse to as existing archive project. Understand the program design by reading the SimpleView.cpp, *.hpp and *.cpp files.  
2. Create your SimpleView1 project with the similar files like the reference design. Add menu to the your program, so that your SimpleView1 program has the menu structure like the sample program. 

3. Work on Cube class, setting vertices and faces, drawFace(int i) and draw() functions, to draw the cube. 

4. Implement Matrix functions 

Matrix::matrixPreMultiply(Matrix* m);  	// mat <- m*mat
Matrix::transpose();  				    // mat <- mat'
Matrix::multiplyVector(GLfloat* v);     // mat*v
Matrix::rotateMatrix(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle); // mat<-Rotate(rx, ry, rz, angle), refer to lecture node 3D transformation slide 16 for the 

5. Implement 

Shape::rotate(GLfloat  rx, GLfloat  ry, GLfloat rz, GLfloat  angle); to rotate MCS w.r.t. vector  (rx,ry,yz) in WCS.

Shape::rotate(GLfloat x0, GLfloat  y0, GLfloat  z0, GLfloat  rx, GLfloat  ry, GLfloat rz, GLfloat  angle); to rotate w.r.t. axis (x0,y0,z0)+u(rx,ry,yz) in WCS.

void Camera::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) 
to rotate eye position in WCS.

void Camera::translate(GLfloat tx, GLfloat ty, GLfloat tz) 
to translate in WCS. 


6. Create Pyramid class and add Pyramid object to World, similar to Cube class. 

	obj = new Pyramid();
	obj->translate(-2.5, 0, 0);
	objlist.push_back(obj);


7. Create House class, by objects Pyramid* pyramid and Cube* cube objects, like 
   
   	cube =  new Cube();
	cube->setParentMC(&mc);
	pyramid = new Pyramid();
	pyramid->setParentMC(&mc);
	pyramid->translate(0, 1, 0); // this puts pyramid at the top of the cube.

  then add a House object into world, like 
  
	obj = new House();
	obj->setId(3);
	obj->se
	obj->translate(2.5, 0, 0);
	objlist.push_back(obj);

