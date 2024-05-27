#ifndef PASSENGER
#define PASSENGER

#include "Main.hpp"
#include "Tree.hpp"

// Function prototype for getting particular passenger details
passenger* getPassenger(Tree* root, int passengerId);

// Function prototype for printing user details
void printUserDetails(Tree* node);


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

int passenger::counter = 0; // Initialize static member variable

#endif
