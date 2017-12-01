#pragma once
#include <WinSock2.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <exception>
#include <json/json.h>

#pragma commenet(lib, "ws2_32.lib");

#define BUF_MAX 100

using namespace std;

class SSOSocket {
protected:
	SOCKET sock;
	sockaddr_in sv_addr;
	const USHORT port = 7654;
	Json::Value query, msg;
	Json::Reader reader;
	Json::FastWriter writer;

	char buf[BUF_MAX];

	string user_id;

	void printBuffer();

public:
	SSOSocket(string sv_ip);
	~SSOSocket();

	void Connect();

	void SetQuery(string code);
	string GetQuery();

	void SendQuery();
	void RecvMsg();

	void ParseMsg();
};
