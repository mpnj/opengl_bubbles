#include <time.h>
#include "bubble.h"
#include <vector>

//���������

class Core //"����" ����
{
public:
	Core();
	void showPoints();//�������� ���-�� �����.
	void gameObserver();//������ �� ��������� �����. ������ ����� � ���������� ������.
	void mousePressed(int button, int state, int x, int y);//���������� �����. ������ ���� � ��������� ����.
	int width;//������ ����
	int height;//������ ����
private:
	std::vector<bubble> bubbles;//��� ����� ��������� ����. ����� ������������ ������,�.�. �� ���� ���� ����� ������������(�� ������ �����),����� ������ ��������,��� ������� �� ���� ���-��. ���� ���� ������� �������.
	int points;//��������� ����.
	time_t coreSeconds;//����� �������������� ���������� ����� ����� �� �������
	void glWrite(float x, float y, int *font, std::string text);//����� ��� ������ ������ �� �����. � ��� ������ ��� ����� ���-�� �����.
};