#ifndef __INCLUDE_HTTP_TCPSERVER__
#define __INCLUDE_HTTP_TCPSERVER__
#include "http_tcpServer.h"
#endif

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_SSTREAM__
#define __INCLUDE_SSTREAM__
#include <sstream>
#endif

#ifndef __INCLUDE_IO__
#define __INCLUDE_IO__
#include <io.h>
#endif

#ifndef __INCLUDE_FORMAT__
#define __INCLUDE_FORMAT__
#include <format>
#endif

#ifndef __INCLUDE_THREADPOOL__
#define __INCLUDE_THREADPOOL__
#include "ThreadPool.h"
#endif

void removeCarriageReturn(char* token) {
	if(token == nullptr) {
		return;
	}

	char* read_ptr = token;
	char* write_ptr = token;

	while (*read_ptr) {
		if (*read_ptr != '\r') {
			*write_ptr = *read_ptr;
			++write_ptr;
		}

		++read_ptr;
	}

	*write_ptr = '\0';
}

namespace {
	const int BUFFER_SIZE = 30720;

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
		: m_ip_address(ip_address), m_port(port), m_socket(), m_new_socket(),
		m_incomingMessage(), m_socketAddress(),
		m_socketAddress_len(sizeof(m_socketAddress)),
		m_serverMessage(buildResponse()), m_wsaData()
		//m_serverMessage(), m_wsaData()
	{
		
		m_socketAddress.sin_family = AF_INET;
		m_socketAddress.sin_port = htons(m_port);
		m_socketAddress.sin_addr.s_addr = inet_addr(m_ip_address.c_str());

		if (startServer() != 0) {
			ostringstream ss;
			ss << "Failed to start server with PORT: " << ntohs(m_socketAddress.sin_port);
			log(ss.str());
		}
	}

	TcpServer::~TcpServer() {
		closeServer();
	}

	int TcpServer::startServer() {
		if (WSAStartup(MAKEWORD(2, 0), &m_wsaData) != 0) {
			exitWithError("WSAStartup failed");
		}

		m_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (m_socket < 0) {
			exitWithError("Cannot create socket");
			return 1;
		}

		if (::bind(m_socket, (sockaddr*)&m_socketAddress, m_socketAddress_len) < 0) {
			exitWithError("Cannot connect socket to address");
			return 1;
		}

		return 0;
	}

	void TcpServer::closeServer() {
		closesocket(m_socket);
		closesocket(m_new_socket);
		WSACleanup();
		exit(0);
	}

	void TcpServer::startListen() {
		if (listen(m_socket, 20) < 0) {
			exitWithError("Socket listen failed");
		}

		ostringstream ss;
		ss << "\n*** Listening on ADDRESS: " << inet_ntoa(m_socketAddress.sin_addr) << " PORT: " << ntohs(m_socketAddress.sin_port) << " ***\n\n";
		log(ss.str());

		int bytesReceived;

		Thread::ThreadPool tPool(10);
		vector<future<void>> futureResults;

		while (true) {
			log("===== Waiting for a new connection =====\n\n\n");
			acceptConnection(m_new_socket);

			/*char buffer[BUFFER_SIZE] = {0};
			bytesReceived = recv(m_new_socket, buffer, BUFFER_SIZE, 0);
			log(buffer);
			if (bytesReceived < 0) {
				exitWithError("Failed to receive bytes from client socket connection");
			}*/

			futureResults.emplace_back(tPool.EnqueueJob([this](SOCKET& new_socket) {
				http_handler(new_socket);

				ostringstream ss;
				ss << "------ Received Request from client ------\n\n";
				log(ss.str());

				sendResponse();

				closesocket(new_socket);
				}, m_new_socket));
			

		}
	}

	void TcpServer::acceptConnection(SOCKET& new_socket) {
		new_socket = accept(m_socket, (sockaddr*)&m_socketAddress, &m_socketAddress_len);
		if (new_socket < 0) {
			ostringstream ss;
			ss << "Server failed to accept incoming connection form ADDRESS: " << inet_ntoa(m_socketAddress.sin_addr) << "; PORT: " << ntohs(m_socketAddress.sin_port);
			exitWithError(ss.str());
		}
	}

	string TcpServer::buildResponse() {
		string htmlFile = "<!DOCTYPE html><html lang=\"en\"><body><h1> HOME </h1><p> Hello from your Server :) </p></body></html>";
		ostringstream ss;
		ss << "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " << htmlFile.size() << "\n\n" << htmlFile;

		return ss.str();
	}

	void TcpServer::sendResponse() {
		int bytesSent;
		long totalBytesSent = 0;

		while (totalBytesSent < m_serverMessage.size()) {
			bytesSent = send(m_new_socket, m_serverMessage.c_str(), m_serverMessage.size(), 0);
			if (bytesSent < 0) {
				break;
			}
			totalBytesSent += bytesSent;
		}

		if (totalBytesSent == m_serverMessage.size()) {
			log("------ Server Response sent to client ------\n\n");
		}
		else {
			log("Error sending response to client.");
		}
	}

