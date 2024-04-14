#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>

//Including necessary files
#include "LinkedList.h"

using namespace std;

int main() {
    //userChoice determines which algorithm is used
    //1 displays lists
    //2 uses insertionSort
    //3 uses bubbleSort
    //4 uses mergeSort
    int userChoice = 3;

    //We use bubbleSort for our chosen algorithm

    if (userChoice == 1) {
        cout << "Primary operation of inserting nodes into corresponding Linked Lists:" << endl;
        //Read input from the file
        ifstream inputFile("input.txt");

        //Created required array to hold linked lists
        vector<LinkedList> Vertices;

        //Get first line of file and create linked lists
        string firstLine;
        getline(inputFile, firstLine);

        //Create linked lists for each character in the first line of the file
        for (char ch : firstLine) {
            if (ch != ' ') {
                LinkedList newList;
                newList.setKey(ch);
                Vertices.push_back(newList);
            }
        }

        //Set variables for information from text file
        char source;
        char destination;
        int weight;

        //Place file contents into corresponding linked lists
        string line;
        while (getline(inputFile, line)) {
            int commaCount = 0;
            int spaceCount = 0;
            string strSave;
            for (char ch : line) {
                if (ch != ',' && ch != ' ') {
                    //Compare to find which token is being looked at
                    if (commaCount == 0 && spaceCount == 0) {
                        source = ch;
                    }
                    else if (commaCount == 1 && spaceCount == 1) {
                        destination = ch;
                    }
                    //Combine last 2 chars of each line to form an int
                    else if (commaCount == 2 && spaceCount == 2) {
                        strSave = strSave + ch;
                        //Convert string to into to save to weight
                        weight = stoi(strSave);
                    }
                }
                //Determine if ch being looked at is ',' or ' '
                else if (ch == ',') {
                    commaCount++;
                }
                else if (ch == ' ') {
                    spaceCount++;
                }
            }
            //Iterate through linked lists and place weight-source-destination nodes accordingly
            for (LinkedList& ll : Vertices) {
                if (ll.getKey() == source) {
                    ll.insertAtEnd(weight, source, destination);
                }
            }
        }

        //Display linked lists
        int size = Vertices.size();
        for (int i = 0; i < size; i++) {
            cout << Vertices[i].getKey();
            Vertices[i].display();
        }

        //Close the file
        inputFile.close();
    }
    else if (userChoice == 2) {
        cout << "Using insertionSort to sort Linked Lists:" << endl;
        //Read input from the file
        ifstream inputFile("input.txt");

        //Created required array to hold linked lists
        vector<LinkedList> Vertices;

        //Get first line of file and create linked lists
        string firstLine;
        getline(inputFile, firstLine);

        //Create linked lists for each character in the first line of the file
        for (char ch : firstLine) {
            if (ch != ' ') {
                LinkedList newList;
                newList.setKey(ch);
                Vertices.push_back(newList);
            }
        }

        //Set variables for information from text file
        char source;
        char destination;
        int weight;

        //Place file contents into corresponding linked lists
        string line;
        while (getline(inputFile, line)) {
            int commaCount = 0;
            int spaceCount = 0;
            string strSave;
            for (char ch : line) {
                if (ch != ',' && ch != ' ') {
                    //Compare to find which token is being looked at
                    if (commaCount == 0 && spaceCount == 0) {
                        source = ch;
                    }
                    else if (commaCount == 1 && spaceCount == 1) {
                        destination = ch;
                    }
                    //Combine last 2 chars of each line to form an int
                    else if (commaCount == 2 && spaceCount == 2) {
                        strSave = strSave + ch;
                        //Convert string to into to save to weight
                        weight = stoi(strSave);
                    }
                }
                //Determine if ch being looked at is ',' or ' '
                else if (ch == ',') {
                    commaCount++;
                }
                else if (ch == ' ') {
                    spaceCount++;
                }
            }
            //Iterate through linked lists and place weight-source-destination nodes accordingly
            for (LinkedList& ll : Vertices) {
                if (ll.getKey() == source) {
                    ll.insertAtEnd(weight, source, destination);
                }
            }
        }

        //Sort linked lists
        for (LinkedList& ll : Vertices) {
            Node* head = ll.getHead();
            ll.insertionSort(); //Call insertionSort
        }

        //Display linked lists
        int size = Vertices.size();
        for (int i = 0; i < size; i++) {
            cout << Vertices[i].getKey();
            Vertices[i].display();
            //Display insertionSortCount
            cout << "Insertion sort operation count: " << Vertices[i].getInsertionSortCount() << endl;
        }

        //Close the file
        inputFile.close();
    } else if (userChoice == 3) {
        cout << "Using bubbleSort to sort Linked Lists:" << endl;
        //Read input from the file
        ifstream inputFile("input.txt");

        //Created required array to hold linked lists
        vector<LinkedList> Vertices;

        //Get first line of file and create linked lists
        string firstLine;
        getline(inputFile, firstLine);

        //Create linked lists for each character in the first line of the file
        for (char ch : firstLine) {
            if (ch != ' ') {
                LinkedList newList;
                newList.setKey(ch);
                Vertices.push_back(newList);
            }
        }

        //Set variables for information from text file
        char source;
        char destination;
        int weight;

        //Place file contents into corresponding linked lists
        string line;
        while (getline(inputFile, line)) {
            int commaCount = 0;
            int spaceCount = 0;
            string strSave;
            for (char ch : line) {
                if (ch != ',' && ch != ' ') {
                    //Compare to find which token is being looked at
                    if (commaCount == 0 && spaceCount == 0) {
                        source = ch;
                    }
                    else if (commaCount == 1 && spaceCount == 1) {
                        destination = ch;
                    }
                    //Combine last 2 chars of each line to form an int
                    else if (commaCount == 2 && spaceCount == 2) {
                        strSave = strSave + ch;
                        //Convert string to into to save to weight
                        weight = stoi(strSave);
                    }
                }
                //Determine if ch being looked at is ',' or ' '
                else if (ch == ',') {
                    commaCount++;
                }
                else if (ch == ' ') {
                    spaceCount++;
                }
            }
            //Iterate through linked lists and place weight-source-destination nodes accordingly
            for (LinkedList& ll : Vertices) {
                if (ll.getKey() == source) {
                    ll.insertAtEnd(weight, source, destination);
                }
            }
        }

        //Sort linked lists
        for (LinkedList& ll : Vertices) {
            Node* head = ll.getHead();
            ll.bubbleSort(); //Call bubbleSort
        }

        //Display linked lists
        int size = Vertices.size();
        for (int i = 0; i < size; i++) {
            cout << Vertices[i].getKey();
            Vertices[i].display();
            //Display bubbleSortCount
            cout << "Bubble sort operation count: " << Vertices[i].getBubbleSortCount() << endl;
        }

        //Close the file
        inputFile.close();
    }
    else if (userChoice == 4) {
    cout << "Using mergesort to sort Linked Lists:" << endl;
        //Mergesort Implementation
        //Read input from the file
        ifstream inputFile("input.txt");

        //Created required array to hold linked lists
        vector<LinkedList> Vertices;

        //Get first line of file and create linked lists
        string firstLine;
        getline(inputFile, firstLine);

        //Create linked lists for each character in the first line of the file
        for (char ch : firstLine) {
            if (ch != ' ') {
                LinkedList newList;
                newList.setKey(ch);
                Vertices.push_back(newList);
            }
        }

        //Set variables for information from text file
        char source;
        char destination;
        int weight;

        //Place file contents into corresponding linked lists
        string line;
        while (getline(inputFile, line)) {
            int commaCount = 0;
            int spaceCount = 0;
            string strSave;
            for (char ch : line) {
                if (ch != ',' && ch != ' ') {
                    //Compare to find which token is being looked at
                    if (commaCount == 0 && spaceCount == 0) {
                        source = ch;
                    }
                    else if (commaCount == 1 && spaceCount == 1) {
                        destination = ch;
                    }
                    //Combine last 2 chars of each line to form an int
                    else if (commaCount == 2 && spaceCount == 2) {
                        strSave = strSave + ch;
                        //Convert string to into to save to weight
                        weight = stoi(strSave);
                    }
                }
                //Determine if ch being looked at is ',' or ' '
                else if (ch == ',') {
                    commaCount++;
                }
                else if (ch == ' ') {
                    spaceCount++;
                }
            }
            //Iterate through linked lists and place weight-source-destination nodes accordingly
            for (LinkedList& ll : Vertices) {
                if (ll.getKey() == source) {
                    ll.insertAtEnd(weight, source, destination);
                }
            }
        }

        //Sort linked lists
        for (LinkedList& ll : Vertices) {
            Node* head = ll.getHead();
            ll.mergeSort(&head); //Call mergeSort with address of head pointer
        }

        //Display linked lists
        int size = Vertices.size();
        for (int i = 0; i < size; i++) {
            cout << Vertices[i].getKey();
            Vertices[i].display();
            //Display mergeSortCount
            cout << "Merge sort operation count: " << Vertices[i].getMergeSortCount() << endl;
        }

        //Close the file
        inputFile.close();
    }
}
