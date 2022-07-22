#include <iostream>
using namespace std;
#include <GL/glut.h>
#include <GL/glu.h>
int le[500], re[500];

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

void intersection(int x1, int y1, int x2, int y2)
{
    int x, y, t, m;
    if (y1 > y2)
    {
        t = y1;
        y1 = y2;
        y2 = t;
        t = x1;
        x1 = x2;
        x2 = t;
    }
    if ((y2 - y1) == 0)
        m = x2 - x1;
    else
        m = (x2 - x1) / (y2 - y1);
    x = x1;
    for (y = y1; y <= y2; y++)
    {
        if (x < le[y])
            le[y] = x;
        if (x > re[y])
            re[y] = x;

        x = x + m;
    }
}

void draw()
{
    int x, y;
    int p1[2] = {125, 250}, p2[2] = {250,125}, p3[2] = {375,250}, p4[2] = {250,375};
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i < 500; i++)
    {
        le[i] = 500;
        re[i] = 0;
    }
    glBegin(GL_LINE_LOOP);
    glVertex2iv(p1);
    glVertex2iv(p2);
    glVertex2iv(p3);
    glVertex2iv(p4);
    glEnd();

    intersection(p1[0], p1[1], p2[0], p2[1]);
    intersection(p2[0], p2[1], p3[0], p3[1]);
    intersection(p3[0], p3[1], p4[0], p4[1]);
    intersection(p4[0], p4[1], p1[0], p1[1]);

    for (y = 0; y < 500; y++)
        {
            for (x = le[y]; x < re[y]; x++)
            {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                glEnd();
                glFlush();
            }
        }
    

    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Scan Line");
    myinit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}