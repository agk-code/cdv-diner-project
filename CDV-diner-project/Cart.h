#pragma once
#include <vector>
#include "CartProduct.h"
class Cart
{
private:
	std::vector<CartProduct> list;
public:
	Cart();
	~Cart();
	void addProduct(CartProduct _product);
	std::vector<CartProduct> readCartList();
	void incrementByProduct(int i);
	void removeByProduct(int i);
	void clearProducts();
	double readCartPrice();
};

