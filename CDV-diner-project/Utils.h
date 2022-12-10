#pragma once
#include "CartProduct.h"
#include "ProductsList.h"
#include <vector>

namespace Utils {
	int PrepTime(std::vector<CartProduct>, bool delivery);
	void createCategoryAndDishesVectors(ProductsList* productsList);
}