#pragma once
#include <iostream>
#include <string>
#include "ServerSocket.h"
#include "ClientSocket.h"
#include "SSOSocket.h"
#include <windows.h>
#include <process.h>

#define SV_PORT 3456
#define BACKLOG 5
#define SSO_SERVER "127.0.0.1"

DWORD WINAPI ClientThread(void* arg);

char *sender_name;
char *sender_addr;
char *reply_addr;
char *subject;
char *recipient;
char *body;

int main() {
	try {
		ServerSocket sv_sock(SV_PORT);
		sv_sock.Listen(BACKLOG);
		while (1) {
			ClientSocket *c_sock = new ClientSocket(SSO_SERVER);
			sockaddr ad;
			int a;
			HANDLE cThread = NULL;
			DWORD cThread_id = NULL;
			//test code
			c_sock->ss_sock.SetQuery("WWNPSPRPSOCAZRUWZBACVZQRZIDHDM");
			c_sock->ss_sock.SendQuery();
			c_sock->ss_sock.RecvMsg();
			c_sock->ss_sock.ParseMsg();

			c_sock->Setsock(sv_sock.Accept((sockaddr*)&(c_sock->cl_addr), &(c_sock->cl_len)));
			cThread = (HANDLE)CreateThread(
				NULL, 0, ClientThread, c_sock, 0, &cThread_id
			);
		}
	}
	catch (exception e) {
		std::cout << "Error: " << e.what() << "WSA: " << WSAGetLastError() << endl;
	}
}

DWORD WINAPI ClientThread(void* arg) {
	ClientSocket cl_sock = *((ClientSocket*)arg);
	SSOSocket ss_sock(SSO_SERVER);

	sender_name = "임의의 이름";
	sender_addr = "dks0554@naver.com";
	reply_addr = "whkwlsdud@naver.com";
	subject = "Test3";
	recipient = "whkwlsdud@naver.com";
	body = "....";


	std::cout << "send mail complete" << endl;
	return 0;
}