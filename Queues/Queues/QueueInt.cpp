#include "QueueInt.h"

using namespace std;

/*Function definitions for the QueueInt class */

/*Pushing data into a queue */
void Queue_Int::push(const int& x) {
    /*Check if full */
    if((front_queue==back_queue+1)||((front_queue==0)&& (back_queue==max_queue_size-1))) {
        throw overflow_error("Queue Full ! Unable to push");
    }
    else {
        /*Queue is not full
         *Check if empty
         */
        if(empty()) {
            front_queue=back_queue=0;
            data[back_queue]=x;
        }
        else {
            /*Queue is not empty */
            back_queue = ((back_queue == max_queue_size-1)?0:back_queue+1);
            data[back_queue]=x;
        }
        queue_size++;
    }
}

/*Removing an element from the queue */
void Queue_Int::pop() {
    /*Check if the queue is empty */
    if(empty()) {
        throw underflow_error("Empty Queue ! Nothing to pop");
    }
    else {
        /*If the queue contains exactly one element */
        if(Size()==1) {
            data[front_queue]=0;
            front_queue = back_queue = -1;
        }
        else {
            /*The queue contains more than one element */
            data[front_queue]=0;
            front_queue = ((front_queue==max_queue_size-1)?0:++front_queue);
        }
        queue_size--;
    }
}

/*Print the queue from front to rear */
void Queue_Int::print() {

    if(empty()) {
        cout<<"\nEmty Queue"<<endl;
    }

    for(int i=front_queue;i<=back_queue;i++) {
        if(i==front_queue)
            cout<<"front-->"<<data[i];
        else if(i==back_queue)
            cout<<"--"<<data[i]<<"<--rear"<<endl;
        else
        cout<<"--"<<data[i];
    }
}
