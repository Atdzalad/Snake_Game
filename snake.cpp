#include"acllib.h"
#include"snake.h"
#include<iostream>
using namespace std;
Snake::Snake()
{
	life = true;
	direction = 1;
	length = 3;
	x[1] = 250; y[1] = 200;
	x[2] = 250; y[1] = 210;
	x[3] = 250; y[3] = 220;


}

Snake::~Snake()
{
}

void Snake::move()
{
	switch (direction)
	{
	case 0://上↑
		for (int i = length; i > 1 ; i--)
		{
			y[i] = y[i - 1];
			x[i] = x[i - 1];
		}
		y[1]-=10;
		break;
	case 1://下↓
		for (int i = length; i > 1; i--)
		{
			y[i] = y[i - 1];
			x[i] = x[i - 1];
		}
		y[1]+=10;
		break;
	case 2://左←
		for (int i = length; i > 1; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		x[1]-=10;
		break;
	case 3://右→
		for (int i = length; i > 1; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		x[1]+=10;
		break;
	default:
		break;
	}


}
void Snake::turn(int key)
{
	if (key == 0x26 && direction != 0 && direction != 1) {  //按键 ↑
		direction = 0;
	}
	if (key == 0x28 && direction != 1 && direction != 0) {  //按键 ↓
		direction = 1;
	}
	if (key == 0x25 && direction != 2 && direction != 3) {  //按键 ←
		direction = 2;
	}
	if (key == 0x27 && direction != 3 && direction != 2) {  //按键 →
		direction = 3;
	}
}

void Snake::longer()
{
	if (x[length] < x[length - 1])
	{
		x[length + 1] = x[length] - 10;
		y[length + 1] = y[length];
		length++;
		return;
	}
	else
	{
		x[length + 1] = x[length] + 10;
		y[length + 1] = y[length];
		length++;
		return;
	}

	if (y[length] < y[length - 1])
	{
		x[length + 1] = x[length];
		y[length + 1] = y[length] - 10;
		length++;
		return;
	}
	else
	{
		x[length + 1] = x[length];
		y[length + 1] = y[length] + 10;
		length++;
		return;
	}
	return;
}

void Snake::draw()
{
	for (int i = 1; i <= length; i++)
	{
		setBrushColor(RED);
		setPenColor(RED);
		rectangle(x[i], y[i], x[i] + 10, y[i] + 10);
	}
	return;
}

void Snake::judge()
{
	if (x[1] <= -10 || x[1] >= 500 || y[1] >= 500 || y[1] <= -10)
	{
		life = false;
		return;
	}
	for (int i = length; i > 1; i--)
	{
		if (x[i] == x[1] && y[i] == y[1])
		{
			life = false;
			return;
		}
	}
	return;
}

bool Snake::getlife()
{
	return this->life;
}

bool Snake::ate(int fodx, int fody)
{
	//cout <<"SNAKE"<< x[1] << ' ' << y[1] << endl;
	//cout <<"FOOD"<< fodx << ' ' << fody << endl;
	//cout << "length:" << length << endl;
	if (x[1]==fodx&&y[1]==fody)
	{
		return true;
	}
	else
	{
		return false;
	}
}