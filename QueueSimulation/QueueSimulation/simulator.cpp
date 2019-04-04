//
//  simulator.cpp
//  QueueSimulation
//
//  Created by Quincy Copeland on 3/29/19.
//  Copyright © 2019 Quincy Copeland. All rights reserved.
//

#include "simulator.hpp"
#include <iostream>


//void printEvent(const Event& event) {
//    //std::cout << event.customerName;
//    std::cout << ", Time: " << event.eventTime;
//    std::cout << ", Duration: " << event.duration;
//    std::cout << ", Event type: ";
//    if (event.event == arrival){
//         std::cout << "ARRIVAL";
//    }
//    else {
//        std::cout << "DEPARTURE";
//    }
//}


//Params: Event structs object
//Void: pushes an even into bank priority queue
void Bank::addEvent(Event& event) {
    eventQueue.push(event);
}

//Params: Event structs object
//Void: pushes an even into grocery priority queue
void Grocery::addEvent(Event& event) {
    eventQueue.push(event);
}


// add a bank queue customer (not really an event)
void Bank::addBankQueueCustomer(Event& event) {
    bankQueue.push(event);
}

//Params: array of checkers
//Returns: index of checker with the shortest line
int Grocery::chooseShortestLine(std::array<int, 6>& checkers){
    
    int indexOfShortest = 0;
    for (int i = 1; i < checkers.size(); i++) {
        if (checkers[i] < checkers[indexOfShortest]) {
            indexOfShortest = i;
        }
    }
    return indexOfShortest;
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


//Grocery Store simulator driver function
void Grocery::runSim() {
    while (!eventQueue.empty()) {
        Event customer = eventQueue.top(); // get next event in priority queue
        currentTime = customer.eventTime;
        eventQueue.pop();
        int shortestLine;
        
        //switch comparing types of events {arrival, departure}
        switch (customer.event) {
            case arrival:
                shortestLine = chooseShortestLine(checkers); //finds the line with shoretest service time
                customer.cashier = shortestLine; //cashier refers to an int
                customer.totalServiceTime = checkers.at(shortestLine) + customer.serviceDuration;
                serviceTimes.push_back(customer.totalServiceTime); //storing all service times
                checkers.at(shortestLine)+= customer.serviceDuration;
                customer.eventTime = currentTime + checkers.at(shortestLine);
                customer.event = departure;
                addEvent(customer);
                break;
            case departure:
                //customer leaves you need to take away there service time from
                //the total remaining time of the line they are in
                checkers.at(customer.cashier)-= customer.serviceDuration;
                break;
            default:
                std::cout << "ERROR: Should never get here! " << std::endl;
        }
    }
}


