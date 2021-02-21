#ifndef __EECS_SCANNER_HPP
#define __EECS_SCANNER_HPP

#if !defined(yyFlexerOnce)
#include <FlexLexer.h>

#include "grammar.hh"

#include <istream>
using namespace std;
namespace EECS{
class Scammer : yyFlexLexer{
public:
        Scanner(std::istream * in) : yyFlexLexer(in){ 
                lineNum = 0;
                charNum = 0;
        }
        virtual ~Scanner() { }

        virtual int yylex( EECS::Parser::semantic_type * lval);

        void warm(int linNum, int charNum, std::string msg){
                cerr << "lex problem at " << lineNum << "," << charNum << "***WARNING*** " << msg << endl;
        }

        void error(int linNum, int charNum, std::string msg){
                cerr << "lex problem at " << lineNum << "," << charNum << "***ERROR*** " << msg << endl;
        }

private:
        EECS::Parser::Semantic_type *yylval = nullptr; 
        size_t lineNum;
        size_t charNum;
};
}

#endif
