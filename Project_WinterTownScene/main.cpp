#include <GL/glut.h>
#include <cmath>
#include <ctime>
bool day = true;
float cloudOffset = 0.0f;
float centerX = 42.0f;
float centerY = 160.0f;
float radius = 20.0f;
char activeLight = 'B';
float xcar = 0.0f;
float ycar = 2.0f;
float xOffset = 0.0f;
float angle = 0.0f;
float angle2 = 0.0f;
bool lampLight = false;
bool snowing = false;
void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}
void drawSnow(int value)// A312
{
    if (snowing)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.0f, 0.0f, 0.0f); // Snow color (white)

        for (int i = 0; i < 500; i++)   // 500 snowflakes
        {
            float x = rand() % 1200 - 600; // Random x-coordinate (-600 to 600)
            float y = rand() % 600 - 300;  // Random y-coordinate (-300 to 300)

            glPointSize(5.5f); // Set the snowflake size
            glBegin(GL_POINTS);
            glVertex2f(x, y); // Draw the snowflake as a point
            glEnd();
        }

        glFlush();                        // Render the scene
        glutPostRedisplay();              // Request a redraw
        glutTimerFunc(16, drawSnow, 0);   // Schedule next call to `drawSnow`
    }
}
void drawCircle2(GLfloat centerX, GLfloat centerY, GLfloat radius)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int angle = 0; angle <= 360; angle++)
    {
        GLfloat rad = angle * 3.14159f / 180.0f;
        GLfloat x = centerX + cos(rad) * radius;
        GLfloat y = centerY + sin(rad) * radius;
        glVertex2f(x, y);
    }
    glEnd();
}
void drawCircle(GLfloat centerX, GLfloat centerY, GLfloat radius, GLint segments)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Center of the circle
    for (int i = 0; i <= segments; i++)
    {
        GLfloat angle = 2.0f * 3.14159f * i / segments; // Calculate the angle
        GLfloat x = centerX + cos(angle) * radius;      // X coordinate
        GLfloat y = centerY + sin(angle) * radius;      // Y coordinate
        glVertex2f(x, y);
    }
    glEnd();
}
void drawCloud(GLfloat centerX, GLfloat centerY)
{
    if(day == true)
    {
        glColor3ub(255, 255, 255);
    }
    else
    {
        glColor3ub(20, 20, 20);
    }
    drawCircle2(centerX, centerY, 20.0f);           // Center circle
    drawCircle2(centerX - 20.0f, centerY, 15.0f);   // Left circle
    drawCircle2(centerX + 20.0f, centerY, 15.0f);   // Right circle
    drawCircle2(centerX - 10.0f, centerY + 15.0f, 15.0f); // Top left circle
    drawCircle2(centerX + 10.0f, centerY + 15.0f, 15.0f); // Top right circle
}
void Clouds()  // A301
{
    GLfloat baseX = 400.0f;

    drawCloud(baseX - cloudOffset, 155);
    drawCloud(baseX - cloudOffset - 200, 160);
    drawCloud(baseX - cloudOffset - 400, 170);
}
void updateClouds(int value)
{
    cloudOffset += 0.5f;


    if (cloudOffset > 600.0f)
        cloudOffset = 0.0f;

    glutPostRedisplay();
    glutTimerFunc(16, updateClouds, 0);
}
void sky() // O301
{
    glBegin(GL_QUADS);
    if(day == true )
    {
        glColor3ub(130, 159, 250);
    }
    else
    {
        glColor3ub(40, 40, 40);
    }
    glVertex2f(-200, 110);
    glVertex2f(-200, 200);
    glVertex2f(200, 200);
    glVertex2f(200, 110);
    glEnd();
}
void drawMoon() //O302
{
    GLfloat x = 65.0f;
    GLfloat y = 160.0f;
    GLfloat outerRadius = 30.0f;

    glColor3ub(255, 255, 224);
    drawCircle2(x, y, outerRadius);

}
void drawSun() // A302
{
    //sun
    glColor3ub(255, 255, 0);
    drawCircle2(centerX,centerY,18);

}
void updateSun(int value)
{
    centerX += 0.05f;


    if (centerX > 170.0f)
    {
        centerX = -200.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateSun, 0);
}
void Bigtree() //O303
{
    glBegin(GL_TRIANGLES);

    // Top point of the tree
    GLfloat topX = 5.33397f;
    GLfloat topY = 92.24686f;

    glColor3ub(51, 102, 153); // Deepest icy blue
    glVertex2f(topX, topY - 75.0f);
    glVertex2f(-30.0f, -40.0f);
    glVertex2f(45.0f, -40.0f);

    glColor3ub(77, 128, 179); // Dark icy blue
    glVertex2f(topX, topY - 60.0f);
    glVertex2f(-30.0f, -15.0f);
    glVertex2f(41.0f, -15.0f);

    glColor3ub(102, 153, 204); // Deeper icy blue
    glVertex2f(topX, topY - 45.0f);
    glVertex2f(-23.0f, 11.0f);
    glVertex2f(35.0f, 11.0f);

    glColor3ub(128, 179, 230); // Moderate icy blue
    glVertex2f(topX, topY - 30.0f);
    glVertex2f(-17.0f, 35.0f);
    glVertex2f(30.0f, 35.0f);

    glColor3ub(153, 204, 255); // darker icy blue
    glVertex2f(topX, topY - 15.0f);
    glVertex2f(-10.0f, 50.0f);
    glVertex2f(22.0f, 50.0f);

    glColor3ub(179, 229, 255); // Light icy blue
    glVertex2f(topX, topY);
    glVertex2f(-2.31f, 69.0f);
    glVertex2f(15.0f, 69.0f);

    glEnd();

    //treebody
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(-0.5f, -37.0f);
    glVertex2f(13.5f, -37.0f);
    glVertex2f(13.5f, -73.0f);
    glVertex2f(-0.5f, -73.0f);
    glEnd();

}
void disTree() //O304
{

    glBegin(GL_TRIANGLES);

    // Top point of the tree
    GLfloat topX = -77.0f;
    GLfloat topY = -48.0f;

    glColor3ub(179, 229, 255);
    glVertex2f(topX, topY - 20);
    glVertex2f(-85.0f, -68.0f);
    glVertex2f(-68.0f, -68.0f);

    glColor3ub(153, 204, 255);
    glVertex2f(topX, topY -25);
    glVertex2f(-88.0f, -80.0f);
    glVertex2f(-65.0f, -80.0f);

    glColor3ub(128, 179, 230);
    glVertex2f(topX, topY -30);
    glVertex2f(-93.0f, -90.0f);
    glVertex2f(-61.0f, -90.0f);


    glColor3ub(102, 153, 204);
    glVertex2f(topX, topY -35);
    glVertex2f(-93.0f, -98.0f);
    glVertex2f(-58.0f, -100.0f);

    glEnd();
}
void disTree1() //O305
{
    glPushMatrix();
    glTranslatef(0,135,0);
    disTree();
    glPopMatrix();

}
void disTree2() //O306
{
    glPushMatrix();
    glTranslatef(20,100,0);
    glScalef(0.5f, 0.5f, 2.0f);
    disTree();
    glPopMatrix();

}
void disTree3() //O307
{
    glPushMatrix();
    glTranslatef(180,140,0);
    disTree();
    glPopMatrix();

}
void disTree4()  //O308
{
    glPushMatrix();
    glTranslatef(150,15,0);
    glScalef(0.5f, 0.5f, 2.0f);
    disTree();
    glPopMatrix();
}
void disTree5()  //O309
{
    glPushMatrix();
    glTranslatef(160,15,0);
    glScalef(0.5f, 0.5f, 2.0f);
    disTree();
    glPopMatrix();
}
void disTree6()  //O310
{
    glPushMatrix();
    glTranslatef(200,10,0);
    glScalef(0.5f, 0.5f, 2.0f);
    disTree();
    glPopMatrix();
}
void disTree7()  //O311
{
    glPushMatrix();
    glTranslatef(-40,5,0);
    glScalef(0.5f, 0.5f, 2.0f);
    disTree();
    glPopMatrix();
}
void disTree8()  //O312
{
    glPushMatrix();
    glTranslatef(-20,1,0);
    glScalef(0.5f, 0.5f, 2.0f);
    disTree();
    glPopMatrix();
}

