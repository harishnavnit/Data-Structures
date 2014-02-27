#ifndef __QUEUE_INT_H__
#define __QUEUE_INT_H__

#include <iostream>
#include <cstdlib>
#include <climits>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <cstring>


using std::cout;
using std::cin;
using std::underflow_error;
using std::overflow_error;
using std::cerr;
using std::exception;
using std::ostream;


/**Listing for class Queue begins */
class Queue_Int {
public :
/*User-defined Definitions */
    typedef size_t size_type;
    typedef int value_type;

private :
    /*Variable that holds the max size of the queue */
    static const size_t max_queue_size=5;

    value_type data[max_queue_size];        //An array to represent the queue
    size_type queue_size;
    int front_queue;
    int back_queue;

    public :
    /*Default Constructor */
    Queue_Int():queue_size(0),front_queue(-1),back_queue(-1) {
        for(int i=0;i<max_queue_size;i++) {
            data[i]=0;
        }
    }

    /* Test wether the container is empty
     * Returns wether the queue is empty
     */
    bool empty() const {return (queue_size==0); }

    /*Insert elments.
     *Adds a new element to the end of the queue,after it's current last element
     *The content of this new element is initialized to a copy of x
     */
    void push(const int& x);

    /*Delete the next element.
     *Removes the next element in the queue,effectively reducing it's size by one.
     *The removed element is the "oldest" element in the queue whose value can be
     *retrieved by calling member queue::front()
     */
    void pop();

    /*To get the size of the queue */
    size_type Size() const {return queue_size;}

    /*Access the next element. Returns a reference to the last element in the queue.
     *This is the "oldest" element in the queue and the same element that is popped
     *out from the queue if member queue::pop is called
     */
    value_type& front() {return data[front_queue];}
    const value_type& front() const {return data[front_queue];}

    /*Access the last element. Returns a reference to the last element in the queue.
     *This is the "newest" element in the queue, i.e the last element
     *pushed into the queue
     */
    value_type& back() {return data[back_queue];}
    const value_type& back() const {return data[back_queue];}

    /*To print the queue */
    void print();

    /*Friend Function for overloading the output operator with the
     *Queue_Int class
     */
    //friend ostream& operator << (ostream& out, const Queue_Int& q);
};

#include "QueueInt.cpp"

#endif
