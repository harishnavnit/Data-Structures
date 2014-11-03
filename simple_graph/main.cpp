#include "graph.h"

using namespace std;

int main(int argc, char const* argv[])
{
    int x,y;
    string cmd;
    simple_graph g1("Test_Graph");

    cout<<"\nEnter your command : ";
    do {
        cin>>cmd;

        if(cmd == "print") {
            g1.print();
        }
        else if(cmd == "insert") {
            cin>>x>>y;
            g1.insert(x,y);
        }
        else if(cmd == "delete_edge") {
            cin>>x>>y;
            g1.delete_edge(x,y);
        }
        else if(cmd == "delete_vertex") {
            cin>>x;
            g1.delete_vertex(x);
        }
        else {
            cerr<<"\nUnknown Command"<<endl;
            break;
        }
    } while(cmd != "exit" || cmd != "Exit" || cmd != "EXIT" || cmd != "quit" || cmd != "QUIT" || cmd != "Quit");

    return 0;
}