void smallTree1() //O313
{
    glBegin(GL_TRIANGLES);

    // Top point of the tree
    GLfloat topX = -77.0f;
    GLfloat topY = -48.0f;

    glColor3ub(179, 229, 255);
    glVertex2f(topX, topY - 20);
    glVertex2f(-85.0f, -68.0f);
    glVertex2f(-68.0f, -68.0f);

    glColor3ub(153, 204, 255);
    glVertex2f(topX, topY -25);
    glVertex2f(-88.0f, -80.0f);
    glVertex2f(-65.0f, -80.0f);

    glColor3ub(128, 179, 230);
    glVertex2f(topX, topY -30);
    glVertex2f(-93.0f, -90.0f);
    glVertex2f(-61.0f, -90.0f);


    glColor3ub(102, 153, 204);
    glVertex2f(topX, topY -35);
    glVertex2f(-93.0f, -98.0f);
    glVertex2f(-58.0f, -100.0f);



    glColor3ub(77, 128, 179);
    glVertex2f(topX, topY - 40);
    glVertex2f(-95.0f, -108.0f);
    glVertex2f(-57.0f, -108.0f);

    glEnd();

    // Draw the tree trunk
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(-72.0f, -108.0f);
    glVertex2f(-82.0f, -108.0f);
    glVertex2f(-82.0f, -120.0f);
    glVertex2f(-72.0f, -120.0f);
    glEnd();
}
void smallTree2()  //O314
{
    glBegin(GL_TRIANGLES);

    // Top point of the tree
    GLfloat topX = -77-70;
    GLfloat topY = -48+18;

    glColor3ub(179, 229, 255);
    glVertex2f(topX, topY - 20);
    glVertex2f(-85-70, -68+18);
    glVertex2f(-68-70, -68+18);

    glColor3ub(153, 204, 255);
    glVertex2f(topX, topY -25);
    glVertex2f(-88-70, -80+18);
    glVertex2f(-65-70, -80+18);

    glColor3ub(128, 179, 230);
    glVertex2f(topX, topY -30);
    glVertex2f(-93-70, -90+18);
    glVertex2f(-61-70, -90+18);


    glColor3ub(102, 153, 204);
    glVertex2f(topX, topY -35);
    glVertex2f(-93-70, -98+18);
    glVertex2f(-58-70, -100+18);



    glColor3ub(77, 128, 179);
    glVertex2f(topX, topY - 40);
    glVertex2f(-95-70, -108+18);
    glVertex2f(-57-70, -108+18);

    glEnd();

    // Draw the tree trunk
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(-72-70, -108+18);
    glVertex2f(-82-70, -108+18);
    glVertex2f(-82-70, -120+18);
    glVertex2f(-72-70, -120+18);
    glEnd();
}
void smallTree3()  //O315
{
    glBegin(GL_TRIANGLES);

    // Top point of the tree
    GLfloat topX = -77+235;
    GLfloat topY = -48-82;

    glColor3ub(179, 229, 255);
    glVertex2f(topX, topY - 20);
    glVertex2f(-85+235, -68-82);
    glVertex2f(-68+235, -68-82);

    glColor3ub(153, 204, 255);
    glVertex2f(topX, topY -25);
    glVertex2f(-88+235, -80-82);
    glVertex2f(-65+235, -80-82);

    glColor3ub(128, 179, 230);
    glVertex2f(topX, topY -30);
    glVertex2f(-93+235, -90-82);
    glVertex2f(-61+235, -90-82);


    glColor3ub(102, 153, 204);
    glVertex2f(topX, topY -35);
    glVertex2f(-93+235, -98-82);
    glVertex2f(-58+235, -100-82);



    glColor3ub(77, 128, 179);
    glVertex2f(topX, topY - 40);
    glVertex2f(-95+235, -108-82);
    glVertex2f(-57+235, -108-82);

    glEnd();

    // Draw the tree trunk
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(-72+235, -108-82);
    glVertex2f(-82+235, -108-82);
    glVertex2f(-82+235, -120-82);
    glVertex2f(-72+235, -120-82);
    glEnd();
}
void smallTree4()  //O316
{
    glBegin(GL_TRIANGLES);

    // Top point of the tree
    GLfloat topX = -77.0f+157;
    GLfloat topY = -48.0f-65;

    glColor3ub(179, 229, 255);
    glVertex2f(topX, topY - 20);
    glVertex2f(-85.0f+157, -68.0f-65);
    glVertex2f(-68.0f+157, -68.0f-65);

    glColor3ub(153, 204, 255);
    glVertex2f(topX, topY -25);
    glVertex2f(-88.0f+157, -80.0f-65);
    glVertex2f(-65.0f+157, -80.0f-65);

    glColor3ub(128, 179, 230);
    glVertex2f(topX, topY -30);
    glVertex2f(-93.0f+157, -90.0f-65);
    glVertex2f(-61.0f+157, -90.0f-65);


    glColor3ub(102, 153, 204);
    glVertex2f(topX, topY -35);
    glVertex2f(-93.0f+157, -98.0f-65);
    glVertex2f(-58.0f+157, -100.0f-65);



    glColor3ub(77, 128, 179);
    glVertex2f(topX, topY - 40);
    glVertex2f(-95.0f+157, -108.0f-65);
    glVertex2f(-57.0f+157, -108.0f-65);

    glEnd();

    // Draw the tree trunk
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(-72.0f+157, -108.0f-65);
    glVertex2f(-82.0f+157, -108.0f-65);
    glVertex2f(-82.0f+157, -120.0f-65);
    glVertex2f(-72.0f+157, -120.0f-65);
    glEnd();
}
void drawTrainRoad()  //O317
{
    glColor3f(0.66f, 0.66f, 0.66f); // RGB equivalent of gray
    glBegin(GL_LINES);

    glVertex2f(-201, 110);
    glVertex2f(201, 110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.66f, 0.66f, 0.66f);
    glVertex2f(-201, 80);
    glVertex2f(201, 80);
    glVertex2f(200, 96);
    glVertex2f(-201, 96);
    glEnd();

    //TrainLine
    for(int i = 0 ; i < 400 ; i=i+10)
    {
        glBegin(GL_LINES);
        glColor3f(0.66f, 0.66f, 0.66f);
        glVertex2f(-188.17042+i,90.28146);
        glVertex2f(-189.21768+i+5,110);
        glEnd();
    }
    glFlush();
}
void Building1()  //O318
{
    //body1
    glBegin(GL_QUADS);
    if(day == true)
    {
        glColor3ub(220.0f, 220.0f, 220.0f);
    }
    else
    {
        glColor3ub(200.0f, 200.0f, 200.0f);
    }
    glVertex2f(80, 140+15);
    glVertex2f(134, 143+15);
    glVertex2f(134, 93+15);
    glVertex2f(81, 95+15);
    glEnd();
    //windowforbody1
    //window1
    glBegin(GL_QUADS);
    if(day == true)
    {
        glColor3ub(150.0f, 150.0f, 150.0f);
    }
    else
    {
        glColor3ub(140.0f, 140.0f, 130.0f);
    }
    glVertex2f(86, 133+15);
    glVertex2f(92, 133+15);
    glVertex2f(92, 118+15);
    glVertex2f(86, 118+15);
    glEnd();
    //window2
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(86+10, 133+15);
    glVertex2f(92+10, 133+15);
    glVertex2f(92+10, 118+15);
    glVertex2f(86+10, 118+15);
    glEnd();
    //window3
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(86+20, 133+15);
    glVertex2f(92+20, 133+15);
    glVertex2f(92+20, 118+15);
    glVertex2f(86+20, 118+15);
    glEnd();
    //window4
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(86+30, 133+15);
    glVertex2f(92+30, 133+15);
    glVertex2f(92+30, 118+15);
    glVertex2f(86+30, 118+15);
    glEnd();
    //window5
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(86, 133-8);
    glVertex2f(92, 133-8);
    glVertex2f(92, 118-8);
    glVertex2f(86, 118-8);
    glEnd();
    //window6
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(86+10, 133-8);
    glVertex2f(92+10, 133-8);
    glVertex2f(92+10, 118-8);
    glVertex2f(86+10, 118-8);
    glEnd();
    //window7
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(86+20, 133-8);
    glVertex2f(92+20, 133-8);
    glVertex2f(92+20, 118-8);
    glVertex2f(86+20, 118-8);
    glEnd();
    //window8
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(86+30, 133-8);
    glVertex2f(92+30, 133-8);
    glVertex2f(92+30, 118-8);
    glVertex2f(86+30, 118-8);
    glEnd();

    //body2
    glBegin(GL_QUADS);
    glColor3ub(240.0f, 240.0f, 240.0f);
    glVertex2f(134, 143+15);
    glVertex2f(172, 142+15);
    glVertex2f(171, 95+15);
    glVertex2f(134, 93+15);
    glEnd();

    //windowforbody2
    //window1
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(140, 133-8);
    glVertex2f(144, 133-8);
    glVertex2f(144, 118-8);
    glVertex2f(140, 118-8);
    glEnd();
    //window2
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(140+10, 133-8);
    glVertex2f(144+10, 133-8);
    glVertex2f(144+10, 118-8);
    glVertex2f(140+10, 118-8);
    glEnd();
    //window3
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(140+20, 133-8);
    glVertex2f(144+20, 133-8);
    glVertex2f(144+20, 118-8);
    glVertex2f(140+20, 118-8);
    glEnd();
    //window4
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(140, 133+15);
    glVertex2f(144, 133+15);
    glVertex2f(144, 118+15);
    glVertex2f(140, 118+15);
    glEnd();
    //window2
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(140+10, 133+15);
    glVertex2f(144+10, 133+15);
    glVertex2f(144+10, 118+15);
    glVertex2f(140+10, 118+15);
    glEnd();
    //window3
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(140+20, 133+15);
    glVertex2f(144+20, 133+15);
    glVertex2f(144+20, 118+15);
    glVertex2f(140+20, 118+15);
    glEnd();
    glFlush();
}
void Building2()  //O319
{

    //Top1
    glBegin(GL_QUADS);
    glColor3ub(255.0f, 255.0f, 255.0f);
    glVertex2f(68, 53);
    glVertex2f(154, 53);
    glVertex2f(154, 47);
    glVertex2f(68, 47);
    glEnd();
    //Top2
    glBegin(GL_QUADS);
    glColor3ub(255.0f, 255.0f, 255.0f);
    glVertex2f(154, 53);
    glVertex2f(154, 47);
    glVertex2f(199, 45);
    glVertex2f(199, 52);
    glEnd();

    //body1
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 22.0f, 22.0f);
    glVertex2f(68, 47);
    glVertex2f(154, 47);
    glVertex2f(154, -30);
    glVertex2f(67, -30);
    glEnd();
    //windowforbody1
    //window1
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76, 38);
    glVertex2f(85, 38);
    glVertex2f(85, 24);
    glVertex2f(76, 24);
    glEnd();
    //window2
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+15, 38);
    glVertex2f(85+15, 38);
    glVertex2f(85+15, 24);
    glVertex2f(76+15, 24);
    glEnd();
    //window3
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+30, 38);
    glVertex2f(85+30, 38);
    glVertex2f(85+30, 24);
    glVertex2f(76+30, 24);
    glEnd();
    //window4
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+45, 38);
    glVertex2f(85+45, 38);
    glVertex2f(85+45, 24);
    glVertex2f(76+45, 24);
    glEnd();
    //window4=5
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+60, 38);
    glVertex2f(85+60, 38);
    glVertex2f(85+60, 24);
    glVertex2f(76+60, 24);
    glEnd();
    //window6
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76, 38-20);
    glVertex2f(85, 38-20);
    glVertex2f(85, 24-20);
    glVertex2f(76, 24-20);
    glEnd();
    //window7
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+15, 38-20);
    glVertex2f(85+15, 38-20);
    glVertex2f(85+15, 24-20);
    glVertex2f(76+15, 24-20);
    glEnd();
    //window8
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+30, 38-20);
    glVertex2f(85+30, 38-20);
    glVertex2f(85+30, 24-20);
    glVertex2f(76+30, 24-20);
    glEnd();
    //window9
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+45, 38-20);
    glVertex2f(85+45, 38-20);
    glVertex2f(85+45, 24-20);
    glVertex2f(76+45, 24-20);
    glEnd();
    //window10
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+60, 38-20);
    glVertex2f(85+60, 38-20);
    glVertex2f(85+60, 24-20);
    glVertex2f(76+60, 24-20);
    glEnd();
    //window11
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+60, 38-40);
    glVertex2f(85+60, 38-40);
    glVertex2f(85+60, 24-40);
    glVertex2f(76+60, 24-40);
    glEnd();
    //window6
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76, 38-40);
    glVertex2f(85, 38-40);
    glVertex2f(85, 24-40);
    glVertex2f(76, 24-40);
    glEnd();
    //window7
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+15, 38-40);
    glVertex2f(85+15, 38-40);
    glVertex2f(85+15, 24-40);
    glVertex2f(76+15, 24-40);
    glEnd();
    //window8
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+30, 38-40);
    glVertex2f(85+30, 38-40);
    glVertex2f(85+30, 24-40);
    glVertex2f(76+30, 24-40);
    glEnd();
    //window9
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+45, 38-40);
    glVertex2f(85+45, 38-40);
    glVertex2f(85+45, 24-40);
    glVertex2f(76+45, 24-40);
    glEnd();
    //window10
    glBegin(GL_QUADS);
    glColor3ub(40.0f, 40.0f, 40.0f);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(76+60, 38-40);
    glVertex2f(85+60, 38-40);
    glVertex2f(85+60, 24-40);
    glVertex2f(76+60, 24-40);
    glEnd();

    //body2
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(154, 47);
    glVertex2f(199, 45);
    glVertex2f(202, -26);
    glVertex2f(154, -30);
    glEnd();

    //windowforbody2
    //window1
    glBegin(GL_QUADS);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(140, 133-8);
    glVertex2f(144, 133-8);
    glVertex2f(144, 118-8);
    glVertex2f(140, 118-8);
    glEnd();

    glFlush();

    //down1
    glBegin(GL_QUADS);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(67, -30);
    glVertex2f(68, -24);
    glVertex2f(154, -30);
    glVertex2f(155, -38);
    glEnd();
    //down2
    glBegin(GL_QUADS);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(154, -30);
    glVertex2f(154, -38);
    glVertex2f(201, -33);
    glVertex2f(201, -26);
    glEnd();
}
void Building3()  //O320
{

    //bodyone
    glBegin(GL_POLYGON);
    glColor3ub(150, 16, 16 );
    glVertex2f(-157.47993,-1.84999);
    glVertex2f(-123.88842,32.27472);
    glVertex2f(-92.42971,1.3492);
    glVertex2f(-72.16816,2.9488);
    glVertex2f(-68.97595,-40.06488);
    glVertex2f(-157.32255,-54.80844);
    glEnd();

    //body2
    glBegin(GL_POLYGON);
    glColor3ub(150, 16, 16 );
    glVertex2f(-157.32255,-54.80844);
    glVertex2f(-157.47993,-1.84999);
    glVertex2f(-185.36237,33.11448);
    glVertex2f(-205.59467,8.54668);
    glVertex2f(-202.70435,-50.22336);
    glEnd();

    //body1line
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(-157.47993,-1.84999);
    glVertex2f(-123.88842,32.27472);
    glVertex2f(-92.42971,1.3492);
    glVertex2f(-72.16816,2.9488);
    glVertex2f(-68.97595,-40.06488);
    glVertex2f(-157.32255,-54.80844);
    glEnd();

    //body2line
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0 );
    glVertex2f(-157.32255,-54.80844);
    glVertex2f(-157.47993,-1.84999);
    glVertex2f(-185.36237,33.11448);
    glVertex2f(-205.59467,8.54668);
    glVertex2f(-202.70435,-50.22336);
    glEnd();

    //top
    glBegin(GL_POLYGON);
    glColor3ub(245, 250, 255 );
    glVertex2f(-184.88065,35.85858);
    glVertex2f(-93.35354,40.3403);
    glVertex2f(-70.2309,4.6929);
    glVertex2f(-92.42971,1.3492);
    glVertex2f(-123.88842,32.27472);
    glVertex2f(-157.47993,-1.84999);
    glEnd();
    //topline
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0, 0 );
    glVertex2f(-184.88065,35.85858);
    glVertex2f(-93.35354,40.3403);
    glVertex2f(-70.2309,4.6929);
    glVertex2f(-92.42971,1.3492);
    glVertex2f(-123.88842,32.27472);
    glVertex2f(-157.47993,-1.84999);
    glEnd();

    glColor3ub(0,0, 0 );
    drawCircle(-125.62889,11.91873,5,200);

    //DOORLine

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0, 0 );
    glVertex2f(-128.0375,-7.35014);
    glVertex2f(-108.76863,-7.35014);
    glVertex2f(-108.76863,-41.55237);
    glVertex2f(-128.06438,-46.36959);

    glEnd();
    //Door
    glBegin(GL_POLYGON);
    glColor3ub(235,235, 235 );
    glVertex2f(-128.0375,-7.35014);
    glVertex2f(-108.76863,-7.35014);
    glVertex2f(-108.76863,-41.55237);
    glVertex2f(-128.06438,-46.36959);

    glEnd();

    //Window1
    glBegin(GL_POLYGON);
    glColor3ub(200,200, 200);
    glVertex2f(-149,-20);
    glVertex2f(-140,-20);
    glVertex2f(-140,-34);
    glVertex2f(-149,-34);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0, 0);
    glVertex2f(-149,-20);
    glVertex2f(-140,-20);
    glVertex2f(-140,-34);
    glVertex2f(-149,-34);
    glEnd();
    //window2
    glBegin(GL_POLYGON);
    glColor3ub(200,200, 200);
    glVertex2f(-149+55,-20+5);
    glVertex2f(-140+55,-20+5);
    glVertex2f(-140+55,-34+5);
    glVertex2f(-149+55,-34+5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0, 0);
    glVertex2f(-149+55,-20+5);
    glVertex2f(-140+55,-20+5);
    glVertex2f(-140+55,-34+5);
    glVertex2f(-149+55,-34+5);
    glEnd();
    //window3
    glBegin(GL_POLYGON);
    glColor3ub(200,200, 200);
    glVertex2f(-192.70752,-8.6697);
    glVertex2f(-174.56096,-8.6697);
    glVertex2f(-174.56096,-25.74881);
    glVertex2f(-193.06333,-25.92672);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0, 0);
    glVertex2f(-192.70752,-8.6697);
    glVertex2f(-174.56096,-8.6697);
    glVertex2f(-174.56096,-25.74881);
    glVertex2f(-193.06333,-25.92672);
    glEnd();
    //topPipe
    glBegin(GL_POLYGON);
    glColor3ub(150, 16, 16 );
    glVertex2f(-155.42449,52.27393);
    glVertex2f(-142.18791,52.56168);
    glVertex2f(-141.61241,38.35363);
    glVertex2f(-156.57549,38.35363);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0, 0);
    glVertex2f(-155.42449,52.27393);
    glVertex2f(-142.18791,52.56168);
    glVertex2f(-141.61241,38.35363);
    glVertex2f(-156.57549,38.35363);
    glEnd();



    glColor3ub(0,0, 0 );
    drawCircle(-181.99032,11.91873,5,200);



}
void TrainPillar()  //O321
{

    for(int x = 0 ; x < 400 ; x = x+60)
    {
        //Pillar1
        glBegin(GL_QUADS);
        glColor3f(0.66f, 0.66f, 0.66f);
        glVertex2f(-178.85618+x,68.0603+20);
        glVertex2f(-163.84122+x,66.75465+20);
        glVertex2f(-164.49404+x,36.39832);
        glVertex2f(-177.22412+x,36.72473);
        glEnd();
        //Pillar1Front1
        glBegin(GL_QUADS);
        glColor3ub(124, 123, 123);
        glVertex2f(-163.84122+x,66.75465+20);
        glVertex2f(-153.69106+x,66.49209+20);
        glVertex2f(-157.30838+x,36.34776);
        glVertex2f(-164.49404+x,36.39832);
        glEnd();

    }

}

