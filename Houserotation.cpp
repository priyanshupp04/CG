#include<stdio.h>
#include<math.h>
#include<gl/glut.h>

float xp,yp;
float td;
float p[9][2]={{10,10},{10,80},{50,90},{90,80},{90,10},{40,10},{40,30},{60,30},{60,10}};
int count=0;

void init()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(-300,300,-300,300);
	glMatrixMode(GL_MODELVIEW);
}

void displayhouse()
{
	unsigned int i;

	//glClearColor(1,1,1,1);
	//glClear(GL_COLOR_BUFFER_BIT);
		
	glColor3f(0,0,1);

	glBegin(GL_LINE_LOOP);
		for(i=0;i<5;i++)
			glVertex2fv(p[i]);
	glEnd();

	glBegin(GL_LINES);
		glVertex2fv(p[1]);
		glVertex2fv(p[3]);
		glVertex2fv(p[5]);
		glVertex2fv(p[6]);
		glVertex2fv(p[6]);
		glVertex2fv(p[7]);
		glVertex2fv(p[7]);
		glVertex2fv(p[8]);
	glEnd();
}

void disp()
{
	unsigned int i;

	if(count==0)
	{
		glClearColor(1,1,1,1);
		glClear(GL_COLOR_BUFFER_BIT);
		count++;
	}
	
	glColor3f(0,0,1);

	displayhouse();

	float x,y;
	float t=3.142/180*td;
	
	
	for(i=0;i<9;i++)
	{
		x = p[i][0] * cos(t)-p[i][1]*sin(t)+ xp * (1-cos(t)) + yp * sin(t);
		y = p[i][0] * sin(t)+p[i][1]*cos(t)+ yp * (1-cos(t)) - xp * sin(t);
		p[i][0] = x;
		p[i][1] = y;
	}

	glColor3f(0,1,0);

	glFlush();
}

void mouse(int b,int s,int x,int y)
{
	if(s==GLUT_DOWN)
		glutPostRedisplay();
}

void main()
{	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(300,150);
	glutCreateWindow("House Rotation");
	init();

	printf("Enter the value of xp,yp,theta\n");
	scanf("%f%f%f",&xp,&yp,&td);
	
	glutDisplayFunc(disp);
	glutMouseFunc(mouse);
		
	glutMainLoop();
}
