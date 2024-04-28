#include <bits/stdc++.h>

int main() {
    std::string inputStr;
    

    std::stack<int> st;
    int first;
    int second;
    int inputValue;
    bool cont = true;
    std::string condition;

    std::string token;

    

    while (cont) {

        cont = false;

        std::cout << "Enter a postfix expression with a $ at the end: \n";
        std::getline(std::cin, inputStr);
        std::stringstream ss(inputStr);

        while (ss >> token) {

            if (isdigit(token[0])) {
                st.push(std::stoi(token));
            }

            else if (token == "-") {
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();
                st.push(second - first);
            }

            else if (token == "+") {
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();
                st.push(second + first);
            }

            else if (token == "*") {
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();
                st.push(second * first);
            }

            else if (token == "/") {
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();
                st.push(second / first);
            }

            else if (token == "$") {
                break;
            }

            else {
                std::cout << "Enter the value of " << token << ": ";
                std::cin >> inputValue;
                st.push(inputValue);
            }
        }
        std::cout << "Expression's value is " << st.top() << std::endl;
        std::cout << "CONTINUE(y/n)? ";
        std::cin >> condition;
        if (condition == "y") {
            cont = true;
            while (!st.empty()) {
                st.pop();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return 0;
}