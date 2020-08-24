// Lab_1.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include "windows.h"
#include "math.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

#define STEPS 40
#define MAX_STARS 500
#define PI 3.14159265358979323846


const int screenWidth = 640;
const int screenHeight = 480;

typedef struct star
{
	GLint x, y, radius, velocity;
	GLfloat intensidty;

}STAR;

STAR sky[MAX_STARS];

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
		glVertex2i( (GLint)(x + (radius*cos(i*twicePi / STEPS)) + 0.5), 
					(GLint)(y + (radius*sin(i*twicePi / STEPS)) + 0.5));
	}

	glEnd();
}

void SkyInit()
{
	for (int i = 0; i < MAX_STARS; i++)
	{
		sky[i].x = rand() % screenWidth;
		sky[i].y = rand() % screenHeight;
		sky[i].radius = 1 + rand() % 3;
		sky[i].intensidty = sky[i].radius / 3.0f;
		sky[i].velocity = sky[i].radius * 2 + rand() % 3;
	}
}

void SkyDraw()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < MAX_STARS; i++)
	{
		glColor3f(sky[i].intensidty, sky[i].intensidty, sky[i].intensidty);
		GLCircle(sky[i].x, sky[i].y, sky[i].radius);
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	GLfloat r = 1.0;
	GLfloat g = 1.0;
	GLfloat b = 1.0;
	glColor3f(r, g, b);

	glPushMatrix();
	SkyDraw();
	glPopMatrix();
	glutSwapBuffers();
}

void Update()
{
	for (int i = 0; i < MAX_STARS; i++)
	{
		/*sky[i].x += sky[i].velocity;
		if (sky[i].x >= screenWidth)
		{
			sky[i].x = 0;
			sky[i].y = rand() % screenHeight;
			sky[i].radius = 1 + rand() % 3;
			sky[i].intensidty = sky[i].radius / 3.0f;
			sky[i].velocity = sky[i].radius * 2 + rand() % 3;
		}*/

		sky[i].x -= sky[i].velocity; //
		if (sky[i].x <= 0) //
		{
			sky[i].x = screenWidth; //
			sky[i].y = rand() % screenHeight;
			sky[i].radius = 1 + rand() % 3;
			sky[i].intensidty = sky[i].radius / 3.0f;
			sky[i].velocity = sky[i].radius * 2 + rand() % 3;
		}
	}
	Sleep(50);
	glutPostRedisplay();
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
	SkyInit();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(Update);
	glutMainLoop();
	return 0;
}
