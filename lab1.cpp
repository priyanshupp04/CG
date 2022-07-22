#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
int xx,yy,xend,yend;

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}
void setpixel(int x ,int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}
void bresenham()
{
    int dx = fabs(xend-xx);
    int dy = fabs(yend-yy);
    int x ,y,p;
    x = xx , y=yy ;
    glColor3f(1,0,0);glPointSize(3);
    if(dx>dy)
    {
       //if m<1
       p = 2*dy-dx;
       setpixel(x,y);
       while(x<xend)
       {
            x = x+1 ;
            if(p<0)
                p = p + 2*dy ;
            else{
                y = y+1;
                p = p + 2*dy - 2*dx ;
            }
            setpixel(x,y);
            //cout<<x<<"\t"<<y<<endl;
       }
    }
    else{
        p = 2*dx-dy;
        setpixel(x,y);
        while(y<yend)
        {
            y = y+1 ;
            if(p<0)
                p = p + 2*dx ;
            else
            {
                 x = x+1 ;
                p = p+2*dx-2*dy;
            }
            setpixel(x,y);
            //cout<<x<<"\t"<<y;
        }
    }

    
}
void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    bresenham();
    glFlush();
}
int main(int argc ,char**argv)
{
    glutInit(&argc,argv);
    cout<<"Enter the first points"<<endl;
    cin>>xx>>yy;
    cout<<"Enter the second points"<<endl;
    cin>>xend>>yend;
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Bresenham");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}