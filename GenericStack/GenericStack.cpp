#include "GenericStack.h"

using namespace std;

/*Definitions */

/*Adding an element to the stack */
template<class Type>
void Stack<Type>::push(const value_type& x) {
    /*Check for overflow */
    if(top_of_stack==stack_size-1)
        throw overflow_error("Stack Overflow ");

    data[++top_of_stack]=x;
    return;
}

/*Removing an element from the stack */
template<class Type>
void Stack<Type>::pop() {
    /*Check for underflow */
    if(top_of_stack=-1) {
        throw underflow_error("Stack Underflow ");
    }
    --top_of_stack;
    return;
}

/*Printing the elements of the stack */
template<class Type>
void Stack<Type>::print() {

    cout<<endl;

    for(int i=top_of_stack;i>=0;i--)
    {
        if(i==top_of_stack)
            cout<<data[i]<<"<--Top"<<endl;
        else
            cout<<data[i]<<endl;
    }

    cout<<endl;
}
