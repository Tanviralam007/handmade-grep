#ifndef GREP_H
#define GREP_H

#include <string>
#include <vector>

class mygrep {
    public:
        mygrep(const std::string& pattern);

        // main search function - search pattern in a text
        bool search(const std::string& text) const;

        // search in a line and return all matched positions
        std::vector<size_t> find_matches(const std::string& line) const;

        // process a file and return all matched lines
        void process_file(const std::string& filename) const;

        // process stdin
        void process_stdin() const;

    private:
        std::string pattern_;

        // helpper function for literal character matching
        bool match_literal(const std::string& text, size_t pos) const;

        // helper function to check if character is a digit
        bool is_digit(char c) const;

        // Helper function to match a single pattern element at position
        bool matchSingleElement(const std::string& text, size_t text_pos, 
                           const std::string& pattern, size_t pattern_pos, 
                           size_t& consumed_pattern, size_t& consumed_text) const;
};

#endif