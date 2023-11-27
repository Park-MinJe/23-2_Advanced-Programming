#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#ifndef __INCLUDE_VECTOR__
#define __INCLUDE_VECTOR__
#include <vector>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __INCLUDE_SPREADSHEETPSERVICE__
#define __INCLUDE_SPREADSHEETPSERVICE__
#include "../MySpreadSheet/SpreadSheetService.h"
#endif

#ifndef __INCLUDE__FILEREADERSERVICE__
#define __INCLUDE__FILEREADERTSERVICE__
#include "../MySpreadSheet/FileReaderService.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

namespace http {
	class Controller {
		//Logger* _log;
		SpreadSheetService* spreadSheetService;
		FileReaderService* frService;

	public:
		Controller() {
			//_log = new Logger("Controller");
			//_log->debug("Controller is allocated");

			spreadSheetService = new SpreadSheetService();
			frService = new FileReaderService();
		}
		~Controller() {
			//_log->debug("Controller is deallocated");
			//delete _log;
			delete spreadSheetService;
			delete frService;
		}

		vector<string> getPathTokens(char*& uri) {
			char* nextToken;
			vector<string> path;
			for (nextToken = strtok(uri, "/\\"); nextToken != NULL; nextToken = strtok(NULL, "/\\")) {
				cout << (string(nextToken));
				path.push_back(string(nextToken));
			}

			return path;
		}

		pair<int, string> pathVerifier(string method, vector<string> pathTokens) {
			if (method.compare("GET") == 0) {
				if (pathTokens[0].compare("mssFiles") == 0) {
					return make_pair(200, ShowMssFiles());
				}
				if (pathTokens[0].compare("workbooks") == 0) {
					return make_pair(200, getWorkbookList());
				}
			}
			return make_pair(400, "<h1>404 Not Found</h1>\n");
		}

		/* GET /mssFiles */
		string ShowMssFiles() {
			vector<string> dirAndFileNames = frService->GetMssFilesService();
			string rt = "<p> " + dirAndFileNames[0] + " </p>";

			rt += "<table><tr><th scope=\"col\">ID</td><th scope=\"col\">File Name</td></tr>";
			
			vector<string>::iterator filesIter;
			int i = 0;
			for (i = 0, filesIter = dirAndFileNames.begin() + 1; filesIter != dirAndFileNames.end(); ++i, filesIter++) {
				rt += "<tr><td>" + to_string(i+1) + "</td><td>" + *filesIter + "</td></tr>";
			}
			rt += "</table>";

			return rt;
		}

		/* GET /workbooks */
		string getWorkbookList() {
			map<string, string> workbookList = spreadSheetService->GetWorkBookList();
			string rt = "<table>";

			rt += "<tr><th scope=\"col\">ID</td><th scope=\"col\">File Name</td></tr>";
			
			map<string, string>::iterator workbookListIter;
			for (workbookListIter = workbookList.begin(); workbookListIter != workbookList.end(); workbookListIter++) {
				rt += "<tr><td>" + workbookListIter->first + "</td><td>" + workbookListIter->second + "</td></tr>";
			}
			rt += "</table>";

			return rt;
		}
	};
}

#endif