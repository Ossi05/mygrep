#include "App.h"
#include "MyGrep.h"
#include <string>
#include <iostream>
#include <vector>

void App::interactive_mode()
{
	std::string text;
	std::string search_term{};

	std::cout << "Give a string from which to search for: ";
	std::getline(std::cin, text);

	std::cout << "Give search string: ";
	std::getline(std::cin, search_term);
	std::cout << std::endl;

	size_t index = MyGrep::find_from_string(search_term, text);

	if (index == std::string::npos)
	{
		// Index not found
		std::cout
			<< '"' << search_term << '"'
			<< " NOT found in "
			<< '"' << text << '"';
		return;
	}

	// Index found
	std::cout
		<< '"' << search_term << '"'
		<< " found in "
		<< '"' << text << '"'
		<< " in position "
		<< index;
}
void App::print_matching_lines(const std::string& search_term, const std::string& file_name)
{
	std::vector<std::string> lines{ MyGrep::get_matching_lines(search_term, file_name) };

	for (const auto& line : lines) {
		std::cout << line << std::endl;
	}

}
void App::run(int argc, char* argv[])
{
	switch (argc) {
	case 1:
		interactive_mode();
		break;
	case 3:
		print_matching_lines(argv[1], argv[2]);
		break;
	default:
		std::cerr << "mygrep: argument not found";
		break;
	}
}
