#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int length) : head(nullptr) {
    for (int i = 0; i < length; i++) {
        insertPosition(i + 1, array[i]); // Inserting at the end of the list
    }
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->link;
        delete current;
        current = next;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    if (pos <= 1 || !head) {
        head = new Node(newNum, head);
        return;
    }
    Node* current = head;
    for (int i = 1; current && i < pos - 1; i++) {
        current = current->link;
    }
    if (current) {
        current->link = new Node(newNum, current->link);
    }
}

bool LinkedList::deletePosition(int pos) {
    if (pos < 1 || !head) return false;
    Node *temp = head, *prev = nullptr;
    int count = 1;
    while (temp && count < pos) {
        prev = temp;
        temp = temp->link;
        count++;
    }
    if (!temp) return false;
    if (prev) {
        prev->link = temp->link;
    } else {
        head = temp->link;
    }
    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    Node* current = head;
    int count = 1;
    while (current && count < pos) {
        current = current->link;
        count++;
    }
    return current ? current->data : std::numeric_limits<int>::max();
}

int LinkedList::search(int target) {
    Node* current = head;
    int pos = 1;
    while (current) {
        if (current->data == target) return pos;
        current = current->link;
        pos++;
    }
    return -1;
}

void LinkedList::printList() {
    if (!head) {
        std::cout << "[]" << std::endl;
        return;
    }
    Node* current = head;
    std::cout << '[';
    while (current) {
        std::cout << current->data;
        if (current->link) std::cout << ' ';
        current = current->link;
    }
    std::cout << ']' << std::endl;
}
