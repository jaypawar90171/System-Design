#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <bits/stdc++.h>
#include "../models/Restaurant.h"
using namespace std;

class RestaurantManager
{
    private:
        vector<Restaurant*> restaurants;
        static RestaurantManager* instance;

        RestaurantManager() {
            // Private Constrcutor
        }

    public:
        static RestaurantManager* getInstance()
        {
            if(!instance)
            {
                instance = new RestaurantManager()
            }
            return instance;
        }

        void addRestaurant(Restaurant* r) 
        {
            restaurants.push_back(r);
        }
        
        // return lit of restaurants matches the location
        vector<Restaurant*> searchByLocation(string loc)
        {
            vector<Restaurant*> res;
            transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
            for(auto res: restaurants)
            {
                string r1 = res->getLocation();
                transform(rl.begin(), rl.end(), rl.begin(), ::tolower);

                if(r1 == loc) res.push_back(r1);
            }
            return res;
        }

}
RestaurantManager* RestaurantManager::instance = nullptr;

#endif