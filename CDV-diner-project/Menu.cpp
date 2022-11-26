#include <iostream>

#include "menu.h"
#include "Category.h"

using namespace std;

// Constructor

Menu::Menu() {
	this->initVaribles();
}

void Menu::initVaribles()
{
	this->choose = 0;
}

void Menu::changeChoose(int _choose)
{
	this->choose = _choose;
}

void Menu::showMenu()
{
	cout << "Witaj w cudownym programie!" << endl;	
	cout << this->list.size() << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].readCategoryName() << endl;
	}
}

void Menu::addCategory(Category cat)
{
	cout << "Add category" << endl;
	this->list.push_back(cat);
}

Menu::~Menu() {};