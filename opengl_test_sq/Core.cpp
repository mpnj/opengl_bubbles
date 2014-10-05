#include "stdafx.h"
#include "Core.h"
#include <string>
//����������
Core::Core()
{//��������� ������������� ����. ��������� ����,������ ������.
	points=0;
	width=600;
	height=600;
}
void Core::showPoints()
{
	glWrite(20, 20, (int*)GLUT_BITMAP_8_BY_13, std::to_string((long double)points));//�������� ����� �� ���������.
}

void Core::glWrite(float x, float y, int *font, std::string text)
{//������� ����� �� �����.(����� ����)
	glColor3f(255,255,255);
	glRasterPos2f(x, y);
	for (int i=0; i<text.length(); i++)
		glutBitmapCharacter(font, text[i]);
}

void Core::gameObserver()
{
	time_t seconds;
	seconds = time (NULL);
	if(coreSeconds!=seconds)//��� � ������� ������� ����� ���
	{
		bubble b;
		bubbles.push_back(b);
		coreSeconds = seconds;
	}
	for(unsigned i=0;i<bubbles.size();i++)
	{//������������� � ������� ����
			bubbles[i].draw();
			bubbles[i].move();
	}
	for(unsigned i=0;i<bubbles.size();i++)
	{
		if(bubbles[i].y<-bubbles[i].radius)//���������,�� ���� �� ��� �� ������� ���������
		{
			bubbles.erase(bubbles.begin()+i);//������� �� �������,���� ��� "����" ������������
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
			{//�� ������� ������������� ��������� ������ ������������ ���������� ����� ����� ����� � ������� ����. ���� ��� ������,������ ���� ������ ���� � ��� ���� ����������.
			 //�������:����������=sqrt((x2-x1)^2 + (y2-y1)^2).
			 //� ��� ��� �������� y-���������� ����� ��������. ������ ��������� � ������� ��������� �����. � ����� newY=600-y;
				if(sqrt((double)((bubbles[i].x-x)*(bubbles[i].x-x)+
								(bubbles[i].y-(600-y))*(bubbles[i].y-(600-y)))
						)<=bubbles[i].radius)
				{
					points+=bubbles[i].v;//�����,��� ���������� ����� ������ ���� ����� ��������. ����� ���� ����� ����������� ����������� ���� ��� ����������� ������� � ��������.
					bubbles.erase(bubbles.begin()+i);//���������� ���.
				}
			}
		}
	}
}