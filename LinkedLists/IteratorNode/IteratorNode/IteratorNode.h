#ifndef __ITERATOR_NODE_H__
#define __ITERATOR_NODE_H__

#include "List.h"

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <iomanip>

using std::cout;
using std::cin;
using std::ostream;
using std::ifstream;
using std::endl;

class Iterator_Node {
private :
    node* node_ptr;             //Self-Referential Structures

public :
    /*Constructors */
    Iterator_Node(Node* p):node_ptr(p) { }              //One-Argument Constructor

    /*Getter Functions */
    node* get_node_ptr() {return node_ptr;}

    /*Overload the indirection operator */
    /*Non-Const Version */
    int& operator* () {
        assert(node_ptr != NULL);                       //Checks if the node points to NULL
        return node_ptr->data;                          //Returns the data part of the node
    }
    /*Const Version of the overloading function */
    const int& operator* () const {
        assert(node_ptr != NULL);
        return node_ptr->data;
    }

    /*Overload the arrow(->) operator */
    /*Non-Const version */
    node* operator-> () {
        assert(node_ptr != NULL);
        return node_ptr;
    }
    /*Const Version of the above operator overloading function */
    const node* operator-> () const {
        assert(node_ptr!=NULL);
        return node_ptr;
    }

    /*Overloading the equality operator(==) */
    bool operator==(const Iterator_Node& i) {
        return (this->node_ptr==i.node_ptr);
    }
    bool operator!=(const Iterator_Node& i) {
        return (this->node_ptr!=i.node_ptr;)
    }

    /*Overload the ++ operator (Prefix/Postfix versions) */
    node& operator ++ () {
        node_ptr=node_ptr->get_next();
        return (*node_ptr);
    }
    node& operator ++ (int) {
        node* temp_ptr = this->node_ptr;
        node_ptr = node_ptr->get_next();
        return (*temp_ptr)
    }
};
