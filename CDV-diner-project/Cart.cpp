#include "Cart.h"

Cart::Cart()
{

}

Cart::~Cart()
{
}

void Cart::addProduct(CartProduct _product)
{
	this->list.push_back(_product);
}

std::vector<CartProduct> Cart::readCartList()
{
	return std::vector<CartProduct>(this->list);
}
