#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include <scene.h>
#include <iostream>

class MenuScene : public Scence
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter()
	{
		std::cout << "�������˵�" << std::endl;
	}
	void on_update() 
	{
		std::cout << "���˵���������..." << std::endl;
	}
	void on_draw() 
	{
		outtextxy(10,10,_T("���˵���ͼ����"));
	}
	void on_input(const ExMessage& msg) {}
	void on_exit()
	{
		std::cout << "���˵��˳�" << std::endl;
	}

private:

};

#endif // !_MENU_SCENE_H_
