#ifndef NODE_H
#define NODE_H

class Node {
    int data;
    Node* link;
    friend class LinkedList; // Allows LinkedList full access to Node's internals

};

#endif // NODE_H
