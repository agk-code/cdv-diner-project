#include <iostream>

#include "menu.h"

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
}

Menu::~Menu() {};