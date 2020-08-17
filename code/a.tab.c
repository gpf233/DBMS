
/*  A Bison parser, made from a.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	ID	257
#define	STRING	258
#define	NUMBER	259
#define	CREATE	260
#define	TABLE	261
#define	CHAR	262
#define	INT	263
#define	SELECT	264
#define	FROM	265
#define	WHERE	266
#define	INSERT	267
#define	INTO	268
#define	VALUES	269
#define	DELETE	270
#define	UPDATE	271
#define	SET	272
#define	DATABASE	273
#define	DATABASES	274
#define	USE	275
#define	SHOW	276
#define	TABLES	277
#define	DROP	278
#define	EXIT	279
#define	OR	280
#define	AND	281

#line 1 "a.y"

#include "func.h"
#include "share.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* currentdatabase = NULL;
struct Fieldsdef* lastfield = NULL;
struct Strings* laststring = NULL;
struct Stringss* laststrings = NULL;
struct KVs* lastkv = NULL;
struct Selectedfields* lastsf = NULL;

#line 15 "a.y"
typedef union {
    char char_var;
    char* string;
    int int_var;
    struct Fieldsdef* fieldsdef_var;
    struct Createsql* createsql_var;
    struct Strings* strings_var;
    struct Stringss* stringss_var;
    struct Insertsql* insertsql_var;
    struct Deletesql* deletesql_var;
    struct Selectedfields* sf_var;
    struct Conditions* cons_var;
    struct KVs* kvs_var;
    struct Updatesql* updatesql_var;
    struct Selectsql* selectsql_var;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		143
#define	YYFLAG		-32768
#define	YYNTBASE	38

#define YYTRANSLATE(x) ((unsigned)(x) <= 281 ? yytranslate[x] : 73)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    35,     2,     2,     2,     2,     2,     2,    29,
    30,    37,     2,    31,     2,    36,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    28,    32,
    34,    33,     2,     2,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     5,     7,     9,    11,    13,    15,    17,    19,
    21,    23,    25,    27,    29,    34,    38,    42,    47,    55,
    59,    61,    64,    69,    71,    75,    80,    87,    97,   101,
   103,   107,   111,   113,   115,   117,   121,   123,   125,   130,
   137,   139,   143,   147,   151,   155,   157,   159,   161,   163,
   165,   167,   169,   172,   174,   178,   184,   192,   196,   198,
   202,   206,   212,   220,   222,   224,   228,   230,   234,   236,
   238
};

static const short yyrhs[] = {    38,
    39,     0,    39,     0,    40,     0,    41,     0,    42,     0,
    43,     0,    44,     0,    48,     0,    49,     0,    50,     0,
    57,     0,    64,     0,    67,     0,    72,     0,     6,    19,
     3,    28,     0,    22,    20,    28,     0,    21,     3,    28,
     0,    24,    19,     3,    28,     0,     6,     7,     3,    29,
    45,    30,    28,     0,    45,    31,    46,     0,    46,     0,
     3,    47,     0,     8,    29,     5,    30,     0,     9,     0,
    22,    23,    28,     0,    24,     7,     3,    28,     0,    13,
    14,     3,    15,    51,    28,     0,    13,    14,     3,    29,
    55,    30,    15,    51,    28,     0,    51,    31,    52,     0,
    52,     0,    29,    53,    30,     0,    53,    31,    54,     0,
    54,     0,     5,     0,     4,     0,    55,    31,    56,     0,
    56,     0,     3,     0,    16,    11,     3,    28,     0,    16,
    11,     3,    12,    58,    28,     0,    59,     0,    29,    58,
    30,     0,    58,    27,    58,     0,    58,    26,    58,     0,
    60,    62,    61,     0,    63,     0,    63,     0,     5,     0,
     4,     0,    32,     0,    33,     0,    34,     0,    35,    34,
     0,     3,     0,     3,    36,     3,     0,    17,     3,    18,
    65,    28,     0,    17,     3,    18,    65,    12,    58,    28,
     0,    65,    31,    66,     0,    66,     0,     3,    34,     5,
     0,     3,    34,     4,     0,    10,    68,    11,    70,    28,
     0,    10,    68,    11,    70,    12,    58,    28,     0,    69,
     0,    37,     0,    69,    31,    63,     0,    63,     0,    70,
    31,    71,     0,    71,     0,     3,     0,    25,    28,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    53,    53,    54,    58,    61,    65,    69,    85,    88,    92,
   115,   121,   136,   158,   163,   167,   171,   175,   179,   184,
   188,   193,   198,   203,   209,   213,   217,   225,   232,   237,
   243,   249,   254,   260,   267,   273,   278,   284,   291,   296,
   301,   304,   307,   315,   323,   335,   342,   349,   356,   362,
   365,   368,   371,   374,   380,   387,   393,   399,   403,   408,
   415,   422,   429,   436,   440,   444,   449,   455,   460,   466,
   472
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","ID","STRING",
"NUMBER","CREATE","TABLE","CHAR","INT","SELECT","FROM","WHERE","INSERT","INTO",
"VALUES","DELETE","UPDATE","SET","DATABASE","DATABASES","USE","SHOW","TABLES",
"DROP","EXIT","OR","AND","';'","'('","')'","','","'<'","'>'","'='","'!'","'.'",
"'*'","statements","statement","createdatabase","showdatabases","usedatabase",
"dropdatabase","createsql","fieldsdef","field_type","type","showtables","droptable",
"insertsql","tuples","tuple","values","value","columns","column","deletesql",
"conditions","condition","comp_left","comp_right","comp_op","table_field","updatesql",
"assignments","assignment","selectsql","fields_star","table_fields","tables",
"table","exit", NULL
};
#endif

static const short yyr1[] = {     0,
    38,    38,    39,    39,    39,    39,    39,    39,    39,    39,
    39,    39,    39,    39,    40,    41,    42,    43,    44,    45,
    45,    46,    47,    47,    48,    49,    50,    50,    51,    51,
    52,    53,    53,    54,    54,    55,    55,    56,    57,    57,
    58,    58,    58,    58,    59,    60,    61,    61,    61,    62,
    62,    62,    62,    63,    63,    64,    64,    65,    65,    66,
    66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
    72
};

static const short yyr2[] = {     0,
     2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     4,     3,     3,     4,     7,     3,
     1,     2,     4,     1,     3,     4,     6,     9,     3,     1,
     3,     3,     1,     1,     1,     3,     1,     1,     4,     6,
     1,     3,     3,     3,     3,     1,     1,     1,     1,     1,
     1,     1,     2,     1,     3,     5,     7,     3,     1,     3,
     3,     5,     7,     1,     1,     3,     1,     3,     1,     1,
     2
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    12,    13,    14,     0,     0,    54,    65,    67,     0,    64,
     0,     0,     0,     0,     0,     0,     0,     0,    71,     1,
     0,     0,     0,     0,     0,     0,     0,     0,    17,    16,
    25,     0,     0,     0,    15,    55,    70,     0,    69,    66,
     0,     0,     0,    39,     0,     0,    59,    26,    18,     0,
     0,    21,     0,    62,     0,     0,     0,    30,    38,     0,
    37,     0,     0,    41,     0,    46,     0,     0,    56,     0,
     0,    24,    22,     0,     0,     0,    68,    35,    34,     0,
    33,    27,     0,     0,     0,     0,     0,     0,    40,    50,
    51,    52,     0,     0,    61,    60,     0,    58,     0,    19,
    20,    63,    31,     0,    29,     0,    36,    42,    44,    43,
    53,    49,    48,    45,    47,    57,     0,    32,     0,    23,
    28,     0,     0
};

static const short yydefgoto[] = {    10,
    11,    12,    13,    14,    15,    16,    71,    72,    93,    17,
    18,    19,    77,    78,   100,   101,    80,    81,    20,    83,
    84,    85,   134,   114,    86,    21,    66,    67,    22,    29,
    30,    58,    59,    23
};

static const short yypact[] = {    28,
     6,     0,    -7,     1,    11,    65,   -14,    35,    -9,     5,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    80,    81,    -3,-32768,-32768,    78,    59,
    88,    89,    75,    66,    67,    68,    94,    95,-32768,-32768,
    70,    72,    98,    99,   100,     2,    -4,   101,-32768,-32768,
-32768,    77,    79,   103,-32768,-32768,-32768,    -8,-32768,-32768,
    82,   105,    -1,-32768,    76,    20,-32768,-32768,-32768,    31,
    16,-32768,    -1,-32768,    99,    53,    38,-32768,-32768,    55,
-32768,    -1,    45,-32768,    30,-32768,    56,    -1,-32768,   101,
    84,-32768,-32768,    86,   103,    48,-32768,-32768,-32768,    57,
-32768,-32768,    82,   102,   105,    29,    -1,    -1,-32768,-32768,
-32768,-32768,    85,    74,-32768,-32768,    54,-32768,   104,-32768,
-32768,-32768,-32768,    53,-32768,    82,-32768,-32768,    91,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    90,-32768,    39,-32768,
-32768,   115,-32768
};

static const short yypgoto[] = {-32768,
   106,-32768,-32768,-32768,-32768,-32768,-32768,    26,-32768,-32768,
-32768,-32768,     3,    19,-32768,     4,-32768,    18,-32768,   -72,
-32768,-32768,-32768,-32768,    -2,-32768,-32768,    34,-32768,-32768,
-32768,-32768,    50,-32768
};


#define	YYLAST		129


static const short yytable[] = {    28,
    96,    26,    26,    73,   142,    35,    31,    63,    36,   106,
     1,    32,    24,    33,     2,   117,    61,     3,    39,    74,
     4,     5,    75,    64,    25,     6,     7,    82,     8,     9,
    62,    88,    43,     1,   129,   130,    27,     2,    91,    92,
     3,    37,    60,     4,     5,    94,    95,    89,     6,     7,
    90,     8,     9,    38,   107,   108,    98,    99,   128,   115,
   116,   110,   111,   112,   113,   102,   141,    34,   103,   103,
   107,   108,   109,   107,   108,   122,    26,   132,   133,   107,
   108,   136,    41,    42,   104,   105,   123,   124,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    26,    65,    68,    70,    69,    79,   137,    87,
    76,   135,   119,   120,   143,    40,   126,   108,   131,   140,
   121,   125,   127,   118,    97,     0,     0,   138,   139
};

static const short yycheck[] = {     2,
    73,     3,     3,    12,     0,    20,    14,    12,    23,    82,
     6,    11,     7,     3,    10,    88,    15,    13,    28,    28,
    16,    17,    31,    28,    19,    21,    22,    29,    24,    25,
    29,    12,    36,     6,   107,   108,    37,    10,     8,     9,
    13,     7,    45,    16,    17,    30,    31,    28,    21,    22,
    31,    24,    25,    19,    26,    27,     4,     5,    30,     4,
     5,    32,    33,    34,    35,    28,    28,     3,    31,    31,
    26,    27,    28,    26,    27,    28,     3,     4,     5,    26,
    27,    28,     3,     3,    30,    31,    30,    31,    11,    31,
     3,     3,    18,    28,    28,    28,     3,     3,    29,    28,
     3,     3,     3,     3,    28,     3,    28,     3,     5,    34,
    29,   114,    29,    28,     0,    10,    15,    27,    34,    30,
    95,   103,   105,    90,    75,    -1,    -1,   124,   126
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 3:
#line 54 "a.y"
{
    createdatabasefunc(yyvsp[0].string);
    free(yyvsp[0].string);
;
    break;}
case 4:
#line 58 "a.y"
{
    showdatabasesfunc();
;
    break;}
case 5:
#line 61 "a.y"
{
    usedatabasefunc(yyvsp[0].string);
    free(yyvsp[0].string);
;
    break;}
case 6:
#line 65 "a.y"
{
    dropdatabasefunc(yyvsp[0].string);
    free(yyvsp[0].string);
;
    break;}
case 7:
#line 69 "a.y"
{
    createsqlfunc(yyvsp[0].createsql_var);
    free(yyvsp[0].createsql_var->table);
    while (yyvsp[0].createsql_var->fdef->next_fdef) {
        struct Fieldsdef *temp = yyvsp[0].createsql_var->fdef->next_fdef;
        yyvsp[0].createsql_var->fdef->next_fdef = yyvsp[0].createsql_var->fdef->next_fdef->next_fdef;
        //printf("释放字段%s空间。\n", temp->field);
        free(temp->field);
        free(temp);
    }
    //printf("释放字段头节点空间。\n");
    free(yyvsp[0].createsql_var->fdef);
    //printf("删除表%s。\n", $1->table);
    free(yyvsp[0].createsql_var);
    //printf("空间清理完毕。\n");
;
    break;}
case 8:
#line 85 "a.y"
{
    showtablesfunc();
;
    break;}
case 9:
#line 88 "a.y"
{
    droptablefunc(yyvsp[0].string);
    free(yyvsp[0].string);
;
    break;}
case 10:
#line 92 "a.y"
{
    //printf("insertsql -> statement\n");
    insertsqlfunc(yyvsp[0].insertsql_var);
    free(yyvsp[0].insertsql_var->table);
    while (yyvsp[0].insertsql_var->column->next_string) {
        struct Strings* temp = yyvsp[0].insertsql_var->column->next_string;
        yyvsp[0].insertsql_var->column->next_string = yyvsp[0].insertsql_var->column->next_string->next_string;
        free(temp);
    }
    free(yyvsp[0].insertsql_var->column);
    while (yyvsp[0].insertsql_var->tuples->next_strings) {
        struct Stringss* temp = yyvsp[0].insertsql_var->tuples->next_strings;
        yyvsp[0].insertsql_var->tuples->next_strings = yyvsp[0].insertsql_var->tuples->next_strings->next_strings;
        while (temp->strings->next_string) {
            struct Strings* tmp = temp->strings->next_string;
            temp->strings->next_string = temp->strings->next_string->next_string;
            free(tmp);
        }
        free(temp);
    }
    free(yyvsp[0].insertsql_var->tuples);
    free(yyvsp[0].insertsql_var);
;
    break;}
case 11:
#line 115 "a.y"
{
    deletesqlfunc(yyvsp[0].deletesql_var);
    free(yyvsp[0].deletesql_var->table);
    myfree(yyvsp[0].deletesql_var->conditions);
    free(yyvsp[0].deletesql_var);
;
    break;}
case 12:
#line 121 "a.y"
{
    updatesqlfunc(yyvsp[0].updatesql_var);
    free(yyvsp[0].updatesql_var->table);
    struct KVs* cur = yyvsp[0].updatesql_var->kvs;
    while (cur->next_kv) {
        struct KVs* temp = cur->next_kv;
        cur->next_kv = cur->next_kv->next_kv;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
    free(cur->next_kv);
    myfree(yyvsp[0].updatesql_var->conditions);
    free(yyvsp[0].updatesql_var);
;
    break;}
case 13:
#line 136 "a.y"
{
    //printf("识别select语句\n");
    selectsqlfunc(yyvsp[0].selectsql_var);
    struct Selectedfields* cur = yyvsp[0].selectsql_var->sf;
    /*if (!cur) {
        while (cur->next_sf) {
            struct Selectedfields* temp = cur->next_sf;
            cur->next_sf = cur->next_sf->next_sf;
            free(temp->table);
            free(temp->field);
        }
        free(cur);
    }*/
    struct Strings* curr = yyvsp[0].selectsql_var->st;
    while (curr->next_string) {
        struct Strings* temp = curr->next_string;
        curr->next_string = curr->next_string->next_string;
        free(temp->string);
    }
    free(curr);
    myfree(yyvsp[0].selectsql_var->conditions);
