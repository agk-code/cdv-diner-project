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
#include <regex>

using namespace std;

// Constructor
Menu::Menu(Cart *_cart)
{
	this->cart = *_cart;
	this->chooseCategory = '1';
	this->chooseDish = '1';
	this->chooseBasket = '1';
	this->chooseEditBasket = '1';
}

// Destructor
Menu::~Menu() {}

// Main menu loop
void Menu::initMenu(string *name, ProductsList productList, int *tableNumber, bool *delivery, std::string *deliveryTime, std::string* address)
{
	this->showRestaurantData();
	this->setName(name);
	this->setDelivery(delivery);
	if (*delivery) {
		this->deliveryChosen(deliveryTime);
	} else {
		this->setTable(tableNumber);
	}
  
	while (true) {
		this->categoryMenu(productList);
		cout << "\nq - Wyjdz\n";
		cout << "k - Koszyk\n\n";
		cout << "Wybor: ";
		cin >> this->chooseCategory;
		if (this->chooseCategory == 'q') {
			exit(0);
		}
		if (this->chooseCategory == 'k') {
			this->basketMenu(address, delivery);
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
	cout << "Witaj w restauracji JoJo's Bizarre Diner\n\n";
	cout << "Najlepszy hamon w calej galaktyce\n";
	cout << "Adres  ul.Ziemianska 182/4, 62-420 Kolebka Nowej Nadzieji - Mars\n\n";
	cout << "Aby zamowic nacisnij enter\n";
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
	while (true) {
		
		cout << "Jedzenie na miejscu (0) czy dostawa (1)? ";
		cin >> answer;
		if (answer == 0) {
			*delivery = false;
			system("cls");
			break;
		}
		if (answer == 1) {
			*delivery = true;
			system("cls");
			break;
		}
		system("cls");
		cout << "Podaj prawidlowa wartosc" << endl;
		system("pause");
		system("cls");

	}
}

void Menu::setAddress(string* address) {
	string tempAddress;
	regex address_regex("[A-Za-z]+\.[[:space:]][A-Za-z]+[[:space:]][0-9]+,[[:space:]][a-zA-Z]+,[[:space:]][0-9]{2}-[0-9]{3}");
	system("cls");

	getline(cin, tempAddress);

	while (true) {
		
		cout << "Format danych: Adres: al. Wojenna 1, Warszawa, 00-123" << endl;
		cout << "Podaj adres dostawy: ";

		cin.ignore();
		getline(cin, tempAddress);

		if (regex_match(tempAddress, address_regex)) {
			*address = tempAddress;
			break;
		}

		system("cls");
		cout << "Podano bledne dane" << endl;

	}
	
}

void Menu::deliveryChosen(string *deliveryTime) {
	time_t currentTime;
	time(&currentTime);
	struct tm timeInfo;
	localtime_s(&timeInfo, &currentTime);
	int year, month, day, hour, minutes;
	day = timeInfo.tm_mday;
	month = timeInfo.tm_mon + 1;
	year = timeInfo.tm_year + 1900;
	hour = timeInfo.tm_hour;
	minutes = timeInfo.tm_min;

	const int maxHour = 23, maxMinutes = 59;
	
	int deliveryHour, deliveryMinutes;
	char c;
	while (true) {
		cout << "Zamowienia przyjmujemy do godziny 22:59" << endl << endl;
		cout << "Podaj godzine dostawy (HH), wcisnij enter, a pozniej podaj minuty (MM): ";
		cout << endl;
		cin >> deliveryHour >> c >> deliveryMinutes;
		while (!cin.good()) {
			system("cls");
			cout << "Podano nieprawidlowa date" << endl;
			cout << "Podaj najpierw godzine dostawy (HH), wcisnij enter, a pozniej podaj minuty (MM): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> deliveryHour >> c >> deliveryMinutes;
		}
		if ((deliveryHour < maxHour && deliveryMinutes < maxMinutes) &&
			(hour <= deliveryHour)) {
			deliveryMinutes = (int)round(deliveryMinutes / 10) * 10;
			*deliveryTime = to_string(day) + "." + to_string(month) + "." + to_string(year) + ", " +
				to_string(deliveryHour) + c + to_string(deliveryMinutes);
			break;
		}
		else {
			system("cls");
			cout << "Podano nieprawidlowa date" << endl;
		}
	}
	
	system("cls");
}

// Render category menu
void Menu::categoryMenu(ProductsList productList)
{
	cout << "Wybierz kategorie dania" << endl;
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
		for (int i = 0; i < category.readDishList().size(); i++) {
			cout << (i + 1)
				<< ". "
				<< category.readDishList()[i].readDishName()
				<< "  Cena: "
				<< category.readDishList()[i].readDishPrice()
				<< endl;
		}
		cout << "\np - powrot";
		cout << "\nd - zobacz opisy dan\n\n";
		cout << "Wybierz numer produkt lub inne dzialanie: ";
		cin >> this->chooseDish;
		system("cls");
		
		if (this->chooseDish == 'p') break;
		
		if (this->chooseDish == 'd') this->dishesDescriptionMenu(category);
		
		//Checking if user choose is a number
		int tempChose = ((int)this->chooseDish - 49);
		if (tempChose >= 0 && ((int)this->chooseDish - 48) <= (int)category.readDishList().size()) {
			
			//make products in cart add their quantity

			if (this->cart.readCartList().size() > 0) {
				bool addNew = true;
				for (int i = 0; i < cart.readCartList().size(); i++) {
					if (this->cart.readCartList()[i].readProductName() == category.readDishList()[tempChose].readDishName()) {
						this->cart.incrementByProduct(i);
						addNew = false;
						break;
					}
				}

				if (addNew) {
					CartProduct tempCartProduct(category.readDishList()[tempChose], 1);
					this->cart.addProduct(tempCartProduct);
				}
			}
			
			else {
				CartProduct tempCartProduct(category.readDishList()[tempChose], 1);
				this->cart.addProduct(tempCartProduct);
				break;
			}

			break;
		}
		system("cls");
	}
}

void Menu::dishesDescriptionMenu(Category category)
{
	while (true) {
		cout << "Kategoria " << category.readCategoryName() << endl << endl << endl;
		//TODO Do it better
		for (int i = 0; i < category.readDishList().size(); i++) {
			cout << (i + 1)
				<< ". "
				<< category.readDishList()[i].readDishName()
				<< endl << endl
				<< "\t" << category.readDishList()[i].readDishDescription()
				<< endl << endl
				<< "\tAlergeny: "
				<< endl
				<< "\t" << category.readDishList()[i].readDishAlergens()
				<< endl << endl << endl;
		}
		cout << "\np - powrot\n\n";
		cin >> this->chooseDish;
		system("cls");
		
		if (this->chooseDish == 'p') break;
		
		system("cls");
	}
}

void Menu::basketShowProducts() {
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
}

void Menu::basketMenu(std::string* address,  bool* delivery) {
	system("cls");
	cout << "Koszyk" << endl;
	this->basketShowProducts();
	
	cout << "\nCzas przygotowania to: " << Utils::PrepTime(this->cart.readCartList(), delivery) << " minut" << endl;
	cout << "\nKoszt calkowity: " << this->cart.readCartPrice() << endl;
	cout << "\na - Przejdz do podsumowania\n";
	cout << "e - Edycja koszyka\n";
	cout << "p - powrot\n";
	cout << "\nWybor: ";
	cin >> this->chooseBasket;

	if (this->chooseBasket == 'a') {
		
		if (*delivery) {
			this->setAddress(address);
		}
		
		Bill bill;
		bill.createBill(this->cart);
		exit(0);
	}
	if (this->chooseBasket == 'e') {
		this->editBasketMenu();
	}

	system("cls");
}

void Menu::editBasketMenu() {

	while (true) {
		system("cls");
		cout << "Usuwanie" << endl;
		this->basketShowProducts();

		cout << "\np - powrot\n";
		cout << "\nWybor: ";
		cin >> this->chooseEditBasket;

		if(this->chooseEditBasket == 'p') break;

		//Checking if user choose is a number
		int tempChoose = ((int)this->chooseDish - 49);
		if (tempChoose >= 0 && ((int)this->chooseDish - 48) <= (int)cart.readCartList().size()) {
			if (cart.readCartList().size() > 1) {
				cart.removeByProduct(tempChoose);
			}
			else {
				cart.clearProducts();
			}
			
		}
	};
};
