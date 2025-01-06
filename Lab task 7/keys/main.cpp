#include <windows.h>
#include <GL/glut.h>
#include <math.h>

float positions[4][2] = {{0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}};
float _circle = 0.0f;
float _circle2 = 0.0f;
float _rectangle = 0.0f;
float _triangle = 0.0f;


void circle(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float pi = 3.1416;
        float angle = (i * 2 * pi) / 200;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glColor3f(r, g, b);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}


void rectangle(float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex2f(xc - 1.0f, yc - 0.5f);
    glVertex2f(xc + 1.0f, yc - 0.5f);
    glVertex2f(xc + 1.0f, yc + 0.5f);
    glVertex2f(xc - 1.0f, yc + 0.5f);
    glEnd();
}


void triangle(float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex2f(xc, yc + 1.5f);
    glVertex2f(xc - 1.0f, yc - 1.0f);
    glVertex2f(xc + 1.0f, yc - 1.0f);
    glEnd();
}


void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    circle(0.5f, 0.0, _circle, 1.0f, 0.0f, 0.0f);
    rectangle(0.0f, _rectangle, 0.0f, 1.0f, 0.0f);
    triangle(_triangle, 0.0f, 0.0f, 0.0f, 1.0f);
    circle(0.5f, _circle2,0.0f, 1.0f, 1.0f, 0.0f);

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    float step = 0.5f;
    switch (key) {
        case 'w':
            _circle += step;
            if (_circle > 5.0f) _circle = -5.0f;
            break;
        case 's':
            _circle -= step;
            if (_circle > 5.0f) _circle = 5.0f;
            break;
        case 'a':
            _rectangle -= step;
            if (_rectangle < -5.0f) _rectangle = 5.0f;
            break;
        case 'd':
            _rectangle += step;
            if (_rectangle > +5.0f) _rectangle = -5.0f;
            break;
        case 'i':
            _triangle += step;
            if (_triangle > 5.0f) _triangle = -5.0f;
            break;
        case 'k':
            _triangle -= step;
            if (_triangle < -5.0f) _triangle = 5.0f;
            break;
        case 'j':
          _circle2 += step;
            if (_circle2 > 5.0f) _circle2 = -5.0f;
            break;
        case 'l':
          _circle2 -= step;
            if (_circle2 > 5.0f) _circle2 = +5.0f;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Object Movement with Keyboard");
    gluOrtho2D(-10, 10, -10, 10);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
