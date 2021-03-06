#ifndef _TOKEN_H
#define _TOKEN_H

#include <string>

class Token {

    public:
        std::string value;
        enum Type {
            TOKEN_ID,               //id -> string literal
            TOKEN_STRING,           //between ""
            TOKEN_CHAR,             //between ''
            TOKEN_INT,              //integer literal
            TOKEN_FLOAT,            //float literal
            TOKEN_HEX,              //hexadecimal literal 0x
            TOKEN_BIN,              //binary literal 0b
            TOKEN_SEMICOLON,        //;
            TOKEN_COMMA,            //,
            TOKEN_DOT,              //.
            TOKEN_COLON,            //:
            TOKEN_LEFT_PAREN,       //(
            TOKEN_RIGHT_PAREN,      //)
            TOKEN_LEFT_BRACKET,     //[
            TOKEN_RIGHT_BRACKET,    //]
            TOKEN_LEFT_BRACE,       //{
            TOKEN_RIGHT_BRACE,      //}
            TOKEN_PLUS,             //+
            TOKEN_INCREASE,         //++
            TOKEN_MINUS,            //-
            TOKEN_DECREASE,         //--
            TOKEN_DIVIDE,           // /
            TOKEN_MULTIPLY,         //*
            TOKEN_POWER,            //**
            TOKEN_MODULO,           //%
            TOKEN_EQUALS,           //=
            TOKEN_DOUBLE_EQUALS,    //==
            TOKEN_GREATER_THAN,     //>
            TOKEN_LESS_THAN,        //<
            TOKEN_GREATER_EQUALS,   //>=
            TOKEN_LESS_EQUALS,      //<=
            TOKEN_CHAIN,            //&
            TOKEN_AND,              //&&
            TOKEN_OR,               //||
            TOKEN_BIT_OR,           //|
            TOKEN_XOR,              //^
            TOKEN_BIT_LEFT_SHIFT,   //<<
            TOKEN_BIT_RIGHT_SHIFT,  //>>
            TOKEN_NEGATE,           //! / not
            TOKEN_IF,               //?
            TOKEN_ELSE_IF,          //&?
            TOKEN_EXTRACT,          //->
            TOKEN_INJECT,           //=>
            TOKEN_PREPROCESSOR,     //#
            TOKEN_CONTAINS_VALUE,   //=?
            TOKEN_CONTAINS_KEY,     //-?
            TOKEN_ADDRESS,          //@
            TOKEN_EOF               //End of file
        } type;
        Token(Token::Type type, std::string value);
        Token(std::string value, Token::Type type);

};

const std::string tokenTypeToStr(Token::Type type);
std::string tokenToStr(Token* token);

#endif