#include "Menu.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

// Constructor
Menu::Menu()
{
	this->choose = '1';
}

// Destructor
Menu::~Menu() {}

// Main menu loop
void Menu::initMenu(string *name, ProductsList productList)
{
	this->setName(name);
	while (true) {
		this->categoryMenu(productList);
		cout << "q - Wyjdz\n";
		cout << "Wybor: ";
		cin >> this->choose;
		if (this->choose == 'q') {
			exit(0);
		}
		else {
			system("cls");
			//Checking if user choose is a number
			if (((int)choose - 49) >= 0 && ((int)choose - 48) <= productList.readProductList().size()) {
				this->dishesMenu(productList.readProductList()[((int)choose - 49)]);
			}
		}
	};
}

// Set username
void Menu::setName(std::string *name)
{
	cout << "Podaj imie: ";
	cin >> *name;
	system("cls");
}

// Render category menu
void Menu::categoryMenu(ProductsList productList)
{
	cout << "Menu Kategorii" << endl;
	for (int i = 0; i < productList.readProductList().size(); i++) {
		cout << (i + 1) << ". " << productList.readProductList()[i].readCategoryName() << endl;
	}
}

// Render dishes menu
void Menu::dishesMenu(Category category)
{
	cout << "Kategoria " << category.readCategoryName() << endl;
	//TODO Do it better
	cout << "ID Nazwa Cena Czas Przygotowania" << endl;
	for (int i = 0; i < category.readDishList().size(); i++) {
		cout << (i + 1)
			<< ". "
			<< category.readDishList()[i].readDishName()
			<< "  "
			<< category.readDishList()[i].readDishPrice()
			<< "  "
			<< category.readDishList()[i].readDishTime()
			<< endl;
	}
	system("pause");
	system("cls");
}
