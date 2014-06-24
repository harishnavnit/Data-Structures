#include <iostream>
#include "List_Doubly_Linked.h"
#include "Node.h"
#include "Iterator_Node.h"
#include <string>
#include <cstring>

using namespace std;

int main()
{
    List_doubly_linked<string> l1;

    l1.push_front("Legend");
    l1.push_front("a");
    l1.push_front("is");
    l1.push_front("Harish");

    l1.pop_back();

    l1.print();

    return EXIT_SUCCESS;
}

