#ifndef SCHEDULE
#define SCHEDULE

#include <string>
#include <iostream>
using namespace std;

class Schedule 
{
private:
    string departureTime;
    string arrivedTime;

public:
    Schedule(string depTime,string arrTime)
        : departureTime(depTime), arrivedTime(arrTime) {}
    Schedule(Schedule* s)
    {
        this->arrivedTime = s->arrivedTime;
        this->departureTime = s->departureTime;
    }
	Schedule(){}
    string getDepartureTime()
    { 
    	return departureTime;
    }
    string getArrivedTime()
    { 
    	return arrivedTime;
    }
};

void schedule(Schedule s);

#endif 
