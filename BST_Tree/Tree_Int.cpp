#include "Node.h"
#include "Tree_Int.h"

#include <cmath>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/* Function definitions */

/*****************************************************************************************/
/* Static Data of the Tree_Int class */
int Tree_Int::deletion_flag = 0;

/*****************************************************************************************/
/* Inorder Traversal
 * Left, Root, Right
 */
void Tree_Int::inorder(Node<int> *node_ptr) {
  if(node_ptr == NULL) {
    return;
  }
  else {
    /* Inorder traversal using recursion */
    inorder(node_ptr->get_left_ptr());      // Traverse to the left child
    cout<<node_ptr->get_data()<<" ";        // Print the data
    v.push_back(node_ptr->get_data());
    inorder(node_ptr->get_right_ptr());     // Traverse to the right
  }
  return;
}

void Tree_Int::inorder() {
  inorder(get_root());
  return;
}

/**************************************************************************************/
/* Insert elements into the tree 
 * Sort the elements while insertions 
 */
void Tree_Int::insert(int x) {
    Node<int> *node_ptr = new Node<int>(x);

    if(empty()) {
        /* Empty Tree
         * insert the root
         */
        root = node_ptr;
        ++tree_size;
    }
    else {
        /* Tree not empty */

        Node<int> *temp = root;

        while(1) {
            if(temp->get_data() > x) {
                /* Traverse the left subtree */
                if(temp->get_left_ptr() == NULL) {
                    /* Left subtree empty
                     * insert the node here
                     */
                    temp->set_left_ptr(node_ptr);
                    break;
                }
                else {
                    /* Left subtree is not empty
                     * Continue traversing
                     */
                    temp = temp->get_left_ptr();
                }
            }
            else if(temp->get_data() < x) {
                /* Traverse the right subtree */

                if(temp->get_right_ptr() == NULL) {
                    /* Right subtree empty
                     * Insert node here
                     */
                    temp->set_right_ptr(node_ptr);
                    break;
                }
                else {
                    temp = temp->get_right_ptr();
                }
            }
            else {
               // cerr << "\n\nElement to be inserted already Present !\n\n";
                return;
            }
        } /* while(1) {...} */

        /* Increment the size of the tree */
        ++tree_size;

    } /* Tree not empty */
}

/*************************************************************************************/
/* Search the tree for an element */
Node<int>* Tree_Int::search_tree(int value) {
  Node<int> *curr_node = get_root();

  while(curr_node != NULL) {
    if(value == curr_node->get_data()) {
      return curr_node; 
    }
    else if(curr_node->get_data()>value) {
      curr_node = curr_node->get_left_ptr();
    }
    else if(curr_node->get_data() < value) {
      curr_node = curr_node->get_right_ptr();
    }
  }
  return NULL;
}

/************************************************************************************/
/* Finding the parent of a node */
Node<int>* Tree_Int::get_parent(Node<int> *node) {
  if(node == NULL) return NULL;

  /* Start from the root */
  Node<int> *curr_node = get_root();
  Node<int> *prev_node = NULL;

  while(curr_node != NULL) {
    if(node->get_data() == curr_node->get_data()) {
      return prev_node;
    }
    else {
      prev_node = curr_node;
      if(node->get_data() < curr_node->get_data())
        curr_node = curr_node->get_left_ptr();
      else if(node->get_data() > curr_node->get_data())
        curr_node = curr_node->get_right_ptr();
    }
  }

  return NULL;
}
/*************************************************************************************/
/* Find the inorder predecessor of the node */
Node<int>* Tree_Int::get_inorder_predecessor(Node<int> *node) {
  if(node == NULL)
    return NULL;
  else {
    if(node->get_left_ptr() != NULL) {
      /* Left subtree is not NULL.
       * Return the rightmost node of the left subtree 
       */
      Node<int> *curr_node = node->get_left_ptr();
      while(curr_node->get_right_ptr() != NULL) {
        curr_node = curr_node->get_right_ptr();
      }
      return curr_node;
    }
    else {
      /* Left subtree is NULL.
       * Start from root. Move down the tree.
       * Save node when moving right.
       * Inorder predecessor can be NULL.
       */
      Node<int> *succ_node = NULL;
      Node<int> *curr_node = get_root();    //Start from root.

      while(curr_node != NULL) {
        if(node->get_data() < curr_node->get_data()) {
          // Moving to left subtree 
          curr_node = curr_node->get_left_ptr();
        }
        else if(node->get_data() > curr_node->get_data()) {
          // Moving to the right subtree.
          // Save the current node. May be the answer.
          succ_node = curr_node;
          curr_node = curr_node->get_right_ptr();
        }
        else {
          /* Found the node */
          break;
        }
      }
      return succ_node;
    }
  }
}

