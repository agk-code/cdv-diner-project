#include <iostream>

#include "ProductsList.h"
#include "Category.h"

using namespace std;

// Constructor
ProductsList::ProductsList() {
	this->choose = 0;
}

// Destructor
ProductsList::~ProductsList() {}

// Changing methods
void ProductsList::changeChoose(int _choose)
{
	this->choose = _choose;
}

void ProductsList::addCategory(Category cat)
{
	this->list.push_back(cat);
}

// Reading methods
std::vector<Category> ProductsList::readProductList()
{
	return std::vector<Category>(this->list);
}
