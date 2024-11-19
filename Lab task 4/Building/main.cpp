#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cmath> // GLUT, include glu.h and gl.h


void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0; i<200; i++)
    {
        glColor3f(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+xc,y+yc);
    }
    glEnd();
}

void TOP()
{

    glBegin(GL_POLYGON);

    glColor3ub(52, 73, 94);

    glVertex2d(-4,6);
    glVertex2d(0,8);
    glVertex2d(4,6);

    glEnd();



}
void Rectangle()
{

    glBegin(GL_QUADS);

    glColor3ub(153, 163, 164);

    glVertex2d(-2,6);
    glVertex2d(2,6);
    glVertex2d(2,-4);
    glVertex2d(-2,-4);



    glEnd();



}

void BuildingLine()
{

    glBegin(GL_LINE_LOOP);

    glColor3ub(0,0,0);

    glVertex2d(-2,6);
    glVertex2d(2,6);
    glVertex2d(2,-4);
    glVertex2d(-2,-4);



    glEnd();



}
void Door()
{

    glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2d(-0.8237,-2.4);
    glVertex2d(0.52269,-2.4);
    glVertex2d(0.52269,-3.97944);
    glVertex2d(-0.8237,-3.97944);

    glEnd();
}

void DoorLine()
{

    glBegin(GL_LINE_LOOP);

    glColor3ub(255,255,255);

    glVertex2d(-0.8237,-2.4);
    glVertex2d(0.52269,-2.4);
    glVertex2d(0.52269,-3.97944);
    glVertex2d(-0.8237,-3.97944);

    glEnd();



}
void Line4()
{
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);

    glVertex2d(-2,4);
    glVertex2d(2,4);

    glEnd();

}
void Line1()
{
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);

    glVertex2d(-2,2);
    glVertex2d(2,2);

    glEnd();

}
void Line2()
{
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);

    glVertex2d(-2,0);
    glVertex2d(2,0);

    glEnd();

}
void Line3()
{
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);

    glVertex2d(-2,-2);
    glVertex2d(2,-2);

    glEnd();

}


void window1()
{
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);

    glVertex2d(-0.56,3.36);
    glVertex2d(0.63,3.36);
    glVertex2d(0.63,2.57);
    glVertex2d(-0.56,2.57);

    glEnd();

}
void Windowline1(){
 glBegin(GL_LINE_LOOP);

    glColor3ub(255,255,255);

    glVertex2d(-0.56,3.36);
    glVertex2d(0.63,3.36);
    glVertex2d(0.63,2.57);
    glVertex2d(-0.56,2.57);



    glEnd();
    }

void windows1(){
    window1();
    Windowline1();
}


void window2()
{
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);

    glVertex2d(-0.56,1.31);
    glVertex2d(0.63,1.31);
    glVertex2d(0.63,0.6);
    glVertex2d(-0.56,0.6);

    glEnd();

}
void Windowline2(){
 glBegin(GL_LINE_LOOP);

    glColor3ub(255,255,255);

   glVertex2d(-0.56,1.31);
    glVertex2d(0.63,1.31);
    glVertex2d(0.63,0.6);
    glVertex2d(-0.56,0.6);



    glEnd();
    }

void windows2(){
    window2();
    Windowline2();
}

void window3()
{
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);

    glVertex2d(-0.56,5.24);
    glVertex2d(0.63,5.24);
    glVertex2d(0.63,4.5);
    glVertex2d(-0.56,4.5);

    glEnd();

}
void Windowline3(){
 glBegin(GL_LINE_LOOP);

    glColor3ub(255,255,255);

    glVertex2d(-0.56,5.24);
    glVertex2d(0.63,5.24);
    glVertex2d(0.63,4.5);
    glVertex2d(-0.56,4.5);

    glEnd();
    }

void windows3(){
    window3();
    Windowline3();
}





void window4()
{
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);

    glVertex2d(-0.56,-0.62);
    glVertex2d(0.63,-0.62);
    glVertex2d(0.63,-1.35);
    glVertex2d(-0.56,-1.35);

    glEnd();

}
void Windowline4(){
 glBegin(GL_LINE_LOOP);

    glColor3ub(255,255,255);

    glVertex2d(-0.56,-0.62);
    glVertex2d(0.63,-0.62);
    glVertex2d(0.63,-1.35);
    glVertex2d(-0.56,-1.35);

    glEnd();
    }

void windows4(){
    window4();
    Windowline4();
}
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(1);


  Rectangle();
  BuildingLine();
  Door();DoorLine();
  Line1();Line2();Line3();Line4();
  windows1();
  windows2();
  windows3();
  windows4();
  TOP();




    glFlush();  // Render now
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(720, 720);
    glutCreateWindow("Building"); // Create a window with the given title
    // Set the window's initial width & height
    glutDisplayFunc(display);
    gluOrtho2D(-6,6,-6,8 );// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
