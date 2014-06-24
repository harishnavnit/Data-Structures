#include "Node.h"
#include "Iterator_Node.h"
#include "List_Doubly_Linked.h"

using namespace std;

/***************************************************************************************************************/
/* Insert elements to the end of the list */
template <class type>
void List_doubly_linked<type> :: push_back(const type &d) {

    Node<type> *to_be_inserted = new Node<type>(d);        //Node to be inserted

    /* Check if the list is empty */
    if(empty()) {
        /* Add the node to the next of sentinel head */
        sentinel_head.set_next_ptr(to_be_inserted);
        to_be_inserted->set_prev_ptr(&sentinel_head);
        to_be_inserted->set_next_ptr(&sentinel_tail);
        sentinel_tail.set_prev_ptr(to_be_inserted);
    }

    /* if the list contains at least one element */
    else {
        Node<type> *temp = sentinel_tail.get_prev_ptr();        //Reach the last element of the list
        temp->set_next_ptr(to_be_inserted);
        to_be_inserted->set_next_ptr(temp);
        to_be_inserted->set_next_ptr(&sentinel_tail);
        sentinel_tail.set_prev_ptr(to_be_inserted);
    }

    list_size++;

    return;
}

/**************************************************************************************************************/
/* Insert an element to the head of the list */
template <class type>
void List_doubly_linked<type> :: push_front(const type &d) {

    Node<type> *to_be_inserted = new Node<type>(d);         //Node to be inserted

    /* Check if the list is empty */
    if(empty()) {
        push_back(d);
    }
    /* The list contains at least one element */
    else {

        list_size++;     //First increment after inserting the first element.

        Node<type> *temp = sentinel_head.get_next_ptr();
        temp->set_prev_ptr(to_be_inserted);
        to_be_inserted->set_next_ptr(temp);

        to_be_inserted->set_prev_ptr(&sentinel_head);
        sentinel_head.set_next_ptr(to_be_inserted);
    }

    return;
}

/******************************************************************************************************************/
/* Remove an element from the end of the list */
template <class type>
void List_doubly_linked<type> :: pop_back() {
    /* Check if the list is empty */
    if(empty()) {
      /* Nothing to pop. 
       * Do Nothing. 
       */
      return; 
    }

    /* The list contains atleast one element */
    else {
      Node<type> *temp = sentinel_tail.get_prev_ptr();
      Node<type> *prev_temp = temp->get_prev_ptr();

      prev_temp->set_next_ptr(&sentinel_tail);
      sentinel_tail.set_prev_ptr(prev_temp);

      delete temp;
      list_size--;
    }
}

/********************************************************************************************************************/
/* Print the list from head to tail */
template <class type> 
void List_doubly_linked<type> :: print() {
    
    Node<type> *ptr = sentinel_head.get_next_ptr();

    while(ptr != &sentinel_tail) {
      cout<<ptr->get_data()<<" --> ";
      ptr = ptr->get_next_ptr();
    }
    cout<<endl;
}
