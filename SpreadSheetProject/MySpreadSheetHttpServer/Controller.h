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

		pair<vector<string>, vector<string>> getPathTokens(char*& uri) {
			char* path = strtok(uri, "?");
			char* params = strtok(NULL, "?");

			char* nextToken;
			vector<string> path_list;
			for (nextToken = strtok(path, "/\\"); nextToken != NULL; nextToken = strtok(NULL, "/\\")) {
				//cout << (string(nextToken));
				path_list.push_back(string(nextToken));
			}

			vector<string> param_list;
			for (nextToken = strtok(params, "=&"); nextToken != NULL; nextToken = strtok(NULL, "=&")) {
				if (strcmp(nextToken, "file") == 0) {
					nextToken = strtok(NULL, "=&");
					cout << string(nextToken) << "\n";
					param_list.push_back(string(nextToken));
				}
				else {
					nextToken = strtok(NULL, "=&");
				}
			}

			return make_pair(path_list, param_list);
		}

		pair<int, string> pathVerifier(string method, pair<vector<string>, vector<string>> pathAndParamTokens) {
			vector<string> pathTokens = pathAndParamTokens.first;
			vector<string> paramTokens = pathAndParamTokens.second;

			if (method.compare("GET") == 0) {
				/* GET /mssFiles */
				if (pathTokens[0].compare("mssFiles") == 0) {
					return ShowMssFiles();
				}

				/* GET /workbooks */
				else if (pathTokens[0].compare("workbooks") == 0) {
					if (pathTokens.size() == 1) {
						return getWorkbookList();
					}
					/* GET /workbooks/{workbookname} */
					else if (pathTokens.size() == 2) {

					}
					/* GET /workbooks/{workbookname}/{workpagename} */
					else if (pathTokens.size() == 3) {
						cout << "debug\n";
						return getWorkPageData(pathTokens[1], pathTokens[2]);
					}
					else {
						return make_pair(400, "<h1>404 Not Found</h1>\n");
					}
				}
				else {
					return make_pair(400, "<h1>404 Not Found</h1>\n");
				}
			}
			else if (method.compare("POST") == 0) {
				if (pathTokens[0].compare("workbook") == 0) {
					/* POST /workbook/generate?file={fileName} */
					if (pathTokens.size() >= 2 && pathTokens[1].compare("generate") == 0)
						return makeWorkbookWithExistingMssFiles(paramTokens);
				}
				else {
					return make_pair(400, "<h1>404 Not Found</h1>\n");
				}
			}
			return make_pair(400, "<h1>404 Not Found</h1>\n");
		}

		/* GET /mssFiles */
		pair<int, string> ShowMssFiles() {
			vector<string> dirAndFileNames = frService->GetMssFilesService();
			string rt = "<p> " + dirAndFileNames[0] + " </p>";

			rt += "<table><tr><th scope=\"col\">ID</td><th scope=\"col\">File Name</td></tr>";

			vector<string>::iterator filesIter;
			int i = 0;
			for (i = 0, filesIter = dirAndFileNames.begin() + 1; filesIter != dirAndFileNames.end(); ++i, filesIter++) {
				rt += "<tr><td>" + to_string(i + 1) + "</td><td>" + *filesIter + "</td></tr>";
			}
			rt += "</table>";

			return make_pair(200, rt);
		}

		/* GET /workbooks */
		pair<int, string> getWorkbookList() {
			map<string, string> workbookList = spreadSheetService->GetWorkBookList();
			string rt = "<table>";

			rt += "<tr><th scope=\"col\">ID</td><th scope=\"col\">File Name</td></tr>";

			map<string, string>::iterator workbookListIter;
			for (workbookListIter = workbookList.begin(); workbookListIter != workbookList.end(); workbookListIter++) {
				rt += "<tr><td>" + workbookListIter->first + "</td><td>" + workbookListIter->second + "</td></tr>";
			}
			rt += "</table>";

			return make_pair(200, rt);
		}

		/* GET /workbooks/{workbookname}/{workpagename} */
		pair<int, string> getWorkPageData(string pWorkBookName, string pWorkPageName) {
			pair<string, vector<vector<string>>> workpage = spreadSheetService->GetWorPageDataService(pWorkBookName, pWorkPageName);
			
			string rt = "<form action = \"http://localhost:8080/workbooks/" + pWorkBookName + "/" + pWorkPageName + "/edit\" accept-charset=\"utf-8\" name = \"update\" method = \"post\">";
			rt += "<p>" + workpage.first + "</p>";

			rt += "<table>";

			int row = 0, col = 0;
			vector<vector<string>>::iterator rowIter;
			vector<string>::iterator colIter;
			for (rowIter = workpage.second.begin(); rowIter != workpage.second.end(); rowIter++) {
				rt += "<tr>";
				for (colIter = (*rowIter).begin(); colIter != (*rowIter).end(); colIter++) {
					rt += "<td><input type=\"text\" name=\"" + to_string(row) + "-" + to_string(col) + "\" placeholder=\"" + *colIter + "\"/></td>";
					col++;
				}
				rt += "</tr>";
				row++;
			}

			rt += "</table><input type=\"submit\" value=\"submit\"< / form>";

			return make_pair(200, rt);
		}

		/* POST /workbook/generate?file={fileName} */
		pair<int, string> makeWorkbookWithExistingMssFiles(vector<string> paramTokens) {
			map<string, vector<vector<string>>> tabs = frService->GetTabsByFileNameFromRootResourceDirService(paramTokens);
			spreadSheetService->CreatWorkBookByExistingTablesService(tabs, "CreatedFileByExistingTabs");
			pair<string, vector<string>> workbookListInfo = spreadSheetService->GetWorkBookListService("CreatedFileByExistingTabs");

			string rt = "<p> " + workbookListInfo.first + " </p>";
			rt += "<table>";

			vector<string>::iterator workbookListIter;
			for (workbookListIter = workbookListInfo.second.begin(); workbookListIter != workbookListInfo.second.end(); workbookListIter++) {
				rt += "<tr><td>" + *workbookListIter + "</td></tr>";
			}

			rt += "</table>";
			
			return make_pair(200, rt);
		}
	};
}

#endif