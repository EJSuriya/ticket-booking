#ifndef CLASS_HPP
#define CLASS_HPP

#include "Train.hpp"
#include <algorithm>
#include "Class.hpp"
using namespace std;



void create_train()
{
	ClassType* acClass=new ClassType("AC", 100, 2.2);
	ClassType *sleeperClass=new ClassType("sleeper", 100, 1.2);
    ClassType *ladies=new ClassType("ladies", 100, 1.3);
    ClassType *secondSitting=new ClassType("sitting", 100, 1);
    ClassType *unreserved=new ClassType("ur", 100, 0.8);
	
    Schedule *schedule=new Schedule("5.45pm", "2.30am");

    
    classTypes.push_back(acClass);
    classTypes.push_back(sleeperClass);
    classTypes.push_back(ladies);
    classTypes.push_back(secondSitting);
    classTypes.push_back(unreserved);
    

    // create stations
    stations *s1=new stations("Chennai-Egmore", 0.0);
    stations *s2=new stations("vilupuram", 165.0);
    stations *s3=new stations("trichy", 164.0);
    stations *s4=new stations("pudukottai", 56.0);
    stations *s5=new stations("Mandabam-Ramnad", 129.0);
    vector<stations*>route;
    route.push_back(s1);
    route.push_back(s2);
    route.push_back(s3);
    route.push_back(s4);
    route.push_back(s5);
    // creating train 
    Train *express=new Train(train_id,"Rameswaram Express", classTypes, schedule, "Chennai", "Ramnad", "2024-05-04", route);
    Train *express1=new Train(train_id,"Rameswaram Express", classTypes, schedule, "Chennai", "Ramnad", "2024-05-05", route);
    Train *express2=new Train(train_id,"Rameswaram Express", classTypes, schedule, "Chennai", "Ramnad", "2024-05-06", route);
    Train *express3=new Train(train_id,"Rameswaram Express", classTypes, schedule, "Chennai", "Ramnad", "2024-05-07", route);
    Train *express4=new Train(train_id,"Rameswaram Express", classTypes, schedule, "Chennai", "Ramnad", "2024-05-08", route);
    Train *express5=new Train(train_id,"Rameswaram Express", classTypes, schedule, "Chennai", "Ramnad", "2024-05-09", route);
    trainList.push_back(express);
    trainList.push_back(express1);
    trainList.push_back(express2);
    trainList.push_back(express3);
    trainList.push_back(express4);
    trainList.push_back(express5);
}

void trainDetails(Train* t)
{
	cout<<"TRAIN ID :"<<t->get_train_id()<<endl;
    cout << "Train name : "<< t->getTrainName() << endl;
    cout << "Source : "<< t->getSource() << endl;
    cout << "Destination : "<< t->getDestination() << endl;
    cout << "Departure time : "<< t->getSchedule()->getDepartureTime() << endl;
    cout << "Arrived time : "<< t->getSchedule()->getArrivedTime() << endl;
    cout << "Date : "<< t->getDate() << endl;
    
    cout << "Available Seats:" << endl;
    for (int i = 0; i < t->getClasses().size(); i++)
    {
        cout << t->getClasses()[i]->getClassName() << " : " << t->getClasses()[i]->getCapacity() << endl;
    }
}


Train* searchTrain(string date,string source,string destination) 
{
	Train *train=nullptr;
    for (auto train : trainList) 
    {
        if (train->getDate() == date && train->getSource() == source && train->getDestination() == destination)
        {
            return train;
        }
    }
    return nullptr;
}


void allStations(int id)
{
    int stationNo = 1;
    for(auto t : trainList)
    {
    	if(t->get_train_id()==id)
    	{
        	for(auto s : t->getRoute())
        	{
            	cout <<stationNo++<<"."<<s->get_stationName() << endl;
        	}
        	break;
        }
    }
}


void trainTimings()
{
    int source;
    int destination;
    string date;
    int id,temp=0;
    for (auto it :trainList)
    {
    	if(temp==it->get_train_id())
    	{
    		continue;
    	}
    	cout<<"TRAIN NAME : "<< it->getTrainName()<<"           TRAIN ID :"<<it->get_train_id()<<endl;
    	temp=it->get_train_id();
    }
    cout << "ENTER THE TRAIN ID IN WHICH YOU WANT TO CHECK:" <<endl;
    cin>>id;
    bool id_present=false;
    for (auto ite :trainList)
    {
    	if(ite->get_train_id()==id)
    	{
    		id_present=true;
    	}
    }
    if(!id_present)
    {
    	cout<<"INCORRECT TRAIN ID !!!"<<endl;
    	return;
    }
    allStations(id);
    int count=0;
    for (auto ite :trainList)
    {
    	if(ite->get_train_id()==id)
    	{
    		++count;
    		cout << "timing of this train is " << endl;
    		cout << "arrival time is : "<< ite->getSchedule()->getArrivedTime()<<endl;
    		cout << "departure time is : "<< ite->getSchedule()->getDepartureTime()<<endl;
    	}
    	if(count>0)
    	{
    		break;
    	}
    }
    
}

