#include<iostream>
using namespace std;
#include<GL/glut.h>
#include<GL/glu.h>

float Cx=0,Cy=0,Cz=3;
void myinit()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);
}
void square(float A[],float B[],float C[], float D[])
{
    glBegin(GL_POLYGON);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);
    glEnd();
    glFlush();
}
void cube(float v0[],float v1[],float v2[],float v3[],float v4[],float v5[],float v6[],float v7[])
{
    glColor3f(0,0,1);
    square(v0,v1,v2,v3);
    glColor3f(0,1,1);
    square(v0,v4,v7,v3);
    glColor3f(1,1,1);
    square(v1,v5,v6,v2);
    glColor3f(1,0,1);
    square(v0,v4,v5,v1);
    glColor3f(0,0,0);
    square(v4,v5,v6,v7);
    glColor3f(0,1,0);
    square(v3,v2,v6,v7);
}
void draw()
{
    float v[8][3]={{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(Cx,Cy,Cz,0,0,0,0,1,0);
    cube(v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]);
    glutSwapBuffers();
}
void key(unsigned char ch ,int x,int y)
{
    switch (ch)
    {
     case 'x': Cx = Cx-0.5 ; break;
     case 'X': Cx = Cx+0.5 ; break;

     case 'y':Cy = Cy-0.5 ; break ;
     case 'Y':Cy = Cy+0.5 ; break ;

     case 'z': Cz = Cz-0.5 ; break;
     case 'Z': Cz = Cz+0.5 ; break;
    }
    glutPostRedisplay();
}

int main(int argc , char*argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,150);
    glutCreateWindow("COLOR CUBE");
    myinit();
    glutDisplayFunc(draw);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
