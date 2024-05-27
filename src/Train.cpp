#include "Train.hpp"

void trainTimings()
{
    string source;
    string destination;
    string date;
    cout << "enter the source location " << endl;
    cin >> source;
    cout << " enter the destination " << endl;
    cin >> destination;
    cout << "enter the journey date " << endl;
    cin >> date;
    Train* train =  nullptr;
    train = searchTrain(date,source,destination);
    cout << "timing of this train is " << endl;
    cout << "arrival time is : "<< train->getSchedule().getArrivedTime();
    cout << "departure time is : "<< train->getSchedule().getDepartureTime()
}

void addTrain2()
{
    string name;
    string date;
    string source;
    string destination;
    cout << "please enter the train name " << endl;
    cin >> name;
    cout << "enter the source location of the train " << endl;
    cin >> source;
    cout << "enter the destination of the train " << endl;
    cin >> destination;
    cout << "enter the journey date " << endl;

    vector<ClassType> classes;

    for (int i = 0; i < 4; i++)
    {
        string className;
        string capacity;
        double price;
        cout << "enter the class name" << endl;
        cin >> className;
        cout << "enter the class capacity " << endl;
        cin >> capacity;
        cout << "enter the price for the class " << endl;
        cin >> price;
        ClassType c = new ClassType(className,capacity,price);
        classes.push_back(c);
    }

    string departureTime;
    string arrivalTime;
    cout << "enter the departure time of the train " << endl;
    cin >> departureTime;
    cout << "enter the arrival time of the train " << endl;
    cin >> arrivalTime;

    Schedule s =  new Schedule(departureTime,arrivalTime);

    string stationName;
    double distanceFromPrevious;
    vector<stations> route;
    for (int i = 0; i < 10; i++)
    {
        cout << "enter the station name" << endl;
        cin >> stationName;
        cout << "enter the distance from the previous station" << endl;
        cin >> distanceFromPrevious;
        stations s = new stations(stationName,distanceFromPrevious);
        route.push_back(s);
    }
    Train train = new Train(name,classes,s,source,destination,data,route);
    trainList.push_back(train);
    cout << "created train successfully " << endl;
}

void addTrain(ClassType* c,Schedule* s,stations* station)
{
    string name;
    string source;
    string destination;
    string date;
    int availabeSeats;
    cout << "enter the name of the train " << endl;
    cin >> name;
    cout << "enter the souce location" << endl;
    cin >> source;
    cout <<"enter the destination" << endl;
    cin >> destination;
    cout << " enter the date of the travel" << endl;
    cin >> date;

    string className;
    int classCapacity;
    float classPrice;
    cout << "enter the class name" << endl;
    cin >> className;
    cout << "enter the class capacity" << endl;
    cin >> Capacity;
    cout << "enter the class price " << endl;
    ClassType* cls1 = new ClassType(c);
    ClassType* cls2 = new ClassType(c);
    ClassType* cls3 = new ClassType(c);
    ClassType* cls4 = new ClassType(c);
    vector <ClassType> classType;
    classType.push_back(cls1);
    classType.push_back(cls2);
    classType.push_back(cls3);
    classType.push_back(cls4);
    Schedule* s1 = new Schedule(s);
    vector<stations*>route;
    stations* st1 = new stations(station);
    stations* st2 = new stations(station);
    stations* st3 = new stations(station);
    stations* st4 = new stations(station);
    stations* st5 = new stations(station);
    stations* st6 = new stations(station);
    route.push_back(st1);
    route.push_back(st2);
    route.push_back(st3);
    route.push_back(st4);
    route.push_back(st5);
    route.push_back(st6);
    Train* train = new Train(name,classType,s1,source,destination,date,route);
    trainDetails(train);
}


Train* searchTrain(const string& date, const string& source, const string& destination) {
    for (auto& train : trainList) {
        if (train.getDate() == date && train.getSource() == source && train.getDestination() == destination) {
            return &train;
        }
    }
    return nullptr;
}


vector<Train*> searchTRainAdvanced()
{
    vector<Train*> filteredList;
    Train* train = nullptr;
    string source;
    string destination;
    string date;
    cout << "enter the source location number " << endl;
    int ssno;
    int dsno;
    allStations();
    cin >> ssno;
    allStations()
    cout << "please enter the destination number" << endl;
    cin >> dsno;
    cout << "enter the journey date (y/m/d)"<<endl;
    cin >> date;
    source = returnStation(ssno)->stationName;
    destination = returnStation(dsno)->stationName;

    for(auto& t : trainList)
    {
        int index = 0;
        for(auto& s : t.getRoute())
        {
            index++;
            if (s.stationName == source)
            {
                for (int i = index; i < t.getRoute().size(); i++)
                {
                    if (t.getRoute()[i].stationName == destination)
                    {
                        if (date = t.getDate())
                        {
                            filteredList.push_back(t);
                        }
                    }
                }
            }
        }
    }  
    return filteredList;  
}


void trainDetails(Train* t)
{
    cout << "Train name : "<< t->getTrainName() << endl;
    cout << "Source : "<< t->getSource() << endl;
    cout << "Destination : "<< t->getDestination() << endl;
    cout << "Departure time : "<< t->getSchedule().getDepartureTime() << endl;
    cout << "Arrived time : "<< t->getSchedule().getArrivedTime() << endl;
    cout << "Date : "<< t->getDate() << endl;
    
    cout << "Available Seats:" << endl;
    for (int i = 0; i < t->getClasses().size(); i++)
    {
        cout << t->getClasses()[i].className << " : " << t->getClasses()[i].capacity << endl;
    }
}

void removeTrain(Train t,int id)
{
    Train* elementToDelete = nullptr;
    for (int i = 0; i < trainList.size();)
    {
        if (t.getTrainId() == id)
        {
            elementToDelete = t;
        }
    }

    auto it = find(trainList.begin(),trainList.end(),elementToDelete);

    if (it != trainList.end())
    {
        trainList.erase(it);
    }
    cout << "train deleted successfully " << endl;
}

// get all train details

void allTrainDetails()
{
    for(auto & t : trainList)
    {
        trainDetails(t);
    }
}
