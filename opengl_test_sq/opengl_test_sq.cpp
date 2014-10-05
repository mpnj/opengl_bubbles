// opengl_test_sq.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Core.h"

Core core;//создаём объект ядра игры. 

//попробовал сначала упрятать три функции ниже в виде статических методов в класс,но мне показалось,что прозначность от этого очень пострадала. Поэтому оставляю их тут.

void mouse(int button, int state, int x, int y)
{
	core.mousePressed(button, state, x, y);//передаём управление core для реагирования на клик.
}

void display()//основная функция для отрисовки. Здесь производит свою работу core.
{
	glClear(GL_COLOR_BUFFER_BIT);
	core.gameObserver();
	core.showPoints();
	glFlush();
}

void timer(int = 0)//перерисовывает новые кадры.
{
	display();
	glutTimerFunc(50,timer,0);
}

int main( int argc, char **argv)
{
	//инициализируем необходимые компоненты для работы с OpenGL.
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

