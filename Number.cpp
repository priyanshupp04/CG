//prog to display number of any digit

#include<stdlib.h>

#include<GL\glut.h>

#include<stdio.h>

#include<string.h>

#include<math.h>

int n;

void myinit()

{

	glMatrixMode(GL_PROJECTION);	glLoadIdentity();

	gluOrtho2D(0,100,0,100);

	glMatrixMode(GL_MODELVIEW);

}

void display()

{

		int i;

		char str[20];

		glClearColor(1,1,1,1);

		glClear(GL_COLOR_BUFFER_BIT);

		_itoa_s(n,str,10);//converting integer to its acscii and storing it in string str

		//counting the num of digits

		

		glColor3f(0,1,0);//defining the color of the primitive here its num

		glRasterPos2f(10,90);

		for(i=0;i<strlen(str);i++)

		{

			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);

		}

		

		glFlush();

}

int main()

{

		glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

		glutInitWindowPosition(100,100);

		glutInitWindowSize(500,500);

		glutCreateWindow("N DIGIT NUMBER");

		printf("Enter a num");

		scanf_s("%d",&n);//accepting the number

		myinit();

		glutDisplayFunc(display);

		glutMainLoop();

}
