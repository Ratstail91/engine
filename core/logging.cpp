#ifdef DEBUG_LOG

#include "core.hpp"
#include "logging.hpp"

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#ifdef PLATFORM_WINDOWS
#include <windows.h>
#endif

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
	out.open(_out);
	err.open(_err);

	initialized = true;

	log("Logging initialized");
}

void logging::quit() {
	log("Logging finished");

	initialized = false;

	out.close();
	err.close();
}

void logging::log(const char* str) {
	if (!initialized) {
		error("Logging library not initialized");
	}

	cout << timestamp() << str << endl;
	out << timestamp() << str << endl;
}

void logging::warn(const char* str) {
	if (!initialized) {
		error("Logging library not initialized");
	}

#ifdef PLATFORM_WINDOWS
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, 14);
#endif

	cout << timestamp() << "WARNING: " << str << endl;
	out << timestamp() << "WARNING: " << str << endl;

#ifdef PLATFORM_WINDOWS
	SetConsoleTextAttribute(hConsole, 15);
#endif
}

void logging::error(const char* str) {
#ifdef PLATFORM_WINDOWS
	HANDLE hConsole = GetStdHandle(STD_ERROR_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, 12);
#endif

	cerr << timestamp() << "ERROR: " << str << endl;
	out << timestamp() << "ERROR: " << str << endl;
	err << timestamp() << "ERROR: " << str << endl;

#ifdef PLATFORM_WINDOWS
	SetConsoleTextAttribute(hConsole, 15);
#endif
}

#endif