;
    break;}
case 14:
#line 158 "a.y"
{
    printf("bye bye~\n");
    return 0;
;
    break;}
case 15:
#line 163 "a.y"
{
    yyval.string = yyvsp[-1].string;
;
    break;}
case 16:
#line 167 "a.y"
{

;
    break;}
case 17:
#line 171 "a.y"
{
    yyval.string = yyvsp[-1].string
;
    break;}
case 18:
#line 175 "a.y"
{
    yyval.string = yyvsp[-1].string
;
    break;}
case 19:
#line 179 "a.y"
{
    yyval.createsql_var = (struct Createsql *) malloc(sizeof(struct Createsql));
    yyval.createsql_var->table = yyvsp[-4].string;
    yyval.createsql_var->fdef = yyvsp[-2].fieldsdef_var;
;
    break;}
case 20:
#line 184 "a.y"
{
    lastfield->next_fdef = yyvsp[0].fieldsdef_var;
    lastfield = yyvsp[0].fieldsdef_var;
;
    break;}
case 21:
#line 188 "a.y"
{
    yyval.fieldsdef_var = (struct Fieldsdef *) malloc(sizeof(struct Fieldsdef));//headnode
    yyval.fieldsdef_var->next_fdef = yyvsp[0].fieldsdef_var;
    lastfield = yyvsp[0].fieldsdef_var;
;
    break;}
