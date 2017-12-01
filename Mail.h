#pragma once
#include "CSmtp.h"

#pragma comment(lib, "libeay32.lib")
#pragma comment(lib, "ssleay32.lib")
#pragma comment(lib, "json_vc71_libmtd.lib")

#define MAIL_SERVER "smtp.naver.com"
#define SECURITY_TYPE USE_SSL
#define MAIL_SERVER_PORT 465

#define MAIL_ID "dks0554"
#define MAIL_PASSWORD "skdi124"
#define MAILER "Computer Communication / SSO Mailer"


class Mail : public CSmtp {
public:
	Mail() : CSmtp() {
		//Set Security Type
		this->SetSMTPServer(MAIL_SERVER, MAIL_SERVER_PORT);
		this->SetSecurityType(SECURITY_TYPE);
		//Set ID & Password
		this->SetLogin(MAIL_ID);
		this->SetPassword(MAIL_PASSWORD);
		//Set Client name
		this->SetXPriority(XPRIORITY_NORMAL);
		this->SetXMailer(MAILER);
	}
	void SetRecipients(char** recipients, int num_of_recipients);
};