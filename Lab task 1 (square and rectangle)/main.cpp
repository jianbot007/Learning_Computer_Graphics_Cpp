

	#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glLineWidth(1.5);

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red

	glVertex2f(-0.7f, 0.6f);    // x, y
	glVertex2f(-.4f, 0.6f);
	glVertex2f(-.4f, 0.3f);
	glVertex2f(-0.7f, 0.3f);    // x, y

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.0f); //Green

	glVertex2f(0.2f, 0.6f);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(.6f, 0.4f);     // x, y
	glVertex2f(.2f, 0.4f);    // x, y
	  // x, y

	glEnd();


	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutInitWindowSize(720, 720);
	glutCreateWindow("Square & Rectangle"); // Create a window with the given title
	  // Set the window's initial width & height
	glutDisplayFunc(display);
	gluOrtho2D(15,15,15,15);// Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
