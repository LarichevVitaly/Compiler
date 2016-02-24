//
// Created by user on 2/22/16.
//

#ifndef COMPILER_CONST_H
#define COMPILER_CONST_H

// Типы токенов
enum TokenType {
    NUMBER,     // Переменная
    ID,         // Константа
    WORD,       // Слово
    PLUS,       // +
    MINUS,      // -
    EQUAL,      // =
    DO,         // do
    WHILE,      // while
    SEMICOLON,  // ;
    BEGIN,      // BEGIN
    END,        // END
    LASTEND,    // END.
};

// Событие
enum Events{
    Event_digit,     // Цифра
    Event_character, // Буква
    Event_space,    // Пробел
    Event_plus,     // Плюс
    Event_minus,    // Минус
    Event_semicolon,// ;
    Event_equal,    // =
    Event_undefined // Ошибка
};

// Состояния
enum Statement{
    State_start,        // Состояние на входе
    State_id,           // Идентификатор
    State_word,         // Константы
    State_digit,        // Переменная
    State_space,        // Пробел
    State_plus,         // +
    State_equal,        // =
    State_semicolon,    // ;
    State_minus,         // Минус
    State_createToken,  // Запись токена
    State_error,      // Ошибка
};

// Тип для элемента прохода
struct Trastition{
    Statement prevState;    // Предыдущее состояние
    Statement currentState; // Состояние
    Events currentEvent;    // Событие
};

#endif //COMPILER_CONST_H
