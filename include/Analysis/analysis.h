//
// Created by user on 2/22/16.
//

#ifndef COMPILER_ANALYSIS_H
#define COMPILER_ANALYSIS_H
#include "Lex.h"

class Analysis {
    public:
        Analysis();
        ~Analysis();
        bool Run(const char * fileName);

    private:
        void LogError(std::string str);
        Lex * lex;
};


#endif //COMPILER_ANALYSIS_H
