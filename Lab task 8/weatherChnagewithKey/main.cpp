#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

enum WeatherState { SUNNY, OVERCAST, RAINY };
WeatherState currentWeather = SUNNY;

const int MAX_RAINDROPS = 1000;
float raindropX[MAX_RAINDROPS];
float raindropY[MAX_RAINDROPS];
int numRaindrops = 0;

float rainSpeed = 0.02f;

// Add raindrop
void addRaindrop() {
    if (numRaindrops < MAX_RAINDROPS) {
        raindropX[numRaindrops] = (rand() % 2000 - 1000) / 1000.0f;
        raindropY[numRaindrops] = 0.6f;
        numRaindrops++;
    }
}


void drawSunWithRays() {
    // Sun
    glColor3f(1.0, 1.0, 0.0); // Yellow color
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159 / 180;
        glVertex2f(0.1 * cos(theta) - 0.7, 0.1 * sin(theta) + 0.7); // Sun on the left
    }
    glEnd();

    // Rays
    glColor3f(1.0, 1.0, 0.0);
    for (int i = 0; i < 360; i += 30) {
        float theta = i * 3.14159 / 180;
        float x1 = 0.1 * cos(theta) - 0.7;
        float y1 = 0.1 * sin(theta) + 0.7;
        float x2 = 0.15 * cos(theta) - 0.7; // End point outside the sun
        float y2 = 0.15 * sin(theta) + 0.7;
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
}

// Draw the ground
void drawGround() {
    glColor3f(0.2f, 0.8f, 0.2f); // Green color for ground
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.5f); // Separate ground from the sky
    glVertex2f(-1.0f, -0.5f);
    glEnd();
}

// Draw combined cloud
void drawCloud(float x, float y) {
    glColor3f(0.5, 0.5, 0.5); // Grey color
    glPushMatrix();
    glTranslatef(x, y, 0.0);

    for (float i = -0.1; i <= 0.1; i += 0.1) {
        for (float j = -0.1; j <= 0.1; j += 0.1) {
            glBegin(GL_POLYGON);
            for (int k = 0; k < 360; k++) {
                float theta = k * 3.14159 / 180;
                glVertex2f(0.15 * cos(theta) + i, 0.1 * sin(theta) + j);
            }
            glEnd();
        }
    }

    glPopMatrix();
}

// Draw raindrop
void drawRaindrop(float x, float y) {
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x, y - 0.05f);
    glEnd();
}

// Draw rain
void drawRain() {
    glColor3f(0.8f, 0.8f, 1.0f); // Light blue color for raindrops
    for (int i = 0; i < numRaindrops; ++i) {
        drawRaindrop(raindropX[i], raindropY[i]);
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw the ground
    drawGround();

    if (currentWeather == SUNNY) {
        glClearColor(0.5, 0.8, 1.0, 1.0); // Light blue sky
        drawSunWithRays(); // Draw the sun with rays

    } else if (currentWeather == OVERCAST) {
        glClearColor(0.7, 0.7, 0.7, 1.0); // Grayish sky
        drawCloud(-0.4, 0.4);
        drawCloud(0.3, 0.5);

    } else if (currentWeather == RAINY) {
        glClearColor(0.5, 0.5, 0.6, 1.0); // Dark gray sky
        drawRain(); // Draw rain
    }

    glutSwapBuffers();
}

// Update raindrops
void update(int value) {
    if (currentWeather == RAINY) {
        if (rand() % 10 < 7) {
            addRaindrop();
        }

        for (int i = 0; i < numRaindrops; ++i) {
            raindropY[i] -= rainSpeed;
            if (raindropY[i] <= -1.0f) {
                raindropY[i] = 1.0f;
                raindropX[i] = (rand() % 2000 - 1000) / 1000.0f;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

// Keyboard input handler
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 's':
            currentWeather = SUNNY;
            break;
        case 'r':
            currentWeather = RAINY;
            break;
        case 'c':
            currentWeather = OVERCAST;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

// Initialization
void initialize() {
    glClearColor(0.5, 0.8, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    srand(static_cast<unsigned>(time(0)));
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Weather Change Simulation");

    initialize();

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
