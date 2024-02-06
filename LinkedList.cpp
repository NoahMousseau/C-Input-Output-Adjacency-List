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
