#include "LinkedList.h"
#include <iostream>

//Implementing insertionSort
void LinkedList::insertionSort() {
    Node* sorted = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        Node* newNode = new Node(current->data, current->dataK1, current->dataK2);

        // Find the correct position for the new node in the sorted list
        if (sorted == nullptr || sorted->data >= newNode->data) {
            newNode->next = sorted;
            sorted = newNode;
        }
        else {
            Node* currentSorted = sorted;
            while (currentSorted->next != nullptr && currentSorted->next->data < newNode->data) {
                currentSorted = currentSorted->next;
            }
            newNode->next = currentSorted->next;
            currentSorted->next = newNode;
            // Increment insertionSortCount
            insertionSortCount++;
        }
        current = next;
    }
    head = sorted;
}