/*********************************************************************************/
/* Find the inorder sucessor of the node */
Node<int>* Tree_Int::get_inorder_successor(Node<int> *node) {
  if(node == NULL)
    return NULL;

  else {
    if(node->get_right_ptr() != NULL) {
      /* Right subtree is not NULL.
       * Return the leftmost node of the right subtree
       */
      Node<int> *curr_node = node->get_right_ptr();     //Moving to right subtree
      while(curr_node->get_left_ptr() != NULL) {
        curr_node = curr_node->get_left_ptr();
      }
      return curr_node;
    }
    else {
      /* Right subtree is NULL.
       * Start from root. Move down.
       * Save node when moving left.
       * Inorder successor can be NULL.
       */

      Node<int> *succ_node = NULL;
      Node<int> *curr_node = get_root();          // Starting from Root

      while(curr_node != NULL) {
        
        if(node->get_data() > curr_node->get_data()) {
          // Move to right subtree
          curr_node = curr_node->get_right_ptr();
        }
        else if(node->get_data() < curr_node->get_data()){
          //Moving to the left subtree.
          //Save the current node.May be the answer.
          succ_node = curr_node; 
          curr_node = curr_node->get_left_ptr();
        }
        else {
          /* Node found ! */
          break;
        }
      }
      return succ_node;
    }
  }
}

/******************************************************************************************/
/* Check if a node is a leaf node */
bool Tree_Int::is_leaf(Node<int> *node) {
  if((node->get_left_ptr() == NULL) && 
     (node->get_right_ptr() == NULL))
    return true;
  else 
    return false;
}

/****************************************************************************************/
/* Check if a node has only one sibbling */
bool Tree_Int::has_only_one_sibbling(Node<int> *node) {

  if( (node->get_left_ptr() == NULL) && (node->get_right_ptr() != NULL) ||
      (node->get_left_ptr() != NULL) && (node->get_right_ptr() == NULL) )
    return true;
  else 
    return false;
}

/****************************************************************************************/
/* Check if a node has two sibblings */
bool Tree_Int::has_two_sibblings(Node<int> *node) {

  if((node->get_left_ptr() != NULL) &&
     (node->get_right_ptr() != NULL))
    return true;
  else
    return false;
}

/***************************************************************************************/
/* Check if a node is a left child */
bool Tree_Int::is_left_child(Node<int> *node) {
  if(node == NULL)
    return false;

  if(is_root(node))
    return false;
  else 
    return (get_parent(node)->get_left_ptr() == node);
}

/***************************************************************************************/
/* Check if a node is right child */
bool Tree_Int::is_right_child(Node<int> *node) {
  if(node == NULL)
    return false; 

  if(is_root(node))
    return false;
  else 
    return (get_parent(node)->get_right_ptr() == node);
}

