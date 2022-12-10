
#include <fstream>
#include "json.hpp"

#include "Utils.h"
#include "Dish.h"
#include "Category.h"


using json = nlohmann::json;


using namespace Utils;

int Utils::PrepTime(std::vector<CartProduct> product_list, bool delivery)
{
    std::vector<int> prep_time;
    for (int i = 0; i < product_list.size(); i++)
    {
        prep_time.push_back(product_list[i].readProductTime());
    }
    int waiting_time = 0, max = 0, stand[3] = { 0,0,0 };
    int min = stand[0];
    for (int j = 0; j < prep_time.size(); j++)
    {
        min = 999;
        for (int i = 0; i < 3; i++)
        {
            if (min > stand[i])
            {
                min = stand[i];
            }
        }
        if (min == stand[0])
        {
            stand[0] += prep_time[j];
        }
        else if (min == stand[1])
        {
            stand[1] += prep_time[j];
        }
        else
        {
            stand[2] += prep_time[j];
        }

    }
    for (int n = 0; n < 3; n++)
    {
        if (max < stand[n])
        {
            max = stand[n];
        }
    }

    if (delivery) {
        max += 15;
    }
    
    return max;
    
}

void Utils::createCategoryAndDishesVectors(ProductsList* productsList){
	
    
    //Create a json object from json file
    const std::string dishesJsonFile = "Dishes.json";
    std::ifstream dishesMenu(dishesJsonFile);
    json dishesJson;
    dishesMenu >> dishesJson;
    dishesMenu.close();
	
	
    //Categories
    for (int i = 0; i < dishesJson.size(); i++) {

        std::vector<Dish> currentDishesVector;
        json currentCategoryValuesJson = dishesJson[i]["categoryValues"];
        
        
        //Dishes
        for (int j = 0; j < currentCategoryValuesJson.size(); j++) {

          
            currentDishesVector.push_back(
                Dish(
                    currentCategoryValuesJson[j]["name"],
                    currentCategoryValuesJson[j]["description"],
                    currentCategoryValuesJson[j]["ingredients"],
                    currentCategoryValuesJson[j]["alergens"],
                    currentCategoryValuesJson[j]["price"],
                    currentCategoryValuesJson[j]["time"]
				)
			);
		}
		
		productsList->addCategory(Category(dishesJson[i]["categoryName"], currentDishesVector));
    }
}