#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using std::cout;
using std::cin;
using std::cerr;


/* List of the tokens */
enum Token_Type {

  EOL,                /* End of Line        */
  VALUE,              /* Value              */
  Rparen,             /* Right Parenthesis  */
  Lparen,             /* Left Parenthesis   */
  Plus,               /* Addition           */
  Minus,              /* Subtraction        */
  Div,                /* Division           */
  Mult,               /* Multiplication     */
  Exp,                /* Exponentiation     */
  Unknown             /* Unknown token      */

};

/* The Token class. */
template <class T>
class Token {
private:
  Token_Type token_type;
  T          token_value;

public:
  /* Constructor */
  Token(Token_Type tt = EOL, const T& val = 0)
    :token_type(tt), token_value(val) { }

  Token_Type get_type () const  { return token_type; }
  const T&   get_value() const  { return token_value;}
};

/* The Tokenizer class that tokenizes an input stream */
template <class T>
class Tokenizer {
private:
  std::istream& in;     //Connect the tokenizer to an input stream

public:
  /* Constructors */
  Tokenizer(std::istream& is) : in(is) { }

  Token<T> get_token();               //Fetch the next token from the stream
  void clear() { in.clear();}
};

#include "tokenizer.cpp"

#endif // __TOKENIZER_H__
