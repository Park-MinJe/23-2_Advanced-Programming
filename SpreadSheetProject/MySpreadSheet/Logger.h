#ifndef __LOGGER_H__
#define __LOGGER_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __INCLUDE_CTIME__
#define __INCLUDE_CTIME__
#include <ctime>
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class Logger {
	string loc;
public:
	Logger(string sLoc) : loc(sLoc) { }

	string getLogTime() {
		time_t t = time(nullptr);
		struct tm tstruct;
		errno_t error = localtime_s(&tstruct, &t);

		char buf[80];
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
		return string(buf);
	}
	
	void info(string msg) {
		string logTime = this->getLogTime();

		cout << logTime + "@" + loc + " [info] " + msg + "\n";
	}

	void debug(string msg) {
		string logTime = this->getLogTime();

		cout << logTime + "@" + loc + " [debug] " + msg + "\n";
	}

	void warn(string msg) {
		string logTime = this->getLogTime();

		cout << logTime + "@" + loc + " [warn] " + msg + "\n";
	}
};

#endif