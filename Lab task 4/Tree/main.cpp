#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cmath> // GLUT, include glu.h and gl.h



void Rectangle()
{

    glBegin(GL_QUADS);

    glColor3ub(110, 44, 0);

    glVertex2d(-1.0,-1.0);
    glVertex2d(0,-1.0);
    glVertex2d(0,-3);
    glVertex2d(-1,-3);



    glEnd();



}

void Triangle1()
{

    glBegin(GL_POLYGON);

    glColor3ub(30, 132, 73 );

    glVertex2d(-3.0,-1.0);
    glVertex2d(-0.46,0.48);
    glVertex2d(2,-1);

    glEnd();

}
void Triangle2()
{

    glBegin(GL_POLYGON);

    glColor3ub(20, 90, 50 );

    glVertex2d(-2.0,0);
    glVertex2d(-0.48,1.48);
    glVertex2d(1.0,0);

    glEnd();

}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(1.5);



    Rectangle();
    Triangle1();
    Triangle2();



    glFlush();  // Render now
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(720, 720);
    glutCreateWindow("Tree"); // Create a window with the given title
    // Set the window's initial width & height
    glutDisplayFunc(display);
    gluOrtho2D(-6,6,-6,6);// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
