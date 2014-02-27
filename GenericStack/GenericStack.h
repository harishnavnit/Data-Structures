#ifndef __GENERICSTACK_H__
#define __GENERICSTACK_H__

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <iomanip>

using std::cout;
using std::cin;
using std::cerr;
using std::exception;
using std::underflow_error;
using std::overflow_error;
using std::ostream;


/*Declarations */
template<class Type> class Stack;

/*Stack Template */
template<class Type>
class Stack {
public:
    /*Public data types */
    typedef size_t size_type;
    typedef Type value_type;

private:
    /*Size of the stack */
    static const size_t stack_size=10;

    /*Array for holding the elements of the stack */
    value_type data[stack_size];

    /*To keep track of the top of the stack */
    signed int top_of_stack;

public:
    /*Default Constructors */
    Stack():top_of_stack(-1) { }

    /*Function to check if the stack is empty */
    bool empty() const {return (top_of_stack==-1); }

    /*Function to return the number of elements on the stack */
    size_type Size() const {return size_type(top_of_stack+1);}

    /*Returns a reference to the top element of the stack
     *Non-Const and Const versions
     */
    value_type& top() { return data[top_of_stack]; }
    const value_type& top() const { return data[top_of_stack]; }

    /*Add element to the top of the stack */
    void push(const value_type& x);

    /*Removes an element from the top of the stack */
    void pop();

    /*Print the contents of the stack from top to bottom */
    void print();
};

#include "GenericStack.cpp"

#endif
