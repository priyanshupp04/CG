#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
GLfloat p[3][2]={{20,20},{40,40},{60,20}};
GLfloat xp,yp,theta,rtheta;
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
}
void drawtraingle()
{
    glBegin(GL_TRIANGLES);
    glVertex2fv(p[0]);
    glVertex2fv(p[1]);
    glVertex2fv(p[2]);
    glEnd();
    glFlush();
}
void display()
{
    float x,y;
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    drawtraingle();
    rtheta = (theta*3.14)/180;
    for(int i = 0 ; i<3; i++)
    {
        x=p[i][0];
        y=p[i][1];
        p[i][0] = xp + (x-xp)*cos(rtheta)-(y-yp)*sin(rtheta);
        p[i][1] = xp + (x-xp)*sin(rtheta)+(y-yp)*cos(rtheta);
    }
    glColor3f(0,1,1);
    drawtraingle();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    cout<<"Enter the xp,yp,thetha value"<<endl;
    cin>>xp>>yp>>theta;
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Triangle Rotation");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}