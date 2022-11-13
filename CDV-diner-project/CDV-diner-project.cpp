#include <iostream>
#include <vector>

#include "Menu.h";
#include "Category.h";
#include "Dish.h";

using namespace std;

string name = "";
vector<Dish> cart;
bool delivery = false;

void createMenu(Menu menu) {
	Dish dish1("Zupa", "Opis", "1.Woda\n 2.Makaron\n", "1.Makraon\n", 13.37, 100000);
	Dish dish2;
	cout << dish1.readDishName() << endl;
	cout << dish2.readDishName() << endl;
	vector<Dish> list { dish1, dish2 };
	Category zupy("Zupy", list);
	menu.addCategory(zupy);

}

void setName() {
	cout << "Podaj imie: ";
	cin >> name;
}

int main()
{
		
	Menu menu;

	setName();

	createMenu(menu);

	menu.showMenu();

}