case 22:
#line 193 "a.y"
{
    yyval.fieldsdef_var = yyvsp[0].fieldsdef_var;
    yyval.fieldsdef_var->field = yyvsp[-1].string;
    yyval.fieldsdef_var->next_fdef = NULL;
;
    break;}
case 23:
#line 198 "a.y"
{
    yyval.fieldsdef_var = (struct Fieldsdef *) malloc(sizeof(struct Fieldsdef));
    yyval.fieldsdef_var->type = TYPE_CHAR;
    yyval.fieldsdef_var->length = yyvsp[-1].int_var;
;
    break;}
case 24:
#line 203 "a.y"
{
    yyval.fieldsdef_var = (struct Fieldsdef *) malloc(sizeof(struct Fieldsdef));
    yyval.fieldsdef_var->type = TYPE_INT;
    yyval.fieldsdef_var->length = 0;
;
    break;}
case 25:
#line 209 "a.y"
{

;
    break;}
case 26:
#line 213 "a.y"
{
    yyval.string = yyvsp[-1].string;
;
    break;}
case 27:
#line 217 "a.y"
{
    //printf("INSERT INTO ID VALUES tuples; -> insertsql\n");
    yyval.insertsql_var = (struct Insertsql*)malloc(sizeof(struct Insertsql));
    yyval.insertsql_var->table = yyvsp[-3].string;
    yyval.insertsql_var->column = (struct Strings*)malloc(sizeof(struct Strings));
    yyval.insertsql_var->column->next_string = NULL;
    yyval.insertsql_var->tuples = yyvsp[-1].stringss_var;
;
    break;}
