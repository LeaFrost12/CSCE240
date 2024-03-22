#Lea Frost
#PA 4 - user 2 intent query mapper
#CSCE 240H - S24

import time

THRESHOLD = 0.7
WORD_LENGTH = 5

#match sentence
def matchSentence(user_sent, map_sent):
    matches = 0
    match_percent = 0   

    #split sentences into an array for comparison
    user_arr = user_sent.split()
    map_arr = map_sent.split()


    #for each word, check the match for each word in the mapped sentence
    for i in range (len(map_arr)):
        j = 0
        match = False
        while(not match and j<len(user_arr)):
            if(matchWord(user_arr[j].upper(),map_arr[i].upper())>=THRESHOLD):
                matches += 1
                match = True
                print(matches)
            j += 1

    #calculate percentage match
    match_percent = matches / len(map_arr)

    #return percentage match
    return match_percent


#match words
#calculates the number of operations needed to convert user's input to the mapped input
#divides operations by mapped word length
def matchWord(user_word, map_word):
    match_percent = 0
    if(len(user_word)<WORD_LENGTH):
        distance = editDistance(user_word, map_word[0:WORD_LENGTH], len(user_word), WORD_LENGTH)
    else:
        distance = editDistance(user_word[0:WORD_LENGTH], map_word[0:WORD_LENGTH], WORD_LENGTH, WORD_LENGTH)

    match_percent = 1 - (distance / len(map_word))
    
    print(f"{user_word} + {map_word} match: {match_percent}")
    print(f"{user_word} + {map_word} distance: {distance}")
    
    return match_percent

def editDistance(user_word, map_word, user_length, map_length ):

    if user_length == 0:
        return map_length 

    if map_length == 0:
        return user_length

    if user_word[user_length-1] == map_word[map_length-1]:
        return editDistance(user_word, map_word, user_length-1, map_length-1)

    return 1 + min(editDistance(user_word, map_word, user_length, map_length -1),    # Insert
                   editDistance(user_word, map_word, user_length-1, map_length ),    # Remove
                   editDistance(user_word, map_word, user_length-1, map_length -1)    # Replace
                   )
  
#main class
def main():
    start = time.perf_counter()
    percent = matchSentence("what are amazon's legal proceedings?", "legal proceedings")
    
    end = time.perf_counter()
    elapsed = end-start
    print(f"time elapsed: {elapsed}")
    print(percent)
    
    

if __name__ == "__main__":
    main()
    