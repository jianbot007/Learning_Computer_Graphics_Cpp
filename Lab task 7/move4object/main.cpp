#include <windows.h>
#include <GL/glut.h>
#include <math.h>

// Position variables for each object
float circleY = 0.0f;
float rectX = 0.0f;
float triangleX = 0.0f;
float yellowCircleY = 0.0f;


bool circleDirection = true;
bool rectDirection = true;
bool triangleDirection = true;
bool yellowCircleDirection = true;

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

void updatePositions(int value) {

    if (circleDirection)
        circleY += 0.1f;
    else
        circleY -= 0.1f;

    if (circleY >= 5.0f || circleY <= -5.0f)
        circleDirection = !circleDirection;


    if (rectDirection)
        rectX -= 0.1f;
    else
        rectX += 0.1f;

    if (rectX >= 5.0f || rectX <= -5.0f)
        rectDirection = !rectDirection;

    if (triangleDirection)
        triangleX += 0.1f;
    else
        triangleX -= 0.1f;

    if (triangleX >= 5.0f || triangleX <= -5.0f)
        triangleDirection = !triangleDirection;


    if (yellowCircleDirection)
        yellowCircleY -= 0.1f;
    else
        yellowCircleY += 0.1f;

    if (yellowCircleY >= 5.0f || yellowCircleY <= -5.0f)
        yellowCircleDirection = !yellowCircleDirection;

    glutPostRedisplay();
    glutTimerFunc(50, updatePositions, 0);
}

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    circle(0.5f, 0.0f, circleY, 1.0f, 0.0f, 0.0f);
    rectangle(rectX, 0.0f, 0.0f, 1.0f, 0.0f);
    triangle(triangleX, 0.0f, 0.0f, 0.0f, 1.0f);
    circle(0.5f, 0.0f, yellowCircleY, 1.0f, 1.0f, 0.0f);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simplified 4 Object Animation");
    gluOrtho2D(-10, 10, -10, 10);
    glutDisplayFunc(display);
    glutTimerFunc(50, updatePositions, 0);
    glutMainLoop();
    return 0;
}
