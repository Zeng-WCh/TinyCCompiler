/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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

    int yylex();

    #define yyerror(x) \
    do {\
        fprintf(stderr, "error: %s\n", x); \
    } while(0)

#line 84 "parser.cpp"

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
  YYSYMBOL_tok_number = 6,                 /* tok_number  */
  YYSYMBOL_tok_string_literal = 7,         /* tok_string_literal  */
  YYSYMBOL_tok_identifier = 8,             /* tok_identifier  */
  YYSYMBOL_tok_const = 9,                  /* tok_const  */
  YYSYMBOL_tok_comma = 10,                 /* tok_comma  */
  YYSYMBOL_tok_semicolon = 11,             /* tok_semicolon  */
  YYSYMBOL_tok_assign = 12,                /* tok_assign  */
  YYSYMBOL_tok_plus = 13,                  /* tok_plus  */
  YYSYMBOL_tok_minus = 14,                 /* tok_minus  */
  YYSYMBOL_tok_star = 15,                  /* tok_star  */
  YYSYMBOL_tok_slash = 16,                 /* tok_slash  */
  YYSYMBOL_tok_mod = 17,                   /* tok_mod  */
  YYSYMBOL_tok_lparen = 18,                /* tok_lparen  */
  YYSYMBOL_tok_rparen = 19,                /* tok_rparen  */
  YYSYMBOL_tok_lbrace = 20,                /* tok_lbrace  */
  YYSYMBOL_tok_rbrace = 21,                /* tok_rbrace  */
  YYSYMBOL_tok_lbracket = 22,              /* tok_lbracket  */
  YYSYMBOL_tok_rbracket = 23,              /* tok_rbracket  */
  YYSYMBOL_tok_lt = 24,                    /* tok_lt  */
  YYSYMBOL_tok_gt = 25,                    /* tok_gt  */
  YYSYMBOL_tok_le = 26,                    /* tok_le  */
  YYSYMBOL_tok_ge = 27,                    /* tok_ge  */
  YYSYMBOL_tok_eq = 28,                    /* tok_eq  */
  YYSYMBOL_tok_ne = 29,                    /* tok_ne  */
  YYSYMBOL_tok_and = 30,                   /* tok_and  */
  YYSYMBOL_tok_or = 31,                    /* tok_or  */
  YYSYMBOL_tok_not = 32,                   /* tok_not  */
  YYSYMBOL_tok_if = 33,                    /* tok_if  */
  YYSYMBOL_tok_else = 34,                  /* tok_else  */
  YYSYMBOL_tok_while = 35,                 /* tok_while  */
  YYSYMBOL_tok_break = 36,                 /* tok_break  */
  YYSYMBOL_tok_continue = 37,              /* tok_continue  */
  YYSYMBOL_tok_return = 38,                /* tok_return  */
  YYSYMBOL_tok_unknown = 39,               /* tok_unknown  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_CompUnits = 41,                 /* CompUnits  */
  YYSYMBOL_CompUnit = 42,                  /* CompUnit  */
  YYSYMBOL_Decl = 43,                      /* Decl  */
  YYSYMBOL_ConstDecl = 44,                 /* ConstDecl  */
  YYSYMBOL_ConstDefs = 45,                 /* ConstDefs  */
  YYSYMBOL_ConstDef = 46,                  /* ConstDef  */
  YYSYMBOL_ConstSelector = 47,             /* ConstSelector  */
  YYSYMBOL_ConstInitVal = 48,              /* ConstInitVal  */
  YYSYMBOL_ConstInits = 49,                /* ConstInits  */
  YYSYMBOL_VarDecl = 50,                   /* VarDecl  */
  YYSYMBOL_VarDecls = 51,                  /* VarDecls  */
  YYSYMBOL_VarDefs = 52,                   /* VarDefs  */
  YYSYMBOL_VarDef = 53,                    /* VarDef  */
  YYSYMBOL_InitVal = 54,                   /* InitVal  */
  YYSYMBOL_Inits = 55,                     /* Inits  */
  YYSYMBOL_FuncDef = 56,                   /* FuncDef  */
  YYSYMBOL_Params = 57,                    /* Params  */
  YYSYMBOL_Param = 58,                     /* Param  */
  YYSYMBOL_Block = 59,                     /* Block  */
  YYSYMBOL_BlockItems = 60,                /* BlockItems  */
  YYSYMBOL_BlockItem = 61,                 /* BlockItem  */
  YYSYMBOL_Stmt = 62,                      /* Stmt  */
  YYSYMBOL_Exp = 63,                       /* Exp  */
  YYSYMBOL_Cond = 64,                      /* Cond  */
  YYSYMBOL_LVal = 65,                      /* LVal  */
  YYSYMBOL_66_1 = 66,                      /* $@1  */
  YYSYMBOL_LVals = 67,                     /* LVals  */
  YYSYMBOL_PrimaryExp = 68,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 69,                  /* UnaryExp  */
  YYSYMBOL_Args = 70,                      /* Args  */
  YYSYMBOL_MulExp = 71,                    /* MulExp  */
  YYSYMBOL_AddExp = 72,                    /* AddExp  */
  YYSYMBOL_RelExp = 73,                    /* RelExp  */
  YYSYMBOL_EqExp = 74,                     /* EqExp  */
  YYSYMBOL_LAndExp = 75,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 76,                    /* LOrExp  */
  YYSYMBOL_ConstExp = 77                   /* ConstExp  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

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
static const yytype_uint8 yyrline[] =
{
       0,    39,    39,    44,    52,    57,    64,    69,    77,    84,
      89,    97,    98,   102,   108,   115,   116,   117,   120,   121,
     124,   126,   127,   130,   131,   134,   135,   136,   137,   140,
     141,   142,   145,   146,   149,   150,   151,   152,   155,   156,
     159,   160,   161,   164,   165,   168,   169,   172,   173,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     189,   191,   193,   193,   194,   196,   197,   200,   201,   202,
     204,   205,   206,   207,   208,   209,   212,   213,   216,   217,
     218,   219,   222,   223,   224,   227,   228,   229,   230,   231,
     234,   235,   236,   239,   240,   243,   244,   247
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
  "tok_char", "tok_number", "tok_string_literal", "tok_identifier",
  "tok_const", "tok_comma", "tok_semicolon", "tok_assign", "tok_plus",
  "tok_minus", "tok_star", "tok_slash", "tok_mod", "tok_lparen",
  "tok_rparen", "tok_lbrace", "tok_rbrace", "tok_lbracket", "tok_rbracket",
  "tok_lt", "tok_gt", "tok_le", "tok_ge", "tok_eq", "tok_ne", "tok_and",
  "tok_or", "tok_not", "tok_if", "tok_else", "tok_while", "tok_break",
  "tok_continue", "tok_return", "tok_unknown", "$accept", "CompUnits",
  "CompUnit", "Decl", "ConstDecl", "ConstDefs", "ConstDef",
  "ConstSelector", "ConstInitVal", "ConstInits", "VarDecl", "VarDecls",
  "VarDefs", "VarDef", "InitVal", "Inits", "FuncDef", "Params", "Param",
  "Block", "BlockItems", "BlockItem", "Stmt", "Exp", "Cond", "LVal", "$@1",
  "LVals", "PrimaryExp", "UnaryExp", "Args", "MulExp", "AddExp", "RelExp",
  "EqExp", "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
#endif

#define YYPACT_NINF (-149)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      95,    12,    15,    24,   200,  -149,  -149,  -149,  -149,  -149,
      66,    82,  -149,    21,    46,  -149,  -149,    10,    44,     9,
     227,    16,    47,    48,  -149,    11,    29,   131,  -149,  -149,
       3,   227,   227,   227,    69,   227,  -149,  -149,  -149,  -149,
    -149,   115,   112,    53,    86,    75,  -149,   112,   113,   227,
      44,  -149,    86,   109,    89,   227,    41,    46,  -149,   202,
     227,  -149,    64,  -149,  -149,   124,  -149,  -149,    45,  -149,
     227,   227,   227,   227,   227,   134,   102,  -149,   156,    86,
    -149,   138,  -149,  -149,    86,   193,  -149,  -149,   154,    89,
     227,  -149,  -149,  -149,   114,   171,   227,  -149,    44,  -149,
    -149,  -149,  -149,   115,   115,   179,    48,  -149,  -149,   161,
     165,   194,   201,   218,  -149,  -149,   149,  -149,  -149,   206,
     207,  -149,  -149,  -149,  -149,  -149,  -149,    50,  -149,  -149,
     195,   227,  -149,  -149,   199,  -149,   150,   227,   227,  -149,
    -149,  -149,   212,  -149,  -149,  -149,   227,    89,  -149,  -149,
    -149,  -149,    64,   208,   112,   164,   125,   198,   211,   219,
    -149,   226,  -149,   160,   227,   227,   227,   227,   227,   227,
     227,   227,   160,  -149,   196,   112,   112,   112,   112,   164,
     164,   125,   198,  -149,   160,  -149
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     4,     6,     7,     5,
      25,     0,    21,     0,     0,     1,     2,    25,     0,     0,
       0,     0,    27,     0,    20,     0,     0,     0,     9,    69,
      62,     0,     0,     0,     0,     0,    26,    29,    68,    70,
      78,    82,    60,     0,     0,     0,    38,    97,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     8,     0,
       0,    63,    64,    73,    74,     0,    30,    32,     0,    75,
       0,     0,     0,     0,     0,    40,     0,    34,     0,     0,
      23,     0,    28,    36,     0,     0,    11,    15,     0,     0,
       0,    10,    71,    76,     0,     0,     0,    67,     0,    31,
      79,    80,    81,    83,    84,     0,     0,    51,    43,     0,
       0,     0,     0,     0,    47,    52,     0,    45,    48,     0,
      68,    39,    35,    24,    37,    16,    18,     0,    13,    12,
       0,     0,    72,    65,     0,    33,    41,     0,     0,    56,
      57,    59,     0,    44,    46,    50,     0,     0,    17,    14,
      77,    66,    42,     0,    85,    90,    93,    95,    61,     0,
      58,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,    53,    86,    87,    88,    89,    91,
      92,    94,    96,    55,     0,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,   235,   -67,  -149,  -149,   186,  -149,   -79,  -149,
    -149,    63,  -149,   221,   -31,  -149,  -149,   222,   168,   -39,
    -149,   132,  -148,   -17,   111,   -72,  -149,   116,  -149,   -24,
    -149,    91,   -20,     7,    81,    83,  -149,   -18
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    27,    28,    56,    86,   127,
       8,    11,    22,    12,    36,    68,     9,    45,    46,   115,
     116,   117,   118,   119,   153,    38,    61,    62,    39,    40,
      94,    41,    42,   155,   156,   157,   158,    87
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,    37,    48,    67,   120,    77,   126,    63,    64,   114,
     129,    69,    43,    83,    43,   174,    65,    37,    17,    82,
      10,    59,    18,    13,   183,    60,    23,    14,    44,    47,
      52,    81,    20,    37,    47,    47,   185,    88,    49,    25,
     122,    54,    93,    95,   120,   124,   100,   101,   102,   114,
      29,    55,    30,    89,    26,    98,    17,    31,    32,    50,
     147,    75,    33,    90,    34,    47,    99,   135,   162,    47,
      47,   148,   130,    21,    17,    29,    35,    30,    18,   134,
      21,    37,    31,    32,    19,    78,    96,    33,    20,    34,
      66,   120,    23,    24,    79,    29,   142,    30,     1,     2,
     120,    35,    31,    32,     3,   106,    76,    33,    29,    85,
      30,     3,   120,   107,   150,    31,    32,   154,   154,    78,
      33,    35,    76,   108,   131,    73,    74,    47,    84,   161,
      70,    71,    72,   132,    35,   109,    80,   110,   111,   112,
     113,    57,    58,    97,   175,   176,   177,   178,   154,   154,
     154,   154,   106,   168,   169,    29,   105,    30,     3,    43,
     107,   123,    31,    32,   103,   104,    29,    33,    30,    76,
     143,   107,    60,    31,    32,   179,   180,   128,    33,   137,
      76,    35,   109,   138,   110,   111,   112,   113,   164,   165,
     166,   167,    35,   109,   133,   110,   111,   112,   113,    29,
      15,    30,   136,     1,     2,   139,    31,    32,    29,     3,
      30,    33,   140,    85,   125,    31,    32,   145,   149,   146,
      33,    92,   151,   160,    29,    35,    30,   163,   170,   141,
     184,    31,    32,    29,    35,    30,    33,   173,   172,    16,
      31,    32,   171,    91,    51,    33,   121,    53,   144,   159,
      35,   181,   152,     0,   182,     0,     0,     0,     0,    35
};

static const yytype_int16 yycheck[] =
{
      20,    18,    20,    34,    76,    44,    85,    31,    32,    76,
      89,    35,     3,    52,     3,   163,    33,    34,     8,    50,
       8,    18,    12,     8,   172,    22,    10,     3,    19,    49,
      19,    49,    22,    50,    54,    55,   184,    55,    22,    18,
      79,    12,    59,    60,   116,    84,    70,    71,    72,   116,
       6,    22,     8,    12,     8,    10,     8,    13,    14,    12,
      10,     8,    18,    22,    20,    85,    21,    98,   147,    89,
      90,    21,    90,    10,     8,     6,    32,     8,    12,    96,
      17,    98,    13,    14,    18,    10,    22,    18,    22,    20,
      21,   163,    10,    11,    19,     6,   113,     8,     3,     4,
     172,    32,    13,    14,     9,     3,    20,    18,     6,    20,
       8,     9,   184,    11,   131,    13,    14,   137,   138,    10,
      18,    32,    20,    21,    10,    13,    14,   147,    19,   146,
      15,    16,    17,    19,    32,    33,    23,    35,    36,    37,
      38,    10,    11,    19,   164,   165,   166,   167,   168,   169,
     170,   171,     3,    28,    29,     6,    22,     8,     9,     3,
      11,    23,    13,    14,    73,    74,     6,    18,     8,    20,
      21,    11,    22,    13,    14,   168,   169,    23,    18,    18,
      20,    32,    33,    18,    35,    36,    37,    38,    24,    25,
      26,    27,    32,    33,    23,    35,    36,    37,    38,     6,
       0,     8,    23,     3,     4,    11,    13,    14,     6,     9,
       8,    18,    11,    20,    21,    13,    14,    11,    23,    12,
      18,    19,    23,    11,     6,    32,     8,    19,    30,    11,
      34,    13,    14,     6,    32,     8,    18,    11,    19,     4,
      13,    14,    31,    57,    23,    18,    78,    25,   116,   138,
      32,   170,   136,    -1,   171,    -1,    -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     9,    41,    42,    43,    44,    50,    56,
       8,    51,    53,     8,     3,     0,    42,     8,    12,    18,
      22,    51,    52,    10,    11,    18,     8,    45,    46,     6,
       8,    13,    14,    18,    20,    32,    54,    63,    65,    68,
      69,    71,    72,     3,    19,    57,    58,    72,    77,    22,
      12,    53,    19,    57,    12,    22,    47,    10,    11,    18,
      22,    66,    67,    69,    69,    63,    21,    54,    55,    69,
      15,    16,    17,    13,    14,     8,    20,    59,    10,    19,
      23,    77,    54,    59,    19,    20,    48,    77,    77,    12,
      22,    46,    19,    63,    70,    63,    22,    19,    10,    21,
      69,    69,    69,    71,    71,    22,     3,    11,    21,    33,
      35,    36,    37,    38,    43,    59,    60,    61,    62,    63,
      65,    58,    59,    23,    59,    21,    48,    49,    23,    48,
      77,    10,    19,    23,    63,    54,    23,    18,    18,    11,
      11,    11,    63,    21,    61,    11,    12,    10,    21,    23,
      63,    23,    67,    64,    72,    73,    74,    75,    76,    64,
      11,    63,    48,    19,    24,    25,    26,    27,    28,    29,
      30,    31,    19,    11,    62,    72,    72,    72,    72,    73,
      73,    74,    75,    62,    34,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    43,    44,    45,
      45,    46,    46,    47,    47,    48,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    54,
      54,    54,    55,    55,    56,    56,    56,    56,    57,    57,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    64,    66,    65,    65,    67,    67,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    70,    70,    71,    71,
      71,    71,    72,    72,    72,    73,    73,    73,    73,    73,
      74,    74,    74,    75,    75,    76,    76,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     4,     3,     4,     1,     2,     3,     1,     3,
       3,     1,     3,     3,     4,     1,     3,     2,     4,     1,
       2,     3,     1,     3,     5,     6,     5,     6,     1,     3,
       2,     4,     5,     2,     3,     1,     2,     1,     1,     4,
       2,     1,     1,     5,     7,     5,     2,     2,     3,     2,
       1,     1,     0,     2,     2,     3,     4,     3,     1,     1,
       1,     3,     4,     2,     2,     2,     1,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* CompUnits: CompUnits CompUnit  */
