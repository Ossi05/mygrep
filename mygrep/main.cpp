#include "App.h"
#include <iostream>
#include <exception>

int main(int argc, char* argv[])
{
	// occurrences typo
	try {
		App app;
		app.run(argc, argv);
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "mygrep: an unknown error occurred" << std::endl;
		return 1;
	}
}