void drawMovingTrain()  // A303
{

    glPushMatrix();
    glTranslatef(xOffset, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(150.0f, 150.0f, 150.0f);
    glVertex2f(-106 + xOffset, 123);
    glVertex2f(-1.8 + xOffset, 123);
    glVertex2f(4 + xOffset, 97);
    glVertex2f(-109 + xOffset, 97);
    glEnd();
    //train color
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-107.77306 + xOffset,108.66057);
    glVertex2f(2.68616 + xOffset,109.36358);
    glVertex2f(2.88498+ xOffset,103.99561);
    glVertex2f(-107.72416+ xOffset,103.77022);
    glEnd();
    //window
    for(int i = 0 ; i < 90 ; i=i+15)
    {
        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-95 + i + xOffset, 118);
        glVertex2f(-85 + i + xOffset, 118);
        glVertex2f(-85 + i + xOffset, 102);
        glVertex2f(-95 + i+ xOffset, 102);
        glEnd();
    }

    glPopMatrix();
    xOffset += 0.5f;


    if (xOffset > 200)
    {
        xOffset = -200.0f; // Reset to left side
    }
}

void timerforTrain(int value)
{
    glutPostRedisplay();  // Trigger a redraw of the screen
    glutTimerFunc(10, timerforTrain, 0);  // Call the timer function again after 10ms
}

