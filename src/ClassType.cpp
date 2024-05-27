#include "Class.hpp"

void addClassType(const ClassType& classType) 
{
    classes.push_back(classType);
}


void classDetails(ClassType* c)
{
    cout << "Class Name : " << c->className << endl;
    cout << "Class Capacity : "<< c->capacity << endl;
    cout << "Class price per km : " << c->price << endl;
}