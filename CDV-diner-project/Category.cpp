#include "Category.h"

Category::Category(std::string name, std::vector<Dish> dishList)
{
}

Category::~Category()
{
}

std::string Category::readCategoryName()
{
	return std::string(this->name);
}

std::vector<Dish> Category::readDishList()
{
	return std::vector<Dish>(this->dishList);
}

