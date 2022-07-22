#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>

float ya = 50 , xa = 10 ;
int yflag=1,xflag=1,aniflag=1;
void animate()
{
    if(aniflag==1)
    {
        if(ya>-50 && yflag==1)
            ya = ya -0.01;
        if(ya<=-50 && yflag==1)
            yflag=0;
        if(ya>=50 && yflag==0)
            yflag=1;
        if(ya<50 && yflag==0)
            ya = ya+0.01;

        if(xa>-10 && xflag==1)
            xa = xa -0.01;
        if(xa<=-10 && xflag==1)
            xflag=0;
        if(xa>=10 && xflag==0)
            xflag=1;
        if(xa<10 && xflag==0)
            xa = xa+0.01;
    }
    glutPostRedisplay();
}
void draw()
{
    GLfloat x[4],y1[4],y2[4];
    GLdouble xt[200],y1t[200],y2t[200];
    int i ,c;
    GLdouble t;
    glClear(GL_COLOR_BUFFER_BIT);

    x[0]=100;x[1]=200;x[2]=200;x[3]=300-xa;
    y1[0]=450;y1[1] = 450+ya ;y1[2]= 450-ya; y1[3] =450 ;
    y2[0]=400;y2[1]=400+ya; y2[2]=400-ya ; y2[3]=400;

    for(i=0,c=0,t=0;t<1;i++,t=t+0.01)
    {
        xt[i]= pow(1-t,3)*x[0]+3*pow(1-t,2)*t*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
        y1t[i]=pow(1-t,3)*y1[0]+3*pow(1-t,2)*t*y1[1]+3*pow(t,2)*(1-t)*y1[2]+pow(t,3)*y1[3];
        y2t[i]=pow(1-t,3)*y2[0]+3*pow(1-t,2)*t*y2[1]+3*pow(t,2)*(1-t)*y2[2]+pow(t,3)*y2[3];
        c++;
    }
    glColor3f(1,0.25,1);
    glBegin(GL_QUAD_STRIP);
    for(i = 0 ; i<c ; i++)
    {
        glVertex2d(xt[i],y1t[i]);
        glVertex2d(xt[i],y2t[i]);
    }
    glEnd();

    glColor3f(0,0.25,0);
    glRecti(90,460,100,50);
    glFlush();
}
void menu(int n)
{
    if(n==1)
        aniflag=1;
    if(n==2)
        aniflag=2;
    if(n==3)
        exit(0);
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);

    glutCreateMenu(menu);
    glutAddMenuEntry("start",1);
    glutAddMenuEntry("stop",2);
    glutAddMenuEntry("exit",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("bezierCurve");
    myinit();
    glutDisplayFunc(draw);
    glutIdleFunc(animate);
    glutMainLoop();
    return 0;
}