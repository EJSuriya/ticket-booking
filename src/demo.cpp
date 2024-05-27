#include <iostream>
#include <string>
#include <vector>
#include<map>
#include<memory>
#include<algorithm>
// #include <nlohmann/json.hpp>
// #include <nlohmann/adl_serializer.hpp>

using namespace std;

class passenger {
private:
    int passengerId;
    string name;
    int age;
    char gender;
    string username;
    string password;
    static int counter;

public:
    passenger() : passengerId(counter++) {} // Assign incremented counter value
    passenger(string name, int age, char gender, string username, string password)
        : name(name), age(age), gender(gender), username(username), password(password), passengerId(counter++) {}

    // Getter methods
    int getPassengerId() const { return passengerId; }
    string getName() const { return name; }
    int getAge() const { return age; }
    char getGender() const { return gender; }
    string getUsername() const { return username; }
    string getPassword() const { return password; }
};

int passenger::counter = 0; // Initialize static member variable

struct Tree {
    vector<passenger> passengerList[8];
    Tree* left;
    Tree* right;
};

Tree* createNode(passenger p, Tree* node) {
    if (node == nullptr)
    {
        Tree* newNode = new Tree;
        // newNode->passengerList[0].push_back(p);
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    // node->passengerList[0].push_back(p);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void condition(Tree*& root, passenger* p)
{
    if (root == nullptr)
    {
        root = createNode(*p, nullptr);
        return;
    }
    if (p->getGender() == tolower('f'))
    {
        if (p->getAge() < 60)
        {
            if (p->getName()[0] >= tolower('a') && p->getName()[0] < tolower('m'))
            {
                root->passengerList[0].push_back(*p);
            }else
            {
                root->passengerList[1].push_back(*p);
            }
            
        }else
        {
            if (p->getName()[0] >= tolower('a') && p->getName()[0] < tolower('m'))
            {
                root->passengerList[2].push_back(*p);
            }else
            {
                root->passengerList[3].push_back(*p);
            }
        }
    }else
    {
        if (p->getAge() < 60)
        {
            if (p->getName()[0] >= tolower('a') && p->getName()[0] < tolower('m'))
            {
                root->passengerList[4].push_back(*p);
            }else
            {
                root->passengerList[5].push_back(*p);
            }
            
        }else
        {
            if (p->getName()[0] >= tolower('a') && p->getName()[0] < tolower('m'))
            {
                root->passengerList[6].push_back(*p);
            }else
            {
                root->passengerList[7].push_back(*p);
            }
        }
    }
}

Tree* insert(Tree* root, passenger* p)
{
    condition(root,p);
    return root;
}

// search passenger 
passenger* getPassenger(Tree* root, int passengerId)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    for (int i = 0; i < 8; i++)
    {
        for (const auto& passengers : root->passengerList[i])
        {
            if (passengers.getPassengerId() == passengerId)
            {
                return const_cast<passenger*>(&passengers);
            }
        }
    }

    return nullptr;
}

// for traversal

void printUserDetails(Tree* node)
{
    if (node == nullptr)
    {
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < node->passengerList[i].size(); j++)
        {
            cout << node->passengerList[i][j].getPassengerId() << " ";
            cout << node->passengerList[i][j].getName() << " ";
            cout << node->passengerList[i][j].getAge() << " ";
            cout << node->passengerList[i][j].getGender() << " ";
            cout << node->passengerList[i][j].getUsername() << " ";
            cout << node->passengerList[i][j].getPassword() << endl;
        }
    }
    printUserDetails(node->left);
    printUserDetails(node->right);
}

void signUp(Tree*& root)
{
    string name;
    int age;
    char gender;
    string username;
    string password;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    passenger* p = new passenger(name, age, gender, username, password);
    root = insert(root, p); // Update the root pointer with the new passenger
    cout << "Passenger added successfully" << endl;
}

// log in
void logIn(Tree* root)
{
    string username;
    string password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    bool loggedIn = false;
    const int maxAttempts = 3;
    int attempts = 0;

    while (!loggedIn && attempts < maxAttempts)
    {
        for (auto i = 0; i < 8; i++)
        {
            for(const auto& passenger : root->passengerList[i])
            {
                if (passenger.getUsername() == username && passenger.getPassword() == password)
                {
                    loggedIn = true;
                    cout << "LOG IN successful"<< endl;
                    // Additional actions for successful login (if any)
                    return; // Exit the function after successful login
                }
            }
        }
        
        attempts++;
        if (attempts < maxAttempts)
        {
            cout << "Login failed. Please try again." << endl;
            cout << "Attempts left: " << maxAttempts - attempts << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
        }
    }

    if (!loggedIn)
    {
        cout << "Login failed after " << maxAttempts << " attempts." << endl;
        cout << "Would you like to sign up? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            signUp(root); // Prompt the user to sign up if desired
        }
    }
}

