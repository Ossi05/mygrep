#pragma once
#include <string>

class App
{
private:
	void interactive_mode();
	void print_matching_lines(const std::string& search_term, const std::string& file_name);
public:
	void run(int argc, char* argv[]);
};

