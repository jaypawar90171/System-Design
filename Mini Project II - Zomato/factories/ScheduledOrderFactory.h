#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std;

class ScheduledOrderFactory  : public OrderFactory
{
    private:
        string sheduleTime;

    public:
        ScheduledOrderFactory(string scheduleTime) {
            this->scheduleTime = scheduleTime;
        }

        Order* createOrder(
            User* user, 
            Cart* cart, 
            Restaurant* restaurant, 
            const vector<MenuItem> &MenuItem, 
            PaymentStrategy* paymentStrategy, 
            double totalCost, 
            const string &orderType
        ) override {
            Order* order = nullptr;

            if(orderType == "Delivery")
            {
                auto deliveryOrder = new DeliveryOrder();
                deliveryOrder->setRestaurantAddress(user->getAddress());
                order = deliveryOrder;
            }
            else
            {
                auto pickupOrder = new PickupOrder();
                pickupOrder->setRestaurantAddress(user->getAddress());
                order = pickupOrder;
            }

            order->setUser(user);
            order->setRestaurant(restaurant);
            order->setItems(menuItems);
            order->setPaymentStrategy(paymentStrategy);
            order->setScheduled(TimeUtils::getCurrentTime());
            order->setTotal(totalCost);

            return order;
        }
}