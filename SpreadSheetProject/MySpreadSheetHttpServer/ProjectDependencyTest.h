#ifndef __DEPENDENCYTEST_H__
#define __DEPENDENCYTEST_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class DependencyTest {
public:
	DependencyTest(){}
	void printHello() {
		cout << "Hello, world!\n";
	}
};

#endif