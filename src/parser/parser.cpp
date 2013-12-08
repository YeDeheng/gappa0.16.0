/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 12 "parser.ypp"

#include <cstdlib>
#include <iostream>

#include "parser/ast.hpp"
#include "proofs/dichotomy.hpp"
#include "parser/parser.h"

#define yyerror(msg) my_yyerror(yylloc, msg)

int yylex(YYSTYPE *yylval_param, YYLTYPE *yylloc_param);

#define error(msg) \
  std::cerr << "Error: " << msg << " at line " << yylloc.first_line << " column " << yylloc.first_column << '\n'
#define warning(msg) \
  std::cerr << "Warning: " << msg << " at line " << yylloc.first_line << " column " << yylloc.first_column << '\n'

int my_yyerror(YYLTYPE &yylloc, char const *errstr) {
    error(errstr);
    return EXIT_FAILURE;
}

#define failure(msg) do {\
  error(msg); \
  YYERROR; \
} while (0)

extern void register_user_rewrite(ast_real const *, ast_real const *, hint_cond_vect *);
extern void generate_graph(ast_prop const *p);
extern void parse_property_tree(property_tree &tree, ast_prop const *p);
extern void test_ringularity(ast_real const *, ast_real const *, bool);
extern int test_rewriting(ast_real const *, ast_real const *, std::string &);
extern void check_approx(ast_real const *);
extern std::set< ast_real const * > free_variables;
extern bool parameter_rfma;

static ast_number const *negative_number(ast_number const *nn) {
  if (nn->base == 0) return nn;
  ast_number n = *nn;
  char &c = n.mantissa[0];
  assert(c == '+');
  c = '-';
  return normalize(n);
}

static function_class const *rounding_mode = NULL;

static ast_real const *rnd_normalize(ast_real const &real) {
  ast_real const *r = normalize(real);
  if (!rounding_mode) return r;
  return normalize(ast_real(real_op(rounding_mode, r)));
}

static unsigned long read_integer_param(ast_number const *n)
{
  return (unsigned long)(atoi(n->mantissa.c_str()) * 2) | 1;
}

#define YYINCLUDED_STDLIB_H



/* Line 268 of yacc.c  */
#line 134 "parser/parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     FUNID = 259,
     VARID = 260,
     IN = 261,
     BY = 262,
     NUMBER = 263,
     SQRT = 264,
     LOG = 265,
     EXP = 266,
     LOG2 = 267,
     EXP2 = 268,
     FMA = 269,
     NE = 270,
     LE = 271,
     GE = 272,
     RDIV = 273,
     FIX = 274,
     FLT = 275,
     IMPL = 276,
     OR = 277,
     AND = 278,
     NOT = 279,
     NEG = 280
   };
#endif
/* Tokens.  */
#define IDENT 258
#define FUNID 259
#define VARID 260
#define IN 261
#define BY 262
#define NUMBER 263
#define SQRT 264
#define LOG 265
#define EXP 266
#define LOG2 267
#define EXP2 268
#define FMA 269
#define NE 270
#define LE 271
#define GE 272
#define RDIV 273
#define FIX 274
#define FLT 275
#define IMPL 276
#define OR 277
#define AND 278
#define NOT 279
#define NEG 280




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 80 "parser.ypp"

  ast_number const	*number;
  ast_ident		*ident;
  ast_real const	*real;
  ast_real_vect		*reals;
  dichotomy_var		dvar;
  dvar_vect		*dvars;
  ast_prop		*prop;
  function_class const	*function;
  function_params	*params;
  unsigned long		param;
  hint_cond		*precond;
  hint_cond_vect	*preconds;



