#include "iostream"
#include "GeneralFunctions.h"

using namespace std;

void printing(List<int> &stack) {
    for (int item: stack) {
        cout << item << ' ';
    }
    cout << endl;
}

void whatOperation(char ch, List<int> &stack, List<char> &func, List<Equation> &equation) {
    int left, middle, right;

    if (ch == LETTER_I)
        cout << "IF" << ' ';
    else
        cout << ch << ' ';
    printing(stack);

    if (ch == NEGATION) {
        left = stack.remove_front();
        stack.push_front(neg(left));
    } else if (ch == 'I') {
        left = stack.remove_front();
        middle = stack.remove_front();
        right = stack.remove_front();
        stack.push_front(ifFunction(left, middle, right));
    } else {
        left = stack.remove_front();
        right = stack.remove_front();
        if (ch == PLUS) {
            stack.push_front(addition(left, right));
        } else if (ch == MINUS) {
            stack.push_front(subtraction(left, right));
        } else if (ch == MULTIPLICATION) {
            stack.push_front(multiplication(left, right));
        } else if (ch == DIVISION) {
            if (left == 0) {
                cout << "ERROR" << endl;
                cout << endl;
                stack.clear();
                equation.clear();
                func.clear();
            } else
                stack.push_front(division(left, right));
        }
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

int neg(int left) {
    return -1 * left;
}

int ifFunction(int left, int middle, int right) {
    if (right > 0)
        return middle;
    return left;
}

bool isEndBracket(char ch) {
    if (ch == CLOSE_BRACKET)
        return true;
    else
        return false;
}

void removeFromBrackets(List<Equation> &equation, List<char> &func) {
    char tmp = func.getValue();
    while (tmp != OPEN_BRACKET) {
        tmp = func.remove_front();
        equation.push_back({0, tmp, false});
        tmp = func.getValue();
    }
    func.remove_front();
}

bool checkFunc(char ch) {
    if (ch == PLUS || ch == MINUS || ch == MULTIPLICATION || ch == DIVISION ||
        ch == NEGATION || ch == OPEN_BRACKET || ch == CLOSE_BRACKET ||
        ch == LETTER_I || ch == COMMA)
        return true;
    else
        return false;
}

void checkChPriority(char ch, int &chPri) {
    chPri = 0;
    if (ch == OPEN_BRACKET)
        chPri = MAX_PRIORITY;
    else if (ch == NEGATION || ch == LETTER_I)
        chPri = MIDDLE_PRIORITY;
    else if (ch == MULTIPLICATION || ch == DIVISION)
        chPri = LOW_PRIORITY;
    else
        chPri = ZERO_PRIORITY;
}

void checkTopPriority(List<char> &func, int &topPri) {
    char top = func.getValue();
    topPri = 0;
    if (top == OPEN_BRACKET)
        topPri = MAX_PRIORITY;
    else if (top == NEGATION || top == LETTER_I)
        topPri = MIDDLE_PRIORITY;
    else if (top == MULTIPLICATION || top == DIVISION)
        topPri = LOW_PRIORITY;
    else
        topPri = ZERO_PRIORITY;
}

void checkPriority(char ch, List<Equation> &equation, List<char> &func, int &chPri, int &topPri) {
    checkChPriority(ch, chPri);
    checkTopPriority(func, topPri);
    while (chPri < topPri || chPri == topPri) {
        char tmp = func.remove_front();
        if (topPri == MAX_PRIORITY && chPri == MAX_PRIORITY || topPri == MIDDLE_PRIORITY && chPri == MIDDLE_PRIORITY) {
            func.push_front(tmp);
            break;
        }
        if (tmp == OPEN_BRACKET || tmp == CLOSE_BRACKET) {
            func.push_front(tmp);
            break;
        }
        equation.push_back({0, tmp, false});
        if (func.getSize() == 0)
            break;
        checkTopPriority(func, topPri);
    }
    if (ch != COMMA)
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
        if (ch == LETTER_I)
            getchar();
        if (func.getSize() == 0)
            func.push_front(ch);
        else if (isEndBracket(ch)) {
            removeFromBrackets(equation, func);
        } else
            checkPriority(ch, equation, func, chPri, topPri);
    }
}