void logOut(Tree* root)
{
    string username;
    string password;
    cout << "enter the username" << endl;
    cin >> username;
    cout << "enter the password " << endl;
    cin >> password;
    for (int i = 0; i < 8; i++)
    {
        for(auto p : root->passengerList[i])
        {
            if (p.getUsername() == username && p.getPassword() == password)
            {
                auto it = find(root->passengerList[i].begin(),root->passengerList[i].end(),p);
                if (it != root->passengerList[i].end())
                {
                    root->passengerList[i].erase(it);
                    cout << "log out successful" << endl;
                    return;
                }
                
                cout << "LOG OUT successful" << endl;
                return;
            }
        }
    }
    
}

static int tid = 1;
static int Capacity = 500;

struct ClassType {
    string className;
    int capacity;
    double price;

    ClassType(const string& name, int cap, double price)
        : className(name), capacity(cap), price(price) {}
        ClassType(ClassType* c)
        {
            this->className = c->className;
            this->price = c->price;
            this->capacity = capacity;
        }
};

class Schedule {
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

    string getDepartureTime() const { return departureTime; }
    string getArrivedTime() const { return arrivedTime; }
};

// stations

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


class Train {
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
    int getTrainId() const { return trainId; }
    string getTrainName() const { return trainName; }
    string getSource() const { return source; }
    string getDestination() const { return destination; }
    string getDate() const { return date; } // Add getter for date
    const Schedule& getSchedule() const { return schedule; }
    const vector<ClassType>& getClasses() const { return classes; }
    const vector<stations>& getRoute() const {return route;}

    void addClassType(const ClassType& classType) {
        classes.push_back(classType);
    }
//     double calculateDistance(string source, string destination)
//     {
//         int start = -1, end = -1;

//         // Find the indices of the source and destination stations
//         for (int i = 0; i < route.size(); i++)
//         {
//             if (route[i].stationName == source)
//             {
//                 start = static_cast<int>(i);
//             }
//             else if (route[i].stationName == destination)
//             {
//                 end = static_cast<int>(i);
//             }

//             if (start != -1 && end != -1)
//                 break; // If both source and destination are found, exit the loop
//         }

//         // Check if source and destination stations were found
//         if (start == -1 || end == -1)
//         {
//             cout << "Source or destination station not found in the route." << endl;
//             return 0.0; // Return 0 or any other appropriate value
//         }

//         double distance = 0;

//         // Calculate the distance by summing up the distances between stations
//         for (int i = start; i < end; i++)
//         {
//             distance += route[i].distanceFromPrevious;
//         }

//         return distance;
//     }
};


// method for check train timings

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
    cout << "departure time is : "<< train->getSchedule().getDepartureTime();
}

// method for between stations

void betweenStations(Train* train)
{
    for (int i = 0; i < train->getRoute().size(); i++)
    {
        cout <<"station name : " <<train->getRoute()[i].stationName <<"distance from the previous station : "<<train->getRoute()[i].distanceFromPrevious << endl;
    }
    
}

// method for ticket fare enquiry
void fareEnquiry()
{
    Train* train = nullptr;
    string source;
    string destination;
    string date;
    cout << "enter the souce location" << endl;
    cin >> source;
    cout << "enter the destination location " << endl;
    cin >> destination;
    cout << " enter the journey date " << endl;
    cin >> date;
    train = searchTrain(date, source, destination);

    string className;
    cout << "please enter the class name (ac,sleeper,ladies,sitting)" << endl;
    cin >> className;
    // convert the string into lowercase
    locale loc;
    for(auto c : className)
    {
        c = tolower(c,loc);
    }

    for (int i = 0; i < train->getClasses().size(); i++)
    {
        if (train->getClasses()[i].className == className)
        {
            double distance = train->calculateDistance(source, destination);
            double fare = train->getClasses()[i].price * distance;
            cout << "fare is " << fare << endl;
            return;
        }   
    }

}
// save train objects
vector<Train> trainList;

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

