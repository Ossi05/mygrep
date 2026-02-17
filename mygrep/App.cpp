#include "App.h"
#include "MyGrep.h"
#include <string>
#include <iostream>

void App::run_interactive_mode()
{
	std::string text;
	std::string search_term{};

	std::cout << "Give a string from which to search for: ";
	std::getline(std::cin, text);

	std::cout << "Give search string: ";
	std::getline(std::cin, search_term);
	std::cout << std::endl;

	size_t index = MyGrep::find_from_string(text, search_term);

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
