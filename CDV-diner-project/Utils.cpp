
#include "Utils.h"




using namespace Utils;

int Utils::PrepTime(std::vector<CartProduct> product_list)
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

    return max;
    
}