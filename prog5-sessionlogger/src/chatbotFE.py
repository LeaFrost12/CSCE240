#Lea Frost
#ChatbotFE
#CSCE 240H - S24

import sessionlogger
import time
import chatbotBE

#main class
def main():

    user_input = ""
    user_utterances = 0
    system_utterances = 0

    #Create session file name
    current_time = sessionlogger.getTime()
    session_file = f"..\data\chat_sessions\chatsession_{current_time}.txt"

    #out file name
    output_file = "..\data\output\output.txt"

    #record start time
    start = time.perf_counter()
    
    #while loop that continues until the user enters quit
    while (not user_input == "QUIT") & (not user_input == "Q") & (not "QUIT" in user_input):
        
        #save question as a string
        user_input = input("\nEnter the question you would like to ask or enter \"quit\" or \"q\" to exit:\n>")

        #print user utterance to session file
        chatbotBE.printToFile(f"<USER INPUT>:\n\n{user_input}\n", session_file, 'a')
        user_utterances += 1

        user_input = user_input.upper()
        #find the part based on user input
        output = chatbotBE.mapToPart(user_input)

        #print to output file
        chatbotBE.printToFile(output, output_file, 'w')

        #print to session file
        chatbotBE.printToFile(f"<SYSTEM OUTPUT>:\n{output}\n", session_file, 'a')
        system_utterances += 1

    #calculate elapsed time
    elapsed_time = time.perf_counter() - start

    sessionlogger.logSession("chatsession_" + current_time + ".txt", user_utterances, system_utterances, int(elapsed_time))
        

if __name__ == "__main__":
    main()
    