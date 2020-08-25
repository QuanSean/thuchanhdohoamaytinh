#include "pch.h"
#include "windows.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
}

void display() {

	//xóa bộ đệm màu cửa sổ
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glutSolidTeapot(1.0);
	glFlush();

}

void reshape(int width, int height) {

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	//sử dụng ma trận MODEVIEW
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char * argv[]) {

	glutInit(&argc, argv);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutCreateWindow("hello, teapot!");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

	glutMainLoop();
}