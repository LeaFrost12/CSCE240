#Lea Frost
#CSCE240
#Programming Assignment 1 - Extractor

lines = words = parts = chars = 0

#takes file path and records stats of the file
def readFile(file_name):
    global lines, words, chars, parts
    partlist = []
    file = open(file_name, 'r', encoding="utf8")
    #go through each line and count words, lines, chars, and add instances of "PART"
    for line in file:
        lines += 1
        wordlist = line.split()
        words += len(wordlist)
        chars +=  len(line)
        if "PART" in line:
            partlist.append(line.strip())
    #get rid of duplicates in the list
    parts = len(set(partlist))
    file.close()

#takes the company name and prints the stats to terminal and to a stats file
def printStats(company_name):
    #print to the terminal
    str = f"Statistical Report on {company_name}'s 2022 10-k form:\nLines: {lines}\nWords: {words}\nChars: {chars}\nParts: {parts}\n"
    print(str)
    #print to the file
    file = open(f"data/{company_name}-stats.txt", "w")
    file.write(str)
    file.close()