//
//  base.cpp
//  Simulator
//
//  Created by Adam Quintana on 4/8/19.
//  Copyright © 2019 Adam Quintana. All rights reserved.
//

#include "event.hpp"
#include "base.hpp"

//Params: Event structs object
//Void: pushes an even into priority queue
void Base::addEvent(Event& event) {
    eventQueue.push(event);
}


