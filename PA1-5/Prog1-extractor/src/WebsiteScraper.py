#I am not using this
import requests
from bs4 import BeautifulSoup

def scrape(url):
    resp=requests.get(url)
    print("Opening the webpage...")
    print(resp.status_code)
    if resp.status_code==200:
        soup = BeautifulSoup(resp.text, 'html.parser')
        #save the 
        filing_text = soup.get_text()
        #open the destination file
        with open('data/companyname-quarteryear.txt', 'w') as file:
            file.write(filing_text)

        print("10-K filing saved successfully.")
    else:
        print("Error - Could not open the webpage.")

# Example URL for a 10-K filing (replace with the actual URL)
filing_url = 'https://www.sec.gov/Archives/edgar/data/1018724/000101872423000004/amzn-20221231.htm'

# Call the function with the 10-K filing URL
scrape(filing_url)