void addTrain2()
{
    string name;
    string date;
    string source;
    string destination;
    int id;
    cout <<"ENTER THE TRAIN ID :"<<endl;
    cin>>id;
    cout << "please enter the train name " << endl;
    cin >> name;
    cout << "enter the source location of the train " << endl;
    cin >> source;
    cout << "enter the destination of the train " << endl;
    cin >> destination;
    cout << "enter the journey date " << endl;
	cin>>date;
    vector<ClassType*> classes;

    for (int i = 0; i < 4; i++)
    {
        string className;
        int capacity;
        double price;
        cout << "enter the class name" << endl;
        cin >> className;
        cout << "enter the class capacity " << endl;
        cin >> capacity;
        cout << "enter the price for the class " << endl;
        cin >> price;
        ClassType* c = new ClassType(className,capacity,price);
        classes.push_back(c);
    }

    string departureTime;
    string arrivalTime;
    cout << "enter the departure time of the train " << endl;
    cin >> departureTime;
    cout << "enter the arrival time of the train " << endl;
    cin >> arrivalTime;

    Schedule *s =  new Schedule(departureTime,arrivalTime);

    string stationName;
    double distanceFromPrevious;
    vector<stations*> route;
    for (int i = 0; i < 10; i++)
    {
        cout << "enter the station name" << endl;
        cin >> stationName;
        cout << "enter the distance from the previous station" << endl;
        cin >> distanceFromPrevious;
        stations *s = new stations(stationName,distanceFromPrevious);
        route.push_back(s);
    }
    Train *train_obj = new Train(id,name,classes,s,source,destination,date,route);
    trainList.push_back(train_obj);
    cout << "created train successfully " << endl;
}

void addTrain()
{
	int id;
    for (auto it :trainList)
    {
    	cout<<"TRAIN NAME : "<< it->getTrainName()<<"           TRAIN ID :"<<it->get_train_id()<<endl;
    }
    cout << "ENTER THE TRAIN ID IN WHICH YOU WANT TO COPY AND CREATE ANOTHER TRAIN WITH DIFFERENT DATE:" <<endl;
    cin>>id;
    string date;
    cout << " enter the date of the travel" << endl;
    cin >> date;
    for (auto ite :trainList)
    {
    	if(ite->get_train_id()==id)
    	{
 			Train* train_obj = new Train(ite,date);
    		trainList.push_back(train_obj);
    		cout << "created train successfully " << endl;
    		trainDetails(train_obj);
    		return;
    	}
    }
    cout<<"!!! INCORRECT TRAIN ID !!!"<<endl;
    
}

//void train_details(string a,string b,string c,string d,)


// show all the stations



// return the  particular station
string returnStation(int no)
{
    int stationNo = 1;
    for(auto t : trainList)
    {
        for(auto s : t->getRoute())
        {
            if (stationNo++ == no)
            {
            	cout<<s->get_stationName()<<endl;
                return s->get_stationName();
            }
            
        }
    }
    return "null";
}



vector<Train*> searchTRainAdvanced(int* so, int* d,string* da)
{
    vector<Train*> filteredList;
    Train* train = nullptr;
    string source;
    string destination;
    string date;
    label:
    int train_id=100;
    /*
    for (auto it :trainList)
    {
    	cout<<"TRAIN NAME : "<< it->getTrainName()<<"           TRAIN ID :"<<it->get_train_id()<<endl;
    }
    cout << "ENTER THE TRAIN ID IN WHICH YOU WANT TO CHECK:" <<endl;
    cin>>train_id;*/
    allStations(train_id);
    int ssno;
    int dsno;
    //bool date_present=false;
    cout << "enter the source location number " << endl;
    cin >> ssno;
    if(ssno<1 || ssno>=5 )
    {
    	cout<<"!!!INVALID INPUT CANNOT BOOK TICKET!!!"<<endl;
    	goto label;
    }
    cout << "please enter the destination number" << endl;
    cin >> dsno;
    if(dsno<=ssno || dsno<=1 || dsno >5)
    {
    	cout<<"!!!INVALID INPUT CANNOT BOOK TICKET!!!"<<endl;
    	goto label;
    }
    for (auto it :trainList)
    {
    	cout<<"TRAIN NAME : "<< it->getTrainName()<<"           AVAILABLE DATES :"<<it->getDate()<<endl;
    }
    cout << "enter the journey date (y/m/d)"<<endl;
    cin >> date;
    /*for (auto it :trainList)
    {
    	if(it->getDate()==date)
    	{
    		date_present=true;
    	}
    }
    if(!date_present)
    {
    	cout<<"!!!INVALID INPUT CANNOT BOOK TICKET!!!"<<endl;
    	goto label;
    }*/
    source = returnStation(ssno);
    destination = returnStation(dsno);

    for(auto t : trainList)
    {
        for(auto s : t->getRoute())
        {
            if (s->get_stationName() == source)
            {
                for (int i = 0; i < t->getRoute().size(); i++)
                {
                    if (t->getRoute()[i]->get_stationName() == destination)
                    {
                        if (date == t->getDate())
                        {
                        	
                            filteredList.push_back(t);
                            *so=ssno;
                            *d=dsno;
                            *da=date;
                            return filteredList;
                        }
                    }
                }
            }
        }
    }
    cout<<"TRAIN WAS NOT AVAILABLE FOR THAT PARTICULAR DAY YOU HAVE ENTERED!!!"<<endl; 
    return filteredList;  
}



