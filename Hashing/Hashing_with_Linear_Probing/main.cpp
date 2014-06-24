#include "Hashing_with_Linear_Probing.h"

using namespace std;

/* Begining of the Driver Class
 * A.K.A main()
 * The program entry point
 */
int main(int argc, const char *argv[])
{
  hash_map hm;
  bucket b;

  b.name = "Harish"; hm.insert(b);
  b.name = "Navnit"; hm.insert(b);
  b.name = "Arvind"; hm.insert(b);
  hm.print();
  return 0;
}
