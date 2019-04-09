//
//  bank.hpp
//  Simulator
//
//  Created by Adam Quintana on 4/8/19.
//  Copyright © 2019 Adam Quintana. All rights reserved.
//

#ifndef bank_hpp
#define bank_hpp

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <array>
#include <unordered_map>
#include "base.hpp"
#include "event.hpp"

#define NUM_TELLERS 6

class Bank : public Base {

private:
    //member variables
    std::queue<Event> bankQueue;
    int tellersAvailable = NUM_TELLERS;

public:
    //methods
    void addBankQueueCustomer(Event& event);
    void runSim() override;

    //public member variable
    std::vector<int> serviceTimes;
};

#endif /* bank_hpp */
