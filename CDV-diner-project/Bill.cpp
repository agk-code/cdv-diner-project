#include "Bill.h"
#include "CartProduct.h"
#include <iostream>
#include <fstream>

using namespace std;

Bill::Bill() {}

Bill::~Bill() {}

void Bill::createBill(Cart cart)
{

	cout << "Tworzenie rachunku" << endl;
	cout << cart.readCartList().size() << endl;
	system("pause");

	fstream plik;
	plik.open("bill.txt", ios::out | ios::app);
	
	for (int i = 0; i < cart.readCartList().size(); i++) {
		plik << (i + 1) << ". "
			<< cart.readCartList()[i].readProductName()
			<< "   "
			<< cart.readCartList()[i].readProductPrice()
			<< "   "
			<< cart.readCartList()[i].readProductTime()
			<< "   "
			<< cart.readCartList()[i].readProductQuantity()
			<< endl;
	}

	plik.close();
}