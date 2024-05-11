#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>

std::string table[15][31];
int t_index = 0;
bool errors = false;
std::vector<std::string> tokens;
std::stack<std::string> st;
std::vector<std::string> words;
std::set<std::string> terminal = {
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "p", "q", "r", "s", "+", "-", "*", "/", "=", "program", "var", "var", ",", ";", ":", "(", ")", "begin", "end.", "integer", "write", "\"value=\",", "lam"};

std::unordered_map<std::string, int> r_index = {
        {"P", 0},
        {"DL", 1},
        {"D", 2},
        {"T", 3},
        {"SL", 4},
        {"PS", 5},
        {"S", 6},
        {"W", 7},
        {"R", 8},
        {"A", 9},
        {"E", 10},
        {"PE", 11},
        {"M", 12},
        {"PM", 13},
        {"F", 14}
    };

std::unordered_map<std::string, int> c_index = {
        {"0", 0},
        {"1", 1},
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6},
        {"7", 7},
        {"8", 8},
        {"9", 9},
        {"p", 10},
        {"q", 11},
        {"r", 12},
        {"s", 13},
        {"+", 14},
        {"-", 15},
        {"*", 16},
        {"/", 17},
        {"=", 18},
        {"program", 19},
        {"var", 20},
        {",", 21},
        {";", 22},
        {":", 23},
        {"(", 24},
        {")", 25},
        {"begin", 26},
        {"end.", 27},
        {"integer", 28},
        {"write", 29},
        {"\"value=\",", 30}
    };

