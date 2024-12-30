#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
using namespace std;


float _move1 = 0.0f;
float _move = 0.0f;
void drawScene() {
glClear(GL_COLOR_BUFFER_BIT);
glColor3d(1,0,0);
glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);



 glPushMatrix();
glTranslatef(_move, 0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(-0.5f, 0.1f);
glVertex2f(-0.5f, 0.0f);
glVertex2f(-0.4f, 0.0f);
glVertex2f(-0.4f, 0.1f);
glEnd();
glPopMatrix();



glColor3d(0,1,0);
glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);



 glPushMatrix();
glTranslatef(_move1, 0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.6f, 0.1f);
glVertex2f(0.7f, 0.1f);
glVertex2f(0.7f, 0.0f);
glVertex2f(0.6f, 0.0f);
glEnd();
glPopMatrix();


glutSwapBuffers();
}



void update(int value) {



 _move += .02;
if(_move > 1.0)
{
_move = 0.0;
}

_move1 -= .02;
if(_move1 < -1.0)
{
_move1 = 0.0;
}
glutPostRedisplay();
glutTimerFunc(20, update, 0);
}



int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(800, 800);
glutCreateWindow("Transformation");
glutDisplayFunc(drawScene);
gluOrtho2D(-2,2,-2,2);
glutTimerFunc(20, update, 0); //Add a timer
glutMainLoop();
return 0;
}
