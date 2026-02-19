#include "App.h"
#include "MyGrep.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Flag.h"

void App::interactive_mode()
{
	std::string text;
	std::string search_term{};

	// 1. Get the text and search term from the user
	std::cout << "Give a string from which to search for: ";
	std::getline(std::cin, text);

	std::cout << "Give search string: ";
	std::getline(std::cin, search_term);
	std::cout << std::endl;

	// 2. Find the search term from the text
	size_t index = MyGrep::find_from_string(search_term, text);

	// 3. Print results
	if (index == std::string::npos)
	{
		// Search term no found
		std::cout
			<< '"' << search_term << '"'
			<< " NOT found in "
			<< '"' << text << '"';
		return;
	}

	// Search term found
	std::cout
		<< '"' << search_term << '"'
		<< " found in "
		<< '"' << text << '"'
		<< " in position "
		<< index;
}

void App::print_matching_lines(const std::string& search_term, const std::string& file_name, const Options& options)
{
	// 1. Find matching lines
	std::vector<Line> lines{ MyGrep::get_matching_lines(search_term, file_name, options) };

	// 2. Print matching lines
	for (const auto& line : lines) {
		std::cout
			<< (options.show_line_number ? std::to_string(line.line_number) + ": " : "")
			<< line.text
			<< std::endl;
	}

	if (options.show_occurances) {
		// Show matching or not matching occurences
		std::cout
			<< "\nOccurrences of lines "
			<< (options.reverse_search ? "NOT containing " : "containing ")
			<< '"' << search_term << '"'
			<< ": "
			<< lines.size()
			<< std::endl;
	}

}

Options App::parse_options(const std::string& options_str)
{
	Options options{};

	// 1. Check if options_str starts with the prefix
	if (options_str.rfind(Flag::prefix, 0) != 0)
	{
		throw std::invalid_argument("mygrep: invalid option: " + options_str);
	}

	// 2. Go through the selected options
	for (char c : options_str.substr(Flag::prefix.length()))
	{
		switch (c) {
		case Flag::show_line_numbers:
			options.show_line_number = true;
			break;
		case Flag::occurrences:
			options.show_occurances = true;
			break;
		case Flag::ignore_case:
			options.ignore_case = true;
			break;
		case Flag::reverse_search:
			options.reverse_search = true;
			break;
		default:
			break;
		}

	}

	// 3. Return the options
	return options;
}
void App::run(int argc, char* argv[])
{
	switch (argc) {
	case 1:
		// No arguments provided
		interactive_mode();
		break;
	case 3:
		// 2 arguments provided: search term and file name
		print_matching_lines(argv[1], argv[2]);
		break;
	case 4:
		// 3 arguments provided: options, search term and file name
		print_matching_lines(
			argv[2],
			argv[3],
			parse_options(argv[1]));
		break;
	default:
		std::cerr << "mygrep: argument not found";
		break;
	}
}
