#include "http_tcpServer_linux.h"

#include <iostream>
#include <sstream>
#include <io.h>

namespace {
	void log(const string& message) {
		cout << message << endl;
	}

	void exitWithError(const string& errorMessage) {
		cout << WSAGetLastError() << endl;
		log("ERROR: " + errorMessage);
		exit(1);
	}
}

namespace http {
	TcpServer::TcpServer(string ip_address, int port)
		: m_ip_address(ip_address), m_port(port), m_socket(),
		m_new_socket(), m_incomingMessage(), m_socketAddress(),
		m_socketAddress_len(sizeof(m_socketAddress)),
		m_serverMessage() {
		startServer();
	}


}