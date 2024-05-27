#ifndef TRAIN_HPP
#define TRAIN_HPP



#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <queue>
//#include "Main.hpp"
#include "Class.hpp"
//#include "Station.hpp"
#include "Schedule.hpp"

using namespace std;

static int tid = 1;
static int Capacity = 500;
static int train_id=100;

class stations
{
	private:
    string stationName;
    double distanceFromPrevious;
    public:
    stations(string stationName,double distance):stationName(stationName),distanceFromPrevious(distance){}
    string get_stationName()
    {
    	return stationName;
    }
    double get_distanceFromPrevious()
    {
    	return distanceFromPrevious;
    }
    stations(stations* sta)
    {
        this->distanceFromPrevious = sta->get_distanceFromPrevious();
        this->stationName = sta->get_stationName();
    }
};



class Train 
{
private:
    int trainId;
    string trainName;
    vector<ClassType*> classes;
    Schedule *schedule;
    string source;
    string destination;
    string date; 
    vector<stations*> route;
    

public:
	bool acArray[100];
	bool ladiesArray[100];
	bool sleeperArray[100];
	bool sittingArray[100];
    Train(int id,string trainName,vector<ClassType*> classTypes,Schedule* schedule,string source,string destination,string date,vector<stations*> route)
        : trainId(id), trainName(trainName), classes(classTypes), schedule(schedule), source(source), destination(destination), date(date),route(route) 
        {
        	fill(acArray, acArray + 100, true);
			fill(sleeperArray, sleeperArray + 100, true);
			fill(ladiesArray, ladiesArray + 100, true);
			fill(sittingArray, sittingArray + 100, true);
        };
        
   Train(Train* t, string date)
    {
        this->trainId = t->get_train_id();
        this->trainName = t->getTrainName();
        this->date = date;
        this->classes = t->getClasses();
        this->route = t->getRoute();
        this->source = t->getSource();
        this->destination = t->getDestination();
        this->schedule = t->getSchedule();
        fill(acArray, acArray + 100, true);
		fill(sleeperArray, sleeperArray + 100, true);
		fill(ladiesArray, ladiesArray + 100, true);
		fill(sittingArray, sittingArray + 100, true);
    };
    Train(){};
    int get_train_id()
    { 
    	return trainId;
    	
    }
    string getTrainName()
    { 
    	return trainName;
    	
    }
    string getSource()
    { 
    	return source;
    }
    string getDestination()
    { 
    	return destination;
    }
    string getDate()
    { 
    	return date;
    }
    Schedule* getSchedule()
    { 
    	return schedule;
    }
    vector<ClassType*> getClasses()
    { 
    	return classes;
    }
    vector<stations*> getRoute()
    {
    	return route;
    }
    
    bool* get_ac_array()
    {
    	return acArray;
    }
    bool* get_sleeper_array()
    {
    	return sleeperArray;
    }
    bool* get_ladies_array()
    {
    	return ladiesArray;
    }
    bool* get_sitting_array()
    {
    	return sittingArray;
    }
    
	friend bool isSeatAvailable(Train* train,int seatNumber, string name);
	
	friend void reset_status(Train* train,int seatNo,string name);
	
	friend void change_seat_status(Train* train,int array);
};

//extern Train *obj;

//extern Train* train_obj ;

//Train train;

//Train* obj =nullptr;

// save train objects
static vector <Train*> trainList;

void create_train();

// Function prototype for retrieving train timings
void trainTimings();

// Function prototype for adding a train with a parametrized constructor
void addTrain2();

// Function prototype for adding a train with a copy constructor
void addTrain();

// Function prototype for searching a train by date, source, and destination
Train* searchTrain(string date,string source,string destination);

// Function prototype for searching trains in advance
vector<Train*> searchTRainAdvanced(int *a,int *b,string *c);

// Function prototype for displaying train details
void trainDetails(Train* t);

// Function prototype for removing a train from the list
void removeTrain(Train t, int id);

// Function prototype for retrieving details of all trains
void allTrainDetails(int id);

//void Train(Train t);





#endif
