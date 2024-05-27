#include "Class.hpp"
//#include "Main.hpp"

void addClassType(ClassType* classType) 
{
    classTypes.push_back(classType);
}


void classDetails(ClassType* c)
{
    cout << "Class Name : " << c->getClassName() << endl;
    cout << "Class Capacity : "<< c->getCapacity()<< endl;
    cout << "Class price per km : " << c->getPrice() << endl;
}
