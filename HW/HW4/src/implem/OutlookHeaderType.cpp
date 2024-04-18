
#include "../headers/OutlookHeaderType.h"
#include <string>


//accessors
string OutlookHeaderType::getAuthenticationResults()
{
    return authenticationResults;
}
string OutlookHeaderType::getThreadTopic()
{
    return threadTopic;
}
string OutlookHeaderType::getThreadIndex()
{
    return threadIndex;
}
string OutlookHeaderType::getReferences()
{
    return references;;
}
string OutlookHeaderType::getInReplyTo()
{
    return inReplyTo;
}
string OutlookHeaderType::getAcceptLanguage()
{
    return acceptLanguage;
}
string OutlookHeaderType::getContentLanguage()
{
    return contentLanguage;
}
string OutlookHeaderType::getXMSHasAttach()
{
    return xMSHasAttach;
}
string OutlookHeaderType::getXMSExchangeOrganization()
{
    return xMSExchangeOrganization;
}

//mutators
void OutlookHeaderType::setAuthenticationResults(string authenticationResults)
{
   this->authenticationResults = authenticationResults;
}
void OutlookHeaderType::setThreadTopic(string threadTopic)
{
    this->threadTopic = threadTopic;
}
void OutlookHeaderType::setThreadIndex(string threadIndex)
{
    this->threadIndex = threadIndex;
}
void OutlookHeaderType::setReferences(string references)
{
    this->references = references;
}
void OutlookHeaderType::setInReplyTo(string inReplyTo)
{
    this->inReplyTo = inReplyTo;
}
void OutlookHeaderType::setAcceptLanguage(string acceptLanguage)
{
    this->acceptLanguage = acceptLanguage;
}
void OutlookHeaderType::setContentLanguage(string contentLanguage)
{
    this->contentLanguage = contentLanguage;
}
void OutlookHeaderType::setXMSHasAttach(string xMSHasAttach)
{
    this->xMSHasAttach = xMSHasAttach;
}
void OutlookHeaderType::setXMSExchangeOrganization(string XMSExchangeOrganization)
{
    this->xMSExchangeOrganization = xMSExchangeOrganization;
}