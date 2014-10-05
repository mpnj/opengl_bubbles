
#include <stdlib.h>
#include <glut.h>
#include <math.h>

// интерфейс

class bubble // класс предназначен для представления "пузырей".
{
public:
	bubble();
	int x;//координата x
	int y;//координата y
	int radius;//радиус шара
	int v;//скорость
	void draw();//рисование шара
	void move();//метод для реализации "падения" шара
private:
	float color_r;//цвет шара r
	float color_g;//цвет шара g
	float color_b;//цвет шара b
};
