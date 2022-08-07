/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */


#include<GL/gl.h>
#include<GL/glu.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void myInit(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1200.0, 0.0, 800.0);
}

bool cond=true;
int i=0;
float x_pos=0;


void drawBoat();
void tree();
void scene();


void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
	float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

	float x = r * cosf(theta);//calculate the x component
	float y = r * sinf(theta);//calculate the y component

	glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}

void tree()
{
	glBegin(GL_POLYGON); //Tree
	glColor3f(1.2, 0.5, 0.4);
	glVertex2i(435, 344);
	glVertex2i(450, 345);
	glVertex2i(450, 550);
	glVertex2i(435, 550);

	glEnd();
	glColor3f(0.0, 0.7, 0.1);
	DrawCircle(415, 545, 50, 1000); // 4
	glColor3f(0.0, 0.7, 0.1);
	DrawCircle(430, 600, 50, 1000);
	glColor3f(0.0, 0.7, 0.1);
	DrawCircle(460, 550, 50, 1000);

}

void scene()
{

	glBegin(GL_POLYGON); //Sky
	glColor3f(0.4, 0.5, 1.0);
	glVertex2i(0, 800);
	glVertex2i(1200, 800);
	//glColor3f(0.7, 0.7, 1.0);
	glVertex2i(1200, 0);
	glVertex2i(0, 0);
	glEnd();

	glBegin(GL_POLYGON); //Middle ground
	glColor3f(0.0, 0.7, 0.0);
	glVertex2i(0, 100);
	glVertex2i(0, 280);
	glVertex2i(200, 330);
	glVertex2i(400, 350);
	glVertex2i(600, 330);
	glVertex2i(800, 320);
	glVertex2i(1000, 300);
	glVertex2i(1200, 270);
	glVertex2i(1200, 100);

	glEnd();


	glBegin(GL_POLYGON); // River
	glColor3f(0.2, 0.3, 1.1);
	glVertex2i(0, 150);
	glVertex2i(1200, 150);
	glVertex2i(1200, 0);
	glVertex2i(0, 0);
	glEnd();

	//tree();

	glBegin(GL_POLYGON); //House
	glColor3f(0.9, 0.7, 0.1);
	glVertex2i(350, 344);
	glVertex2i(350, 460);
	glVertex2i(430, 460);
	glVertex2i(430, 344);
	glEnd();

	glBegin(GL_POLYGON); //House
	glColor3f(0.9, 0., 0.0);
	glVertex2i(340, 460);
	glVertex2i(390, 500);
	glVertex2i(440, 460);
	glEnd();

	glBegin(GL_POLYGON); //Door
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(370, 344);
	glVertex2i(370, 430);
	glVertex2i(410, 430);
	glVertex2i(410, 344);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(390, 344);
	glVertex2i(390, 430);
	glEnd();


    //rocket
    glBegin(GL_POLYGON);
    glColor3f(0.231, 0.035, 0.267);
    glVertex2f(800,320+i);
    glVertex2f(825,320+i);
    glVertex2f(825,440+i);
    glVertex2f(800,440+i);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.631, 0.145, 0.349);
    glVertex2f(800,440+i);
    glVertex2f(825,440+i);
    glVertex2f(812.5,490+i);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.373, 0.094, 0.329);
    glVertex2f(800,440+i);
    glVertex2f(780,415+i);
    glVertex2f(800,415+i);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(800,320+i);
    glVertex2f(780,320+i);
    glVertex2f(800,370+i);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(825,320+i);
    glVertex2f(845,320+i);
    glVertex2f(825,370.0+i);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(825,440+i);
    glVertex2f(825,415+i);
    glVertex2f(845,415+i);
    glEnd();
    glColor3f(0.945, 0.733, 0.835);
    glBegin(GL_POLYGON);
    glVertex2f(800,320+i);
    glVertex2f(807,320+i);
    glVertex2f(803.5,300+i);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(809,320+i);
    glVertex2f(816,320+i);
    glVertex2f(812,300+i);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(825,320+i);
    glVertex2f(817.5,320+i);
    glVertex2f(820.5,300+i);
    glEnd();


    glutPostRedisplay();

}


void drawBoat()
{
    glTranslatef(0,0,0);
	glBegin(GL_POLYGON); // Boat Starts
	glColor3f(0.7, 0.8, 0.1);
	glVertex2i((x_pos+230), 100);
	glVertex2i((x_pos+230), 165);
	glVertex2i((x_pos+480), 165);
	glVertex2i((x_pos+480), 100);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.5, 0.1);
	glVertex2i((x_pos+250), 20);
	glVertex2i((x_pos+220), 100);
	glVertex2i((x_pos+550), 100);
	glVertex2i((x_pos+500), 20);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.1, 0.1);
	glVertex2i((x_pos+235), 135);
	glVertex2i((x_pos+235), 160);
	glVertex2i((x_pos+270), 160);
	glVertex2i((x_pos+270), 135);
	glEnd();

	glFlush();

}

void timer(int) {

    glutTimerFunc(1000/600, timer, 0);

    // moving object forward
    if (x_pos < 980 &&  cond)
    {
       x_pos+=0.5;


    }

    else  {
        x_pos -= 5;
        cond=false;
    }


    // moving rocket upward
    if(i<1200)
        i+=3;
    else{
        i=0;
    }


}

void myDisplay(void)
{
	scene();
	tree();
    drawBoat();
	glFlush();

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1250, 600);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("2D_Rocket_Boat_scenerio");
	glutDisplayFunc(myDisplay);
	glutTimerFunc(0,timer,0);
	myInit();
	glutMainLoop();
}
