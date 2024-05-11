#include <bits/stdc++.h>
#include <iostream>

int main() {
    // Open the file
    std::ifstream file("finalf24.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }
    std::ofstream out("output.cpp");

    bool inVar = false;
    bool inBegin = false;

    out << "#include <iostream>\nusing namespace std;\nint main() {\n";

    std::string line;
    // Read the file line by line
    while (std::getline(file, line)) {
        if (line == "var") {
            inVar = true;
            continue;
        }
        if (line == "begin") {
            inVar = false;
            inBegin = true;
            continue;
        }
        if (line == "end.") {
            break;
        }
        if (inVar) {
            auto found = line.find(':');
            std::string cleaned_line = line.substr(0, found);
            out << "\tint " << cleaned_line << ";\n";
        }
        if (inBegin) {
            if (line.find("write") != std::string::npos) {
                if (line.find(',') != std::string::npos) {
                    auto found1 = line.find('(');
                    auto found2 = line.find(',');
                    std::string value1 = line.substr(found1 + 2, found2 - found1 - 2);
                    auto found3 = found2 + 2;
                    auto found4 = line.find(')');
                    std::string value2 = line.substr(found3, found4 - found3 - 1);
                    out << "\tcout << " << value1 << " << " << value2 << " ;\n";
                }
                else {
                    auto found1 = line.find('(');
                    auto found2 = line.find (')');
                    std::string value = line.substr(found1 + 2, found2 - found1 - 2);
                    out << "\tcout << " << value << ";\n";
                }
                
            }
            else {
                out << "\t" << line << std::endl;
            }
        }

    }
    out << "\treturn 0 ;\n";
    out << "}\n";

    // Close the file
    file.close();
    std::cout << "Output printed to output.cpp" << std::endl;
    return 0;
}