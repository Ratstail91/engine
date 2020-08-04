#include "logging.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
	std::cout << "Testing logging" << std::endl;

	LOG_INIT("out.log", "err.log");

	LOG("Hello world");

	LOG_QUIT();

	return 0;
}