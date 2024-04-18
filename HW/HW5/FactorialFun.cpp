/*
Lea Frost
HW 5 - CSCE 240
*/

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

//function to find factorial
int factorial(int n)
{
    if(n>1)
        return n * factorial(n-1);
    else
        return 1;
}

//function to find combination
int combination(int n, int r)
{
    return factorial(n)/(factorial(r)*factorial(n-r));
}

string* split(string str)
{
    int i = 0;
    string* result = new string[4];
    stringstream data(str);
    string line;
    while(getline(data,line,' '))
    {
        result[i] = line;
        i++;
    }
    return result;
}

int main()
{
    cout << "Enter 'Factorial Fun' + one or two numbers separated by spaces:\nExample: FactorialFun 6 2 compare\n>";
    
    int i = 0;
    string line;
    string* words = new string[4];

    getline(cin, line);

    words = split(line);

    int fact;
    int comb;
    double elapsed_time;
    if(words[0]=="FactorialFun")
    {
        if(words[3]=="compare")
        {
            auto start = chrono::steady_clock::now();
            fact = factorial(stoi(words[1]));
            auto end = chrono::steady_clock::now();
            chrono::duration<double> fact_elapsed_time = end - start;
            cout << words[1] << "! is " << fact << ", took: " << fact_elapsed_time.count() << " seconds" << endl;

            start = chrono::steady_clock::now();
            comb = combination(stoi(words[1]), stoi(words[2]));
            end = chrono::steady_clock::now();
            chrono::duration<double> comb_elapsed_time = end - start;
            cout << "C^" << words[1] << "_" << words[2] << " is " << comb << ", took: " << comb_elapsed_time.count() << " seconds" << endl;

            if(comb_elapsed_time > fact_elapsed_time)
            {
                cout << "Time for processing C^" << words[1] << "_" << words[2] << " is more" << endl;
            }
            else
            {
                cout << "Time for processing " << words[1] << "! is more" << endl;
            } 
            return 0;

        }
        else if(!words[2].empty())
        {
            auto start = chrono::system_clock::now();
            comb = combination(stoi(words[1]), stoi(words[2]));
            auto end = chrono::system_clock::now();
            chrono::duration<double> elapsed_time = end - start;
            cout << comb << "\nTime for processing " << "C^" << words[1] << "_" << words[2] << ": " << elapsed_time.count() << " seconds";

        }
        else if(!words[1].empty())
        {
            auto start = chrono::system_clock::now();
            fact = factorial(stoi(words[1]));
            auto end = chrono::system_clock::now();
            chrono::duration<double> elapsed_time = end - start;
            cout << fact << "\nTime for processing " << words[1] << "!: " << elapsed_time.count() << " seconds";
            return 0;
        }
        else
        {
            cout << "ERROR - Invalid input. Please try again" << endl;
            return 1;
        }
    }
    else
    {
        cout << "ERROR - Please start your prompt with 'FactorialFun'" << endl;
        return 1;
    }

}