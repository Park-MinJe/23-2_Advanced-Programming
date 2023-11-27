#ifndef __INCLUDE_SPREADSHEETTEST_H__
#define __INCLUDE_SPREADSHEETTEST_H__
#include "SpreadSheetTest.h"
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "../MyLogger/Logger.h"
#endif

#pragma comment(lib, "../x64/Debug/MyLogger.lib")

Logger* _logMain = new Logger("Main");

int main() {
	// Type down casting test
	//_typeDownCasting();

	// Work Page initializing test
	//_workPageInitializing();

	// Work Book initializing test
	//_workBookInitializing();

	// Spread Sheet Program test
	//_spreadSheetProgram();

	// File System test
	// File Reader Initializing test
	_fileReaderTest();

	delete _logTable;
	delete _logTest;
	delete _logMain;
}