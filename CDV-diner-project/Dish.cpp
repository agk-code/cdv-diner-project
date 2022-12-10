#include "Dish.h"

// Constructor
Dish::Dish(std::string _name, std::string _description, std::string _ingredients, std::string _alergens, double _price, int _time)
{
	this->name = _name;
	this->description = _description;
	this->ingredients = _ingredients;
	this->alergens = _alergens;
	this->price = _price;
	this->time = _time;
}

// Destructor
Dish::~Dish() {}

// Reading methods
std::string Dish::readDishName() {
	return std::string(this->name);
}

std::string Dish::readDishAlergens() {
	return std::string(this->alergens);
}

std::string Dish::readDishDescription() {
	return std::string(this->description);
}

double Dish::readDishPrice()
{
	return this->price;
}

int Dish::readDishTime()
{
	return this->time;
}


