#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <limits>

class LinkedList {
private:
    Node* head;

public:
    LinkedList(); // Default constructor
    LinkedList(int* array, int len); // Constructor from array
    ~LinkedList(); // Destructor

    void insertPosition(int pos, int newNum);
    bool deletePosition(int pos);
    int get(int pos);
    int search(int target);
    void printList();
};

#endif // LINKEDLIST_H
