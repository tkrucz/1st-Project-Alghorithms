#include "iostream"
#include "Define.cpp"
#include "List.h"
#include "GeneralFunctions.h"

using namespace std;

int main() {

//    equation.push_back({4, '0', true});
//    equation.push_back({4, '0', true});
//    equation.push_back({2, '0', true});
//    equation.push_back({0, '-', false});
//    equation.push_back({5, '0', true});
//    equation.push_back({0, '*', false});
//    equation.push_back({0, '+', false});

    List<int> stack; //List for numbers
    List<char> func; //List for operators
    List<Equation> equation; //List for postfix equation values

    int n; //number of formulas
    cin >> n;

    int chPri = 0, topPri = 0, finalNumber = 0;
    char ch;

    for (int i = 0; i < n; i++) {
        while ((ch = (char) getchar()) != DOT) {
            whichList(ch, equation, func, chPri, topPri, finalNumber);
        }
        //END OF INPUT
        while (func.getSize() != 0) {
            ch = func.remove_front();
            equation.push_back({0, ch, false});
        }

        while (equation.getSize() != 0) {
            Equation tmp = equation.remove_front();
            if (tmp.isNumber)
                stack.push_front(tmp.nbr);
            else {
                char ch = tmp.func;
                whatOperation(ch, stack);
            }
        }
        cout << stack.remove_front();
        stack.clear();
        equation.clear();
        func.clear();
    }
    return 0;
}
