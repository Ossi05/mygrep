#include "MyGrep.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

size_t MyGrep::find_from_string(const std::string& search_term, const std::string& text)
{
	return text.find(search_term);
}

std::vector<std::string> MyGrep::get_matching_lines(const std::string& search_term, const std::string& file_name)
{
	std::ifstream in_file{ file_name };

	if (!in_file)
	{
		throw std::runtime_error("mygrep: file not found: " + file_name);
	}

	std::vector<std::string> matching_lines{};
	std::string line{};

	while (std::getline(in_file, line)) {
		if (find_from_string(search_term, line) == std::string::npos) continue;

		matching_lines.push_back(line);
	}

	return matching_lines;
}
