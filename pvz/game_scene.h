#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include <scene.h>
#include <iostream>
#include "scene_manager.h"

extern SceneManager scene_manager;


class GameScene :public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter() 
	{
		std::cout << "进入游戏内场景" << std::endl;

	}
	void on_update() 
	{
		std::cout << "游戏在运行" << std::endl;
	}
	void on_draw() 
	{
		outtextxy(10, 10, _T("游戏绘图内容"));
	}
	void on_input(const ExMessage& msg) 
	{
		if (msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Menu);
		}
	}
	void on_exit()
	{
		std::cout << "退出游戏局内" << std::endl;
	}

private:

};


#endif // !_GAME_SCENE_H_
