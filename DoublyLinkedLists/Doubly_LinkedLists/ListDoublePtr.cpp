#include "Node.h"
#include "DoublyLinkedList.h"
#include "ListDoublePtr.h"

using namespace std;

/*Function definitions for the List_double_ptr_Int class */

/*Pushing a node to the end of the list */
void List_double_ptr_Int::push_back(const int& d) {
    //Node to be inserted
    Node *node = new Node(d);

    /*Check if the list is empty */
    if(this->Size()==0) {
        /*Insert the first node */

        //Linking the new node and the sentinel head
        sentinel_head.set_next(node);
        node->set_prev(&sentinel_head);

        //Linking the new node and the sentinel tail
        sentinel_tail.set_prev(node);
        node->set_next(&sentinel_tail);
    }
    else {
        /*The List contains atleast one element */

           Node* temp = sentinel_tail.get_prev();   //Storing the link of the node before sentinel tail
           temp->set_next(node);
           node->set_prev(temp);
           sentinel_tail.get_prev(node);
           node->set_next(&sentinel_tail);
    }

    list_size++;
    return;
}

/*Removing a node from the end of the list */
void List_double_ptr_Int::pop_back() {
    /*Check if the List is empty */
    if(this->Size()==0) {
        throw underflow_error("Empty List ! Nothing to pop");
    }
    else {
        if(this->Size()==1) {
            /*The List contains exactly one element */
            Node* temp = sentinel_head.get_next();      //Setting the temp to the head of the list
                                                        //(the only element in the list)
            sentinel_head.set_next(&sentinel_tail);
            sentinel_tail.set_prev(&sentinel_head);
            delete temp;
            --list_size;
            return;
        }
        else {
            /*The list contains atleast one element */
            Node* temp = sentinel_tail.get_prev();      //Storing the link of the last element in the list
            Node* temp_1 = temp->get_prev();            //Storing the link of the second last element

            //Pointing the second last element to the sentinel tail
            temp_1->set_next(&sentinel_tail);
            sentinel_tail.set_prev(temp1);      //Setting the second last element of the list as the previous
                                                //element of the list.
            delete temp;
            --list_size;
        }
    }
}

/*Printing the List from head to tail */
void List_double_ptr_Int::print() {
    /*Check if the list is empty */
    if(Size()==0) {
        cout<<"\nEmpty Linked List"<<endl;
    }
    else {
        /*The List contains more than one element */
        Node* temp = sentinel_head.get_next();

        while((this->get_next()!=sentinel_tail) || (this->get_next()==NULL)) {
            cout<<this->get_data()"-->";
            temp=temp->get_next();
        }
    }
}
