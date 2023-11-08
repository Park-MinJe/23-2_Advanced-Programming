#include "Types.h"

int main() {
	
	Types* pInterface = new Integer(10);

	cout << ((Integer*)pInterface)->getIntValue() << "\n";

	delete pInterface;
}