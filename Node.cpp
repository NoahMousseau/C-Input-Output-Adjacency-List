//Node structure to represent each element in the linked list
struct Node {
    char dataK1;
    char dataK2;
    int data;
    Node* next;

    //Constructor to initialize the node with data and a null next pointer
    Node(int intValue, char charValueK1, char charValueK2) : data(intValue), dataK1(charValueK1), dataK2(charValueK2), next(nullptr) {}
};