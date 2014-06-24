/** Write a program to count the no. of leaf nodes in a BST */

#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <cassert>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

/* Listing for the class Node begins */
template <class type>
class Node{
private:
  type data;
  size_t height;
  Node *left;
  Node *right;
  Node *parent;

public:
  /* Constructors */
  Node() :
	  data(0),left(NULL),right(NULL),parent(NULL) {
	    /* Default Construtor */
	  }

  Node(type d) :
	  data(d),left(NULL),right(NULL),parent(NULL) {
	    /* One argument Constructor */
	  }

  /* Getter Functions */
  type 	       get_data	     () const { return data;	}
  size_t       get_height    () const { return height;}
  Node<type>*  get_left_ptr  () const { return left;	}
  Node<type>*  get_right_ptr () const { return right;	}
  Node<type>*  get_parent    () const { return parent;}

  /* Setter Functions */
  void set_data	      (type d)    	    { data = d; return;    }
  void set_height     (size_t h) 	      { height = h; return;  }
  void set_left_ptr   (Node<type> *ptr) { left = ptr; return;  }
  void set_right_ptr  (Node<type> *ptr) { right = ptr; return; }
  void set_parent     (Node<type> *ptr) { parent = ptr; return;}

};

#endif //__NODE_H__
