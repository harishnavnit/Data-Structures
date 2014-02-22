#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <climits>

#define MAX 10

using std::cout;
using std::cin;
using std::exception;
using std::underflow_error;
using std::overflow_error;
using std::cerr;
using std::ifstream;
using std::ostream;


/*Listing for class Stack begins */
class stack {
private :
    int data[MAX];              //Array to hold the stack elements
    int _size;               //Holds the size of the stack
    int top_of_stack;    //Hold the element in the top of the stack

public :
    /*Constructors */
    stack() : top_of_stack(-1) {} //Default Constructor

    /*Checks if the stack is empty */
    bool empty() {
        return (top_of_stack==-1);
    }

    /*Returns the size of the stack */
    size_t Size() {
        return top_of_stack+1;
    }

    /*Add element to the top of the stack */
    void push(const size_t& x);

    /*Remove an element from the stack */
    void pop();

    /*Print the elements of the stack */
    void print();
};

#endif
