//
//  simulator.hpp
//  QueueSimulation
//
//  Created by Quincy Copeland on 3/29/19.
//  Copyright © 2019 Quincy Copeland. All rights reserved.
//

#ifndef simulator_hpp
#define simulator_hpp

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <array>
#include <unordered_map>

#define NUM_TELLERS 6

enum EventType {arrival, departure};

//Event Struct
struct Event {
    
    //member variables
    double eventTime;
    double serviceDuration;
    double waitTime;
    double totalServiceTime;
    int customerID;
    int cashier;
    EventType event;
};


struct compareEventTime{
    bool operator()(const Event& lhs, const Event& rhs) const {
        return lhs.eventTime > rhs.eventTime;
    }
};


//************Bank Class*****************//
class Bank {
    
private:
    //member variables
    std::priority_queue<Event, std::vector<Event>, compareEventTime> eventQueue;
    std::queue<Event> bankQueue;
    int currentTime = 0;
    int tellersAvailable = NUM_TELLERS;
    
public:
    //methods
    void addEvent(Event& event);
    void addBankQueueCustomer(Event& event);
    void runSim();
    
    //public member variable
    std::vector<int> serviceTimes;
};


//************Grocery Class*****************//
class Grocery {
private:
    //member variables
    std::priority_queue<Event, std::vector<Event>, compareEventTime> eventQueue;
    std::array<int, 6> checkers;
    int currentTime = 0;
public:
    //methods
    void addEvent(Event& event);
    int chooseShortestLine(std::array<int, 6>& checkers);
    void runSim();
    
    //public member variable
    std::vector<int> serviceTimes;
};










#endif /* simulator_hpp */
