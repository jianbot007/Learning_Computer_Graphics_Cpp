#include <windows.h>
#include <GL/glut.h>
#include <cmath>


box1(){

    glBegin(GL_QUADS);
    glColor3ub(205, 169, 245);
    glVertex2d(-4,4);
    glVertex2d(4, 4);
    glVertex2d(4, 3);
    glVertex2d(-4, 3);
    glEnd();

}

box2(){

    glBegin(GL_QUADS);
    glColor3ub(156, 173, 250);
    glVertex2d(-4,3);
    glVertex2d(4, 3);
    glVertex2d(4, 2);
    glVertex2d(-4, 2);
    glEnd();

}


box3(){

    glBegin(GL_QUADS);
    glColor3ub(53, 176, 182);
    glVertex2d(-4,2);
    glVertex2d(4, 2);
    glVertex2d(4, 1);
    glVertex2d(-4, 1);
    glEnd();

}

box4(){

    glBegin(GL_QUADS);
    glColor3ub(10, 159, 12);
    glVertex2d(-4,1);
    glVertex2d(4, 1);
    glVertex2d(4, 0);
    glVertex2d(-4, 0);
    glEnd();

}

box5(){

    glBegin(GL_QUADS);
    glColor3ub(170, 90, 7);
    glVertex2d(-4,0);
    glVertex2d(4, 0);
    glVertex2d(4, -1);
    glVertex2d(-4, -1);
    glEnd();

}

box6(){

    glBegin(GL_QUADS);
    glColor3ub(30, 53, 3);
    glVertex2d(-4,-1);
    glVertex2d(4, -1);
    glVertex2d(4, -2);
    glVertex2d(-4, -2);
    glEnd();

}
box7(){

    glBegin(GL_QUADS);
    glColor3ub( 218, 59, 34);
    glVertex2d(-4,-2);
    glVertex2d(4, -2);
    glVertex2d(4, -3);
    glVertex2d(-4, -3);
    glEnd();

}

box11(){

 glBegin(GL_LINE_LOOP);
    glColor3ub(255, 255, 255);
    glVertex2d(-4,4);
    glVertex2d(4, 4);
    glVertex2d(4, 3);
    glVertex2d(-4, 3);
    glEnd();

}

box22(){

     glBegin(GL_LINE_LOOP);
    glColor3ub(255, 255, 255);
    glVertex2d(-4,3);
    glVertex2d(4, 3);
    glVertex2d(4, 2);
    glVertex2d(-4, 2);
    glEnd();

}


box33(){

    glBegin(GL_LINE_LOOP);
    glColor3ub(255, 255, 255);
    glVertex2d(-4,2);
    glVertex2d(4, 2);
    glVertex2d(4, 1);
    glVertex2d(-4, 1);
    glEnd();

}

box44(){

     glBegin(GL_LINE_LOOP);
    glColor3ub(255, 255, 255);
    glVertex2d(-4,1);
    glVertex2d(4, 1);
    glVertex2d(4, 0);
    glVertex2d(-4, 0);
    glEnd();

}

box55(){

     glBegin(GL_LINE_LOOP);
    glColor3ub(255, 255, 255);
    glVertex2d(-4,0);
    glVertex2d(4, 0);
    glVertex2d(4, -1);
    glVertex2d(-4, -1);
    glEnd();

}

box66(){

     glBegin(GL_LINE_LOOP);
    glColor3ub(255, 255, 255);
    glVertex2d(-4,-1);
    glVertex2d(4, -1);
    glVertex2d(4, -2);
    glVertex2d(-4, -2);
    glEnd();

}
box77(){

    glBegin(GL_LINE_LOOP);
    glColor3ub(255, 255, 255);
    glVertex2d(-4,-2);
    glVertex2d(4, -2);
    glVertex2d(4, -3);
    glVertex2d(-4, -3);
    glEnd();

}

Rainbow(){
 box1();
    box2();
    box3(); box4();box5();box6();box7();
}

Line(){
  box11();
    box22();
    box33(); box44();box55();box66();box77();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
     Rainbow();
     Line();





    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Rainbow");
    glutInitWindowSize(720, 720);
    glutDisplayFunc(display);
    gluOrtho2D(-6, 6, -6, 6);
    glutMainLoop();
}






