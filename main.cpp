#include "iostream"
#include "Define.cpp"
#include "GeneralFunctions.h"
using namespace std;

int main() {
    char a = PLUS;
    cout << a << endl;

    int n; //number of formulas
    cin >> n;

    for (int i = 0; i < n; i++) {
        char ch;
        while ((ch = (char) getchar()) != DOT) {
            whichList(ch);
        }
    }
    return 0;
}
