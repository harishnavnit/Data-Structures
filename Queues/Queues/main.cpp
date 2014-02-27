#include "QueueInt.h"

using namespace std;

int main()
{
    Queue_Int q;            //Object of the queue class
    int el;             //Element to be pushed
    string cmd;         //String to manipulate the input

    cout<<"\n ***********Queue of Integers **************"<<endl;

        while(1)
        {
            try{
                cin>>cmd;

                if(cmd=="push") cin>>el;
                if(cmd=="push") q.push(el);
                else if(cmd=="pop") q.pop();
                else if(cmd=="print") q.print();
                else if(cmd=="exit") break;
                else
                    cerr<<"Invalid Command"<<endl;
            }
            catch(overflow_error e) {
                cout<<e.what()<<endl;
            }
            catch(underflow_error e) {
                cout<<e.what()<<endl;
            }
        }

    return 0;
}
