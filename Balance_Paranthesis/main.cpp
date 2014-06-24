#include "tokenizer.h"
#include <stack>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using std::stack;

/* Program entry point */
int main() {
  stack< Token<int> > stk;
  Tokenizer<int> tokenizer(cin);
  bool err_flag = false;

  while(1) {
    cout<<"\nEnter expression : ";
    cout.flush();
    Token<int> curr_token = tokenizer.get_token();

    /* Read tokens till the EOL */
    while(curr_token.get_type() != EOL) {
      if(curr_token.get_type() == Lparen) {
        stk.push(curr_token);
      }
      else if(curr_token.get_type() == Rparen) {
        if(stk.empty()) {
          cerr<<"\nUnbalance Right parenthesis"<<endl;
          err_flag = true;
          cin.ignore(1000,'\n');
          break;
        }
        else {
          /* Remove a corresponding left parenthesis */
          stk.pop();
        }
      }
      else if(curr_token.get_type() == Unknown) {
        cerr<<"\nParse Error !" <<endl;
        err_flag = true;
        break;
      }

      /* Get the next token */
      curr_token = tokenizer.get_token();
   
    } /* while */

    if(!err_flag) {
      cout<<endl<<(stk.empty() ? "\nEqual no. of parenthesis" : "\nUnequal no. of parenthesis" )<<endl;
    }

    err_flag = false;
    tokenizer.clear();
   // stk.clear();
  } /* while(1) { ... } */

  return EXIT_SUCCESS;
}
