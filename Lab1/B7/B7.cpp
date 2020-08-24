// Lab_1.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include "windows.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"


const int screenWidth = 640;
const int screenHeight = 480;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void DrawRectangle(GLint x, GLint y, GLint a, GLint b)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2i(x, y);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2i(x + a, y);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2i(x + a, y + b);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(x, y + b);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	GLint w = 400;
	GLint h = 200;
	GLint x = (screenWidth - w) / 2;
	GLint y = (screenHeight - h) / 2;
	DrawRectangle(x, y, w, h);

	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	glMatrixMode(GL_MODELVIEW);
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


