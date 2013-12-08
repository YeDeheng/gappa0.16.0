/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
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



/* Line 2068 of yacc.c  */
#line 117 "parser/parser.h"
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



