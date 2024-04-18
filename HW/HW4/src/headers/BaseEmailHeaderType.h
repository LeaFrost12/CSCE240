


#ifndef HEADERS_BASEEMAILHEADERTYPE_H
#define HEADERS_BASEEMAILHEADERTYPE_H

#include <string>

using namespace std;

class BaseEmailHeaderType{
    string received;
    string to;
    string from;
    string cc;
    string contentType;
    string date;
    string messageID;
    string subject;
    string contentTransferEncoding;

    public:
        BaseEmailHeaderType(){};

        string getReceived();
        string getTo();
        string getFrom();
        string getCC();
        string getContentType();
        string getDate();
        string getMessageID();
        string getSubject();
        string getContentTransferEncoding();

        void setReceived(string received);
        void setTo(string to);
        void setFrom(string from);
        void setCC(string cc);
        void setContentType(string contentType);
        void setDate(string date);
        void setMessageID(string messageID);
        void setSubject(string subject);
        void setContentTransferEncoding(string contentTransferEncoding);
};
#endif