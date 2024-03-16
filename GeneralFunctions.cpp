#include "iostream"
#include "GeneralFunctions.h"
#include "List.h"
#include "Define.cpp"

void whatOperator(char ch) {

    if (ch == CLOSE_BRACKET) {

    } else if (ch == NEGATION) {

    }
}

void whatOperation(char ch, List<int> &stack) {
    int left, right;
    left = stack.remove_front();
    right = stack.remove_front();
    if (ch == PLUS) {
        stack.push_front(addition(left, right));
    } else if (ch == MINUS) {
        stack.push_front(subtraction(left, right));
    } else if (ch == MULTIPLICATION) {
        stack.push_front(multiplication(left, right));
    } else if (ch == DIVISION) {
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

int negation(int left) {
    return -1 * left;
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