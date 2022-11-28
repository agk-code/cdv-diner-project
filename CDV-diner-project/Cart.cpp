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
	return std::vector<CartProduct>(this->list);
}
