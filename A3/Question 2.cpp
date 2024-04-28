#include <bits/stdc++.h>

int main() {
    int table[4][3] = {
        {0, 1, 2},
        {2, 1, 3},
        {0, 3, 3},
        {3, 3, 3}
    };

    std::string inputStr;
    std::string variable;
    std::string equalSign;
    std::cin >> variable >> equalSign >>inputStr;
    int finState1 = 1;
    int finState2 = 2;
    int currState = 0;


    for (auto i : inputStr) {
        if (i == 'a') {
            currState = table[currState][0];
        }
        else if (i == 'b') {
            currState = table[currState][1];
        }
        else if (i == 'c') {
            currState = table[currState][2];
        }
        else if (i == '$') {
            break;
        }
    }

    if (currState == finState1 || currState == finState2) {
        std::cout << variable << " is Valid" << std::endl;
    }
    else {
        std::cout << variable << " is Invalid" << std::endl;
    }
    return 0;
}