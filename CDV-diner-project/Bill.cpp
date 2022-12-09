#include "Bill.h"
#include "CartProduct.h"
#include <iostream>
#include <fstream>

using namespace std;

Bill::Bill() {}

Bill::~Bill() {}

void Bill::createBill(Cart cart)
{
	system("cls");

	fstream plik;
	plik.open("bill.txt", ios::out);
	
	
	for (int i = 0; i < cart.readCartList().size(); i++) {
		
		plik
			<< "Zamowienie w restauraji JoJo's Bizarre Diner" << endl
			<< cart.readCartList()[i].readProductName()
			<< "\t Cena:"
			<< cart.readCartList()[i].readProductPrice()
			<< "\t Ilosc:"
			<< cart.readCartList()[i].readProductQuantity()
			<< endl;
	}

	plik << "Suma: " << cart.readCartPrice() << endl;
	//TODO add time or delivery address
	plik.close();
	
	cout << "Zamowienie zostalo przyjete do realizacji" << endl;
	system("pause");
	system("cls");
	
	plik.good() ? cout << "Pomyslnie wydrukowano paragon do pliku bill.txt" << endl : cout << "Nie uda³o sie wydrukowac paragonu do pliku bill.txt" << endl;
	system("pause");
	
	exit(0);
}