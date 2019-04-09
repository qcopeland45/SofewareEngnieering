//
//  event.hpp
//  Simulator
//
//  Created by Adam Quintana on 4/8/19.
//  Copyright © 2019 Adam Quintana. All rights reserved.
//

#ifndef event_hpp
#define event_hpp

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

#endif /* event_hpp */
