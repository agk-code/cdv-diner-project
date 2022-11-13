#include <iostream>

#include "menu.h";

using namespace std;

string name = "";

void setName() {
	cout << "Podaj imie: ";
	cin >> name;
}

int main()
{
		
	Menu menu;

	setName();

	menu.showMenu();
}
