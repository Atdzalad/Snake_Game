#pragma once
class Snake
{
public:
	Snake();
	~Snake();
	void draw();
	void move();
	void turn(int key);
	void longer();
	void judge();
	bool getlife();
	bool ate(int fodx,int fody);
private:
	int x[400];     //蛇身横坐标
	int y[400];     //蛇身纵坐标
	int length;     //蛇的长度
	bool life;      //蛇的状态
	int direction;  //方向：0123对应上下左右
};
