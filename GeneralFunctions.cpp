#include "iostream"
#include "GeneralFunctions.h"

using namespace std;

void printing(List<int> &stack) {
    for (int item: stack) {
        cout << item << ' ';
    }
    cout << endl;
}

void whatOperation(char ch, List<int> &stack) {
    int left, right;

    cout << ch << ' ';
    printing(stack);

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

bool checkFunc(char ch) {
    if (ch == PLUS || ch == MINUS || ch == MULTIPLICATION || ch == DIVISION
        || ch == NEGATION || ch == OPEN_BRACKET || ch == CLOSE_BRACKET)
        return true;
    else return false;
}

void checkChPriority(char ch, int &chPri) {
    chPri = 0;
    if (ch == NEGATION)
        chPri = MAX_PRIORITY;
    else if (ch == MULTIPLICATION || ch == DIVISION)
        chPri = MIDDLE_PRIORITY;
    else
        chPri = LOW_PRIORITY;
}

void checkTopPriority(List<char> &func, int &topPri) {
    char top = func.getValue();
    topPri = 0;
    if (top == NEGATION)
        topPri = MAX_PRIORITY;
    else if (top == MULTIPLICATION || top == DIVISION)
        topPri = MIDDLE_PRIORITY;
    else
        topPri = LOW_PRIORITY;
}

void checkPriority(char ch, List<Equation> &equation, List<char> &func, int &chPri, int &topPri) {
    checkChPriority(ch, chPri);
    checkTopPriority(func, topPri);
    while (chPri < topPri || chPri == topPri) {
        char tmp = func.remove_front();
        equation.push_back({0, tmp, false});
        if (func.getSize() == 0)
            break;
        checkTopPriority(func, topPri);
    }
    func.push_front(ch);
}

void whichList(char ch, List<Equation> &equation, List<char> &func, int &chPri, int &topPri, int &finalNumber,
               bool &wasDigit) {
    if ((ch >= '0' && ch <= '9') || ch == SPACE) {
        if (ch != SPACE) {
            int digit;
            digit = ch - '0';
            finalNumber = finalNumber * 10 + digit;
            wasDigit = true;
        } else {
            if (finalNumber >= 0 && wasDigit)
                equation.push_back({finalNumber, '0', true});
            finalNumber = 0;
            wasDigit = false;
        }
    } else if (checkFunc(ch)) {
        if (func.getSize() == 0)
            func.push_front(ch);
        else
            checkPriority(ch, equation, func, chPri, topPri);
    }
}