case 28:
#line 225 "a.y"
{
    //printf("INSERT INTO ID (columns) VALUES tuples; -> insertsql\n");
    yyval.insertsql_var = (struct Insertsql*)malloc(sizeof(struct Insertsql));
    yyval.insertsql_var->table = yyvsp[-6].string;
    yyval.insertsql_var->column = yyvsp[-4].strings_var;
    yyval.insertsql_var->tuples = yyvsp[-1].stringss_var;
;
    break;}
case 29:
#line 232 "a.y"
{
    //printf("tuples, tuple -> tuples\n");
    laststrings->next_strings = yyvsp[0].stringss_var;
    laststrings = yyvsp[0].stringss_var;
;
    break;}
case 30:
#line 237 "a.y"
{
    //printf("tuple -> tuples\n");
    yyval.stringss_var = (struct Stringss *) malloc(sizeof(struct Stringss));//headnode
    yyval.stringss_var->next_strings = yyvsp[0].stringss_var;
    laststrings = yyvsp[0].stringss_var;
;
    break;}
case 31:
#line 243 "a.y"
{
    //printf("(values) -> tuple\n");
    yyval.stringss_var = (struct Stringss *) malloc(sizeof(struct Stringss));
    yyval.stringss_var->strings = yyvsp[-1].strings_var;
    yyval.stringss_var->next_strings = NULL;
;
    break;}