void road1() //O322
{
    glBegin(GL_QUADS);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(-201, -109);
    glVertex2f(-85, -160);
    glVertex2f(-150, -184);
    glVertex2f(-201, -150);
    glEnd();

     //middleLine
    glBegin(GL_LINES);
    if (day == false)
    {
        glColor3ub(170.0f, 170.0f, 170.0f);

    }
    else
    {
        glColor3ub(255.0f, 255.0f, 255.0f);
    }
    glVertex2f(-201, -132);
    glVertex2f(-111, -168);
    glEnd();
}
void road2()  //O323
{

    glBegin(GL_QUADS);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(-200, -200);
    glVertex2f(-29, -200);
    glVertex2f(200, -118);
    glVertex2f(201, -60);
    glEnd();
    glBegin(GL_LINES);

    if (day == false)
    {
        glColor3ub(170.0f, 170.0f, 170.0f);
    }
    else
    {
        glColor3ub(255.0f, 255.0f, 255.0f);
    }
    glVertex2f(-108, -196);
    glVertex2f(200, -90);
    glEnd();
}

void road3()  //O324
{

    glBegin(GL_QUADS);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(148, -86);
    glVertex2f(185, -69);
    glVertex2f(-201, 15);
    glVertex2f(-200, 0);
    glEnd();
    glBegin(GL_LINES);
    if (day == false)
    {
        glColor3ub(170.0f, 170.0f, 170.0f);
    }
    else
    {
        glColor3ub(255.0f, 255.0f, 255.0f);
    }
    glVertex2f(165, -78);
    glVertex2f(-200, 6);
    glEnd();
}

