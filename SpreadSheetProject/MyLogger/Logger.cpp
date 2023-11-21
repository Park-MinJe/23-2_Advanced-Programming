#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "Logger.h"
#endif

Logger::Logger(string sLoc) : loc(sLoc) { }

string Logger::getLogTime() {
	time_t t = time(nullptr);
	struct tm tstruct;
	errno_t error = localtime_s(&tstruct, &t);

	char buf[80];
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return string(buf);
}

void Logger::info(string msg) {
	string logTime = this->getLogTime();

	cout << logTime + "@" + loc + " [info] " + msg + "\n";
}

void Logger::debug(string msg) {
	string logTime = this->getLogTime();

	cout << logTime + "@" + loc + " [debug] " + msg + "\n";
}

void Logger::warn(string msg) {
	string logTime = this->getLogTime();

	cout << logTime + "@" + loc + " [warn] " + msg + "\n";
}