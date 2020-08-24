// B14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "windows.h"
#include "math.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"


const int screenWidth = 640;
const int screenHeight = 480;
const double r = 150;
const double pi = 3.141592654;

struct GLdoublePoint
{
	GLdouble x;
	GLdouble y;
};

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_FLAT);
}

void DrawStar()
{
	glBegin(GL_POINTS);

	GLdoublePoint v0, v1, v2, v3, v4, v5;
	GLdoublePoint v6, v7, v8, v9, v10;
	//ngoai
	v0.x = screenWidth / 2;
	v0.y = screenHeight / 2;

	v1.x = v0.x;
	v1.y = v0.y + r;

	v2.x = v0.x + r * sin(2 * pi / 5);
	v2.y = v0.y + r * cos(2 * pi / 5);

	v3.x = v0.x + r * sin(pi / 5);
	v3.y = v0.y - r * cos(pi / 5);

	v4.x = v0.x - r * sin(pi / 5);
	v4.y = v0.y - r * cos(pi / 5);

	v5.x = v0.x - r * sin(2 * pi / 5);
	v5.y = v0.y + r * cos(2 * pi / 5);
	//trong
	v6.x = v0.x;
	v6.y = v0.y - r/2;

	v7.x = v0.x + r / 2 * sin(2 * pi / 5);
	v7.y = v0.y - r / 2 * cos(2 * pi / 5);

	v8.x = v0.x + r / 2 * sin(pi / 5);
	v8.y = v0.y + r / 2 * cos(pi / 5);

	v9.x = v0.x - r / 2 * sin(pi / 5);
	v9.y = v0.y + r / 2 * cos(pi / 5);

	v10.x = v0.x - r / 2 * sin(2 * pi / 5);
	v10.y = v0.y - r / 2 * cos(2 * pi / 5);

	glVertex2d(v1.x, v1.y);
	glVertex2d(v2.x, v2.y);
	glVertex2d(v3.x, v3.y);
	glVertex2d(v4.x, v4.y);
	glVertex2d(v5.x, v5.y);

	glVertex2d(v6.x, v6.y);
	glVertex2d(v7.x, v7.y);
	glVertex2d(v8.x, v8.y);
	glVertex2d(v9.x, v9.y);
	glVertex2d(v10.x, v10.y);

	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);
	glColor3f(0.0f, 0.0f, 0.0f);

	DrawStar();

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