void Traffic1()  // A310
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(-112.02481,-128.54004-15);
    glVertex2f(-112.02481,-68.13455-15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(180.0f, 180.0f, 180.0f);
    glVertex2f(-115.9435,-67.71343-20);
    glVertex2f(-107.02837,-68.12808-20);
    glVertex2f(-107.44303,-78.49451-20-10);
    glVertex2f(-116.98014,-79.1165-20-10);
    glEnd();
    glColor3ub(activeLight == 'R' ? 255 : 50, 0, 0);
    drawCircle2(-112, -93, 2);


    glColor3ub(activeLight == 'Y' ? 255 : 50, activeLight == 'Y' ? 255 : 50, 0);
    drawCircle2(-112, -98, 2);


    glColor3ub(0, 0, activeLight == 'B' ? 255 : 50);
    drawCircle2(-112, -103, 2);
}

void Traffic2() // A311
{
    glPushMatrix();
    glTranslatef(300,90,0);
    Traffic1();
    glPopMatrix();
}


void drawWheel() // A304
{

    // Draw the wheel
    glColor3ub(0, 0, 0);
    drawCircle(31.8f, -129.44f, 5.0f, 380.0f);

    // Draw the spokes
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(31.80317, -129.43969);
    glVertex2f(30.73613, -125.62883);

    glVertex2f(31.80317, -129.43969);
    glVertex2f(32.31129, -133.14893);

    glVertex2f(31.80317, -129.43969);
    glVertex2f(34.24212, -126.94993);

    glVertex2f(31.80317, -129.43969);
    glVertex2f(34.69943, -130.70998);

    glVertex2f(31.80317, -129.43969);
    glVertex2f(29.21179, -132.03108);

    glVertex2f(31.80317, -129.43969);
    glVertex2f(28.90692, -128.42346);
    glEnd();

}

