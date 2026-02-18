#include "App.h"
#include <iostream>

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
}