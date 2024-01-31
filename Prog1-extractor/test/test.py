#Lea Frost
#CSCE 240
#Programming Assignment 1 - Extractor

#import from file reader
from src.Extractor import *
#ask user which company they want and store input
input = int(input("Enter 1 to get the stats of Amazon's 2022 10-k report\nEnter 2 to get the stats of Ebay's 2022 10-k report\n"))
#amazon
if(input==1):
    readFile("data/Amazon-2022.txt")
    printStats("Amazon")
#ebay
elif(input==2):
    readFile("data/Ebay-2022.txt")
    printStats("Ebay")
#invalid input
else:
    print("Invalid input: Please enter 1 or 2!")