void DrawWheel2() // A305
{
    // Draw the static wheel (circle)
    glColor3ub(0, 0, 0);
    drawCircle(31.8f + 30, -129.44f + 10, 5.0f, 380.0f);

    // Rotate only the spikes
    glPushMatrix();
    glTranslatef(31.8f + 30, -129.44f + 10, 0.0f); // Translate to the center of the wheel
    glRotatef(angle2, 0.0f, 0.0f, 1.0f); // Rotate the spikes
    glTranslatef(-(31.8f + 30), -(-129.44f + 10), 0.0f); // Translate back

    // Draw the rotating spikes
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(31.80317 + 30, -129.43969 + 10);
    glVertex2f(30.73613 + 30, -125.62883 + 10);

    glVertex2f(31.80317 + 30, -129.43969 + 10);
    glVertex2f(32.31129 + 30, -133.14893 + 10);

    glVertex2f(31.80317 + 30, -129.43969 + 10);
    glVertex2f(34.24212 + 30, -126.94993 + 10);

    glVertex2f(31.80317 + 30, -129.43969 + 10);
    glVertex2f(34.69943 + 30, -130.70998 + 10);

    glVertex2f(31.80317 + 30, -129.43969 + 10);
    glVertex2f(29.21179 + 30, -132.03108 + 10);

    glVertex2f(31.80317 + 30, -129.43969 + 10);
    glVertex2f(28.90692 + 30, -128.42346 + 10);
    glEnd();

    glPopMatrix();
}

