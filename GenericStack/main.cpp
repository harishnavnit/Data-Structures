#include "GenericStack.h"

using namespace std;

/*Program enty point */
int main()
{
    Stack<string> stk;
    string cmd;
    string data;

    cout<<"\n**************** Generic Stack ******************** \n"<<endl;
    while(1) {
        try{
            cin>>cmd;
            if(cmd=="push") cin>>data;
            if(cmd=="push") stk.push(data);
            else if(cmd=="pop")stk.pop();
            else if(cmd=="print") stk.print();
            else if(cmd=="exit") break;
            else    cerr<<"Wrong Command"<<endl;
        }
        catch(const overflow_error& e) {
            cerr<<e.what()<<endl;
        }
        catch(const underflow_error& e) {
            cerr<<e.what()<<endl;
        }
    }
    return 0;
}
