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

#ifndef __INCLUDE_CSTDIO__
#define __INCLUDE_CSTDIO__
#include <cstdio>
#endif

#ifndef __INCLUDE_FILESYSTEM__
#define __INCLUDE_FILESYSTEM__
#include "FileSystem.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

#ifndef __INCLUDE_VECTOR__
#define __INCLUDE_VECTOR__
#include <vector>
#endif

#ifndef __INCLUDE_SSTREAM__
#define __INCLUDE_SSTREAM__
#include <sstream>
#endif

namespace {
	vector<string> split(string str, char Delimiter) {
		istringstream iss(str);
		string buffer;

		vector<string> result;

		// TODO: table의 한 항목이 ','를 포함하는 경우 예외처리
		while (getline(iss, buffer, Delimiter)) {
			result.push_back(buffer);
		}

		return result;
	}
}

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

	pair<string, vector<vector<string>>> readMssFile(string fn) {
		vector<vector<string>> fileContent;

		readFile.open(".\\resources\\" + fn);
		if (readFile.is_open()) {
			while (!readFile.eof()) {
				string str;
				getline(readFile, str);
				_log->debug(str);

				vector<string> lineOfFile = split(str, ',');
				fileContent.push_back(lineOfFile);
			}
			readFile.close();
		}

		return make_pair(fn, fileContent);
	}
};

#endif