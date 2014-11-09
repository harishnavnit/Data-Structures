#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Graph {
private:
    string name; 		// Name of the graph
    map<int, set<int> > data;	// To store the edges/vertices
    
    /* For weighted graphs */
    map<pair<int, int>, int> edge_weights;

public:
    /* Constructor */
    Graph(string g_name) : name(g_name) { }

    /* Utility functions */
    void insert_weighted_edge   (int, 			int,     	int);
    bool is_edge                (int,      				int);
    void delete_vertex          (int          				   );
    void delete_edge            (int,					int);
    void MST_using_KRUSKAL      (vector<pair<int, int> > &mst_tree_edges   );
    void print                  (void       				   );
    map<int, set<int> > :: iterator find_vertex		(int 		   );
    size_t vertex_count(void )  { 	return data.size();		   }
    
    /* Additional getter and setter functions */
    int get_weight(int, int);
    void set_weight(int, int, int);
};

#include "Kruskal.cpp"

#endif // __KRUSKAL_H__
