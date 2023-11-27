#ifndef __PRINT_TABLE_H__
#define __PRINT_TABLE_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "../MyLogger/Logger.h"
#endif

#pragma comment(lib, "../x64/Debug/MyLogger.lib")

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

namespace {
	Logger* _logTable = new Logger("Print Table");

	void printTable(string tbName, vector<string>& contents) {
		int row = contents.size(),
			maxLen = 0,
			strLen,
			tabNameLen = tbName.length();

		// format을 위해 최대 가로 길이 판단
		maxLen = tabNameLen;
		for (int i = 0; i < row; ++i) {
			strLen = contents.at(i).length();
			maxLen = maxLen < strLen ? strLen : maxLen;
		}

		string table = "";
		// -----------------
		for (int i = 0; i < maxLen + 4; i++) {
			table += "-";
		}
		table += "\n";
		cout << table;

		// |   {tabName}   |
		table = "|";
		for (int i = 0; i < maxLen + 2 - tabNameLen + 1; ++i) {
			if (i == (maxLen + 2 - tabNameLen + 1) / 2)
				table += tbName;
			else {
				table += " ";
			}
		}
		table += "|\n";
		cout << table;

		// |---------------|
		table = "|";
		for (int i = 0; i < maxLen + 2; ++i) {
			table += "-";
		}
		table += "|\n";
		cout << table;

		// |    {constent}    |
		table = "";
		for (int i = 0; i < row; ++i) {
			table += "|";

			string tmp = contents.at(i);
			int tmpLen = tmp.length();
			for (int j = 0; j < maxLen + 2 - tmpLen + 1; ++j) {
				if (j == maxLen - tmpLen)
					table += tmp;
				else {
					table += " ";
				}
			}

			table += "|\n";
		}
		cout << table;

		// ------------------
		table = "";
		for (int i = 0; i < maxLen + 4; i++) {
			table += "-";
		}
		table += "\n";

		cout << table << "\n";
	}

	void printTable(string tbName, vector<vector<string>>& contents) {
		int row = contents.size(),
			col = contents.at(0).size(),
			maxLen = 0,
			strLen = 0,
			tabNameLen = tbName.length();

		int* colLen = new int[col];
		for (int i = 0; i < col; ++i) {
			colLen[i] = 0;
		}

		// format을 위해 최대 가로 길이 판단
		maxLen = tabNameLen;
		for (int i = 0; i < row; ++i) {
			strLen = 1;
			for (int j = 0; j < col; ++j) {
				int tmpLen = contents.at(i).at(j).length();
				colLen[j] = colLen[j] < tmpLen ? tmpLen : colLen[j];
				strLen += tmpLen + 3;
			}
			maxLen = maxLen < strLen ? strLen : maxLen;
		}

		string table = "";
		// -----------------
		for (int i = 0; i < maxLen + 4; i++) {
			table += "-";
		}
		table += "\n";
		cout << table;

		// |   {tabName}   |
		table = "|";
		for (int i = 0; i < maxLen + 2 - tabNameLen + 1; ++i) {
			if (i == (maxLen + 2 - tabNameLen + 1) / 2)
				table += tbName;
			else {
				table += " ";
			}
		}
		table += "|\n";
		cout << table;

		// |---------------|
		table = "|";
		for (int i = 0; i < maxLen + 2; ++i) {
			table += "-";
		}
		table += "|\n";
		cout << table;

		// |    {constent}    |    {constent}    |
		table = "";
		for (int i = 0; i < row; ++i) {
			table = "|";

			for (int j = 0; j < col; ++j) {
				string tmp = contents.at(i).at(j);
				int tmpLen = tmp.length();
				for (int k = 0; k < colLen[j] + 2 - tmpLen + 1; ++k) {
					if (k == colLen[j] - tmpLen)
						table += tmp;
					else {
						table += " ";
					}
				}

				table += "|";
			}
			table += "\n";

			cout << table;
		}

		// ------------------
		table = "";
		for (int i = 0; i < maxLen + 4; i++) {
			table += "-";
		}
		table += "\n";

		cout << table << "\n";

		delete colLen;
	}

	void printTable(string tbName, vector<vector<Cell*>>& contents) {
		int row = contents.size(),
			col = contents.at(0).size(),
			maxLen = 0,
			strLen = 0,
			tabNameLen = tbName.length();

		int* colLen = new int[col];
		for (int i = 0; i < col; ++i) {
			colLen[i] = 0;
		}

		// format을 위해 최대 가로 길이 판단
		maxLen = tabNameLen;
		for (int i = 0; i < row; ++i) {
			strLen = 1;
			for (int j = 0; j < col; ++j) {
				int tmpLen = contents.at(i).at(j)->getValue().length();
				colLen[j] = colLen[j] < tmpLen ? tmpLen : colLen[j];
				strLen += tmpLen + 3;
			}
			maxLen = maxLen < strLen ? strLen : maxLen;
		}

		string table = "";
		// -----------------
		for (int i = 0; i < maxLen + 4; i++) {
			table += "-";
		}
		table += "\n";
		cout << table;

		// |   {tabName}   |
		table = "|";
		for (int i = 0; i < maxLen + 2 - tabNameLen + 1; ++i) {
			if (i == (maxLen + 2 - tabNameLen + 1) / 2)
				table += tbName;
			else {
				table += " ";
			}
		}
		table += "|\n";
		cout << table;

		// |---------------|
		table = "|";
		for (int i = 0; i < maxLen + 2; ++i) {
			table += "-";
		}
		table += "|\n";
		cout << table;

		// |    {constent}    |    {constent}    |
		table = "";
		for (int i = 0; i < row; ++i) {
			table = "|";

			for (int j = 0; j < col; ++j) {
				string tmp = contents.at(i).at(j)->getValue();
				int tmpLen = tmp.length();
				for (int k = 0; k < colLen[j] + 2 - tmpLen + 1; ++k) {
					if (k == colLen[j] - tmpLen)
						table += tmp;
					else {
						table += " ";
					}
				}

				table += "|";
			}
			table += "\n";

			cout << table;
		}

		// ------------------
		table = "";
		for (int i = 0; i < maxLen + 4; i++) {
			table += "-";
		}
		table += "\n";

		cout << table << "\n";
	}
}

#endif