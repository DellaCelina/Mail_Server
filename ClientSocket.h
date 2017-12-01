#pragma once
#include <Winsock2.h>
#include <stdlib.h>
#include "Mail.h"
#include <json/json.h>
#include "SSOSocket.h"

#pragma comment (lib, "ws2_32.lib")

class ClientSocket {
private:
	char* recv_buffer;
	const int buffer_max = 100;
	Json::Reader reader;
	Json::FastWriter writer;
	Json::Value pars;

public:
	SOCKET sock;
	SSOSocket ss_sock;
	Mail mail;
	sockaddr_in cl_addr;
	int cl_len;

	ClientSocket(string sso_ip);
	~ClientSocket();
	void Setsock(SOCKET socket) { sock = socket; }
	SOCKET Getsock() { return sock; }

	void SendMail(char * sender, char * send_mail, char* recver, char * recv_mail,
		char * reply_mail, char * subject, char * body);
};
