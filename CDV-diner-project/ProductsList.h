#pragma once
#include <vector>
#include "Category.h"
class ProductsList
{
private:
	int choose;
	std::vector<Category> list;
	void changeChoose(int choose);
public:
	ProductsList();
	~ProductsList();
	void addCategory(Category cat);
	std::vector<Category> readProductList();
};
