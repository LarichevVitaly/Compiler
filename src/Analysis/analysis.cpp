//
// Created by user on 2/22/16.
//
#include <iostream>
#include "Analysis/analysis.h"

Analysis::Analysis() {
    lex =  new Lex();
}

Analysis::~Analysis() {
    delete lex;
}

bool Analysis::Run(const char * fileName) {
    lex->Run(fileName);
    return true;
}

void Analysis::LogError(std::string str) {
    std::cout << "[Фаза анализа]: " << str << std::endl;
}
