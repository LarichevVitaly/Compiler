//
// Created by user on 2/22/16.
//

#ifndef COMPILER_COMPILER_H
#define COMPILER_COMPILER_H

#include "Analysis/analysis.h"

class Compiler {
    public:
        Compiler();
        ~Compiler();
        bool Compile(const char * fileName);

    private:
        Analysis * analyser;

};

#endif //COMPILER_COMPILER_H