// search for train
Train* searchTrain(const string& date, const string& source, const string& destination) {
    for (auto& train : trainList) {
        if (train.getDate() == date && train.getSource() == source && train.getDestination() == destination) {
            return &train;
        }
    }
    return nullptr;
}

void trainDetails(Train* t)
{
    cout << "Train name : "<< t->getTrainName() << endl;
    cout << "Source : "<< t->getSource() << endl;
    cout << "Destination : "<< t->getDestination() << endl;
    cout << "Departure time : "<< t->getSchedule().getDepartureTime() << endl;
    cout << "Arrived time : "<< t->getSchedule().getArrivedTime() << endl;
    cout << "Date : "<< t->getDate() << endl;
    
    // Print available seats for each class
    cout << "Available Seats:" << endl;
    for (int i = 0; i < t->getClasses().size(); i++)
    {
        cout << t->getClasses()[i].className << " : " << t->getClasses()[i].capacity << endl;
    }
    
}


void display()
{
    cout << "1.sign up" << endl;
    cout << "2.log in" << endl;
    cout << "3.exit" << endl;
    cout << "4.ticket booking"<< endl;
}

// for ticket class 

class Ticket
{
    int ticketId;
    int trainId;
    int passengerId;
    int destinationNo;
    int seatNo;
    static int counter;


    public:
        Ticket(int trainId,int passengerId):
        ticketId(counter++),trainId(trainId),passengerId(passengerId){}

        int getTicketId()
        {
            return ticketId;
        }
        int getTrainId()
        {
            return trainId;
        }
        int getPassengerId()
        {
            return passengerId;
        }
        int getDestinationNo()
        {
            return destinationNo;
        }
        int getSeatNumber()
        {
            return seatNo;
        }
};

int Ticket::counter = 1;

// map to store ticket mappings
map<int,pair<int,int>> ticketMappings;

// check seat is available or not
bool isSeatAvailable(int seatNumber, bool array[], int maxSize) {
    if (seatNumber < 1 || seatNumber > maxSize) {
        cout << "Invalid seat number" << endl;
        return false;
    }
    return array[seatNumber - 1];
}

void printTicketDetails(int id,Tree* root)
{
    int trainId = ticketMappings[id].first;
    int passengerId = ticketMappings[id].second;
    Train* train = nullptr;
    passenger* p = nullptr;
    if (ticketMappings.find(id) != ticketMappings.end())
    {


        // find the train corresponding to the train id
        
        for(auto & t : trainList)
        {
            if (t.getTrainId() == trainId)
            {
                train = &t;
                break;
            }
            
        }

         p = getPassenger(root,passengerId);
    }
    // Print ticket details
        if (train != nullptr && p != nullptr)
        {
            cout << "Ticket ID: " << id << endl;
            cout << "Train Name: " << train->getTrainName() << endl;
            cout << "Source: " << train->getSource() << endl;
            cout << "Destination: " << train->getDestination() << endl;
            cout << "Passenger Name: " << p->getName() << endl;
        }else
        {
            cout << "ticket details not found"<< endl;
        }
        
    
}


// int maxSizeAc;
// int maxSizeSleeper;
// int maxSizeSitting;
// int maxSizeLadies;
// // ticket booking
// void ticketBooking(Tree* root)
// {
//     string source;
//     string destination;
//     string date;
//     cout << "please enter the source " << endl;
//     cin >> source;
//     cout << "please enter the destination " << endl;
//     cin >> destination;
//     cout << "please enter the date " << endl;
//     cin >> date;
//     Train* train = searchTrain(date, source, destination);
//     if (train == nullptr) {
//         cout << "Train not found" << endl;
//         return;
//     }
//     trainDetails(train);
//     cout << "Enter class type: (ac,sleeper,sitting,ladies)";
//     string classType;
//     cin >> classType;
//     // convert the string into lowercase
//     locale loc;
//     for(auto c : classType)
//     {
//         c = tolower(c,loc);
//     }
//     // Check if the class type is valid
//     bool classExits = false;

//     for (auto& c : train->getClasses())
//     {
//         if (c.className == classType)
//         {
//             classExits = true;
//             break;
//         }
//     }
//     if (!classExits)
//     {
//         cout << "Invalid class type" << endl;
//         return;
//     }

