#include <bits/stdc++.h>

std::vector<std::string> reserved = {"while", "for", "switch", "do", "return"};
std::string inputStr;

bool number(std::string string) {
    for (auto i : string) {
        if (!isdigit(i)) {
            return false;
        }
    }
    return true;
}

bool reserve(std::string string) {
    auto it = std::find(reserved.begin(), reserved.end(), string);
    if (it != reserved.end()) {
        return true;
    }
    else {
        return false;
    }
}

bool ident(std::string string) {
    for (auto i : string) {
        if (std::isalnum(i) || i == '_') {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    std::string inputStr;
    bool isNum;
    bool isIdent;
    bool isRes;
    bool flag = true;
    while (flag) {
        std::getline(std::cin, inputStr);
        if ((int(inputStr[0]) >= 65) && (int(inputStr[0]) <= 122) || (inputStr[0] == '_')) {
            isNum = false;
            isRes = reserve(inputStr);
            isIdent = ident(inputStr);
        }
        else if (isdigit(inputStr[0])) {
            isIdent = false;
            isRes = false;
            isNum = number(inputStr);
        }

        if (isNum) {
            std::cout << inputStr << " is a number" << std::endl;
        }
        else {
            std::cout << inputStr << " is not a number" << std::endl;
        }
    /////////////////////////////
        if (isIdent) {
            std::cout << inputStr << " is a identifier" << std::endl;
        }
        else {
            std::cout << inputStr << " is not a identifier" << std::endl;
        }
    /////////////////////////////
        if (isRes) {
            std::cout << inputStr << " is a reserved word" << std::endl;
        }
        else {
            std::cout << inputStr << " is not a reserved word" << std::endl;
        }
        std::cout << std::endl;
    }

    
    return 0;
}