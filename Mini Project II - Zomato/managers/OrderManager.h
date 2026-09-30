#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <bits/stdc++.h>
#include "../models/order.h"
using namespace std;

class OrderManager
{
    private:
        Vector<Order*> order;
        static OrderManager* instance;

        OrderManager() {}

    public:
        static OrderManager* getInstance() 
        {
            if (!instance) 
            {
                instance = new OrderManager();
            }
            return instance;
        }

        void addOrder(Order* order) 
        {
            orders.push_back(order);
        }

        void listOrder()
        {
            cout << "\n--- All Orders ---" << endl;
            for(auto order: orders)
            {
                cout << order->getType() << " order for " << order->getUser()->getName()
                    << " | Total: ₹" << order->getTotal()
                    << " | At: " << order->getScheduled() << endl;
            }
        }
}

OrderManager* OrderManager::instance = nullptr

#endif