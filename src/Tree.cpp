#include "Tree.hpp"

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


