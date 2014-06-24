/* Class Node to define a Node in the list */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>
#include <cassert>

/* Declaration of template classes */
template <class type> class Iterator_Node;
/* Listing for template class Node */
template <class type>
class Node {
private:
    type data;              //Data part of the node
    Node<type> *next;             /* Pointer to the next node in the list
                             * Self-Referential structures */
    Node<type> *prev;             /* Pointer to the previous node in the list */

public:
    /* Constructors */
    Node() :
        data(), next(NULL),prev(NULL) {
        /* Default Constructor */
    }
    Node(type d) :
        data(d),next(NULL),prev(NULL) {
        /* One Argument Constructor */
    }

    /* Getter Functions */
    type        get_data()     const { return data; }
    Node<type>* get_next_ptr() const { return next; }
    Node<type>* get_prev_ptr() const { return prev; }

    /* Setter Functions */
    void set_data    (type d)           { data = d; return; }
    void set_next_ptr(Node<type> *node) { next = node; return; }
    void set_prev_ptr(Node<type> *node) { prev = node; return; }

    /* Friend classes and functions */
    friend class Iterator_Node<type>;
};

#endif // NODE_H
