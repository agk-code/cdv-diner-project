#include "Menu.h"
#include "CartProduct.h"
#include "Bill.h"
#include "Utils.h"

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

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
void Menu::initMenu(string *name, ProductsList productList, int *tableNumber, bool *delivery, std::string *deliveryTime)
{
	this->showRestaurantData();
	this->setName(name);
	this->setDelivery(delivery);
	if (delivery) {
		this->deliveryChosen(deliveryTime);
	} else {
    this->setTable(tableNumber);
  }
  
	while (true) {
		this->categoryMenu(productList);
		cout << "q - Wyjdz\n";
		cout << "k - Koszyk\n\n";
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

void Menu::showRestaurantData()
{
	cout << "Witaj w restauracji Czerowne Placki\n\n";
	cout << "Najlepsze placki w calej galaktyce\n\n";
	cout << "Ziemianska 182/4, Kolepka Nowej Nadzieji - Mars\n\n";
	cout << "Aby zamowic nacisnij enter\n\n";
	system("pause");
	system("cls");
}

// Set username
void Menu::setName(std::string *name)
{
	cout << "Podaj imie: ";
	cin >> *name;
	system("cls");
}

void Menu::setTable(int* tableNumber)
{
	int tempInput;
	while (true) {
		system("cls");
		cout << "Podaj numer stolika (1-10): ";
		cin >> tempInput;
		while (!cin.good()) {
			system("cls");
			cout << "Podano nie poprawny numer stolika" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Podaj numer stolika (1-10): ";
			cin >> tempInput;
		}
		if (tempInput > 0 && tempInput < 11) {
			break;
		}
		else {
			system("cls");
			cout << "Podano liczbe ze zlego zakresu" << endl;
			system("pause");
		}
	}
	*tableNumber = tempInput;
	system("cls");
}

void Menu::setDelivery(bool* delivery) {
	int answer;
	cout << "Jedzenie na miejscu (0) czy dostawa (1)? ";
	while (true) {
		cin >> answer;
		if (answer == 0) {
			*delivery = false;
			break;
		}
		if (answer == 1) {
			*delivery = true;
			break;
		}
		system("cls");
		cout << "Podaj prawidlowa wartosc";

	}
}

void Menu::deliveryChosen(std::string *deliveryTime) {
	time_t currentTime;
	time(&currentTime);
	struct tm* date;
	date = localtime(&currentTime);
	int year, month, day, hour, minutes;
	day = date->tm_mday;
	month = date->tm_mon + 1;
	year = date->tm_year + 1900;
	hour = date->tm_hour;
	minutes = date->tm_min;

	const int maxHour = 23, maxMinutes = 60;
	
	int deliveryHour, deliveryMinutes;
	char c;
	cout << "Podaj godzine dostawy (HH:MM): ";
	while (true) {
	    cin >> deliveryHour >> c >> deliveryMinutes;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    if((deliveryHour < maxHour && deliveryMinutes < maxMinutes) &&
	       (hour < deliveryHour)){
	        deliveryMinutes = round(deliveryMinutes/10) * 10;
			*deliveryTime = to_string(day) + "." + to_string(month) + "." + to_string(year) + ", " + 
				to_string(deliveryHour) + c + to_string(deliveryMinutes);
	        break;
		}
	}
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
	while (true) {
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
		cout << "\np - powrot\n\n";
		cout << "Wybierz produkt: ";
		cin >> this->chooseDish;
		system("cls");
		if (this->chooseDish == 'p') break;
		//Checking if user choose is a number
		int tempChose = ((int)this->chooseDish - 49);
		if (tempChose >= 0 && ((int)this->chooseDish - 48) <= (int)category.readDishList().size()) {
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
			break;
			//}
		}
		system("cls");
	}
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
	cout << "\nczas przygotowania to: " << Utils::PrepTime(this->cart.readCartList()) << endl;
	cout << "\np - Przejdz do podsumowania\n";
	cout << "Dowolny inny wybor - powrot\n\n";
	cout << "Wybor: ";
	cin >> this->chooseBasket;
	if (this->chooseBasket == 'p') {
		Bill bill;
		bill.createBill(this->cart);
		exit(0);
	}
	system("cls");
}
