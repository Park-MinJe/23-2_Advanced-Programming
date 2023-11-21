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
	Logger(string sLoc);

	string getLogTime();

	void info(string msg);

	void debug(string msg);

	void warn(string msg);
};

#endif