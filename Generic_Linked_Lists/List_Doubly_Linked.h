#ifndef LIST_DOUBLY_LINKED_H
#define LIST_DOUBLY_LINKED_H

#include "Node.h"
#include "Iterator_Node.h"

using namespace std;

template <class type>
class List_doubly_linked {
public:
    typedef size_t size_type;                               /* Represent the size of the list */
    typedef Iterator_Node<type> iterator;                   /* Iterator to a node in the list */
    typedef const Iterator_Node<type> const_iterator;       /* Constant iterator to a node in the list */

private:
    Node<type> sentinel_head;           /* Dummy node at the start of the list */
    Node<type> sentinel_tail;           /* Dummy node at the end of the list   */
    size_type list_size;                /* No. of elements in the list         */

public:

    /* Constructors */
    explicit List_doubly_linked() :
        sentinel_head(),sentinel_tail(),list_size(0) {
        /* Default Constructor */
    }



    /* Utility Functions */

    /* Insert an element to the end of the list */
    void push_back(const type &d);

    /* Insert an element to the front of the list */
    void push_front(const type &d);

    /* Remove an element from the end of the list */
    void pop_back();

    /* Remove an element from the front of the list */
    void pop_front();

    /* Check if the list is empty */
    bool empty() { return (list_size == 0); }

    /* Print the list from head to tail */
    void print();

    /* Print the list from tail to head */
    void print_reverse();

    /* Get the size of the list.
     * i.e No. of elements in the list
     */
    size_type Size() const { return list_size; }

    /* Returns the iterator to the first
     * element in the list
     */
    iterator begin() {
        return iterator(sentinel_head.get_next_ptr());
    }
    /* Const Version */
    const_iterator begin() const {
        return const_iterator(sentinel_head.get_next_ptr());
    }

    /* Returns the iterator to past the
     * last element in the list.
     */
    iterator end() {
        return iterator(&sentinel_tail);
    }
    /* Const version */
    const_iterator end() const {
        return const_iterator((Node<type>* const)&sentinel_tail);
    }

    /* Clear the list.
     * Remove all the elements in the list.
     */
    void clear();


};  /* End of List_doubly_linked class */

#include "List_Doubly_Linked.cpp"

#endif // LIST_DOUBLY_LINKED_H
