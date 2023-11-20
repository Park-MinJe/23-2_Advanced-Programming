#ifndef __HTTPTCPSERVER_H__
#define __HTTPTCPSERVER_H__

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

#ifndef __INCLUDE_STDIO__
#define __INCLUDE_STDIO__
#include <stdio.h>
#endif

#ifndef __INCLUDE_WINSOCK__
#define __INCLUDE_WINSOCK__
#include <winsock.h>
#endif

#ifndef __INCLUDE_STDLIB__
#define __INCLUDE_STDLIB__
#include <stdlib.h>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef HEADER_FMT
#define HEADER_FMT "HTTP/1.1 %d %s\nContent-Length: %ld\nContent-Type: %s\n\n"
#endif

#ifndef NOT_FOUND_CONTENT
#define NOT_FOUND_CONTENT "<h1>404 Not Found</h1>\n"
#endif

#ifndef SERVER_ERROR_CONTENT
#define SERVER_ERROR_CONTENT "<h1>500 Internal Server Error</h1>\n"
#endif

#pragma comment(lib,"ws2_32.lib")

namespace http {
	class TcpServer {
	public:
		TcpServer(string ip_address, int port);
		~TcpServer();
		void startListen();
	
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
		void acceptConnection(SOCKET& new_socket);
		string buildResponse();
		void sendResponse();

		// HTTP
		void fill_header(char* header, int status, long len, const char* type);
		void find_mime(char* ct_type, char* uri);
		void handle_404(SOCKET asock);
		void handle_500(SOCKET asock);
		void http_handler(SOCKET asock);
	};
}

#endif