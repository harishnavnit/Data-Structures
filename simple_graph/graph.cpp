#include "graph.h"
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <string>
#include <queue>

using namespace std;

/* Public member function definitions */

/* Insert an edge from a to b */
void simple_graph::insert(int from_a, int to_b) {
    map<int, set<int> > :: iterator from_temp_itr, to_temp_itr;

    from_temp_itr = data.find(from_a);
    to_temp_itr   = data.find(to_b);

    if(from_temp_itr == data.end()) {
        /* Insert edge */
        cout<<"\nInserting edge from "<<from_a<<" --> "<<to_b<<endl;
        set<int> temp_set;
        temp_set.insert(to_b);
        pair<int, set<int> > temp_pair(from_a, temp_set);
        data.insert(temp_pair);
    }
    else if(from_temp_itr != data.end()) {
        from_temp_itr->second.insert(to_b);
    }
    else {
        cerr<<"\nOops ! That's awkward ! :("<<endl;
    }

    if(to_temp_itr == data.end()) {
        cout<<"\nInserting edge from "<<to_b<<" --> "<<from_a<<endl;
        set<int> temp_set;
        temp_set.clear();
        temp_set.insert(from_a);
        pair<int, set<int> > temp_pair(to_b, temp_set);
        data.insert(temp_pair);
    }
    else if(to_temp_itr != data.end()) {
        to_temp_itr->second.insert(from_a);
    }
    else {
        cerr<<"\nOops ! That's awkward ! :( "<<endl;
    }
}

/* Delete a vertex and all edges containing it */
void simple_graph::delete_vertex(int a) {
    map<int, set<int> > :: iterator temp_iter;
    temp_iter = data.find(a);

    cout<<"\nDeleting vertex "<< a <<endl;

    if(temp_iter == data.end()) {
        cout<<"\nVertex not found"<<endl;
    }
    else {
        map<int, set<int> > :: iterator new_iter;

        for(new_iter = data.begin(); new_iter != data.end(); ++new_iter) {
            new_iter->second.erase(a);
        }
        data.erase(temp_iter);
    }
}

/* Delete and edge in a graph */
void simple_graph::delete_edge(int a, int b) {
    map<int, set<int> > :: iterator itr1, itr2;

    itr1 = data.find(a);
    itr2 = data.find(b);

    cout<<"\nDeleting edege between "<< a << " and "<< b << endl;

    if(itr1 != data.end() && itr2 != data.end()) {
        // Found a and b
        itr1->second.erase(b);
        itr2->second.erase(a);
    }
    else {
        cout<<"\nEdge not present"<<endl;
    }
}

/**void simple_graph::BFS_vist(int vertex,) {

}*/

/* Print the resulting graph */
void simple_graph::print() {

    cout<<"\nPrinting the edges and vertices in the graph"<<endl;
    map<int, set<int> > :: iterator iter;

    for(iter = data.begin(); iter != data.end(); iter++) {
        cout<< iter->first;
        for(set<int>::iterator i = iter->second.begin(); i!=iter->second.end(); i++) {
            cout<<" --> "<<*i;
        }
        cout<<";"<<endl;
    }
}
