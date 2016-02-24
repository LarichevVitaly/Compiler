#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H
#include <iostream>
#include "Const.h"
#include "Console/Console.h"

class Token
{
    public:
        Token();
        ~Token();
        void Set(std::string value,TokenType type);
        const char * GetStringType();
        const char * GetValue();
    private:
        std::string value;
        TokenType type;
};


#endif //COMPILER_TOKEN_H