case 32:
#line 249 "a.y"
{
    //printf("values, value -> values\n");
    laststring->next_string = yyvsp[0].strings_var;
    laststring = yyvsp[0].strings_var;
;
    break;}
case 33:
#line 254 "a.y"
{
    //printf("value -> values\n");
    yyval.strings_var = (struct Strings *) malloc(sizeof(struct Strings));//headnode
    yyval.strings_var->next_string = yyvsp[0].strings_var;
    laststring = yyvsp[0].strings_var;
;
    break;}
case 34:
#line 260 "a.y"
{
    //printf("NUMBER -> value\n");
    yyval.strings_var = (struct Strings *) malloc(sizeof(struct Strings));
    char buffer[1024];
    yyval.strings_var->string = strdup(itoa(yyvsp[0].int_var, buffer, 10));
    yyval.strings_var->next_string = NULL;
;
    break;}
case 35:
#line 267 "a.y"
{
    //printf("STRING -> value\n");
    yyval.strings_var = (struct Strings *) malloc(sizeof(struct Strings));
    yyval.strings_var->string = yyvsp[0].string;
    yyval.strings_var->next_string = NULL;
;
    break;}
case 36:
#line 273 "a.y"
{
    //printf("columns, column -> columns\n");
    laststring->next_string = yyvsp[0].strings_var;
    laststring = yyvsp[0].strings_var;
;
    break;}
