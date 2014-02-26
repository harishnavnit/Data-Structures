#ifndef __LIST_DOUBLE_PTR_INT__
#define __LIST_DOUBLE_PTR_INT__

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip.h>
#include <climits>

#include "Node.h"
#include "DoublyLinkedList.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::exception;
using std::underflow_error;
using std::overflow_error;


/*Listing for the doubly linked list class begins */
class List_double_ptr_Int {
public :
    /*User-defined declarations */
    typedef size_t size_type;
    typedef Iterator_Node iterator;
    typedef const Iterator_Node const_iterator;

private :
    Node sentinel_head;     /*Dummy node at the start of the list */
    Node sentinel_tail;     /*Dummy node at the end of the list */
    size_type list_size;    //Holds the no. of elements in the list

public :
    /*Constructors */
    explicit List_double_ptr_Int():sentinel_head(NULL),sentinel_tail(NULL),list_size(0) {}

    /*Destructors */
    virtual ~List_double_ptr_Int() {clear();}

    /*Returns the iterator the first element of the list */
    //Non-Const version
    iterator begin() {
     return iterator(sentinel_head.get_next());
    }
    //Const version
    const_iterator begin() const {
     return const_iterator(sentinel_head.get_next());
    }

    /*Returns a reference to the next element after the end in the list container*/
    //Non-Const version
    iterator end() {
     return iterator(sentinel_tail.get_next());
    }
    //Const version
    const_iterator end() const {
     return const_iterator(sentinel_tail.get_next());
    }

    /*Function to push an element to the end of the list */
    void push_back(const int& d);

    /*Function to push an element to the front of the list */
    void push_front(const int& d);

    /*Function to remove an element from the end of the list */
    void pop_back();

    /*Function to remove an element from the front of the list */
    void pop_front();

    /*Function to print the list from head to tail */
    void print();

    /*Function to print the list from tail to head */
    void reverse_print();
};

#include "ListDoublePtr.cpp"

#endif
