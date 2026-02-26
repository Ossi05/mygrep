#pragma once
#include <string>
#include <vector>

struct Line {
	std::string text{};
	size_t line_number{};
};

struct Options {
	bool show_line_number{};
	bool show_occurrences{};
	bool ignore_case{};
	bool reverse_search{};
};

class MyGrep
{
public:
	static size_t find_from_string(const std::string& search_term, const std::string& text, bool ignore_case = false);
	static std::vector<Line> get_matching_lines(
		const std::string& search_term,
		const std::string& file_name,
		const Options& options = Options()
	);
};

