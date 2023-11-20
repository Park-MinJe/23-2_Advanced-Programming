#include "http_tcpServer.h"
#include "ThreadPool.h"

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

int work(int t, int id) {
	cout << to_string(id) + " start\n";
	this_thread::sleep_for(chrono::seconds(t));
	cout << to_string(id) + " end after " + to_string(t) + "s\n";
	return t + id;
}

int main() {
	//using namespace http;

	//TcpServer server = TcpServer("127.0.0.1", 8080);
	//server.startListen();

	ThreadPool::ThreadPool pool(3);
	vector<future<int>> futures;
	for (int i = 0; i < 10; i++) {
		futures.emplace_back(pool.EnqueueJob(work, i % 3 + 1, i));
	}
	for (auto& f : futures) {
		cout << ("result : " + to_string(f.get()) + " \n");
	}

	return 0;
}