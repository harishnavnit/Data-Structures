#ifndef __SIMPLETOKENIZER_H__
#define __SIMPLETOKENIZER_H__

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;


/**********************************************************************/
template <class T>
class Input_processor {
private:
  T input_value;
  bool push_to_stack;
  bool pop_from_stack;

public:
  Input_processor():input_value(), push_to_stack(false), pop_from_stack(false) { }

  T get_input_value() {
    cout<<"\nEnter expression : ";
    cin>>input_value;
  }


  void parse_input_and_operate();
};

/**********************************************************************/

#endif // __SIMPLETOKENIZER_H__
