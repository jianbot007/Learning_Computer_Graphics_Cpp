#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cmath> // GLUT, include glu.h and gl.h

void Board1(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // Red

    glVertex2d(-2, 4);
    glVertex2d(-1, 4);
    glVertex2d(-1, 3);
    glVertex2d(-2, 3);


    glEnd();
}
void Board2(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // Red

    glVertex2d(-1,4);
    glVertex2d(0, 4);
    glVertex2d(0, 3);
    glVertex2d(-1, 3);


    glEnd();
}
void Board3(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // Red

    glVertex2d(0,4);
    glVertex2d(1, 4);
    glVertex2d(1, 3);
    glVertex2d(0, 3);


    glEnd();
}
void Board4(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // Red

    glVertex2d(1,4);
    glVertex2d(2, 4);
    glVertex2d(2, 3);
    glVertex2d(1, 3);


    glEnd();
}
void Board5(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // Red

    glVertex2d(1,3);
    glVertex2d(2, 3);
    glVertex2d(2, 2);
    glVertex2d(1, 2);


    glEnd();
}

void Board6(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // Red

    glVertex2d(0,3);
    glVertex2d(1, 3);
    glVertex2d(1, 2);
    glVertex2d(0, 2);


    glEnd();
}

void Board7(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // Red

    glVertex2d(-1,3);
    glVertex2d(0, 3);
    glVertex2d(0, 2);
    glVertex2d(-1, 2);


    glEnd();
}
void Board8(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // Red

    glVertex2d(-2,3);
    glVertex2d(-1, 3);
    glVertex2d(-1, 2);
    glVertex2d(-2, 2);


    glEnd();
}

//row2

void Board9(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // Red

    glVertex2d(-2,2);
    glVertex2d(-1, 2);
    glVertex2d(-1, 1);
    glVertex2d(-2, 1);


    glEnd();
}

void Board10(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // Red

    glVertex2d(-1,2);
    glVertex2d(0, 2);
    glVertex2d(-0, 1);
    glVertex2d(-1, 1);


    glEnd();
}
void Board11(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // Red

    glVertex2d(0,2);
    glVertex2d(1, 2);
    glVertex2d(1, 1);
    glVertex2d(0, 1);


    glEnd();
}
void Board12(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // Red

    glVertex2d(1,2);
    glVertex2d(2, 2);
    glVertex2d(2, 1);
    glVertex2d(1, 1);


    glEnd();
}
void Board13(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // Red

    glVertex2d(1,1);
    glVertex2d(2, 1);
    glVertex2d(2, 0);
    glVertex2d(1, 0);


    glEnd();
}
void Board14(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // Red

    glVertex2d(0,1);
    glVertex2d(1, 1);
    glVertex2d(1, 0);
    glVertex2d(0, 0);


    glEnd();
}
void Board15(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // Red

    glVertex2d(-1,1);
    glVertex2d(0, 1);
    glVertex2d(0, 0);
    glVertex2d(-1, 0);


    glEnd();
}
void Board16(){
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // Red

    glVertex2d(-2,1);
    glVertex2d(-1, 1);
    glVertex2d(-1, 0);
    glVertex2d(-2, 0);


    glEnd();
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(1.5);

    Board1();
    Board2();
    Board3();
    Board5();
    Board6();
    Board7();
    Board8();
    Board9();
    Board10();
    Board11();
    Board12();
    Board13();Board14();Board15();Board16();





    glFlush();  // Render now
}





/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(720, 720);
    glutCreateWindow("4 shapes"); // Create a window with the given title
    // Set the window's initial width & height
    glutDisplayFunc(display);
    gluOrtho2D(-6,6,-6,6);// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
