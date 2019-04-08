#include"acllib.h"
#include"food.h"
#include"snake.h"
#include<iostream>
food fod;
Snake Sna;
void judge()
{
	if (Sna.ate(fod.getx(),fod.gety()))
	{
		fod.beate();
		Sna.longer();
	}
}
void Paintwindow(int id)
{
	beginPaint();
	clearDevice();
	if (Sna.ate(fod.getx(), fod.gety())==true)
	{
		fod.beate();
		Sna.longer();
	}
	//fod.beate();
	Sna.judge();
	fod.creatfood();
	fod.draw();
	Sna.draw();


	Sna.move();
	if (!(Sna.getlife()))
	{
		clearDevice();
		setTextSize(40);
		paintText(150, 200, "GAME OVER");
	}
	endPaint();
}

void keyListener(int key, int event)
{
	Sna.turn(key);
}

int Setup()
{
	//initConsole();
	initWindow("snake", DEFAULT, DEFAULT, 500, 500);
	registerTimerEvent(Paintwindow);
	registerKeyboardEvent(keyListener);
	startTimer(0, 100);
	return 0;
}