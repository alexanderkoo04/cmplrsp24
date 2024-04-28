#include <bits/stdc++.h>

int main() {

    // non-terminals map [string number, letter]
    std::unordered_map<std::string, char> non_term1 = {
        {"1", 'a'},
        {"2", 'b'},
        {"3", 'c'},
        {"4", 'd'},
        {"5", 'e'},
        {"6", 'f'},
        {"7", 'g'},
        {"8", 'h'},
        {"9", 'i'},
        {"10", 'j'},
        {"11", 'k'},
        {"12", 'l'},
        {"13", 'm'},
        {"14", 'n'},
        {"15", 'o'}
    };

    // non-terminals map [letter, int]
    std::unordered_map<char, int> non_term2 = {
        {'a', 1},
        {'b', 2},
        {'c', 3},
        {'d', 4},
        {'e', 5},
        {'f', 6},
        {'g', 7},
        {'h', 8},
        {'i', 9},
        {'j', 10},
        {'k', 11},
        {'l', 12},
        {'m', 13},
        {'n', 14},
        {'o', 15}
    };

    // right side CFG map, [rule #, count]
    std::unordered_map<int, int> right_map = {
        {1, 6},
        {2, 6},
        {3, 2},
        {4, 6},
        {5, 6},
        {6, 2},
        {7, 6},
        {8, 2}
    };

    // left side CFG map, [rule #, letter]
    std::unordered_map<int, char> left_map = {
        {1, 'E'},
        {2, 'E'},
        {3, 'E'},
        {4, 'T'},
        {5, 'T'},
        {6, 'T'},
        {7, 'F'},
        {8, 'F'}
    };

    // row indexer
    std::unordered_map<char, int> index = {
        {'i', 0},
        {'+', 1},
        {'-', 2},
        {'*', 3},
        {'/', 4},
        {'(', 5},
        {')', 6},
        {'$', 7},
        {'E', 8},
        {'T', 9},
        {'F', 10}
    };
    
    std::string table[16][11] = {
        {"S5", "-1", "-1", "-1", "-1", "S4", "-1", "-1", "1", "2", "3"},
        {"-1", "S6", "S7", "-1", "-1", "-1", "-1", "ACC", "-1", "-1", "-1"},
        {"-1", "R3", "R3", "S8", "S9", "-1", "R3", "R3", "-1", "-1", "-1"},
        {"-1", "R6", "R6", "R6", "R6", "-1", "R6", "R6", "-1", "-1", "-1"},
        {"S5", "-1", "-1", "-1", "-1", "S4", "-1", "-1", "10", "2", "3"},
        {"-1", "R8", "R8", "R8", "R8", "-1", "R8", "R8", "-1", "-1", "-1"},
        {"S5", "-1", "-1", "-1", "-1", "S4", "-1", "-1", "-1", "11", "3"},
        {"S5", "-1", "-1", "-1", "-1", "S4", "-1", "-1", "-1", "12", "3"},
        {"S5", "-1", "-1", "-1", "-1", "S4", "-1", "-1", "-1", "-1", "13"},
        {"S5", "-1", "-1", "-1", "-1", "S4", "-1", "-1", "-1", "-1", "14"},
        {"-1", "S6", "S7", "-1", "-1", "-1", "S15", "-1", "-1", "-1", "-1"},
        {"-1", "R1", "R1", "S8", "S9", "-1", "R1", "R1", "-1", "-1", "-1"},
        {"-1", "R2", "R2", "S8", "S9", "-1", "R2", "R2", "-1", "-1", "-1"},
        {"-1", "R4", "R4", "R4", "R4", "-1", "R4", "R4", "-1", "-1", "-1"},
        {"-1", "R5", "R5", "R5", "R5", "-1", "R5", "R5", "-1", "-1", "-1"},
        {"-1", "R7", "R7", "R7", "R7", "-1", "R7", "R7", "-1", "-1", "-1"}
    };

    /*

        0   1   2   3   4   5   6   7   8   9   10
        i   +   -   *   /   (   )   $   E   T   F
    0
    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
    11
    12
    13
    14
    15
    
    */
    std::stack<char> st;
    std::string input;
    char curr_char;
    char st_top;
    char second_top;
    std::cin >> input;
    st.push('0');
    while (input != "") {
        curr_char = input[0];
        if (st.top() >= 'a' && st.top() <= 'o') {
            st_top = non_term2[st.top()];
        }
        else {
            st_top = st.top();
        }
        if (table[st_top][index[curr_char]][0] == 'S') {
            st.push(curr_char);
            st.push(table[st_top][index[curr_char]][1]);
            input.erase(input.begin());
        }
        else if (table[st_top][index[curr_char]][0] == 'R') {
            for (int i = 0; i < right_map[table[st_top][index[curr_char]][1]]; i++) {
                st.pop();
            }
            second_top = st.top();
            st.push(left_map[static_cast<int>(table[st_top][index[curr_char]][1])]);
            st.push(non_term1[table[second_top][left_map[static_cast<int>(table[st_top][index[curr_char]][1])]]]);
        }
        else if (table[st_top][index[curr_char]][0] == 'A') {
            std::cout << "Parsed, input accepted." << std::endl;
        }
        else if (table[st_top][index[curr_char]][0] == '-') {
            std::cout << "Failed to parse." << std::endl;
        }
    }
    return 0;
}