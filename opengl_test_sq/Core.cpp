#include "stdafx.h"
#include "Core.h"
#include <string>
//реализация
Core::Core()
{//начальная инициализация игры. стартовые очки,размер экрана.
	points=0;
	width=600;
	height=600;
}
void Core::showPoints()
{
	glWrite(20, 20, (int*)GLUT_BITMAP_8_BY_13, std::to_string((long double)points));//вызываем метод ля отрисовки.
}

void Core::glWrite(float x, float y, int *font, std::string text)
{//выводим текст на экран.(белый цвет)
	glColor3f(255,255,255);
	glRasterPos2f(x, y);
	for (int i=0; i<text.length(); i++)
		glutBitmapCharacter(font, text[i]);
}

void Core::gameObserver()
{
	time_t seconds;
	seconds = time (NULL);
	if(coreSeconds!=seconds)//раз в секунду пускаем новый шар
	{
		bubble b;
		bubbles.push_back(b);
		coreSeconds = seconds;
	}
	for(unsigned i=0;i<bubbles.size();i++)
	{//прописовываем и двигаем шары
			bubbles[i].draw();
			bubbles[i].move();
	}
	for(unsigned i=0;i<bubbles.size();i++)
	{
		if(bubbles[i].y<-bubbles[i].radius)//проверяем,не ушёл ли шар из области видимости
		{
			bubbles.erase(bubbles.begin()+i);//удаляем из вектора,если шар "упал" окончательно
		}
	}
	
}

void Core::mousePressed(int button, int state, int x, int y)
{
	if((button==GLUT_LEFT_BUTTON))
	{
		if ((state==GLUT_DOWN)) 
		{
			for(unsigned i=0;i<bubbles.size();i++)
			{//по формуле аналитической геометрии просто подсчитываем расстояние между метом клика и центром шара. Если оно меньше,значит клик внутри шара и его надо уничтожить.
			 //формула:расстояние=sqrt((x2-x1)^2 + (y2-y1)^2).
			 //и тут ещё пришлось y-координаты клика изменить. Точнее перевести в систему координат шаров. в итоге newY=600-y;
				if(sqrt((double)((bubbles[i].x-x)*(bubbles[i].x-x)+
								(bubbles[i].y-(600-y))*(bubbles[i].y-(600-y)))
						)<=bubbles[i].radius)
				{
					points+=bubbles[i].v;//решил,что количество очков должно быть равно скорости. Тогда очки будут справедливо начисляться даже при минимальной разнице в скорости.
					bubbles.erase(bubbles.begin()+i);//уничтожаем шар.
				}
			}
		}
	}
}