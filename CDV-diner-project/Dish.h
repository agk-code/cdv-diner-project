#pragma once
#include <string>
class Dish
{
private:
	std::string name;
	std::string description;
	std::string ingredients;
	std::string alergens;
	double price;
	int time;

public:
	Dish(
		std::string _name = "Testowy produkt",
		std::string _description = "Test",
		std::string _ingredients = "1.Sos\n 2.Makaron\n",
		std::string _alergens = "1.Sos\n",
		double _price = 420.69,
		int _time = 1668352918
	);
	~Dish();
	std::string readDishName();
};

