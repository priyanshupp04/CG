#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
float v[8][3] = {{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};
float p[8][3] = {{0,0,1},{0,1,1},{1,1,1},{1,0,1},{0,0,0},{0,1,0},{1,1,0},{1,0,0}};
float theta[3] = {0,0,0};
int flag = 2 ;

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4,4,-4,4,-4,4);
    glMatrixMode(GL_MODELVIEW);
     glEnable(GL_DEPTH_TEST);
}
void idle()
{
    theta[flag] += 0.1;
    if(theta[flag]>360)
        theta[flag]=0;
    glutPostRedisplay();
}
void mouse(int button , int status , int x ,int y)
{
    if(button==GLUT_LEFT_BUTTON && status==GLUT_DOWN)
        flag =2 ;
    if(button==GLUT_MIDDLE_BUTTON && status==GLUT_DOWN)
        flag =1 ;
    if(button==GLUT_RIGHT_BUTTON && status==GLUT_DOWN)
        flag=0;
}
void drawpoly(int a,int b,int c ,int d)
{
    glBegin(GL_POLYGON);
    glColor3fv(p[a]);
    glVertex3fv(v[a]);
    glColor3fv(p[b]);
    glVertex3fv(v[b]);
    glColor3fv(p[c]);
    glVertex3fv(v[c]);
    glColor3fv(p[d]);
    glVertex3fv(v[d]);
    glEnd();
}
void colorcube()
{
    drawpoly(0,1,2,3);
    drawpoly(4,5,6,7);
    drawpoly(0,1,5,4);
    drawpoly(1,5,6,2);
    drawpoly(0,4,7,3);
    drawpoly(3,2,6,7);
}

void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
    glLoadIdentity();
    glRotatef(theta[0],1,0,0);
    glRotatef(theta[1],0,1,0);
    glRotatef(theta[2],0,0,1);
    colorcube();

    glutSwapBuffers();
}
int main(int argc , char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("CUBE ROTATION");
    myinit();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    glutMainLoop();
}