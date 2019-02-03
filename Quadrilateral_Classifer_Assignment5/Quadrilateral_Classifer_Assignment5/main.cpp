//
//  main.cpp
//  assignment3
//
//  Created by Quincy Copeland on 1/15/19.
//  Copyright © 2019 Quincy Copeland. All rights reserved.
//
#define pdd pair<double, double>
#include <iostream>
#include <string>
#include "functions.hpp"

using namespace std;


int main(int argc, const char * argv[])
{
    
    //5 0 9 3 4 3
    //6 1 9 5 2 2
    //6 1 9 7 2 4
    //4 0 8 2 4 2
    //7 0 7 3 0 7
    //70 0 70 30 0 30
    //5 1 5 5 1 5
    //4 0 4 4 0 4
    //5 0 3 3 0 5
    //1 4 4 4 0 8
    //rhombus
    //quad
    //trap
    //parallel
    //trap
    //rectangle
    //kite
    //square
    //kite
    //quad
    
    
    string line;
    vector<double> points;
    while (getline(cin, line)) {
        points = ParseString(line);
        Quadrilateral quad;
        SortCordinants(points, quad);
        CalculateLength(quad);
        CalculateSlope(quad);
        printCorrectShape(quad);
    }

    
    return 0;
}
