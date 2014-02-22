/*Program to implement Linked Lists
 *Contains the Listing of the Header Files
 */

 #ifndef __LIST_H__
 #define __LIST_H__

 #include <iostream>
 #include <cstdlib>
 #include <climits>
 #include <stdexcept>
 #include <string>
 #include <algorithm>

 using std::ostream;
 using std::istream;
 using std::exception;
 using std::overflow_error;
 using std::underflow_error;
 using std::exception;

 /*Listing for class node begins */
 class node {
 private :
    int data;                   //Holds the data part of the node
    node* next;                 //Holds the reference for the next node

public :
    /*Constructors */
    node() : data(0),next(NULL) { }         //Default Constructor
    node(int d) : data(d),next(NULL) { }    //One-Argument Constructor

    /*Getter Functions */
    int get_data() {return data;}          //Returns the data in the node
    node* get_next() {return next;}        //Returns the next pointer in the list

    /*Setter Functions */
    void set_data(int d) {data = d;}        //Sets the data to some integer
    void set_next(node* n) {next = n;}       //Sets the next node in the list

    /*Function to overload the output operator */

    friend class List;
 };

/*Listing for class list begins */
class List {
private :
    node* head;                     //Node for containing the head
    node* tail;                     //Node for containing the tail
    size_t _size;                   //variable to hold the size of the list

public :
    /*Constructors */
    List() : head(NULL),tail(NULL),_size(0) { }     //Default Constructor

    /*Function to check if the list is empty */
    bool empty() {
    return ((head == NULL ) && (tail == NULL));
    }

    /*Function to return the size of the list */
    size_t size() {
    return _size;
    }

   /*Function to insert an element to the front of the list
    *push_front()
    */
    void push_front(int d);

   /*Function to insert an element at the end of the list
     *push_back()
    */
    void push_back(const int& d);

   /*Function to remove an element from the front of the list
    *pop_front()
    */
    void pop_front();

   /*Function to remove an element from the back of the list
    *pop_back()
    */
    void pop_back();

    /*Function to clear the list
    *Pop elements till the list gets empty
    */
    void clear();

    /*Function to sort the elements of the linked list */
    void sort();

    /*Function that reverses the content of the linked list */
    void reverse();

    /*Function to delete an element at a given position of the linked list */
    void node_delete(int p);

    /*Function to swap the contents of two linked lists */
    void swap(List& lst);

    /*Function to print the contents of the list from head to tail */
    void print();
};

#include "List.cpp"

#endif
