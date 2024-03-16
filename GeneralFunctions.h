#ifndef INC_1ST_PROJECT___CALCULATOR_GENERALFUNCTIONS_H
#define INC_1ST_PROJECT___CALCULATOR_GENERALFUNCTIONS_H
#include "List.h"

void whatOperator(char ch);

void whatOperation(char op, List<int>& stack);

int addition(int left, int right);

int subtraction(int left, int right);

int multiplication(int left, int right);

int division(int left, int right);

void whichList(char ch); //UNNECESSARY?

#endif