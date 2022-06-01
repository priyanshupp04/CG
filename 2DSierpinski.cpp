#include<stdio.h>
#include<string.h>
#include<gl/glut.h>

void myinit()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
}

void disp_tri(float v0[2],float v1[2],float v2[2])
{
	glBegin(GL_POLYGON);
		glVertex2fv(v0);
		glVertex2fv(v1);
		glVertex2fv(v2);
	glEnd();
}


void div_tri(float v0[2],float v1[2],float v2[2],int n)
{
	float a[2],b[2],c[2];
	int i;

	if(n>0)
	{
		for(i=0;i<2;i++)
		{
			a[i] = (v0[i] + v1[i])/2;
			b[i] = (v1[i] + v2[i])/2;
			c[i] = (v0[i] + v2[i])/2;
		}
		div_tri(v0,a,c,n-1);
		div_tri(a,v1,b,n-1);
		div_tri(b,c,v2,n-1);
	}
	else
		disp_tri(v0,v1,v2);
}

int c;

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	

	float v[3][2] = {{-25,-25},{0,25},{25,-25}};

	char str[]="2D Sierpinski Gasket";
	int i;

	glColor3f(0,0,1);
	glRasterPos2i(-20,40);
	for(i=0;i<strlen(str);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
	glColor3f(1,0,0);
	div_tri(v[0],v[1],v[2],c);
	glFlush();	
}

void main()
{	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(300,150);
	printf("Enter the number of subdivisions:\n");
	scanf("%d",&c);
	glutCreateWindow("2D Recursive Sierpinski");
	myinit();
	glutOverlayDisplayFunc(display);
	glutDisplayFunc(display);
	glutMainLoop();
}
