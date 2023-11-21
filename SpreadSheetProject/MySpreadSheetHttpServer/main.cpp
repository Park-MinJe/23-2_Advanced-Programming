#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_SERVERTEST__
#define __INCLUDE_SERVERTEST__
#include "ServerTest.h"
#endif

int main() {
	// Spread Sheet integration test
	_ProjectDepencencyTest();
	
	// Connection test
	//_TcpServerIntegrationTest();

	return 0;
}