case 37:
#line 278 "a.y"
{
    //printf("column -> columns\n");
    yyval.strings_var = (struct Strings *) malloc(sizeof(struct Strings));//headnode
    yyval.strings_var->next_string = yyvsp[0].strings_var;
    laststring = yyvsp[0].strings_var;
;
    break;}
case 38:
#line 284 "a.y"
{
    //printf("ID -> column\n");
    yyval.strings_var = (struct Strings *) malloc(sizeof(struct Strings));
    yyval.strings_var->string = yyvsp[0].string;
    yyval.strings_var->next_string = NULL;
;
    break;}
case 39:
#line 291 "a.y"
{
    yyval.deletesql_var = (struct Deletesql*)malloc(sizeof(struct Deletesql));
    yyval.deletesql_var->table = yyvsp[-1].string;
    yyval.deletesql_var->conditions = NULL;
;
    break;}
case 40:
#line 296 "a.y"
{
    yyval.deletesql_var = (struct Deletesql*)malloc(sizeof(struct Deletesql));
    yyval.deletesql_var->table = yyvsp[-3].string;
    yyval.deletesql_var->conditions = yyvsp[-1].cons_var;
;
    break;}
case 41:
#line 301 "a.y"
{
    yyval.cons_var = yyvsp[0].cons_var;
;
    break;}
case 42:
#line 304 "a.y"
{
    yyval.cons_var = yyvsp[-1].cons_var;
;
    break;}
case 43:
#line 307 "a.y"
{
    yyval.cons_var = (struct Conditions*)malloc(sizeof(struct Conditions));
    yyval.cons_var->left = yyvsp[-2].cons_var;
    yyval.cons_var->cmp = 'a';
    yyval.cons_var->right = yyvsp[0].cons_var;
    yyval.cons_var->table = NULL;
    yyval.cons_var->value = NULL;
;
    break;}
case 44:
#line 315 "a.y"
{
    yyval.cons_var = (struct Conditions*)malloc(sizeof(struct Conditions));
    yyval.cons_var->left = yyvsp[-2].cons_var;
    yyval.cons_var->cmp = 'o';
    yyval.cons_var->right = yyvsp[0].cons_var;
    yyval.cons_var->table = NULL;
    yyval.cons_var->value = NULL;
;
    break;}
