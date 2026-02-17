#pragma once
#include <string>
#include <vector>

class MyGrep
{
public:
	static size_t find_from_string(const std::string& search_term, const std::string& text);
	static std::vector<std::string> get_matching_lines(const std::string& search_term, const std::string& file_name);
};

