#include "Kruskal.h"

using namespace std;

/*Begining of the Main method */
int main(int argc, char const* argv[])
{
    int x, y, w;
    string cmd;
    char help;
    vector<pair<int, int> > mst_edges;
    Graph g1("KRUSKAL");

    cout<<"\n************************************************************************************************\n"<<endl;
    cout<<"\nPress 'H' to view the commands : ";
    cin>>help;
    
    if(help == 'H' || help == 'h') {
      cout<<"\nThe following commands are recognized"<<endl;
      cout<<"1. Insert an edge from 'a' to 'b' with weight 'w' 	: <insert edge1 edge2 weight>"<<endl;
      cout<<"2. Delete and edge from 'a' to 'b' \t		: <delete_edge edge1 edge2>"<<endl;
      cout<<"3. Delete vertex 'v'				\t: <delete_vertex vertex_name>"<<endl;
      cout<<"4. Find and print the MST using Kruskal algorithm  	: <kruskal>"<<endl;
      cout<<"5. Print final graph after running all commands	\t: <print>"<<endl;
    }
    
    cout<<"\nEnter the command : "<<endl;
    do {
        cin >> cmd;

        if(cmd == "print") {
            g1.print();
        }
        else if(cmd == "kruskal") {
            g1.MST_using_KRUSKAL(mst_edges);
        }
        else if(cmd == "insert") {
            cin>> x >> y >> w;
            g1.insert_weighted_edge(x, y, w);
        }
        else if(cmd == "delete_edge") {
            cin >> x >> y;
            g1.delete_edge(x, y);
        }
        else if(cmd == "delete_vertex") {
            cin>> x;
            g1.delete_vertex(x);
        }
        else {
            cerr << "\nUnknown Command" << endl;
        }
    } while(cmd != "exit");

    cout<<endl;

    return EXIT_SUCCESS;
}
