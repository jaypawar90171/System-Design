#ifndef RESTURANT_H
#define RESTURANT_H

#include <bits/stdc++.h>
#include "MenuItem.h"
using namespace std;

class Resturant
{
    private:
        static int nextResturantId;
        int restaurantId;
        string name;
        string location;
        vector<MenuItem> menu;

    public:
        Resturant(const string& name, const string& location)
        {
            this->name = name;
            this->location = location;
            this->restaurantId = ++nextResturantId;
        }

        ~Resturant()
        {
            // Optional: just for clarity or debug
            cout << "Destroying Restaurant: " << name << ", and clearing its menu." << endl;
            menu.clear();
        }

        //Getters and setters
        string getName() const {
            return name;
        }

        void setName(const string &n) {
            name = n;
        }

        string getLocation() const {
            return location;
        }

        void setLocation(const string &loc) {
            location = loc;
        }

        void addMenuItem(const MenuItem &item) {
            menu.push_back(item);
        }

        const vector<MenuItem>& getMenu() const {
            return menu;
        }
}

int Resturant::nextResturantId = 0;

#endif