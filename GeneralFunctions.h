#ifndef INC_1ST_PROJECT___CALCULATOR_GENERALFUNCTIONS_H
#define INC_1ST_PROJECT___CALCULATOR_GENERALFUNCTIONS_H

#include "List.h"
#include "Define.cpp"

void printing(List<int> &stack);

void whatOperation(char ch, List<int> &stack, List<char> &func, List<Equation> &equation);

int addition(int left, int right);

int subtraction(int left, int right);

int multiplication(int left, int right);

int division(int left, int right);

int neg(int left);

int min(int first, int second);

int max(int first, int second);

int ifFunction(int left, int middle, int right);

void argumentCounter(char ch, List<int> &min_maxSize, bool &wasMin, bool &wasMax);

bool isEndBracket(char ch);

void removeFromBrackets(List<Equation> &equation, List<char> &func, List<int> &min_maxSize, bool &wasMin, bool &wasMax);

bool checkFunc(char ch);

void checkChPriority(char ch, int &chPri);

void checkTopPriority(List<char> &func, int &topPri);

void checkPriority(char ch, List<Equation> &equation, List<char> &func, int &chPri, int &topPri);

void whichList(char ch, List<Equation> &equation, List<char> &func, List<int> &min_maxSize, int &chPri, int &topPri,
               int &finalNumber, bool &wasDigit, bool &wasMin, bool &wasMax);

#endif