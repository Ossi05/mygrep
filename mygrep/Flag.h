#pragma once
#include <string>

struct Flag {
	static const std::string prefix;
	static const char show_line_numbers{ 'l' };
	static const char occurrences{ 'o' };
	static const char ignore_case{ 'i' };
	static const char reverse_search{ 'r' };
};
