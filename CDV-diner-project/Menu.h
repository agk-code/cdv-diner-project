#pragma once
class Menu
{
private:
	int choose;
	void initVaribles();
	void changeChoose(int choose);
public:
	void showMenu();
	Menu();
	~Menu();
};

