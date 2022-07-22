#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>

float xmin=-0.5,ymin=-0.5,xmax=0.5,ymax=0.5;
float x1=-0.8,Y1=-0.6,x2=0.6,y2=0.8;
int clipflag=0,flag=1;
int c1,c2;
int left=1,right=2,bot=4,top=8;

int getcode(float x ,float y)
{
    int code = 0 ;
    if(x<xmin)
        code = code|left ;
    if(x>xmax)
        code = code|right;
    if(y<ymin)
        code = code|bot;
    if(y>ymax)
        code = code|top;
    return code;
}
void clip()
{
    float x , y ;
    int c ;
    if(c1)
        c = c1 ;
    else
        c = c2 ;
    if(c & left)
    {
        x = xmin ;
        y = Y1 + (y2-Y1)*((xmin-x1)/(x2-x1));
    }
    if(c&right)
    {
        x = xmax ;
        y = Y1 +(y2-Y1)*((xmax-x1)/(x2-x1));
    }
    if(c & bot)
    {
        y = ymin ;
        x = x1 + (x2-x1)*((ymin-Y1)/(y2-Y1));
    }
    if(c & top)
    {
        y=ymax ;
        x=x1 + (x2-x1)*((ymax-Y1)/(y2-Y1));
    }
    if(c=c1)
    {
        x1 = x ;
        Y1 = y ;
    }
    else
    {
        x2 =x;
        y2 =y;
    }


}
void draw()
{
    float x,y;
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
    glEnd();

    glColor3f(1,1,0);
    if(flag==1)
    {
        glBegin(GL_LINES);
        glVertex2f(x1,Y1);
        glVertex2f(x2,y2);
        glEnd();
    }
    while(1 && clipflag==1)
    {
        c1 = getcode(x1,Y1);
        c2 = getcode(x2,y2);

        if((c1|c2)==0)
            break;
        else if((c1&c2)!=0)
        { flag = 0; break;}
        else
            clip();
    }
    glFlush();
}

void key(unsigned char ch, int x ,int y)
{
    clipflag = 1 ;
    glutPostRedisplay();
}
int main(int argc , char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Cohen Sutherland");
   // myinit();
    glutDisplayFunc(draw);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}