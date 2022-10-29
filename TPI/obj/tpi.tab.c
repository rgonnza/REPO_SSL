
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "../src/tpi.y"

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ts.h"
#define YYDEBUG 1

enum errores{
        centinela,
        lvalue        
}cod_error;

int flag_error=0;
char* tipo;
char* identificador;
char* tipoSentencia;
int flag_tipo;
int flag_tipoAsignado;
int flag_retorno;
char* array ="array de ";
char* pointer="puntero a ";
int yylex();
int esArray=0;
int esInicializado=0;
int esPuntero=0;
Lista auxVariables;
Lista auxParametros;
FILE *yyin;
ts *aux;
char *identificador;


int yywrap(){
	return(1);
}
extern int yylineno;

void yyerror (char *s) {
   
   printf("%s \nError sintactico ");
}



/* Line 189 of yacc.c  */
#line 118 "tpi.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
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
     ENTERO = 258,
     REAL = 259,
     ID = 260,
     TIPO_DATO = 261,
     IF = 262,
     ELSE = 263,
     SWITCH = 264,
     WHILE = 265,
     DO = 266,
     FOR = 267,
     MAYOR_O_IGUAL = 268,
     MENOR_O_IGUAL = 269,
     IGUAL_O_DISTINTO = 270,
     INCREMENTO_O_DECREMENTO = 271,
     AND = 272,
     OR = 273,
     SIZEOF = 274,
     RETURN = 275,
     OPERADOR_ASIGNACION = 276,
     VOID = 277,
     CARACTER = 278,
     LITERAL_CADENA = 279
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 45 "../src/tpi.y"

struct yylval_struct{
        char cadena[30];
        int entero;
        int tipo;
        char caracter;
        float real
}mystruct;



