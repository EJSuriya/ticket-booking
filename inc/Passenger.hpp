#ifndef PASSENGER
#define PASSENGER

//#include "Main.hpp"
//#include "Tree.hpp"
#include <string>
#include<iostream>
#include <vector>
using namespace std;

class passenger 
{
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
    int getPassengerId()
    {
        return passengerId;
    }
    string getName()
    { 
        return name;
    }
    int getAge()
    { 
        return age;
    }
    char getGender()
    { 
    	return gender;
    }
    string getUsername()
    { 
    	return username;
    }
    string getPassword()
    { 
    	return password;
    }
};

//

struct Tree {
    vector<passenger*> passengerList[8];
    Tree* left;
    Tree* right;
};

static Tree* root=nullptr;

// Function prototype for creating a new node
Tree* createNode(Tree* root, passenger* p);

// Function prototype for determining the insertion condition based on passenger details
Tree* condition(Tree* root, passenger* p);

// Function prototype for inserting a passenger into the tree
Tree* insert(Tree* root, passenger* p);




//



// Function prototype for getting particular passenger details
passenger* getPassenger(Tree* root, int passengerId);

// Function prototype for printing user details
void printUserDetails(Tree* node);



#endif
