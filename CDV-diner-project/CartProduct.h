#pragma once
#include "Dish.h"
class CartProduct
{
private:
	int quantity;
	Dish dish;
public:
	CartProduct(Dish _dish, int _quantity);
	~CartProduct();
	std::string readProductName();
	double readProductPrice();
	int readProductTime();
	int readProductQuantity();
};
