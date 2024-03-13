#include "iostream"
#include "GeneralFunctions.h"
#include "OperatorList.h"
#include "OperandList.h"
#include "Define.cpp"

void whichList(char ch, OperatorList &Operators, OperandList &Operands) {
    // If the character is a digit, add it to the OperandList
    if (ch >= '0' && ch <= '9') {
        Operands.push_front(int(ch));
    }
        // If the character is an operator or parentheses, add it to the OperatorList
    else if (ch == PLUS || ch == MINUS || ch == MULTIPLICATION || ch == DIVISION
             || ch == NEGATION || ch == OPEN_BRACKET || ch == CLOSE_BRACKET) {
        Operators.push_front(ch);
    }
        // If the character is a space or comma, print a space
    else if (ch == SPACE || ch == COMMA) {
        std::cout << " ";
    }
}
