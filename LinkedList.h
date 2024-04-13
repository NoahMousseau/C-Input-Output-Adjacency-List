#pragma once
#include "Node.cpp"

class Node;

class LinkedList {
    private:
        Node* head;
        char key;
        int insertionSortCount;
        int bubbleSortCount;
        int mergeSortCount;

    public:
        LinkedList();
        char getKey();
        Node* getHead();
        int getInsertionSortCount();
        int getBubbleSortCount();
        int getMergeSortCount();
        void setKey(char ch);
        void insertionSort();
        void bubbleSort();
        Node* merge(Node* left, Node* right);
        void mergeSort(Node** headRef);
        void insertAtEnd(int intValue, char charValueK1, char charValueK2);
        void display() const;
};
