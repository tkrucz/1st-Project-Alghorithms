#include "iostream"
#include "Define.cpp"
#include "List.h"
#include "GeneralFunctions.h"

using namespace std;

int main() {

    List<int> stack;
    List<Equation> equation;

    equation.push_back({4, '0', true});
    equation.push_back({4, '0', true});
    equation.push_back({2, '0', true});
    equation.push_back({0, '-', false});
    equation.push_back({5, '0', true});
    equation.push_back({0, '*', false});
    equation.push_back({0, '+', false});

    while (equation.getSize() != 0) {
        Equation tmp = equation.remove_front();
        if (tmp.isNumber)
            stack.push_front(tmp.nbr);
        else {
            char op = tmp.func;
            whatOperation(op, stack);
        }
    }
    cout<<stack.remove_front();

    //MAIN CODE
//    int n; //number of formulas
//    cin >> n;
//
//    for (int i = 0; i < n; i++) {
//        char ch;
//        while ((ch = (char) getchar()) != DOT) {
//            whichList(ch);
//        }
//    }
    return 0;
}
