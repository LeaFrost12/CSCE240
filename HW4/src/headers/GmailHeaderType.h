


#ifndef HEADERS_GMAILHEADERTYPE_H_
#define HEADERS_GMAILHEADERTYPE_H_

#include "BaseEmailHeaderType.h"

class GmailHeaderType : public BaseEmailHeaderType
{
    string mimeVersion;
    string xGoogleSmtpSource;
    string deliveredTo;
    string replyTo;

    public:
        string getMimeVersion();
        string getXGoogleSmtpSource();
        string getDeliveredTo();
        string getReplyTo();

        void setMimeVersion(string mimeVersion);
        void setXGoogleSmtpSource(string xGoogleSmtpSource);
        void setDeliveredTo(string deliveredTo);
        void setReplyTo(string replyTo);
};

#endif