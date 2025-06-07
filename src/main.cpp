#include "../include/grep.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	std::string pattern = argv[1];

	try {
		mygrep grep(argv[1]);

		if (argc == 2) {
			// No files provided, process stdin
			grep.process_stdin();
		} else {
			// Process each file provided
			for (int i = 2; i < argc; ++i) {
				grep.process_file(argv[i]);
			}
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}