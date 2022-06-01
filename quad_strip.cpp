#include<GL/glut.h>

float v[4][2] = {{25,25},{50,25},{25,50},{50,50}};
float u[4][2] = {{50,50},{75,50},{50,75},{75,75}};

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,100,0,100);
	glMatrixMode(GL_MODELVIEW);
}

void disp1()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
		glBegin(GL_QUAD_STRIP);
			glVertex2fv(v[0]);
			glVertex2fv(v[1]);
			glVertex2fv(v[2]);
			glVertex2fv(v[3]);
			glVertex2fv(u[0]);
			glVertex2fv(u[1]);
			glVertex2fv(u[2]);
			glVertex2fv(u[3]);
		glEnd();
	glFlush();
}

void main()
{	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(300,150);
	glutCreateWindow("Triangle");
	myinit();
	glutDisplayFunc(disp1);
	glutMainLoop();
}
