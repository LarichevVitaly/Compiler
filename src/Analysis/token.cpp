//
// Created by user on 2/22/16.
//
#include <iostream>
#include "Analysis/token.h"


Token::Token()
{
    type = NUMBER; // Тип по Дефолту
    value = "";
}

Token::~Token()
{

}

void Token::Set(std::string tokenValue, TokenType tokenType)
{
    value = tokenValue;
    type = tokenType;
}

const char * Token::GetStringType()
{
    std::string result = "";

    switch(type)
    {
        case NUMBER:
            result = "Цифра";
            break;
        case WORD:
            result = "Слово";
        case ID:
            result = "Переменная";
            break;
        default:
            result = "undefined type";
    }

    return result.c_str();
}

const char * Token::GetValue()
{
    return value.c_str();
}