/* Line 214 of yacc.c  */
#line 190 "tpi.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 202 "tpi.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   394

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,     2,     2,    31,    32,     2,
      34,    35,    29,    27,    25,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    36,
       2,    26,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    10,    12,    14,    16,
      23,    30,    37,    44,    46,    50,    51,    54,    56,    60,
      62,    64,    67,    69,    71,    75,    79,    81,    82,    85,
      86,    91,    92,    95,    97,    99,   101,   105,   107,   109,
     111,   117,   119,   123,   125,   129,   131,   135,   137,   141,
     145,   147,   151,   155,   157,   161,   165,   169,   171,   174,
     177,   180,   185,   187,   189,   191,   193,   195,   200,   205,
     207,   211,   213,   215,   217,   221,   223,   225,   230,   231,
     233,   237,   239,   241,   243,   245,   247,   249,   251,   253,
     255,   257,   261,   262,   265,   268,   270,   273,   275,   278,
     281,   283,   286,   288,   294,   302,   308,   314,   322,   332,
     334,   336,   339
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    -1,    44,    45,    -1,    -1,    46,    -1,
      77,    -1,    47,    -1,    50,    -1,    22,     5,    34,    48,
      35,    36,    -1,    52,     5,    34,    48,    35,    36,    -1,
      22,     5,    34,    48,    35,    78,    -1,    52,     5,    34,
      48,    35,    78,    -1,    49,    -1,    49,    25,    48,    -1,
      -1,     6,     5,    -1,     6,    -1,    52,    53,    51,    -1,
      36,    -1,     1,    -1,     6,    57,    -1,     1,    -1,    54,
      -1,    53,    25,    54,    -1,     5,    56,    55,    -1,     1,
      -1,    -1,    26,    58,    -1,    -1,    56,    37,    76,    38,
      -1,    -1,    57,    29,    -1,    59,    -1,     1,    -1,    61,
      -1,    68,    60,    59,    -1,    26,    -1,    21,    -1,    62,
      -1,    62,    39,    58,    40,    61,    -1,    63,    -1,    62,
      18,    63,    -1,    64,    -1,    63,    17,    64,    -1,    65,
      -1,    64,    15,    65,    -1,    66,    -1,    65,    13,    66,
      -1,    65,    14,    66,    -1,    67,    -1,    66,    27,    67,
      -1,    66,    28,    67,    -1,    68,    -1,    67,    29,    68,
      -1,    67,    30,    68,    -1,    67,    31,    68,    -1,    70,
      -1,    16,    68,    -1,    68,    16,    -1,    69,    68,    -1,
      19,    85,     6,    86,    -1,    32,    -1,    29,    -1,    28,
      -1,    33,    -1,    72,    -1,    70,    37,    58,    38,    -1,
      70,    85,    71,    86,    -1,    59,    -1,    71,    25,    59,
      -1,     5,    -1,    76,    -1,    24,    -1,    85,    58,    86,
      -1,    73,    -1,     1,    -1,     5,    85,    74,    86,    -1,
      -1,    75,    -1,    75,    25,    74,    -1,    76,    -1,    24,
      -1,    23,    -1,     3,    -1,     4,    -1,    78,    -1,    82,
      -1,    83,    -1,    84,    -1,    87,    -1,    41,    79,    42,
      -1,    -1,    81,    79,    -1,    80,    79,    -1,    77,    -1,
      80,    77,    -1,    50,    -1,    81,    50,    -1,    58,    36,
      -1,    36,    -1,     1,    36,    -1,     1,    -1,     7,    85,
      58,    86,    77,    -1,     7,    85,    58,    86,    77,     8,
      77,    -1,     9,    85,    58,    86,    77,    -1,    10,    85,
      58,    86,    77,    -1,    11,    77,    10,    85,    58,    86,
      36,    -1,    12,    85,    54,    36,    58,    36,    58,    86,
      77,    -1,    34,    -1,    35,    -1,    20,    36,    -1,    20,
      58,    36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   100,   103,   104,   105,   110,   113,   116,
     127,   138,   149,   167,   168,   170,   171,   174,   176,   179,
     193,   196,   197,   199,   200,   203,   230,   239,   240,   242,
     243,   245,   246,   250,   251,   257,   258,   266,   267,   270,
     271,   274,   275,   277,   278,   280,   281,   283,   284,   285,
     287,   288,   289,   291,   292,   293,   294,   297,   298,   299,
     300,   301,   303,   303,   303,   303,   306,   307,   308,   311,
     312,   314,   322,   323,   324,   325,   326,   332,   360,   361,
     362,   364,   365,   367,   368,   369,   374,   375,   376,   383,
     390,   393,   395,   396,   397,   400,   401,   403,   404,   407,
     417,   418,   423,   430,   431,   432,   435,   436,   437,   439,
     441,   444,   445
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTERO", "REAL", "ID", "TIPO_DATO",
  "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "MAYOR_O_IGUAL",
  "MENOR_O_IGUAL", "IGUAL_O_DISTINTO", "INCREMENTO_O_DECREMENTO", "AND",
  "OR", "SIZEOF", "RETURN", "OPERADOR_ASIGNACION", "VOID", "CARACTER",
  "LITERAL_CADENA", "','", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'&'",
  "'!'", "'('", "')'", "';'", "'['", "']'", "'?'", "':'", "'{'", "'}'",
  "$accept", "input", "line", "declaracion", "declaracionDeFuncion",
  "argsFuncion", "argumentoA", "declaracionVarSimples",
  "finDeclaracionVariable", "tipoDato", "listaVarSimples", "unaVarSimple",
  "inicializacion", "arreglo", "puntero", "expresion", "expAsignacion",
  "operAsignacion", "expCondicional", "expOr", "expAnd", "expIgualdad",
  "expRelacional", "expAditiva", "expMultiplicativa", "expUnaria",
  "operUnario", "expPostFijo", "listaArgumentos", "expPrimaria",
  "usoDeFuncion", "listaParametros", "parametro", "constante", "sentencia",
  "sentenciaCompuesta", "sentencias_y_declaraciones", "listaSentencias",
  "listaDeclaraciones", "sentenciaDeExpresion", "sentenciaDeControl",
  "sentenciaDeIteracion", "aperturaParentesis", "cierreParentesis",
  "sentenciaDeSalto", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    44,    61,    43,    45,    42,
      47,    37,    38,    33,    40,    41,    59,    91,    93,    63,
      58,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    46,    46,    47,
      47,    47,    47,    48,    48,    49,    49,    49,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    65,
      66,    66,    66,    67,    67,    67,    67,    68,    68,    68,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    73,    74,    74,
      74,    75,    75,    76,    76,    76,    77,    77,    77,    77,
      77,    78,    79,    79,    79,    80,    80,    81,    81,    82,
      82,    82,    82,    83,    83,    83,    84,    84,    84,    85,
      86,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     1,     1,     1,     1,     6,
       6,     6,     6,     1,     3,     0,     2,     1,     3,     1,
       1,     2,     1,     1,     3,     3,     1,     0,     2,     0,
       4,     0,     2,     1,     1,     1,     3,     1,     1,     1,
       5,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     4,     4,     1,
       3,     1,     1,     1,     3,     1,     1,     4,     0,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     2,     2,     1,     2,     1,     2,     2,
       1,     2,     1,     5,     7,     5,     5,     7,     9,     1,
       1,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,   102,    84,    85,    71,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    73,    64,
      63,    62,    65,   109,   100,     0,     3,     5,     7,     8,
       0,     0,    33,    35,    39,    41,    43,    45,    47,    50,
      53,     0,    57,    66,    75,    72,     6,    86,    87,    88,
      89,     0,    90,   101,    78,    21,     0,     0,     0,   102,
       0,     0,    76,    58,     0,    76,   111,     0,     0,    97,
       0,    95,     0,     0,     0,    26,    29,     0,    23,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    38,    37,     0,    60,     0,     0,     0,    82,
       0,    79,    81,    32,     0,     0,     0,     0,    29,     0,
       0,   112,    15,    91,    95,    94,    97,    93,    15,    27,
      20,     0,    19,    18,    42,    53,     0,    44,    46,    48,
      49,    51,    52,    54,    55,    56,    36,     0,    69,     0,
     110,    74,    77,    78,     0,     0,     0,     0,     0,    61,
      17,     0,    13,     0,     0,     0,    25,    24,     0,    67,
       0,    68,    80,   103,   105,   106,     0,     0,    16,     0,
      15,     0,    28,     0,    40,    70,     0,     0,     0,     9,
      11,    14,    10,    12,    30,   104,   107,     0,     0,   108
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,    27,    28,   151,   152,    69,   123,    70,
      77,    78,   156,   119,    55,    31,    32,    94,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   139,    43,
      44,   100,   101,    45,    71,    47,    72,    73,    74,    48,
      49,    50,    51,   141,    52
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -139
static const yytype_int16 yypact[] =
{
    -139,   150,  -139,    93,  -139,  -139,    35,  -139,    35,    35,
      35,   231,    35,   299,    35,   265,    42,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,   189,  -139,  -139,  -139,  -139,
      65,   -11,  -139,  -139,     1,    80,    84,    50,    68,    58,
      34,   299,    24,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,   333,  -139,  -139,    12,    73,   333,   333,   333,   355,
     105,    85,  -139,   100,   111,    13,  -139,    82,    91,  -139,
      85,  -139,    86,   189,   189,  -139,    92,    20,  -139,  -139,
     299,   333,   299,   299,   299,   299,   299,   299,   299,   299,
     299,  -139,  -139,  -139,   299,   100,   333,   299,    96,  -139,
      96,   110,  -139,  -139,    96,    96,    96,    35,  -139,   101,
      96,  -139,   130,  -139,  -139,  -139,  -139,  -139,   130,     4,
    -139,    85,  -139,  -139,    80,   100,    98,    84,    50,    68,
      68,    58,    58,   100,   100,   100,  -139,   103,  -139,    27,
    -139,  -139,  -139,    12,   231,   231,   231,   333,   333,  -139,
     134,   107,   121,   112,   333,    23,  -139,  -139,   299,  -139,
     299,  -139,  -139,   140,  -139,  -139,    96,   116,  -139,    -7,
     130,    18,  -139,   120,  -139,  -139,   231,   127,   333,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,    96,   231,  -139
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,  -139,  -139,  -105,  -139,    11,  -139,   164,
    -139,   -53,  -139,  -139,  -139,   -14,   -77,  -139,     9,  -139,
      88,    89,    94,     8,    14,    -9,  -139,  -139,  -139,  -139,
    -139,    33,  -139,   -52,    -1,  -138,    39,  -139,  -139,  -139,
    -139,  -139,    -3,   -82,  -139
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -93
static const yytype_int16 yytable[] =
{
      46,    67,   102,    54,    63,    56,    57,    58,   109,    61,
      60,    64,    29,   153,   -34,     4,     5,   136,   142,    80,
     138,   120,   144,   145,   146,    79,     4,     5,   149,   179,
     154,   180,    95,   183,    25,    17,    99,    98,   -34,    97,
      81,   155,   104,   105,   106,   121,    17,    68,   -34,   -34,
      91,   -34,   160,   -34,   182,    92,   122,   161,    23,    25,
      93,    96,   140,    84,    85,   181,    75,   126,   157,    23,
      76,   125,   114,   125,   125,   125,   125,   125,   125,   133,
     134,   135,   137,   175,   177,   116,    75,    88,    89,    90,
     108,   102,   129,   130,   -22,    86,    87,    82,   -22,    83,
     131,   132,   103,   173,   147,   188,   -76,   -76,   -76,   -76,
     -76,   -76,   115,   117,   -76,   107,    91,   110,   111,   -76,
     -76,   -76,   -76,   -76,   -76,   112,   118,   -76,   113,    53,
     -76,   140,   -76,   166,   167,   143,   150,   148,   158,   168,
     172,   159,   169,   163,   164,   165,   170,   171,   176,   125,
       2,     3,   178,     4,     5,     6,     7,     8,   184,     9,
      10,    11,    12,   186,   187,    30,    13,   174,   124,    14,
      15,   127,    16,    17,    18,   185,   162,   128,    19,    20,
       0,     0,    21,    22,    23,     0,    24,   189,     0,     0,
       3,    25,     4,     5,     6,     7,     8,     0,     9,    10,
      11,    12,     0,     0,     0,    13,     0,     0,    14,    15,
       0,     0,    17,    18,     0,     0,     0,    19,    20,     0,
       0,    21,    22,    23,     0,    24,     0,     0,     0,     0,
      25,   -92,    59,     0,     4,     5,     6,     0,     8,     0,
       9,    10,    11,    12,     0,     0,     0,    13,     0,     0,
      14,    15,     0,     0,    17,    18,     0,     0,     0,    19,
      20,     0,     0,    21,    22,    23,    65,    24,     4,     5,
       6,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,    14,     0,     0,     0,    17,    18,
       0,     0,     0,    19,    20,     0,     0,    21,    22,    23,
      62,    66,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,    14,     0,
       0,     0,    17,    18,     0,     0,     0,    19,    20,     0,
       0,    21,    22,    23,    65,     0,     4,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,    14,     0,     0,     0,    17,    18,     0,     0,
       0,    19,    20,     0,     0,    21,    22,    23,   -76,   -76,
     -76,   -76,   -76,   -76,     0,     0,   -76,     0,     0,     0,
       0,   -76,   -76,   -76,   -76,   -76,   -76,     0,     0,   -76,
       0,    53,   -76,     0,   -76
};

static const yytype_int16 yycheck[] =
{
       1,    15,    54,     6,    13,     8,     9,    10,    61,    12,
      11,    14,     1,   118,     1,     3,     4,    94,   100,    18,
      97,     1,   104,   105,   106,    36,     3,     4,   110,    36,
      26,   169,    41,   171,    41,    23,    24,    51,    25,    42,
      39,    37,    56,    57,    58,    25,    23,     5,    35,    36,
      16,    38,    25,    40,    36,    21,    36,   139,    34,    41,
      26,    37,    35,    13,    14,   170,     1,    81,   121,    34,
       5,    80,    73,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    96,   160,   166,    74,     1,    29,    30,    31,
       5,   143,    84,    85,     1,    27,    28,    17,     5,    15,
      86,    87,    29,   155,   107,   187,    13,    14,    15,    16,
      17,    18,    73,    74,    21,    10,    16,     6,    36,    26,
      27,    28,    29,    30,    31,    34,    34,    34,    42,    36,
      37,    35,    39,   147,   148,    25,     6,    36,    40,     5,
     154,    38,    35,   144,   145,   146,    25,    35,     8,   158,
       0,     1,    36,     3,     4,     5,     6,     7,    38,     9,
      10,    11,    12,    36,   178,     1,    16,   158,    80,    19,
      20,    82,    22,    23,    24,   176,   143,    83,    28,    29,
      -1,    -1,    32,    33,    34,    -1,    36,   188,    -1,    -1,
       1,    41,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,    20,
      -1,    -1,    23,    24,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,    33,    34,    -1,    36,    -1,    -1,    -1,    -1,
      41,    42,     1,    -1,     3,     4,     5,    -1,     7,    -1,
       9,    10,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    33,    34,     1,    36,     3,     4,
       5,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    19,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,    34,
       1,    36,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,    33,    34,     1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    19,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,    33,    34,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    -1,    -1,    34,
      -1,    36,    37,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,     0,     1,     3,     4,     5,     6,     7,     9,
      10,    11,    12,    16,    19,    20,    22,    23,    24,    28,
      29,    32,    33,    34,    36,    41,    45,    46,    47,    50,
      52,    58,    59,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    72,    73,    76,    77,    78,    82,    83,
      84,    85,    87,    36,    85,    57,    85,    85,    85,     1,
      77,    85,     1,    68,    85,     1,    36,    58,     5,    50,
      52,    77,    79,    80,    81,     1,     5,    53,    54,    36,
      18,    39,    17,    15,    13,    14,    27,    28,    29,    30,
      31,    16,    21,    26,    60,    68,    37,    85,    58,    24,
      74,    75,    76,    29,    58,    58,    58,    10,     5,    54,
       6,    36,    34,    42,    77,    79,    50,    79,    34,    56,
       1,    25,    36,    51,    63,    68,    58,    64,    65,    66,
      66,    67,    67,    68,    68,    68,    59,    58,    59,    71,
      35,    86,    86,    25,    86,    86,    86,    85,    36,    86,
       6,    48,    49,    48,    26,    37,    55,    54,    40,    38,
      25,    86,    74,    77,    77,    77,    58,    58,     5,    35,
      25,    35,    58,    76,    61,    59,     8,    86,    36,    36,
      78,    48,    36,    78,    38,    77,    36,    58,    86,    77
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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
# if YYLTYPE_IS_TRIVIAL
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
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:

/* Line 1455 of yacc.c  */
#line 110 "../src/tpi.y"
    {
 
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 116 "../src/tpi.y"
    { printf("Se encontro una funcion \n");
                                        if(!flag_error){
                                                Item *item;
                                                aux = agregarEnTabla(strdup((yyvsp[(2) - (6)].mystruct).cadena), 'F', strdup("void"));
                                                for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                                {
                                                        agregarArgumento(&aux->argumentos, strdup((yyvsp[(2) - (6)].mystruct).cadena), strdup(item->tipo), item->valor_entero);
                                                }
                                                auxVariables.cabeza=NULL;
                                        }
                                ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 127 "../src/tpi.y"
    { printf("Se encontro una funcion \n");
                                        if(!flag_error){
                                                Item *item;
                                                aux = agregarEnTabla(strdup((yyvsp[(2) - (6)].mystruct).cadena), 'F', strdup(tipo));
                                                for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                                {
                                                        agregarArgumento(&aux->argumentos, strdup((yyvsp[(2) - (6)].mystruct).cadena), strdup(item->tipo), item->valor_entero);
                                                }
                                                auxVariables.cabeza=NULL;
                                        }   
                                ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 138 "../src/tpi.y"
    { printf("Se encontro una funcion \n");
                                        if(!flag_error){
                                                Item *item;
                                                aux = agregarEnTabla(strdup((yyvsp[(2) - (6)].mystruct).cadena), 'F', strdup("void"));
                                                for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                                {
                                                        agregarArgumento(&aux->argumentos, strdup((yyvsp[(2) - (6)].mystruct).cadena), strdup(item->tipo), item->valor_entero);
                                                }
                                                auxVariables.cabeza=NULL;
                                        }
                                ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 149 "../src/tpi.y"
    { printf("Se encontro una funcion \n");
                                        char *tipoRetorno = (yyvsp[(1) - (6)].mystruct).cadena;
                                        if(!flag_error){
                                                Item *item;
                                                aux = agregarEnTabla(strdup((yyvsp[(2) - (6)].mystruct).cadena), 'F', strdup(tipoRetorno));
                                                for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                                {
                                                        agregarArgumento(&aux->argumentos, strdup((yyvsp[(2) - (6)].mystruct).cadena), strdup(item->tipo), item->valor_entero);
                                                }
                                                auxVariables.cabeza=NULL;
                                        }
                                        if(flag_retorno != (yyvsp[(1) - (6)].mystruct).tipo){
                                                agregarEnLista(&noReconocidos, concatenar("No coincide el retorno con el tipo de dato de la funcion ", (yyvsp[(2) - (6)].mystruct).cadena), ERROR_SEMANTICO, yylineno);
                                        }
                                ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 171 "../src/tpi.y"
    {
                                        agregarEnListaAlFinal(&auxVariables, (yyvsp[(2) - (2)].mystruct).cadena, (yyvsp[(1) - (2)].mystruct).cadena,(yyvsp[(1) - (2)].mystruct).tipo); // $<mystruct>1.tipo es el flag_tipo
                                ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 179 "../src/tpi.y"
    {
                                        Item *item;
                                        
                                        for (item = auxVariables.cabeza; item != NULL; item = item->siguiente)
                                        {
                                                aux=obtenerDeTabla(item->token, 'V');
                                                if(aux){
                                                        agregarEnLista(&noReconocidos, concatenar("Ya se encuentra definida la variable ", item->token), ERROR_SEMANTICO , yylineno );
                                                }else{
                                                        aux = agregarEnTabla(strdup(item->token), 'V', strdup(tipo));                                                         
                                                }
                                        }
                                        auxVariables.cabeza=NULL;
                                ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 193 "../src/tpi.y"
    {flag_error=1 ;agregarEnLista(&noReconocidos, "Falta ;", "", yylineno);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 196 "../src/tpi.y"
    {tipo = (yyvsp[(1) - (2)].mystruct).cadena; flag_tipo=(yyvsp[(1) - (2)].mystruct).tipo;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 197 "../src/tpi.y"
    {printf("Falta tipo de dato en linea \n", yylineno);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 203 "../src/tpi.y"
    {
                                        if(!flag_error){
                                                if(esArray&&esPuntero){
                                                        agregarEnLista(&noReconocidos, "No puede ser puntero y array a la vez", "", yylineno);
                                                } else{
                                                if(esPuntero){tipo=concatenar(pointer,tipo); flag_tipo=1;}
                                                if(esArray){tipo=concatenar(array,tipo); flag_tipo=1;}                 
                                                if(esInicializado){
                                                        if(flag_tipo == flag_tipoAsignado){ 
                                                                printf("los tipos coinciden\n");
                                                                printf("Var: %s de tipo %s \n", (yyvsp[(1) - (3)].mystruct).cadena, tipo );
                                                                agregarEnLista(&auxVariables, (yyvsp[(1) - (3)].mystruct).cadena, tipo,yylineno);
                                                        }else{
                                                                printf("No coinciden los tipos de datos\n");
                                                                agregarEnLista(&noReconocidos, "No coinciden los tipos de datos", "", yylineno);
                                                                flag_error = 0;                                                        
                                                        }
                                                } else {
                                                        printf("Var: %s de tipo %s \n", (yyvsp[(1) - (3)].mystruct).cadena, tipo );
                                                        agregarEnLista(&auxVariables, (yyvsp[(1) - (3)].mystruct).cadena, tipo,yylineno);
                                                }
                                                } 
                                                esArray=0;
                                                esInicializado=0;
                                                esPuntero=0;
                                        }
                                ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 230 "../src/tpi.y"
    {
                                        if(!flag_error){
                                                printf("Falta identificador \n");
                                                agregarEnLista(&noReconocidos, "Falta identificador", "", yylineno);       
                                                flag_error = 1;
                                        }
                                ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 240 "../src/tpi.y"
    {esInicializado=1;flag_tipoAsignado=(yyvsp[(2) - (2)].mystruct).tipo;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 243 "../src/tpi.y"
    {esArray=1;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 246 "../src/tpi.y"
    {esPuntero=1;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 251 "../src/tpi.y"
    {
                                        printf("No se pudo conocer la expresion en linea %i", yylineno);
                                        agregarEnLista(&noReconocidos, "Expresion no reconocida", "", yylineno);
                                        flag_error = 0;
                                ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 258 "../src/tpi.y"
    {
                                        if((yyvsp[(1) - (3)].mystruct).tipo != 4){
                                                agregarEnLista(&noReconocidos, "Se requiere un lvalue modificable como operando izquierdo de una asignación", "", yylineno);
                                                flag_error = 1;
                                        }
                                ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 314 "../src/tpi.y"
    {
                                        aux = obtenerDeTabla(strdup((yyvsp[(1) - (1)].mystruct).cadena), 'V');
                                        if(!aux){
                                                agregarEnLista(&noReconocidos, concatenar("No existe el identificador ", (yyvsp[(1) - (1)].mystruct).cadena), "", yylineno);
                                                flag_error = 1;
                                        }
                                        (yyval.mystruct).tipo = aux->tipo_dato;
                                ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 323 "../src/tpi.y"
    {(yyval.mystruct).tipo=(yyvsp[(1) - (1)].mystruct).tipo;;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 326 "../src/tpi.y"
    {
                                        if(flag_error){
                                                agregarEnLista(&noReconocidos, "No se asigno valor a un lvalue", "", yylineno);
                                        }
                               ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 332 "../src/tpi.y"
    {
                                int errorArg = 0;
                                Item *param;
                                aux = obtenerDeTabla(strdup((yyvsp[(1) - (4)].mystruct).cadena), 'F');                                
                                Item *auxArgumento;
                                Lista *lista = &aux->argumentos;
                                param = auxParametros.cabeza;                                
                                auxArgumento = lista->cabeza;
                        
                                if(longitudLista(aux->argumentos) != longitudLista(auxParametros)){
                                        errorArg = 1; // no coinciden la cantidad de argumentos
                                }else{
                                        while((param != NULL)){
                                                printf("Valor entero de param: %i\n", param->valor_entero);
                                                printf("Valor entero de auxArgumento: %i\n", auxArgumento->valor_entero);
                                                if(param->valor_entero != auxArgumento->valor_entero){
                                                        errorArg = 1;
                                                }
                                                param = param->siguiente;
                                                auxArgumento = auxArgumento->siguiente;
                                        }
                                }
                                if(errorArg == 1){ // hay error en el paso de parametros
                                        agregarEnLista(&noReconocidos, concatenar("Error en el paso de argumentos de la funcion ", (yyvsp[(1) - (4)].mystruct).cadena) ,ERROR_SEMANTICO, yylineno);
                                }
;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 364 "../src/tpi.y"
    {flag_tipoAsignado=(yyvsp[(1) - (1)].mystruct).tipo; agregarEnLista(&auxParametros, "", "", flag_tipoAsignado);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 365 "../src/tpi.y"
    {flag_tipoAsignado=(yyvsp[(1) - (1)].mystruct).tipo; agregarEnLista(&auxParametros, "", "", flag_tipoAsignado);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 367 "../src/tpi.y"
    {(yyval.mystruct).tipo=(yyvsp[(1) - (1)].mystruct).tipo;;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 368 "../src/tpi.y"
    {(yyval.mystruct).tipo=(yyvsp[(1) - (1)].mystruct).tipo;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 369 "../src/tpi.y"
    {(yyval.mystruct).tipo=(yyvsp[(1) - (1)].mystruct).tipo;;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 376 "../src/tpi.y"
    {
                                        char* msg = concatenar("De control ", tipoSentencia);
                                        if(!flag_error){
                                                agregarEnLista(&sentencias, "Sentencia", msg, yylineno);
                                                printf("Se encontro una sentencia de control \n");
                                        }
                                ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 383 "../src/tpi.y"
    {
                                        char* msg = concatenar("De iteracion ", tipoSentencia);
                                        if(flag_error==0){
                                                agregarEnLista(&sentencias, "Sentencia", msg, yylineno);        
                                                printf("Se encontro una sentencia de iteracion \n");
                                        }
                                ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 407 "../src/tpi.y"
    {
                                        if(!flag_error){
                                                agregarEnLista(&sentencias, "Sentencia", "De expresion", yylineno);
                                        }else{
                                        if(cod_error==lvalue){
                                        agregarEnLista(&noReconocidos, "Se requiere un lvalue modificable como operando izquierdo de una asignación", "", yylineno);        
                                                }
                                        }
                                        flag_error=0;
                                ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 418 "../src/tpi.y"
    {
                                        if(!flag_error){
                                                agregarEnLista(&noReconocidos, "Secuencia de tokens no reconocida", "", yylineno);      
                                        }
                                ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 423 "../src/tpi.y"
    {
                                        if(!flag_error){
                                                agregarEnLista(&noReconocidos, "Falta ;", "", yylineno);                                
                                        }
                                ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 430 "../src/tpi.y"
    {tipoSentencia="if";;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 431 "../src/tpi.y"
    {tipoSentencia="if-else";;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 432 "../src/tpi.y"
    {tipoSentencia="switch";;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 435 "../src/tpi.y"
    {tipoSentencia = "while";;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 436 "../src/tpi.y"
    {tipoSentencia="do-while";}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 437 "../src/tpi.y"
    {tipoSentencia = "for";}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 445 "../src/tpi.y"
    {flag_retorno=(yyvsp[(2) - (3)].mystruct).tipo;}
    break;



/* Line 1455 of yacc.c  */
#line 2052 "tpi.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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



/* Line 1675 of yacc.c  */
#line 448 "../src/tpi.y"


ts *tabla_simbolos;

int main (){


        printf("> ");
        inicializar(); //inicializo las listas
        auxVariables.cabeza = NULL;
        auxParametros.cabeza = NULL;
        FILE *f = fopen("salida.txt", "w");        
        yyin=fopen("entrada.c", "r");
        if(!yyparse()){
                printf("\n***Parser completado***\n\n");
                mostrarReporte();
                reporteErrores(&noReconocidos);
                realizarReporte(f);
        }else{
                printf("\nEL parser fallo\n");
        }

        fclose(yyin);
        fclose(f);
        
        
        /* return yyparse(); */
}
