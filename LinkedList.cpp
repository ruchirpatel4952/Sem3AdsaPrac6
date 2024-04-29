#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    for (int i = len - 1; i >= 0; --i) {
        insertPosition(1, array[i]); // insert at the beginning to preserve order
    }
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->link;
        delete current;
        current = next;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    if (pos <= 1 || head == nullptr) {
        head = new Node(newNum, head);
        return;
    }

    Node* current = head;
    for (int i = 1; current != nullptr && i < pos - 1; ++i) {
        current = current->link;
    }

    if (current != nullptr) {
        current->link = new Node(newNum, current->link);
    }
}

bool LinkedList::deletePosition(int pos) {
    if (pos < 1 || head == nullptr) return false;

    Node* temp = head;
    if (pos == 1) {
        head = head->link;
        delete temp;
        return true;
    }

    Node* prev = nullptr;
    int count = 1;
    while (temp != nullptr && count < pos) {
        prev = temp;
        temp = temp->link;
        count++;
    }

    if (temp == nullptr) return false;

    prev->link = temp->link;
    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    Node* current = head;
    int count = 1;
    while (current != nullptr && count < pos) {
        current = current->link;
        count++;
    }

    if (current == nullptr) return std::numeric_limits<int>::max();
    return current->data;
}

int LinkedList::search(int target) {
    Node* current = head;
    int index = 1;
    while (current != nullptr) {
        if (current->data == target) return index;
        current = current->link;
        index++;
    }
    return -1;
}

void LinkedList::printList() {
    if (head == nullptr) {
        std::cout << "[]" << std::endl;
        return;
    }

    Node* current = head;
    std::cout << '[';
    while (current != nullptr) {
        std::cout << current->data;
        if (current->link != nullptr) {
            std::cout << ' ';
        }
        current = current->link;
    }
    std::cout << ']' << std::endl;
}
