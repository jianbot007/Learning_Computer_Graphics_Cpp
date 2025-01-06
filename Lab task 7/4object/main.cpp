#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
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
void triangle();
void rectangle();
void circle1();

void display4(int a){
glutDisplayFunc(rectangle);
  glutPostRedisplay();

}

void circle2(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

           circle(3,0,0,1,0,0);

           glFlush();
           glutTimerFunc(500,display4,0);
}

void display3(int a){
 glutDisplayFunc(circle2);
  glutPostRedisplay();

}

void circle1(){
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

           circle(3,0,0,1,0,0);

           glFlush();
           glutTimerFunc(500,display3,0);

}
void display1(int a)
{
  glutDisplayFunc(triangle);
  glutPostRedisplay();
}
void rectangle()
{
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
           glColor3f(1.0f, 1.0f, 0.0f);
           glVertex2f(0.0f, 0.0f);
  glVertex2f(2.0f, 0.0f);
  glVertex2f(2.0f, 3.0f);
  glVertex2f(0.0f, 3.0f);
           glEnd();
           glFlush();
           glutTimerFunc(500,display1,0);
}
void display2(int a)
{
  glutDisplayFunc(circle1);
  glutPostRedisplay();
}

void triangle()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
           glColor3f(0.5f, 0.0f, 1.0f);
           glVertex2f(0.0f, 0.0f);
  glVertex2f(2.0f, 0.0f);
  glVertex2f(2.0f, 3.0f);
           glEnd();
           glFlush();
           glutTimerFunc(500,display2,0);
}

void display() {

           rectangle();

}




int main(int argc, char** argv) {
           glutInit(&argc, argv);
           glutCreateWindow("4 object");
           glutInitWindowSize(320, 320);
           glutDisplayFunc(display);
           gluOrtho2D(-10,10,-10,10);
           glutMainLoop();
           return 0;
}

