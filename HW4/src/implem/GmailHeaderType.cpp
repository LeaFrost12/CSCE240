
#include "../headers/GmailHeaderType.h"
#include <string>

//accessors
string GmailHeaderType::getMimeVersion()
{
    return mimeVersion;
}
string GmailHeaderType::getXGoogleSmtpSource()
{
    return xGoogleSmtpSource;
}
string GmailHeaderType::getDeliveredTo()
{
    return deliveredTo;
}
string GmailHeaderType::getReplyTo()
{
    return replyTo;
}

//mutators
void GmailHeaderType::setMimeVersion(string mimeVersion)
{
    this->mimeVersion = mimeVersion;
}
void GmailHeaderType::setXGoogleSmtpSource(string xGoogleSmtpSource)
{
    this->xGoogleSmtpSource = xGoogleSmtpSource;
}
void GmailHeaderType::setDeliveredTo(string deliveredTo)
{
    this->deliveredTo = deliveredTo;
}
void GmailHeaderType::setReplyTo(string replyTo)
{
    this->replyTo = replyTo;
}