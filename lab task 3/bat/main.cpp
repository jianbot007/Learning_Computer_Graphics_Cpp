#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cmath> // GLUT, include glu.h and gl.h
void vat(){
glBegin(GL_POLYGON);

glColor3f(0.0f, 0.0f, 0.0f);


    glVertex2d(-3.22,1.58);
    glVertex2d(-1.02,1.56);
    glVertex2d(0,1);



    glVertex2d(1.18,1.62);
    glVertex2d(3.4,1.6);
    glVertex2d(2.42,0.28);
    glVertex2d(0.08,-0.62);

    glVertex2d(-2.26,0.28);


glEnd();
}

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
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

void circles(){
circle(1.5, -3.32, 0.58, 255,255,255);
circle(1.6, -1.1, -1.4, 255,255,255);
circle(1.3, 1.66, -0.9, 255,255,255);
circle(1.19, 3.58, 0.66, 255,255,255);
circle(1 ,0.3, 2, 255,255,255);
circle(0.3,0.27, 1, 0,0,0);
}

void Line(){
glBegin(GL_LINES);

glColor3f(0.0f, 0.0f, 0.0f);




glVertex2d(0.16,1.2);
glVertex2d(0.16,1.43324);

glVertex2d(0.36,1.2);
glVertex2d(0.36,1.43324);




glEnd();

}


 void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(1.5);


vat();
circles();
Line();




    glFlush();  // Render now
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(720, 720);
    glutCreateWindow("Bat"); // Create a window with the given title
    // Set the window's initial width & height
    glutDisplayFunc(display);
    gluOrtho2D(-6,6,-6,6);// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
