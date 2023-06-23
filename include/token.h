/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
# define YYDEBUG 1
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
    tok_string_literal = 261,      /* tok_string_literal  */
    tok_const = 262,               /* tok_const  */
    tok_comma = 263,               /* tok_comma  */
    tok_semicolon = 264,           /* tok_semicolon  */
    tok_assign = 265,              /* tok_assign  */
    tok_plus = 266,                /* tok_plus  */
    tok_minus = 267,               /* tok_minus  */
    tok_star = 268,                /* tok_star  */
    tok_slash = 269,               /* tok_slash  */
    tok_mod = 270,                 /* tok_mod  */
    tok_lparen = 271,              /* tok_lparen  */
    tok_rparen = 272,              /* tok_rparen  */
    tok_lbrace = 273,              /* tok_lbrace  */
    tok_rbrace = 274,              /* tok_rbrace  */
    tok_lbracket = 275,            /* tok_lbracket  */
    tok_rbracket = 276,            /* tok_rbracket  */
    tok_lt = 277,                  /* tok_lt  */
    tok_gt = 278,                  /* tok_gt  */
    tok_le = 279,                  /* tok_le  */
    tok_ge = 280,                  /* tok_ge  */
    tok_eq = 281,                  /* tok_eq  */
    tok_ne = 282,                  /* tok_ne  */
    tok_if = 283,                  /* tok_if  */
    tok_and = 284,                 /* tok_and  */
    tok_or = 285,                  /* tok_or  */
    tok_not = 286,                 /* tok_not  */
    tok_else = 287,                /* tok_else  */
    tok_while = 288,               /* tok_while  */
    tok_break = 289,               /* tok_break  */
    tok_continue = 290,            /* tok_continue  */
    tok_return = 291,              /* tok_return  */
    tok_unknown = 292,             /* tok_unknown  */
    tok_identifier = 293,          /* tok_identifier  */
    tok_number = 294               /* tok_number  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define tok_int 258
#define tok_void 259
#define tok_char 260
#define tok_string_literal 261
#define tok_const 262
#define tok_comma 263
#define tok_semicolon 264
#define tok_assign 265
#define tok_plus 266
#define tok_minus 267
#define tok_star 268
#define tok_slash 269
#define tok_mod 270
#define tok_lparen 271
#define tok_rparen 272
#define tok_lbrace 273
#define tok_rbrace 274
#define tok_lbracket 275
#define tok_rbracket 276
#define tok_lt 277
#define tok_gt 278
#define tok_le 279
#define tok_ge 280
#define tok_eq 281
#define tok_ne 282
#define tok_if 283
#define tok_and 284
#define tok_or 285
#define tok_not 286
#define tok_else 287
#define tok_while 288
#define tok_break 289
#define tok_continue 290
#define tok_return 291
#define tok_unknown 292
#define tok_identifier 293
#define tok_number 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "./src/parser.y"

    int intVal;
    char *strVal;
    void *ast;

#line 151 "token.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKEN_H_INCLUDED  */
