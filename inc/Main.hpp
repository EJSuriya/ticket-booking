#ifndef MAIN
#define MAIN
// header

#include "Train.hpp"
#include "Passenger.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

passenger* current_user=nullptr;

Train* current_train=nullptr;

void fill_array();
// Function prototype for signing up a new passenger
Tree* signUp(Tree* root);
bool log_in_result=false;
// Function prototype for displaying menu options
void display();
void trainTimings();
// Function prototype for logging in a passenger
passenger* logIn(Tree* root);
void user_history(passenger * p);
// Function prototype for logging out a passenger
void logOut(Tree* root);
void seat_details();
//vector<Train> searchTRainAdvanced();
void ticketBooking(Tree *root);
void cancelTicket(Tree *root);
void fareEnquiry();
void printTicketDetails(int id,Tree* root);
void ticketBooking(Tree *root);
void calculateTicketFare();

void specific_seat_details();

void seat_status();
#endif 
