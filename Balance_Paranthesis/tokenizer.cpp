#include "tokenizer.h"

using namespace std;

/* Find the next token,
 * skipping the blanks and return it
 */
template <class T>
Token<T> Tokenizer<T> ::get_token() {
  char ch;
  T value;

  /* Skip the blanks */
  while(in.get(ch) && (ch == ' ') || (ch == '\t')) {
    /* Do nothing !
     * We intend to skip the blank spaces.
     */
  }

  if(in.good()) {
    switch(ch) {
      case '^' : return Exp;
      case '\n': return EOL;
      case '/' : return Div;
      case '*' : return Mult;
      case '+' : return Plus;
      case '-' : return Minus;
      case '(' : return Lparen;
      case ')' : return Rparen;

      default :
          in.putback(ch);   //Putback the char to the input stream

          if(in >> value) {
            return Token<T> (VALUE,value);
          }
          else {
              cin.clear();
              cin.ignore(1000, '\n');
              return Unknown;
          }
    } /* switch(ch) {...} */

    return EOL;
  }
}
