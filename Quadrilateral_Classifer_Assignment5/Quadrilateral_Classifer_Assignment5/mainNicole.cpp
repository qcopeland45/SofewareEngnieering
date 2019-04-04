//
//  main.cpp
//  Classifying Quadrilaterals Program
//
//  Created by Nicole Morris on 1/16/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <sstream>

struct Point {double x; double y;};
struct Angle {Point a; Point b; Point c; float degrees;};
struct Quad {float ab; float bc; float cd; float da; Angle a; Angle b; Angle c; Angle d;};

/*
 * MATH FXNS
 * Used to find components quadrilateral features (side length, angle degrees, side slope)
 */

//Calculates the length of a line between 2 xy coordinates
//Modified from www.geeksforgeeks.org/program-calculate-distance-two-points/
float calcLength(Point a, Point b){
    
    return sqrt(pow(b.x - a.x,2) + pow(b.y-a.y,2));
}

//Calculates the value of degress based on 3 xy coordinates
//Modified from www.geeksforgeeks.org/find-angles-given-triangle/
float calcDeg(Point a, Point b, Point c){
    
    double pi = 3.1415926535;
    float sideAB = calcLength(a,b);
    float sideBC = calcLength(b,c);
    float sideCA = calcLength(c,a);
    
    return (180 / pi * (acos((pow(sideAB,2) + pow(sideBC,2) - pow(sideCA,2)) / (2 * sideAB * sideBC))));
    
}

//Calculates the slope of a line
//Modified from www.geeksforgeeks.org/program-find-slope-line/
float slope(float ax, float ay, float bx, float by){
    
    return (by - ay) / (bx - ax);
    
}

/*
 * CLASSIFICATION FXNS
 * Determines the type of quadrilateral (square, rhombus, rectangle, parallelogram, kite, trapezoid, quadrilateral)
 */

//Determines if a quadrilateral is a parallelogram
bool isParallelogram(Quad quad){
    
    //Opposite sides are congruent
    if(quad.ab == quad.cd && quad.bc == quad.da){
        return true;
    }
    
    return false;
}

//Determines if a parallelogram is a rhombus
bool isRhombus(Quad quad){
    
    if(quad.ab == quad.bc){
        if(quad.bc == quad.cd){
            if(quad.cd == quad.da){
                if(quad.da == quad.ab){
                    return true;
                }
            }
            
        }
    }
    return false;
}

//Determines if a parallelogram is a rectangle
bool isRectangle(Quad quad){
    
    if(quad.a.degrees == quad.b.degrees){
        if(quad.b.degrees == quad.c.degrees){
            if(quad.c.degrees == quad.d.degrees){
                if(quad.d.degrees == quad.a.degrees){
                    return true;
                }
            }
        }
    }
    
    return false;
}

//Determines if a rhombus or rectangle is a square
bool isSquare(Quad quad){
    
    //Already classified as a rhombus so...
    return isRectangle(quad);
    
}

//Determines if a quadrilateral is a kite
bool isKite(Quad quad){
    
    if((quad.ab == quad.bc && quad.cd == quad.da) || (quad.ab == quad.da && quad.bc == quad.cd)){
        return true;
    }
    return false;
}

//Determines if a quadrilateral is a trapezoid
bool isTrapezoid(Quad quad){
    
    if(slope(quad.a.b.x,quad.a.b.y,quad.b.b.x,quad.b.b.y) == slope(quad.d.b.x,quad.d.b.y,quad.c.b.x,quad.c.b.y)){
        if(!(slope(quad.b.b.x,quad.b.b.y,quad.c.b.x,quad.c.b.y) == slope(quad.a.b.x,quad.a.b.y,quad.d.b.x,quad.d.b.y))){
            return true;
        }
    } else if (slope(quad.b.b.x,quad.b.b.y,quad.c.b.x,quad.c.b.y) == slope(quad.a.b.x,quad.a.b.y,quad.d.b.x,quad.d.b.y)){
        if(!(slope(quad.a.b.x,quad.a.b.y,quad.b.b.x,quad.b.b.y) == slope(quad.d.b.x,quad.d.b.y,quad.c.b.x,quad.c.b.y))){
            return true;
        }
    }
    
    return false;
    
}

//Prints the classification of a parallelogram
void classifyParallel(Quad quad){
    //If parallelogram, determine if rhombus
    if(isRhombus(quad)){
        
        //If rhombus, determine if square
        if(isSquare(quad)){
            std:: cout << "square" << std::endl;
        } else {
            std:: cout << "rhombus" << std::endl;
        }
        
    } else {
        //Confirm is a rectangle
        
        if(isRectangle(quad)){
            std:: cout << "rectangle" << std::endl;
            
        } else {
            
            //If not rhombus or rectangle...
            std:: cout << "parallelogram" << std::endl;
            
        }
    }
}

//Prints the classification of a quadrilateral that is not a parallelogram
void classifyNotParallel(Quad quad){
    if(isKite(quad)){
        std::cout << "kite" << std::endl;
    } else if(isTrapezoid(quad)){
        std::cout << "trapezoid" << std::endl;
    } else {
        std::cout << "quadrilateral" << std::endl;
    }
}

//Prints the classification of a quadrilateral
void classifyQuad(Quad quad){
    
    //Determine if parallelogram
    if(isParallelogram(quad)){
        classifyParallel(quad);
    } else {
        
        classifyNotParallel(quad);
    }
}

/*
 * ERROR CHECKING FUNCTIONS
 */

void error(std::string message){
    std::cout << message << std::endl;
    exit(1);
}

