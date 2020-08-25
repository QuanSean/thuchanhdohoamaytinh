// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "windows.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <Math.h>
#define PI 3.14159265f

// tiêu đề cửa sổ 
char title[] = "Bouncing Ball (2D)";
// kích thước cửa sổ
int windowWidth = 640;
int windowHeight = 480;

int windowPosX = 50;
int windowPosY = 50;
//bán kính bóng
GLfloat ballRadius = 0.5f; 

GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;

GLfloat ballXMax, ballXMin, ballYMax, ballYMin;
// tốc độ di chuyển theo phương dọc và phương ngang
GLfloat xSpeech = 0.02f;
GLfloat ySpeech = 0.007f;

int refreshMillis = 30;

GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

void initGl() {
	glClearColor(0.0, 0.0, 0.0, 1.0);

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(ballX, ballY, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 1.0f, 1.0f); //màu bóng
	glVertex2f(0.0f, 0.0f); 
	int numSegments = 100;

	GLfloat angle;
	for (int i = 0; i <= numSegments; i++) {
		angle = i * 2.0f* PI / numSegments;
		glVertex2f(cos(angle)* ballRadius, sin(angle) * ballRadius);
	}
	glEnd();
	glutSwapBuffers();

	ballX += xSpeech;
	ballY += ySpeech;

	if (ballX > ballXMax) {
		ballX = ballXMax;
		xSpeech = -xSpeech;
	}
	else if (ballX < ballXMin) {
		ballX = ballXMin;
		xSpeech = -xSpeech;
	}
	if (ballY > ballYMax) {
		ballX = ballYMax;
		ySpeech = -ySpeech;
	}
	else if (ballY < ballYMin) {
		ballY = ballYMin;
		ySpeech = -ySpeech;
	}
}

void reshape(GLsizei width, GLsizei height) {
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height) {
		clipAreaXLeft = -1.0 * aspect;
		clipAreaXRight = 1.0 * aspect;
		clipAreaYBottom = -1.0;
		clipAreaYTop = 1.0;
	}
	else {
		clipAreaXLeft = -1.0;
		clipAreaXRight = 1.0;
		clipAreaYBottom = -1.0 / aspect;
		clipAreaYTop = 1.0 / aspect;
	}
	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYBottom);
	ballXMin = clipAreaXLeft + ballRadius;
	ballXMax = clipAreaXRight - ballRadius;
	ballYMin = clipAreaYBottom + ballRadius;
	ballYMax = clipAreaYTop - ballRadius;
}

void Timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(refreshMillis, Timer, 0);

}
int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);

	glutInitWindowSize(windowHeight, windowHeight);

	glutInitWindowPosition(windowPosX, windowPosY);

	glutCreateWindow(title);

	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutTimerFunc(0, Timer, 0);
	initGl();
	glutMainLoop();
	return 0;

}