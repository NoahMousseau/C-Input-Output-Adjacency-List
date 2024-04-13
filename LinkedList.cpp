#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), insertionSortCount(0), bubbleSortCount(0), mergeSortCount(0) {}

char LinkedList::getKey() {
    return key;
}

Node* LinkedList::getHead() {
    return head;
}

int LinkedList::getInsertionSortCount() {
    return insertionSortCount;
}

int LinkedList::getBubbleSortCount() {
    return bubbleSortCount;
}

int LinkedList::getMergeSortCount() {
    return mergeSortCount;
}

void LinkedList::setKey(char ch) {
    key = ch;
}

void LinkedList::insertAtEnd(int intValue, char charValueK1, char charValueK2) {
    Node* newNode = new Node(intValue, charValueK1, charValueK2);
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::display() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << " -> (" << current->dataK2 << ", " << current->data << ")";
        current = current->next;
    }
    std::cout << std::endl;
}
