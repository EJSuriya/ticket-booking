#include "Ticket.hpp"

bool isSeatAvailable(int seatNumber, bool array[], int maxSize) 
{
    if (seatNumber < 1 || seatNumber > maxSize) 
    {
        cout << "Invalid seat number" << endl;
        return false;
    }
    return array[seatNumber - 1]
}

void printTicketDetails(int id,Tree* root)
{
    int trainId = ticketMappings[id].first;
    int passengerId = ticketMappings[id].second;
    Train* train = nullptr
    passenger* p = nullptr;
    if (ticketMappings.find(id) != ticketMappings.end())
    {
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

    if (train != nullptr && p != nullptr)
    {
        cout << "Ticket ID: " << id << endl;
        cout << "Train Name: " << train->getTrainName() << endl;
        cout << "Source: " << train->getSource() << endl
        cout << "Destination: " << train->getDestination() << endl;
        cout << "Passenger Name: " << p->getName() << endl;
    }else
    {
        cout << "ticket details not found"<< endl
    }
}

double calculateTicketFare(Train* train)
{
    int sno;
    int dno;
    allStations();
    cout << "enter source location number " << endl;
    cin >> sno
    allStations();
    cout << "enter destination number " << endl;
    cin >> dno;
    string source;
    string destination;
    source = returnStation(sno)->stationName;
    destination = returnStation(dno)->stationName
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
    
    for (int i = start+1; i <= end i++)
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

int acCapacity;
int ladiesCapacity
int sleeperCapacity;
int sittingCapacity;

vector<vector<bool>> ticketBooking(Tree* root)
{
    vector<vector<bool>> ticketArray;
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
    int i = 0
    for(auto& t : availableTrains)
    {
        if(availableTrains[i++] == tno-1)
        {
            train = t;
        }
    }

    double totalAmount = 0.0;
    for(auto& c : train->getClasses())
    {
        if (c.className == "ac")
        {
            acCapacity = c.capacity;
        }
        if (c.className == "sleeper")
        {
            sleeperCapacity = c.capacity
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

    bool acArray[acCapacity];
    bool ladiesArray[ladiesCapacity];
    bool sleeperArray[sleeperCapacity]
    bool sittingArray[sittingCapacity];

    fill(acArray, acArray + acCapacity, true);
    fill(sleeperArray, sleeperArray + sleeperCapacity, true)
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
    int selectedCapacity
    bool* selectedArray;
    bool seatAvailable = false;
    cout << "Enter the seat number : " << endl;
    cin >> seatNo;

    if (className == "ac")
    {
        selectedCapacity = acCapacity;
        selectedArray = acArray;
        seatAvailable = isSeatAvailable(seatNo, selectedArray, selectedCapacity)
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
        selectedArray = ladiesArray
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
        totalAmount += calculateTicketFare(train)
        selectedArray[seatNo-1] = false;

        int passengerId;
        cout << "enter your passenger id " << endl;
        cin >> passengerId;
        p = getPassenger(root, passengerId);
        Ticket* t = new Ticket(train->getTrainId(), p->getPassengerId());
        for(auto& c : train->getClasses())
        {
            if (c.className == "ac")
            {
                acCapacity--;
            }else if (c.className == "sleeper")
            {
                sleeperCapacity--;
            }
            else if (c.className == "ladies")
            {
                ladiesCapacity--;
            }
            else if (c.className == "sitting")
            {
                sittingCapacity--;
                break;
            }

        }
    }
}