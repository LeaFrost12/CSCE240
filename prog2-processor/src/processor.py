#Lea Frost
#PA2 
#CSCE 240

#import regex
import re

#Initialize file name
file = ""

#returns the contents of an item
def printItem(start,end):
    #initialize a text string to store the text
    text = ""
    #initialize the regex start and end
    start = re.compile(start)
    end = re.compile(end)
    #iterate through each line in the file
    #open 10k file
    with open(file, "r") as file:
        for line in file:
            #when the start expression is found, add each line until the end expression is reached
            if(re.search(start, line)):
                #continue until end is reached
                while(not re.search(end, line)):
                    text += line
                    line = file.readline()
                break
    #print to file
    printToFile(line)
    print(f"Here is the answer to that question:\n{line}")
                

#findPart() for determining what part the user wants and then returning that part from the array
def findPart(str):
    #determine what business they question is asking about and set the path to that file
    if "EBAY" in str:
        file = "data/Ebay-2022.txt"
    elif "AMAZON" in str:
        file = "data/Amazon-2022.txt"
    #if company name is not included, ask them to try again
    else:
        return "Sorry, I didn't catch the name of the business. Please include the business name and try again. You can ask about Ebay or Amazon."
    #business name was found, now decide what question they are asking and return the item contents
    #Item 1: Business
    if "BUSINESS" in str:
        return printItem(r"Item\s1\.\s*Business")
    #Item 1A: Risk factors
    elif "RISK FACTORS" in str:
        return printItem("")
    #Item 2: Properties
    elif "PROPERTIES" in str:
        return printItem("")
    #Item 3: Legal Proceedings
    elif "LEGAL PROCEEDINGS" in str:
        return printItem("")
    #Item 5: Market
    elif "MARKET" in str:
        return printItem("")
    #Item 7A: Disclosures
    elif(str.contains("DISCLOSURES")):
        return printItem("")
    #Item 10: Directors
    elif(str.contains("DIRECTORS")):
        return printItem("")
    #Item 11: #Compensation
    elif(str.contains("COMPENSATION")):
        return printItem("")
    #Item 15: Statements
    elif(str.contains("STATEMENTS")):
        return printItem("")
    else:
        return "Sorry, I don't recognize that question. Please ask one of the questions listed in the documentation file 'test_output.txt' and in the form of 'prog2processor -t \"[question]\"'"

#prints a string to the output file
def printToFile(str):
    #open file for writing
    with open("data/output.txt", "w") as file:
        #write to file
        file.write(str)