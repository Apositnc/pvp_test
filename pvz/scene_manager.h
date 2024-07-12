#include <scene.h>
#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

//获取全局指针引用
extern Scene* menu_scene;
extern Scene* game_scene;
extern Scene* selector_scene;

class SceneManager
{
public:
	enum class SceneType
	{
		Menu,
		Game,
		Selector
	};
public:
	SceneManager() = default;
	~SceneManager() = default;

	void set_cruuent_scene(Scene* scene)
	{//使用私有成员current_state 保存当前场景指针
		current_scene = scene;
		current_scene->on_enter();
	}

	//跳转场景
	void switch_to(SceneType type)
	{
		current_scene->on_exit();//首先退出当前场景
		switch (type)
		{
		case SceneType::Menu:
			current_scene = menu_scene;
			break;
		case SceneType::Game:
			current_scene = game_scene;
			break;
		case SceneType::Selector:
			current_scene = selector_scene;
			break;
		default:
			break;
		}//找到新的场景，调用on—enter（）；
		current_scene->on_enter();
	}

	void on_update() 
	{
		current_scene->on_update();
	}
	void on_draw() 
	{
		current_scene->on_draw();
	}
	void on_input(const ExMessage& msg) 
	{
		current_scene->on_input(msg);
	}

private:
	Scene* current_scene = nullptr;
};



#endif // !_SCENE_MANAGER_H_
