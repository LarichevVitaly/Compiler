#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
using namespace std;

/*========
Loger class
==========*/

class Console
{
    public:
        Console();
       ~Console();
       void LogInfo(const char * logTarget,const char * logInfo);
       void LogError(const char * logTarget, const char * logError);
};


#endif // CONSOLE_H
