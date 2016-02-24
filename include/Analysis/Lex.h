//
// Created by user on 2/22/16.
//
#ifndef COMPILER_LEX_H
#define COMPILER_LEX_H
#include <iostream>
#include <vector>
#include "Const.h"
#include "token.h"


class Lex {
    public:
        Lex();
        ~Lex();
        bool Run(const char * fileName);

    private:
        void AddTokenToList(std::string str, TokenType type);
        void LogTokenList();

        void CreateTable();
        Events GetEventType(char current);
        TokenType GetTokenByState(Statement state);

        std::vector<Token *> tokenList; // Список токенов
        Statement tableTransition[8][11];
};

#endif //COMPILER_LEX_H
