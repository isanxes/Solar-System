
#include <windows.h>		// Header File For Windows
#include <GL\gl.h>			// Header File For The OpenGL32 Library
#include <GL\glu.h>			// Header File For The GLu32 Library
#include <GL\glaux.h>		// Header File For The Glaux Library
#include <cmath>

#include "Point.h"
#include "PrimitiveDrawer.h"


PrimitiveDrawer::PrimitiveDrawer(){}

// Draw a point at the given position.
void PrimitiveDrawer::DrawPoint(Point point) {
    glBegin(GL_POINTS);
	glVertex3f(point.x,point.y,point.z);
    glEnd();
  }

 // Draw a line between the given two positions.
void PrimitiveDrawer::DrawLine(Point start, Point end) {
    glBegin(GL_LINES);
    glVertex3f(start.x, start.y, start.z);
    glVertex3f(end.x, end.y, end.z);
    glEnd();
  }

 // Draw a triangle with the given three vertices.
void PrimitiveDrawer::DrawTriangle(Point v1, Point v2, Point v3) {
    glBegin(GL_TRIANGLES);
    glVertex3f(v1.x, v1.y, v1.z);
    glVertex3f(v2.x, v2.y, v2.z);
    glVertex3f(v3.x, v3.y, v3.z);
    glEnd();
  }

// Draw a quadrilateral with the given four vertices.
  void PrimitiveDrawer::DrawQuad(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
    glVertex3f(v1.x, v1.y, v1.z);
    glVertex3f(v2.x, v2.y, v2.z);
    glVertex3f(v3.x, v3.y, v3.z);
    glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }
  void PrimitiveDrawer::DrawSphere(double r,double lats,double longs ,float rightLeft,float upDown,float red,float g,float b) 
{
	float M_PI = 3.14;
	int i, j;
	for (i = 0; i <= lats; i++) {
		double lat0 = M_PI * (-0.5 + (double)(i - 1) / lats);
		double z0 = sin(lat0);
		double zr0 = cos(lat0);

		double lat1 = M_PI * (-0.5 + (double)i / lats);
		double z1 = sin(lat1);
		double zr1 = cos(lat1);
		
		glBegin(GL_QUAD_STRIP);
		glColor3f(red,g,b);
		for (j = 0; j <= longs; j++) {

			double lng = 2 * M_PI * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			glNormal3f(x * zr0+upDown, y * zr0+rightLeft, z0);
			glVertex3f(r * x * zr0+upDown, r * y * zr0+rightLeft, r * z0);

			glNormal3f(x * zr1+upDown, y * zr1+rightLeft, z1);
			glVertex3f(r * x * zr1+upDown, r * y * zr1+rightLeft, r * z1);
		}
		glEnd();
		RGB(1,1,1);
	}
  
  }
  void PrimitiveDrawer::DrawCircle(float size,float right,float left ,float red,float green,float blue){
	  glBegin(GL_POINTS);
	  glColor3f(red,green,blue);
	  for(float i=0;i <= 2*3.14;i += 0.01)
	  {
		  float x=size*cos(i);
		  float y=size*sin(i);
		  glVertex3f(x+left,y+right,0);
	  }
	  glEnd();
	  RGB(1,1,1);
  }