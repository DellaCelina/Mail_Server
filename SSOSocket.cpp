#include "SSOSocket.h"

void SSOSocket::printBuffer() {
	for (int i = 0; buf[i] != '\n'; i++) {
		putchar(buf[i]);
	}
	cout << endl;
}

SSOSocket::SSOSocket(string sv_ip){
	if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		throw exception("SSOSocket Error");
	memset(&sv_addr, 0, sizeof(sv_addr));
	sv_addr.sin_family = AF_INET;
	sv_addr.sin_port = htons(port);
	sv_addr.sin_addr.S_un.S_addr = inet_addr(sv_ip.c_str());

	Connect();
}

SSOSocket::~SSOSocket(){
	closesocket(sock);
}

void SSOSocket::Connect()
{
	if (connect(sock, (sockaddr*)&sv_addr, sizeof(sv_addr)) == SOCKET_ERROR) {
		throw exception("Connect Error");
	}
}

void SSOSocket::SetQuery(string code)
{
	query["code"] = code.c_str();
	query["commandSort"] = "query";
	query["code"] = code.c_str();
}

string SSOSocket::GetQuery()
{
	return writer.write(query);
}

void SSOSocket::SendQuery(){
	string value = GetQuery();
	if (send(sock, value.c_str(), value.length(), 0) == SOCKET_ERROR)
		throw exception("Send Error");
}

void SSOSocket::RecvMsg() {
	if (recv(sock, buf, BUF_MAX, 0) == 0)
		throw exception("Recv Error");
}

void SSOSocket::ParseMsg() {
	string istream = buf;
	printBuffer();
	reader.parse(buf, msg);
	if (msg.get("result", "").asString() == "NO_EXIST")
		user_id = "\0";
	else if (msg.get("result", "").asString() == "EXIST")
		user_id = msg.get("id", "").asString();
}
