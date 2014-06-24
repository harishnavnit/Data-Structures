/* Class Iterator_Node to represent a
 * (safe) pointer to a node in the list
 */

#ifndef ITERATOR_NODE_H
#define ITERATOR_NODE_H

#include "Node.h"
#include <cstdlib>

using std::cout;
using std::endl;

/*
 * An iterator to a node(in the list)
 * of any typed
 *
 * Listing for the Iterator_Node class
 */
template <class type>
class Iterator_Node{
private:
    Node<type> *node_ptr;

public:
    /* Constructors */
    Iterator_Node(Node<type> *node) :
        node_ptr(node) {
        /* One Arguement Constructor */
    }

    /* Getter Functions */
    Node<type>* get_node_ptr() { return node_ptr; }


    /** Don't allow the user of the class to set the node_ptr
     * to an arbitrary value using a public member function.
     * So, no set_node_ptr(Node<type> *)
     */
    /* Setter Functions */
    //void set_node_ptr(Node<type> *node) { node_ptr = node; return; }


    /* Overload the indirection operator */
    type& operator*() {
        assert(this->node_ptr != NULL);         //Check if the current Node is not empty
        assert(this->get_next_ptr() != NULL);       //Check if the current Node is not sentinel tail

        return this->node_ptr->data;
    }

    /* Overload the indirection operator
     * Const version
     */
    const type& operator*() const {

        assert(this->node_ptr != NULL);
        assert(this->get_next_ptr() != NULL);

        return this->node_ptr->data;
    }

    /* Overload the arrow operator */
    type* operator->() {
        assert(this->node_ptr != NULL);
        assert(this->get_next_ptr != NULL);

        return &(node_ptr->data);
    }

    /* Overload the arrorw operator
     * Const Version
     */
    const type* operator->() const {
        assert(this->node_ptr != NULL);
        assert(this->get_next_ptr != NULL);

        return &(node_ptr->data);
    }

    /* Overload the equality operator */
    bool operator==(const Iterator_Node<type> &i) {
        return (this->node_ptr == i.node_ptr);
    }

    /* Overload the inequality operator */
    bool operator!=(const Iterator_Node<type> &i) {
        return (this->node_ptr != i.node_ptr);
    }

    /* Overload the prefix operator */
    Node<type>& operator++() {
        assert(this->node_ptr != NULL);
        assert(this->get_next_ptr() != NULL);

        node_ptr = node_ptr->get_next_ptr();
        return (*node_ptr);
    }

    /* Overload the postfix operator */
    Node<type> operator++(int) {
        assert(this->node_ptr != NULL);
        assert(this->get_next_ptr != NULL);

        Node<type> *temp_ptr = this->node_ptr;
        node_ptr = node_ptr->get_next_ptr();
        return (*temp_ptr);
    }

    /* Overload the -- operator */
    Node<type>& operator-- () {
        assert(this->node_ptr != NULL);
        assert(this->get_next_ptr() != NULL);
        assert(this->get_prev_ptr()->get_prev_ptr() != NULL);

        node_ptr = node_ptr->get_prev_ptr();
        return (*node_ptr);
    }

    /* Overload the -- postfix operator */
    Node<type> operator--(int) {
        assert(this->node_ptr != NULL);                         //Check if the current Node is NULL
        assert(this->get_next_ptr());                           //Check if the current Node is a sentinel tail
        assert(this->get_prev_ptr()->get_prev_ptr() != NULL);   //Check if the iterator is pointing to the begin() node

        Node<type> *temp_ptr = this->node_ptr;
        node_ptr = node_ptr->get_prev_ptr();
        return (*temp_ptr);
    }
};

#endif // ITERATOR_NODE_H
