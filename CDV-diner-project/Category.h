#pragma once
#include <string>
#include <vector>

#include "Dish.h"

class Category
{
private:
	std::string name;
	std::vector<Dish> dishList;

public:
	Category(std::string name, std::vector<Dish> dishList);
	~Category();
	std::string readCategoryName();
	std::vector<Dish> readDishList();
};

