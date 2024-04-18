

#include "../headers/BaseEmailHeaderType.h"
#include <string>


//accessors
string BaseEmailHeaderType::getReceived()
{
    return received;
}

string BaseEmailHeaderType::getTo()
{
    return to;
}
string BaseEmailHeaderType::getFrom()
{
    return from;
}
string BaseEmailHeaderType::getCC()
{
    return cc;
}
string BaseEmailHeaderType::getContentType()
{
    return contentType;
}
string BaseEmailHeaderType::getDate()
{
    return date;
}
string BaseEmailHeaderType::getMessageID()
{
    return messageID;
}
string BaseEmailHeaderType::getSubject()
{
    return subject;
}
string BaseEmailHeaderType::getContentTransferEncoding()
{
    return contentTransferEncoding;
}

//mutators

void BaseEmailHeaderType::setReceived(string received)
{
    this->received = received;
}
void BaseEmailHeaderType::setTo(string to)
{
    this->to = to;
}
void BaseEmailHeaderType::setFrom(string from)
{
    this->from = from;
}
void BaseEmailHeaderType::setCC(string cc)
{
    this->cc = cc;
}
void BaseEmailHeaderType::setContentType(string contentType)
{
    this->contentType = contentType;
}
void BaseEmailHeaderType::setDate(string date)
{
    this->date = date;
}
void BaseEmailHeaderType::setMessageID(string messageID)
{
    this->messageID = messageID;
}
void BaseEmailHeaderType::setSubject(string subject)
{
    this->subject = subject;
}
void BaseEmailHeaderType::setContentTransferEncoding(string contentTransferEncoding)
{
    this->contentTransferEncoding = contentTransferEncoding;
}

