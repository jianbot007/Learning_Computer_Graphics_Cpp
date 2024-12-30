#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cmath> // GLUT, include glu.h and gl.h

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_LINE_LOOP);// Draw a Red 1x1 Square centered at origin
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


void mountain()
{

    glBegin(GL_LINE_LOOP);

    glVertex2f(0,1);

    glVertex2f(3.15,-2.7);
    glVertex2f(-3.15,-2.7);
    glEnd();
}

void Sun()
{


    circle(2.2,0,1,0,0,0);


}

void Ground()
{

    glBegin(GL_LINES);


    glVertex2f(5,-2.7);
    glVertex2f(-5,-2.7);
    glEnd();
}

void Lines()
{

    glBegin(GL_LINES);


    glVertex2f(-3.04,1.9);
    glVertex2f(-0.6,1.9);
    glEnd();

    glBegin(GL_LINES);


    glVertex2f(-2.57,0.8);
    glVertex2f(-1.48,0.8);
    glEnd();

    glBegin(GL_LINES);


    glVertex2f(1.30755,1.6);
    glVertex2f(2.39521,1.6);
    glEnd();


    glBegin(GL_LINES);


    glVertex2f(1.41632,0.8);
    glVertex2f(2.3,0.8);
    glEnd();

    glBegin(GL_LINES);


    glVertex2f(-0.7,0);
    glVertex2f(0,0);
    glEnd();

    glBegin(GL_LINES);


    glVertex2f(-1,-.8);
    glVertex2f(-0.3,-.8);
    glEnd();
    glBegin(GL_LINES);


    glVertex2f(-2.5,-2);
    glVertex2f(-0.5,-2);
    glEnd();


    glBegin(GL_LINES);


    glVertex2f(-2,-1.6);
    glVertex2f(-0.3,-1.6);
    glEnd();

}
void devide()
{
    glBegin(GL_LINES);

    glVertex2f(0,1);
    glVertex2f(0.4,-0.6);

    glVertex2f(0.4,-0.6);
    glVertex2f(0.0,-0.8);

    glVertex2f(0.0,-0.8);
    glVertex2f(-0.4,-1.2);

    glVertex2f(-0.4,-1.2);
    glVertex2f(0.0,-1.6);


    glVertex2f(0.0,-1.6);
    glVertex2f(-0.86776,-2.7);



    glEnd();
}

void Tree1(){

    glBegin(GL_LINES);
    glVertex2f(4,-1);
    glVertex2f(4,-2.7);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(4,-1);
    glVertex2f(4.6,-1.4);
    glVertex2f(3.4,-1.4);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(4,-1.2);
    glVertex2f(4.6,-1.6);
    glVertex2f(3.4,-1.6);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(4,-1.4);
    glVertex2f(4.6,-1.8);
    glVertex2f(3.4,-1.8);
    glEnd();



}


void Tree2(){

    glBegin(GL_LINES);

    glVertex2f(-4,-1);
    glVertex2f(-4,-2.7);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(-4,-1);
    glVertex2f(-4.6,-1.4);
    glVertex2f(-3.4,-1.4);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(-4,-1.2);
    glVertex2f(-4.6,-1.6);
    glVertex2f(-3.4,-1.6);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(-4,-1.4);
    glVertex2f(-4.6,-1.8);
    glVertex2f(-3.4,-1.8);
    glEnd();
}


void renderStrokeString(float x, float y, const char* text, float scale) {
    glPushMatrix();  // Save current state
    glTranslatef(x, y, 0);  // Move to position
    glScalef(scale, scale, 1.0f);  // Scale text
    while (*text) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *text);  // Render each character
        text++;
    }
    glPopMatrix();  // Restore state
}


void Text(){
renderStrokeString(-5.0, -5.0, "MOUNTAIN", 0.015);
    //renderBitmapString(-1.0f, -4.0f, "MOUNTAIN");
}


void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(3);

// mountain();
    Sun();
    mountain();
    Ground();
    Lines();
    devide();
    Tree1(); Tree2();
    Text();

    glFlush();  // Render now
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(720, 720);
    glutCreateWindow("Mountain"); // Create a window with the given title
    // Set the window's initial width & height
    glutDisplayFunc(display);
    gluOrtho2D(-6,6,-6,8 );// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
