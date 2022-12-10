#pragma once
#include <string>
class Dish
{
private:
	std::string description;
	std::string ingredients;
	std::string alergens;
protected:
	std::string name;
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
	std::string readDishDescription();
	std::string readDishAlergens();
	double readDishPrice();
	int readDishTime();
};
