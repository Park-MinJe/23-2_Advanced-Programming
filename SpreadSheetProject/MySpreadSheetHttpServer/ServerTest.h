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

#ifndef __INCLUDE__SPREADSHEETSERVICE__
#define __INCLUDE__SPREADSHEETSERVICE__
#include "../MySpreadSheet/SpreadSheetService.h"
#endif

#pragma comment(lib, "../x64/Debug/MySpreadSheet.lib")

void _ProjectDepencencyTest() {
	//_fileReaderTest();

	SpreadSheetService* ssService = new SpreadSheetService();
	
	FileSystem* fs = new FileReader();
	fs->showMssFiles();

	pair<string, vector<vector<string>>> table1 = ((FileReader*)fs)->readMssFile("test1.mss");
	printTable(table1.first, table1.second);

	pair<string, vector<vector<string>>> table2 = ((FileReader*)fs)->readMssFile("test2.mss");
	printTable(table2.first, table2.second);

	map<string, vector<vector<string>>> tabs;
	tabs.insert(table1);
	tabs.insert(table2);

	ssService->CreatWorkBookByExistingTablesService(tabs, "CreatedFileByExistingTabs");
	ssService->ShowWorkBookInfoService("CreatedFileByExistingTabs");

	delete _logTable;
	delete _logTest;
	delete fs;
	delete ssService;
}

void _TcpServerIntegrationTest() {
	using namespace http;

	TcpServer server = TcpServer("127.0.0.1", 8080);
	server.startListen();
}



#endif