void updateWheelRotation2(int value)
{
    angle2 += 2.0f;
    if (angle2 > 360.0f)
    {
        angle2 -= 360.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateWheelRotation2, 0);
}

void updateWheelRotation(int value)
{
    angle += 2.0f;
    if (angle > 360.0f)
    {
        angle -= 360.0f;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
    glutTimerFunc(20, updateWheelRotation, 0);
}

void car1()
{
    // Glass
    glBegin(GL_POLYGON);
    glColor3ub(66, 66, 66);
    glVertex2f(22.04148, -97.91601);
    glVertex2f(40.10492, -103.69655201);
    glVertex2f(55.98409, -99.05949);
    glVertex2f(64.0525, -106.11935);
    glVertex2f(33.22122, -114.71048);
    glVertex2f(13.67149, -110.02956);
    glEnd();

    // Top
    glBegin(GL_POLYGON);
    glColor3ub(240, 240, 240);
    glVertex2f(22.04148, -97.91601);
    glVertex2f(40.10492, -103.69655201);
    glVertex2f(55.98409, -99.05949);
    glVertex2f(40.17453, -92.18531);
    glEnd();

    // Body
    glBegin(GL_POLYGON);
    glColor3ub(240, 240, 240);
    glVertex2f(19.5272, -135.03581);
    glVertex2f(19.2427, -122.80202);
    glVertex2f(33.22122, -114.71048);
    glVertex2f(64.0525, -106.11935);
    glVertex2f(74.15252, -106.30062);
    glVertex2f(75.29055, -117.6809);
    glEnd();

    // Front body
    glBegin(GL_POLYGON);
    glColor3ub(220, 220, 220);
    glVertex2f(13.67149, -110.02956);
    glVertex2f(33.22122, -114.71048);
    glVertex2f(19.2427, -122.80202);
    glVertex2f(19.5272, -135.03581);
    glVertex2f(-6.93193, -131.53638);
    glVertex2f(-7.50095, -117.9654);
    glEnd();


    DrawWheel2();
    // Draw Wheel 1
    glPushMatrix();
    glTranslatef(31.8f, -129.44f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-31.8f, 129.44f, 0.0f);
    drawWheel();
    glPopMatrix();


}

void timerforcar1(int value);
void movecar1()  // A306
{
    glPushMatrix();
    glTranslatef(xcar, ycar, 0.0f);
    car1();
    glPopMatrix();
    if(xcar < -200.0f)
    {
        xcar = 200.0f;
        ycar = 50.0f;
    }
    if(activeLight == 'Y' || activeLight == 'B')
    {
        xcar = xcar - 0.4f;
        ycar = ycar - 0.15f;
    }

}

void timerforcar1(int value)
{
    glutPostRedisplay();
    glutTimerFunc(10, timerforcar1, 0);
}
void lamp1() //A307
{

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0);
    //Line From Bottom to top
    glBegin(GL_LINES);
    glVertex2f(-112.02481+50,-128.54004-15);
    glVertex2f(-112.02481+50,-68.13455-15+40);
    glEnd();
    //TOPLINE
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-112.02481+50,-68.13455-15+40);
    glVertex2f(-99.50294+50,-69.69685+10);
    glEnd();

    //Light
    glBegin(GL_POLYGON);
    if(day == true)
    {
        if(lampLight == true)
        {
            glColor3f(1.0f, 1.0f, 0.0f);
        }
        else
        {
            glColor3f(0.66f, 0.66f, 0.66f);
        }
    }
    else
    {
        if(lampLight == true)
        {
            glColor3f(1.0f, 1.0f, 1.0f);
        }
        else
        {
            glColor3f(0.66f, 0.66f, 0.66f);
        }
    }
    glVertex2f(-103.46547+50,-63.05795);
    glVertex2f(-97.00931+50+2,-63.05795);
    glVertex2f(-99.97702+50,-68.20959);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle2(-99.50294+50,-69.69685+10,4);

}

