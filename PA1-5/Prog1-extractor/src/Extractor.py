#Lea Frost
#CSCE240
#Programming Assignment 1 - Extractor

lines = words = parts = chars = 0

#takes file path and records stats of the file
def readFile(file_name):
    global lines, words, chars, parts
    partlist = []
    with open(file_name, 'r', encoding="utf8") as inFile:
        with open("data/Formatted-10k.txt", "w", encoding="utf8") as outFile:
            #go through each line and count words, lines, chars, and add instances of "PART"
            for line in inFile:
                lines += 1
                wordlist = line.split()
                words += len(wordlist)
                chars +=  len(line)
                #if part is in the line append it to the part list
                if "PART" in line:
                    partlist.append(line.strip())
                #append to the formatted 10k file
                if not "TABLE OF CONTENT" in line.upper():
                    outFile.write(line)
    #get rid of duplicates in the list
    parts = len(set(partlist))

#takes the company name and prints the stats to terminal and to a stats file
def printStats(company_name):
    #print to the terminal
    str = f"Statistical Report on {company_name}'s 2022 10-k form:\nLines: {lines}\nWords: {words}\nChars: {chars}\nParts: {parts}\n"
    print(str)
    #print to the file
    file = open(f"data/{company_name}-stats.txt", "w")
    file.write(str)
    file.close()