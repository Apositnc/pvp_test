#ifndef _ATLAS_H_
#define _ATLAS_H_

#include<vector>
#include<graphics.h>

class Atlas
{
public:
	Atlas() = default;
	~Atlas() = default;

	//加载指定路径的图片到类中
	void load_from_file(LPCTSTR path_template, int num)
	{
		img_list.clear();
		img_list.resize(num);

		TCHAR path_file[256];
		for (int i = 0; i < num; i++)
		{
			_stprintf(path_file,path_template,i + 1);
			loadimage(&img_list[i],path_file);
		}
	}

	void clear()
	{
		img_list.clear();
	}

	int get_size()
	{
		return (int)img_list.size();
	}

	//获取实际渲染的动画帧
	IMAGE* get_image(int idx)
	{
		if (idx < 0 || idx >= img_list.size())
			return nullptr;
		return &img_list[idx];
	}

	//向图集中加载图片
	void add_image(const IMAGE& img)
	{
		img_list.push_back(img);
	}



private:
	std::vector<IMAGE> img_list;
};


#endif // !_ATLAS_H_

