#include"Passenger.hpp"

// get particular passenger details

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
