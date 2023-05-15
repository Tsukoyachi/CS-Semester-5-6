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
#line 1 "analyse_syntaxique.y"

#include <stdlib.h>
#include <stdio.h>
#include "arbre_abstrait.h"
#include "analyse_lexicale.h"


//n_programme* yyparse();
int yylex();
int yyerror(const char *s);
n_programme* arbre_abstrait;

#line 84 "analyse_syntaxique.c"

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

#include "symboles.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* FIN  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MODULO = 3,                     /* MODULO  */
  YYSYMBOL_DIVISION = 4,                   /* DIVISION  */
  YYSYMBOL_PLUS = 5,                       /* PLUS  */
  YYSYMBOL_TYPE_ENTIER = 6,                /* TYPE_ENTIER  */
  YYSYMBOL_TYPE_BOOLEEN = 7,               /* TYPE_BOOLEEN  */
  YYSYMBOL_MOINS = 8,                      /* MOINS  */
  YYSYMBOL_FOIS = 9,                       /* FOIS  */
  YYSYMBOL_INFERIEUR_OU_EGAL = 10,         /* INFERIEUR_OU_EGAL  */
  YYSYMBOL_SUPERIEUR_OU_EGAL = 11,         /* SUPERIEUR_OU_EGAL  */
  YYSYMBOL_EGAL = 12,                      /* EGAL  */
  YYSYMBOL_DIFFERENT = 13,                 /* DIFFERENT  */
  YYSYMBOL_AFFECTATION = 14,               /* AFFECTATION  */
  YYSYMBOL_INFERIEUR = 15,                 /* INFERIEUR  */
  YYSYMBOL_SUPERIEUR = 16,                 /* SUPERIEUR  */
  YYSYMBOL_PARENTHESE_OUVRANTE = 17,       /* PARENTHESE_OUVRANTE  */
  YYSYMBOL_PARENTHESE_FERMANTE = 18,       /* PARENTHESE_FERMANTE  */
  YYSYMBOL_ACCOLADE_OUVRANTE = 19,         /* ACCOLADE_OUVRANTE  */
  YYSYMBOL_ACCOLADE_FERMANTE = 20,         /* ACCOLADE_FERMANTE  */
  YYSYMBOL_POINT_VIRGULE = 21,             /* POINT_VIRGULE  */
  YYSYMBOL_TANT_QUE = 22,                  /* TANT_QUE  */
  YYSYMBOL_SI = 23,                        /* SI  */
  YYSYMBOL_SINON = 24,                     /* SINON  */
  YYSYMBOL_SINON_SI = 25,                  /* SINON_SI  */
  YYSYMBOL_RETOURNER = 26,                 /* RETOURNER  */
  YYSYMBOL_ET = 27,                        /* ET  */
  YYSYMBOL_OU = 28,                        /* OU  */
  YYSYMBOL_NON = 29,                       /* NON  */
  YYSYMBOL_VIRGULE = 30,                   /* VIRGULE  */
  YYSYMBOL_BOOLEAN = 31,                   /* BOOLEAN  */
  YYSYMBOL_ENTIER = 32,                    /* ENTIER  */
  YYSYMBOL_ECRIRE = 33,                    /* ECRIRE  */
  YYSYMBOL_LIRE = 34,                      /* LIRE  */
  YYSYMBOL_IDENTIFIANT = 35,               /* IDENTIFIANT  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_prog = 37,                      /* prog  */
  YYSYMBOL_listeInstructions = 38,         /* listeInstructions  */
  YYSYMBOL_instruction = 39,               /* instruction  */
  YYSYMBOL_ecrire = 40,                    /* ecrire  */
  YYSYMBOL_conditionnelle = 41,            /* conditionnelle  */
  YYSYMBOL_listeSinonSi = 42,              /* listeSinonSi  */
  YYSYMBOL_declaration = 43,               /* declaration  */
  YYSYMBOL_argument = 44,                  /* argument  */
  YYSYMBOL_expr = 45,                      /* expr  */
  YYSYMBOL_booleen = 46,                   /* booleen  */
  YYSYMBOL_logical = 47,                   /* logical  */
  YYSYMBOL_somme = 48,                     /* somme  */
  YYSYMBOL_produit = 49,                   /* produit  */
  YYSYMBOL_facteur = 50,                   /* facteur  */
  YYSYMBOL_lire = 51,                      /* lire  */
  YYSYMBOL_variable = 52,                  /* variable  */
  YYSYMBOL_fonction = 53,                  /* fonction  */
  YYSYMBOL_listeArgument = 54              /* listeArgument  */
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
typedef yytype_int8 yy_state_t;

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

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif /* 1 */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    88,    91,    96,    99,   102,   107,   112,
     115,   118,   121,   126,   129,   134,   137,   140,   143,   146,
     149,   154,   159,   164,   167,   170,   173,   176,   179,   182,
     185,   188,   191,   194,   197,   200,   203,   206,   211,   215,
     218,   221,   226,   229,   232,   235,   238,   243,   246,   249,
     252,   255,   260,   265,   270,   275,   278
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
  "FIN", "error", "\"invalid token\"", "MODULO", "DIVISION", "PLUS",
  "TYPE_ENTIER", "TYPE_BOOLEEN", "MOINS", "FOIS", "INFERIEUR_OU_EGAL",
  "SUPERIEUR_OU_EGAL", "EGAL", "DIFFERENT", "AFFECTATION", "INFERIEUR",
  "SUPERIEUR", "PARENTHESE_OUVRANTE", "PARENTHESE_FERMANTE",
  "ACCOLADE_OUVRANTE", "ACCOLADE_FERMANTE", "POINT_VIRGULE", "TANT_QUE",
  "SI", "SINON", "SINON_SI", "RETOURNER", "ET", "OU", "NON", "VIRGULE",
  "BOOLEAN", "ENTIER", "ECRIRE", "LIRE", "IDENTIFIANT", "$accept", "prog",
  "listeInstructions", "instruction", "ecrire", "conditionnelle",
  "listeSinonSi", "declaration", "argument", "expr", "booleen", "logical",
  "somme", "produit", "facteur", "lire", "variable", "fonction",
  "listeArgument", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-39)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,   -28,   -26,     7,    20,    12,    61,   -29,    -2,   -29,
     -29,   -29,     9,    41,    46,    46,    25,   -29,   -29,    10,
     -29,    34,   -29,    -7,    46,    46,   -29,   -29,    54,    57,
      66,    40,    94,    55,   -12,   -29,    42,   -29,    71,    59,
      70,    72,    75,    77,   -29,   -29,    85,   -29,    90,    46,
     110,    46,    46,     0,     0,     0,     0,     0,     0,     0,
       0,    -7,    -7,    -7,   109,   -29,   -29,   -29,   -29,   -29,
     -29,   102,   -29,   113,    -2,   -29,    40,    40,    91,   -29,
      91,    14,    91,    14,    14,    14,    14,    14,   -29,   -29,
     -29,   -29,    46,   -29,    56,   -29,   101,   114,   117,   111,
      -2,    46,   118,   116,   120,    -2,   -29,   121,   119,    -2,
     -29,   122,   123,   -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     2,     3,     5,
       7,     6,     0,     0,     0,     0,     0,     1,     4,     0,
      15,     0,    16,     0,     0,     0,    24,    50,     0,    53,
      38,    28,    23,    39,    42,    48,    47,    49,     0,    22,
       0,     0,     0,     0,    46,    47,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,    19,    18,    17,    51,
      52,    55,    21,     0,     0,    38,    26,    27,    40,    42,
      41,    36,    39,    35,    33,    34,    31,    32,    45,    44,
      43,     8,     0,    54,     0,    56,     9,     0,     0,    11,
       0,     0,     0,     0,    38,     0,    10,     0,     0,     0,
      12,     0,    13,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,    -8,   -29,   -29,   -29,    29,   -29,   -29,     5,
     -11,    76,    64,    58,   -10,   -29,   -13,   -29,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    10,    99,    11,    71,    72,
      39,    31,    32,    33,    34,    35,    45,    37,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      18,    36,    36,    30,     1,     2,   -29,    12,    23,    13,
      24,    36,    36,    44,    47,   -29,   -29,    24,   -29,    53,
      38,     3,    54,    19,    14,    27,    16,    28,    29,    46,
      20,     4,    27,     5,    28,    29,    36,    15,    36,    36,
      75,    75,    42,    79,    79,    79,    79,    79,    79,    79,
      79,    88,    89,    90,    23,    21,    40,    41,    61,    62,
     -30,    17,    22,    24,    63,    43,    94,    51,    52,   -30,
     -30,    48,   -30,   -25,    49,    25,    96,    26,    27,    36,
      28,    29,   -25,   -25,    50,   -25,   -38,   -38,    36,    64,
     104,    65,   103,    66,    61,    62,    67,   108,    68,    53,
      63,   111,    54,    69,    55,    56,    57,    58,    70,    59,
      60,    78,    80,    82,    82,    82,    82,    82,    82,    81,
      83,    84,    85,    86,    87,    97,    98,    76,    77,    74,
      91,    93,    92,   100,   101,   102,   106,   105,   107,   110,
     109,   113,   112,    95,     0,     0,     0,     0,    98
};

