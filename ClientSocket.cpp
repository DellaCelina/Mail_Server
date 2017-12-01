#include "ClientSocket.h"

ClientSocket::ClientSocket(string sso_ip):ss_sock(sso_ip){
	sock = INVALID_SOCKET;
	recv_buffer = (char*)malloc(buffer_max * sizeof(char));
	cl_len = sizeof(sockaddr_in);
}

ClientSocket::~ClientSocket() {
	if (sock != INVALID_SOCKET) closesocket(sock);
	free(recv_buffer);
}

void ClientSocket::SendMail(char * sender, char * send_mail, char* recver, char * recv_mail,
	char * reply_mail, char * subject, char * body)
{
	mail.SetSenderName(sender);
	mail.SetSenderMail(send_mail);
	mail.SetReplyTo(reply_mail);
	mail.AddRecipient(recv_mail, recver);
	mail.SetSubject(subject);
	mail.AddMsgLine(body);
	mail.Send();
}
