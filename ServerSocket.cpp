#include "ServerSocket.h"

ServerSocket::ServerSocket(USHORT port) {
	//WSA Start
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) == INVALID_SOCKET)
		throw exception("WSA Start Error");
	//Set Socket
	if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		throw exception("ServerSocket Error");
	//Set Addr & Port
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);
	if (bind(sock, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
		throw exception("Bind error");
}

ServerSocket::~ServerSocket() {
	WSACleanup();
	closesocket(sock);
}

void ServerSocket::Listen(int backlog)
{
	if (listen(sock, backlog) == SOCKET_ERROR)
		throw exception("Listen Error");
}

SOCKET ServerSocket::Accept(sockaddr* addr, int *len) {
	SOCKET rsult;
	if ((rsult = accept(sock, addr, len)) == INVALID_SOCKET)
		throw exception("Accept Error");
	return rsult;
}