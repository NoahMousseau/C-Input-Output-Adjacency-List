#include "Node.cpp"
#include <iostream>

//LinkedList class to encapsulate the linked list operations
class LinkedList {
private:
    Node* head; //Pointer to the first node in the list
    char key;
    //Counters for operations
    int insertionSortCount; 
    int bubbleSortCount;
    int mergeSortCount;

public:
    //Constructor to initialize an empty linked list
    LinkedList() : head(nullptr), insertionSortCount(0), bubbleSortCount(0), mergeSortCount(0) {}

    //Getter for key
    char getKey() {
        return key;
    }

    //Getter for head
    Node* getHead() {
        return head;
    }

    //Getter for insertionSortCount
    int getInsertionSortCount() {
        return insertionSortCount;
    }

    //Getter for bubbleSortCount
    int getBubbleSortCount() {
        return bubbleSortCount;
    }

    //Getter for mergeSortCount
    int getMergeSortCount() {
        return mergeSortCount;
    }

    //Setter for key
    void setKey(char ch) {
        key = ch;
    }

    //Function to use insertion sort with linked lists
    void insertionSort() {
        Node* sorted = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;
            Node* newNode = new Node(current->data, current->dataK1, current->dataK2);

            //Find the correct position for the new node in the sorted list
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
                //Increment insertionSortCount
                insertionSortCount++;
            }
            current = next;
        }
        head = sorted;
    }

    //Function to use bubble sort with linked lists in descending order
    void bubbleSort() {
        if (head == nullptr || head->next == nullptr) {
            //If the list is empty or has only one element, it is already sorted
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
                    //Swap nodes if they are in the wrong order
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

                    //Increment bubbleSortCount
                    bubbleSortCount++;
                }
                current = current->next;
            }
            lastSorted = current;
        } while (swapped);
    }

    //Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        //Base case: If one of the lists is empty, return the other list
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        //Create a new node to store the head of the merged list
        Node* result = nullptr;

        //Compare the head nodes of both lists and choose the smaller one as the head of the merged list
        if (left->data <= right->data) {
            result = left;
            left = left->next;
        }
        else {
            result = right;
            right = right->next;
        }

        //Recursively merge the remaining elements of both lists and append them to the result list
        Node* current = result;
        while (left != nullptr && right != nullptr) {
            //Increment mergeSortCount
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

        //Append the remaining elements of the non-empty list to the result list
        if (left != nullptr) {
            current->next = left;
        }
        else {
            current->next = right;
        }

        return result;
    }


    //Function to sort the linked list using merge sort (ascending order)
    void mergeSort(Node** headRef) {
        Node* head = *headRef;

        //Base case: If the list is empty or has only one element, it is already sorted
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        //Find the middle node of the list
        Node* slow = head;
        Node* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //Split the list into two halves
        Node* second = slow->next;
        slow->next = nullptr;  //Terminate the first half

        //Recursively sort the first and second halves
        mergeSort(&head);
        mergeSort(&second);

        //Merge the sorted halves back together
        *headRef = merge(head, second);
    }


    //Function to insert a new node at the end of the list
    void insertAtEnd(int intValue, char charValueK1, char charValueK2) {
        Node* newNode = new Node(intValue, charValueK1, charValueK2);
        newNode->next = nullptr; //Set the next pointer of the new node to nullptr

        if (head == nullptr) {
            //If the list is empty, make the new node the head
            head = newNode;
        }
        else {
            //Traverse the list to find the last node
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            //Insert the new node after the last node
            current->next = newNode;
        }
    }

    //Function to display the elements of the linked list
    void display() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << " -> (" << current->dataK2 << ", " << current->data << ")";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