void removeTrain(Train* t,int id)
{
    auto it =find(trainList.begin(), trainList.end(), t);
    
    // Check if the element was found
    if (it != trainList.end()) {
        trainList.erase(it); // Erase the element using the iterator
    }
    cout << "train deleted successfully " << endl;
}

// get all train details

void allTrainDetails()
{
    for(auto  t : trainList)
    {
        trainDetails(t);
    }
}



void betweenStations(Train* train)
{
    for (int i = 0; i < train->getRoute().size(); i++)
    {
        cout <<"station name : " <<train->getRoute()[i]->get_stationName() <<"distance from the previous station : "
        <<train->getRoute()[i]->get_distanceFromPrevious() << endl;
    }
    
}



void calculateTicketFare()
{
    int sno;
    int dno;
    int train_id,temp;
    bool present=false;
    Train* obj=nullptr;
    for (auto it :trainList)
    {
    	if(temp==it->get_train_id())
    	{
    		continue;
    	}
    	cout<<"TRAIN NAME : "<< it->getTrainName()<<"           TRAIN ID :"<<it->get_train_id()<<endl;
    	temp=it->get_train_id();
    }
    cout << "ENTER THE TRAIN ID IN WHICH YOU WANT TO CHECK:" <<endl;
    cin>>train_id;
    for (auto it :trainList)
    {
    	if(it->get_train_id()==train_id)
    	{
    		obj=it;
    		present=true;
    	}
    }
    if(!present)
    {
    	cout<<"INCORRECT TRAIN ID !!!!!"<<endl;
    	return;
    }
    allStations(train_id);
    cout << "enter source location number " << endl;
    //semicolon error
    cin >> sno;
    cout << "enter destination number " << endl;
    cin >> dno;
    string source;
    string destination;
    source = returnStation(sno);
    //semicolon error
    destination = returnStation(dno);
    string className;
    cout << "enter the class name " << endl;
    cin >> className;
    double distance;
    int start = -1;
    int end = -1;
    for (int i = 0; i < obj->getRoute().size(); i++)
    {
        if (obj->getRoute()[i]->get_stationName() == source)
        {
            start = i;            
        }
        else if (obj->getRoute()[i]->get_stationName() == destination)
        {
            end = i;
        }
        if (end != -1 && start != -1)
        {
            break;
        }  
    }
    
    for (int i = start+1; i <= end ;i++)
    {
        distance += obj->getRoute()[i]->get_distanceFromPrevious();
    }
    double fare;
    for(auto c : obj->getClasses())
    {
        if (c->getClassName() == className)
        {
            fare = distance * c->getPrice();
        }
        
    }
	cout<<"THE TOTAL FARE AMOUNT IS : "<<fare<<endl;
}


double calculateJourneyFare(Train* train,int source,int destination,string className)
{
	double distance;
    for (int i = source-1; i < destination ;i++)
    {
        distance += train->getRoute()[i]->get_distanceFromPrevious();
    }
    double fare;
    for(auto c : train->getClasses())
    {
        if (c->getClassName() == className)
        {
            fare = distance * c->getPrice();
        }
        
    }
	cout<<"THE TOTAL FARE AMOUNT IS : "<<fare<<endl;
    return fare;
}

void seat_status()
{
	int seatNo,tno,temp;
	string name,date;
	bool available;
	for (auto it :trainList)
    {
    	if(temp==it->get_train_id())
    	{
    		continue;
    	}
    	cout<<"TRAIN NAME : "<< it->getTrainName()<<"           TRAIN ID :"<<it->get_train_id()<<endl;
    	temp=it->get_train_id();
    }
    cout << "ENTER THE TRAIN ID: " << endl;
    cin >>tno;
    cout << "ENTER THE DATE IN WHICH YOU WANT TO CHECK:"<<endl;
    cin>>date;
    Train* train_obj;
    bool present=false;
    for(auto t : trainList)
    {
        if(t->get_train_id()==tno && t->getDate()==date)
        {
        	present=true;
            train_obj = t;
        }
    }
    if(!present)
    {
    	cout<<"!!!INCORRECT TRAIN ID!!!"<<endl;
    	return;
    }
	cout<<"ENTER THE CLASS TYPE:"<<endl;
	cin>>name;
	cout<<"ENTER THE SEAT NUMBER YOU WANT TO CHECK:"<<endl;
	cin>>seatNo;
	available=isSeatAvailable(train_obj,seatNo-1,name);
	
	if(available)
	{
		cout<<"SEAT IS AVAILABLE"<<endl;
	}
	else
	{
		cout<<"SEAT IS NOT AVAILABLE"<<endl;
	}
}



#endif
