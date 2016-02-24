#include "Compiler.h"

Compiler::Compiler() {
    analyser = new Analysis();
}

Compiler::~Compiler() {
    delete analyser;
}

bool Compiler::Compile(const char * fileName) {
    analyser->Run(fileName);
    return false;
}
