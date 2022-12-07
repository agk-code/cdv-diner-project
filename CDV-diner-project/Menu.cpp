#include "Menu.h"
#include "CartProduct.h";
#include "Bill.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

// Constructor
Menu::Menu(Cart *_cart)
{
	this->cart = *_cart;
	this->chooseCategory = '1';
	this->chooseDish = '1';
	this->chooseBasket = '1';
}

// Destructor
Menu::~Menu() {}

// Main menu loop
void Menu::initMenu(string *name, ProductsList productList, bool *delivery)
{
	this->setName(name);
	this->setDelivery(delivery);
	if (delivery) {
		this->deliveryTime();
	}

	while (true) {
		this->categoryMenu(productList);
		cout << "q - Wyjdz\n";
		cout << "k - Koszyk\n";
		cout << "Wybor: ";
		cin >> this->chooseCategory;
		if (this->chooseCategory == 'q') {
			exit(0);
		}
		if (this->chooseCategory == 'k') {
			this->basketMenu();
		}
		else {
			system("cls");
			//Checking if user choose is a number
			if (((int)chooseCategory - 49) >= 0 && ((int)chooseCategory - 48) <= (int)productList.readProductList().size()) {
				this->dishesMenu(productList.readProductList()[((int)chooseCategory - 49)]);
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

void Menu::setDelivery(bool* delivery) {
	int answer;
	cout << "Jedzenie na miejscu (0) czy dostawa (1)? ";
	cin >> answer;
	while (true) {
		if (answer == 0) {
			*delivery = false;
			break;
		}
		if (answer == 1) {
			*delivery = true;
			break;
		}
		system("cls");
		cout << "Podaj prawid³ow¹ wartoœæ";
	}
}

string Menu::deliveryTime() {
//	const time_t currentTime = std::time(nullptr);
//	const std::tm calendar_time = *std::localtime(std::addressof(currentTime));
//	const int currentDay = calendar_time.tm_mday;
//	const int currentMonth = calendar_time.tm_mon;
//	const int currentYear = calendar_time.tm_year + 1900;

//	cout << "Podaj godzinê dostawy: ";
//	std::string deliveryTimeInput;
//	cin >> deliveryTimeInput; 

	return "";
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
	cin >> this->chooseDish;
	system("cls");
	//Checking if user choose is a number
	int tempChose = ((int)chooseDish - 49);
	if (tempChose >= 0 && ((int)chooseDish - 48) <= (int)category.readDishList().size()) {
		//if (this->cart.readCartList().size() > 0) {
		//	for (int i = 0; i < cart.readCartList().size(); i++) {
		//		if (this->cart.readCartList()[i].readProductName() == category.readDishList()[tempChose].readDishName()) {
		//			this->cart.readCartList()[i] = CartProduct(category.readDishList()[tempChose], this->cart.readCartList()[i].readProductQuantity() + 1);
		//		}
		//	}
		//}
		//else {
			CartProduct tempCartProduct(category.readDishList()[tempChose], 1);
			this->cart.addProduct(tempCartProduct);
		//}
	}
	system("cls");
}

void Menu::basketMenu() {
	system("cls");
	cout << "Koszyk" << endl;
	cout << "ID Nazwa Cena Czas Przygotowania Ilosc" << endl;
	for (int i = 0; i < this->cart.readCartList().size(); i++) {
		cout << (i + 1) << ". " 
			<< this->cart.readCartList()[i].readProductName()
			<< "   "
			<< this->cart.readCartList()[i].readProductPrice()
			<< "   "
			<< this->cart.readCartList()[i].readProductTime()
			<< "   "
			<< this->cart.readCartList()[i].readProductQuantity()
			<< endl;
	}
	cout << "p - Przejdz do podsumowania\n";
	cout << "Dowolny klawisz - powrot\n";
	cout << "Wybor: ";
	cin >> this->chooseBasket;
	if (this->chooseBasket == 'p') {
		Bill bill;
		bill.createBill(this->cart);
	}
	system("cls");
}
