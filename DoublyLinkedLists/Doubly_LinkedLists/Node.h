#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <climits>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>

#include "DoublyLinkedList.h"

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::exception;
using std::underflow_error;
using std::overflow_error;

/*Listing for the class Node begins
 *Slight modifications to the node classs
 *defined in the singly linked list programs
 */
class Node {
private :
    int data;
    Node* next;
    Node* prev;

public :
    /*Constructors */
    Node():next(NULL),prev(NULL) {}

    /*Getter Functions */
    int get_data() {return data;}
    Node* get_next() const {return next;}
    Node* get_prev() const {return prev;}

    /*Setter Functions */
    void set_data(int d) {data = d;}
    void set_next(Node* n) {next = n;}
    void set_prev(Node* p) {prev = p;}

    /*Friend Classes and Functions */
    friend class Iterator_Node;
};

#endif
