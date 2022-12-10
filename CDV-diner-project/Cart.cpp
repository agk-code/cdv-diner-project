#include "Cart.h"

#include <iostream>

// Constructor
Cart::Cart() {}

// Destructor
Cart::~Cart() {}

// Changing methods
void Cart::addProduct(CartProduct _product)
{
	this->list.push_back(_product);
}


// Reading methods
std::vector<CartProduct> Cart::readCartList()
{
	return this->list;
}

void Cart::incrementByProduct(int i)
{
	this->list[i].incrementProductQuantity();
}

void Cart::removeByProduct(int i)
{
	std::cout << "Remove By Product: " << i << std::endl;
	this->list.erase(this->list.begin() + i);
}

void Cart::clearProducts() {
	this->list.clear();
}

double Cart::readCartPrice()
{
	double price = 0;
	for (int i = 0; i < this->list.size(); i++) {
		price += (this->list.at(i).readProductPrice()) * this->list.at(i).readProductQuantity();
	}
	return price;
}