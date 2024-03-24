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
    int size;

    if (ch == LETTER_I)
        cout << "IF" << ' ';
    else if (ch == LETTER_A) {
        size = equation.getValue().nbr;
        equation.remove_front();
        cout << "MAX" << size << ' ';
    } else if (ch == 'i') {
        size = equation.getValue().nbr;
        equation.remove_front();
        cout << "MIN" << size << ' ';
    } else
        cout << ch << ' ';
    printing(stack);

    if (ch == NEGATION) {
        left = stack.remove_front();
        stack.push_front(neg(left));
    } else if ((ch == LETTER_A || ch == 'i') && size == 1) {
        left = stack.remove_front();
        if (ch == LETTER_A)
            stack.push_front(max(left, 0));
        else
            stack.push_front(min(left, left + 1));
    } else if (ch == LETTER_I) {
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
        } else if (ch == LETTER_A) {
            if (size == 2)
                stack.push_front(max(left, right));
            else {
                for (int i = 0; i < size - 1; i++) {
                    stack.push_front(max(left, right));
                    if (stack.getSize() > 1) {
                        left = stack.remove_front();
                        right = stack.remove_front();
                    }
                    else break;
                }
            }
        } else if (ch == 'i') {
            if (size == 2)
                stack.push_front(min(left, right));
            else {
                for (int i = 0; i < size - 1; i++) {
                    stack.push_front(min(left, right));
                    if (stack.getSize() > 1) {
                        left = stack.remove_front();
                        right = stack.remove_front();
                    }
                    else break;
                }
            }
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

int min(int first, int second) {
    if (first < second)
        return first;
    else
        return second;
}

int max(int first, int second) {
    if (first > second)
        return first;
    else
        return second;
}

int ifFunction(int left, int middle, int right) {
    if (right > 0)
        return middle;
    return left;
}

void argumentCounter(char ch, List<int> &min_maxSize, bool &wasMin, bool &wasMax) {
    if (ch == COMMA)
        min_maxSize.getValue()++;
    else if (ch == OPEN_BRACKET) {
        min_maxSize.push_front(1);
        wasMin = false;
        wasMax = false;
    }
}

bool isEndBracket(char ch) {
    if (ch == CLOSE_BRACKET)
        return true;
    else
        return false;
}

void
removeFromBrackets(List<Equation> &equation, List<char> &func, List<int> &min_maxSize, bool &wasMin, bool &wasMax) {
    char tmp = func.getValue();
    while (tmp != OPEN_BRACKET) {
        tmp = func.remove_front();
        equation.push_back({0, tmp, false});
        tmp = func.getValue();
    }
    func.remove_front();
    if (func.getSize() != 0) {
        char &m = func.getValue();
        if (m == LETTER_A || m == 'i') {
            equation.push_back({0, m, false});
            func.remove_front();
            int size = min_maxSize.remove_front();
            equation.push_back({size, '0', true});
            wasMin = false;
            wasMax = false;
        }
    }
}

bool checkFunc(char ch) {
    if (ch == PLUS || ch == MINUS || ch == MULTIPLICATION || ch == DIVISION ||
        ch == NEGATION || ch == OPEN_BRACKET || ch == CLOSE_BRACKET ||
        ch == LETTER_I || ch == LETTER_M || ch == COMMA)
        return true;
    else
        return false;
}

void checkChPriority(char ch, int &chPri) {
    chPri = 0;
    if (ch == OPEN_BRACKET)
        chPri = MAX_PRIORITY;
    else if (ch == NEGATION || ch == LETTER_I || ch == LETTER_M)
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
    else if (top == NEGATION || top == LETTER_I || top == LETTER_M)
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

void whichList(char ch, List<Equation> &equation, List<char> &func, List<int> &min_maxSize, int &chPri, int &topPri,
               int &finalNumber, bool &wasDigit, bool &wasMin, bool &wasMax) {
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
        char tmp;
        if (ch == LETTER_I)
            getchar();
        if (ch == LETTER_M) {
            //func.push_front(ch);
            tmp = getchar();
            getchar();
            if (tmp == LETTER_I) {
                wasMin = true;
                func.push_front('i');
            } else {
                wasMax = true;
                func.push_front(tmp);
            }
        }
        if (func.getSize() == 0 && ch != LETTER_M) {
            func.push_front(ch);
        } else if (isEndBracket(ch)) {
            removeFromBrackets(equation, func, min_maxSize, wasMin, wasMax);
        } else if (wasMin || wasMax) {
            argumentCounter(ch, min_maxSize,wasMin,wasMax);
            if (ch == OPEN_BRACKET)
                func.push_front(ch);
            else if (ch != LETTER_M )
                checkPriority(ch,equation,func,chPri,topPri);
        } else
            checkPriority(ch, equation, func, chPri, topPri);
    }
}