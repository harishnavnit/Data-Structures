#include "List.h"
#include <iostream>

using namespace std;

int main()
{
    List l1;                        //Instance of the list class
    int data;               //Contains the data to be pushed
    string cmd;

    cout<<"\n****** Linked List of Integers ******\n"<<endl;

    while(1) {
        try {
            cin>>cmd;

            if(cmd == "push") cin>>data;
            if(cmd == "push") l1.push_back(data);
            else if(cmd == "pop") l1.pop_back();
            else if(cmd == "print") l1.print();
            else if(cmd == "exit") break;
            else cerr<<"Wrong Command !"<<endl;
        }
        catch (const overflow_error& e) {
            cout<<e.what()<<endl;
        }
        catch (const underflow_error& e) {
            cout<<e.what()<<endl;
        }
    }

    return 0;
}
