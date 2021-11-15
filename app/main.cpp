#include "logging.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
	std::cout << "Testing logging" << std::endl;

	LOG_INIT("out.log", "err.log");

	LOG("Hello world");
	WARN("Warning");
	ERROR("Error");

	LOG_QUIT();

	return 0;
}