//------------------------------------------------------------------------------------------------------------
// Group names: Alexander Koo, Camplesg Nguyen, Tristan Do
// Assignment: CPSC 323, No.1
// Due date: 2/8/2024
// Purpose: this program reads an expression in postfix form, evaluates the expression
// and displays its value
//---------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>

int a, b, c, d;

void calculateValue(std::string string) { // void function used to calculate value and print to terminal
    std::stack<int> stack;
    char letter;
    for (int i = 0; i < string.size(); i++) {
        letter = string[i];
        int first;
        int second;
        switch (letter) {
            case 'a':
                stack.push(a);
                break;
            case 'b':
                stack.push(b);
                break;
            case 'c':
                stack.push(c);
                break;
            case 'd':
                stack.push(d);
                break;
            case '-':
                first = stack.top();
                stack.pop();
                second = stack.top();
                stack.pop();
                stack.push(second - first);
                break;
            case '*':
                first = stack.top();
                stack.pop();
                second = stack.top();
                stack.pop();
                stack.push(second * first);
                break;
            case '+':
                first = stack.top();
                stack.pop();
                second = stack.top();
                stack.pop();
                stack.push(second + first);
                break;
            case '$':
                break;
        }
    }
    std::cout << "Value: " << stack.top() << std::endl;
}

void askExpression() { // function to ask for a postfix expression, called if continue = yes
    std::cout << "Enter a postfix expression with $ at the end: ";
}

void continuation() { // function to ask if the user would like to continue
    std::cout << "CONTINUE(y/n)? ";
}

int main() {
    std::string input;
    char condition;
    std::cout << "Enter the values of a, b, c and d: ";
    std::cin >> a >> b >> c >> d;
    askExpression();
    std::cin >> input;
    calculateValue(input);
    continuation();
    std::cin >> condition;
    while(condition == 'y') {
        askExpression();
        std::cin >> input;
        calculateValue(input);
        continuation();
        std::cin >> condition;
    }
    return 0;
}