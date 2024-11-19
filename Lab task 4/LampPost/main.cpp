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

void TOPTriangle()
{

    glBegin(GL_POLYGON);

    glColor3ub(93, 109, 126);

    glVertex2d(-0.58,0.74);
    glVertex2d(-0.1,1.24);
    glVertex2d(0.38,0.74);

    glEnd();

}

void TOPTriangleLine()
{

    glBegin(GL_LINE_LOOP);

    glColor3ub(255,255,255);

    glVertex2d(-0.58,0.74);
    glVertex2d(-0.1,1.24);
    glVertex2d(0.38,0.74);

    glEnd();

}
void BOXLIGHT()
{

    glBegin(GL_LINE_LOOP);

    glColor3ub(255,255,255);

    glVertex2d(0.14,0.02);
    glVertex2d(0.38,0.74);
    glVertex2d(-0.58,0.74);
      glVertex2d(-0.4,0);

    glEnd();

}

void LIGHT()
{

    glBegin(GL_POLYGON);

    glColor3ub(255, 255, 255);

    glVertex2d(0.14,0.02);
    glVertex2d(0.38,0.74);
    glVertex2d(-0.58,0.74);
      glVertex2d(-0.4,0);

    glEnd();

}
void Stand(){
glBegin(GL_POLYGON);

    glColor3ub(26, 82, 118 );

    glVertex2d(-0.2,0);
    glVertex2d(0.1,0);
    glVertex2d(0.1,-1.52);
      glVertex2d(-0.2,-1.52);

    glEnd();

}
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(2);

    TOPTriangle();
    TOPTriangleLine();
    BOXLIGHT();
    LIGHT();
    Stand();




    glFlush();  // Render now
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(720, 720);
    glutCreateWindow("Building"); // Create a window with the given title
    // Set the window's initial width & height
    glutDisplayFunc(display);
    gluOrtho2D(-6,6,-6,6 );// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
