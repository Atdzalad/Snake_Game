#include"acllib.h"
#include"food.h"
#include<stdlib.h>
#include<time.h>


food::food()
{
	status = false;
	x = 5;
	y = 5;
}

food::~food()
{
}

void food::draw()
{
	if (status)
	{
		setBrushColor(GREEN);
		setPenColor(GREEN);
		rectangle(x, y, x + 10, y + 10);
	}
	return;
}

void food::creatfood()
{
	
	if (!status) 
	{
		srand((unsigned)time(0));
		
		x = (rand() % (490 - 0)) + 0;
		while (x % 10 != 0) {
			x--; //�ж�ʳ���x�����Ƿ�Ϊ���������Ǿ͵���
		}
		
		y = (rand() % (490 - 0)) + 0;
		while (y % 10 != 0) {
			y--; //�ж�ʳ���y�����Ƿ�Ϊ���������Ǿ͵���
		}
		status = true;
	}
}
void food::beate()
{
	status = false;
}

int food::getx()
{
	return x;
}
int food::gety()
{
	return y;
}