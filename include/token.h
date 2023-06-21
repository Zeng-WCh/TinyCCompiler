/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TOKEN_H_INCLUDED
# define YY_YY_TOKEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tok_int = 258,                 /* tok_int  */
    tok_void = 259,                /* tok_void  */
    tok_char = 260,                /* tok_char  */
    tok_number = 261,              /* tok_number  */
    tok_string_literal = 262,      /* tok_string_literal  */
    tok_identifier = 263,          /* tok_identifier  */
    tok_const = 264,               /* tok_const  */
    tok_comma = 265,               /* tok_comma  */
    tok_semicolon = 266,           /* tok_semicolon  */
    tok_assign = 267,              /* tok_assign  */
    tok_plus = 268,                /* tok_plus  */
    tok_minus = 269,               /* tok_minus  */
    tok_star = 270,                /* tok_star  */
    tok_slash = 271,               /* tok_slash  */
    tok_mod = 272,                 /* tok_mod  */
    tok_lparen = 273,              /* tok_lparen  */
    tok_rparen = 274,              /* tok_rparen  */
    tok_lbrace = 275,              /* tok_lbrace  */
    tok_rbrace = 276,              /* tok_rbrace  */
    tok_lbracket = 277,            /* tok_lbracket  */
    tok_rbracket = 278,            /* tok_rbracket  */
    tok_lt = 279,                  /* tok_lt  */
    tok_gt = 280,                  /* tok_gt  */
    tok_le = 281,                  /* tok_le  */
    tok_ge = 282,                  /* tok_ge  */
    tok_eq = 283,                  /* tok_eq  */
    tok_ne = 284,                  /* tok_ne  */
    tok_and = 285,                 /* tok_and  */
    tok_or = 286,                  /* tok_or  */
    tok_not = 287,                 /* tok_not  */
    tok_if = 288,                  /* tok_if  */
    tok_else = 289,                /* tok_else  */
    tok_while = 290,               /* tok_while  */
    tok_break = 291,               /* tok_break  */
    tok_continue = 292,            /* tok_continue  */
    tok_return = 293,              /* tok_return  */
    tok_unknown = 294              /* tok_unknown  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "./src/parser.y"

    int intVal;
    char *strVal;
    AST *ast;

#line 109 "token.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKEN_H_INCLUDED  */
