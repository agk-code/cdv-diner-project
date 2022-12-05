#include "Bill.h"

#include <iostream>
#include <fstream>

using namespace std;

Bill::Bill(){}

Bill::~Bill(){}

void Bill::createBill(Cart cart)
{

	cout << "Tworzenie rachunku" << endl;
	cout << cart.readCartList().size() << endl;
	system("pause");

}
