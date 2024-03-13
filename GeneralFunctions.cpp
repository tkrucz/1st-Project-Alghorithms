#include "iostream"
#include "GeneralFunctions.h"
#include "OperatorList.h"
#include "OperandList.h"
#include "Define.cpp"

void whichList(char ch) {
    OperatorList Operators;
    OperandList Operands;
    if (ch == PLUS || ch == MINUS || ch == MULTIPLICATION || ch == DIVISION
        || ch == NEGATION || ch == OPEN_BRACKET || ch == CLOSE_BRACKET) {
        Operators.push_front(ch);
    } else if (ch == SPACE || ch == COMMA)
        std::cout << " ";
    else
        Operands.push_front(int(ch));
}