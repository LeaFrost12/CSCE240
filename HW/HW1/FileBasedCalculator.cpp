/*
Lea Frost
HW 1
CSCE 240
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string operation;
int a;
int b;
int result;

void readFile()
{
    string file_name = "input.txt";
    string line;

    //read 3 lines
    ifstream infile(file_name);
	if (infile.is_open()) {

		getline(infile, line);
        operation = line;
        getline(infile, line);
        a = stoi(line);
        getline(infile, line);
        b = stoi(line);

		infile.close();
	} else
		cout << "Unable to find input file";

}

void writeFile()
{
    string file_name = "output.txt";
    ofstream outfile(file_name);
    string line;

    if (outfile.is_open()) {
        if (operation == "divide" && b==0)
        {
            outfile << "Error - divide by zero.";
        }
        //print result
        else
        {
            outfile << "The result of " << operation << " on " << a << " and " << b << " is below.\n";
            outfile << result;
        }
        // Close output file
        outfile.close();
    } else {
        cout << "Unable to find output file";
    }

}

int main()
{
    //read file, perform the operation, then write file
    readFile();
    if(operation == "add")
        result = a+b;
    else if(operation == "subtract")
        result = a-b;
    else if(operation == "multiply")
        result = a*b;
    else if(operation == "divide")
    {
        if(b = 0)
        {
            
        }
        else
            result = a/b;
    }
    writeFile();
}