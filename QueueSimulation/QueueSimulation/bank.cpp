//
//  bank.cpp
//  Simulator
//
//  Created by Adam Quintana on 4/8/19.
//  Copyright © 2019 Adam Quintana. All rights reserved.
//

#include "bank.hpp"

// add a bank queue customer (not really an event)
void Bank::addBankQueueCustomer(Event& event) {
    bankQueue.push(event);
}

//Bank simulator driver function
void Bank::runSim() {
    while (!eventQueue.empty()) {
        Event customer = eventQueue.top(); // get next event (customer) in priority queue
        currentTime = customer.eventTime;
        eventQueue.pop();
        
        //switch comparing types of events {arrival, departure}
        switch (customer.event) {
            case arrival:
                if (tellersAvailable) {
                    //if there are tellers availble, customer service time should be now (current time)
                    customer.totalServiceTime = customer.serviceDuration;
                    serviceTimes.push_back(customer.totalServiceTime);
                    customer.eventTime += customer.serviceDuration;// ??
                    customer.event = departure;
                    addEvent(customer);
                    tellersAvailable--;
                } else {
                    // no tellers available, put customer in bank queue
                    addBankQueueCustomer(customer);
                }
                break;
            case departure:
                if(!bankQueue.empty()) {
                    Event nextCustomer = bankQueue.front();
                    bankQueue.pop();
                    nextCustomer.totalServiceTime = currentTime - customer.eventTime + customer.serviceDuration;
                    serviceTimes.push_back(nextCustomer.totalServiceTime);
                    nextCustomer.eventTime = currentTime + customer.serviceDuration;
                    nextCustomer.event = departure;
                    addEvent(nextCustomer);
                } else {
                    tellersAvailable++;
                    //printTellerNumberChange();
                }
                break;
            default:
                std::cout << "ERROR: Should never get here! " << std::endl;
        }
    }
}
