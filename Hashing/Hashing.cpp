#include "Hashing.h"

using namespace std;

/** Function definitions */

/************************************************************/
/* The Hash function */
size_t hash_map::hash(key k) {
  size_t i=0, sum=0;

  for(i=0;i<k.size();i++) {
    sum += k[i];
  }
  return (sum % ARRAY_SIZE);
}
/*************************************************************/
/* Insert elements to the hash table */
void hash_map::insert(bucket b) {
  m[hash(b.name)].push_back(b);
}

/*************************************************************/
/* Print the content of the hash table */
void hash_map::print() {
  for(size_t i = 0; i<m.size(); i++) {
    cout<<"["<< i <<"] : ";
    for(list<bucket>::iterator itr = m[i].begin();
        itr != m[i].end(); itr++) {
      cout<<"("<<itr->name<<" , "
          << itr->roll_no<< " ) "
          << "--> ";
    }

    cout<<endl;
  }
}
