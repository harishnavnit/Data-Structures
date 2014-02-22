#include "List.h"

using namespace std;

/*Function defintions of the list class */

void List::push_back(const int& data) {

    node* temp = new node(data);
    ++_size;

        if(empty()) {
            head = tail = temp;
        }

        else {
            //cout<<"\nThe List is not empty ! ";
            tail->set_next(temp);
            tail=temp;
        }
}

void List::push_front(int data) {
    if(!empty()) {
        node* temp = new node(data);
        temp->set_next(head);
        head = temp;
        ++_size;
    }

    else {
        push_back(data);
    }
}

void List::pop_back() {
    if(empty()) {
        throw underflow_error("Empty List ! Nothing to pop");
    }

    else {
        node* temp=head;
        while(temp!=NULL) {
            temp=temp->get_next();
            temp->set_next(NULL);
            delete tail;
            --_size;
        }
    }
}

void List::pop_front() {
    if(empty()) {
        throw underflow_error("Empty List ! Nothing to pop");
    }

    else {
        node* temp = head;
        temp = temp->get_next();
        temp = head;
        delete head;
    }
}

void List::print() {
    /*Checking if the list is empty */
    if(empty()) {
        cout<<"\nEmpty Linked List"<<endl;
    }
    else {
        node* temp = head;
        while(temp != NULL) {
            cout<<"-->"<<temp->get_data();
            temp = temp->get_next();
        }
    }
}

void List :: clear() {
    if(empty()) {
        throw underflow_error("Empty List ! Nothing to clear ");
    }
    while(!empty()) {
        pop_back();
    }
}
