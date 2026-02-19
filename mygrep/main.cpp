#include "App.h"
#include <iostream>
#include <exception>

int main(int argc, char* argv[])
{

	try {
		App app;
		app.run(argc, argv);
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
	catch (...)
	{
		std::cerr << "mygrep: an unknown error occurred";
		return 1;
	}
}