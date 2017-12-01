#pragma once
#include <WinSock2.h>
#include <string.h>
#include <iostream>
#include <stdexcept>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

class ServerSocket {
protected:
	SOCKET sock;
	sockaddr_in addr;
	WSADATA wsaData;
	const int listen_backlog = 5;

public:
	ServerSocket(USHORT port);
	~ServerSocket();

	SOCKET GetSocket() { return sock; }
	void SetSocket(SOCKET socket) { sock = socket; }

	void Listen(int backlog);
	SOCKET Accept(sockaddr* addr, int *len);
};