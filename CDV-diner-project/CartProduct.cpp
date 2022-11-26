#include "CartProduct.h"
#include "Dish.h"

CartProduct::CartProduct(Dish _dish, int _quantity)
{
	this->quantity = _quantity;
	this->name = _dish.readDishName();
	this->price = _dish.readDishPrice();
	this->time = _dish.readDishTime();
}

CartProduct::~CartProduct()
{
}

std::string CartProduct::readProductName()
{
	return std::string(this->name);
}

double CartProduct::readProductPrice()
{
	return this->price;
}

int CartProduct::readProductTime()
{
	return this->time;
}

int CartProduct::readProductQuantity()
{
	return this->quantity;
}
