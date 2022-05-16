//PROGRAM TO DEMONSTRATE Keyboard FUNCTION. 

#include<stdio.h>
#include<gl/glut.h>

int w=640,h=480;
int sizef=0;

void init()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);
	glMatrixMode(GL_MODELVIEW);
}

void disp()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(250-sizef,250-sizef);
		glVertex2f(350+sizef,250-sizef);
		glVertex2f(350+sizef,350+sizef);
		glVertex2f(250-sizef,350+sizef);
	glEnd();
	glFlush();
}



void keyboard(unsigned char key,int x,int y)
{
	if(key=='i')
		sizef +=5;
	else if(key=='d')
		sizef -=5;
	else if(key=='r')
		sizef =0;
	else if(key=='q')
		exit(0);
	glutPostRedisplay();
}

void main()
{	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w,h);
	glutInitWindowPosition(300,150);
	glutCreateWindow("Menu");
	init();
	glutDisplayFunc(disp);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
