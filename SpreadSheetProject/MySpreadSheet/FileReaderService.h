#ifndef __FILEREADERSERVICE_H__
#define __FILEREADERSERVICE_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_MAP__
#define __INCLUDE_MAP__
#include <map>
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "../MyLogger/Logger.h"
#endif

#pragma comment(lib, "../x64/Debug/MyLogger.lib")

#ifndef __INCLUDE_FILEREADER__
#define __INCLUDE_FILEREADER__
#include "../MySpreadSheet/FileReader.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

namespace {
	class FileReaderService {
		Logger* _log;
		FileReader* fr;

	public:
		FileReaderService();
		~FileReaderService();

		void ShowMssFilesService();
		vector<string> GetMssFilesService();
		map<string, vector<vector<string>>> GetTabsByFileNameFromRootResourceDirService(vector<string> pFns);
	};

	FileReaderService::FileReaderService() {
		_log = new Logger("FileSystemService");
		_log->info("FileSystemService is allocated");

		fr = new FileReader();
	}
	FileReaderService::~FileReaderService() {
		_log->info("FileSystemService is deallocated");
		delete _log;

		delete fr;
	}

	void FileReaderService::ShowMssFilesService() {
		fr->showMssFiles();
	}
	vector<string> FileReaderService::GetMssFilesService() {
		return fr->getMssFiles();
	}

	map<string, vector<vector<string>>> FileReaderService::GetTabsByFileNameFromRootResourceDirService(vector<string> pFns) {
		map<string, vector<vector<string>>> rt;
		for (string fn : pFns) {
			rt.insert(fr->readMssFile(fn));
		}

		return rt;
	}
}

#endif