from datetime import datetime

def makeFile():
    current_time = datetime.now().strftime("%Y_%m_%d-%I_%M_%S_%p")
    return f"..\data\chat_sessions\data_{current_time}.txt"