#include "pch.h"
#include "windows.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <Math.h>

GLuint matTroiObject;
GLuint saoThuyObject;
GLuint saoKimObject;
GLuint traiDatObject;
GLuint matTrangObject;
GLuint saoHoaObject;
GLuint saoMocObject;
GLuint saoThoObject;
GLuint saoHaiVuongObject;
GLuint saoThienVuongObject;

GLuint g_angle_day = 0;
GLuint g_angle_year = 0;
GLuint gl_angle_moon = 0;

GLuint VeKhoiCau(const float& banKinh)
{
	GLint soViTuyen = 64;
	GLint soKinhTuyen = 16;
	GLuint boxDisplay = glGenLists(1);
	glNewList(boxDisplay, GL_COMPILE);
	glutSolidSphere(banKinh, soViTuyen, soKinhTuyen);
	glEndList();
	return boxDisplay;
}

void KhoiTao()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat light_pos[] = { 1.0, 1.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	GLfloat ambient[] = { 1.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

	GLfloat diff_use[] = { 0.5, 0.5, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

	GLfloat shininess = 50.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	matTroiObject = VeKhoiCau(3.0);
	saoThuyObject = VeKhoiCau(0.5);
	saoKimObject = VeKhoiCau(0.9);
	traiDatObject = VeKhoiCau(0.9);
	matTrangObject = VeKhoiCau(0.3);
	saoHoaObject = VeKhoiCau(0.6);
	saoMocObject = VeKhoiCau(1.5);
	saoThoObject = VeKhoiCau(1.3);
	saoHaiVuongObject = VeKhoiCau(1.0);
	saoThienVuongObject = VeKhoiCau(1.0);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	#pragma region Mat troi
	glRotated(20.0, 1.0, 0.0, 0.0f);
	GLfloat materialAmbient[] = { 1.0, 1.0, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialAmbient);
	GLfloat diffuse[] = { 1.0, 0.5, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glCallList(matTroiObject);
	#pragma endregion

	#pragma region Trai dat
	glRotatef(g_angle_year, 0.0f, 1.0f, 0.0f);
	glRotatef(g_angle_day, 0.0f, 1.0f, 0.0f);
	glTranslated(10.0, 0.0, 0.0);

	GLfloat materialAmbient2[] = { 0.0, 0.0, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialAmbient2);
	GLfloat diffuse2[] = { 0.2, 1.0, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse2);
	glCallList(traiDatObject);
	#pragma endregion

	#pragma region Mat trang
	glPushMatrix();
	glRotatef(gl_angle_moon, 0.0f, 1.0f, 0.0f);
	glTranslated(2.0, 0.0, 0.0);

	GLfloat materialAmbient3[] = { 0.7, 0.7, 0.7f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialAmbient3);
	GLfloat diffuse3[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse3);
	glCallList(matTrangObject);
	glPopMatrix();
	#pragma endregion

	Sleep(83);

	gl_angle_moon = (gl_angle_moon + 13);
	if (gl_angle_moon >= 360)
	{
		gl_angle_moon = 0;
	}

	g_angle_day = (g_angle_day + 360);
	if (g_angle_day >= 360)
	{
		g_angle_day = 0;
	}

	g_angle_year = (g_angle_year + 1);
	if (g_angle_year >= 360)
	{
		g_angle_year = 0;
	}

	glutSwapBuffers();
	glFlush();

	glutPostRedisplay();
}

void ReShape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)width / (float)height;
	gluPerspective(45.0, ratio, 1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1440, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("BTCK");

	KhoiTao();
	glutReshapeFunc(ReShape);
	glutDisplayFunc(Display);

	glutMainLoop();
}