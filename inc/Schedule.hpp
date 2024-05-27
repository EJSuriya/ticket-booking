#ifndef SCHEDULE
#define SCHEDULE

#include "Main.hpp"

void schedule(Schedule s);

class Schedule 
{
private:
    string departureTime;
    string arrivedTime;

public:
    Schedule(const string& depTime, const string& arrTime)
        : departureTime(depTime), arrivedTime(arrTime) {}
    Schedule(Schedule s)
    {
        this->arrivedTime = s.arrivedTime;
        this->departureTime = s.departureTime;
    }

    string getDepartureTime()
    { 
    	return departureTime;
    }
    string getArrivedTime()
    { 
    	return arrivedTime;
    }
};

#endif 
