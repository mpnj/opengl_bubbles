#include "StdAfx.h"
#include "bubble.h"

//реализация

bubble::bubble()
{
	int deltaV = rand()%20;//обеспечивает варьирование размера шара. 
	radius=20 + deltaV;//радиус шара
	x=radius+rand()%(600-2*radius);//формула имеет такой вид,чтобы шар всегда влезал полностью в экран
	y=600-radius;//по y также обеспечено вхождение в область экрана
	v = 10 - deltaV/2; //скорость зависит от радиуса. 
	//при генерации цвета беру (rand()%800), а не (rand()%1000),чтобы избежать редкого случая генерации абсолютно чёрного шара
	color_r = 1-((float)(rand()%800))/1000;
	color_g = 1-((float)(rand()%800))/1000;
	color_b = 1-((float)(rand()%800))/1000;
}

void bubble::draw()
{
			glColor3f(color_r,color_g,color_b);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glBegin(GL_POLYGON);
			for(double d = 0; d <= 2 * 3.14; d += 0.01)//рисуем в виде круга
				glVertex2d(cos(d)*radius+x, sin(d)*radius+y);
			glEnd();
}

void bubble::move()
{
	y-=v;//заставляем наш шар "падать".
};