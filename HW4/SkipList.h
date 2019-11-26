//
//  SkipList.h
//  Skip_List
//
//  Created by Tali Moreshet on 6/5/19.
//  Copyright Â© 2019 Tali Moreshet. All rights reserved.
//
//
//  This is an implementation of a Skip List class, consisting of Linked Lists, which are made up of Nodes.
//  All classes are templated, such that their types may be provided at creation.
//  Nodes contain data (which doubles as key), and pointers to all directions.

#ifndef SkipList_h
#define SkipList_h

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

using namespace std;

template<class T>
class Node {
public:
    Node(const T& data);                            // constructor
    T data;                                         // node data, doubles as key
    Node<T> *next;                                  // node next pointer
    Node<T> *prev;                                  // node previous pointer
    Node<T> *up;                                    // node above pointer
    Node<T> *down;                                  // node below pointer
    void printData();                               // prints data value
    void print();                                   // prints entire node object content
};

template <class T>
class LinkedList {
public:
    LinkedList(T minVal, T maxVal);                 // constructor: accepts -infinity, +infinity values,
                                                    //  creates linked list with two corresponding nodes
    ~LinkedList();                                  // destructor
    Node<T>* search(Node<T>* location, T data);     // search for data starting at location, return node <= data
    Node<T>* insert(Node<T>* location, T data);     // insert node with data at new node to be placed directly 
                                                    //  after node with povided location, return new node
    void printData();                               // prints linked list data
    void print();                                   // prints linked list with all nodes pointers
    Node<T>* head;                                  // head of list
};

template <class T>
class SkipList {
public:
    SkipList(T minVal, T maxVal);                   // constructor: accepts -infinity, +infinity values,
                                                    //  creates skip list with top-level only
    ~SkipList();                                    // destructor
    Node<T>* search(T data);                        // search for data, return node <= data (existing node, or location
                                                    //  where new node should be inserted in the bottom-most list
    bool insert(T data);                            // insert node with data, return true if inserted, false if exists
    void printData();                               // prints skip list data
    void print();                                   // prints skip list with all nodes pointers
    LinkedList<T> *topList;                         // pointer to the top-most list
};


/********************** From here down is the content of the LinkedList.cpp file: ***********************/

/****** Implementation of Node ******/

// Constructor
template<class T>
Node<T>::Node(const T& data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
    this->up = nullptr;
    this->down = nullptr;
}

// Print node's data value
template <class T>
void Node<T>::printData()
{
    cout << data << " ";
}

// Print entire node object content (data value, object's address, and all pointers)
template <class T>
void Node<T>::print()
{
    cout << " * " << data << ": [addr: " << this << " next: " << this->next << " prev: " << this->prev << " up: " << this->up << " down: " << this->down << "]  ";
}


/****** Implementation of linked list ******/

/*** TO BE COMPLETED ***/
/* CONSTRUCTOR */
template <class T>
LinkedList<T>::LinkedList( T minVal, T maxVal){
    Node<T>* h = new Node<T>(minVal); //head
    Node<T>* t = new Node<T>(maxVal); //tail
    t->prev = h;
    this->head = h;
    this->head->next = t;

}

/* DESTRUCTOR */
template <class T>
LinkedList<T>::~LinkedList(){
    Node<T>* temp = this->head; //Temporary Node used to iterate through linked list
    Node<T>* right;

    while(temp.next != nullptr){
        right = temp->next;
        delete temp;
        temp = right;
    }
}

/* SEARCH */
template <class T>
Node<T>* LinkedList<T>::search(Node<T>* location, T data){
    Node<T>* retVal; //return value
    Node<T>* temp = location; //temporary node
    while(temp->next != nullptr){
        if(data == temp->data){ //value found in linked list
            retVal = temp;
            return retVal;
        }else if(data < temp->data){ //value not found in linked list
            retVal = temp->prev;
            return retVal;
        }
        temp = temp->next;
    }

    return retVal; //needed so warning isn't thrown at compliation about possible no return
}

/* INSERT */
template <class T>
Node<T>* LinkedList<T>::insert(Node<T>* location, T data){
    Node<T>* nodeNew = new Node<T>(data); // New node to be inserted
    Node<T>* temp = location->next; //temporary node to store the original value after location
    nodeNew->next = location->next; //set new node next to location next
    nodeNew->prev = location; //set new node previous to location
    location->next = nodeNew; //set location next to new node
    temp->prev = nodeNew; //set original value after location's previous value to new node

    return nodeNew; //return the new node
}

/* PRINT DATA */
template <class T>
void LinkedList<T>::printData(){
    Node<T>* current = head;
    while(current != nullptr){
        current->printData(); //print only the value stored in the node for every node in the linked list
        current = current->next;
    }
}

/* PRINT */
template <class T>
void LinkedList<T>::print(){
    Node<T>* current = head;
    while(current != nullptr){
        current->print(); //print all the members of each node in the linked list
        current = current->next;
    }
}

/****** Skip List Implementation ******/

   /*** TO BE COMPLETED ***/
template <class T>
SkipList<T>::SkipList(T minVal, T maxVal){
    LinkedList<T> *topLevel = new LinkedList<T>(minVal, maxVal);
    this->topList = topLevel;
    this->height = 0;
}

template <class T>
SkipList<T>::~SkipList(){
    
}

template <class T>
Node<T> *SkipList<T>::search(T data)
{
    Node<T> *temp = topList->head;

    while (temp->down != nullptr)
    {
        temp = temp->down;
        while (data > temp->next->data)
        {
            temp = temp->next;
        }
    }
    return temp;
}

template <class T>
bool SkipList<T>::insert(T data)
{
    Node<T> *n = this->search(data);
    Node<T> *temp = n;
    if(n->data == data){
        return false;
    }else{
        Node<T> *newNode = new Node<T>(data);
        int count = 0;

        if((topList->head->up == nullptr) && ((topList->head->down == nullptr))){ //Scenario 1
            this->newRow(data);
        }

        do{ //Scenarios 2 & 3
            if(count == 0){
                newNode->next = n->next;
                newNode->prev = n;
                n->next->prev = newNode;
                n->next = newNode;

                count++;
            }else{
                if(count >= this->height){
                    this->newRow(data);
                }else{
                    while(temp->prev->up == nullptr ){
                        temp = temp->prev;
                    }
                    temp = temp->up;
                    Node<T>* newN = new Node<T>(data);

                    newN->next = temp->next;
                    newN->prev = temp;
                    temp->next->prev = newN;
                    temp->next = newN;
                }

            }
        }while(rand() % 2 == 1);
    }
}

template <class T>
void SkipList<T>::printData()
{
    Node<T> *tempNode = topList->head;

    do
    {
        temp->printData();
        temp = temp->head->down;
    } while (temp->head->down != nullptr)
}

template <class T>
void SkipList<T>::print()
{
    Node<T>* temp1 = this->topList;
    Node<T>* temp2 = this->topList;

    while(temp1 != nullptr){
        
        temp2 = temp1;

        while(temp2 != nullptr){
            cout << "[Address: " << temp2 << "Next: " << temp2->next << "Prev: " << temp2->prev << "Up: " << temp2->up << "Down: " << temp2->down << "Data: " << temp2->data << "] ";
            temp2 = temp2->next;
        }
        cout << endl;
        temp1 = temp1->down;
    }
}

#endif /* SkipList_h */