static const yytype_int8 yycheck[] =
{
       8,    14,    15,    14,     6,     7,    18,    35,     8,    35,
      17,    24,    25,    23,    25,    27,    28,    17,    30,     5,
      15,    23,     8,    14,    17,    32,    14,    34,    35,    24,
      21,    33,    32,    35,    34,    35,    49,    17,    51,    52,
      51,    52,    32,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     8,    14,    31,    32,     3,     4,
      18,     0,    21,    17,     9,    31,    74,    27,    28,    27,
      28,    17,    30,    18,    17,    29,    20,    31,    32,    92,
      34,    35,    27,    28,    18,    30,    27,    28,   101,    18,
     101,    21,   100,    21,     3,     4,    21,   105,    21,     5,
       9,   109,     8,    18,    10,    11,    12,    13,    18,    15,
      16,    53,    54,    55,    56,    57,    58,    59,    60,    55,
      56,    57,    58,    59,    60,    24,    25,    51,    52,    19,
      21,    18,    30,    19,    17,    24,    20,    19,    18,    20,
      19,   112,    20,    92,    -1,    -1,    -1,    -1,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    23,    33,    35,    37,    38,    39,    40,
      41,    43,    35,    35,    17,    17,    14,     0,    38,    14,
      21,    14,    21,     8,    17,    29,    31,    32,    34,    35,
      46,    47,    48,    49,    50,    51,    52,    53,    45,    46,
      31,    32,    32,    31,    50,    52,    45,    46,    17,    17,
      18,    27,    28,     5,     8,    10,    11,    12,    13,    15,
      16,     3,     4,     9,    18,    21,    21,    21,    21,    18,
      18,    44,    45,    54,    19,    46,    47,    47,    49,    50,
      49,    48,    49,    48,    48,    48,    48,    48,    50,    50,
      50,    21,    30,    18,    38,    54,    20,    24,    25,    42,
      19,    17,    24,    38,    46,    19,    20,    18,    38,    19,
      20,    38,    20,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    40,    41,
      41,    41,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    44,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    47,    48,
      48,    48,    49,    49,    49,    49,    49,    50,    50,    50,
      50,    50,    51,    52,    53,    54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     5,     7,
      11,     8,    12,     7,     8,     3,     3,     5,     5,     4,
       4,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       3,     3,     1,     3,     3,     3,     2,     1,     1,     1,
       1,     3,     3,     1,     4,     1,     3
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
        YY_LAC_DISCARD ("YYBACKUP");                              \
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


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}





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

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
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

  if (yychar <= FIN)
    {
      yychar = FIN;
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* prog: listeInstructions  */
#line 83 "analyse_syntaxique.y"
                        {
arbre_abstrait =creer_n_programme((yyvsp[0].l_inst));
}
#line 1438 "analyse_syntaxique.c"
    break;

  case 3: /* listeInstructions: instruction  */
#line 88 "analyse_syntaxique.y"
                  {
        (yyval.l_inst) =creer_n_l_instructions((yyvsp[0].inst) ,NULL);
    }
#line 1446 "analyse_syntaxique.c"
    break;

  case 4: /* listeInstructions: instruction listeInstructions  */
#line 91 "analyse_syntaxique.y"
                                    {
        (yyval.l_inst) =creer_n_l_instructions((yyvsp[-1].inst) ,(yyvsp[0].l_inst));
    }
#line 1454 "analyse_syntaxique.c"
    break;

  case 5: /* instruction: ecrire  */
#line 96 "analyse_syntaxique.y"
             {
	    (yyval.inst) =(yyvsp[0].inst);
    }
#line 1462 "analyse_syntaxique.c"
    break;

  case 6: /* instruction: declaration  */
#line 99 "analyse_syntaxique.y"
                  {
	    (yyval.inst) =(yyvsp[0].inst);
    }
#line 1470 "analyse_syntaxique.c"
    break;

  case 7: /* instruction: conditionnelle  */
#line 102 "analyse_syntaxique.y"
                     {
		(yyval.inst) =(yyvsp[0].inst);
	}
#line 1478 "analyse_syntaxique.c"
    break;

  case 8: /* ecrire: ECRIRE PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE POINT_VIRGULE  */
#line 107 "analyse_syntaxique.y"
                                                                        {
	    (yyval.inst) =creer_n_ecrire((yyvsp[-2].exp));
    }
#line 1486 "analyse_syntaxique.c"
    break;

  case 9: /* conditionnelle: SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE  */
#line 112 "analyse_syntaxique.y"
                                                                                                                   {
		(yyval.inst) =creer_n_conditionnelle((yyvsp[-4].exp), (yyvsp[-1].l_inst), NULL, NULL);
	}
#line 1494 "analyse_syntaxique.c"
    break;

  case 10: /* conditionnelle: SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE SINON ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE  */
#line 115 "analyse_syntaxique.y"
                                                                                                                                                                               {
		(yyval.inst) =creer_n_conditionnelle((yyvsp[-8].exp), (yyvsp[-5].l_inst), NULL, (yyvsp[-1].l_inst));
	}
#line 1502 "analyse_syntaxique.c"
    break;

  case 11: /* conditionnelle: SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE listeSinonSi  */
#line 118 "analyse_syntaxique.y"
                                                                                                                                {
		(yyval.inst) =creer_n_conditionnelle((yyvsp[-5].exp), (yyvsp[-2].l_inst), (yyvsp[0].inst), NULL);
	}
#line 1510 "analyse_syntaxique.c"
    break;

  case 12: /* conditionnelle: SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE listeSinonSi SINON ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE  */
#line 121 "analyse_syntaxique.y"
                                                                                                                                                                                            {
		(yyval.inst) =creer_n_conditionnelle((yyvsp[-9].exp), (yyvsp[-6].l_inst), (yyvsp[-4].inst), (yyvsp[-1].l_inst));
    }
#line 1518 "analyse_syntaxique.c"
    break;

  case 13: /* listeSinonSi: SINON_SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE  */
#line 126 "analyse_syntaxique.y"
                                                                                                                         {
		(yyval.inst) =creer_n_conditionnelle((yyvsp[-4].exp), (yyvsp[-1].l_inst), NULL, NULL);
	}
#line 1526 "analyse_syntaxique.c"
    break;

  case 14: /* listeSinonSi: SINON_SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE listeSinonSi  */
#line 129 "analyse_syntaxique.y"
                                                                                                                                      {
		(yyval.inst) =creer_n_conditionnelle((yyvsp[-5].exp), (yyvsp[-2].l_inst), (yyvsp[0].inst), NULL);
	}
#line 1534 "analyse_syntaxique.c"
    break;

  case 15: /* declaration: TYPE_ENTIER IDENTIFIANT POINT_VIRGULE  */
#line 134 "analyse_syntaxique.y"
                                                 {
		(yyval.inst) = creer_n_declaration(creer_variable_entier((yyvsp[-1].name), NULL));
	}
#line 1542 "analyse_syntaxique.c"
    break;

  case 16: /* declaration: TYPE_BOOLEEN IDENTIFIANT POINT_VIRGULE  */
#line 137 "analyse_syntaxique.y"
                                                 {
		(yyval.inst) = creer_n_declaration(creer_variable_boolean((yyvsp[-1].name), NULL));
	}
#line 1550 "analyse_syntaxique.c"
    break;

  case 17: /* declaration: TYPE_BOOLEEN IDENTIFIANT AFFECTATION BOOLEAN POINT_VIRGULE  */
#line 140 "analyse_syntaxique.y"
                                                                 {
		(yyval.inst) = creer_n_declaration_affectation(creer_variable_boolean((yyvsp[-3].name), (yyvsp[-1].entier)));
	}
#line 1558 "analyse_syntaxique.c"
    break;

  case 18: /* declaration: TYPE_ENTIER IDENTIFIANT AFFECTATION ENTIER POINT_VIRGULE  */
#line 143 "analyse_syntaxique.y"
                                                               {
		(yyval.inst) = creer_n_declaration_affectation(creer_variable_entier((yyvsp[-3].name), (yyvsp[-1].entier)));
	}
#line 1566 "analyse_syntaxique.c"
    break;

  case 19: /* declaration: IDENTIFIANT AFFECTATION ENTIER POINT_VIRGULE  */
#line 146 "analyse_syntaxique.y"
                                                   {
        (yyval.inst) = creer_n_affectation(creer_variable_entier((yyvsp[-3].name), (yyvsp[-1].entier)));
    }
#line 1574 "analyse_syntaxique.c"
    break;

  case 20: /* declaration: IDENTIFIANT AFFECTATION BOOLEAN POINT_VIRGULE  */
#line 149 "analyse_syntaxique.y"
                                                    {
        (yyval.inst) = creer_n_affectation(creer_variable_boolean((yyvsp[-3].name), (yyvsp[-1].entier)));
    }
#line 1582 "analyse_syntaxique.c"
    break;

  case 21: /* argument: expr  */
#line 154 "analyse_syntaxique.y"
           {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1590 "analyse_syntaxique.c"
    break;

  case 22: /* expr: booleen  */
#line 159 "analyse_syntaxique.y"
              {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1598 "analyse_syntaxique.c"
    break;

  case 23: /* booleen: somme  */
#line 164 "analyse_syntaxique.y"
            {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1606 "analyse_syntaxique.c"
    break;

  case 24: /* booleen: BOOLEAN  */
#line 167 "analyse_syntaxique.y"
              {
        (yyval.exp) = creer_n_booleen((yyvsp[0].entier));
    }
#line 1614 "analyse_syntaxique.c"
    break;

  case 25: /* booleen: produit  */
#line 170 "analyse_syntaxique.y"
              {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1622 "analyse_syntaxique.c"
    break;

  case 26: /* booleen: logical ET logical  */
#line 173 "analyse_syntaxique.y"
                         {
		(yyval.exp) = creer_n_operation("&&", (yyvsp[-2].exp), (yyvsp[0].exp));
	}
#line 1630 "analyse_syntaxique.c"
    break;

  case 27: /* booleen: logical OU logical  */
#line 176 "analyse_syntaxique.y"
                             {
		(yyval.exp) = creer_n_operation("||", (yyvsp[-2].exp), (yyvsp[0].exp));
	}
#line 1638 "analyse_syntaxique.c"
    break;

  case 28: /* booleen: logical  */
#line 179 "analyse_syntaxique.y"
              {
		(yyval.exp) = (yyvsp[0].exp);
	}
#line 1646 "analyse_syntaxique.c"
    break;

  case 29: /* booleen: facteur  */
#line 182 "analyse_syntaxique.y"
              {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1654 "analyse_syntaxique.c"
    break;

  case 30: /* booleen: variable  */
#line 185 "analyse_syntaxique.y"
               {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1662 "analyse_syntaxique.c"
    break;

  case 31: /* booleen: somme INFERIEUR somme  */
#line 188 "analyse_syntaxique.y"
                            {
        (yyval.exp) = creer_n_operation("<",(yyvsp[-2].exp),(yyvsp[0].exp));
    }
#line 1670 "analyse_syntaxique.c"
    break;

  case 32: /* booleen: somme SUPERIEUR somme  */
#line 191 "analyse_syntaxique.y"
                            {
        (yyval.exp) = creer_n_operation(">",(yyvsp[-2].exp),(yyvsp[0].exp));
    }
#line 1678 "analyse_syntaxique.c"
    break;

  case 33: /* booleen: somme EGAL somme  */
#line 194 "analyse_syntaxique.y"
                       {
        (yyval.exp) = creer_n_operation("==",(yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1686 "analyse_syntaxique.c"
    break;

  case 34: /* booleen: somme DIFFERENT somme  */
#line 197 "analyse_syntaxique.y"
                            {
        (yyval.exp) = creer_n_operation("!=",(yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1694 "analyse_syntaxique.c"
    break;

  case 35: /* booleen: somme SUPERIEUR_OU_EGAL somme  */
#line 200 "analyse_syntaxique.y"
                                    {
        (yyval.exp) = creer_n_operation(">=",(yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1702 "analyse_syntaxique.c"
    break;

  case 36: /* booleen: somme INFERIEUR_OU_EGAL somme  */
#line 203 "analyse_syntaxique.y"
                                    {
        (yyval.exp) = creer_n_operation("<=",(yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1710 "analyse_syntaxique.c"
    break;

  case 37: /* booleen: NON booleen  */
#line 206 "analyse_syntaxique.y"
                  {
		(yyval.exp) = creer_n_operation_non("!", (yyvsp[0].exp));
	}
#line 1718 "analyse_syntaxique.c"
    break;

  case 38: /* logical: booleen  */
#line 211 "analyse_syntaxique.y"
              {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1726 "analyse_syntaxique.c"
    break;

  case 39: /* somme: produit  */
#line 215 "analyse_syntaxique.y"
              {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1734 "analyse_syntaxique.c"
    break;

  case 40: /* somme: somme PLUS produit  */
#line 218 "analyse_syntaxique.y"
                         {
        (yyval.exp) =creer_n_operation("+", (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1742 "analyse_syntaxique.c"
    break;

  case 41: /* somme: somme MOINS produit  */
#line 221 "analyse_syntaxique.y"
                          {
        (yyval.exp) = creer_n_operation("-",(yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1750 "analyse_syntaxique.c"
    break;

  case 42: /* produit: facteur  */
#line 226 "analyse_syntaxique.y"
              {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1758 "analyse_syntaxique.c"
    break;

  case 43: /* produit: produit FOIS facteur  */
#line 229 "analyse_syntaxique.y"
                           {
        (yyval.exp) =creer_n_operation("*",(yyvsp[-2].exp),(yyvsp[0].exp));
    }
#line 1766 "analyse_syntaxique.c"
    break;

  case 44: /* produit: produit DIVISION facteur  */
#line 232 "analyse_syntaxique.y"
                               {
        (yyval.exp) =creer_n_operation("/",(yyvsp[-2].exp),(yyvsp[0].exp));
    }
#line 1774 "analyse_syntaxique.c"
    break;

  case 45: /* produit: produit MODULO facteur  */
#line 235 "analyse_syntaxique.y"
                             {
        (yyval.exp) =creer_n_operation("%",(yyvsp[-2].exp),(yyvsp[0].exp));
    }
#line 1782 "analyse_syntaxique.c"
    break;

  case 46: /* produit: MOINS facteur  */
#line 238 "analyse_syntaxique.y"
                    {
        (yyval.exp) = creer_n_operation("*",creer_n_entier(-1),(yyvsp[0].exp));
    }
#line 1790 "analyse_syntaxique.c"
    break;

  case 47: /* facteur: variable  */
#line 243 "analyse_syntaxique.y"
               {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1798 "analyse_syntaxique.c"
    break;

  case 48: /* facteur: lire  */
#line 246 "analyse_syntaxique.y"
           {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1806 "analyse_syntaxique.c"
    break;

  case 49: /* facteur: fonction  */
#line 249 "analyse_syntaxique.y"
               {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1814 "analyse_syntaxique.c"
    break;

  case 50: /* facteur: ENTIER  */
#line 252 "analyse_syntaxique.y"
             {
	    (yyval.exp) = creer_n_entier((yyvsp[0].entier));
    }
#line 1822 "analyse_syntaxique.c"
    break;

  case 51: /* facteur: PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE  */
#line 255 "analyse_syntaxique.y"
                                                   {
	    (yyval.exp) =(yyvsp[-1].exp) ;
    }
#line 1830 "analyse_syntaxique.c"
    break;

  case 52: /* lire: LIRE PARENTHESE_OUVRANTE PARENTHESE_FERMANTE  */
#line 260 "analyse_syntaxique.y"
                                                   {
        (yyval.exp) = creer_lire();
    }
#line 1838 "analyse_syntaxique.c"
    break;

  case 53: /* variable: IDENTIFIANT  */
#line 265 "analyse_syntaxique.y"
                  {
        (yyval.exp) = creer_variable((yyvsp[0].name));
    }
#line 1846 "analyse_syntaxique.c"
    break;

  case 54: /* fonction: IDENTIFIANT PARENTHESE_OUVRANTE listeArgument PARENTHESE_FERMANTE  */
#line 270 "analyse_syntaxique.y"
                                                                        {
        (yyval.exp) = creer_fonction((yyvsp[-3].name),(yyvsp[-1].l_arg));
    }
#line 1854 "analyse_syntaxique.c"
    break;

  case 55: /* listeArgument: argument  */
#line 275 "analyse_syntaxique.y"
               {
        (yyval.l_arg) = creer_n_l_argument((yyvsp[0].exp),NULL);
    }
#line 1862 "analyse_syntaxique.c"
    break;

  case 56: /* listeArgument: argument VIRGULE listeArgument  */
#line 278 "analyse_syntaxique.y"
                                     {
        (yyval.l_arg) = creer_n_l_argument((yyvsp[-2].exp),(yyvsp[0].l_arg));;
    }
#line 1870 "analyse_syntaxique.c"
    break;


#line 1874 "analyse_syntaxique.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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

      if (yychar <= FIN)
        {
          /* Return failure if at end of input.  */
          if (yychar == FIN)
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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);

  return yyresult;
}

#line 282 "analyse_syntaxique.y"


int yyerror(const char *s) {
    printf("yyerror : %s\n",s);
    return 0;
}
