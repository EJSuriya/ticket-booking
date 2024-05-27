#ifndef STATION
#define STATION

#include "Main.hpp"

#include "Train.hpp" 

// Function prototype for displaying stations between route
void betweenStations(Train* train);

// Function prototype for displaying all stations
void allStations();

// Function prototype for returning a particular station
stations* returnStation(int no);

struct stations
{
    string stationName;
    double distanceFromPrevious;
    stations(string stationName,double distance):stationName(stationName),distanceFromPrevious(distance){}
    stations(stations* sta)
    {
        this->distanceFromPrevious = sta->distanceFromPrevious;
        this->stationName = sta->stationName;
    }
};

#endif
