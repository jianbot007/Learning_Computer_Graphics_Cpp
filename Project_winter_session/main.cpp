#include <GL/glut.h>
#include <cmath>

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.8f, 0.9f, 1.0f, 1.0f); // Light blue background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 200.0, 0.0, 200.0); // Orthographic projection
}

// Function to draw a filled circle
void drawCircle(float cx, float cy, float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100.0f;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

// Function to draw the train
void drawTrain(float x, float y, float width, float height) {
    // Draw train body
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the train
    glBegin(GL_QUADS);
    glVertex2f(x, y);                   // Bottom-left
    glVertex2f(x + width, y);           // Bottom-right
    glVertex2f(x + width, y + height);  // Top-right
    glVertex2f(x, y + height);          // Top-left
    glEnd();

    // Draw train windows
    glColor3f(1.0f, 1.0f, 1.0f); // White color for windows
    float windowWidth = width / 10; // Divide train width for 10 windows
    float windowSpacing = width / 15; // Add spacing between windows
    float currentX = x + windowSpacing;

    for (int i = 0; i < 8; i++) { // Draw 8 windows
        glBegin(GL_QUADS);
        glVertex2f(currentX, y + height * 0.2f);               // Bottom-left
        glVertex2f(currentX + windowWidth, y + height * 0.2f); // Bottom-right
        glVertex2f(currentX + windowWidth, y + height * 0.8f); // Top-right
        glVertex2f(currentX, y + height * 0.8f);               // Top-left
        glEnd();

        currentX += windowWidth + windowSpacing;
    }
}

// Function to draw the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the road
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray for road
    glBegin(GL_QUADS);
    glVertex2f(0, 20);  // Bottom-left
    glVertex2f(200, 20); // Bottom-right
    glVertex2f(200, 50); // Top-right
    glVertex2f(0, 50);  // Top-left
    glEnd();

    // Draw lane markings on the road
    glColor3f(1.0f, 1.0f, 1.0f); // White for dashes
    for (int i = 0; i < 200; i += 20) {
        glBegin(GL_QUADS);
        glVertex2f(i, 33);  // Bottom-left
        glVertex2f(i + 10, 33); // Bottom-right
        glVertex2f(i + 10, 37); // Top-right
        glVertex2f(i, 37);  // Top-left
        glEnd();
    }

    // Draw the metro overbridge base
    glColor3f(0.5f, 0.5f, 0.5f); // Gray for bridge
    glBegin(GL_QUADS);
    glVertex2f(0, 120);  // Bottom-left
    glVertex2f(200, 120); // Bottom-right
    glVertex2f(200, 140); // Top-right
    glVertex2f(0, 140);  // Top-left
    glEnd();

    // Draw rounded ends of the metro overbridge
    drawCircle(0, 130, 10, 0.5f, 0.5f, 0.5f); // Left end
    drawCircle(200, 130, 10, 0.5f, 0.5f, 0.5f); // Right end

    // Draw support beams for the metro bridge
    glColor3f(0.4f, 0.4f, 0.4f); // Dark gray for beams
    for (int i = 30; i < 200; i += 40) {
        glBegin(GL_QUADS);
        glVertex2f(i - 5, 50);  // Bottom-left
        glVertex2f(i + 5, 50); // Bottom-right
        glVertex2f(i + 5, 120); // Top-right
        glVertex2f(i - 5, 120);  // Top-left
        glEnd();
    }

    // Draw diagonal support beams
    glColor3f(0.3f, 0.3f, 0.3f); // Darker gray
    for (int i = 20; i < 200; i += 40) {
        glBegin(GL_LINES);
        glVertex2f(i, 50);     // Bottom-left
        glVertex2f(i + 20, 120); // Top-right
        glVertex2f(i + 20, 50); // Bottom-right
        glVertex2f(i, 120);    // Top-left
        glEnd();
    }

    // Draw the train on the metro overbridge
    drawTrain(50, 125, 100, 10); // Position: (50, 125), Width: 100, Height: 10

    glFlush(); // Render the scene
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Realistic Metro Overbridge with Train");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
