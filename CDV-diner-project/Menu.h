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
	void showRestaurantData();
	void setName(std::string* name);
	void setTable(int* tableNumber);
	void setDelivery(bool* delivery);
	void setAddress(std::string* address);
	void deliveryChosen(std::string* deliveryTime);
	void categoryMenu(ProductsList productList);
	void dishesMenu(Category category);
	void dishesDescriptionMenu(Category category);
	void basketMenu(std::string* address, bool* delivery);
public:
	Menu(Cart *_cart);
	~Menu();
	void initMenu(
		std::string* name,
		ProductsList productList,
		int *tableNumber,
		bool* delivery,
		std::string *deliveryTime,
		std::string *address
	);
};