void initialize() {

    st.push("$");
    st.push("P");

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 31; ++j) {
            table[i][j] = "-1";
        }
    }

    // ROW P
    table[r_index["P"]][c_index["program"]] = "program I ; var DL begin SL end.";

    // ROW DL
    table[r_index["DL"]][c_index["p"]] = "D : T ;";
    table[r_index["DL"]][c_index["q"]] = "D : T ;";
    table[r_index["DL"]][c_index["r"]] = "D : T ;";
    table[r_index["DL"]][c_index["s"]] = "D : T ;";

    //ROW D
    table[r_index["D"]][c_index["p"]] = "I D";
    table[r_index["D"]][c_index["q"]] = "I D";
    table[r_index["D"]][c_index["r"]] = "I D";
    table[r_index["D"]][c_index["s"]] = "I D";
    table[r_index["D"]][c_index[","]] = ", D";
    table[r_index["D"]][c_index[":"]] = "lam";
    
    //ROW T
    table[r_index["T"]][c_index["integer"]] = "integer";
    
    //ROW SL
    table[r_index["SL"]][c_index["p"]] = "S PS";
    table[r_index["SL"]][c_index["q"]] = "S PS";
    table[r_index["SL"]][c_index["r"]] = "S PS";
    table[r_index["SL"]][c_index["s"]] = "S PS";
    table[r_index["SL"]][c_index["write"]] = "S PS";
    
    //ROW PS
    table[r_index["PS"]][c_index["p"]] = "SL";
    table[r_index["PS"]][c_index["q"]] = "SL";
    table[r_index["PS"]][c_index["r"]] = "SL";
    table[r_index["PS"]][c_index["s"]] = "SL";
    table[r_index["PS"]][c_index["end."]] = "lam";
    table[r_index["PS"]][c_index["write"]] = "SL";
    
    //ROW S
    table[r_index["S"]][c_index["p"]] = "A S";
    table[r_index["S"]][c_index["q"]] = "A S";
    table[r_index["S"]][c_index["r"]] = "A S";
    table[r_index["S"]][c_index["s"]] = "A S";
    table[r_index["S"]][c_index[";"]] = ";";
    table[r_index["S"]][c_index["write"]] = "W";

    //ROW W
    table[r_index["W"]][c_index["write"]] = "write ( R I ) ;";
    
    //ROW R
    table[r_index["R"]][c_index["p"]] = "lam";
    table[r_index["R"]][c_index["q"]] = "lam";
    table[r_index["R"]][c_index["r"]] = "lam";
    table[r_index["R"]][c_index["s"]] = "lam";
    table[r_index["R"]][c_index["\"value=\","]] = "\"value=\",";
    
    //ROW A
    table[r_index["A"]][c_index["p"]] = "I = E";
    table[r_index["A"]][c_index["q"]] = "I = E";
    table[r_index["A"]][c_index["r"]] = "I = E";
    table[r_index["A"]][c_index["s"]] = "I = E";
    
    //ROW E
    table[r_index["E"]][c_index["0"]] = "M PE";
    table[r_index["E"]][c_index["1"]] = "M PE";
    table[r_index["E"]][c_index["2"]] = "M PE";
    table[r_index["E"]][c_index["3"]] = "M PE";
    table[r_index["E"]][c_index["4"]] = "M PE";
    table[r_index["E"]][c_index["5"]] = "M PE";
    table[r_index["E"]][c_index["6"]] = "M PE";
    table[r_index["E"]][c_index["7"]] = "M PE";
    table[r_index["E"]][c_index["8"]] = "M PE";
    table[r_index["E"]][c_index["9"]] = "M PE";
    table[r_index["E"]][c_index["p"]] = "M PE";
    table[r_index["E"]][c_index["q"]] = "M PE";
    table[r_index["E"]][c_index["r"]] = "M PE";
    table[r_index["E"]][c_index["s"]] = "M PE";
    table[r_index["E"]][c_index["+"]] = "M PE";
    table[r_index["E"]][c_index["-"]] = "M PE";
    table[r_index["E"]][c_index["("]] = "M PE";
    
    //ROW PE
    table[r_index["PE"]][c_index["+"]] = "+ M PE";
    table[r_index["PE"]][c_index["-"]] = "- M PE";
    table[r_index["PE"]][c_index[";"]] = "lam";
    table[r_index["PE"]][c_index[")"]] = "lam";
    
    //ROW M
    table[r_index["M"]][c_index["0"]] = "F PM";
    table[r_index["M"]][c_index["1"]] = "F PM";
    table[r_index["M"]][c_index["2"]] = "F PM";
    table[r_index["M"]][c_index["3"]] = "F PM";
    table[r_index["M"]][c_index["4"]] = "F PM";
    table[r_index["M"]][c_index["5"]] = "F PM";
    table[r_index["M"]][c_index["6"]] = "F PM";
    table[r_index["M"]][c_index["7"]] = "F PM";
    table[r_index["M"]][c_index["8"]] = "F PM";
    table[r_index["M"]][c_index["9"]] = "F PM";
    table[r_index["M"]][c_index["p"]] = "F PM";
    table[r_index["M"]][c_index["q"]] = "F PM";
    table[r_index["M"]][c_index["r"]] = "F PM";
    table[r_index["M"]][c_index["s"]] = "F PM";
    table[r_index["M"]][c_index["+"]] = "F PM";
    table[r_index["M"]][c_index["-"]] = "F PM";
    table[r_index["M"]][c_index["("]] = "F PM";
    
    //ROW PM
    table[r_index["PM"]][c_index["+"]] = "lam";
    table[r_index["PM"]][c_index["-"]] = "lam";
    table[r_index["PM"]][c_index["*"]] = "* F PM";
    table[r_index["PM"]][c_index["/"]] = "/ F PM";
    table[r_index["PM"]][c_index[";"]] = "lam";
    table[r_index["PM"]][c_index[")"]] = "lam";
    
    //ROW F
    table[r_index["F"]][c_index["0"]] = "I";
    table[r_index["F"]][c_index["1"]] = "I";
    table[r_index["F"]][c_index["2"]] = "I";
    table[r_index["F"]][c_index["3"]] = "I";
    table[r_index["F"]][c_index["4"]] = "I";
    table[r_index["F"]][c_index["5"]] = "I";
    table[r_index["F"]][c_index["6"]] = "I";
    table[r_index["F"]][c_index["7"]] = "I";
    table[r_index["F"]][c_index["8"]] = "I";
    table[r_index["F"]][c_index["9"]] = "I";
    table[r_index["F"]][c_index["p"]] = "I";
    table[r_index["F"]][c_index["q"]] = "I";
    table[r_index["F"]][c_index["r"]] = "I";
    table[r_index["F"]][c_index["s"]] = "I";
    table[r_index["F"]][c_index["("]] = "( E )";
}

