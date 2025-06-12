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
    size_t text_pos = pos;
    size_t pattern_pos = 0;
    
    while (pattern_pos < pattern_.length() && text_pos < text.length()) {
        size_t consumed_pattern = 0;
        size_t consumed_text = 0;
        
        if (!match_single_element(text, text_pos, pattern_, pattern_pos, 
                               consumed_pattern, consumed_text)) {
            return false;
        }
        
        pattern_pos += consumed_pattern;
        text_pos += consumed_text;
    }
    
    // Pattern must be fully consumed for a match
    return pattern_pos == pattern_.length();
}

bool mygrep::is_digit(char c) const 
{
    return c >= '0' && c <= '9';
}

bool mygrep::match_single_element(const std::string& text, size_t text_pos, 
                                  const std::string& pattern, size_t pattern_pos, 
                                  size_t& consumed_pattern, size_t& consumed_text) const 
{
    // Check if we have characters left to match
    if (text_pos >= text.length() || pattern_pos >= pattern.length()) {
        return false;
    }
    
    // Check for \d pattern
    if (pattern_pos + 1 < pattern.length() && 
        pattern[pattern_pos] == '\\' && pattern[pattern_pos + 1] == 'd') {
        
        if (is_digit(text[text_pos])) {
            consumed_pattern = 2; // consumed '\d'
            consumed_text = 1;    // consumed one digit
            return true;
        }
        return false;
    }
    
    // Literal character matching
    if (text[text_pos] == pattern[pattern_pos]) {
        consumed_pattern = 1;
        consumed_text = 1;
        return true;
    }

    
    return false;
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