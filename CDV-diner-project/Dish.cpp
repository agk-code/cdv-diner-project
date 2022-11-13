#include "Dish.h"

Dish::Dish(std::string _name, std::string _description, std::string _ingredients, std::string _alergens, double _price, int _time)
{
	this->name = _name;
	this->description = _description;
	this->ingredients = _ingredients;
	this->alergens = _alergens;
	this->price = _price;
	this->time = _time;
}

Dish::~Dish()
{
}

std::string Dish::readDishName() {
	return std::string(this->name);
}
