#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;

class simple_graph {
private:
    map<int, set<int> > data;
    string              name;

public:
    /* Constructor */
    simple_graph(string g_name) : name(g_name) { }

    /* Utility Functions */
    void insert(int a, int b);
    void delete_vertex(int a);
    void delete_edge(int a, int b);
    void BFS_visit();
    void print();
};

#include "graph.cpp"

#endif //__GRAPH_H__
