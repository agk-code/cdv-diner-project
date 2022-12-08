#include <iostream>
#include <vector>

#include "ProductsList.h"
#include "Category.h"
#include "Dish.h"
// TODO rename Cart class to Basket
#include "Cart.h"
#include "CartProduct.h"
#include "Menu.h"

using namespace std;

// Global varibles
string name = "";
bool delivery = false;
string deliveryTime = "";

// Test function for create products list
void createProductsList(ProductsList *productsList) {
	Dish dish1("Zupa", "Opis", "1.Woda\n 2.Makaron\n", "1.Makraon\n", 13.37, 100000);
	Dish dish2;
	vector<Dish> list { dish1, dish2 };
	Category zupy("Zupy", list);
	productsList->addCategory(zupy);
}

int main()
{
	// Create basic objects
	ProductsList productsList;
	Cart cart;
	Menu menu(&cart);

	// Initializing basic objects
	createProductsList(&productsList);
	menu.initMenu(&name, productsList, &delivery, &deliveryTime);

}
