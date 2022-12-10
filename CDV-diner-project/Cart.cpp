#include "Cart.h"

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

double Cart::readCartPrice()
{
	double price = 0;
	for (int i = 0; i < this->list.size(); i++) {
		price += (this->list.at(i).readProductPrice()) * this->list.at(i).readProductQuantity();
	}
	return price;
}