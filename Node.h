#ifndef NODE_H
#define NODE_H

class Node {
    int data;
    Node* link;
    friend class LinkedList; // Allows LinkedList full access to Node's internals

public:
    Node(int data, Node* next = nullptr) : data(data), link(next) {}
};

#endif // NODE_H