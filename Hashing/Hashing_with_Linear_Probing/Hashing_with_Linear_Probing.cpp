#include "Hashing_with_Linear_Probing.h"

using namespace std;

/* Calculate the Hash value */
size_t hash_map::hash(key k) {
  size_t i=0, sum=0;

  for(i=0;i<k.size();i++) {
    sum += k[i];
  }

  return (sum % ARRAY_SIZE);
}

/* Insert elements into the bucket */
void hash_map::insert(bucket b) {

  int curr_location = hash(b.name);

  if( is_empty( m[curr_location] ) )
    m[hash(b.name)].push_back(b);
  else
  {
    /* Bucket contains an element
     * It is filled
     * search the next location
     */
    curr_location += 1;
    insert(b);
  }
}

/* Check if a bucket entry is empty */
bool hash_map::is_empty(bucket b) {

  if( m[hash(b.name)] != " " )
    return true;
  else return false;
}

/* Print the resulting Hash Table */
void hash_map::print() {
  for(size_t i=0; i<m.size(); i++) {
    cout<<"[" << i <<"] : ";
    for(list<bucket>::iterator itr = m[i].begin();
        itr != m[i].end(); itr++) {
      cout<<" ( " <<itr->name << " ) "<<" --> ";
    }
    cout<<endl;
  }
}
