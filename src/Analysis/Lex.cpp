#include <fstream>
#include "Analysis/Lex.h"
#include "Console/Console.h"

extern Console * console;

Lex::Lex() {

}

Lex::~Lex() {

}

bool Lex::Run(const char * fileName) {
    std::ifstream fileP(fileName);
    Trastition trans = {State_start, State_start, Event_space};
    std::string buffer = "";
    char current;

    CreateTable();

    while(!fileP.eof()){
        fileP.get(current);
        buffer += current;

        trans.currentEvent = GetEventType(current);
        trans.prevState = trans.currentState;
        trans.currentState = tableTransition[trans.currentEvent][trans.currentState];

        // Ошибка
        if(trans.currentState == State_error)
        {
            console->LogError("Лексический анализатор", "Cчитан неизвестный символ");
            exit(1);
        }


        // Создание токена
        if(trans.currentState == State_createToken)
        {
            buffer.erase(buffer.length() - 1);
            AddTokenToList(buffer, GetTokenByState(trans.prevState));
            trans = {State_start, State_start, Event_space};
            buffer.clear();
        }

    }

    if(trans.currentState == State_createToken)
    {
        AddTokenToList(buffer, GetTokenByState(trans.prevState));
        trans = {State_start, State_start, Event_space};
        buffer.clear();
    }

    LogTokenList();
    fileP.close();
    return  true;
}

void Lex::LogTokenList()
{
    if(tokenList.size())
        for(int i = 0; i < tokenList.size(); i++)
            console->LogInfo(tokenList[i]->GetStringType(), tokenList[i]->GetValue());
}

void Lex::AddTokenToList(std::string str, TokenType type)
{
    Token * currentToken = new Token();
    currentToken->Set(str, type);
    tokenList.push_back(currentToken);
}

// Заполение таблицы
void Lex::CreateTable()
{
    // Состояние входа
    tableTransition[Event_digit][State_start] = State_digit;    // Если цифра
    tableTransition[Event_character][State_start] = State_word; // Если цифра
    tableTransition[Event_equal][State_start] = State_createToken;// Равно
    tableTransition[Event_minus][State_start] = State_createToken;// Минус
    tableTransition[Event_plus][State_start] = State_createToken;// Плюс
    tableTransition[Event_semicolon][State_start] = State_createToken;  // ;
    tableTransition[Event_space][State_start] = State_start;     // Пробел
    tableTransition[Event_undefined][State_start] = State_error; // Неопознанный

    // Состояние числа
    tableTransition[Event_digit][State_digit] = State_digit; // Если цифра
    tableTransition[Event_character][State_digit] = State_error; // Если цифра
    tableTransition[Event_equal][State_digit] = State_error;  // Равно
    tableTransition[Event_minus][State_digit] = State_error;  // Минус
    tableTransition[Event_plus][State_digit] = State_error;    // Плюс
    tableTransition[Event_semicolon][State_digit] = State_error;  // ;
    tableTransition[Event_space][State_digit] = State_createToken;// Пробел
    tableTransition[Event_undefined][State_digit] = State_error;  // Ошибка

    // Сотояние слова
    tableTransition[Event_digit][State_word] = State_id; // Если цифра
    tableTransition[Event_character][State_word] = State_word; // Если цифра
    tableTransition[Event_equal][State_word] = State_error;  // Равно
    tableTransition[Event_minus][State_word] = State_error;  // Минус
    tableTransition[Event_plus][State_word] = State_error;    // Плюс
    tableTransition[Event_semicolon][State_word] = State_error;  // ;
    tableTransition[Event_space][State_word] = State_createToken;// Пробел
    tableTransition[Event_undefined][State_word] = State_error;  // Ошибка

    // Состояние переменной
    tableTransition[Event_digit][State_id] = State_id; // Если цифра
    tableTransition[Event_character][State_id] = State_id; // Если цифра
    tableTransition[Event_equal][State_id] = State_error;  // Равно
    tableTransition[Event_minus][State_id] = State_error;  // Минус
    tableTransition[Event_plus][State_id] = State_error;    // Плюс
    tableTransition[Event_semicolon][State_id] = State_error;  // ;
    tableTransition[Event_space][State_id] = State_createToken;// Пробел
    tableTransition[Event_undefined][State_id] = State_error;  // Ошибка
}

// Возвращаем тип события по символу
Events Lex::GetEventType(char current)
{
    Events event = Event_undefined;

    if(std::isalpha(current))
        event = Event_character;
    if(std::isdigit(current))
        event = Event_digit;
    if(std::isspace(current))
        event = Event_space;
    if(current == ';')
        event = Event_semicolon;
    if(current == '=')
        event = Event_equal;
    if(current == '+')
        event = Event_plus;
    if(current == '-')
        event = Event_minus;

    return event;
}

// Получение типа токена по состоянию
TokenType Lex::GetTokenByState(Statement state)
{
    TokenType tokenType;

    if(state == State_digit)
        tokenType = NUMBER;
    if(state == State_word)
        tokenType = WORD;
    if(state == State_id)
        tokenType = ID;
    if(state == State_plus)
        tokenType = PLUS;
    if(state == State_minus)
        tokenType = MINUS;
    if(state == State_equal)
        tokenType = EQUAL;
    if(state == State_semicolon)
        tokenType = SEMICOLON;

    return tokenType;
}
