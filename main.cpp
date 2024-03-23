#include "iostream"
#include "Define.cpp"
#include "List.h"
#include "GeneralFunctions.h"

using namespace std;

int main() {

    List<int> stack; //List for numbers
    List<char> func; //List for operators
    List<Equation> equation; //List for postfix equation values
    List<int> min_maxSize;

    int n; //number of formulas
    cin >> n;

    int chPri = 0, topPri = 0, finalNumber = 0;
    char ch;
    bool wasDigit = false, wasMin = false, wasMax = false;

    for (int i = 0; i < n; i++) {
        //GETTING INPUT
        while ((ch = (char) getchar()) != DOT) {
            whichList(ch, equation, func, min_maxSize, chPri, topPri, finalNumber, wasDigit, wasMin, wasMax);
        }

        //END OF INPUT
        while (func.getSize() != 0) {
            ch = func.remove_front();
            equation.push_back({0, ch, false});
        }

        //PRINTING POSTFIX EQUATION
        for (Equation item: equation) {
            if (item.isNumber)
                cout << item.nbr << ' ';
            else {
                if (item.func == LETTER_I)
                    cout << "IF" << ' ';
                else if (item.func == LETTER_A)
                    cout << "MAX";
                else if (item.func == 'i')
                    cout << "MIN";
                else
                    cout << item.func << ' ';
            }
        }
        cout << endl;

        //COMPUTING
        while (equation.getSize() != 0) {
            Equation tmp = equation.remove_front();
            if (tmp.isNumber)
                stack.push_front(tmp.nbr);
            else {
                ch = tmp.func;
                whatOperation(ch, stack, func, equation);
            }
        }

        if (stack.getSize() != 0) {
            cout << stack.remove_front() << endl;
            cout << endl;
            stack.clear();
            equation.clear();
            func.clear();
        }
    }
    return 0;
}
