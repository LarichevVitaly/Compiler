#include <iostream>
#include "Compiler.h"
#include "Console/Console.h"
Console * console = new Console();

int main(int argc, char* argv[])
{
    Compiler * compiler = new Compiler();
    string fileName;

    if(argc > 1)
        if(fileName.find(".pas"))
            compiler->Compile(argv[1]);
        else
            console->LogError("Main функция", "Имя файла .pas");
    else
        console->LogError("Мain функция", "Не передан файл");

    return 0;
}
