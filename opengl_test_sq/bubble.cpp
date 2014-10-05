#include "StdAfx.h"
#include "bubble.h"

//����������

bubble::bubble()
{
	int deltaV = rand()%20;//������������ ������������ ������� ����. 
	radius=20 + deltaV;//������ ����
	x=radius+rand()%(600-2*radius);//������� ����� ����� ���,����� ��� ������ ������ ��������� � �����
	y=600-radius;//�� y ����� ���������� ��������� � ������� ������
	v = 10 - deltaV/2; //�������� ������� �� �������. 
	//��� ��������� ����� ���� (rand()%800), � �� (rand()%1000),����� �������� ������� ������ ��������� ��������� ������� ����
	color_r = 1-((float)(rand()%800))/1000;
	color_g = 1-((float)(rand()%800))/1000;
	color_b = 1-((float)(rand()%800))/1000;
}

void bubble::draw()
{
			glColor3f(color_r,color_g,color_b);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glBegin(GL_POLYGON);
			for(double d = 0; d <= 2 * 3.14; d += 0.01)//������ � ���� �����
				glVertex2d(cos(d)*radius+x, sin(d)*radius+y);
			glEnd();
}

void bubble::move()
{
	y-=v;//���������� ��� ��� "������".
};