// opengl_test_sq.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Core.h"

Core core;//������ ������ ���� ����. 

//���������� ������� �������� ��� ������� ���� � ���� ����������� ������� � �����,�� ��� ����������,��� ������������ �� ����� ����� ����������. ������� �������� �� ���.

void mouse(int button, int state, int x, int y)
{
	core.mousePressed(button, state, x, y);//������� ���������� core ��� ������������ �� ����.
}

void display()//�������� ������� ��� ���������. ����� ���������� ���� ������ core.
{
	glClear(GL_COLOR_BUFFER_BIT);
	core.gameObserver();
	core.showPoints();
	glFlush();
}

void timer(int = 0)//�������������� ����� �����.
{
	display();
	glutTimerFunc(50,timer,0);
}

int main( int argc, char **argv)
{
	//�������������� ����������� ���������� ��� ������ � OpenGL.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(core.width,core.height);
	glutCreateWindow("bubbles");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,core.width,0,core.height);
	glutDisplayFunc(display);
	glutTimerFunc(50,timer,0);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

