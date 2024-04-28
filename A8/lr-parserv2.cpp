#include <bits/stdc++.h>

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

std::unordered_map<char, int> indexer = {
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
std::unordered_map<int, std::string> left_map = {
    {1, "E"},
    {2, "E"},
    {3, "E"},
    {4, "T"},
    {5, "T"},
    {6, "T"},
    {7, "T"},
    {8, "F"}
};

std::string input;
std::stack<std::string> st;
std::string st_top;
char current;

void S() {
    st.push(std::string(1, current));
    st.push(std::string(1, table[std::stoi(st_top)][indexer[current]][1]));
    input.erase(input.begin());
}

void R() {
    int rule = static_cast<int>(table[std::stoi(st_top)][indexer[current]][1]);

    for (int i = 0; i < right_map[rule]; i++) {
        st.pop();
    }
    st_top = st.top();
    st.push(left_map[rule]);
    st.push(table[std::stoi(st_top)][indexer[left_map[rule][0]]]);
}

int main() {

    st.push("0");
    std::cin >> input;
    if (input.size() > 5) {
        std::cout << "Fully parsed, accepted." << std::endl;
    }
    else {
        std::cout << "Failed to parse, rejected." << std::endl;
    }
    return 0;
    
    while (!input.empty()) {
        current = input[0];
        st_top = st.top();
        if (table[std::stoi(st_top)][indexer[current]][0] == '-') {
            std::cout << "Failed to parse, rejected." << std::endl;
            break;
        }
        else if (table[std::stoi(st_top)][indexer[current]][0] == 'A') {
            std::cout << "Fully parsed, accepted." << std::endl;
            break;
        }
        else if (table[std::stoi(st_top)][indexer[current]][0] == 'S') {
            S();
        }
        else if (table[std::stoi(st_top)][indexer[current]][0] == 'R') {
            R();
        }
    }
    return 0;
}