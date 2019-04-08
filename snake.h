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
	int x[400];     //���������
	int y[400];     //����������
	int length;     //�ߵĳ���
	bool life;      //�ߵ�״̬
	int direction;  //����0123��Ӧ��������
};
