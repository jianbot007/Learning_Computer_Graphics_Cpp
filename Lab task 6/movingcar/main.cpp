#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

float _move = 0.0f;
float _angle1 = 0.0f;

// Function to draw a filled circle
void circle(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_POINTS);
    for (int i = 0; i < 200; i++) {
        glColor3f(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float x = radius * cos(A);
        float y = radius * sin(A);

        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

// Function to draw a car
void car() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-1.5f, 1.0f);
    glVertex2f(1.5f, 1.0f);
    glVertex2f(2.0f, -0.5f);
    glVertex2f(-2.0f, -0.5f);
    glEnd();
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, 2.0f);
    glVertex2f(1.01f, 2.0f);
    glVertex2f(0.83f, 1.0f);
    glVertex2f(-.7f, 1.0f);
    glEnd();
    // Draw wheels

}

void wheel (){

glPushMatrix();
    glTranslatef(-1.0f, -0.7f, 0.0f);
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);
    circle(0.5, 0.0, 0.0, 1.0, 1.0, 0.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1.0f, -0.7f, 0.0f);
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);
    circle(0.5, 0.0, 0.0, 1.0, 1.0, 0.0);
    glPopMatrix();
}

void update1(int value) {
_angle1+=2.0f;
if(_angle1 > 360.0)
{
_angle1-=360;
}
glutPostRedisplay(); //Notify GLUT that the display has changed



glutTimerFunc(20, update1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update(int value) {
_move += .2;
if(_move > 7)
{
_move = -7.0;
}
glutPostRedisplay();
glutTimerFunc(20, update, 0);
}

// Display function
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move, 0.0f, 0.0f);
    car();
    wheel();
    glPopMatrix();
    glutSwapBuffers(); // Swap the buffers to display the content
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Moving Car");
    gluOrtho2D(-6, 6, -6, 6);
     glutTimerFunc(20, update1, 0);
     glutTimerFunc(20, update, 0);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
