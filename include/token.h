#ifndef __TOKEN__
#define __TOKEN__

#include <string>

enum TokenType {
    tok_eof = 257,
    tok_int, 
    tok_void,
    tok_char,
    tok_number,
    tok_string_literal,

    tok_identifier,
    tok_const,
    tok_comma, // ,
    tok_semicolon, // ;
    tok_assign, // =
    tok_plus, // +
    tok_minus, // -
    tok_star, // *
    tok_slash, // /
    tok_mod, // %
    tok_lparen, // (
    tok_rparen, // )
    tok_lbrace, // {
    tok_rbrace, // }
    tok_lbracket, // [
    tok_rbracket, // ]
    tok_lt, // <
    tok_gt, // >
    tok_le, // <=
    tok_ge, // >=
    tok_eq, // ==
    tok_ne, // !=
    tok_and, // &&
    tok_or, // ||
    tok_not, // !
    tok_if, // if
    tok_else, // else
    tok_while, // while
    tok_break, // break
    tok_continue, // continue
    tok_return, // return
    
    tok_unknown
};

#endif