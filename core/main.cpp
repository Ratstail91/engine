#include "logging.hpp"

int main(int argc, char** argv) {
	LOG_INIT("out.log", "err.log");

	LOG("log");

	WARN("warn");

	ERROR("error");

	LOG_QUIT();

	return 0;
}