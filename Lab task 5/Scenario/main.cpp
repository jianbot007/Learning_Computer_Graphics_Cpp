#include <GL/glut.h>

void drawTrafficLight() {
    // Draw the pole
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-0.02f, 0.0f);
    glVertex2f(0.02f, 0.0f);
    glVertex2f(0.02f, 0.5f);
    glVertex2f(-0.02f, 0.5f);
    glEnd();

    // Draw the traffic light box
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.5f);
    glVertex2f(0.05f, 0.5f);
    glVertex2f(0.05f, 0.65f);
    glVertex2f(-0.05f, 0.65f);
    glEnd();

    // Red Light
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.03f, 0.6f);
    glVertex2f(0.03f, 0.6f);
    glVertex2f(0.03f, 0.64f);
    glVertex2f(-0.03f, 0.64f);
    glEnd();

    // Yellow pedestrian sign
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.02f, 0.54f);
    glVertex2f(0.02f, 0.54f);
    glVertex2f(0.0f, 0.58f);
    glEnd();
}

void drawRoad() {
    // Draw the main road
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.4f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, 0.4f);
    glVertex2f(-1.0f, 0.4f);
    glEnd();

    // Draw the central divider
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.4f);
    glVertex2f(0.1f, -0.4f);
    glVertex2f(0.1f, 0.4f);
    glVertex2f(-0.1f, 0.4f);
    glEnd();
}

void drawBackground() {
    // Draw sky
    glColor3f(0.5f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    // Draw ground
    glColor3f(0.3f, 0.7f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawBackground();
    drawRoad();
    drawTrafficLight();

    glFlush();
}

void init() {
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f); // Background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Traffic Light Scene");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
