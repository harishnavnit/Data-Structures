#include "DoublyLinkedList.h"
#include "Node.h"

using namespace std;

/*Definitions for the Iterator_Node class begin */

int& Iterator_Node::operator*() {
        /*   Make sure that :
         * 1)The iterator is pointing to NULL
         * 2)This pointer is not pointing to sentinel_tail
         */
        assert(this->node_ptr!=NULL);
        assert(this->node_ptr->get_next() != NULL);

        return this->node_ptr->data;
}
/*Const verison */
const int& Iterator_Node::operator*(){
       assert(this->node_ptr!=NULL);
       assert(this->node_ptr->get_next()!=NULL);

        return this->node_ptr->data;
}

/*Overloading the arrow operator */
//Non-Const verison
Node* Iterator_Node::operator -> () {
        assert(this->node_ptr!=NULL);
        assert(this->node_ptr->get_next()!=NULL);

        return node_ptr;
}
//Const version
const Node* Iterator_Node :: operator -> () const {
        assert(this->node_ptr!=NULL);
        assert(this->node_ptr->get_next()!=NULL);

        return node_ptr;
    }

/*Overloading the equality operators */
    //Non-Const Version
    bool Iterator_Node::operator == (const Iterator_Node& i) {
        return (this->node_ptr == i.node_ptr);
    }
    //Const version
    bool Iterator_Node::operator != (const Iterator_Node& i) {
        return (this->node_ptr!=i.node_ptr);
    }

/*Overload the ++ operators (Postfix/Prefix) */
    //Prefix Version
    Node& Iterator_Node::operator ++ () {
     /*Ensuring that the current node is not a sentinel */
        assert(this->node_ptr!=NULL);
        assert(this->node_ptr->get_next()!=NULl);

        node_ptr = node_ptr->get_next();
        return (*node_ptr);
    }
    //Postfix Version
    Node& Iterator_Node::operator ++ (int) {
        assert(this->node_ptr!=NULL);
        assert(this->node_ptr->get_next()!=NULL);

        Node* temp_ptr = this->node_ptr;
        node_ptr=node_ptr->get_next();
        return (*temp_ptr);
    }

/*Overload the ++ operators (Postfix/Prefix) */
    Node& operator ++ () {}
    Node& operator ++ (int) {}

    /*Overloading the -- operator(Prefix/Postfix) */
    Node& Iterator_Node::operator -- () {
     /*Ensuring the current nodes do not point to the sentinel/begin */
        assert(this->node_ptr!=NULL);
        assert(this->node_ptr->get_next()!=NULL);
        assert(this->node_ptr->get_prev()!=NULL);

        node_ptr = node_ptr->get_prev();
        return (*node_ptr);
    }
    //Postfix Version
    Node& Iterator_Node::operator -- (int) {
     /*Ensuring the current nodes do not point to the sentinel/begin */
        assert(this->node_ptr!=NULL);
        assert(this->node_ptr->get_next()!=NULL);
        assert(this->node_ptr->get_prev()!=NULL);

        Node* temp_ptr= this->node_ptr;
        node_ptr = node_ptr->get_prev();
        return (*temp_ptr);
    }

/* End of Definitions for the Iterator_Node class */
