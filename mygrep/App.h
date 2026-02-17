#pragma once

#include "MyGrep.h"
#include <string>

class App
{
private:
	void interactive_mode();
	void print_matching_lines(
		const std::string& search_term,
		const std::string& file_name,
		const Options& options = Options()
	);
	Options parse_options(const std::string& options_str);
public:
	void run(int argc, char* argv[]);
};

