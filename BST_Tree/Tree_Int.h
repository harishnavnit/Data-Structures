#ifndef __TREE_INT_H__
#define __TREE_INT_H__

#include "Node.h"
#include <vector>

using namespace std;

class Tree_Int {
private:
  Node<int> *root;
  size_t tree_size;
  static int deletion_flag;
  vector<int> v;

public:
  /* Constructors */
  Tree_Int() :
	    root(NULL),tree_size(0) {
	      /* Default Constructor */
	    }

  /* Get the root of the tree */
  Node<int>* get_root() { return root;}

  /* Check if the tree is empty */
  bool empty() { return (tree_size == 0);}

  /* Get the size of the tree */
  size_t Size() { return tree_size; }

  /* Insert elements into the Tree */
  void insert(int x);

  /* Check if a node is a leaf node */
  bool is_leaf(int x);

  /* Inorder Traversal of the tree
   * Left, Right, Root
   */
  void inorder(Node<int> *node_ptr);
  void inorder();

  /* Print the resulting tree elements */
  void print();

  /* Search for an element in the list */
  Node<int>* search_tree(int value);

  /* Delete a node from the tree */
  bool delete_node(int value);
  bool delete_node(Node<int> *node);

  /* Find the inorder predecessor of the node */
  Node<int>* get_inorder_predecessor(Node<int> *node);

  /* Find the inorder successor of the node */
  Node<int>* get_inorder_successor(Node<int> *node);

  /* Check if a node is a leaf node */
  bool is_leaf(Node<int> *node);

  /* Check if a node has only one child */
  bool has_only_one_sibbling(Node<int> *node);

  /* Check if a node has two sibblings */
  bool has_two_sibblings(Node<int> *node);

  /* Check if a node is the root node */
  bool is_root(Node<int> *node) {
    return (node == root);
  }

  /* Check if a node is a right child */
  bool is_right_child(Node<int> *node);

  /* Check if a node is a left child */
  bool is_left_child(Node<int> *node);

  /* Finding the parent of a node */
  Node<int>* get_parent(Node<int> *node);

  /* Find the distance between two nodes */
  int node_distance(Node<int> *node1, Node<int> *node2);
  int node_distance(int val1, int val2);

  /* Print the tree on a dot file */
  void print_to_file();
  void write_to_file(vector<int> v);

};

#include "Tree_Int.cpp"

#endif //__TREE_INT_H__
