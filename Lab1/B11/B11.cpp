// Lab_1.cpp : Defines the entry point for the console application.
//not same lab

#include "pch.h"
#include "windows.h"
#include "math.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#define STEPS 40
#define PI 3.14


const int screenWidth = 640;
const int screenHeight = 480;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void GLCircle(GLint x, GLint y, GLint radius)
{
	GLfloat twicePi = (GLfloat) 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);

	glVertex2i(x, y);
	for (int i = 0; i <= STEPS; i++)
	{
		glVertex2i((GLint)(x + (radius*cos(i*twicePi / STEPS)) + 0.5), (GLint)(y + (radius*sin(i*twicePi / STEPS)) + 0.5));
	}

	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	GLfloat r = 1.0f;
	GLfloat g = 1.0f;
	GLfloat b = 1.0f;

	for (int j = 200; j > 0; j -= 30)
	{
		glColor3f(r, g, b);
		GLCircle(320, 240, j);
		r -= 0.1f;
		g -= 0.2f;
		b -= 0.3f;
	}

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
