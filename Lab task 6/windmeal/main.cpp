#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;
float _angle1 = 0.0f;
void windmealbody()
{

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f, -6.0f);
    glVertex2f(-0.6f, -6.0f);
    glEnd();

}

void pakha()
{
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 4.0f);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(3.5f, -1.0f);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-3.6f, -1.26f);
    glEnd();


}

void update1(int value)
{
    angle1+=2.0f;
    if(_angle1 > 360.0)
    {
        _angle1-=360;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed

    glutTimerFunc(20, update1, 0); //Notify GLUT to call update again in 25 milliseconds
}


void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    windmealbody();
    glPushMatrix();
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);

    pakha();
    glPopMatrix();
    glutSwapBuffers(); // Swap the buffers to display the content
}



// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("windMill");
    gluOrtho2D(-6, 6, -6, 6);
    glutTimerFunc(20, update1, 0);

    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
