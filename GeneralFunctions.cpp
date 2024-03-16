#include "iostream"
#include "GeneralFunctions.h"
#include "List.h"
#include "Define.cpp"

void whatOperator(char ch) {

    if (ch == CLOSE_BRACKET) {

    } else if (ch == NEGATION) {

    }
}

void whatOperation(char op, List<int> &stack) {
    int left, right;
    left = stack.remove_front();
    right = stack.remove_front();
    if (op == PLUS) {
        stack.push_front(addition(left,right));
    } else if (op == MINUS) {
        stack.push_front(subtraction(left, right));
    } else if (op == MULTIPLICATION) {
        stack.push_front(multiplication(left, right));
    } else if (op == DIVISION) {
        stack.push_front(division(left, right));
    }
}

int addition(int left, int right) {
    return left + right;
}

int subtraction(int left, int right) {
    return right - left;
}

int multiplication(int left, int right) {
    return left * right;
}

int division(int left, int right) {
    return right / left;
}

void whichList(char ch) {
    List<char> Operators;
    List<int> Operands;

    if (ch >= '0' && ch <= '9') {
        Operands.push_front(int(ch));
    } else if (ch == PLUS || ch == MINUS || ch == MULTIPLICATION || ch == DIVISION
               || ch == NEGATION || ch == OPEN_BRACKET || ch == CLOSE_BRACKET) {
        Operators.push_front(ch);
        whatOperator(ch); //IN THE FUTURE
    }
}