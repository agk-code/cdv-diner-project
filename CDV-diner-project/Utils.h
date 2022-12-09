#pragma once
#include "CartProduct.h"
#include "ProductsList.h"
#include <vector>

namespace Utils {
	int PrepTime(std::vector<CartProduct>);
	void createCategoryAndDishesVectors(ProductsList* productsList);
}