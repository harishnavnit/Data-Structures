#include "Simple_Tokenizer.h"

using namespace std;
using std::stack;

template <class T>
void Input_processor<T> :: parse_input_and_operate() {
  
  for(int i = 0; i<input_value.size(); i++) {
    if(input_value[i] == '(')
      push_to_stack = true;

    if(input_value[i] == ')')
      pop_from_stack = true;
  }
}

/* Program entry point.
 * a.k.a driver function
 * a.k.a the main function
 */ 
int main(int argc, const char *argv[])
{
  Input_processor<string> input_process;      //Instance of the class Input_processor
  stack<string> stk;                          //Object of the STL class

  string temp_value = (string)input_process.get_input_value();    //Type casting the value returned to string

  for(int i=0; i<)
  if(input_process.push_to_stack)
    stk.push(/* Current location in the string */);
  else if(input_process.pop_from_stack)
    stk.pop(/* Pop out the current value from the stack */);

  return 0;
}
