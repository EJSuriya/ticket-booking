#ifndef CLASS
#define CLASS

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//static int Capacity = 500;

class ClassType {
	private:
    string className;
    int capacity;
    double price;
	public:
    // Constructor
    ClassType(string name, int cap, double price)
        : className(name), capacity(cap), price(price) {}

    // Copy constructor
    ClassType(ClassType* c)
    {
        this->className = c->getClassName();
        this->price = c->getPrice();
        this->capacity = c->getCapacity();
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
    void decrease_count()
    {
    	--capacity;
    }
};


// Creating vector of ClassType for train classes
static vector<ClassType*> classTypes;

// function prototype
void addClassType(const ClassType& classType);
void classDetails(ClassType* c);

#endif
