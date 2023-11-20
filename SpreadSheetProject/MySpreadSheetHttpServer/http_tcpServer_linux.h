#ifndef __INCLUDE_HTTPTCPSERVER__
#define __INCLUDE_HTTPTCPSERVER__

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

#include <stdio.h>
#include <winsock.h>
#include <stdlib.h>
#include <string>

namespace http {
	class TcpServer {
	public:
		TcpServer(string ip_address, int port);
		~TcpServer();
	
	private:
		string m_ip_address;
		int m_port;
		SOCKET m_socket;
		SOCKET m_new_socket;
		long m_incomingMessage;
		struct sockaddr_in m_socketAddress;
		int m_socketAddress_len;
		string m_serverMessage;
		WSADATA m_wsaData;

		int startServer();
		void closeServer();
	};
}

#endif