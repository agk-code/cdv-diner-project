#include <iostream>
#include <vector>

#include "ProductsList.h"
#include "Category.h"
#include "Dish.h"
#include "Cart.h"
#include "CartProduct.h"
#include "Menu.h"

using namespace std;

// Global varibles
string name = "";
bool delivery = false;

// Test function for create products list
void createProductsList(ProductsList *productsList) {
	Dish dish1("Zupa", "Opis", "1.Woda\n 2.Makaron\n", "1.Makraon\n", 13.37, 100000);
	Dish dish2;
	vector<Dish> list { dish1, dish2 };
	Category zupy("Zupy", list);
	productsList->addCategory(zupy);
}

// Test function for create cart
void createCart(Cart *cart) {}

int main()
{
	// Create basic objects
	ProductsList productsList;
	Cart cart;
	Menu menu;

	// Initializing basic objects
	createProductsList(&productsList);
	createCart(&cart);
	menu.initMenu(&name, productsList);

}
