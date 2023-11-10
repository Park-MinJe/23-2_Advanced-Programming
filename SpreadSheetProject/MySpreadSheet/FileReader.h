#ifndef __FILEREADER_H__
#define __FILEREADER_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_FSTREAM__
#define __INCLUDE_FSTREAM__
#include <fstream>
#endif

#ifndef __INCLUDE_WINDOWS__
#define __INCLUDE_WINDOWS__
#include <windows.h>
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "Logger.h"
#endif

#ifndef __INCLUDE_FILESYSTEM__
#define __INCLUDE_FILESYSTEM__
#include "FileSystem.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class FileReader : public FileSystem {
	Logger* _log;

	ifstream readFile;
public:
	FileReader() : FileSystem() {
		_log = new Logger("FileReader");
		_log->info("File Reader is loaded");
	}
	~FileReader() {
		_log->info("File Reader is deallocated");
		delete _log;
	}

	void readMssFile(string fn) {
		readFile.open(".\\resources\\" + fn);
		if (readFile.is_open()) {
			while (!readFile.eof()) {
				string str;
				getline(readFile, str);
				_log->debug(str);
			}
			readFile.close();
		}
	}
};

#endif