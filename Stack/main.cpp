#include "stack.h"
#include "stack.cpp"

using namespace std;

/*Begining of the driver class --- a.k.a main */
int main()
{
    stack s;        //Stack Object
    int el;         //element to be pushed
    string cmd;     //To know what the user wants to do

    cout<<"UINT_MAX = "<<UINT_MAX<<endl;
    while(1) {

    try {

        cin>>cmd;

        if(cmd == "push") cin>>el;
        if(cmd == "push") s.push(el);
        else if(cmd == "pop") {
            s.pop();
        }
        else if(cmd == "print") {
            s.print();
        }
        else if(cmd == "exit") {
            break;
        }
        else
            cerr<<"Wrong Command ! "<<endl;
        }
        catch(const overflow_error& e) {
        cout<<e.what()<<endl;
        }
        catch(const underflow_error& e) {
        cout<<e.what()<<endl;
        }
    }

    return 0;
}
