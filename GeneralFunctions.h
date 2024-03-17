#ifndef INC_1ST_PROJECT___CALCULATOR_GENERALFUNCTIONS_H
#define INC_1ST_PROJECT___CALCULATOR_GENERALFUNCTIONS_H

#include "List.h"
#include "Define.cpp"

void whatOperation(char ch, List<int> &stack);

int addition(int left, int right);

int subtraction(int left, int right);

int multiplication(int left, int right);

int division(int left, int right);

int negation(int left);

bool checkFunc(char ch);

void checkChPriority(char ch, int &chPri);

void checkTopPriority(List<char> &func, int &topPri);

void checkPriority(char ch, List<Equation> &equation, List<char> &func, int &chPri, int &topPri);

void whichList(char ch, List<Equation> &equation, List<char> &func, int &chPri, int &topPri, int &finalNumber);

#endif