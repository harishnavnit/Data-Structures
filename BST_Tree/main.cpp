#include "Tree_Int.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>


using namespace std;

int main(int argc, const char *argv[])
{
  Tree_Int tree;               //Creating the instance of the Tree_Int class
  string elements,distance;    //String inputs.
  int integer,del,d1,d2;
  char ans;                    //User's choice

  cout<<"\n ************************* Tree_Int *************************\n";

  cout<<"\n Enter elements to be inserted(Type 'exit' once you're done) : \n";

  while(elements != "exit") {
      cin>>elements;
      stringstream(elements) >> integer;
      tree.insert(integer);
    }

  cout<<"\n Elements inserted into the tree !"<<endl;
  cout<<"\n Printing the inorder Traversal of the Tree "<<endl<<endl;
  tree.inorder();

  cout<<"\n Would you like to delete any entries from the tree ? (y/n) : ";
  cin>>ans;

  if(ans == 'Y' || ans == 'y') {
    cout<<"\n Enter the entry to be deleted : ";
    cin>>del;

    tree.delete_node(del);
  }

  cout<<"\n Tree after deleting "<<del<<" is as follows : \n"; tree.print();

  cout<<"\n Type 'dist' to find the distance between two nodes in the tree : ";
  cin>>distance;

  if(distance == "dist") {
    cout<<"\n Enter the first entry : ";
    cin>>d1;
    cout<<"\nEnter the second entry : ";
    cin>>d2;

    cout<<"\n Distance between the two entries = "<<tree.node_distance(d1,d2)<<endl;
  }
  else {
    cout<<"\nSkipping Finding the distance !\n";
  }

  cout<<"\n Printing the Final Tree(Printing the Inorder traversal) : \n\n"<<endl;
  tree.print();

  cout<<"\n\n******************************** Tree_Int ****************************\n\n";

  return EXIT_SUCCESS;
}
