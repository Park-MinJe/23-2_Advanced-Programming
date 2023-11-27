#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_WINDOWS__
#define __INCLUDE_WINDOWS__
#include <windows.h>
#endif

#ifndef __INCLUDE_ATLSTR__
#define __INCLUDE_ATLSTR__
#include <atlstr.h>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "../MyLogger/Logger.h"
#include "../MyLogger/Logger.cpp"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

namespace {
	const string TCHARToString(const TCHAR* ptsz) {
		int len = wcslen((wchar_t*)ptsz);

		int lenForChar = 2 * len + 1;
		size_t size = 0;
		char* psz = new char[lenForChar];
		wcstombs_s(&size, psz, len + 1, (wchar_t*)ptsz, lenForChar);
		string s = psz;

		delete[] psz;
		return s;
	}
}

class FileSystem {
	Logger* _log;
	TCHAR currentPath[MAX_PATH] = { 0, };
public:
	FileSystem() {
		_log = new Logger("FileSystem");
		_log->info("File System is loaded");

		GetCurrentDirectory(MAX_PATH, currentPath);
		_log->debug("Current Path is " + TCHARToString(currentPath));
	}
	~FileSystem() {
		_log->info("File System is deallocated");
		delete _log;
	}

	void showMssFiles() {
		WIN32_FIND_DATA c_file;
		
		CString fileFormat;
		fileFormat.Format(_T(".\\resources\\*.mss"));

		HANDLE hFile = FindFirstFile(fileFormat, &c_file);
		CString foundFileName;
		_log->debug("*.mss Files at " + TCHARToString(currentPath) + "\\resources\\");
		if (hFile != INVALID_HANDLE_VALUE) {
			do {
				foundFileName.Format(_T("%s"), c_file.cFileName);
				_log->debug(string(CT2CA(foundFileName)));
			} while (FindNextFile(hFile, &c_file));
		}
		FindClose(hFile);
	}

	vector<string> getMssFiles() {
		vector<string> rt;

		WIN32_FIND_DATA c_file;

		CString fileFormat;
		fileFormat.Format(_T(".\\resources\\*.mss"));

		HANDLE hFile = FindFirstFile(fileFormat, &c_file);
		CString foundFileName;
		rt.push_back(string("*.mss Files at " + TCHARToString(currentPath) + "\\resources\\"));
		if (hFile != INVALID_HANDLE_VALUE) {
			do {
				foundFileName.Format(_T("%s"), c_file.cFileName);
				rt.push_back(string(CT2CA(foundFileName)));
			} while (FindNextFile(hFile, &c_file));
		}
		FindClose(hFile);

		return rt;
	}
};

#endif