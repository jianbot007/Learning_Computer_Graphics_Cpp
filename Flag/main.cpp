#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cmath> // GLUT, include glu.h and gl.h

void Bangladesh(){
     glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 1.0f, 0.0f); // Red

    glVertex2d(-10, 6);    // x, y
    glVertex2d(-2, 6);
    glVertex2d(-2, 0);
    glVertex2d(-10, 0);    // x, y


    glEnd();
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0; i<200; i++)
    {
        glColor3f(1.0,0,0.0);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=1.4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-6,y+3 );
    }

    glEnd();
    glBegin(GL_LINE_LOOP);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // Red

    glVertex2d(7, 12.13);    // x, y
    glVertex2d(14.37, 12.5);
    glVertex2d(14.33, 7.37);
    glVertex2d(7.09, 7.54);
    // x, y


    glEnd();
}

void Japan(){
glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // Red

    glVertex2d(7, 12.13);    // x, y
    glVertex2d(14.37, 12.5);
    glVertex2d(14.33, 7.37);
    glVertex2d(7.09, 7.54);
    // x, y


    glEnd();
//	drawCircle(11.07,9.82,1.47);
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0; i<200; i++)
    {
        glColor3f(1.0,0,0.0);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=1.4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+10.5,y+10 );
    }

    glEnd();
}
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(1.5);

   // Bangladesh();
    Japan();




    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // Red

    glVertex2d(8,4);    // x, y
    glVertex2d(12.2,3.9);
    glVertex2d(12.24,2.98);
    glVertex2d(8,3);
    glEnd();


    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f); // Red

    glVertex2d(-14,-8);    // x, y
    glVertex2d(-2.64,-8);
    glVertex2d(-2.72,-11.35);
    glVertex2d(-14.06,-11.27);
    glEnd();

    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(-14.06,-11.27);
    glVertex2d(-2.72,-11.35);
    glVertex2d(-2.62,-14.68);
    glVertex2d(-14.12,-14.68);
    glEnd();

    glBegin(GL_LINE_LOOP);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // Red

    glVertex2d(-14,-8);    // x, y
    glVertex2d(-2.64,-8);
    glVertex2d(-2.72,-11.35);
    glVertex2d(-14.06,-11.27);
    glEnd();

    glBegin(GL_LINE_LOOP);          // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(-14.06,-11.27);
    glVertex2d(-2.72,-11.35);
    glVertex2d(-2.62,-14.68);
    glVertex2d(-14.12,-14.68);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f); // Red

    glVertex2d(-14,-8);    // x, y
    glVertex2d(-2.64,-8);
    glVertex2d(-2.72,-11.35);
    glVertex2d(-14.06,-11.27);
    glEnd();

    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(-14.06,-11.27);
    glVertex2d(-2.72,-11.35);
    glVertex2d(-2.62,-14.68);
    glVertex2d(-14.12,-14.68);
    glEnd();


    //Ireland
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(0,255,0); // Red

    glVertex2d(-6.61845,10.70625);    // x, y
    glVertex2d(-5.14298,10.66154);
    glVertex2d(-5.09827,8.64955);
    glVertex2d(-6.57373,8.78368);
    glEnd();

    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
    glColor3ub(255,255,255); // Red

    glVertex2d(-5.14298,10.66154);
    glVertex2d(-3.84636,10.66154);
    glVertex2d(-3.84636,8.69426);
    glVertex2d(-6.57373,8.78368);
    glEnd();


    glBegin(GL_QUADS);          // Each set of 4 vertices form a quad
     glColor3ub(229,163,255);
    glVertex2d(-3.84636,10.66154);
    glVertex2d(-2.54975,10.66154);
    glVertex2d(-2.59446,8.64955);
    glVertex2d(-2.59446,8.64955);
    glEnd();


    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(720, 720);
    glutCreateWindow("Square & Rectangle"); // Create a window with the given title
    // Set the window's initial width & height
    glutDisplayFunc(display);
    gluOrtho2D(-20,20,-20,20);// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