//     for (int i = 0; i < train->getClasses().size(); i++)
//     {
//         if (train->getClasses()[i].className == "ac")
//         {
//             maxSizeAc = train->getClasses()[i].capacity;
//             break;
//         }
//         if (train->getClasses()[i].className == "sleeper")
//         {
//             maxSizeSleeper = train->getClasses()[i].capacity;
//             break;
//         }
//         if (train->getClasses()[i].className == "sitting")
//         {
//             maxSizeSitting = train->getClasses()[i].capacity;
//             break;
//         }
//         if (train->getClasses()[i].className == "ladies")
//         {
//             maxSizeLadies = train->getClasses()[i].capacity;
//             break;
//         }
//     }
//     bool acArray[maxSizeAc];
//     bool sleeperArray[maxSizeSleeper];
//     bool sittingArray[maxSizeSitting];
//     bool ladiesArray[maxSizeLadies];
//     // initialize all the arrays to false
//     for (int i = 0; i < maxSizeAc; i++)
//     {
//         acArray[i] = true;
//     }
//     for (int i = 0; i < maxSizeLadies; i++)
//     {
//         ladiesArray[i] = true;
//     }
//     for (int i = 0; i < maxSizeSitting; i++)
//     {
//         sittingArray[i] = true;
//     }
//     for (int i = 0; i < maxSizeSleeper; i++)
//     {
//         sleeperArray[i] = true;
//     }

//     bool isAvailable;
//     int seatNumber;
//     cout << "enter the seat number you want to book " << endl;
//     cin >> seatNumber;
//     for (auto& c : train->getClasses())
//     {
//         if (c.className == classType)
//         {
//             if (c.className == "ac")
//             {
//                 isAvailable = isSeatAvailable(seatNumber,acArray,maxSizeAc);
//                 break;
//             }
//             if (c.className == "sleeper")
//             {
//                 isAvailable = isSeatAvailable(seatNumber,sleeperArray,maxSizeSleeper);
//                 break;
//             }
//             if (c.className == "sitting")
//             {
//                 isAvailable = isSeatAvailable(seatNumber,sittingArray,maxSizeSitting);
//                 break;
//             }
//             if (c.className == "ladies")
//             {
//                 isAvailable = isSeatAvailable(seatNumber,ladiesArray,maxSizeLadies);
//                 break;
//             }
//         }
//     }
//     double totalFare = 0.0;
//     bool paid = false;
//     if (isAvailable)
//     {
//         cout << "Ticket is available " << endl;
//         char ch;
//         cout << "do you want to reserve this seat (y/n)" << endl;
//         cin >> ch;
//         if (ch == 'y' || ch == 'Y')
//         {
//             int passengerId;
//             cout << "enter your passenger id " << endl;
//             cin >> passengerId;
//             passenger* p1 = getPassenger(root, passengerId);
            
//             if (p1 != nullptr)
//             {
//                 int distance = train->calculateDistance(source,destination);
//                 double fare = 0.0;
//                 for(auto& c : train->getClasses())
//                 {
//                     if (c.className == classType)
//                     {
//                         fare = c.price * distance;
//                         totalFare += fare;
//                         break;
//                     } 
//                 }
                
//                 cout << "do you want to add another ticket" << endl;
//                 cin >> ch;
//                 if (ch == 'y' || ch == 'Y')
//                 {
//                     ticketBooking(root);
//                 }else
//                 {
//                     cout << "your amount to pay : "<< totalFare<< endl; 
//                     double payment;
//                     cout << "please enter the money"<< endl;
//                     cin >>payment;
//                     if (payment >= totalFare)
//                     {
//                         cout << "payment successful "<< endl;
//                         paid = true;
//                     }else
//                     {
//                         cout << "payment unsuccessful"<<endl;
//                     }
                    
//                 }
//             }
//             else
//             {
//                 cout << "Invalid passenger ID" << endl;
//             }
            
//             if (paid)
//             {
//                 // create ticket object using unique_ptr
//                 std::unique_ptr<Ticket> ticket(new Ticket(train->getTrainId(), p1->getPassengerId()));
//                 ticketMappings[ticket->getTicketId()] = { train->getTrainId(), p1->getPassengerId() };
//                 // update seat availability
//                 for(auto&c : train->getClasses())
//                 {
//                     if (c.className == classType)
//                     {
//                         if (c.className == "AC")
//                         {
//                             acArray[seatNumber - 1] = false;
//                         }
//                         if (c.className == "sleeper")
//                         {
//                             sleeperArray[seatNumber - 1] = false;
//                         }
//                         if (c.className == "sitting")
//                         {
//                             sittingArray[seatNumber - 1] = false;
//                         }
//                         if (c.className == "ladies")
//                         {
//                             ladiesArray[seatNumber - 1] = false;
//                         }
//                         break;
//                     }
                    
