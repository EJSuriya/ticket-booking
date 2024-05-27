#ifndef TICKET
#define TICKET

#include "Passenger.hpp"
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Train;

Train* train = nullptr;

class Ticket
{
	private:
    int ticketId;
    int trainId;
    int passengerId;
    int sourceNo;
    int destinationNo;
    int seatNo;
    string className;
    string date;
    static int counter;


    public:
        Ticket(int trainId,int passengerId,int sno, int dno,int seatNo,string className,string date):
        ticketId(counter++),trainId(trainId),passengerId(passengerId),sourceNo(sno),destinationNo(dno),seatNo(seatNo),className(className),date(date){}

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
        int getSourceNo()
        {
            return sourceNo;
        }
        int getDestinationNo()
        {
            return destinationNo;
        }
        string getClassName()
        {
            return className;
        }
        int getSeatNumber()
        {
            return seatNo;
        }
        string getDate()
        {
            return date;
        }
};

void user_history(passenger * p);

// Function prototype for checking seat availability
bool isSeatAvailable(int seatNumber, bool array[], int maxSize);

// Function prototype for printing ticket details
void printTicketDetails(int id, Tree* root);



// Function prototype for handling ticket booking
void ticketBooking(Tree* root);

// Function prototype for cancelling a ticket
void cancelTicket(Tree* root);

// Function prototype for releasing seat if passenger's destination is between stations
//void releaseSeat(Train* train, Ticket* ticket, int currentStation);

double calculateTicketFare(Train* train);

double calculateJourneyFare(Train* train,int source,int destination,string className);
// return a particular ticket obj

Ticket returnTicket(int no);

vector<Train*> availableTrains;

int Ticket::counter = 1;

// map to store ticket mappings
map<Ticket*,pair<Train*,passenger*>> ticketMappings;

map<int,Ticket*> tickets;

queue<int> acWaitingList;
queue<int> sleeperWaitingList;
queue<int> ladiesWaitingList;
queue<int> sittingWaitingList;
/*
static bool acArray[100];
static bool ladiesArray[100];
static bool sleeperArray[100];
static bool sittingArray[100];

*/

void change_status(int num,int seat);
#endif
