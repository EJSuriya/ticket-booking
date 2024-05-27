#ifndef CLASS
#define CLASS

#include "Main.hpp"

// function prototype
void addClassType(const ClassType& classType);
void classDetails(ClassType* c);


static int Capacity = 500;

struct ClassType {
    string className;
    int capacity;
    double price;

    // Constructor
    ClassType(const string& name, int cap, double price)
        : className(name), capacity(cap), price(price) {}

    // Copy constructor
    ClassType(ClassType* c)
    {
        this->className = c->className;
        this->price = c->price;
        this->capacity = c->capacity;
    }

    // Getter methods
    string getClassName()
    {
         return className;
    }
    int getCapacity()
    {
        return capacity; 
    }
    double getPrice()
    {
        return price;
    }
};


#endif