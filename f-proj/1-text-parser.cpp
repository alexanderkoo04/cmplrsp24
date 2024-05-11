#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

std::string clean_text(const std::string& text) {
    std::istringstream stream(text);
    std::string line;
    std::vector<std::string> cleaned_lines;

    while (std::getline(stream, line)) {
        auto start = line.find_first_not_of(" \t");
        auto end = line.find_last_not_of(" \t");

        if (start == std::string::npos || end == std::string::npos) {
            continue;
        }

        std::string stripped_line = line.substr(start, end - start + 1);

        auto comment_pos = stripped_line.find("//");
        bool endof = false;
        if (comment_pos == stripped_line.size() - 2) {
            endof = true;
        }
        if (comment_pos != std::string::npos) {
            stripped_line = stripped_line.substr(0, comment_pos);
        }
        if (endof) {
            continue;
        }

        if (stripped_line.empty()) {
            continue;
        }
        

        std::istringstream token_stream(stripped_line);
        std::vector<std::string> tokens;
        std::string token;

        while (token_stream >> token) {
            tokens.push_back(token);
        }

        std::string cleaned_line = std::accumulate(tokens.begin(), tokens.end(), std::string(), [](const std::string& a, const std::string& b) {
            return a.empty() ? b : a + " " + b;
        });

        cleaned_lines.push_back(cleaned_line);

    }
    return std::accumulate(cleaned_lines.begin(), cleaned_lines.end(), std::string(), [](const std::string& a, const std::string& b) {
        return a.empty() ? b : a + "\n" + b;
    });
}

int main() {
    std::ifstream input_file("finalv1.txt");
    if (!input_file.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << input_file.rdbuf();
    input_file.close();
    std::string original_text = buffer.str();

    std::string cleaned_text = clean_text(original_text);

    std::ofstream output_file("finalf24.txt");
    if (!output_file.is_open()) {
        std::cerr << "Output file failed to open." << std::endl;
        return 1;
    }

    output_file << cleaned_text;
    output_file.close();

    std::cout << "Cleaning complete. Output written to 'finalf24.txt'." << std::endl;
    return 0;
}