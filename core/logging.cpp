#ifdef DEBUG_LOG

#include "logging.hpp"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

static ofstream out;
static ofstream err;

//utilities
static string timestamp() {
	time_t t = time(nullptr);
	ostringstream oss;

	oss << "[" << put_time(std::localtime(&t), "%c %Z") << "]: ";

	return oss.str();
}

//API
void logging::init(const char* _out, const char* _err) {
	out.open(_out);
	err.open(_err);

	log("Logging started");
}

void logging::quit() {
	log("Logging finished");

	out.close();
	err.close();
}

void logging::log(const char* str) {
	cout << timestamp() << str << endl;
	out << timestamp() << str << endl;
}

void logging::warn(const char* str) {
	cout << timestamp() << "WARNING: " << str << endl;
	out << timestamp() << "WARNING: " << str << endl;
}

void logging::error(const char* str) {
	cerr << timestamp() << "ERROR: " << str << endl;
	out << timestamp() << "ERROR: " << str << endl;
	err << timestamp() << "ERROR: " << str << endl;
}

#endif