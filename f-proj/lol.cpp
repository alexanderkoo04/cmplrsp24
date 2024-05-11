#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::stack<std::string> st;
std::vector<std::string> words;
bool invalid = false;
int index1 = 0;


int main() {
    st.push("$");
    st.push("end.");
    st.push("sl");
    st.push("begin");
    st.push("dl");
    st.push("var");
    st.push(";");
    st.push("id");
    st.push("pr");

    std::string filename = "finalf24.txt";

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }


    std::string word;
    while (file >> word) {
        words.push_back(word);
    }

    file.close();

    std::cout << "Contents of the vector:" << std::endl;
    for (const auto& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl << std::endl << std::endl;















    

    while (!st.empty() || index1 == words.size()) {
        std::cout << "Current Token: " << words[index1] << "\t" << "Top of St: " << st.top() << std::endl;

        if (st.top() == "pr") {
            if (words[index1] != "program") {
                std::cout << "program is expected" << std::endl;
                break;
            }
            else {
                st.pop();
                index1++;
                continue;
            }
        }
        else if (st.top() == "id") {
            for (auto ch : words[index1]) {
                if (!isalnum(ch)) {
                    std::cout << "invalid identifier" << std::endl;
                    invalid = true;
                    break;
                }
            }
            if (invalid) {
                break;
            }
            else {
                st.pop();
                index1++;
                continue;
            }
        }
        else if (st.top() == ";") {
            if (words[index1] != ";") {
                std::cout << "; is missing" << std::endl;
                break;
            }
            else {
                st.pop();
                index1++;
                continue;
            }
        }
        else if (st.top() == "var") {
            if (words[index1] != "var") {
                std::cout << "var is expected" << std::endl;
                break;
            }
            else {
                st.pop();
                index1++;
                continue;
            }
        }
        else if (st.top() == "dl") {
            st.pop();
            st.push(";");
            st.push("tp");
            st.push(":");
            st.push("dec");
        }
        else if (st.top() == "dec") {
            int count = 0;
            st.pop();
            while (words[index1] != ":") {
                if (words[index1] == ",") {
                    st.push(",");
                }
                else {
                    st.push("id");
                }
                index1++;
                count++;
            }
            index1 -= count;
        }
        else if (st.top() == ",") {
            if (words[index1] != ",") {
                std::cout << ", is missing" << std::endl;
                break;
            }
            else {
                st.pop();
                index1++;
                continue;
            }
        }
        else if (st.top() == ":") {
            if (words[index1] != ":") {
                std::cout << ": is missing" << std::endl;
                break;
            }
            else {
                st.pop();
                index1++;
                continue;
            }
        }
        else if (st.top() == "tp") {
            if (words[index1] != "integer") {
                std::cout << "integer is expected" << std::endl;
                break;
            }
            else {
                st.pop();
                index1++;
                continue;
            }
        }
        else if (st.top() == "begin") {
            if (words[index1] != "begin") {
                std::cout << "begin is expected" << std::endl;
                break;
            }
            else {
                st.pop();
                index1++;
                continue;
            }
        }
        else if (st.top() == "sl") {
            st.pop();
            int come_back = index1;

            while (words[index1] != "end." && index1 != words.size()) {
                if (words[index1])
            }
            if (words[index1] == "end.") {
                index1 = come_back;
                continue;
            }
            else if (index1 == words.size()) {
                std::cout << "end. is expected" << std::endl;
                break;
            }
        }
        else {
            // std::cout << "Token - 1: " << words[index1 - 1] << std::endl;
            // std::cout << "Current Token: " << words[index1] << std::endl;
            // std::cout << "Token + 1: " << words[index1 + 1] << std::endl;
            // std::cout << "Remaining Stack: ";
            // while (!st.empty()) {
            //     std::cout << st.top() << " ";
            //     st.pop();
            // }
            // std::cout << std::endl;
            break;
        }
    }



    return 0;
}
