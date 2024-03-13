#include "iostream"
#include "Define.cpp"
#include "GeneralFunctions.h"
#include "OperandList.h"
#include "OperatorList.h"
using namespace std;

int main() {
    char a = PLUS;
    cout << a << endl;

    int n; //number of formulas
    cin >> n;

    for (int i = 0; i < n; i++) {
         OperatorList operators;
        OperandList operands;
        char ch;
        while ((ch = (char) getchar()) != DOT) {
            whichList(ch,operators,operands);
        }
    }
    return 0;
}
