#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cmath> // GLUT, include glu.h and gl.h

void TriangleofLamp(){

 glBegin(GL_POLYGON);

    glColor3ub(255, 255, 0 );

    glVertex2d(-7.0,6.0);
    glVertex2d(-6.0,6.0);
    glVertex2d(-6.72044,5.3);

    glEnd();
}

void BodyLamp(){

 glBegin(GL_POLYGON);

    glColor3ub(52, 152, 219);

    glVertex2d(-7.66,6.66);
    glVertex2d(-6.0,6.66);
    glVertex2d(-6.0,6.0);
    glVertex2d(-7.0,6.0);
    glVertex2d(-7.1,6.47);
    glVertex2d(-7.68,6.47);
    glVertex2d(-8.8,6.5);



    glEnd();
}

void BottomLamp(){

 glBegin(GL_QUADS);

    glColor3ub(52, 152, 219);

     glVertex2d(-8.6,-2.0);
     glVertex2d(-8.0,-2.0);
    glVertex2d(-8.0,-2.45);
    glVertex2d(-8.6,-2.45);




    glEnd();
}

void LineLamp(){

 glBegin(GL_LINES);


    glColor3ub(52, 152, 219);

    glVertex2d(-8.2,6.5);
    glVertex2d(-8.2,-2.0);


    glEnd();
}


void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(3);


TriangleofLamp();
BodyLamp();
BottomLamp();
LineLamp();




    glFlush();  // Render now
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(720, 720);
    glutCreateWindow("LampPOst"); // Create a window with the given title
    // Set the window's initial width & height
    glutDisplayFunc(display);
    gluOrtho2D(-15,15,-15,15);// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
