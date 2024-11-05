#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cmath> // GLUT, include glu.h and gl.h

void object(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f); // Red

    glVertex2d(-1, 2);
    glVertex2d(1, 2);
    glVertex2d(2, -1);
    glVertex2d(-2, -1);

    glEnd();
}


void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(1.5);

    object();



    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(720, 720);
    glutCreateWindow("Object"); // Create a window with the given title
    // Set the window's initial width & height
    glutDisplayFunc(display);
    gluOrtho2D(-5,5,-5,5);// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
