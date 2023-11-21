#ifndef __SERVERTEST_H__
#define __SERVERTEST_H__

#ifndef __INCLUDE_HTTP_TCPSERVER__
#define __INCLUDE_HTTP_TCPSERVER__
#include "http_tcpServer.h"
#endif

#ifndef __INCLUDE__SPREADSHEETTEST__
#define __INCLUDE__SPREADSHEETTEST__
#include "../MySpreadSheet/SpreadSheetTest.h"
#endif

#pragma comment(lib, "../x64/Debug/MySpreadSheet.lib")

void _ProjectDepencencyTest() {
	_fileReaderTest();

	delete _logTable;
	delete _logTest;
}

void _TcpServerIntegrationTest() {
	using namespace http;

	TcpServer server = TcpServer("127.0.0.1", 8080);
	server.startListen();
}

#endif