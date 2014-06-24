/* Program to demonstrate Hashing */

#ifndef __HASHING_H__
#define __HASHING_H__

#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

struct bucket {
  string name;
  int roll_no;
};

/* A trivial hash based map to map 'string' to 'int'. */
class hash_map {
  typedef string key;
  typedef int val;
  typedef size_t index;

private:
  key name;
  val roll_no;
  const static size_t ARRAY_SIZE = 10;  /* Prime */
  vector< list<bucket> > m;

public:
  hash_map() { m.resize(ARRAY_SIZE);}
  size_t hash(key);
  void insert(bucket b);
  void print();
};

#include "Hashing.cpp"

#endif //__HASHING_H__