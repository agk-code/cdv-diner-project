#pragma once
#include <vector>
#include "Category.h"
class Menu
{
private:
	int choose;
	std::vector<Category> list;
	void initVaribles();
	void changeChoose(int choose);
public:
	void showMenu();
	void addCategory(Category cat);

	Menu();
	~Menu();
};
