#include<stdio.h>
#include<math.h>
#include<gl/glut.h>

void myinit()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	int i;
	float x1,x2,y1,y2,r1=15,r2=18,t;
	
	glColor3f(1,0,0);
	glBegin(GL_QUAD_STRIP);
		for(i=0;i<=24;i++)
		{
			t = 3.142/12 * i;
			x1 = r1*cos(t);
			y1 = r1*sin(t);
			x2 = r2*cos(t);
			y2 = r2*sin(t);
			glVertex2f(x1,y1);
			glVertex2f(x2,y2);
		}
	glEnd();

	glFlush();	
}


void main()
{	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(300,150);

	glutCreateWindow("Stroked O");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
