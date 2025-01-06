#include <windows.h>
#include <GL/glut.h>
void triangle();
void rectangle();
void display1(int a)
{
  glutDisplayFunc(triangle);
  glutPostRedisplay();
}
void rectangle()
{
  glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
           glColor3f(1.0f, 1.0f, 0.0f);
           glEnd();
           glFlush();
           glutTimerFunc(500,display1,0);
}
void display2(int a)
{
  glutDisplayFunc(rectangle);
  glutPostRedisplay();
}

void triangle()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
           glEnd();
           glFlush();
           glutTimerFunc(500,display2,0);
}

void display() {

           rectangle();

}



int main(int argc, char** argv) {
           glutInit(&argc, argv);
           glutCreateWindow("BackGround Change");
           glutInitWindowSize(320, 320);
           glutDisplayFunc(display);
           gluOrtho2D(-10,10,-10,10);
           glutMainLoop();
           return 0;
}


