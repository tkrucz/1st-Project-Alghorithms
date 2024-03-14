#include "iostream"
#include "GeneralFunctions.h"
#include "OperatorList.h"
#include "OperandList.h"
#include "Define.cpp"

void whatOperator(char ch) {
    OperatorList Operators;
    OperandList Operands;
    char op;
    if (ch == CLOSE_BRACKET) {
        Operators.remove_front();
        op = Operators.get_front();
        Operators.remove_front();
    }
    else if(ch == NEGATION)
    {
        
    }
}

void whatOperation(char op) {
    if (op == PLUS) {

    } else if (op == MINUS) {

    } else if (op == MULTIPLICATION) {

    } else if (op == DIVISION) {

    }
}

void whichList(char ch) {
    OperatorList Operators;
    OperandList Operands;
    if (ch >= '0' && ch <= '9') {
        Operands.push_front(int(ch));
    } else if (ch == PLUS || ch == MINUS || ch == MULTIPLICATION || ch == DIVISION
               || ch == NEGATION || ch == OPEN_BRACKET || ch == CLOSE_BRACKET) {
        Operators.push_front(ch);
        whatOperator(ch);
    }
}