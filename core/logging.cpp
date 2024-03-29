#ifdef DEBUG_LOG

#include "core.hpp"
#include "logging.hpp"

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

//for windows
#ifdef PLATFORM_WINDOWS
#include <windows.h>
#endif

//for linux/cygwin
const char* YELLOW = "\033[0;33m";
const char* RED = "\033[0;31m";
const char* NOCOLOR = "\033[0;0m";

using namespace std;

static bool initialized = false;
static ofstream out;
static ofstream err;

//utilities
static string timestamp() {
	time_t t = time(nullptr);
	ostringstream oss;

	oss << "[" << put_time(std::localtime(&t), "%c") << "]: ";

	return oss.str();
}

//API
bool logging::getLoggingInitialized() {
	return initialized;
}

void logging::init(const char* _out, const char* _err) {
	if (initialized) {
		return;
	}

	out.open(_out);
	err.open(_err);

	initialized = true;

	log("Logging initialized");
}

void logging::quit() {
	if (!initialized) {
		return;
	}

	log("Logging finished");

	initialized = false;

	out.close();
	err.close();
}

void logging::log(const char* str) {
	if (!initialized) {
		return;
	}

	cout << timestamp() << str << endl;
	out << timestamp() << str << endl;
}

void logging::warn(const char* str) {
	if (!initialized) {
		return;
	}

#ifdef PLATFORM_WINDOWS
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, 14);
#endif

	cout << YELLOW << timestamp() << str << NOCOLOR << endl;
	out << timestamp() << str << endl;

#ifdef PLATFORM_WINDOWS
	SetConsoleTextAttribute(hConsole, 15);
#endif
}

void logging::error(const char* str) {
	if (!initialized) {
		return;
	}

#ifdef PLATFORM_WINDOWS
	HANDLE hConsole = GetStdHandle(STD_ERROR_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, 12);
#endif

	cerr << RED << timestamp() << str << NOCOLOR << endl;
	out << timestamp() << str << endl;
	err << timestamp() << str << endl;

#ifdef PLATFORM_WINDOWS
	SetConsoleTextAttribute(hConsole, 15);
#endif
}

#endif