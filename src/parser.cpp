/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./src/parser.y"

    #include "ast.h"
    #include "token.h"  
    #include <cstdio> 
    #include <vector>

    int yylex();

    #define yyerror(x) \
    do {\
        fprintf(stderr, "error: %s\n", x); \
    } while(0)

    AST* result = nullptr;

#line 87 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "token.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tok_int = 3,                    /* tok_int  */
  YYSYMBOL_tok_void = 4,                   /* tok_void  */
  YYSYMBOL_tok_char = 5,                   /* tok_char  */
  YYSYMBOL_tok_string_literal = 6,         /* tok_string_literal  */
  YYSYMBOL_tok_const = 7,                  /* tok_const  */
  YYSYMBOL_tok_comma = 8,                  /* tok_comma  */
  YYSYMBOL_tok_semicolon = 9,              /* tok_semicolon  */
  YYSYMBOL_tok_assign = 10,                /* tok_assign  */
  YYSYMBOL_tok_plus = 11,                  /* tok_plus  */
  YYSYMBOL_tok_minus = 12,                 /* tok_minus  */
  YYSYMBOL_tok_star = 13,                  /* tok_star  */
  YYSYMBOL_tok_slash = 14,                 /* tok_slash  */
  YYSYMBOL_tok_mod = 15,                   /* tok_mod  */
  YYSYMBOL_tok_lparen = 16,                /* tok_lparen  */
  YYSYMBOL_tok_rparen = 17,                /* tok_rparen  */
  YYSYMBOL_tok_lbrace = 18,                /* tok_lbrace  */
  YYSYMBOL_tok_rbrace = 19,                /* tok_rbrace  */
  YYSYMBOL_tok_lbracket = 20,              /* tok_lbracket  */
  YYSYMBOL_tok_rbracket = 21,              /* tok_rbracket  */
  YYSYMBOL_tok_lt = 22,                    /* tok_lt  */
  YYSYMBOL_tok_gt = 23,                    /* tok_gt  */
  YYSYMBOL_tok_le = 24,                    /* tok_le  */
  YYSYMBOL_tok_ge = 25,                    /* tok_ge  */
  YYSYMBOL_tok_eq = 26,                    /* tok_eq  */
  YYSYMBOL_tok_ne = 27,                    /* tok_ne  */
  YYSYMBOL_tok_if = 28,                    /* tok_if  */
  YYSYMBOL_tok_and = 29,                   /* tok_and  */
  YYSYMBOL_tok_or = 30,                    /* tok_or  */
  YYSYMBOL_tok_not = 31,                   /* tok_not  */
  YYSYMBOL_tok_else = 32,                  /* tok_else  */
  YYSYMBOL_tok_while = 33,                 /* tok_while  */
  YYSYMBOL_tok_break = 34,                 /* tok_break  */
  YYSYMBOL_tok_continue = 35,              /* tok_continue  */
  YYSYMBOL_tok_return = 36,                /* tok_return  */
  YYSYMBOL_tok_unknown = 37,               /* tok_unknown  */
  YYSYMBOL_tok_identifier = 38,            /* tok_identifier  */
  YYSYMBOL_tok_number = 39,                /* tok_number  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_Program = 41,                   /* Program  */
  YYSYMBOL_CompUnits = 42,                 /* CompUnits  */
  YYSYMBOL_CompUnit = 43,                  /* CompUnit  */
  YYSYMBOL_Decl = 44,                      /* Decl  */
  YYSYMBOL_ConstDecl = 45,                 /* ConstDecl  */
  YYSYMBOL_ConstDecls = 46,                /* ConstDecls  */
  YYSYMBOL_ConstDef = 47,                  /* ConstDef  */
  YYSYMBOL_ConstSelector = 48,             /* ConstSelector  */
  YYSYMBOL_ConstInitVal = 49,              /* ConstInitVal  */
  YYSYMBOL_ConstInits = 50,                /* ConstInits  */
  YYSYMBOL_VarDecl = 51,                   /* VarDecl  */
  YYSYMBOL_VarDecls = 52,                  /* VarDecls  */
  YYSYMBOL_VarDef = 53,                    /* VarDef  */
  YYSYMBOL_InitVal = 54,                   /* InitVal  */
  YYSYMBOL_InitVals = 55,                  /* InitVals  */
  YYSYMBOL_FuncDef = 56,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 57,               /* FuncFParams  */
  YYSYMBOL_FuncFParamList = 58,            /* FuncFParamList  */
  YYSYMBOL_FuncFParam = 59,                /* FuncFParam  */
  YYSYMBOL_FuncFParamDim = 60,             /* FuncFParamDim  */
  YYSYMBOL_Block = 61,                     /* Block  */
  YYSYMBOL_BlockItems = 62,                /* BlockItems  */
  YYSYMBOL_BlockItem = 63,                 /* BlockItem  */
  YYSYMBOL_Stmt = 64,                      /* Stmt  */
  YYSYMBOL_Exp = 65,                       /* Exp  */
  YYSYMBOL_Cond = 66,                      /* Cond  */
  YYSYMBOL_LVal = 67,                      /* LVal  */
  YYSYMBOL_LValSelector = 68,              /* LValSelector  */
  YYSYMBOL_PrimaryExp = 69,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 70,                  /* UnaryExp  */
  YYSYMBOL_FuncRParams = 71,               /* FuncRParams  */
  YYSYMBOL_MulExp = 72,                    /* MulExp  */
  YYSYMBOL_AddExp = 73,                    /* AddExp  */
  YYSYMBOL_RelExp = 74,                    /* RelExp  */
  YYSYMBOL_EqExp = 75,                     /* EqExp  */
  YYSYMBOL_LAndExp = 76,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 77,                    /* LOrExp  */
  YYSYMBOL_ConstExp = 78                   /* ConstExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    46,    46,    50,    55,    62,    65,    70,    75,    82,
      90,    95,   102,   112,   115,   123,   128,   132,   139,   144,
     150,   157,   162,   168,   175,   184,   189,   194,   202,   207,
     213,   222,   233,   237,   243,   248,   254,   259,   273,   277,
     283,   290,   294,   300,   304,   310,   316,   319,   323,   327,
     333,   340,   346,   349,   352,   355,   360,   364,   368,   378,
     382,   389,   392,   395,   400,   403,   410,   413,   416,   421,
     424,   429,   436,   439,   442,   445,   450,   453,   456,   461,
     464,   467,   470,   473,   478,   481,   484,   489,   492,   497,
     500,   505
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tok_int", "tok_void",
  "tok_char", "tok_string_literal", "tok_const", "tok_comma",
  "tok_semicolon", "tok_assign", "tok_plus", "tok_minus", "tok_star",
  "tok_slash", "tok_mod", "tok_lparen", "tok_rparen", "tok_lbrace",
  "tok_rbrace", "tok_lbracket", "tok_rbracket", "tok_lt", "tok_gt",
  "tok_le", "tok_ge", "tok_eq", "tok_ne", "tok_if", "tok_and", "tok_or",
  "tok_not", "tok_else", "tok_while", "tok_break", "tok_continue",
  "tok_return", "tok_unknown", "tok_identifier", "tok_number", "$accept",
  "Program", "CompUnits", "CompUnit", "Decl", "ConstDecl", "ConstDecls",
  "ConstDef", "ConstSelector", "ConstInitVal", "ConstInits", "VarDecl",
  "VarDecls", "VarDef", "InitVal", "InitVals", "FuncDef", "FuncFParams",
  "FuncFParamList", "FuncFParam", "FuncFParamDim", "Block", "BlockItems",
  "BlockItem", "Stmt", "Exp", "Cond", "LVal", "LValSelector", "PrimaryExp",
  "UnaryExp", "FuncRParams", "MulExp", "AddExp", "RelExp", "EqExp",
  "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -25,   -12,    30,    35,     4,  -135,  -135,  -135,  -135,
    -135,    37,    96,  -135,    46,    13,  -135,  -135,    63,    44,
      33,  -135,    63,  -135,   103,  -135,    38,    51,    70,  -135,
     124,   136,  -135,  -135,    69,    45,    13,  -135,    78,    88,
      63,   136,   136,   136,    91,   136,    92,  -135,  -135,  -135,
    -135,  -135,  -135,   110,   138,   138,   100,    88,   127,  -135,
     107,  -135,  -135,  -135,  -135,  -135,   120,  -135,  -135,    24,
    -135,   136,   112,   136,   136,   136,   136,   136,  -135,  -135,
     115,  -135,  -135,  -135,     3,  -135,   124,  -135,  -135,    12,
     136,  -135,  -135,  -135,   110,   110,  -135,  -135,    42,   121,
      33,  -135,  -135,   128,   135,   152,   155,    36,  -135,  -135,
    -135,  -135,   161,   162,  -135,   136,  -135,   150,   127,  -135,
     136,   136,   136,  -135,  -135,  -135,   164,  -135,   136,  -135,
    -135,  -135,   156,   159,   138,    60,   130,   149,   151,   163,
    -135,   170,  -135,    61,   136,   136,   136,   136,   136,   136,
     136,   136,    61,  -135,   153,   138,   138,   138,   138,    60,
      60,   130,   149,  -135,    61,  -135
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     3,     5,     7,     8,
       6,    13,     0,    21,     0,     0,     1,     4,    32,    23,
       0,    20,    32,    13,     0,    10,     0,     0,    33,    34,
       0,     0,    13,    22,     0,     0,     0,     9,    36,     0,
       0,     0,     0,     0,     0,     0,    59,    63,    24,    25,
      62,    64,    72,    76,    56,    91,     0,     0,     0,    11,
       0,    41,    30,    35,    66,    67,     0,    26,    28,     0,
      68,    69,    58,     0,     0,     0,     0,     0,    14,    31,
       0,    12,    15,    38,     0,    61,     0,    27,    70,     0,
       0,    73,    74,    75,    77,    78,    16,    18,     0,    37,
       0,    46,    40,     0,     0,     0,     0,     0,    44,    48,
      42,    43,     0,    62,    29,     0,    65,     0,     0,    17,
       0,     0,     0,    52,    53,    55,     0,    47,     0,    71,
      60,    19,     0,     0,    79,    84,    87,    89,    57,     0,
      54,     0,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,    49,    81,    80,    83,    82,    85,
      86,    88,    90,    51,     0,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,   177,    99,  -135,  -135,   148,   165,   -78,
    -135,  -135,  -135,   166,   -40,  -135,  -135,   167,  -135,   147,
    -135,   -34,  -135,  -135,  -134,   -27,    68,   -83,  -135,  -135,
     -17,  -135,    83,   -31,    20,    41,    43,  -135,   168
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    24,    25,    19,    81,
      98,     9,    12,    13,    48,    69,    10,    27,    28,    29,
      99,   109,    84,   110,   111,   112,   133,    50,    72,    51,
      52,    89,    53,    54,   135,   136,   137,   138,    82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,   113,    97,    49,    68,    62,   100,     1,     2,   154,
       3,     3,   101,    11,    41,    42,    66,    49,   163,    43,
     115,    61,   102,    79,    64,    65,    14,    55,    70,   116,
     165,   103,    86,    15,    45,    16,   104,   105,   106,   107,
     131,    46,    47,    87,    88,   125,   114,    41,    42,    55,
     118,    23,    43,    18,    30,    58,    91,    92,    93,    49,
     113,   119,    22,   117,    31,    31,    26,    45,    39,   113,
     101,    32,    41,    42,    46,    47,    38,    43,    40,    61,
     126,   113,   144,   145,   146,   147,    57,    55,   129,   103,
     134,   134,    45,   132,   104,   105,   106,   107,    60,    46,
      47,   141,    41,    42,    20,    21,    61,    43,    71,    44,
      67,    36,    37,   155,   156,   157,   158,   134,   134,   134,
     134,    78,    45,    73,    74,    75,    41,    42,    83,    46,
      47,    43,    90,    80,    96,    41,    42,    85,    41,    42,
      43,   120,    44,    43,   121,    80,    45,    41,    42,    76,
      77,   122,    43,    46,    47,    45,   148,   149,    45,    94,
      95,   123,    46,    47,   124,    46,    47,    45,   159,   160,
     127,   130,   128,   140,    46,    47,   143,   142,   150,   153,
     152,   151,    17,   108,    59,   164,    33,    63,    35,    34,
     139,   161,     0,     0,   162,     0,     0,     0,     0,    56
};

static const yytype_int16 yycheck[] =
{
      31,    84,    80,    30,    44,    39,     3,     3,     4,   143,
       7,     7,     9,    38,    11,    12,    43,    44,   152,    16,
       8,    18,    19,    57,    41,    42,    38,    58,    45,    17,
     164,    28,     8,     3,    31,     0,    33,    34,    35,    36,
     118,    38,    39,    19,    71,     9,    86,    11,    12,    80,
       8,    38,    16,    16,    10,    10,    73,    74,    75,    86,
     143,    19,    16,    90,    20,    20,     3,    31,    17,   152,
       9,    38,    11,    12,    38,    39,    38,    16,     8,    18,
     107,   164,    22,    23,    24,    25,    17,   118,   115,    28,
     121,   122,    31,   120,    33,    34,    35,    36,    20,    38,
      39,   128,    11,    12,     8,     9,    18,    16,    16,    18,
      19,     8,     9,   144,   145,   146,   147,   148,   149,   150,
     151,    21,    31,    13,    14,    15,    11,    12,    21,    38,
      39,    16,    20,    18,    19,    11,    12,    17,    11,    12,
      16,    20,    18,    16,    16,    18,    31,    11,    12,    11,
      12,    16,    16,    38,    39,    31,    26,    27,    31,    76,
      77,     9,    38,    39,     9,    38,    39,    31,   148,   149,
       9,    21,    10,     9,    38,    39,    17,    21,    29,     9,
      17,    30,     5,    84,    36,    32,    20,    40,    23,    22,
     122,   150,    -1,    -1,   151,    -1,    -1,    -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     7,    41,    42,    43,    44,    45,    51,
      56,    38,    52,    53,    38,     3,     0,    43,    16,    48,
       8,     9,    16,    38,    46,    47,     3,    57,    58,    59,
      10,    20,    38,    53,    57,    48,     8,     9,    38,    17,
       8,    11,    12,    16,    18,    31,    38,    39,    54,    65,
      67,    69,    70,    72,    73,    73,    78,    17,    10,    47,
      20,    18,    61,    59,    70,    70,    65,    19,    54,    55,
      70,    16,    68,    13,    14,    15,    11,    12,    21,    61,
      18,    49,    78,    21,    62,    17,     8,    19,    65,    71,
      20,    70,    70,    70,    72,    72,    19,    49,    50,    60,
       3,     9,    19,    28,    33,    34,    35,    36,    44,    61,
      63,    64,    65,    67,    54,     8,    17,    65,     8,    19,
      20,    16,    16,     9,     9,     9,    65,     9,    10,    65,
      21,    49,    65,    66,    73,    74,    75,    76,    77,    66,
       9,    65,    21,    17,    22,    23,    24,    25,    26,    27,
      29,    30,    17,     9,    64,    73,    73,    73,    73,    74,
      74,    75,    76,    64,    32,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    44,    45,
      46,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      51,    52,    52,    53,    53,    54,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    66,    67,    68,
      68,    69,    69,    69,    70,    70,    70,    70,    70,    71,
      71,    71,    72,    72,    72,    72,    73,    73,    73,    74,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    77,
      77,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     4,
       1,     3,     4,     0,     4,     1,     2,     3,     1,     3,
       3,     1,     3,     2,     4,     1,     2,     3,     1,     3,
       6,     6,     0,     1,     1,     3,     2,     5,     0,     4,
       3,     0,     2,     1,     1,     4,     1,     2,     1,     5,
       7,     5,     2,     2,     3,     2,     1,     1,     2,     0,
       4,     3,     1,     1,     1,     4,     2,     2,     2,     0,
       1,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: CompUnits  */
