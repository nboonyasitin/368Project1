%skeleton "lalr1.cc"
%require "3.0"
%debug
%defines
%defines api.namespace {EECS}
%define parser_class_name {Parser}
%output "parser.cc"
%token-table

%code requires{
        namespace EECS {
                class Manager;
                class Scanner;
                class MathNode;
        }

#ifndef YY_NULLPTR
#define YY_NULPTR 0
#endif
}

%parse-param { Scanner * scanner}
%parse-param { Manager * manager}

%code {
        #include <iostream>
        #include "string.h"
        #include <fstream>
        #include <cstdlib>

        #include "calc.hpp"

        #undef yylex
        #define yylex scanner->yylex
}

%union {
        MathNode * transNode;
        bool transGood;
        int intVal;
}

%token END  0
%token LPAR
%token RPAR
%token PLUS
%token MINUS
%token DIV
%token MULT
%token <intVal> INLIT

%left PLUS MINUS
%left MULT DIV
%precedence NEG


%%type <transNode> Expr
%%type <transGood> Equation



%%
Equation : Expr END { 
                $$ = true;
                cout << "expression value: " << child->print() << "\n";
                }

Expr    : Expr PLUS Expr        { /* $$ = $1 + $3; */}
        | Expr MINUS Expr       { /* $$ = $1 - $3; */}
        | Expr DIV Expr         { /* $$ = $1 / $3; */}
        | Expr MULT Expr        { 
                                        MathNode * arm1 = $1;
                                        MathNode * arm1 = $2;
                                        $$ = new MultNode("arm1", arm1, "arm2", arm2); 
                                }
        | NEG Expr              { /* $$ = -$2; */}
        | INTLIT                { $$ = new EECS::IntNode($1); }
        | LPAR Sum RPAR         { /* $$ = $2; */}
%%

void
EECS::Parser::error(const std::string &err_message){
        std::cerr << "Parse Error: " << err_message << "\n";
}