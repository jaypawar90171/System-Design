#ifndef CART_H
#define CART_H

#include <bits/stdc++.h>
#include "Restaurant.h"
#include "MenuItem.h"
using namespace std;

class Cart
{
    private:
        Restaurant* restaurant;
        vector<MenuItem> items;

    public:
        cart()
        {
            restaurant = nullptr;
        }

        // add items to cart
        void addItem(const MenuItem &item)
        {
            if (!restaurant) {
                cerr << "Cart: Set a restaurant before adding items." << endl;
                return;
            }
            items.push_back(item);
        }

        //remove particular item from cart by name
        void removeItem(string itemName)
        {
            for(const auto &it: items)
            {
                if(it.getName() == itemName)
                {
                    items.erase(items.begin() + it);
                }
            }
        }

        // returns the total price of the cart
        double getTotalCost() const 
        {
            double sum = 0;
            for (const auto& it : items) 
            {
                sum += it.getPrice();
            }
            return sum;
        }

        bool isEmpty() 
        {
            return (!restaurant || items.empty());
        }

        void clear() 
        {
            items.clear();
            restaurant = nullptr;
        }

        // Getters and Setters
        void setRestaurant(Restaurant* r) {
            restaurant = r;
        }

        Restaurant* getRestaurant() const {
            return restaurant;
        }

        const vector<MenuItem>& getItems() const {
            return items;
        }
};

#endif