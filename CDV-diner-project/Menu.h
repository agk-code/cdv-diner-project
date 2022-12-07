#pragma once
#include "ProductsList.h"
#include "Category.h"
#include "Cart.h"

#include <string>

class Menu
{
private:
	char chooseCategory;
	char chooseDish;
	char chooseBasket;
	Cart cart;
	void setName(std::string* name);
	void setDelivery(bool* delivery);
	void categoryMenu(ProductsList productList);
	void dishesMenu(Category category);
	void basketMenu();
public:
	Menu(Cart *_cart);
	~Menu();
	void initMenu(std::string* name, ProductsList productList, bool* delivery);
};

