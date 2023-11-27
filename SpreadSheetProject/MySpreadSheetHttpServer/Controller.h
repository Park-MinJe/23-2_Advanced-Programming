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

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

namespace http {
	class Controller {
		//Logger* _log;
		SpreadSheetService* spreadSheetService;

	public:
		Controller() {
			//_log = new Logger("Controller");
			//_log->debug("Controller is allocated");

			spreadSheetService = new SpreadSheetService();
		}
		~Controller() {
			//_log->debug("Controller is deallocated");
			//delete _log;
			delete spreadSheetService;
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

		string pathVerifier(vector<string> pathTokens) {

		}

		/* GET /workbook */
		string getWorkbookList() {

		}
	};
}

#endif