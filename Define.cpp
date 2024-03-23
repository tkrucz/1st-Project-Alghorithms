#pragma once
#define MAX_PRIORITY 3
#define MIDDLE_PRIORITY 2
#define LOW_PRIORITY 1
#define ZERO_PRIORITY 0
#define SPACE 32
#define OPEN_BRACKET 40
#define CLOSE_BRACKET 41
#define MULTIPLICATION 42
#define PLUS 43
#define COMMA 44
#define MINUS 45
#define DOT 46
#define DIVISION 47
#define LETTER_A 65
#define LETTER_I 73
#define LETTER_M 77
#define NEGATION 78

struct Equation{
    int nbr;
    char func;
    bool isNumber;
};