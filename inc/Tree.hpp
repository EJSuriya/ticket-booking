#ifndef TREE
#define TREE

#include "Main.hpp"

// Function prototype for creating a new node
Tree* createNode(passenger p, Tree* node);

// Function prototype for determining the insertion condition based on passenger details
void condition(Tree*& root, passenger* p);

// Function prototype for inserting a passenger into the tree
Tree* insert(Tree* root, passenger* p);

struct Tree {
    vector<passenger> passengerList[8];
    Tree* left;
    Tree* right;
};



#endif