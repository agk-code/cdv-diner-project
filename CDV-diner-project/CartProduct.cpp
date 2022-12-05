#include "CartProduct.h"
#include "Dish.h"

// Constructor
CartProduct::CartProduct(Dish _dish, int _quantity)
{
	this->dish = _dish;
	this->quantity = _quantity;
}

// Destructor
CartProduct::~CartProduct() {}

// Reading methods
std::string CartProduct::readProductName()
{
	return std::string(this->dish.readDishName());
}

double CartProduct::readProductPrice()
{
	return this->dish.readDishPrice();
}

int CartProduct::readProductTime()
{
	return this->dish.readDishTime();
}

int CartProduct::readProductQuantity()
{
	return this->quantity;
}

void CartProduct::incrementProductQuantity()
{
	this->quantity += 1;
}
