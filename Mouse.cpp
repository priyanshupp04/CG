#include<stdio.h>

#include<gl/glut.h>

int w=640,h=480;

int side=40;

void init()

{

	glMatrixMode(GL_PROJECTION_MATRIX);	glLoadIdentity();

	gluOrtho2D(0,w,0,h);

	glMatrixMode(GL_MODELVIEW);

}

void disp()

{

	glClearColor(1,1,1,1);

	glClear(GL_COLOR_BUFFER_BIT);

	//glColor3f(0,0,1);

	glFlush();

}

void mousef(int b,int s,int x,int y)

{

	float t;

	y=h-y;

	if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN)

	{

		t=side/2.0;

		glColor3f(0,0,1);

		glBegin(GL_POLYGON);

			glVertex2f(x+t,y+t);

			glVertex2f(x+t,y-t);

			glVertex2f(x-t,y-t);

			glVertex2f(x-t,y+t);

		glEnd();

		glFlush();

	}

	if(b==GLUT_RIGHT_BUTTON && s==GLUT_DOWN)

	{	glClearColor(1,1,1,1);

		glClear(GL_COLOR_BUFFER_BIT);

		glFlush();

	}

	

}

void main()

{	

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(w,h);

	glutInitWindowPosition(300,150);

	glutCreateWindow("Menu");

	init();

	glutDisplayFunc(disp);

	glutMouseFunc(mousef);

	glutMainLoop();

}
