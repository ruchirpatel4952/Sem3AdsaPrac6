#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node* link;

    friend class LinkedList; // Allows LinkedList to access Node's private members

public:
    Node(int data, Node* link = nullptr); // Constructor
};

#endif // NODE_H
