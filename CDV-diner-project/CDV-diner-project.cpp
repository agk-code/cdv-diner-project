#include <iostream>
#include <vector>

#include "ProductsList.h"
#include "Category.h"
#include "Dish.h"
#include "Utils.h"

// TODO rename Cart class to Basket
#include "Cart.h"
#include "CartProduct.h"
#include "Menu.h"

using namespace std;

// Global variables
string name = "";
bool delivery = false;
int tableNumber = 1;
string deliveryTime = "";


int main()
{
	// Create basic objects
	ProductsList productsList;
	Cart cart;
	Menu menu(&cart);

	// Initializing basic objects
  Utils::createCategoryAndDishesVectors(&productsList);
	menu.initMenu(&name, productsList, &tableNumber, &delivery, &deliveryTime);
}
