#include "Category.h"

Category::Category(std::string _name, std::vector<Dish> _dishList)
{
	this->name = _name;
	this->dishList = _dishList;
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