int main() {

    initialize();

    std::string filename = "finalf24.txt";
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 31; ++j) {
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
    }

    // for (const std::string& token : tokens) {
    //     std::cout << token << " ";
    // }
    // std::cout << std::endl;

    file.close();

    while (!st.empty()) {
        if (st.top() == "$") {
            st.pop();
            continue;
        }
        if (t_index >= tokens.size()) {
            while (!st.empty()) {
                if (terminal.find(st.top()) != terminal.end()) {
                    std::cout << std::endl << st.top() << " is expected/missing" << std::endl;
                    errors = true;
                    break;
                }
                st.pop();
            }
            if (errors) {
                break;
            }
        }
        if (terminal.find(st.top()) != terminal.end() && tokens[t_index] != st.top()) {
            std::cout << std::endl << st.top() << " is expected/missing" << std::endl;
            // std::cout << std::endl << "Top of st: " << st.top() << " Current token: " << tokens[t_index] << std::endl;
            errors = true;
            break;
        }
        if (st.top() == tokens[t_index]) {
            std::cout << std::endl << "Matched word: " << tokens[t_index] << " Popping: " << st.top() << std::endl;
            st.pop();
            t_index++;
            continue;
        }
        if (st.top() == "I") {
            for (auto ch : tokens[t_index]) {
                if (!isalnum(ch) && ch != '+' && ch != '-') {
                    std::cout << std::endl << "Invalid identifier" << std::endl;
                    // std::cout << "Top of st: " << st.top() << " Current token: " << tokens[t_index] << std::endl;
                    errors = true;
                    break;
                }
            }
            if (errors) {
                break;
            }
            else {
                std::cout << std::endl << "Matched word: " << tokens[t_index] << " Popping I" << std::endl;
                st.pop();
                t_index++;
                continue;
            }
        }
        if (terminal.find(st.top()) == terminal.end() && terminal.find(tokens[t_index]) == terminal.end()) {
            std::string f_ltr(1, tokens[t_index][0]);
            std::istringstream stream(table[r_index[st.top()]][c_index[f_ltr]]);
            std::string word;

            if (st.top() == "D" && tokens[t_index] != ":") {
                if (tokens[t_index - 1] != "," && tokens[t_index - 1] != "var") {
                    errors = true;
                    break;
                }
            }

            std::cout << std::endl << "String of words: ";

            while (stream >> word) {
                words.push_back(word);
                std::cout << word << " ";
            }
            std::cout << std::endl;

            std::reverse(words.begin(), words.end());

            if (words[0] == "lam") {
                st.pop();
                words.clear();
                word.clear();
                continue;
            }
            if (words[0] == "-1") {
                std::cout << "hit -1 error" << std::endl;
                std::cout << "Top of st: " << st.top() << " Current token: " << tokens[t_index] << std::endl;
                errors = true;
                break;
            }

            std::cout << std::endl << "Current token: " << tokens[t_index] << " Top of st: " << st.top() << " THAT ONE" << std::endl;

            st.pop();

            
            for (auto w : words) {
                std::cout << "Pushing to stack: " << w << std::endl;
                st.push(w);
            }
            words.clear();
            word.clear();
        }
        if (terminal.find(st.top()) == terminal.end() && terminal.find(tokens[t_index]) != terminal.end()) {
            std::istringstream stream(table[r_index[st.top()]][c_index[tokens[t_index]]]);
            std::string word;

            std::cout << std::endl << "String of words: ";

            while (stream >> word) {
                words.push_back(word);
                std::cout << word << " ";
            }
            std::cout << std::endl;

            std::reverse(words.begin(), words.end());

            if (words[0] == "lam") {
                st.pop();
                words.clear();
                word.clear();
                continue;
            }
            if (words[0] == "-1") {
                std::cout << "hit -1 error" << std::endl;
                std::cout << "Top of st: " << st.top() << " Current token: " << tokens[t_index] << std::endl;
                errors = true;
                break;
            }

            std::cout << std::endl << "Current token: " << tokens[t_index] << " Top of st: " << st.top() << " THIS ONE" << std::endl;

            st.pop();

            for (auto w : words) {
                std::cout << "Pushing to stack: " << w << std::endl;
                st.push(w);
            }
            words.clear();
            word.clear();
        }
    }

    if (errors && t_index == 0) {
        std::cout << "program is expected/missing" << std::endl;
    }

    if (errors) {
        std::cout << std::endl << "Some errors found" << std::endl;
        if (st.top() == "PS" && t_index == tokens.size() - 1) {
            std::cout << "end. is missing" << std::endl;
        }
        else if (st.top() == "PS") {
            std::cout << "write is expected/missing" << std::endl;
        }
        if (st.top() == "T") {
            std::cout << "integer is expected/missing" << std::endl;
        }
        if (tokens[t_index] == ")") {
            std::cout << "( is expected/missing" << std::endl;
        }
        if (st.top() == "PM") {
            std::cout << ";  is expected/missing" << std::endl;
        }
        if (st.top() == "D") {
            std::cout << std::endl << "Current token: " << tokens[t_index] << " Top of st: " << st.top() << std::endl;
            std::cout <<", is expected/missing" << std::endl;
        }
    }
    else {
        std::cout << std::endl << std::endl << "No errors" << std::endl;
    }

    return 0;
}