void lamp2() //A308
{

    glPushMatrix();
    glTranslatef(60,20,0);
    lamp1();
    glPopMatrix();
}

void lamp3() //A309
{

    glPushMatrix();
    glTranslatef(120,40,0);
    lamp1();
    glPopMatrix();
}
void daynight(bool value) //A313
{
    day = value;
}

void handleKeypress(unsigned char key, int x, int y)
{

    if (key == 'Y' || key == 'y')
    {
        activeLight = 'Y';
    }
    else if (key == 'R' || key == 'r')
    {
        activeLight = 'R';
    }
    else if (key == 'B' || key == 'b')
    {
        activeLight = 'B';
    }
    else if( key == 'D' || key == 'd')
    {
        daynight(true);
    }
    else if( key == 'N' || key == 'n')
    {
        daynight(false);
    }
    else if( key == 'S' || key == 's')
    {
        snowing = true;;
    }
    glutPostRedisplay();
}
void mouseCallback(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)   // When a button is pressed
    {
        switch (button)
        {
        case GLUT_LEFT_BUTTON:
            lampLight = true;
            break;
        case GLUT_RIGHT_BUTTON:
            lampLight = false;
            break;
        case GLUT_MIDDLE_BUTTON:
            snowing = false;
            break;

        }
    }
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawSnow(0);
    if(day == true)
    {
        glClearColor(0.9f, 0.9f, 1.0f, 1.0f);
    }
    else
    {
        glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    }

    sky();
    Clouds();
    TrainPillar();
    if(day == true)
    {
        drawSun();
    }
    else
    {
        drawMoon();
    }
    road1();
    road2();
    road3();

    disTree1();
    disTree2();
    disTree3();

    Building3();
    Building1();
    Building2();
    disTree4();
    disTree5();
    disTree6();
    disTree7();
    disTree8();

    Traffic1();
    Traffic2();
    drawTrainRoad();
    Bigtree();
    lamp1();
    lamp2();
    lamp3();
    movecar1();

    smallTree1();
    smallTree2();
    smallTree3();
    smallTree4();
    drawMovingTrain();
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Winter Town Area Scene");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, drawSnow, 0);
    glutTimerFunc(16, timerforcar1, 0);
    glutTimerFunc(16, updateWheelRotation2, 0);
    glutTimerFunc(16, updateWheelRotation, 0);
    glutTimerFunc(16, timerforTrain, 0);
    glutTimerFunc(16, updateSun, 0);
    glutTimerFunc(16, updateClouds, 0);

    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(mouseCallback);
    glutMainLoop();
    return 0;
}