	// HTTP
	void TcpServer::fill_header(char* header, int status, long len, const char* type) {
		char status_text[40] = { 0 };
		switch (status) {
		case 200:
			strcpy(status_text, "OK");
			break;
		case 404:
			strcpy(status_text, "Not Found");
			break;
		case 500:
		default:
			strcpy(status_text, "Internal Server Error");
			break;
		}
		sprintf(header, HEADER_FMT, status, status_text, len, type);
	}

	void TcpServer::find_mime(char* ct_type, char* uri) {
		char* ext = strrchr(uri, '.');
		if (!strcmp(ext, ".html"))
			strcpy(ct_type, "text/html");
		else if (!strcmp(ext, ".jpg") || !strcmp(ext, ".jpeg"))
			strcpy(ct_type, "image/jpeg");
		else if (!strcmp(ext, ".png"))
			strcpy(ct_type, "image/png");
		else if (!strcmp(ext, ".css"))
			strcpy(ct_type, "text/css");
		else if (!strcmp(ext, ".js"))
			strcpy(ct_type, "text/javascript");
		else strcpy(ct_type, "text/plain");
	}

	void TcpServer::handle_404(SOCKET asock) {
		char header[BUFFER_SIZE] = { 0 };
		fill_header(header, 404, sizeof(NOT_FOUND_CONTENT), "text/html");

		_write(asock, header, strlen(header));
		_write(asock, NOT_FOUND_CONTENT, sizeof(NOT_FOUND_CONTENT));
	}

	void TcpServer::handle_500(SOCKET asock) {
		char header[BUFFER_SIZE] = { 0 };
		fill_header(header, 500, sizeof(SERVER_ERROR_CONTENT), "text/html");

		_write(asock, header, strlen(header));
		_write(asock, SERVER_ERROR_CONTENT, sizeof(SERVER_ERROR_CONTENT));
	}

	void TcpServer::http_handler(SOCKET asock) {
		char header[BUFFER_SIZE] = { 0 };
		char buf[BUFFER_SIZE] = { 0 };

		if (recv(asock, buf, BUFFER_SIZE, 0) < 0) {
			perror("[ERR] Failed to read request.\n");
			handle_500(asock); return;
		}
		log(buf);

		char* method = strtok(buf, " \n=:,");
		char* uri = strtok(NULL, " \n=:,");
		if (method == NULL || uri == NULL) {
			perror("[ERR] Failed to identify method, URI.\n");
			handle_500(asock); return;
		}
		
		printf("[INFO] Handling Request: method=%s, URI=%s\n", method, uri);

		char* nextToken;
		char boundary[BUFFER_SIZE];
		char boundaryEnd[BUFFER_SIZE];
		char salt[3] = "--";
		vector<string> query;
		for (nextToken = strtok(NULL, " \n=:,"); nextToken != NULL; nextToken = strtok(NULL, " \n=:,")) {
			removeCarriageReturn(nextToken);
			//printf("%s\n", nextToken);

			// get boundary id
			if (!strcmp(nextToken, "boundary")) {
				nextToken = strtok(NULL, " \n=:,");
				removeCarriageReturn(nextToken);

				strcpy(boundary, salt);
				strcat(boundary, nextToken);
				
				strcpy(boundaryEnd, boundary);
				strcat(boundaryEnd, salt);
			}
			else if (!strcmp(nextToken, boundary)) {
				
				bool endOfBoundary = false;
				nextToken = strtok(NULL, " \n=:,");
				removeCarriageReturn(nextToken);
				while (strcmp(nextToken, "\"query\"")) {
					if (!strcmp(nextToken, "\"query\""))
						break;

					if (!strcmp(nextToken, boundaryEnd)) {
						endOfBoundary = true;
						break;
					}

					nextToken = strtok(NULL, " \n=:,");
					removeCarriageReturn(nextToken);
				}

				if (!endOfBoundary) {
					nextToken = strtok(NULL, " \n=:,");
					removeCarriageReturn(nextToken);
					while (strcmp(nextToken, "SELECT")) {
						if (!strcmp(nextToken, boundaryEnd))
							break;

						nextToken = strtok(NULL, " \n=:,");
						removeCarriageReturn(nextToken);
					}

					while (strcmp(nextToken, boundaryEnd)) {
						query.push_back(nextToken);

						nextToken = strtok(NULL, " \n=:,");
						removeCarriageReturn(nextToken);
					}
				}
			}
		}

		/*for (string q : query) {
			cout << q << "\n";
		}*/

		/*char safe_uri[BUFFER_SIZE];
		char* local_uri;
		struct stat st;

		strcpy(safe_uri, uri);
		if (!strcmp(safe_uri, "/")) strcpy(safe_uri, "/index.html");

		local_uri = safe_uri + 1;
		if (stat(local_uri, &st) < 0) {
			perror("[WARN] No file found matching URI.\n");
			handle_404(asock); return;
		}

		int fd = open(local_uri, O_RDONLY);
		if (fd < 0) {
			perror("[ERR] Failed to open file.\n");
			handle_500(asock); return;
		}

		int ct_len = st.st_size;
		char ct_type[40];
		find_mime(ct_type, local_uri);
		fill_header(header, 200, ct_len, ct_type);
		_write(asock, header, strlen(header));

		int cnt;
		while ((cnt = read(fd, buf, BUFFER_SIZE)) > 0)
			write(asock, buf, cnt);*/
	}
}