#line 46 "./src/parser.y"
                   {
    result = (AST*) (yyvsp[0].ast);
}
#line 1276 "parser.cpp"
    break;

  case 3: /* CompUnits: CompUnit  */
#line 50 "./src/parser.y"
                    { 
    auto tmp = new CompUnit();
    tmp->add_comp_unit((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
 }
#line 1286 "parser.cpp"
    break;

  case 4: /* CompUnits: CompUnits CompUnit  */
#line 55 "./src/parser.y"
                     {
    auto tmp = (CompUnit*) (yyvsp[-1].ast);
    tmp->add_comp_unit((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1296 "parser.cpp"
    break;

  case 5: /* CompUnit: Decl  */
#line 62 "./src/parser.y"
               {
    (yyval.ast) = (void*) (yyvsp[0].ast);
}
#line 1304 "parser.cpp"
    break;

  case 6: /* CompUnit: FuncDef  */
#line 65 "./src/parser.y"
          {
    (yyval.ast) = (void*) (yyvsp[0].ast);
}
#line 1312 "parser.cpp"
    break;

  case 7: /* Decl: ConstDecl  */
#line 70 "./src/parser.y"
                {
    auto const_ = (ConstDecl*) (yyvsp[0].ast);
    auto tmp = new Decl(const_);
    (yyval.ast) = (void*) tmp;
}
#line 1322 "parser.cpp"
    break;

  case 8: /* Decl: VarDecl  */
#line 75 "./src/parser.y"
          {
    auto var = (VarDecl*) (yyvsp[0].ast);
    auto tmp = new Decl(var);
    (yyval.ast) = (void*) tmp;
}
#line 1332 "parser.cpp"
    break;

  case 9: /* ConstDecl: tok_const tok_int ConstDecls tok_semicolon  */
#line 82 "./src/parser.y"
                                                      {
    auto tmp = ((ConstDecls*) (yyvsp[-1].ast))->_const_decls;
    auto const_ = new ConstDecl(tmp);
    (yyval.ast) = (void*) const_;
    delete (ConstDecls*)(yyvsp[-1].ast);
}
#line 1343 "parser.cpp"
    break;

  case 10: /* ConstDecls: ConstDef  */
#line 90 "./src/parser.y"
                     {
    auto tmp = new ConstDecls();
    tmp->add_const_decl((ConstDef*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1353 "parser.cpp"
    break;

  case 11: /* ConstDecls: ConstDecls tok_comma ConstDef  */
#line 95 "./src/parser.y"
                                {
    auto tmp = (ConstDecls*) (yyvsp[-2].ast);
    tmp->add_const_decl((ConstDef*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1363 "parser.cpp"
    break;

  case 12: /* ConstDef: tok_identifier ConstSelector tok_assign ConstInitVal  */
#line 102 "./src/parser.y"
                                                               {
    std::string name((yyvsp[-3].strVal));
    delete (yyvsp[-3].strVal);
    auto selector = (ConstSelector*) (yyvsp[-2].ast);
    auto init_val = (ConstInitVal*) (yyvsp[0].ast);
    auto tmp = new ConstDef(name, selector, init_val);
    (yyval.ast) = (void*) tmp;
}
#line 1376 "parser.cpp"
    break;

  case 13: /* ConstSelector: %empty  */
#line 112 "./src/parser.y"
               {
    (yyval.ast) = nullptr;
}
#line 1384 "parser.cpp"
    break;

  case 14: /* ConstSelector: ConstSelector tok_lbracket ConstExp tok_rbracket  */
#line 115 "./src/parser.y"
                                                   {
    auto tmp = (ConstSelector*) (yyvsp[-3].ast);
    if (tmp == nullptr)
        tmp = new ConstSelector();
    tmp->add_selector((ConstExp*) (yyvsp[-1].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1396 "parser.cpp"
    break;

  case 15: /* ConstInitVal: ConstExp  */
#line 123 "./src/parser.y"
                       {
    auto tmp = new ConstInitVal();
    tmp->add_const_val((ConstExp*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1406 "parser.cpp"
    break;

  case 16: /* ConstInitVal: tok_lbrace tok_rbrace  */
#line 128 "./src/parser.y"
                        {
    auto tmp = new ConstInitVal();
    (yyval.ast) = (void*) tmp;
}
#line 1415 "parser.cpp"
    break;

  case 17: /* ConstInitVal: tok_lbrace ConstInits tok_rbrace  */
#line 132 "./src/parser.y"
                                   {
    auto tmp = ((ConstInits*) (yyvsp[-1].ast))->_const_inits;
    auto init_val = new ConstInitVal(tmp);
    (yyval.ast) = (void*) init_val;
    delete (ConstInits*) (yyvsp[-1].ast);
}
#line 1426 "parser.cpp"
    break;

  case 18: /* ConstInits: ConstInitVal  */
#line 139 "./src/parser.y"
                         {
    auto tmp = new ConstInits();
    tmp->add_const_init((ConstInitVal*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1436 "parser.cpp"
    break;

  case 19: /* ConstInits: ConstInits tok_comma ConstInitVal  */
#line 144 "./src/parser.y"
                                    {
    auto tmp = (ConstInits*) (yyvsp[-2].ast);
    tmp->add_const_init((ConstInitVal*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1446 "parser.cpp"
    break;

  case 20: /* VarDecl: tok_int VarDecls tok_semicolon  */
#line 150 "./src/parser.y"
                                        {
    auto tmp = ((VarDecls*) (yyvsp[-1].ast))->_var_decls;
    auto var = new VarDecl(tmp);
    (yyval.ast) = (void*) var;
    delete (VarDecls*) (yyvsp[-1].ast);
}
#line 1457 "parser.cpp"
    break;

  case 21: /* VarDecls: VarDef  */
#line 157 "./src/parser.y"
                 {
    auto tmp = new VarDecls();
    tmp->add_var_decl((VarDef*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1467 "parser.cpp"
    break;

  case 22: /* VarDecls: VarDecls tok_comma VarDef  */
#line 162 "./src/parser.y"
                            {
    auto tmp = (VarDecls*) (yyvsp[-2].ast);
    tmp->add_var_decl((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1477 "parser.cpp"
    break;

  case 23: /* VarDef: tok_identifier ConstSelector  */
#line 168 "./src/parser.y"
                                     {
    std::string ident((yyvsp[-1].strVal));
    delete (yyvsp[-1].strVal);
    auto selector = (ConstSelector*) (yyvsp[0].ast);
    auto tmp = new VarDef(ident, selector, nullptr);
    (yyval.ast) = (void*) tmp;
}
#line 1489 "parser.cpp"
    break;

  case 24: /* VarDef: tok_identifier ConstSelector tok_assign InitVal  */
#line 175 "./src/parser.y"
                                                  {
    std::string ident((yyvsp[-3].strVal));
    delete (yyvsp[-3].strVal);
    auto selector = (ConstSelector*) (yyvsp[-2].ast);
    auto init_val = (InitVal*) (yyvsp[0].ast);
    auto tmp = new VarDef(ident, selector, init_val);
    (yyval.ast) = (void*) tmp;
}
#line 1502 "parser.cpp"
    break;

  case 25: /* InitVal: Exp  */
#line 184 "./src/parser.y"
             {
    auto tmp = new InitVal();
    tmp->add_init_val((Exp*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1512 "parser.cpp"
    break;

  case 26: /* InitVal: tok_lbrace tok_rbrace  */
#line 189 "./src/parser.y"
                        {
    auto tmp = new InitVal();
    tmp->set_array();
    (yyval.ast) = (void*) tmp;
}
#line 1522 "parser.cpp"
    break;

  case 27: /* InitVal: tok_lbrace InitVals tok_rbrace  */
#line 194 "./src/parser.y"
                                 {
    auto tmp = ((InitVals*) (yyvsp[-1].ast))->_init_vals;
    auto init_val = new InitVal(tmp);
    init_val->set_array();
    (yyval.ast) = (void*) init_val;
    delete (InitVals*)(yyvsp[-1].ast);
}
#line 1534 "parser.cpp"
    break;

  case 28: /* InitVals: InitVal  */
#line 202 "./src/parser.y"
                  {
    auto tmp = new InitVals();
    tmp->add_init_val((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1544 "parser.cpp"
    break;

  case 29: /* InitVals: InitVals tok_comma InitVal  */
#line 207 "./src/parser.y"
                             {
    auto tmp = (InitVals*) (yyvsp[-2].ast);
    tmp->add_init_val((InitVal*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1554 "parser.cpp"
    break;

  case 30: /* FuncDef: tok_int tok_identifier tok_lparen FuncFParams tok_rparen Block  */
#line 213 "./src/parser.y"
                                                                        {
    std::string ident((yyvsp[-4].strVal));
    delete (char*)(yyvsp[-4].strVal);
    auto func_type = new FuncType(1);
    auto func_fparams = (FuncFParams*) (yyvsp[-2].ast);
    auto block = (Block*) (yyvsp[0].ast);
    auto tmp = new FuncDef(func_type, ident, func_fparams, block);
    (yyval.ast) = (void*) tmp;
}
#line 1568 "parser.cpp"
    break;

  case 31: /* FuncDef: tok_void tok_identifier tok_lparen FuncFParams tok_rparen Block  */
#line 222 "./src/parser.y"
                                                                  {
    std::string ident((yyvsp[-4].strVal));
    delete (char*)(yyvsp[-4].strVal);
    auto func_type = new FuncType(0);
    auto func_fparams = (FuncFParams*) (yyvsp[-2].ast);
    auto block = (Block*) (yyvsp[0].ast);
    auto tmp = new FuncDef(func_type, ident, func_fparams, block);
    (yyval.ast) = (void*) tmp;
}
#line 1582 "parser.cpp"
    break;

  case 32: /* FuncFParams: %empty  */
#line 233 "./src/parser.y"
             {
    auto tmp = new FuncFParams();
    (yyval.ast) = (void*) tmp;
}
#line 1591 "parser.cpp"
    break;

  case 33: /* FuncFParams: FuncFParamList  */
#line 237 "./src/parser.y"
                 {
    auto t = ((FuncFParamList*) (yyvsp[0].ast))->_params;
    auto tmp = new FuncFParams(t);
    (yyval.ast) = (void*) tmp;
}
#line 1601 "parser.cpp"
    break;

  case 34: /* FuncFParamList: FuncFParam  */
#line 243 "./src/parser.y"
                           {
    auto tmp = new FuncFParamList();
    tmp->add_param((FuncFParam*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1611 "parser.cpp"
    break;

  case 35: /* FuncFParamList: FuncFParamList tok_comma FuncFParam  */
#line 248 "./src/parser.y"
                                      {
    auto tmp = (FuncFParamList*) (yyvsp[-2].ast);
    tmp->add_param((FuncFParam*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1621 "parser.cpp"
    break;

  case 36: /* FuncFParam: tok_int tok_identifier  */
#line 254 "./src/parser.y"
                                   {
    std::string ident((yyvsp[0].strVal));
    delete (char*)(yyvsp[0].strVal);
    (yyval.ast) = (void*) (new FuncFParam(ident));
}
#line 1631 "parser.cpp"
    break;

  case 37: /* FuncFParam: tok_int tok_identifier tok_lbracket tok_rbracket FuncFParamDim  */
#line 259 "./src/parser.y"
                                                                 {
    std::string ident((yyvsp[-3].strVal));
    delete (char*)(yyvsp[-3].strVal);
    auto dim = (Dim*) (yyvsp[0].ast);
    auto _dim = dim->_dim;
    std::vector<AST*> d;
    d.push_back(nullptr);
    for (int i = 0; i < _dim.size(); i++) {
        d.push_back(_dim[i]);
    }
    delete dim;
    (yyval.ast) = (void*) (new FuncFParam(ident, d));
}
#line 1649 "parser.cpp"
    break;

  case 38: /* FuncFParamDim: %empty  */
#line 273 "./src/parser.y"
               {
    auto tmp = new Dim();
    (yyval.ast) = (void*) tmp;
}
#line 1658 "parser.cpp"
    break;

  case 39: /* FuncFParamDim: FuncFParamDim tok_lbracket Exp tok_rbracket  */
#line 277 "./src/parser.y"
                                              {
    auto tmp = (Dim*) (yyvsp[-3].ast);
    tmp->add_dim((AST*) (yyvsp[-1].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1668 "parser.cpp"
    break;

  case 40: /* Block: tok_lbrace BlockItems tok_rbrace  */
#line 283 "./src/parser.y"
                                        {
    auto tmp = ((BlockItems*) (yyvsp[-1].ast)) -> _block_items;
    auto block = new Block(tmp);
    delete (BlockItems*)(yyvsp[-1].ast);
    (yyval.ast) = (void*) block;
}
#line 1679 "parser.cpp"
    break;

  case 41: /* BlockItems: %empty  */
#line 290 "./src/parser.y"
            {
    auto tmp = new BlockItems();
    (yyval.ast) = (void*) tmp;
}
#line 1688 "parser.cpp"
    break;

  case 42: /* BlockItems: BlockItems BlockItem  */
#line 294 "./src/parser.y"
                       {
    auto tmp = (BlockItems*) (yyvsp[-1].ast);
    tmp->add_block_item((BlockItem*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1698 "parser.cpp"
    break;

  case 43: /* BlockItem: Stmt  */
#line 300 "./src/parser.y"
                {
    auto tmp = (Stmt*) (yyvsp[0].ast);
    (yyval.ast) = (void*) (new BlockItem(tmp));
}
#line 1707 "parser.cpp"
    break;

  case 44: /* BlockItem: Decl  */
#line 304 "./src/parser.y"
       {
    auto tmp = (Decl*) (yyvsp[0].ast);
    (yyval.ast) = (void*) (new BlockItem(tmp));
}
#line 1716 "parser.cpp"
    break;

  case 45: /* Stmt: LVal tok_assign Exp tok_semicolon  */
#line 310 "./src/parser.y"
                                        {
    auto lval = (LVal*) (yyvsp[-3].ast);
    auto exp = (Exp*) (yyvsp[-1].ast);
    auto tmp = new Assignment(lval, exp);
    (yyval.ast) = (void*) (new Stmt(tmp));
}
#line 1727 "parser.cpp"
    break;

  case 46: /* Stmt: tok_semicolon  */
#line 316 "./src/parser.y"
                {
    (yyval.ast) = (void*) (new Stmt());
}
#line 1735 "parser.cpp"
    break;

  case 47: /* Stmt: Exp tok_semicolon  */
#line 319 "./src/parser.y"
                    {
    auto exp = (Exp*) (yyvsp[-1].ast);
    (yyval.ast) = (void*) (new Stmt(exp));
}
#line 1744 "parser.cpp"
    break;

  case 48: /* Stmt: Block  */
#line 323 "./src/parser.y"
        {
    auto block = (Block*) (yyvsp[0].ast);
    (yyval.ast) = (void*) (new Stmt(block));
}
#line 1753 "parser.cpp"
    break;

  case 49: /* Stmt: tok_if tok_lparen Cond tok_rparen Stmt  */
#line 327 "./src/parser.y"
                                         {
    auto cond = (Cond*) (yyvsp[-2].ast);
    auto stmt = (Stmt*) (yyvsp[0].ast);
    auto tmp = new IfStmt(cond, stmt);
    (yyval.ast) = (void*) (new Stmt(tmp));
}
#line 1764 "parser.cpp"
    break;

  case 50: /* Stmt: tok_if tok_lparen Cond tok_rparen Stmt tok_else Stmt  */
#line 333 "./src/parser.y"
                                                       {
    auto cond = (Cond*) (yyvsp[-4].ast);
    auto stmt1 = (Stmt*) (yyvsp[-2].ast);
    auto stmt2 = (Stmt*) (yyvsp[0].ast);
    auto tmp = new IfStmt(cond, stmt1, stmt2);
    (yyval.ast) = (void*) (new Stmt(tmp));
}
#line 1776 "parser.cpp"
    break;

  case 51: /* Stmt: tok_while tok_lparen Cond tok_rparen Stmt  */
#line 340 "./src/parser.y"
                                            {
    auto cond = (Cond*) (yyvsp[-2].ast);
    auto stmt = (Stmt*) (yyvsp[0].ast);
    auto tmp = new WhileStmt(cond, stmt);
    (yyval.ast) = (void*) (new Stmt(tmp));
}
#line 1787 "parser.cpp"
    break;

  case 52: /* Stmt: tok_break tok_semicolon  */
#line 346 "./src/parser.y"
                          {
    (yyval.ast) = (void*) (new Stmt(1));
}
#line 1795 "parser.cpp"
    break;

  case 53: /* Stmt: tok_continue tok_semicolon  */
#line 349 "./src/parser.y"
                             {
    (yyval.ast) = (void*) (new Stmt(2));
}
#line 1803 "parser.cpp"
    break;

  case 54: /* Stmt: tok_return Exp tok_semicolon  */
#line 352 "./src/parser.y"
                               {
    (yyval.ast) = (void*) (new Stmt(0, (Exp*) (yyvsp[-1].ast)));
}
#line 1811 "parser.cpp"
    break;

  case 55: /* Stmt: tok_return tok_semicolon  */
#line 355 "./src/parser.y"
                           {
    (yyval.ast) = (void*) (new Stmt(0));
}
#line 1819 "parser.cpp"
    break;

  case 56: /* Exp: AddExp  */
#line 360 "./src/parser.y"
            {
    (yyval.ast) = (void*) (new Exp((AddExp*) (yyvsp[0].ast)));
}
#line 1827 "parser.cpp"
    break;

  case 57: /* Cond: LOrExp  */
#line 364 "./src/parser.y"
             {
    (yyval.ast) = (void*) (new Cond((LOrExp*) (yyvsp[0].ast)));
}
#line 1835 "parser.cpp"
    break;

  case 58: /* LVal: tok_identifier LValSelector  */
#line 368 "./src/parser.y"
                                  {
    std::string ident((yyvsp[-1].strVal));
    delete (char*)(yyvsp[-1].strVal);
    auto tmp = ((LValSelector*) (yyvsp[0].ast)) -> _selectors;
    auto lval = new LVal(ident, tmp);
    (yyval.ast) = (void*) lval;
    delete (yyvsp[0].ast);
}
#line 1848 "parser.cpp"
    break;

  case 59: /* LValSelector: %empty  */
#line 378 "./src/parser.y"
              {
    auto tmp = new LValSelector();
    (yyval.ast) = (void*) tmp;
}
#line 1857 "parser.cpp"
    break;

  case 60: /* LValSelector: LValSelector tok_lbracket Exp tok_rbracket  */
#line 382 "./src/parser.y"
                                             {
    auto tmp = (LValSelector*) (yyvsp[-3].ast);
    tmp->add_selector((AST*) (yyvsp[-1].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1867 "parser.cpp"
    break;

  case 61: /* PrimaryExp: tok_lparen Exp tok_rparen  */
#line 389 "./src/parser.y"
                                      {
    (yyval.ast) = (void*) (new PrimaryExp((Exp*) (yyvsp[-1].ast)));
}
#line 1875 "parser.cpp"
    break;

  case 62: /* PrimaryExp: LVal  */
#line 392 "./src/parser.y"
       {
    (yyval.ast) = (void*) (new PrimaryExp((LVal*) (yyvsp[0].ast)));
}
#line 1883 "parser.cpp"
    break;

  case 63: /* PrimaryExp: tok_number  */
#line 395 "./src/parser.y"
             {
    (yyval.ast) = (void*) (new PrimaryExp((yyvsp[0].intVal)));
}
#line 1891 "parser.cpp"
    break;

  case 64: /* UnaryExp: PrimaryExp  */
#line 400 "./src/parser.y"
                     {
    (yyval.ast) = (void*) (new UnaryExp((PrimaryExp*) (yyvsp[0].ast)));
}
#line 1899 "parser.cpp"
    break;

  case 65: /* UnaryExp: tok_identifier tok_lparen FuncRParams tok_rparen  */
#line 403 "./src/parser.y"
                                                   {
    std::string ident((yyvsp[-3].strVal));
    delete (char*)(yyvsp[-3].strVal);
    auto tmp = ((FuncRParams*) (yyvsp[-1].ast)) -> _params;
    (yyval.ast) = (void*) (new UnaryExp(ident, tmp));
    delete (yyvsp[-1].ast);
}
#line 1911 "parser.cpp"
    break;

  case 66: /* UnaryExp: tok_plus UnaryExp  */
#line 410 "./src/parser.y"
                    {
    (yyval.ast) = (void*) (new UnaryExp('+', (UnaryExp*) (yyvsp[0].ast)));
}
#line 1919 "parser.cpp"
    break;

  case 67: /* UnaryExp: tok_minus UnaryExp  */
#line 413 "./src/parser.y"
                     {
    (yyval.ast) = (void*) (new UnaryExp('-', (UnaryExp*) (yyvsp[0].ast)));
}
#line 1927 "parser.cpp"
    break;

  case 68: /* UnaryExp: tok_not UnaryExp  */
#line 416 "./src/parser.y"
                   {
    (yyval.ast) = (void*) (new UnaryExp('!', (UnaryExp*) (yyvsp[0].ast)));
}
#line 1935 "parser.cpp"
    break;

  case 69: /* FuncRParams: %empty  */
#line 421 "./src/parser.y"
             {
    (yyval.ast) = (void*) (new FuncRParams());
}
#line 1943 "parser.cpp"
    break;

  case 70: /* FuncRParams: Exp  */
#line 424 "./src/parser.y"
      {
    auto tmp = new FuncRParams();
    tmp->add_param((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1953 "parser.cpp"
    break;

  case 71: /* FuncRParams: FuncRParams tok_comma Exp  */
#line 429 "./src/parser.y"
                            {
    auto tmp = (FuncRParams*) (yyvsp[-2].ast);
    tmp->add_param((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*) tmp;
}
#line 1963 "parser.cpp"
    break;

  case 72: /* MulExp: UnaryExp  */
#line 436 "./src/parser.y"
                 {
    (yyval.ast) = (void*) (new MulExp((UnaryExp*) (yyvsp[0].ast)));
}
#line 1971 "parser.cpp"
    break;

  case 73: /* MulExp: MulExp tok_star UnaryExp  */
#line 439 "./src/parser.y"
                           {
    (yyval.ast) = (void*) (new MulExp((MulExp*) (yyvsp[-2].ast), '*', (UnaryExp*) (yyvsp[0].ast)));
}
#line 1979 "parser.cpp"
    break;

  case 74: /* MulExp: MulExp tok_slash UnaryExp  */
#line 442 "./src/parser.y"
                            {
    (yyval.ast) = (void*) (new MulExp((MulExp*) (yyvsp[-2].ast), '/', (UnaryExp*) (yyvsp[0].ast)));
}
#line 1987 "parser.cpp"
    break;

  case 75: /* MulExp: MulExp tok_mod UnaryExp  */
#line 445 "./src/parser.y"
                          {
    (yyval.ast) = (void*) (new MulExp((MulExp*) (yyvsp[-2].ast), '%', (UnaryExp*) (yyvsp[0].ast)));
}
#line 1995 "parser.cpp"
    break;

  case 76: /* AddExp: MulExp  */
#line 450 "./src/parser.y"
               {
    (yyval.ast) = (void*) (new AddExp((MulExp*) (yyvsp[0].ast)));
}
#line 2003 "parser.cpp"
    break;

  case 77: /* AddExp: AddExp tok_plus MulExp  */
#line 453 "./src/parser.y"
                         {
    (yyval.ast) = (void*) (new AddExp((AddExp*) (yyvsp[-2].ast), '+', (MulExp*) (yyvsp[0].ast)));
}
#line 2011 "parser.cpp"
    break;

  case 78: /* AddExp: AddExp tok_minus MulExp  */
#line 456 "./src/parser.y"
                          {
    (yyval.ast) = (void*) (new AddExp((AddExp*) (yyvsp[-2].ast), '-', (MulExp*) (yyvsp[0].ast)));
}
#line 2019 "parser.cpp"
    break;

  case 79: /* RelExp: AddExp  */
#line 461 "./src/parser.y"
               {
    (yyval.ast) = (void*) (new RelExp((AddExp*)(yyvsp[0].ast)));
}
#line 2027 "parser.cpp"
    break;

  case 80: /* RelExp: RelExp tok_gt AddExp  */
#line 464 "./src/parser.y"
                       {
    (yyval.ast) = (void*) (new RelExp((RelExp*)(yyvsp[-2].ast), ">", (AddExp*)(yyvsp[0].ast)));
}
#line 2035 "parser.cpp"
    break;

  case 81: /* RelExp: RelExp tok_lt AddExp  */
#line 467 "./src/parser.y"
                       {
    (yyval.ast) = (void*) (new RelExp((RelExp*)(yyvsp[-2].ast), "<", (AddExp*)(yyvsp[0].ast)));
}
#line 2043 "parser.cpp"
    break;

  case 82: /* RelExp: RelExp tok_ge AddExp  */
#line 470 "./src/parser.y"
                       {
    (yyval.ast) = (void*) (new RelExp((RelExp*)(yyvsp[-2].ast), ">=", (AddExp*)(yyvsp[0].ast)));
}
#line 2051 "parser.cpp"
    break;

  case 83: /* RelExp: RelExp tok_le AddExp  */
#line 473 "./src/parser.y"
                       {
    (yyval.ast) = (void*) (new RelExp((RelExp*)(yyvsp[-2].ast), "<=", (AddExp*)(yyvsp[0].ast)));
}
#line 2059 "parser.cpp"
    break;

  case 84: /* EqExp: RelExp  */
#line 478 "./src/parser.y"
              {
    (yyval.ast) = (void*) (new EqExp((RelExp*)(yyvsp[0].ast)));
}
#line 2067 "parser.cpp"
    break;

  case 85: /* EqExp: EqExp tok_eq RelExp  */
#line 481 "./src/parser.y"
                      {
    (yyval.ast) = (void*) (new EqExp((EqExp*)(yyvsp[-2].ast), "==", (RelExp*)(yyvsp[0].ast)));
}
#line 2075 "parser.cpp"
    break;

  case 86: /* EqExp: EqExp tok_ne RelExp  */
#line 484 "./src/parser.y"
                      {
    (yyval.ast) = (void*) (new EqExp((EqExp*)(yyvsp[-2].ast), "!=", (RelExp*)(yyvsp[0].ast)));
}
#line 2083 "parser.cpp"
    break;

  case 87: /* LAndExp: EqExp  */
#line 489 "./src/parser.y"
               {
    (yyval.ast) = (void*) (new LAndExp((EqExp*)(yyvsp[0].ast)));
}
#line 2091 "parser.cpp"
    break;

  case 88: /* LAndExp: LAndExp tok_and EqExp  */
#line 492 "./src/parser.y"
                        {
    (yyval.ast) = (void*) (new LAndExp((LAndExp*)(yyvsp[-2].ast), (EqExp*)(yyvsp[0].ast)));
}
#line 2099 "parser.cpp"
    break;

  case 89: /* LOrExp: LAndExp  */
#line 497 "./src/parser.y"
                {
    (yyval.ast) = (void*) (new LOrExp((LAndExp*)(yyvsp[0].ast)));
}
#line 2107 "parser.cpp"
    break;

  case 90: /* LOrExp: LOrExp tok_or LAndExp  */
#line 500 "./src/parser.y"
                        {
    (yyval.ast) = (void*) (new LOrExp((LOrExp*)(yyvsp[-2].ast), (LAndExp*)(yyvsp[0].ast)));
}
#line 2115 "parser.cpp"
    break;

  case 91: /* ConstExp: AddExp  */
#line 505 "./src/parser.y"
                 {
    (yyval.ast) = (void*) (new ConstExp((AddExp*) (yyvsp[0].ast)));
}
#line 2123 "parser.cpp"
    break;


#line 2127 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 511 "./src/parser.y"
