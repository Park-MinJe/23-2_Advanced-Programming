#ifndef __INCLUDE_TESTING_H__
#define __INCLUDE_TESTING_H__
#include "testing.h"
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "Logger.h"
#endif

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