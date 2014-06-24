#include "Hashing.h"

using namespace std;

/* Program entry point */
int main(int argc, const char *argv[])
{
  hash_map hm;
  bucket b;

  b.name = "Harish", b.roll_no = 12051, hm.insert(b);
  b.name = "Gaurav", b.roll_no = 12053, hm.insert(b);
  b.name = "Subbu ", b.roll_no = 12044, hm.insert(b);
  b.name = "Paamb ", b.roll_no = 12052, hm.insert(b);
  b.name = "Ashwin", b.roll_no = 12010, hm.insert(b);
  b.name = "ASK !!", b.roll_no = 12008, hm.insert(b);
  b.name = "Venti ", b.roll_no = 12501, hm.insert(b);
  b.name = "Arjun ", b.roll_no = 12009, hm.insert(b);
  b.name = "Tony  ", b.roll_no = 12047, hm.insert(b);
  b.name = "Neha  ", b.roll_no = 12030, hm.insert(b);
  b.name = "Shilpa", b.roll_no = 12041, hm.insert(b);
  b.name = "Surya ", b.roll_no = 12501, hm.insert(b);
  b.name = "Tina J", b.roll_no = 12047, hm.insert(b);
  b.name = "Darshana", b.roll_no = 12015, hm.insert(b);
  b.name = "Anu V ", b.roll_no = 12006, hm.insert(b);
  b.name = "Anjana ",b.roll_no = 12005, hm.insert(b);
  b.name = "Amrutha",b.roll_no = 12004, hm.insert(b);
 // b.name = "Stop"   ,b.roll_no = 00000, hm.insert(b);
 // b.name = "Pots"   ,b.roll_no = 00001, hm.insert(b);
  hm.print();

  return 0;
}
