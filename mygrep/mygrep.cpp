#include "MyGrep.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

size_t MyGrep::find_from_string(const std::string& search_term, const std::string& text)
{
	return text.find(search_term);
}

std::vector<Line> MyGrep::get_matching_lines(const std::string& search_term, const std::string& file_name, const Options& options)
{
	std::ifstream in_file{ file_name };

	if (!in_file)
	{
		throw std::runtime_error("mygrep: file not found: " + file_name);
	}

	std::vector<Line> matching_lines{};
	std::string line{};
	size_t line_number{ 0 };

	while (std::getline(in_file, line)) {
		line_number++;
		if (find_from_string(search_term, line) == std::string::npos) continue;

		matching_lines.push_back({ line, line_number });
	}

	return matching_lines;
}