void checkLength(std::vector<std::string> lines){
    
    static int length = lines.size();
    
    //Check number of points
    if(length < 6 | length > 6){
        error("error 1");
    }
    
}

void checkRange(double digits[6]){
    
    for(int i = 0; i < 6; i++){
        if(digits[i] < 0| digits[i] >100){
            error("error 1");
        }
    }
    
}

bool isSamePoint(Point a, Point b){
    if(a.x == b.x && a.y == b.y){
        return true;
    }
    return false;
}

void checkPointColl(Point a, Point b, Point c, Point d){
    
    if(isSamePoint(a,b) | isSamePoint(b,c) | isSamePoint(c,d) | isSamePoint(d,a)){
        error("error 2");
        exit(1);
    }
    
}

//Modified from www.geeksforgeeks.org/program-for-point-of-intersection-of-two-lines
bool isOnLine(Point a, Point b, Point intersect){
    
    double ax, bx, ay, by;
    
    //Determine max and min x values
    if(a.x >= b.x){
        ax = b.x;
        bx = a.x;
        
    } else {
        ax = a.x;
        bx = b.x;
    }
    
    //Determine max and min y values
    if(a.y >= b.y){
        ay = b.y;
        by = a.y;
        
    } else {
        ay = a.y;
        by = b.y;
    }
    
    //Determine if intersect is on line
    if(ax <= intersect.x && intersect.x <= bx && ay <= intersect.y && intersect.y <= by){
        return true;
    }
    
    return false;
}

//Modified from www.geeksforgeeks.org/program-for-point-of-intersection-of-two-lines
void checkLineColl(Point a, Point b, Point c, Point d){
    
    //Line AB = c1 = a1x + b1y
    double a1 = c.y - b.y; //expect 1
    double b1 = b.x - c.x; //expect -7
    double c1 = a1*(b.x) + b1*(b.y); //expect -60
    
    //Line CD = c2 = a2x + b2y
    double a2 = a.y - d.y; //expect -3
    double b2 = d.x - a.x; //expect 9
    double c2 = a2*(d.x) + b2*(d.y); //expect 0
    
    double determinant = a1*b2 - a2*b1; //expect -12
    
    if(determinant != 0){
        double x = (b2*c1 - b1*c2)/determinant; //expect 45
        double y = (a1*c2 - a2*c1)/determinant; //expect 15
        Point intersect = {x,y};
        
        if(isOnLine(b,c,intersect) && isOnLine(d,a,intersect)){
            error("error 3");
            exit(1);
        }
        
    }
    
}

//Modified from www.geeksforgeeks.org/program-check-three-points-collinear
double calcTriArea(Point a, Point b, Point c){
    return a.x * (b.y-c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

void checkCollinear(Point a, Point b, Point c, Point d){
    
    if(calcTriArea(a,b,c) == 0 || calcTriArea(b,c,d) == 0 || calcTriArea(c,d,a) == 0 || calcTriArea(d,a,b) == 0){
        error("error 4");
        exit(1);
    }
    
}

void checkForErrors(Point a, Point b, Point c, Point d){
    
    //Confirm no points are the same
    checkPointColl(a,b,c,d);
    
    //Confirm no lines cross
    checkLineColl(a,b,c,d);
    
    //Confirm no 3 points are collinear
    checkCollinear(a,b,c,d);
    
}

std::vector<std::string> parseLine(std::string line){
    
    std::stringstream ss(line);
    std::string value;
    std::vector<std::string> parsed;
    while (std::getline(ss, value, ' '))
    {
        parsed.push_back(value);
    }
    
    checkLength(parsed);
    
    return parsed;
    
}

/*
 * DATA INPUT FXNS
 * Stores user inputted quadrilateral data
 */

//Stores a quadrilateral
Quad storeQuad(Point a, Point b, Point c, Point d){
    
    Angle angA = {d,a,b, calcDeg(d,a,b)};
    Angle angB = {a,b,c, calcDeg(a,b,c)};
    Angle angC = {b,c,d, calcDeg(b,c,d)};
    Angle angD = {c,d,a, calcDeg(c,b,a)};
    
    Quad quad = {calcLength(a,b), calcLength(b,c), calcLength(c,d), calcLength(d,a), angA, angB, angC, angD};
    
    return quad;
    
}

//Stores input data
std::vector<Quad> storeInputData(){
    
    std::vector<Quad> data;
    
    while(!std::cin.eof()){
        
        //Input line
        std::string line;
        getline(std::cin, line);
        
        //Parse line
        std::vector<std::string> parsed = parseLine(line);
        
        //Convert to digits
        double digits[6];
        for(int i = 0; i < parsed.size(); i++){
            
            if(isdigit(parsed[i][0])){
                double digit = stoi(parsed[i]);
                digits[i] = digit;
            } else {
                error("error 1");
            }
        }
        
        checkRange(digits);
        
        Point a = {0,0};
        Point b = {digits[0],digits[1]};
        Point c = {digits[2],digits[3]};
        Point d = {digits[4],digits[5]};
        
        //Check points
        checkForErrors(a, b, c, d);
        
        data.push_back(storeQuad(a, b, c, d));
        
    }
    
    return data;
    
}

/*
 * MAIN
 */

int main(int argc, const char * argv[]) {
    
    //Store data points from file
    std::vector<Quad> data = storeInputData();
    
    //Classify each quadrilateral
    for(int i = 0; i < data.size(); i++){
        classifyQuad(data[i]);
    }
    
    return 0;
    
}
