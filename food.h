#pragma once
class food
{
public:
	food();
	~food();
	void draw();
	void creatfood();
	void beate();
	int getx();
	int gety();

private:
	int x;
	int y;
	bool status;
};

