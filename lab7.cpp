#include<GL/glut.h>
#include<GL/glu.h>
#include<iostream>
using namespace std;
int N ;

void triangle(float A[],float B[] , float C[])
{
    glBegin(GL_TRIANGLES);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glEnd();
   
}
void tetra(float V1[],float V2[], float V3[], float V4[])
{
    glColor3f(1,1,1);
    triangle(V1,V2,V3);
    glColor3f(1,0,0);
    triangle(V1,V3,V4);
    glColor3f(0,1,0);
    triangle(V2,V3,V4);
    glColor3f(0,0,1);
    triangle(V1,V2,V4);
}
void mid(float ab[],float a[], float b[])
{
    for(int i = 0 ; i<3 ; i++)
        ab[i] = (a[i] + b[i])/2;
}
void div(float v1[],float v2[],float v3[],float v4[],int n)
{
    float v12[3],v13[3],v14[3],v23[3],v24[3],v34[3];
    if(n>0)
    {
        mid(v12,v1,v2);
        mid(v13,v1,v3);
        mid(v14,v1,v4);
        mid(v23,v2,v3);
        mid(v24,v2,v4);
        mid(v34,v3,v4);

        div(v1,v12,v13,v14,n-1);
        div(v12,v2,v23,v24,n-1);
        div(v13,v23,v3,v4,n-1);
        div(v14,v24,v34,v4,n-1);

    }
    else 
        tetra(v1,v2,v3,v4);
}
void draw()
{
    float p[4][3] = {{0,0.4,0.5},{-0.5,-0.5,0.5},{0.5,-0.5,0.5},{0,0,-0.5}};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity();
    div(p[0],p[1],p[2],p[3],N);
    glutSwapBuffers();
}

int main(int argc, char*argv[])
{
    cout<<"Enter the subdivision :"<<endl;
    cin>>N;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("SERPIENSKI");
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}