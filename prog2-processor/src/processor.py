#Lea Frost
#PA2 
#CSCE 240

#import regex
import re

#Initialize file name

#returns the contents of an item using a start and end pattern
def printItem(start, end, file):
    #initialize a text string to store the text
    text = ""
    #initialize the regex start and end
    start = re.compile(start)
    end = re.compile(end)
    #iterate through each line in the file
    #open 10k file
    with open(file, "r", encoding="utf8") as f:
        for line in f:
            #when the start expression is found, add each line until the end expression is reached
            if(re.search(start, line)):
                #continue until end is reached
                while(not re.search(end, line)):
                    text += line
                    line = f.readline()
                break
    #print to file
    printToFile(text)
    #print to command line
    print(f"Here is the answer to that question:\n{text}")

#findPart() for determining what part the user wants and then returning that part from the array
def findPart(str):
    #determine what business they question is asking about and set the path to that file
    if "APPLE" in str:
        file = "data/Apple-2023.txt"
    elif "AMAZON" in str:
        file = "data/Amazon-2022.txt"
    #if company name is not included, ask them to try again
    else:
        print("Sorry, I didn't catch the name of the business. Please include the business name and try again. You can ask about Apple or Amazon.")
        return
    #business name was found, now decide what question they are asking and return the item contents
    #Item 1: Business
    if "BUSINESS" in str:
        return printItem(r"(?i)ITEM 1.\s*BUSINESS", r"(?i)ITEM 1A.\s*RISK FACTORS", file)
    #Item 1A: Risk factors
    elif "RISK FACTOR" in str:
        return printItem(r"(?i)ITEM 1A.\s*RISK FACTORS", r"(?i)ITEM 1B.\s*UNRESOLVED STAFF COMMENTS", file)
    #Item 2: Properties
    elif "PROPERTIES" in str:
        return printItem(r"(?i)ITEM 2.\s*PROPERTIES", r"(?i)ITEM 3.\s*LEGAL PROCEEDINGS", file)
    #Item 3: Legal Proceedings
    elif "LEGAL PROCEEDING" in str:
        return printItem(r"(?i)ITEM 3.\s*LEGAL PROCEEDINGS", r"(?i)ITEM 4.\s*MINE SAFETY DISCLOSURES", file)
    #Item 5: Market
    elif "MARKET" in str:
        return printItem(r"(?i)ITEM 5.\s*MARKET", r"(?i)ITEM 6.", file)
    #Item 7A: Disclosures
    elif "DISCLOSURE" in str:
        return printItem(r"(?i)ITEM 7A.\s*Quantitative and Qualitative Disclosures About Market Risk", r"(?i)ITEM 8.\s*Financial Statements and Supplementary Data", file)
    #Item 10: Directors
    elif "DIRECTOR" in str:
        return printItem(r"(?i)ITEM 10.\s*Directors, Executive Officers, and Corporate Governance", r"(?i)ITEM 11.\s*Executive Compensation", file)
    #Item 11: #Compensation
    elif "COMPENSATION" in str:
        return printItem(r"(?i)ITEM 11.\s*Executive Compensation", r"(?i)ITEM 12.", file)
    #Item 15: Statements
    elif "STATEMENT" in str:
        return printItem(r"(?i)ITEM 15.\s*Exhibit and Financial Statement Schedules", r"(?i)ITEM 16.", file)
    #all information
    elif "ALL INFORMATION" in str:
        return printItem(r"(?i)ITEM 1.\s*BUSINESS", r"(?i)ITEM 16.", file)
    else:
        print("Sorry, I don't recognize that question. Please ask one of the questions listed in the documentation file 'test_output.txt'.")
    

#prints a string to the output file
def printToFile(str):
    #open file for writing
    with open("data/output.txt", "w") as file:
        #write to file
        file.write(str)