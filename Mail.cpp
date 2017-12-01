#include "Mail.h"

void Mail::SetRecipients(char ** recipients, int num_of_recipients)
{
	//Set Recipients
	for(int i = 0; i<num_of_recipients; i++)
		this->AddRecipient(recipients[i]);
}

