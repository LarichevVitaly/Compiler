#include "Console/Console.h"

Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

/* Log Info */
void Console::LogInfo(const char * logTarget, char const * logInfo)
{
    cout << "[" << logTarget << "]: '" << logInfo << "'" << endl;
}

/* Log Error */
void Console::LogError(const char * logTarget, char const * logError)
{
    cout << "[" << logTarget << "]: '" << logError << "'" << endl;
}
