#include "Node.cpp"
#include <iostream>

//LinkedList class to encapsulate the linked list operations
class LinkedList {
private:
    Node* head; //Pointer to the first node in the list
    char key;

public:
    //Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    //Getter for key
    char getKey() {
        return key;
    }

    //Getter for head
    Node* getHead() {
        return head;
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
                if (current->data < current->next->data) {
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
                }
                current = current->next;
            }
            lastSorted = current;
        } while (swapped);
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
