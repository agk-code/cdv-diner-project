#pragma once
#include <string>
class Dish
{
protected:
	std::string name;
	std::string description;
	std::string ingredients;
	std::string alergens;
	double price;
	int time;

public:
	Dish(
		std::string _name = "Testowy produkt",
		std::string _description = "",
		std::string _ingredients = "",
		std::string _alergens = "",
		double _price = 420.69,
		int _time = 1668352918
	);
	~Dish();
	std::string readDishName();
	double readDishPrice();
	int readDishTime();
};

