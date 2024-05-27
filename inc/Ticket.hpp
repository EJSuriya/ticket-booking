#ifndef TICKET
#define TICKET

#include "Main.hpp"

#include "Tree.hpp" 
#include "Train.hpp"
#include "Passenger.hpp"

// Function prototype for checking seat availability
bool isSeatAvailable(int seatNumber, bool array[], int maxSize);

// Function prototype for printing ticket details
void printTicketDetails(int id, Tree* root);

// Function prototype for calculating ticket fare
double calculateTicketFare(Train* train);

// Function prototype for handling ticket booking
void ticketBooking(Tree* root);

// Function prototype for cancelling a ticket
void cancelTicket(Tree* root);

// Function prototype for releasing seat if passenger's destination is between stations
void releaseSeat(Train* train, Ticket* ticket, int currentStation);

// return a particular ticket obj

Ticket returnTicket(int no);


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
map<Ticket,pair<Train,passenger>> ticketMappings;

map<int,Ticket*> tickets;

queue<int> acWaitingList;
queue<int> sleeperWaitingList;
queue<int> ladiesWaitingList;
queue<int> sittingWaitingList;

#endif
