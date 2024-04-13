#include "LinkedList.h"
#include <iostream>

//Implementing a function to merge
Node* LinkedList::merge(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* result = nullptr;

    if (left->data <= right->data) {
        result = left;
        left = left->next;
    }
    else {
        result = right;
        right = right->next;
    }

    Node* current = result;
    while (left != nullptr && right != nullptr) {
        mergeSortCount++;
        if (left->data <= right->data) {
            current->next = left;
            left = left->next;
        }
        else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    if (left != nullptr) {
        current->next = left;
    }
    else {
        current->next = right;
    }

    return result;
}

//Implementing mergeSort
void LinkedList::mergeSort(Node** headRef) {
    Node* head = *headRef;

    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* slow = head;
    Node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = slow->next;
    slow->next = nullptr;

    mergeSort(&head);
    mergeSort(&second);

    *headRef = merge(head, second);
}