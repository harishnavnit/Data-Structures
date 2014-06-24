/* Demonstrate Linear Probing in Hash Tables */

#ifndef __HASHING_WITH_LINEAR_PROBING__
#define __HASHING_WITH_LINEAR_PROBING__

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>

using namespace std;

/* Structure to Represent a bucket in the Hash Table */
struct bucket {
  string name;      //The string to be mapped
};

/* A Trivial hash based map, to map 'string' to 'int' */
class hash_map {

  /* User defined definitions */
  typedef string key;
  typedef size_t index;

private:
  key name;
  const static size_t ARRAY_SIZE = 5; //Prime
  vector< list<bucket> > m;     //Vector of buckets (which can function as a list)

public:
  /* Default Constructor */
  hash_map() {
    m.resize(ARRAY_SIZE);
  }

  /* Compute the hash */
  size_t hash(key);

  /* Check if a certain bucket is empty or filled */
  bool is_empty(size_t new_index);

  /* Insert elements into buckets in the hash table */
  void insert(list<bucket>);

  /* Print the contents of the hash table */
  void print();
};

#include "Hashing_with_Linear_Probing.cpp"

#endif
