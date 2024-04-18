


#ifndef HEADERS_OUTLOOKHEADERTYPE_H_
#define HEADERS_OUTLOOKHEADERTYPE_H_

#include "BaseEmailHeaderType.h"

class OutlookHeaderType : public BaseEmailHeaderType
{
    string authenticationResults;
    string threadTopic;
    string threadIndex;
    string references;
    string inReplyTo;
    string acceptLanguage;
    string contentLanguage;
    string xMSHasAttach;
    string xMSExchangeOrganization;

    public:
        string getAuthenticationResults();
        string getThreadTopic();
        string getThreadIndex();
        string getReferences();
        string getInReplyTo();
        string getAcceptLanguage();
        string getContentLanguage();
        string getXMSHasAttach();
        string getXMSExchangeOrganization();

        void setAuthenticationResults(string authenticationResults);
        void setThreadTopic(string threadTopic);
        void setThreadIndex(string threadIndex);
        void setReferences(string references);
        void setInReplyTo(string inReplyTo);
        void setAcceptLanguage(string acceptLanguage);
        void setContentLanguage(string contentLanguage);
        void setXMSHasAttach(string xMSHasAttach);
        void setXMSExchangeOrganization(string xMSExchangeOrganization);
};

#endif