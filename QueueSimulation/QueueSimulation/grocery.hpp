//
//  grocery.hpp
//  Simulator
//
//  Created by Adam Quintana on 4/8/19.
//  Copyright © 2019 Adam Quintana. All rights reserved.
//

#ifndef grocery_hpp
#define grocery_hpp

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <array>
#include <unordered_map>
#include "base.hpp"
#include "event.hpp"

class Grocery : public Base {
private:
    //member variables
    std::array<int, 6> checkers;
public:
    //methods
    int chooseShortestLine(std::array<int, 6>& checkers);
    void runSim() override;

    //public member variable
    std::vector<int> serviceTimes;
};

#endif /* grocery_hpp */
