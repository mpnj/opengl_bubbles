
#include <stdlib.h>
#include <glut.h>
#include <math.h>

// ���������

class bubble // ����� ������������ ��� ������������� "�������".
{
public:
	bubble();
	int x;//���������� x
	int y;//���������� y
	int radius;//������ ����
	int v;//��������
	void draw();//��������� ����
	void move();//����� ��� ���������� "�������" ����
private:
	float color_r;//���� ���� r
	float color_g;//���� ���� g
	float color_b;//���� ���� b
};