//                 }
//                 cout << "your ticket id is " << ticket->getTicketId() << endl;
//                 printTicketDetails(ticket->getTicketId(),root);
//             }else
//             {
//                 cout << "please complete the payment to further continue"<< endl;
//             }
            

//         }
//     }else
//     {
//         cout << "ticket is not available please select some other seat number "<< endl;
//     }
    
// }


// show all the stations
int stationNo = 1;
void allStations()
{
    
    for(auto& t : trainList)
    {
        for(auto& s : t.getRoute())
        {
            cout <<stationNo++"."<<s.stationName << endl;
        }
    }
}

// return the  particular station
stations* returnStation(int no)
{
    stationNo = 1;
    for(auto& t : trainList)
    {
        for(auto& s : t.getRoute())
        {
            if (stationNo++ == no)
            {
                return s;
            }
            
        }
    }
    return nullptr;
}

// search train advance
vector<Train*> searchTRainAdvanced()
{
    vector<Train*> filteredList;
    Train* train = nullptr;
    string source;
    string destination;
    string date;
    cout << "enter the source location number " << endl;
    // cin >> source;
    // cout << "enter the destination location" << endl;
    // cin >> destination;
    // cout << "enter the date" << endl;
    // cin >> date;
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
                // for(auto& d : t.getRoute())
                // {
                //     if (d.stationName == destination)
                //     {
                //         if (t.getDate == date)
                //         {
                //             /* code */
                //         }
                        
                //     }
                    
                // }       
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


// class details of the train

void classDetails(ClassType* c)
{
    cout << "Class Name : " << c->className << endl;
    cout << "Class Capacity : "<< c->capacity << endl;
    cout << "Class price per km : " << c->price << endl;
}

double calculateTicketFare(Train* train)
{
    int sno;
    int dno;
    allStations();
    cout << "enter source location number " << endl;
    cin >> sno;
    allStations();
    cout << "enter destination number " << endl;
    cin >> dno;
    string source;
    string destination;
    source = returnStation(sno)->stationName;
    destination = returnStation(dno)->stationName;
    string className;
    cout << "enter the class name " << endl;
    cin >> className;
    double distance;
    int start = -1;
    int end = -1;
    for (int i = 0; i < train->getRoute().size(); i++)
    {
        if (train->getRoute()[i].stationName == source)
        {
            start = i;            
        }else if (train->getRoute()[i].stationName = destination)
        {
            end = i;
        }
        if (end != -1 && start != -1)
        {
            break;
        }  
    }
    
    for (int i = start+1; i <= end; i++)
    {
        distance += train->getRoute()[i].distanceFromPrevious;
    }
    double fare;
    for(auto& c : train->getClasses())
    {
        if (c.className == className)
        {
            fare = distance * c.price;
        }
        
    }

    return fare;
}

// ticket booking

// void ticketBooking(Tree* root)
// {
//     vector<Train*> availableTrains;
//     availableTrains = searchTRainAdvanced();
//     int trainNo = 1;
//     for(auto& t : availableTrains)
//     {
//         cout <<"Train Number : "<< trainNo++ << endl;
//         trainDetails(t);
//     }
//     cout << "select the train number " << endl;
//     int tno;
//     cin >>tno;
//     Train* train = nullptr;
//     map<Ticket,pair<Train,passenger>>
//     int i = 0;
//     for(auto& t : availableTrains)
//     {
//         if(availableTrains[i++] == tno-1)
//         {
//             train = t;
//         }
//     }

//     double totalAmount = 0.0;
//     int acCapacity;
//     int ladiesCapacity;
//     int sleeperCapacity;
//     int sittingCapacity;

//     for(auto& c : train->getClasses())
//     {
//         if (c.className == "ac")
//         {
//             acCapacity = c.capacity;
//         }
//         if (c.className == "sleeper")
//         {
//             sleeperCapacity = c.capacity;
//         }
//         if (c.className == "ladies")
//         {
//             ladiesCapacity = c.capacity;
//         }
//         if (c.className == "sitting")
//         {
//             sittingCapacity = c.capacity;
//         }
//     }

//     // array to store the tickets
    
//     bool acArray[acCapacity];
//     bool ladiesArray[ladiesCapacity];
//     bool sleeperArray[sleeperCapacity];
//     bool sittingArray[sittingCapacity];

//     fill(acArray,acArray+acCapacity,true);
//     fill(sleeperArray,sleeperArray+sleeperCapacity,true);
//     fill(ladiesArray,ladiesArray+ladiesCapacity,true);
//     fill(sittingArray,sittingArray+sittingCapacity,true);

//     redo:
//     string className;
//     cout << "enter the class type (ac,sleeper,sitting,ladies)" << endl;
//     cin >> className;
//     ClassType* classType = nullptr;
//     bool isClassAvailable = false;
//     for(auto& c : train->getClasses())
//     {
//         if (c.className == className)
//         {
//             classType = c;
//             break;
//         }
//     }
//     classDetails(classType);

//     int seatNo;
//     int selectedCapacity;
//     bool selectedArray[selectedCapacity];
//     bool seatAvailable = false;
//     cout << "Enter the seat number : " << endl;
//     cin >> seatNo;

//     for(auto& c : train->getClasses())
//     {
//         if (c.className == className)
//         {
//             selectedCapacity = c.capacity;
//             selectedArray[selectedCapacity];
//             seatAvailable = isSeatAvailable(seatNo,selectedArray,selectedCapacity);
//         }
//         // if (c.className == className)
//         // {
//         //     selectedCapacity = c.capacity;
//         //     selectedArray[selectedCapacity];
//         //     seatAvailable = isSeatAvailable(seatNo,selectedArray,selectedCapacity);
//         // }
//         // if (c.className == className)
//         // {
//         //     selectedCapacity = c.capacity;
//         //     selectedArray[selectedCapacity];
//         //     seatAvailable = isSeatAvailable(seatNo,selectedArray,selectedCapacity);
//         // }
//         // if (c.className == className)
//         // {
//         //     selectedCapacity = c.capacity;
//         //     selectedArray[selectedCapacity];
//         //     seatAvailable = isSeatAvailable(seatNo,selectedArray,selectedCapacity);
//         // }
        
//     }
//     bool isConfirm;
//     if (seatAvailable)
//     {
//         string confirmation;
//         cout << "please confirm for booking this ticket ( yes || no ) "<< endl;
//         cin >> confirmation;
//         if(confirmation == "yes")
//         {
//             isConfirm = true;
//         }else
//         {
//             cout << "please confirm for further purpose " << endl;
//         }
        

//     }else
//     {
//         cout << "seat is already booked , please select any other seat " << endl;
//     }
//     double amountPayable;
//     passenger* p = nullptr;
//     if (isConfirm)
//     {
//         totalAmount += calculateTicketFare(train);
//         string choice;
//         cout << "do you wan to add another ticket ( yes || no )" << endl;
//         cin >> choice;
//         if (choice == "yes")
//         {
//             goto redo;
//         }else
//         {
//             cout << "your ticket amount " << totalAmount << endl;
//             cout << "please pay this amount " << endl;
//             cin >> amountPayable;
//             if (amountPayable >= totalAmount)
//             {
//                 selectedArray[seatNo-1] = false;
                
//                 int passengerId;
//                 cout << "enter your passenger id " << endl;
//                 cin >> passengerId;
//                 p = getPassenger(root,passengerId);
//                 Ticket* t = new Ticket(train->getTrainId(),p->getPassengerId());
//                 ticketMappings[t->getTicketId()] = {train->getTrainId(),p->getPassengerId()};
//                 cout << "your ticket is confirmed " << endl;
//                 printTicketDetails(t->getTicketId(),root);
//             }else
//             {
//                 cout << "pay the amount for confirm" << endl;
//             }  
//         } 
//     }else
//     {
//         cout << "please confirm for further purpose " << endl;
//     }
    
    
    
    
    





// }

// ticket booking

void ticketBooking(Tree* root)
{
    vector<Train*> availableTrains;
    availableTrains = searchTrainAdvanced();
    int trainNo = 1;
    for(auto& t : availableTrains)
    {
        cout <<"Train Number : "<< trainNo++ << endl;
        trainDetails(t);
    }
    cout << "select the train number " << endl;
    int tno;
    cin >>tno;
    Train* train = nullptr;
    map<Ticket*, pair<Train*, Passenger*>> ticketMappings;
    int i = 0;
    for(auto& t : availableTrains)
    {
        if(availableTrains[i++] == tno-1)
        {
            train = t;
        }
    }

    double totalAmount = 0.0;
    int acCapacity;
    int ladiesCapacity;
    int sleeperCapacity;
    int sittingCapacity;

    for(auto& c : train->getClasses())
    {
        if (c.className == "ac")
        {
            acCapacity = c.capacity;
        }
        if (c.className == "sleeper")
        {
            sleeperCapacity = c.capacity;
        }
        if (c.className == "ladies")
        {
            ladiesCapacity = c.capacity;
        }
        if (c.className == "sitting")
        {
            sittingCapacity = c.capacity;
        }
    }

    // array to store the tickets
    
    bool acArray[acCapacity];
    bool ladiesArray[ladiesCapacity];
    bool sleeperArray[sleeperCapacity];
    bool sittingArray[sittingCapacity];

    fill(acArray, acArray + acCapacity, true);
    fill(sleeperArray, sleeperArray + sleeperCapacity, true);
    fill(ladiesArray, ladiesArray + ladiesCapacity, true);
    fill(sittingArray, sittingArray + sittingCapacity, true);

redo:
    string className;
    cout << "enter the class type (ac,sleeper,sitting,ladies)" << endl;
    cin >> className;
    ClassType* classType = nullptr;
    bool isClassAvailable = false;
    for(auto& c : train->getClasses())
    {
        if (c.className == className)
        {
            classType = &c;
            break;
        }
    }
    classDetails(classType);

    int seatNo;
    int selectedCapacity;
    bool* selectedArray;
    bool seatAvailable = false;
    cout << "Enter the seat number : " << endl;
    cin >> seatNo;

    if (className == "ac")
    {
        selectedCapacity = acCapacity;
        selectedArray = acArray;
        seatAvailable = isSeatAvailable(seatNo, selectedArray, selectedCapacity);
    }
    else if (className == "sleeper")
    {
        selectedCapacity = sleeperCapacity;
        selectedArray = sleeperArray;
        seatAvailable = isSeatAvailable(seatNo, selectedArray, selectedCapacity);
    }
    else if (className == "ladies")
    {
        selectedCapacity = ladiesCapacity;
        selectedArray = ladiesArray;
        seatAvailable = isSeatAvailable(seatNo, selectedArray, selectedCapacity);
    }
    else if (className == "sitting")
    {
        selectedCapacity = sittingCapacity;
        selectedArray = sittingArray;
        seatAvailable = isSeatAvailable(seatNo, selectedArray, selectedCapacity);
    }

    bool isConfirm;
    if (seatAvailable)
    {
        string confirmation;
        cout << "please confirm for booking this ticket ( yes || no ) "<< endl;
        cin >> confirmation;
        if(confirmation == "yes")
        {
            isConfirm = true;
        }
        else
        {
            cout << "please confirm for further purpose " << endl;
        }
    }
    else
    {
        cout << "seat is already booked, please select any other seat " << endl;
    }

    double amountPayable;
    Passenger* p = nullptr;
    if (isConfirm)
    {
        totalAmount += calculateTicketFare(train);
        selectedArray[seatNo-1] = false;

        int passengerId;
        cout << "enter your passenger id " << endl;
        cin >> passengerId;
        p = getPassenger(root, passengerId);
        Ticket* t = new Ticket(train->getTrainId(), p->getPassengerId());
        ticketMappings[t] = make_pair(train, p);

        string choice;
        cout << "do you want to add another ticket ( yes || no )" << endl;
        cin >> choice;
        if (choice == "yes")
        {
            goto redo;
        }
        else
        {
            cout << "your total ticket amount: " << totalAmount << endl;
            cout << "please pay this amount " << endl;
            cin >> amountPayable;
            if (amountPayable >= totalAmount)
            {
                for (auto& [ticket, mapping] : ticketMappings)
                {
                    cout << "Your ticket is confirmed " << endl;
                    printTicketDetails(ticket->getTicketId(), root);
                }
            }
            else
            {
                cout << "Pay the amount to confirm the tickets" << endl;
            }
        }
    }
    else
    {
        cout << "please confirm for further purpose " << endl;
    }
}


// for cancel ticket

void cancelTicket(Tree* root)
{
    int id;
    cout << "please enter your ticket id " << endl;
    cin >> id;
    printTicketDetails(id,root);
    string choice;
    cout << "do you want to cancel the ticket " << endl;
    cin >> choice;
    if(choice == "yes")
    ticketMappings.erase(id);

    cout << "ticket  cancellation successful " << endl;
}

// find the particular ticket 




// if the passenger's destination location is a between station , 
// then we need to mark the seat is free for booking

void releaseSeat(Train* train, Ticket* ticket ,int currentStation)
{
    int passengerDestination = ticket->getDestinationNo();
    if (currentStation > passengerDestination)
    {
        int seatNo = ticket->getSeatNumber();
        bool* selectedArray;
        int selectedCapacity;

        for (int i = 0; i < train->getClasses().size(); i++)
        {
            if (train->getClasses()[i].className == "ac")
            {
                selectedCapacity = train->getClasses()[i].capacity;
                selectedArray = train->getClasses()[i];
            }
            else if (train->getClasses()[i].className == "sleeper")
            {
                selectedCapacity = train->getClasses()[i].capacity;
                selectedArray = train->getClasses()[i];
            }
            else if (train->getClasses()[i].className == "sitting")
            {
                selectedCapacity = train->getClasses()[i].capacity;
                selectedArray = train->getClasses()[i];
            }
            else if (train->getClasses()[i].className == "ladies")
            {
                selectedCapacity = train->getClasses()[i].capacity;
                selectedArray = train->getClasses()[i];
            }
            
            
        }
        
        selectedArray[seatNo-1] = true;
    }
    
}

// add train  using parametarized constructor
void addTrain2()
{
    // for creating train object
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

    // className;
    // capacity;
    // price;

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
    //  add all these values to train
    Train train = new Train(name,classes,s,source,destination,data,route);
    trainList.push_back(train);
    cout << "created train successfully " << endl;
}

// remove train 

void removeTrain(Train t,int id)
{
    Train* elementToDelete = nullptr;
    for (int i = 0; i < trainList.size(); i++)
    {
        if (t.getTrainId() == id)
        {
            elementToDelete = t;
        }
        
    }

    auto it = find(trainList.begin(),trainList.end(),elementToDelete);

    // if the value is found , erase it
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

// return a particular ticket obj

Ticket reutrnTicket(int no)
{
    Ticket* t = nullptr;
    for (auto& [ticket, mapping] : ticketMappings)
    {
        if (ticket->getTicketId() == no)
        {
            t = ticket;
        }
    }
    return *t;   
}

// 

int main() 
{

    Tree* root = nullptr;
    bool loop = true;

    // Create some dummy passengers to insert into the tree
    passenger dummy("dummy",1,'m',"dummy","dummy");
    passenger p1("nithish", 24, 'm', "nithish@123", "yazhini0411@");
    // Assuming you have a root node declared somewhere

    
    // Insert passengers into the tree
    // cout << "into the insert function" << endl;
    root = insert(root, &dummy);
    root = insert(root, &p1);


    // create train
    ClassType acClass("AC", 100, 2.2);
    ClassType sleeperClass("sleeper", 100, 1.2);
    ClassType ladies("ladies", 50, 1.3);
    ClassType secondSitting("sitting", 150, 1);
    ClassType unreserved("ur", 100, 0.8);

    Schedule schedule("5.45pm", "2.30am");

    // Creating vector of ClassType for train classes
    vector<ClassType> classTypes;
    classTypes.push_back(acClass);
    classTypes.push_back(sleeperClass);
    classTypes.push_back(ladies);
    classTypes.push_back(secondSitting);
    classTypes.push_back(unreserved);
    

    // create stations
    vector<stations> route1 = {
        stations("Chennai-Egmore", 0.0),
        stations("vilupuram", 165.0),
        stations("trichy", 164.0),
        stations("pudukottai", 56.0),
        stations("Mandabam-Ramnad", 129.0)
    };

    // creating train 

    
    Train rameshwaramExpress1("Rameswaram Express1", classTypes, schedule, "Chennai-Egmore", "Mandabam-Ramnad", "2024-05-07", route1);


    trainList.push_back(rameshwaramExpress1);
    // trainList.push_back(rameshwaramExpress2);

    // print the trains 

    // for(auto i : trainList)
    // {
    //     cout << i.getTrainId() << endl;
    //     cout << i.getTrainName() << endl;
    //     cout << i.getSource() << endl;
    //     cout << i.getDestination() << endl;
    //     cout << i.getSchedule().getDepartureTime() << endl;
    //     cout << i.getSchedule().getArrivedTime() << endl;
    // }
    printUserDetails(root);

    while (loop)
    {
        display();
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            signUp(root);
            break;
        case 2:
            logIn(root);
            break;
        case 3:
            loop = false;
            break;
        case 4:
            // ticketBooking(root);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    // cout << "into the print function"<< endl;

    // print details
    // cout << "end of functions "<< endl;
    
    return 0;
}

