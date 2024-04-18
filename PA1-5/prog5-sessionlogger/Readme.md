Author: Lea Frost

Code written for CSCE 240, PA5

Description:
This project answers user questions about a business based on
the business's 10k form. The program is built to work for 
Apple and Amazon, but can work for other companies.
It also reports interaction statistics when requested.

How to use:
To run the chatbot, navigate to src and run
'python chatbotFE.py' and ask questions.
Supported questions are listed in test_output.txt, but any
input is acceptable.

For interaction statistics, navigate to src and run any of 
these commands:
    python prog5-sessionlogger -summary
    python prog5-sessionlogger -showchat [chat number]
    python prog5-sessionlogger -showchat-summary [chat number]

Layout:
    data
        chat sessions
            Contains saved chat sessions
        input
            Contains company 10k files
        output
            chat_statistics.csv
            output.txt
    doc
        report.txt
        test_output.txt
    src
        chatbot.py
        sessionlogger.py
        wordmatcher.py
    test
        test.txt