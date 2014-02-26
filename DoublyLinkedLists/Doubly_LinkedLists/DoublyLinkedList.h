#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include "Node.h"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <ctype.h>
#include <cmath>
#include <climits>

using std::cout;
using std::cin;
using std::exception;
using std::underflow_error;
using std::overflow_error;
using std::cin;
using std::endl;

/*Listing for the Iterator_Node class begins */
class Iterator_Node {
private :
    Node* node_ptr;

public :
    /*One-Argument Constructor */
    Iterator_Node(Node* p) : node_ptr(p) { }

    /*Getter Functions */
    Node* get_node_ptr() {return node_ptr;}

    /*No Setter Functions here !
     *A setter function allows the user
     *to set the node_ptr to an arbitrary
     *value using the member function .
     */


    /*Overloading the indirection operator(*)
     *Non-Const and const verions version
     */
    int& operator* () { }
    const int& operator* () const {
    }

    /*Overloading the arrow(->) operator */
    /*Non-Const and Const Versions */
    Node* operator -> () {    }
    const Node* operator -> () const {    }

    /*Overload the equality operators
     *Non-Const and Const versions
     */
    bool operator == (const Iterator_Node& i) {}
    bool operator != (const Iterator_Node& i) {}

    /*Overload the ++ operators (Postfix/Prefix) */
    Node& operator ++ () {}
    Node& operator ++ (int) {}

    /*Overloading the -- operator(Prefix/Postfix) */
    Node& operator -- () {}
    Node& operator -- (int) {}

    /*Friend Classes and functions */
    friend class Node;
};


#include "DoublyLinkedList.cpp"

#endif
