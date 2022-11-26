#pragma once
#include "Dish.h"
class CartProduct : Dish
{
private:
	int quantity;
public:
	CartProduct(Dish _dish, int _quantity);
	~CartProduct();
	std::string readProductName();
	double readProductPrice();
	int readProductTime();
	int readProductQuantity();
};

