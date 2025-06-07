#include "../include/grep.h"
#include <iostream>
#include <fstream>
#include <sstream>

mygrep::mygrep(const std::string& pattern) : pattern_(pattern) 
{
    if (pattern_.empty()) throw std::invalid_argument("Pattern cannot be empty");
}

bool mygrep::search(const std::string& text) const 
{
    return text.find(pattern_) != std::string::npos;
}

std::vector<size_t> mygrep::find_matches(const std::string& line) const 
{
    std::vector<size_t> matches;

    // if pattern is longer than line, no matches
    if (pattern_.length() > line.length()) return matches;
    
    // search through each possible starting position
    for (size_t i = 0; i <= line.length() - pattern_.length(); ++i) {
        if (match_literal(line, i)) {
            matches.push_back(i);
        }
    }

    return matches;
}

bool mygrep::match_literal(const std::string& text, size_t pos) const 
{
    // match if there is enough characters left in text
    if (pos + pattern_.length() > text.length()) return false;

    // compare each character in the pattern with the text
    for (size_t i = 0; i < pattern_.length(); ++i) {
        if (text[pos + i] != pattern_[i]) {
            return false; // mismatch found
        }
    }
    return true; // all characters matched successfully
}

void mygrep::process_file(const std::string& filename) const 
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;
    int line_number = 1;

    while (std::getline(file, line)) {
        if (search(line)) {
            std::cout << "Line " << line_number << ": " << line << std::endl;
        }
        ++line_number;
    }

    file.close();
}

void mygrep::process_stdin() const 
{
    std::string line;
    int line_number = 1;

    while (std::getline(std::cin, line)) {
        if (search(line)) {
            std::cout << "Line " << line_number << ": " << line << std::endl;
        }
        ++line_number;
    }
}