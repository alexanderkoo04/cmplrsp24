#include <bits/stdc++.h>

int indexer(char c) {
    if (c == 'i') {
        return 0;
    }
    else if (c == '+') {
        return 1;
    }
    else if (c == '-') {
        return 2;
    }
    else if (c == '*') {
        return 3;
    }
    else if (c == '/') {
        return 4;
    }
    else if (c == '(') {
        return 5;
    }
    else if (c == ')') {
        return 6;
    }
    else if (c == '$') {
        return 7;
    }
    else if (c == 'E') {
        return 0;
    }
    else if (c == 'Q') {
        return 1;
    }
    else if (c == 'T') {
        return 2;
    }
    else if (c == 'R') {
        return 3;
    }
    else if (c == 'F') {
        return 4;
    }
    return 0;
}

int main() {

    char print_element;
    std::stack<char> st;
    std::stack<char> temp_st;
    std::string push_val;
    st.push('$');
    st.push('E');
    char first_char;
    char st_top;
    std::string input_string;
    std::cin >> input_string;
    std::string table[5][8] = {
        {"TQ", "-1", "-1", "-1", "-1", "TQ", "-1", "-1"},
        {"-1", "+TQ", "-TQ", "-1", "-1", "-1", "L", "L"},
        {"FR", "-1", "-1", "-1", "-1", "FR", "-1", "-1"},
        {"-1", "L", "L", "*FR", "/FR", "-1", "L", "L"},
        {"i", "-1", "-1", "-1", "-1", "(E)", "-1", "-1"}
    };

    /*
        0   1   2   3   4   5   6   7    
        i   +   -   *   /   (   )   $
    0 E
    1 Q
    2 T
    3 R
    4 F

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
        
        push_val = table[indexer(st_top)][indexer(first_char)];
        if (push_val == "L") {
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