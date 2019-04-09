//
//  grocery.cpp
//  Simulator
//
//  Created by Adam Quintana on 4/8/19.
//  Copyright © 2019 Adam Quintana. All rights reserved.
//

#include "grocery.hpp"

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