case 45:
#line 323 "a.y"
{
    yyval.cons_var = (struct Conditions*)malloc(sizeof(struct Conditions));
    yyval.cons_var->left = yyvsp[-2].cons_var;
    yyval.cons_var->cmp = yyvsp[-1].char_var;
    yyval.cons_var->right = yyvsp[0].cons_var;
    yyval.cons_var->table = NULL;
    yyval.cons_var->value = NULL;
    yyvsp[-2].cons_var->left = NULL;
    yyvsp[-2].cons_var->right = NULL;
    yyvsp[0].cons_var->left = NULL;
    yyvsp[0].cons_var->right = NULL;
;
    break;}
case 46:
#line 335 "a.y"
{
    yyval.cons_var = (struct Conditions*)malloc(sizeof(struct Conditions));
    yyval.cons_var->type = 0;
    yyval.cons_var->value = yyvsp[0].sf_var->field;
    yyval.cons_var->table = yyvsp[0].sf_var->table;
    free(yyvsp[0].sf_var);
;
    break;}
case 47:
#line 342 "a.y"
{
    yyval.cons_var = (struct Conditions*)malloc(sizeof(struct Conditions));
    yyval.cons_var->type = 0;
    yyval.cons_var->value = yyvsp[0].sf_var->field;
    yyval.cons_var->table = yyvsp[0].sf_var->table;
    free(yyvsp[0].sf_var);
;
    break;}
case 48:
#line 349 "a.y"
{
    yyval.cons_var = (struct Conditions*)malloc(sizeof(struct Conditions));
    char buffer[1024];
    yyval.cons_var->type = 2;
    yyval.cons_var->value = strdup(itoa(yyvsp[0].int_var, buffer, 10));
    yyval.cons_var->table = NULL;
;
    break;}
case 49:
#line 356 "a.y"
{
    yyval.cons_var = (struct Conditions*)malloc(sizeof(struct Conditions));
    yyval.cons_var->type = 1;
    yyval.cons_var->value = yyvsp[0].string;
    yyval.cons_var->table = NULL;
;
    break;}
case 50:
#line 362 "a.y"
{
    yyval.char_var = '<';
;
    break;}
case 51:
#line 365 "a.y"
{
    yyval.char_var = '>';
;
    break;}
case 52:
#line 368 "a.y"
{
    yyval.char_var = '=';
;
    break;}
case 53:
#line 371 "a.y"
{
    yyval.char_var = '!';
;
    break;}
case 54:
#line 374 "a.y"
{
    yyval.sf_var = (struct Selectedfields*)malloc(sizeof(struct Selectedfields));
    yyval.sf_var->field = yyvsp[0].string;
    yyval.sf_var->table = NULL;
    yyval.sf_var->next_sf = NULL;
;
    break;}
case 55:
#line 380 "a.y"
{
    yyval.sf_var = (struct Selectedfields*)malloc(sizeof(struct Selectedfields));
    yyval.sf_var->field = yyvsp[0].string;
    yyval.sf_var->table = yyvsp[-2].string;
    yyval.sf_var->next_sf = NULL;
;
    break;}
case 56:
#line 387 "a.y"
{
    yyval.updatesql_var = (struct Updatesql*)malloc(sizeof(struct Updatesql));
    yyval.updatesql_var->table = yyvsp[-3].string;
    yyval.updatesql_var->kvs = yyvsp[-1].kvs_var;
    yyval.updatesql_var->conditions = NULL;
;
    break;}
case 57:
#line 393 "a.y"
{
    yyval.updatesql_var = (struct Updatesql*)malloc(sizeof(struct Updatesql));
    yyval.updatesql_var->table = yyvsp[-5].string;
    yyval.updatesql_var->kvs = yyvsp[-3].kvs_var;
    yyval.updatesql_var->conditions = yyvsp[-1].cons_var;
;
    break;}
