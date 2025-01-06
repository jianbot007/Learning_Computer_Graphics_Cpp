#include <GL/glut.h>
#include <cstdlib>
#include <ctime>


float raindropY = 10.0f;
float waterLevel = -10.0f;

void drawRaindrop(float x, float y) {
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(x, y);
    glEnd();
}


void drawWater(float level) {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-10.0f, level);
    glVertex2f(10.0f, level);
    glVertex2f(10.0f, -10.0f);
    glVertex2f(-10.0f, -10.0f);
    glEnd();
}


void update(int value) {

    raindropY -= 0.2f;


    if (raindropY < waterLevel + 0.2f) {
        raindropY = 10.0f;
    }


    waterLevel += 0.01f;


    if (waterLevel >= 10.0f) {
        waterLevel = 10.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(50, update, 0);
}


void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    drawWater(waterLevel);


    drawRaindrop(0.0f, raindropY);
     drawRaindrop(1.0f, raindropY); drawRaindrop(2.0f, raindropY);
      drawRaindrop(-1.0f, raindropY); drawRaindrop(-2.0f, raindropY);
         drawRaindrop(3.0f, raindropY); drawRaindrop(4.0f, raindropY);
      drawRaindrop(-3.0f, raindropY); drawRaindrop(-4.0f, raindropY);
          drawRaindrop(5.0f, raindropY); drawRaindrop(6.0f, raindropY);
      drawRaindrop(-5.0f, raindropY); drawRaindrop(-5.0f, raindropY);
         drawRaindrop(7.0f, raindropY); drawRaindrop(8.0f, raindropY);
      drawRaindrop(-7.0f, raindropY); drawRaindrop(-6.0f, raindropY);


    glFlush();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rain and Flood Simulation");

    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

    glutDisplayFunc(display);
    glutTimerFunc(50, update, 0);

    glutMainLoop();
    return 0;
}


