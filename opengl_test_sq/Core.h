#include <time.h>
#include "bubble.h"
#include <vector>

//интерфейс

class Core //"ядро" игры
{
public:
	Core();
	void showPoints();//показать кол-во очков.
	void gameObserver();//следит за состояние шаров. создаёт новые и уничтожает старые.
	void mousePressed(int button, int state, int x, int y);//обработчик клика. Лопает шары и начисляет очки.
	int width;//ширина окна
	int height;//высота окна
private:
	std::vector<bubble> bubbles;//тут будут храниться шары. Решил использовать вектор,т.к. по нему чаще нужно перемещаться(на каждом кадре),чтобы делать проверки,чем удалять из него что-то. Хотя есть вставка конечно.
	int points;//набранные очки.
	time_t coreSeconds;//чтобы контролировать добавление новых шаров по времени
	void glWrite(float x, float y, int *font, std::string text);//метод для вывода текста на экран. В моём случае это будет кол-вл очков.
};