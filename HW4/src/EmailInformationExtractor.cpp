

#include "../src/implem/BasicEmailHeaderType.cpp"
#include "../src/implem/GmailHeaderType.cpp"
#include "../src/implem/OutlookHeaderType.cpp"

#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int countLines(string file)
{
    int coun = 0;
    string line;
    ifstream infile(file);
	if (infile.is_open()) {

        while(getline(infile, line))
        {
            coun++;
        }
        infile.close();
    }
    return coun;
}

void printContent(string headerFile, string start, string end)
{
    smatch m;
    string line;
    string text;

    int numLines = countLines(headerFile);

    regex s(start);
    regex e(end);

    ifstream infile(headerFile);
    if(infile.is_open())
    {
        for(int i = 0; i<numLines; i++)
        {
            getline(infile, line);
            if(regex_match(line, s))
            {
                while(!regex_match(line, e))
                {
                    text += line;
                    getline(infile,line);
                }
                break;
            }
        }
    }
    else
    {
        cout << "Error - file not found" << endl;
    }
    cout << "Here are the contents of that part:\n" << text << endl;
}

//takes header and part and returns the contents of the part
void returnPart(string part, int type)
{
    //if it is gmail
    if (type == 1)
    {
        string file = "../data/GmailHeader.txt";
        if (part == "To")
        {
            printContent(file, "To.*", "Message-ID.*");
        }
        if (part == "From")
        {
            printContent(file, "From.*", "Content-Type.*");
        }
        if (part == "CC")
        {
             printContent(file, "CC.*", "Subject.*");
        }
        if (part == "Received")
        {
            printContent(file, "Received.*", "X-Google-Smtp-Source.*");
        }
        if (part == "Content-Type")
        {
            printContent(file, "Content-Type.*", "Date.*"); 
        }
        if (part == "Date")
        {
            printContent(file, "Date.*", "From.*");
        }
        if (part == "Message-ID")
        {
             printContent(file, "Message-ID.*", "MIME-Version.*");
        }
        if (part == "Subject")
        {
            printContent(file, "Subject.*", "Thread-Topic.*");
        }
        if (part == "Content-Transfer-Encoding")
        {
            printContent(file, "Content-Transfer-Encoding.*", "$");
        }
        if (part == "MIME-Version")
        {
            printContent(file, "MIME-Version.*", "Content-Type.*");
        }
        if (part == "X-Google-Smtp-Source")
        {
            printContent(file, "X-Google-Smtp-Source.*", "Received.*");
        }
        if (part == "Delivered-To")
        {
            printContent(file, "Delivered-To.*", "Received.*");
        }
        if (part == "Reply-To")
        {
            printContent(file, "Reply-To.*", "To.*");
        }
    }
    //if it is outlook
    else if (type == 2)
    {
        if (part == "Received")
        {
            printContent("../data/OutlookHeader.txt", "Received.*", "Authentication-Results.*");
        }
        if (part == "To")
        {
            printContent("../data/OutlookHeader.txt", "To.*", "CC.*");
        }
        if (part == "From")
        {
            printContent("../data/OutlookHeader.txt", "From.*", "To.*");
        }
        if (part == "CC")
        {
            printContent("../data/OutlookHeader.txt", "CC.*", "Subject.*");
        }
        if (part == "Content-Type")
        {
           printContent("../data/OutlookHeader.txt", "Content-Type.*", "Content-Transfer-Encoding.*"); 
        }
        if (part == "Date")
        {
            printContent("../data/OutlookHeader.txt", "Date.*", "Message-ID.*");
        }
        if (part == "Message-ID")
        {
            printContent("../data/OutlookHeader.txt", "Message-ID.*", "References.*");
        }
        if (part == "Subject")
        {
            printContent("../data/OutlookHeader.txt", "Subject.*", "Thread-Topic.*");
        }
        if (part == "Content-Transfer-Encoding")
        {
            printContent("../data/OutlookHeader.txt", "Content-Transfer-Encoding.*", "From.*");
        }
        if (part == "Authentication Results")
        {
            printContent("../data/OutlookHeader.txt", "Authentication Results.*", "Received.*");
        }
        if (part == "Thread Topic")
        {
            printContent("../data/OutlookHeader.txt", "Thread-Topic.*", "Thread-Index.*");
        }
        if (part == "Thread Index")
        {
            printContent("../data/OutlookHeader.txt", "Thread-Index.*", "Date.*");

        }
        if (part == "References")
        {
            printContent("../data/OutlookHeader.txt", "References.*", "In-Reply-To.*");

        }
        if (part == "In-Repy-To")
        {
            printContent("../data/OutlookHeader.txt", "In-Reply-To.*", "Accept-Language.*");
        }
        if (part == "Accept-Language")
        {
            printContent("../data/OutlookHeader.txt", "Accept-Language.*", "Content-Language.*");
        }
        if (part == "X-MS-Has-Attach")
        {
            printContent("../data/OutlookHeader.txt", "X-MS-Has-Attach.*", "X-MS-Exchange-Organization.*");
        }
        if (part == "X-MS-Exchange-Organization")
        {
            printContent("../data/OutlookHeader.txt", "X-MS-Exchange-Organization.*", "$");
        }
        
    }

}

int main()
{
    int input;
    string header;
    string partValue;
    string part;
    string headerFile;

    //ask user if they want to test gmail or outlook
    cout << "Enter 1 to test Gmail and 2 to test Outlook:\n>";
    cin >> input;
    if (input == 1)
    {
        headerFile = "../data/GmailHeader.txt";
    }
    else if (input == 2)
    {
        headerFile = "../data/OutlookHeader.txt";
    }
    else
    {
        cout << "Error - Invalid input" << endl;
        return 0;
    }

    //take input from user
    cout << "Enter the part you are looking for (copy and paste from test_input.txt in the docs folder):\n>";
    cin >> part;

    //return part
    returnPart(part, input);

}