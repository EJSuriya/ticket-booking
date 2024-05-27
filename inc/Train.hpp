#ifndef TRAIN
#define TRAIN

#include "Main.hpp"


static int tid = 1;
static int Capacity = 500;

// Function prototype for retrieving train timings
void trainTimings();

// Function prototype for adding a train with a parametrized constructor
void addTrain2();

// Function prototype for adding a train with a copy constructor
void addTrain(ClassType* c, Schedule* s, stations* station);

// Function prototype for searching a train by date, source, and destination
Train* searchTrain(const string& date, const string& source, const string& destination);

// Function prototype for searching trains in advance
vector<Train*> searchTrainAdvanced();

// Function prototype for displaying train details
void trainDetails(Train* t);

// Function prototype for removing a train from the list
void removeTrain(Train t, int id);

// Function prototype for retrieving details of all trains
void allTrainDetails();



class Train 
{
private:
    int trainId;
    string trainName;
    vector<ClassType> classes;
    Schedule schedule;
    string source;
    string destination;
    string date; 
    int availableSeats;
    vector<stations> route;

public:
    Train(const string& trainName, const vector<ClassType>& classTypes, const Schedule& schedule, const string& source, const string& destination, const string& date,const vector<stations>& route)
        : trainId(tid++), trainName(trainName), classes(classTypes), schedule(schedule), source(source), destination(destination), date(date),availableSeats(Capacity),route(route) {}
    Train(Train* t)
    {
        this->getTrainId() = t->getTrainId();
        this->getTrainName() = t->getTrainName();
        this->classes = t->getClasses();
        this->getRoute() = t->getRoute();
        this->getSource() = t->getSource();
        this->getDestination() = t->getDestination();
        this->getDate() = t->getDate();
        this->availableSeats = t->availableSeats;
        this->getSchedule() = t->getSchedule();
    }
    int getTrainId()
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
    const Schedule& getSchedule()
    { 
    	return schedule;
    }
    const vector<ClassType>& getClasses()
    { 
    	return classes;
    }
    const vector<stations>& getRoute()
    {
    	return route;
    }

};

#endif
