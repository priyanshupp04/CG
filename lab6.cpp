#include<GL/glut.h>
#include<GL/glu.h>

void myinit()
{
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
}

void draw()
{
    float pos[] = {0,1,0,1};
    float col[] = {1,1,1,1};
    float M[] ={0,1,0,1};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glLightfv(GL_LIGHT0,GL_POSITION,pos);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,M);
   
    gluLookAt(0,1,3,0,0,0,0,1,0);
    
    glPushMatrix();
    glScalef(1,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5,-0.5,-0.5);
    glScalef(0.05,1,0.05);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5,-0.5,0.5);
    glScalef(0.05,1,0.05);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-0.5,-0.5);
    glScalef(0.05,1,0.05);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-0.5,0.5);
    glScalef(0.05,1,0.05);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.25,0);
    glutSolidTeapot(0.25);
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc , char**argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Tea Pot");
    myinit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
