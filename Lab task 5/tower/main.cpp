#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cmath> // GLUT, include glu.h and gl.h

void Ground()
{

    glBegin(GL_LINE_LOOP);

    glColor3ub(0,0,0);
    glVertex2f(-4,-4);
    glVertex2f(-0.97,-2.5);
    glVertex2f(-0.0,-2.4);
    glVertex2f(0.78,-2.5);
    glVertex2f(4,-4);

    glEnd();
}

void Ground2()
{

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);

    glVertex2f(-6,-4);
    glVertex2f(6,-4);

    glEnd();
}

void Rectangle()
{


    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);

    glVertex2f(-0.14,-0.8);
    glVertex2f(0.18,-0.8);
    glVertex2f(0.23,-2.4);
    glVertex2f(-0.2,-2.4);

    glEnd();

}

void InnerRectangle1()
{


    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);

    glVertex2f(-0.0,-0.88);
    glVertex2f(0.064,-0.88);
    glVertex2f(0.078,-1.02);
    glVertex2f(-0.018,-1.02);

    glEnd();

}
void InnerRectangle2()
{


    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);

    glVertex2f(-0.0,-1.84);
    glVertex2f(0.064,-1.84);
    glVertex2f(0.078,-2.00);
    glVertex2f(0.0,-2.0);

    glEnd();

}

void TOPRectangle1()
{


    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);


    glVertex2f(0.23,-0.55);
    glVertex2f(-0.16,-0.55);
    glVertex2f(-0.14,-0.8);
    glVertex2f(0.18,-0.8);

    glEnd();

}

void TOPT()
{

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);


    glVertex2f(0.023,-0.0998);
    glVertex2f(-0.15,-0.31);
    glVertex2f(0.21,-0.31);

    glEnd();

}

void TOPR()
{
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);


    glVertex2f(-0.085,-0.31);
    glVertex2f(0.13,-0.31);
    glVertex2f(0.13,-0.55);
    glVertex2f(-0.093,-0.55);


    glEnd();

}

void Lines(){
 glBegin(GL_LINES);
    glColor3ub(0,0,0);


    glVertex2f(0.023,0.03457);
    glVertex2f(0.023,-0.0998);


    glVertex2f(-0.18,-0.64);
    glVertex2f(0.22,-0.64);


    glVertex2f(-0.18,-0.695);
    glVertex2f(0.22,-0.695);


    glEnd();


}

void Top()
{
    TOPR();
    TOPT();

}

LineTOP(){

 glBegin(GL_LINES);
    glColor3ub(0,0,0);


    glVertex2f(-2.00857,-0.06395);
    glVertex2f(-0.34323,-0.39303);


    glVertex2f(-2.37753,-0.50);
    glVertex2f(-0.37314,-0.50);


    glVertex2f(-2,-1);
    glVertex2f(-0.37314,-0.66481);

     glVertex2f(0.45023,-0.37306);
    glVertex2f(2.11641,-0.07483);

     glVertex2f(0.5,-0.5);
    glVertex2f(2.5,-0.5);

     glVertex2f(0.48264,-0.65184);
    glVertex2f(2.11641,-0.96952);


    glEnd();


}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(3);


    Rectangle();
    Ground();
    Ground2();
    InnerRectangle1();
    InnerRectangle2();
    TOPRectangle1();
    Top();
    Lines();
    LineTOP();
    glFlush();
     // Render now
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(720, 720);
    glutCreateWindow("TOWER"); // Create a window with the given title
    // Set the window's initial width & height
    glutDisplayFunc(display);
    gluOrtho2D(-6,6,-6,4 );// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
