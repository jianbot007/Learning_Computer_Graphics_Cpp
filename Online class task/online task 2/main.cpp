
#include <windows.h>
#include <GL/glut.h>
#include <cmath>


const double squareSize = 1.0;


void drawSquare(double x, double y, bool isBlack) {

    if (isBlack) {
        glColor3f(0.0f, 0.0f, 0.0f);
    } else {
        glColor3f(1.0f, 1.0f, 1.0f);
    }


    glBegin(GL_QUADS);
    glVertex2d(x, y);
    glVertex2d(x + squareSize, y);
    glVertex2d(x + squareSize, y - squareSize);
    glVertex2d(x, y - squareSize);
    glEnd();
}


void drawCheckerboard() {
    int rows = 4, cols = 4; // Number of rows and columns for the checkerboard

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            double x = -2.0 + j * squareSize;
            double y = 4.0 - i * squareSize;


            bool isBlack = (i + j) % 2 == 0;

            drawSquare(x, y, isBlack);
        }
    }
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCheckerboard();
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Checkerboard Example");
    glutInitWindowSize(720, 720);
    glutDisplayFunc(display);
    gluOrtho2D(-6, 6, -6, 6);
    glutMainLoop();
}






