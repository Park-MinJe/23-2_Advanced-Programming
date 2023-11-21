#ifndef __DTOS_H__
#define __DTOS_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __INCLUDE_VECTOR__
#define __INCLUDE_VECTOR__
#include <vector>
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "../MyLogger/Logger.h"
#include "../MyLogger/Logger.cpp"
#endif

class TabFileDTO {
	Logger* _log;
public:
	string sTabName;
	vector<vector<string>> tabContents;

	TabFileDTO() {
		_log = new Logger("TabFileDTO");
		_log->info("TabFileDTO is allocated");
	}
	~TabFileDTO() {
		_log->info("TabFileDTO is deallocated");
		delete _log;
	}
};

class TabDirectoryDTO {
	Logger* _log;
public:
	string sRootDir;
	string sFileDir;
	vector<TabFileDTO*> tabsInfo;

	TabDirectoryDTO() {
		_log = new Logger("TabDirectoryDTO");
		_log->info("TabDirectoryDTO is allocated");
	}
	~TabDirectoryDTO() {
		_log->info("TabDirectoryDTO is deallocated");
		delete _log;
	}
};

#endif