/* Line 293 of yacc.c  */
#line 237 "parser/parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 262 "parser/parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    44,     2,     2,     2,
      32,    34,    27,    25,    33,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      40,    39,    41,    37,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,    38,    31,    45,     2,     2,     2,
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
      29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    11,    15,    22,    29,    37,    41,
      45,    55,    63,    69,    73,    77,    81,    85,    88,    92,
      94,    97,   100,   102,   104,   106,   108,   110,   114,   115,
     119,   122,   124,   127,   128,   134,   141,   144,   147,   151,
     155,   157,   159,   161,   166,   170,   174,   178,   182,   186,
     191,   196,   201,   206,   211,   220,   224,   227,   230,   232,
     236,   238,   242,   244,   248,   254,   256,   260,   264,   268,
     272,   276,   280,   282,   286,   287,   291,   292,   299,   305,
     311,   316
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    67,    -1,    58,    30,    49,    31,
      -1,    59,    16,    50,    -1,    19,    32,    59,    33,    52,
      34,    -1,    20,    32,    59,    33,    51,    34,    -1,    59,
       6,    35,    50,    33,    50,    36,    -1,    59,     6,    37,
      -1,    59,    17,    50,    -1,    59,    18,    59,     6,    35,
      50,    33,    50,    36,    -1,    38,    59,    18,    59,    38,
      16,     8,    -1,    59,    18,    59,     6,    37,    -1,    59,
      39,    59,    -1,    49,    23,    49,    -1,    49,    22,    49,
      -1,    49,    21,    49,    -1,    24,    49,    -1,    32,    49,
      34,    -1,     8,    -1,    25,     8,    -1,    26,     8,    -1,
       8,    -1,    50,    -1,    52,    -1,     3,    -1,    53,    -1,
      54,    33,    53,    -1,    -1,    40,    54,    41,    -1,     4,
      55,    -1,    39,    -1,    56,    39,    -1,    -1,    58,     3,
      57,    59,    42,    -1,    58,    43,     3,    39,    56,    42,
      -1,    58,     5,    -1,    58,     4,    -1,    58,    43,     5,
      -1,    58,    43,     4,    -1,    50,    -1,     5,    -1,     3,
      -1,    56,    32,    60,    34,    -1,    59,    25,    59,    -1,
      59,    26,    59,    -1,    59,    27,    59,    -1,    59,    28,
      59,    -1,    38,    59,    38,    -1,     9,    32,    59,    34,
      -1,    10,    32,    59,    34,    -1,    11,    32,    59,    34,
      -1,    12,    32,    59,    34,    -1,    13,    32,    59,    34,
      -1,    14,    32,    59,    33,    59,    33,    59,    34,    -1,
      32,    59,    34,    -1,    25,    59,    -1,    26,    59,    -1,
      59,    -1,    60,    33,    59,    -1,    50,    -1,    61,    33,
      50,    -1,    59,    -1,    59,     6,    51,    -1,    59,     6,
      32,    61,    34,    -1,    62,    -1,    63,    33,    62,    -1,
      59,    15,    52,    -1,    59,    16,    52,    -1,    59,    17,
      52,    -1,    59,    40,    52,    -1,    59,    41,    52,    -1,
      64,    -1,    65,    33,    64,    -1,    -1,    30,    65,    31,
      -1,    -1,    67,    59,    21,    59,    66,    42,    -1,    67,
      60,    44,    63,    42,    -1,    67,    49,    44,    63,    42,
      -1,    67,    44,    63,    42,    -1,    67,    59,    45,    59,
      42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   127,   130,   135,   137,   139,   141,   142,
     143,   145,   147,   148,   149,   150,   151,   152,   153,   156,
     157,   158,   161,   168,   175,   176,   179,   180,   188,   189,
     192,   205,   206,   213,   214,   225,   231,   232,   233,   234,
     237,   238,   239,   248,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   276,   277,   278,   281,   282,
     289,   290,   293,   294,   295,   298,   299,   306,   307,   308,
     309,   310,   313,   314,   321,   322,   324,   325,   345,   361,
     368,   374
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "FUNID", "VARID", "IN", "BY",
  "NUMBER", "SQRT", "LOG", "EXP", "LOG2", "EXP2", "FMA", "NE", "LE", "GE",
  "RDIV", "FIX", "FLT", "IMPL", "OR", "AND", "NOT", "'+'", "'-'", "'*'",
  "'/'", "NEG", "'{'", "'}'", "'('", "','", "')'", "'['", "']'", "'?'",
  "'|'", "'='", "'<'", "'>'", "';'", "'@'", "'$'", "'~'", "$accept",
  "BLOB", "BLOB1", "PROP", "SNUMBER", "INTEGER", "SINTEGER",
  "FUNCTION_PARAM", "FUNCTION_PARAMS_AUX", "FUNCTION_PARAMS", "FUNCTION",
  "EQUAL", "PROG", "REAL", "REALS", "DPOINTS", "DVAR", "DVARS", "PRECOND",
  "PRECONDS_AUX", "PRECONDS", "HINTS", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    43,    45,    42,    47,   280,
     123,   125,    40,    44,    41,    91,    93,    63,   124,    61,
      60,    62,    59,    64,    36,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    50,
      50,    50,    51,    52,    53,    53,    54,    54,    55,    55,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    63,    63,    64,    64,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    67,    67,
      67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     3,     6,     6,     7,     3,     3,
       9,     7,     5,     3,     3,     3,     3,     2,     3,     1,
       2,     2,     1,     1,     1,     1,     1,     3,     0,     3,
       2,     1,     2,     0,     5,     6,     2,     2,     3,     3,
       1,     1,     1,     4,     3,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     8,     3,     2,     2,     1,     3,
       1,     3,     1,     3,     5,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     0,     3,     0,     6,     5,     5,
       4,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      33,     0,    76,     0,     1,     2,     0,    37,    36,     0,
       0,    42,    28,    41,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,     0,    58,     0,    31,     0,     0,     0,     0,     0,
      39,    38,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    19,     0,     0,    56,    19,    57,     0,
       0,     0,    62,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,     3,     0,    25,     0,     0,
      23,    24,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    55,     0,    48,     0,     0,
      80,    16,    15,    14,     0,    58,     0,     0,     8,     4,
       9,     0,    74,    44,    45,    46,    47,    13,     0,    59,
       0,    34,     0,    20,    21,     0,    29,    49,    50,    51,
      52,    53,     0,     0,     0,     0,    22,     0,    63,    66,
      79,    43,     0,     0,     0,     0,    81,    78,    35,    27,
       0,     0,     0,     0,    60,     0,     0,     0,    12,     0,
      72,     0,    77,     0,     5,     6,     0,     0,    64,     0,
       0,     0,     0,     0,     0,     0,    75,     0,     0,    11,
      61,     7,     0,    67,    68,    69,    70,    71,    73,    54,
       0,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    29,    30,   148,    91,    92,    93,    43,
      31,    36,     3,    38,    33,   165,    63,    64,   170,   171,
     155,     5
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -131
static const yytype_int16 yypact[] =
{
    -131,    30,  -131,     5,  -131,   147,    -1,  -131,  -131,   184,
     115,  -131,    45,  -131,  -131,     0,    62,    71,    74,    78,
     108,   116,   121,   184,   215,   246,   184,   277,   277,     3,
    -131,   138,    96,   -27,  -131,    -2,   277,    77,   318,    97,
    -131,  -131,    58,  -131,   277,   277,   277,   277,   277,   277,
     277,   277,  -131,  -131,   277,   277,  -131,  -131,  -131,   104,
     294,   279,    61,  -131,   -26,   184,   184,   184,   277,   277,
      25,    70,    70,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,  -131,    65,  -131,   165,  -131,   166,   172,
    -131,  -131,  -131,   101,   210,   236,   240,   267,   322,   347,
     351,   360,   333,   137,  -131,  -131,   277,  -131,    -3,   277,
    -131,   155,   167,  -131,    -6,   379,   -22,    70,  -131,  -131,
    -131,   105,   373,    53,    53,  -131,  -131,   379,   206,   379,
      23,  -131,   163,  -131,  -131,    58,  -131,  -131,  -131,  -131,
    -131,  -131,   277,    70,   198,   174,  -131,    70,  -131,  -131,
    -131,  -131,   178,   146,   277,   171,  -131,  -131,  -131,  -131,
     364,   173,   180,   199,  -131,    82,    70,    70,  -131,   314,
    -131,   153,  -131,   277,  -131,  -131,   209,    70,  -131,   185,
     197,    70,    70,    70,    70,    70,  -131,   277,   337,  -131,
    -131,  -131,    70,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
     203,  -131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,    -8,   -38,    98,  -130,   110,  -131,  -131,
      -4,  -131,  -131,    -5,   177,  -131,   134,   -54,    86,  -131,
    -131,  -131
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      32,    37,    35,    12,    90,   146,    81,   109,     6,     7,
       8,    81,   151,   161,   114,    52,   110,    82,    59,    56,
      58,    60,    61,    62,    65,    66,    67,   109,   130,   147,
       4,    84,    44,   119,   120,     9,   150,    83,    34,    94,
      95,    96,    97,    98,    99,   100,   101,    68,    10,   102,
     103,   193,   194,   195,   196,   197,   109,   111,   112,   113,
     117,    87,   118,    62,   115,   157,    14,   108,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    62,    14,   152,
      77,    78,   132,    88,    89,    42,    75,    76,    77,    78,
      75,    76,    77,    78,    45,    88,    89,    90,    65,    66,
      67,   145,    70,    46,    62,    90,    47,   131,    85,   164,
      48,   153,    71,    72,    73,   177,   178,    74,    39,    40,
      41,    75,    76,    77,    78,    65,    66,    67,   179,   180,
      75,    76,    77,    78,   135,    79,    86,   160,   104,   190,
      49,    80,   136,    90,    90,    90,    90,    90,    50,   169,
      11,    12,    13,    51,   200,    14,    15,    16,    17,    18,
      19,    20,    75,    76,    77,    78,    21,    22,   188,    12,
      69,    23,    24,    25,   133,   107,    65,    66,    67,    26,
     134,   167,   169,   168,   186,    27,   187,    11,    12,    13,
      67,    28,    14,    15,    16,    17,    18,    19,    20,    75,
      76,    77,    78,    21,    22,   158,   146,   174,    23,    24,
      25,   166,   163,   172,   175,   176,    26,   189,    11,    12,
      13,   191,    27,    53,    15,    16,    17,    18,    19,    20,
     192,    75,    76,    77,    78,    75,    76,    77,    78,   201,
      24,    25,   162,   149,   137,   159,   116,    54,   156,    11,
      12,    13,     0,    55,    57,    15,    16,    17,    18,    19,
      20,    75,    76,    77,    78,    75,    76,    77,    78,     0,
     138,    24,    25,   198,   139,     0,     0,     0,    54,     0,
      11,    12,    13,     0,    55,    14,    15,    16,    17,    18,
      19,    20,    75,    76,    77,    78,     0,   106,     0,     0,
      70,   140,    24,    25,    75,    76,    77,    78,     0,    54,
      71,    72,    73,     0,     0,    55,     0,   107,     0,    75,
      76,    77,    78,     0,    70,     0,     0,     0,   105,   181,
     182,   183,     0,    79,    71,    72,    73,     0,     0,    75,
      76,    77,    78,    75,    76,    77,    78,    75,    76,    77,
      78,     0,     0,     0,   184,   185,   141,    79,    75,    76,
      77,    78,    75,    76,    77,    78,     0,   105,     0,     0,
       0,   199,    75,    76,    77,    78,    75,    76,    77,    78,
     142,     0,     0,     0,   143,    75,    76,    77,    78,    75,
      76,    77,    78,   144,     0,     0,     0,   173,    75,    76,
      77,    78,     0,   154,    75,    76,    77,    78
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-131))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       5,     9,     6,     4,    42,     8,    33,    33,     3,     4,
       5,    33,    34,   143,    68,    23,    42,    44,    26,    24,
      25,    26,    27,    28,    21,    22,    23,    33,    82,    32,
       0,    36,    32,    71,    72,    30,    42,    39,    39,    44,
      45,    46,    47,    48,    49,    50,    51,    44,    43,    54,
      55,   181,   182,   183,   184,   185,    33,    65,    66,    67,
      35,     3,    37,    68,    69,    42,     8,     6,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     8,   117,
      27,    28,    86,    25,    26,    40,    25,    26,    27,    28,
      25,    26,    27,    28,    32,    25,    26,   135,    21,    22,
      23,   106,     6,    32,   109,   143,    32,    42,    31,   147,
      32,     6,    16,    17,    18,    33,    34,    21,     3,     4,
       5,    25,    26,    27,    28,    21,    22,    23,   166,   167,
      25,    26,    27,    28,    33,    39,    39,   142,    34,   177,
      32,    45,    41,   181,   182,   183,   184,   185,    32,   154,
       3,     4,     5,    32,   192,     8,     9,    10,    11,    12,
      13,    14,    25,    26,    27,    28,    19,    20,   173,     4,
      32,    24,    25,    26,     8,    38,    21,    22,    23,    32,
       8,    35,   187,    37,    31,    38,    33,     3,     4,     5,
      23,    44,     8,     9,    10,    11,    12,    13,    14,    25,
      26,    27,    28,    19,    20,    42,     8,    34,    24,    25,
      26,    33,    38,    42,    34,    16,    32,     8,     3,     4,
       5,    36,    38,     8,     9,    10,    11,    12,    13,    14,
      33,    25,    26,    27,    28,    25,    26,    27,    28,    36,
      25,    26,   144,   109,    34,   135,    69,    32,    42,     3,
       4,     5,    -1,    38,     8,     9,    10,    11,    12,    13,
      14,    25,    26,    27,    28,    25,    26,    27,    28,    -1,
      34,    25,    26,   187,    34,    -1,    -1,    -1,    32,    -1,
       3,     4,     5,    -1,    38,     8,     9,    10,    11,    12,
      13,    14,    25,    26,    27,    28,    -1,    18,    -1,    -1,
       6,    34,    25,    26,    25,    26,    27,    28,    -1,    32,
      16,    17,    18,    -1,    -1,    38,    -1,    38,    -1,    25,
      26,    27,    28,    -1,     6,    -1,    -1,    -1,    34,    15,
      16,    17,    -1,    39,    16,    17,    18,    -1,    -1,    25,
      26,    27,    28,    25,    26,    27,    28,    25,    26,    27,
      28,    -1,    -1,    -1,    40,    41,    34,    39,    25,    26,
      27,    28,    25,    26,    27,    28,    -1,    34,    -1,    -1,
      -1,    34,    25,    26,    27,    28,    25,    26,    27,    28,
      33,    -1,    -1,    -1,    33,    25,    26,    27,    28,    25,
      26,    27,    28,    33,    -1,    -1,    -1,    33,    25,    26,
      27,    28,    -1,    30,    25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    48,    58,     0,    67,     3,     4,     5,    30,
      43,     3,     4,     5,     8,     9,    10,    11,    12,    13,
      14,    19,    20,    24,    25,    26,    32,    38,    44,    49,
      50,    56,    59,    60,    39,    56,    57,    49,    59,     3,
       4,     5,    40,    55,    32,    32,    32,    32,    32,    32,
      32,    32,    49,     8,    32,    38,    59,     8,    59,    49,
      59,    59,    59,    62,    63,    21,    22,    23,    44,    32,
       6,    16,    17,    18,    21,    25,    26,    27,    28,    39,
      45,    33,    44,    39,    59,    31,    39,     3,    25,    26,
      50,    52,    53,    54,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    34,    34,    18,    38,     6,    33,
      42,    49,    49,    49,    63,    59,    60,    35,    37,    50,
      50,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      63,    42,    56,     8,     8,    33,    41,    34,    34,    34,
      34,    34,    33,    33,    33,    59,     8,    32,    51,    62,
      42,    34,    50,     6,    30,    66,    42,    42,    42,    53,
      59,    52,    51,    38,    50,    61,    33,    35,    37,    59,
      64,    65,    42,    33,    34,    34,    16,    33,    34,    50,
      50,    15,    16,    17,    40,    41,    31,    33,    59,     8,
      50,    36,    33,    52,    52,    52,    52,    52,    64,    34,
      50,    36
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1806 of yacc.c  */
#line 127 "parser.ypp"
    { generate_graph((yyvsp[(3) - (4)].prop)); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 131 "parser.ypp"
    {
    real_op const *p = boost::get< real_op const >((yyvsp[(1) - (3)].real));
    (yyval.prop) = new ast_prop(ast_atom_bnd((yyvsp[(1) - (3)].real), (!p || p->type != UOP_ABS) ? NULL : token_zero, (yyvsp[(3) - (3)].number)));
  }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 136 "parser.ypp"
    { (yyval.prop) = new ast_prop(ast_atom_fix((yyvsp[(3) - (6)].real), atoi((yyvsp[(5) - (6)].number)->mantissa.c_str()))); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 138 "parser.ypp"
    { (yyval.prop) = new ast_prop(ast_atom_flt((yyvsp[(3) - (6)].real), atoi((yyvsp[(5) - (6)].number)->mantissa.c_str()))); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 140 "parser.ypp"
    { (yyval.prop) = new ast_prop(ast_atom_bnd((yyvsp[(1) - (7)].real), (yyvsp[(4) - (7)].number), (yyvsp[(6) - (7)].number))); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 141 "parser.ypp"
    { (yyval.prop) = new ast_prop(ast_atom_bnd((yyvsp[(1) - (3)].real), NULL, NULL)); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 142 "parser.ypp"
    { (yyval.prop) = new ast_prop(ast_atom_bnd((yyvsp[(1) - (3)].real), (yyvsp[(3) - (3)].number), NULL)); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 144 "parser.ypp"
    { (yyval.prop) = new ast_prop(ast_atom_rel((yyvsp[(1) - (9)].real), (yyvsp[(3) - (9)].real), (yyvsp[(6) - (9)].number), (yyvsp[(8) - (9)].number))); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 146 "parser.ypp"
    { (yyval.prop) = new ast_prop(ast_atom_rel((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), negative_number((yyvsp[(7) - (7)].number)), (yyvsp[(7) - (7)].number))); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 147 "parser.ypp"
    { (yyval.prop) = new ast_prop(ast_atom_rel((yyvsp[(1) - (5)].real), (yyvsp[(3) - (5)].real), NULL, NULL)); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 148 "parser.ypp"
    { (yyval.prop) = new ast_prop(ast_atom_eql((yyvsp[(1) - (3)].real), (yyvsp[(3) - (3)].real))); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 149 "parser.ypp"
    { (yyval.prop) = new ast_prop((yyvsp[(1) - (3)].prop), PROP_AND,  (yyvsp[(3) - (3)].prop)); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 150 "parser.ypp"
    { (yyval.prop) = new ast_prop((yyvsp[(1) - (3)].prop), PROP_OR,   (yyvsp[(3) - (3)].prop)); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 151 "parser.ypp"
    { (yyval.prop) = new ast_prop((yyvsp[(1) - (3)].prop), PROP_IMPL, (yyvsp[(3) - (3)].prop)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 152 "parser.ypp"
    { (yyval.prop) = new ast_prop((yyvsp[(2) - (2)].prop)); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 153 "parser.ypp"
    { (yyval.prop) = (yyvsp[(2) - (3)].prop); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 156 "parser.ypp"
    { (yyval.number) = (yyvsp[(1) - (1)].number); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 157 "parser.ypp"
    { (yyval.number) = (yyvsp[(2) - (2)].number); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 158 "parser.ypp"
    { (yyval.number) = negative_number((yyvsp[(2) - (2)].number)); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 162 "parser.ypp"
    {
    if ((yyvsp[(1) - (1)].number)->exponent != 0 || (yyvsp[(1) - (1)].number)->mantissa.size() >= 7) failure("the number does not look like an integer");
    (yyval.number) = (yyvsp[(1) - (1)].number);
  }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 169 "parser.ypp"
    {
    if ((yyvsp[(1) - (1)].number)->exponent != 0 || (yyvsp[(1) - (1)].number)->mantissa.size() >= 7) failure("the number does not look like an integer");
    (yyval.number) = (yyvsp[(1) - (1)].number);
  }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 175 "parser.ypp"
    { (yyval.param) = read_integer_param((yyvsp[(1) - (1)].number)); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 176 "parser.ypp"
    { (yyval.param) = reinterpret_cast< unsigned long >((yyvsp[(1) - (1)].ident)); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 179 "parser.ypp"
    { (yyval.params) = new function_params(1, (yyvsp[(1) - (1)].param)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 181 "parser.ypp"
    {
    function_params *p = (yyvsp[(1) - (3)].params);
    p->push_back((yyvsp[(3) - (3)].param));
    (yyval.params) = p;
  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 188 "parser.ypp"
    { (yyval.params) = NULL; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 189 "parser.ypp"
    { (yyval.params) = (yyvsp[(2) - (3)].params); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 193 "parser.ypp"
    {
    ast_ident *r = (yyvsp[(1) - (2)].ident);
    function_class const *f;
    if (function_params *p = (yyvsp[(2) - (2)].params)) {
      f = (*r->fun)(*p);
      delete p;
    } else f = (*r->fun)(function_params());
    if (!f) failure("invalid parameters for " << r->name);
    (yyval.function) = f;
  }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 207 "parser.ypp"
    {
    function_class const *f = (yyvsp[(1) - (2)].function);
    if (f->type != UOP_ID) failure(f->pretty_name() << " is not a rounding operator");
    rounding_mode = f;
  }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 215 "parser.ypp"
    {
    ast_ident *v = (yyvsp[(2) - (5)].ident);
    ast_real const *r = (yyvsp[(4) - (5)].real);
    if (v->type != ID_NONE) failure("the symbol " << (yyvsp[(2) - (5)].ident)->name << " is redefined");
    v->type = ID_VAR;
    v->var = r;
    if (r->name) warning(r->name->name << " is being renamed to " << v->name);
    r->name = v;
    rounding_mode = NULL;
  }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 226 "parser.ypp"
    {
    ast_ident *v = (yyvsp[(3) - (6)].ident);
    v->type = ID_FUN;
    v->fun = new default_function_generator((yyvsp[(5) - (6)].function));
  }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 231 "parser.ypp"
    { failure("the symbol " << (yyvsp[(2) - (2)].ident)->name << " is redefined"); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 232 "parser.ypp"
    { failure("the symbol " << (yyvsp[(2) - (2)].ident)->name << " is redefined"); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 233 "parser.ypp"
    { failure("the symbol " << (yyvsp[(3) - (3)].ident)->name << " is redefined"); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 234 "parser.ypp"
    { failure("the symbol " << (yyvsp[(3) - (3)].ident)->name << " is redefined"); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 237 "parser.ypp"
    { (yyval.real) = normalize(ast_real((yyvsp[(1) - (1)].number))); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 238 "parser.ypp"
    { (yyval.real) = (yyvsp[(1) - (1)].ident)->var; }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 240 "parser.ypp"
    {
    ast_ident *v = (yyvsp[(1) - (1)].ident);
    v->type = ID_VAR;
    ast_real *r = normalize(ast_real(v));
    free_variables.insert(r);
    v->var = r;
    (yyval.real) = r;
  }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 249 "parser.ypp"
    {
    function_class const *f = (yyvsp[(1) - (4)].function);
    ast_real_vect *ops = (yyvsp[(3) - (4)].reals);
    if ((f->type == UOP_ID && ops->size() != 1) ||
        (f->type != UOP_ID && f->type != COP_FMA && ops->size() != 2) ||
        (f->type == COP_FMA && ops->size() != 3))
      failure("incorrect number of arguments when calling " << f->pretty_name());
    (yyval.real) = normalize(ast_real(real_op(f, *ops)));
    delete ops;
  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 259 "parser.ypp"
    { (yyval.real) = rnd_normalize(ast_real(real_op((yyvsp[(1) - (3)].real), BOP_ADD, (yyvsp[(3) - (3)].real)))); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 260 "parser.ypp"
    { (yyval.real) = rnd_normalize(ast_real(real_op((yyvsp[(1) - (3)].real), BOP_SUB, (yyvsp[(3) - (3)].real)))); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 261 "parser.ypp"
    { (yyval.real) = rnd_normalize(ast_real(real_op((yyvsp[(1) - (3)].real), BOP_MUL, (yyvsp[(3) - (3)].real)))); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 262 "parser.ypp"
    { (yyval.real) = rnd_normalize(ast_real(real_op((yyvsp[(1) - (3)].real), BOP_DIV, (yyvsp[(3) - (3)].real)))); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 263 "parser.ypp"
    { (yyval.real) = normalize(ast_real(real_op(UOP_ABS, (yyvsp[(2) - (3)].real)))); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 264 "parser.ypp"
    { (yyval.real) = rnd_normalize(ast_real(real_op(UOP_SQRT, (yyvsp[(3) - (4)].real)))); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 265 "parser.ypp"
    { (yyval.real) = rnd_normalize(ast_real(real_op(UOP_LOG, (yyvsp[(3) - (4)].real)))); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 266 "parser.ypp"
    { (yyval.real) = rnd_normalize(ast_real(real_op(UOP_EXP, (yyvsp[(3) - (4)].real)))); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 267 "parser.ypp"
    { (yyval.real) = rnd_normalize(ast_real(real_op(UOP_LOG2, (yyvsp[(3) - (4)].real)))); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 268 "parser.ypp"
    { (yyval.real) = rnd_normalize(ast_real(real_op(UOP_EXP2, (yyvsp[(3) - (4)].real)))); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 270 "parser.ypp"
    {
    if (!parameter_rfma)
      (yyval.real) = rnd_normalize(ast_real(real_op(normalize(ast_real(real_op((yyvsp[(3) - (8)].real), BOP_MUL, (yyvsp[(5) - (8)].real)))), BOP_ADD, (yyvsp[(7) - (8)].real))));
    else
      (yyval.real) = rnd_normalize(ast_real(real_op((yyvsp[(7) - (8)].real), BOP_ADD, normalize(ast_real(real_op((yyvsp[(3) - (8)].real), BOP_MUL, (yyvsp[(5) - (8)].real)))))));
  }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 276 "parser.ypp"
    { (yyval.real) = (yyvsp[(2) - (3)].real); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 277 "parser.ypp"
    { (yyval.real) = (yyvsp[(2) - (2)].real); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 278 "parser.ypp"
    { (yyval.real) = normalize(ast_real(real_op(UOP_NEG, (yyvsp[(2) - (2)].real)))); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 281 "parser.ypp"
    { (yyval.reals) = new ast_real_vect(1, (yyvsp[(1) - (1)].real)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 283 "parser.ypp"
    {
    (yyvsp[(1) - (3)].reals)->push_back((yyvsp[(3) - (3)].real));
    (yyval.reals) = (yyvsp[(1) - (3)].reals);
  }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 289 "parser.ypp"
    { (yyval.param) = fill_splitter(0, (yyvsp[(1) - (1)].number)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 290 "parser.ypp"
    { (yyval.param) = fill_splitter((yyvsp[(1) - (3)].param), (yyvsp[(3) - (3)].number)); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 293 "parser.ypp"
    { dichotomy_var v = { (yyvsp[(1) - (1)].real), 0 }; (yyval.dvar) = v; }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 294 "parser.ypp"
    { dichotomy_var v = { (yyvsp[(1) - (3)].real), read_integer_param((yyvsp[(3) - (3)].number)) }; (yyval.dvar) = v; }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 295 "parser.ypp"
    { dichotomy_var v = { (yyvsp[(1) - (5)].real), (yyvsp[(4) - (5)].param) }; (yyval.dvar) = v; }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 298 "parser.ypp"
    { (yyval.dvars) = new dvar_vect(1, (yyvsp[(1) - (1)].dvar)); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 300 "parser.ypp"
    {
    (yyvsp[(1) - (3)].dvars)->push_back((yyvsp[(3) - (3)].dvar));
    (yyval.dvars) = (yyvsp[(1) - (3)].dvars);
  }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 306 "parser.ypp"
    { (yyval.precond) = new hint_cond(COND_NE, (yyvsp[(1) - (3)].real), (yyvsp[(3) - (3)].number)); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 307 "parser.ypp"
    { (yyval.precond) = new hint_cond(COND_LE, (yyvsp[(1) - (3)].real), (yyvsp[(3) - (3)].number)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 308 "parser.ypp"
    { (yyval.precond) = new hint_cond(COND_GE, (yyvsp[(1) - (3)].real), (yyvsp[(3) - (3)].number)); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 309 "parser.ypp"
    { (yyval.precond) = new hint_cond(COND_LT, (yyvsp[(1) - (3)].real), (yyvsp[(3) - (3)].number)); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 310 "parser.ypp"
    { (yyval.precond) = new hint_cond(COND_GT, (yyvsp[(1) - (3)].real), (yyvsp[(3) - (3)].number)); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 313 "parser.ypp"
    { (yyval.preconds) = new hint_cond_vect(1, (yyvsp[(1) - (1)].precond)); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 315 "parser.ypp"
    {
    (yyvsp[(1) - (3)].preconds)->push_back((yyvsp[(3) - (3)].precond));
    (yyval.preconds) = (yyvsp[(1) - (3)].preconds);
  }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 321 "parser.ypp"
    { (yyval.preconds) = NULL; }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 322 "parser.ypp"
    { (yyval.preconds) = (yyvsp[(2) - (3)].preconds); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 326 "parser.ypp"
    {
    ast_real const *r1 = (yyvsp[(2) - (6)].real), *r2 = (yyvsp[(4) - (6)].real);
    hint_cond_vect *hc = (yyvsp[(5) - (6)].preconds);
    test_ringularity(r1, r2, !hc);
    std::string info;
    int t = test_rewriting(r1, r2, info);
    if (t == 1) {
      warning("no need for the rewriting");
      std::cerr << "  if one of the following relations is present\n" << info;
    } else if (t == 2) {
      warning("no need for the rewriting");
      if (!info.empty())
        std::cerr << "  if all the following properties can be proved\n" << info;
    }
    check_approx(r1);
    register_user_rewrite(r1, r2, hc);
    register_approx(r1, r2);
    delete hc;
  }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 346 "parser.ypp"
    {
    dichotomy_hint h;
    h.src = *(yyvsp[(4) - (5)].dvars); delete (yyvsp[(4) - (5)].dvars);
    ast_prop *p = NULL;
    for (ast_real_vect::const_iterator i = (yyvsp[(2) - (5)].reals)->begin(), i_end = (yyvsp[(2) - (5)].reals)->end();
         i != i_end; ++i)
    {
      ast_prop *q = new ast_prop(ast_atom_bnd(*i, NULL, NULL));
      if (!p) p = q;
      else p = new ast_prop(p, PROP_AND, q);
    }
    delete (yyvsp[(2) - (5)].reals);
    parse_property_tree(h.dst, p);
    dichotomies.push_back(h);
  }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 362 "parser.ypp"
    {
    dichotomy_hint h;
    h.src = *(yyvsp[(4) - (5)].dvars); delete (yyvsp[(4) - (5)].dvars);
    parse_property_tree(h.dst, (yyvsp[(2) - (5)].prop));
    dichotomies.push_back(h);
  }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 369 "parser.ypp"
    {
    dichotomy_hint h;
    h.src = *(yyvsp[(3) - (4)].dvars); delete (yyvsp[(3) - (4)].dvars);
    dichotomies.push_back(h);
  }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 375 "parser.ypp"
    {
    if (!register_approx((yyvsp[(2) - (5)].real), (yyvsp[(4) - (5)].real)))
      warning("relation already known");
  }
    break;



/* Line 1806 of yacc.c  */
#line 2383 "parser/parser.cpp"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



