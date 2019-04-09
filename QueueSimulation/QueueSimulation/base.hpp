//
//  base.hpp
//  Simulator
//
//  Created by Adam Quintana on 4/8/19.
//  Copyright © 2019 Adam Quintana. All rights reserved.
//

#ifndef base_hpp
#define base_hpp

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <array>
#include "event.hpp"

class Base {
protected:
    //member variables
    std::priority_queue<Event, std::vector<Event>, compareEventTime> eventQueue;
    //std::array<int, 6> checkers;
    int currentTime = 0;
public:
    //methods
    void addEvent(Event& event);
    //int chooseShortestLine(std::array<int, 6>& checkers);
    virtual void runSim() {};
    
    //public member variable
    std::vector<int> serviceTimes;
};

#endif /* Business_hpp */
