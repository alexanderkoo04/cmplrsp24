#include <bits/stdc++.h>

int main() {

    char print_element;
    std::stack<char> st;
    std::stack<char> temp_st;
    std::string push_val;
    st.push('$');
    st.push('S');
    char first_char;
    char st_top;
    std::string input_string;
    std::cin >> input_string;
    std::string table[7][10] = {
        {"aW", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"},
        {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "=E", "-1"},
        {"TQ", "-1", "-1", "-1", "-1", "TQ", "-1", "-1", "-1", "-1"},
        {"-1", "+TQ", "-TQ", "-1", "-1", "-1", "lambda", "-1", "-1", "lambda"},
        {"FR", "-1", "-1", "-1", "-1", "FR", "-1", "-1", "-1", "-1"},
        {"-1", "lambda", "lambda", "*FR", "/FR", "-1", "lambda", "-1", "-1", "lambda"},
        {"a", "-1", "-1", "-1", "-1", "(E)", "-1", "-1", "-1", "-1"}
    };

    std::unordered_map<char, int> indexer = {
        {'a', 0}, {'+', 1}, {'-', 2}, {'*', 3}, {'/', 4}, {'(', 5}, {')', 6}, {'=', 8}, {'$', 9}, {'S', 0}, {'W', 1}, {'E', 2}, {'Q', 3}, {'T', 4}, {'R', 5}, {'F', 6}
    };

    /*

        0   1   2   3   4   5   6   7    8   9
        a   +   -   *   /   (   )   lam  =   $
    0 S
    1 W
    2 E
    3 Q
    4 T
    5 R
    6 F

    */

    while (true) {
        if (st.empty()) {
            std::cout << "Fully Parsed, accepted." << std::endl;
            break;
        }
        st_top = st.top();
        st.pop();
        first_char = input_string[0];
        if (st_top == first_char) {
            input_string.erase(0, 1);
            std::cout << "Stack: ";
            while (!st.empty()) {
                temp_st.push(st.top());
                st.pop();
            }

            while (!temp_st.empty()) {
                std::cout << temp_st.top() << " ";
                st.push(temp_st.top());
                temp_st.pop();
            }
            std::cout << std::endl;
            continue;
        }
        
        push_val = table[indexer[st_top]][indexer[first_char]];
        if (push_val == "lambda") {
            continue;
        }
        else if (push_val == "-1") {
            std::cout << "Failed To Parse, rejected." << std::endl;
            break;
        }
        else {
            for (int i = push_val.size() - 1; i >= 0; i--) {
                st.push(push_val[i]);
            }
        }
    }

    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         std::cout << table[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }


    
    return 0;
}