#line 39 "./src/parser.y"
                   {
    auto tmp = (CompUnit*) (yyvsp[-1].ast);
    tmp->add_comp_unit((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*)tmp;
}
#line 1301 "parser.cpp"
    break;

  case 3: /* CompUnits: CompUnit  */
#line 44 "./src/parser.y"
           {
    auto tmp = new CompUnit();
    tmp->add_comp_unit((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*)tmp;
}
#line 1311 "parser.cpp"
    break;

  case 4: /* CompUnit: Decl  */
#line 52 "./src/parser.y"
     {
    auto tmp = new CompUnit();
    tmp->add_comp_unit((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*)tmp;
}
#line 1321 "parser.cpp"
    break;

  case 5: /* CompUnit: FuncDef  */
#line 57 "./src/parser.y"
          {
    auto tmp = new CompUnit();
    tmp->add_comp_unit((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*)tmp;
}
#line 1331 "parser.cpp"
    break;

  case 6: /* Decl: ConstDecl  */
#line 64 "./src/parser.y"
                {
    auto tmp = (ConstDecl*) (yyvsp[0].ast);
    auto ret = new Decl(tmp);
    (yyval.ast) = (void*)ret;
}
#line 1341 "parser.cpp"
    break;

  case 7: /* Decl: VarDecl  */
#line 69 "./src/parser.y"
          {
    auto tmp = (VarDecl*) (yyvsp[0].ast);
    auto ret = new Decl(tmp);
    (yyval.ast) = (void*)ret;
}
#line 1351 "parser.cpp"
    break;

  case 8: /* ConstDecl: tok_const tok_int ConstDefs tok_semicolon  */
#line 77 "./src/parser.y"
                                          {
    auto tmp = (ConstDefs*) (yyvsp[-1].ast);
    auto ret = new ConstDecl(tmp);
    (yyval.ast) = (void*) ret;
}
#line 1361 "parser.cpp"
    break;

  case 9: /* ConstDefs: ConstDef  */
#line 84 "./src/parser.y"
         {
    auto tmp = new ConstDefs();
    tmp->add_const((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*)tmp;
}
#line 1371 "parser.cpp"
    break;

  case 10: /* ConstDefs: ConstDefs tok_comma ConstDef  */
#line 89 "./src/parser.y"
                               {
    auto tmp = (ConstDefs*) (yyvsp[-2].ast);
    tmp->add_const((AST*) (yyvsp[0].ast));
    (yyval.ast) = (void*)tmp;
}
#line 1381 "parser.cpp"
    break;

  case 11: /* ConstDef: tok_identifier tok_assign ConstInitVal  */
#line 97 "./src/parser.y"
                                       {}
#line 1387 "parser.cpp"
    break;

  case 12: /* ConstDef: tok_identifier ConstSelector tok_assign ConstInitVal  */
#line 98 "./src/parser.y"
                                                       {}
#line 1393 "parser.cpp"
    break;

  case 13: /* ConstSelector: tok_lbracket ConstExp tok_rbracket  */
#line 102 "./src/parser.y"
                                   {
    auto tmp = (AST*) (yyvsp[-1].ast);
    auto ret = new ConstSelector();
    ret->add_selector(tmp);
    (yyval.ast) = (void*)ret;
}
#line 1404 "parser.cpp"
    break;

  case 14: /* ConstSelector: ConstSelector tok_lbracket ConstExp tok_rbracket  */
#line 108 "./src/parser.y"
                                                   {
    auto tmp = (ConstSelector*) (yyvsp[-3].ast);
    tmp->add_selector((AST*) (yyvsp[-1].ast));
    (yyval.ast) = (void*)tmp;
}
#line 1414 "parser.cpp"
    break;

  case 15: /* ConstInitVal: ConstExp  */
#line 115 "./src/parser.y"
                       {}
#line 1420 "parser.cpp"
    break;

  case 16: /* ConstInitVal: tok_lbrace tok_rbrace  */
#line 116 "./src/parser.y"
                                    {}
#line 1426 "parser.cpp"
    break;

  case 17: /* ConstInitVal: tok_lbrace ConstInits tok_rbrace  */
#line 117 "./src/parser.y"
                                               {}
#line 1432 "parser.cpp"
    break;

  case 18: /* ConstInits: ConstInitVal  */
#line 120 "./src/parser.y"
                         {}
#line 1438 "parser.cpp"
    break;

  case 19: /* ConstInits: ConstInits tok_comma ConstInitVal  */
#line 121 "./src/parser.y"
                                              {}
#line 1444 "parser.cpp"
    break;

  case 20: /* VarDecl: tok_int VarDecls tok_semicolon  */
#line 124 "./src/parser.y"
                                       {}
#line 1450 "parser.cpp"
    break;

  case 21: /* VarDecls: VarDef  */
#line 126 "./src/parser.y"
                 {}
#line 1456 "parser.cpp"
    break;

  case 22: /* VarDecls: VarDecls tok_comma VarDef  */
#line 127 "./src/parser.y"
                                    {}
#line 1462 "parser.cpp"
    break;

  case 23: /* VarDefs: tok_lbracket ConstExp tok_rbracket  */
#line 130 "./src/parser.y"
                                            {}
#line 1468 "parser.cpp"
    break;

  case 24: /* VarDefs: VarDecls tok_lbracket ConstExp tok_rbracket  */
#line 131 "./src/parser.y"
                                                      {}
#line 1474 "parser.cpp"
    break;

  case 25: /* VarDef: tok_identifier  */
#line 134 "./src/parser.y"
                       {}
#line 1480 "parser.cpp"
    break;

  case 26: /* VarDef: tok_identifier tok_assign InitVal  */
#line 135 "./src/parser.y"
                                          {}
#line 1486 "parser.cpp"
    break;

  case 27: /* VarDef: tok_identifier VarDefs  */
#line 136 "./src/parser.y"
                               {}
#line 1492 "parser.cpp"
    break;

  case 28: /* VarDef: tok_identifier VarDefs tok_assign InitVal  */
#line 137 "./src/parser.y"
                                                  {}
#line 1498 "parser.cpp"
    break;

  case 29: /* InitVal: Exp  */
#line 140 "./src/parser.y"
             {}
#line 1504 "parser.cpp"
    break;

  case 30: /* InitVal: tok_lbrace tok_rbrace  */
#line 141 "./src/parser.y"
                               {}
#line 1510 "parser.cpp"
    break;

  case 31: /* InitVal: tok_lbrace Inits tok_rbrace  */
#line 142 "./src/parser.y"
                                     {}
#line 1516 "parser.cpp"
    break;

  case 32: /* Inits: InitVal  */
#line 145 "./src/parser.y"
               {}
#line 1522 "parser.cpp"
    break;

  case 33: /* Inits: Inits tok_comma InitVal  */
#line 146 "./src/parser.y"
                               {}
#line 1528 "parser.cpp"
    break;

  case 34: /* FuncDef: tok_int tok_identifier tok_lparen tok_rparen Block  */
#line 149 "./src/parser.y"
                                                            {}
#line 1534 "parser.cpp"
    break;

  case 35: /* FuncDef: tok_int tok_identifier tok_lparen Params tok_rparen Block  */
#line 150 "./src/parser.y"
                                                                   {}
#line 1540 "parser.cpp"
    break;

  case 36: /* FuncDef: tok_void tok_identifier tok_lparen tok_rparen Block  */
#line 151 "./src/parser.y"
                                                             {}
#line 1546 "parser.cpp"
    break;

  case 37: /* FuncDef: tok_void tok_identifier tok_lparen Params tok_rparen Block  */
#line 152 "./src/parser.y"
                                                                    {}
#line 1552 "parser.cpp"
    break;

  case 38: /* Params: Param  */
#line 155 "./src/parser.y"
              {}
#line 1558 "parser.cpp"
    break;

  case 39: /* Params: Params tok_comma Param  */
#line 156 "./src/parser.y"
                               {}
#line 1564 "parser.cpp"
    break;

  case 40: /* Param: tok_int tok_identifier  */
#line 159 "./src/parser.y"
                              {}
#line 1570 "parser.cpp"
    break;

  case 41: /* Param: tok_int tok_identifier tok_lbracket tok_rbracket  */
#line 160 "./src/parser.y"
                                                        {}
#line 1576 "parser.cpp"
    break;

  case 42: /* Param: tok_int tok_identifier tok_lbracket tok_rbracket LVals  */
#line 161 "./src/parser.y"
                                                              {}
#line 1582 "parser.cpp"
    break;

  case 43: /* Block: tok_lbrace tok_rbrace  */
#line 164 "./src/parser.y"
                             {}
#line 1588 "parser.cpp"
    break;

  case 44: /* Block: tok_lbrace BlockItems tok_rbrace  */
#line 165 "./src/parser.y"
                                        {}
#line 1594 "parser.cpp"
    break;

  case 45: /* BlockItems: BlockItem  */
#line 168 "./src/parser.y"
                      {}
#line 1600 "parser.cpp"
    break;

  case 46: /* BlockItems: BlockItems BlockItem  */
#line 169 "./src/parser.y"
                                 {}
#line 1606 "parser.cpp"
    break;

  case 47: /* BlockItem: Decl  */
#line 172 "./src/parser.y"
                {}
#line 1612 "parser.cpp"
    break;

  case 48: /* BlockItem: Stmt  */
#line 173 "./src/parser.y"
                {}
#line 1618 "parser.cpp"
    break;

  case 49: /* Stmt: LVal tok_assign Exp tok_semicolon  */
#line 176 "./src/parser.y"
                                        {}
#line 1624 "parser.cpp"
    break;

  case 50: /* Stmt: Exp tok_semicolon  */
#line 177 "./src/parser.y"
                        {}
#line 1630 "parser.cpp"
    break;

  case 51: /* Stmt: tok_semicolon  */
#line 178 "./src/parser.y"
                    {}
#line 1636 "parser.cpp"
    break;

  case 52: /* Stmt: Block  */
#line 179 "./src/parser.y"
            {}
#line 1642 "parser.cpp"
    break;

  case 53: /* Stmt: tok_if tok_lparen Cond tok_rparen Stmt  */
#line 180 "./src/parser.y"
                                             {}
#line 1648 "parser.cpp"
    break;

  case 54: /* Stmt: tok_if tok_lparen Cond tok_rparen Stmt tok_else Stmt  */
#line 181 "./src/parser.y"
                                                           {}
#line 1654 "parser.cpp"
    break;

  case 55: /* Stmt: tok_while tok_lparen Cond tok_rparen Stmt  */
#line 182 "./src/parser.y"
                                                {}
#line 1660 "parser.cpp"
    break;

  case 56: /* Stmt: tok_break tok_semicolon  */
#line 183 "./src/parser.y"
                              {}
#line 1666 "parser.cpp"
    break;

  case 57: /* Stmt: tok_continue tok_semicolon  */
#line 184 "./src/parser.y"
                                 {}
#line 1672 "parser.cpp"
    break;

  case 58: /* Stmt: tok_return Exp tok_semicolon  */
#line 185 "./src/parser.y"
                                   {}
#line 1678 "parser.cpp"
    break;

  case 59: /* Stmt: tok_return tok_semicolon  */
#line 186 "./src/parser.y"
                               {}
#line 1684 "parser.cpp"
    break;

  case 60: /* Exp: AddExp  */
#line 189 "./src/parser.y"
            {}
#line 1690 "parser.cpp"
    break;

  case 61: /* Cond: LOrExp  */
#line 191 "./src/parser.y"
             {}
#line 1696 "parser.cpp"
    break;

  case 62: /* $@1: %empty  */
#line 193 "./src/parser.y"
                     {}
#line 1702 "parser.cpp"
    break;

  case 63: /* LVal: tok_identifier $@1  */
#line 193 "./src/parser.y"
                        {}
#line 1708 "parser.cpp"
    break;

  case 64: /* LVal: tok_identifier LVals  */
#line 194 "./src/parser.y"
                           {}
#line 1714 "parser.cpp"
    break;

  case 65: /* LVals: tok_lbracket Exp tok_rbracket  */
#line 196 "./src/parser.y"
                                     {}
#line 1720 "parser.cpp"
    break;

  case 66: /* LVals: LVals tok_lbracket Exp tok_rbracket  */
#line 197 "./src/parser.y"
                                           {}
#line 1726 "parser.cpp"
    break;

  case 67: /* PrimaryExp: tok_lparen Exp tok_rparen  */
#line 200 "./src/parser.y"
                                      {}
#line 1732 "parser.cpp"
    break;

  case 68: /* PrimaryExp: LVal  */
#line 201 "./src/parser.y"
                 {}
#line 1738 "parser.cpp"
    break;

  case 69: /* PrimaryExp: tok_number  */
#line 202 "./src/parser.y"
                       {}
#line 1744 "parser.cpp"
    break;

  case 70: /* UnaryExp: PrimaryExp  */
#line 204 "./src/parser.y"
                     {}
#line 1750 "parser.cpp"
    break;

  case 71: /* UnaryExp: tok_identifier tok_lparen tok_rparen  */
#line 205 "./src/parser.y"
                                               {}
#line 1756 "parser.cpp"
    break;

  case 72: /* UnaryExp: tok_identifier tok_lparen Args tok_rparen  */
#line 206 "./src/parser.y"
                                                    {}
#line 1762 "parser.cpp"
    break;

  case 73: /* UnaryExp: tok_plus UnaryExp  */
#line 207 "./src/parser.y"
                            {}
#line 1768 "parser.cpp"
    break;

  case 74: /* UnaryExp: tok_minus UnaryExp  */
#line 208 "./src/parser.y"
                             {}
#line 1774 "parser.cpp"
    break;

  case 75: /* UnaryExp: tok_not UnaryExp  */
#line 209 "./src/parser.y"
                           {}
#line 1780 "parser.cpp"
    break;

  case 76: /* Args: Exp  */
#line 212 "./src/parser.y"
          {}
#line 1786 "parser.cpp"
    break;

  case 77: /* Args: Args tok_comma Exp  */
#line 213 "./src/parser.y"
                         {}
#line 1792 "parser.cpp"
    break;

  case 78: /* MulExp: UnaryExp  */
#line 216 "./src/parser.y"
                 {}
#line 1798 "parser.cpp"
    break;

  case 79: /* MulExp: MulExp tok_star UnaryExp  */
#line 217 "./src/parser.y"
                                 {}
#line 1804 "parser.cpp"
    break;

  case 80: /* MulExp: MulExp tok_slash UnaryExp  */
#line 218 "./src/parser.y"
                                  {}
#line 1810 "parser.cpp"
    break;

  case 81: /* MulExp: MulExp tok_mod UnaryExp  */
#line 219 "./src/parser.y"
                                {}
#line 1816 "parser.cpp"
    break;

  case 82: /* AddExp: MulExp  */
#line 222 "./src/parser.y"
               {}
#line 1822 "parser.cpp"
    break;

  case 83: /* AddExp: AddExp tok_plus MulExp  */
#line 223 "./src/parser.y"
                               {}
#line 1828 "parser.cpp"
    break;

  case 84: /* AddExp: AddExp tok_minus MulExp  */
#line 224 "./src/parser.y"
                                {}
#line 1834 "parser.cpp"
    break;

  case 85: /* RelExp: AddExp  */
#line 227 "./src/parser.y"
               {}
#line 1840 "parser.cpp"
    break;

  case 86: /* RelExp: RelExp tok_lt AddExp  */
#line 228 "./src/parser.y"
                             {}
#line 1846 "parser.cpp"
    break;

  case 87: /* RelExp: RelExp tok_gt AddExp  */
#line 229 "./src/parser.y"
                             {}
#line 1852 "parser.cpp"
    break;

  case 88: /* RelExp: RelExp tok_le AddExp  */
#line 230 "./src/parser.y"
                             {}
#line 1858 "parser.cpp"
    break;

  case 89: /* RelExp: RelExp tok_ge AddExp  */
#line 231 "./src/parser.y"
                             {}
#line 1864 "parser.cpp"
    break;

  case 90: /* EqExp: RelExp  */
#line 234 "./src/parser.y"
              {}
#line 1870 "parser.cpp"
    break;

  case 91: /* EqExp: EqExp tok_eq RelExp  */
#line 235 "./src/parser.y"
                           {}
#line 1876 "parser.cpp"
    break;

  case 92: /* EqExp: EqExp tok_ne RelExp  */
#line 236 "./src/parser.y"
                           {}
#line 1882 "parser.cpp"
    break;

  case 93: /* LAndExp: EqExp  */
#line 239 "./src/parser.y"
               {}
#line 1888 "parser.cpp"
    break;

  case 94: /* LAndExp: LAndExp tok_and EqExp  */
#line 240 "./src/parser.y"
                               {}
#line 1894 "parser.cpp"
    break;

  case 95: /* LOrExp: LAndExp  */
#line 243 "./src/parser.y"
                {}
#line 1900 "parser.cpp"
    break;

  case 96: /* LOrExp: LOrExp tok_or LAndExp  */
#line 244 "./src/parser.y"
                              {}
#line 1906 "parser.cpp"
    break;

  case 97: /* ConstExp: AddExp  */
#line 247 "./src/parser.y"
                 {}
#line 1912 "parser.cpp"
    break;


#line 1916 "parser.cpp"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 249 "./src/parser.y"