/****************************************************************************************/
/* Delete a node from the tree */
bool Tree_Int::delete_node(Node<int>  *node) {

  /* If a node has no child, 
   * simply delete it.
   * If a node has only one child,
   * replace the node by it's child
   * and delete the node. 
   * If a node has two nodes, 
   * choose the inorder predecessor/successor 
   * of the node to be deleted. Replace the node
   * to be deleted with the value of the inorder 
   * predecessor/successor. Then delete the inorder
   * predecessor/successor.
   */

  /* Would require the implementation of the following functions : 
   * 1. get_inorder_predecessor() -- Done
   * 2. get_inorder_successor()   -- Done
   * 3. is_leaf()                 -- Done
   * 4. has_only_one_sibbling()   -- Done
   * 5. has_two_sibblings()       -- Done
   * 6. get_parent()              -- Done
   * 7. is_root()                 -- Done
   * 8. is_right_child()          -- Done
   * 9. is_left_child()           -- Done
   * 10.get_parent()              -- Done
   */

  if(is_leaf(node)) {

    if(is_root(node)) {
      root = NULL;
    }
    else if(is_left_child(node)) {
      get_parent(node)->set_left_ptr(NULL);
    }
    else {
      assert(is_right_child(node));
      get_parent(node)->set_right_ptr(NULL);
    }

    delete node; 
    --tree_size;
    return true;

  } /* is_leaf(node) { ... } */

  else {
    /* Not a leaf node */
    /* Check if it has only one child */
    if(has_only_one_sibbling(node)) {

      if(node->get_left_ptr() != NULL) {

        /* Left child of parent and has only one child node */
        if(is_left_child(node)) {
          /* Set the child of the current node as the
           * child of the current node's parent
           * and then delete current node.
           */
          get_parent(node)->set_left_ptr(node->get_left_ptr());
        }

        /* Right child of parent and has only one child node */
        else if(is_right_child(node)) {
          /* Set the parent's right child as the
           * current node's left child.
           * and then delete the current node.
           */
          get_parent(node)->set_right_ptr(node->get_left_ptr());
        }
        else {
          assert(is_root(node));
          root = node->get_left_ptr();
        }

        delete node; 
        --tree_size;
        return true;

      } /* if(node->get_left_ptr() != NULL) { ... } */

      else {
        /* Node has only one sibling.
         * This node has no left child.(node->get_left_ptr() == NULL)
         * So it needs to have right child.
         */
        assert(node->get_right_ptr() != NULL);
        if(is_left_child(node)) {
          get_parent(node)->set_left_ptr(node->get_right_ptr());
        }
        else if(is_right_child(node)) {
          get_parent(node)->set_right_ptr(node->get_right_ptr());
        }
        else {
          assert(is_root(node));
            root = node->get_right_ptr();
        }

        delete node; 
        --tree_size;
        return true;
      }
    } /* if(has_only_one_sibbling()) { ... } */

    else {
        /* Has two sibblings 
         * So either find the inorder predecessor 
         * or the inorder successor. 
         * Always using one of the two results in an 
         * unbalanced tree
         */

      assert(has_two_sibblings(node));

      Node<int>* inorder_predecessor_or_successor = NULL;

      if(deletion_flag == 0) {
        deletion_flag = 1;
        inorder_predecessor_or_successor = get_inorder_successor(node);
      }
      else {
        deletion_flag = 0;
        inorder_predecessor_or_successor = get_inorder_predecessor(node);
      }

      assert(inorder_predecessor_or_successor != NULL);

      /* Save the data part of the inorder_predecessor_or_successor node */
      int temp = inorder_predecessor_or_successor->get_data();

      /* Now delete the inorder_predecessor_or_successor.
       * This node will either be a leaf node or will have max one child
       */
      delete_node(inorder_predecessor_or_successor);
      node->set_data(temp);  /* Assign data to node */
      return false;
    }

  } /* Not a leaf node */
} /* Node do not point to NULL */

bool Tree_Int::delete_node(int value) {
  Node<int> *node = search_tree(value);
  return (delete_node(node));
}

/*****************************************************************************************/
/* Find the distance between two nodes */
int Tree_Int::node_distance(Node<int> *node1, Node<int> *node2) {

  int loc1,loc2,dist = 0;

  for(int i=0;i<v.size();i++) {
    if(v[i] == node1->get_data())
      loc1 = i;

    if(v[i] == node2->get_data())
      loc2 = i;
  }

  dist = abs(loc1 - loc2);

  return dist;
}

int Tree_Int::node_distance(int val1, int val2) {
  Node<int> *node1 = search_tree(val1);
  Node<int> *node2 = search_tree(val2);

  return (node_distance(node1, node2));
}

/*****************************************************************************************/
/* Print the Contents of the tree */
void Tree_Int::print() {

  inorder();
  cout<<endl<<endl;
}

/******************************************************************************************/
/* Printing the contents to a dot file */
//void Tree_Int::print_to_file() {
  /* Re-implement the inorder traversal method */

  /**ofstream out_file("Tree_Int.dot");
  Node<int> *node = get_root();

  if(node == NULL)
    return;

  else {
    inorder(node->get_left_ptr());
    v.push_back(node->get_data());
    inorder(node->get_right_ptr());
  }

  write_to_file(v);     //Passing the vector to be written to the file.

  return;
}

void write_to_file(vector<int> v) {

  ofstream out_file("Tree_Int.dot");     //Opening the file in output mode.
  assert(out_file.good());               //Check if the input file stream is good.

  out_file << "graph G { "<<endl;       //Print the Graph.
  for(int i=0;i<v.size()-2;i++) {
    out_file >>v[i]>> "--" >>v[i+1]>>endl
             >> v[i+1] >> "--" >>v[i+2]>>endl;
  }

  return;
}
*/
