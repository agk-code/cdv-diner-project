#pragma once
#include "ProductsList.h"
#include "Category.h"

#include <string>

class Menu
{
private:
	char choose;
	void setName(std::string* name);
	void categoryMenu(ProductsList productList);
	void dishesMenu(Category category);
public:
	Menu();
	~Menu();
	void initMenu(std::string *name, ProductsList productList);
};