case 58:
#line 399 "a.y"
{
    lastkv->next_kv = yyvsp[0].kvs_var;
    lastkv = yyvsp[0].kvs_var;
;
    break;}
case 59:
#line 403 "a.y"
{
    yyval.kvs_var = (struct KVs*)malloc(sizeof(struct KVs));//headnode
    yyval.kvs_var->next_kv = yyvsp[0].kvs_var;
    lastkv = yyvsp[0].kvs_var;
;
    break;}
case 60:
#line 408 "a.y"
{
    yyval.kvs_var = (struct KVs*)malloc(sizeof(struct KVs));
    char buffer[1024];
    yyval.kvs_var->key = yyvsp[-2].string;
    yyval.kvs_var->value = strdup(itoa(yyvsp[0].int_var, buffer, 10));
    yyval.kvs_var->next_kv = NULL;
;
    break;}
case 61:
#line 415 "a.y"
{
    yyval.kvs_var = (struct KVs*)malloc(sizeof(struct KVs));
    yyval.kvs_var->key = yyvsp[-2].string;
    yyval.kvs_var->value = yyvsp[0].string;
    yyval.kvs_var->next_kv = NULL;
;
    break;}
case 62:
#line 422 "a.y"
{
    //printf("SELECT fields_star FROM tables; -> selectsql\n");
    yyval.selectsql_var = (struct Selectsql*)malloc(sizeof(struct Selectsql));
    yyval.selectsql_var->sf = yyvsp[-3].sf_var;
    yyval.selectsql_var->st = yyvsp[-1].strings_var;
    yyval.selectsql_var->conditions = NULL;
;
    break;}
case 63:
#line 429 "a.y"
{
    //printf("SELECT fields_star FROM tables WHERE conditions; -> selectsql\n");
    yyval.selectsql_var = (struct Selectsql*)malloc(sizeof(struct Selectsql));
    yyval.selectsql_var->sf = yyvsp[-5].sf_var;
    yyval.selectsql_var->st = yyvsp[-3].strings_var;
    yyval.selectsql_var->conditions = yyvsp[-1].cons_var;
;
    break;}
case 64:
#line 436 "a.y"
{
    //printf("table_fields -> fields_star\n");
    yyval.sf_var = yyvsp[0].sf_var;
;
    break;}
case 65:
#line 440 "a.y"
{
    //printf("* -> fields_star\n");
    yyval.sf_var = NULL;
;
    break;}
case 66:
#line 444 "a.y"
{
    //printf("table_fields, table_field -> table_fields\n");
    lastsf->next_sf = yyvsp[0].sf_var;
    lastsf = yyvsp[0].sf_var;
;
    break;}
case 67:
#line 449 "a.y"
{
    //printf("table_field -> table_fields\n");
    yyval.sf_var = (struct Selectedfields*)malloc(sizeof(struct Selectedfields));
    yyval.sf_var->next_sf = yyvsp[0].sf_var;
    lastsf = yyvsp[0].sf_var;
;
    break;}
case 68:
#line 455 "a.y"
{
    //printf("tables, table -> tables\n");
    laststring->next_string = yyvsp[0].strings_var;
    laststring = yyvsp[0].strings_var;
;
    break;}
case 69:
#line 460 "a.y"
{
    //printf("table -> tables\n");
    yyval.strings_var = (struct Strings*)malloc(sizeof(struct Strings));
    yyval.strings_var->next_string = yyvsp[0].strings_var;
    laststring = yyvsp[0].strings_var;
;
    break;}
case 70:
#line 466 "a.y"
{
    //printf("ID -> table\n");
    yyval.strings_var = (struct Strings*)malloc(sizeof(struct Strings));
    yyval.strings_var->string = yyvsp[0].string;
    yyval.strings_var->next_string = NULL;
;
    break;}
case 71:
#line 472 "a.y"
{

;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 476 "a.y"

void yyerror(char *msg) {
    printf("error msg: %s.", msg);
}
int main() {
    return yyparse();
}
