#include "LinkedList.h"
#include <iostream>

//Implementing bubbleSort
void LinkedList::bubbleSort() {
    if (head == nullptr || head->next == nullptr) {
        // If the list is empty or has only one element, it is already sorted
        return;
    }

    bool swapped;
    Node* current;
    Node* lastSorted = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                // Swap nodes if they are in the wrong order
                int tempData = current->data;
                char tempDataK1 = current->dataK1;
                char tempDataK2 = current->dataK2;

                current->data = current->next->data;
                current->dataK1 = current->next->dataK1;
                current->dataK2 = current->next->dataK2;

                current->next->data = tempData;
                current->next->dataK1 = tempDataK1;
                current->next->dataK2 = tempDataK2;

                swapped = true;

                // Increment bubbleSortCount
                bubbleSortCount++;
            }
            current = current->next;
        }
        lastSorted = current;
    } while (swapped);
}