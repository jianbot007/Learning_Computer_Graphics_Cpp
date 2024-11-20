#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cmath> // GLUT, include glu.h and gl.h
void RectangleofBench()
{

    glBegin(GL_POLYGON);

    glColor3ub(211, 84, 0  );

    glVertex2d(9.0,-0.6);
    glVertex2d(13.0,-0.6);
    glVertex2d(13.0,-0.8);
    glVertex2d(9.0,-0.8);

    glEnd();
}

void leg1()
{

    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    glVertex2d(9.8,-0.8);
    glVertex2d(10.0,-0.8);
    glVertex2d(10.0,-1.4);
    glVertex2d(9.8,-1.4);

    glEnd();
}

void leg2()
{

    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    glVertex2d(11.8,-0.8);
    glVertex2d(12.0,-0.8);
    glVertex2d(12.0,-1.38);
    glVertex2d(11.8,-1.38);

    glEnd();
}
void display()
{
    glClearColor(0.0f, 0.3f, 1.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(1);

RectangleofBench();
leg1();
leg2();




    glFlush();  // Render now
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(720, 720);
    glutCreateWindow("Bench"); // Create a window with the given title
    // Set the window's initial width & height
    glutDisplayFunc(display);
    gluOrtho2D(8,14,-4,0);// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
