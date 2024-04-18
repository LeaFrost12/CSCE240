/*
Lea Frost
CSCE 240
HW 3
2/7/2024
*/
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


#include "../src/headers/Shape.h"
#include "../src/headers/Circle.h"
#include "../src/headers/Rectangle.h"
#include "../src/headers/Triangle.h"

#include "../src/implem/Shape.cpp"
#include "../src/implem/Circle.cpp"
#include "../src/implem/Rectangle.cpp"
#include "../src/implem/Triangle.cpp"

using namespace std;

/*
function for counting the number of lines in order to determine
how many shapes there are
*/
int countLines()
{
    int coun = 0;
    string file_name = "../data/input.txt";
    string line;
    ifstream infile(file_name);
	if (infile.is_open()) {

        while(getline(infile, line))
        {
            coun++;
        }
        infile.close();
    }
    return coun;
}

int numLines = countLines();

/*
Puts the lines of the file into an array
*/
string* readFile()
{
    string file_name = "../data/input.txt";
    string line;
    ifstream infile(file_name);
	if (infile.is_open()) {

        string* lines = new string[numLines];
        for(int i = 0; i<numLines; i++)
        {
            getline(infile, line);
            lines[i] = line;
        }
        infile.close();
        return lines;
		
	} else
    {
		cout << "Unable to find input file";
        return nullptr;
    }
    

}
/*
splits a string into an array by spaces
*/
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
    string output;
    //Take user input
    int property;
    cout << "Enter 1 for area and 2 for perimeter:\n>";
    cin >> property;
    //initialize array and read file
    string* lines = new string[numLines];
    lines = readFile();
    
    //open output file
    string outfile = "../data/output.txt";
    fstream f;
    f.open(outfile);

    //check if file was opened
    if (f) {
    //Iterate through the shapes, perform the operation, and print to output file
    for(int i = 0; i<numLines; i++)
    {
        //split the line
        string* splitline = split(lines[i]);
        //If its a rectangle
        if(splitline[0]=="RECTANGLE")
        {
            if(splitline[1].empty()|| splitline[2].empty())
            {
                output = "Not enough information to calculate";
            }
            else
            {
                Rectangle rect(stod(splitline[1]), stod(splitline[2]));
                
                if(property == 1)
                {
                    output = "RECTANGLE AREA: " + to_string(rect.getArea()) + "cm";
                }
                else if(property == 2)
                {
                    output = "RECTANGLE PERIMETER: " + to_string(rect.getPerimeter()) + "cm";
                }
            }
        }
        //If its a Circle
        else if(splitline[0]=="CIRCLE")
        {
            if(splitline[1].empty())
            {
                output = "Not enough information to calculate";
            }
            else
            {
                Circle circ(stod(splitline[1]));
                if(property==1)
                {
                    output = "CIRCLE AREA: " + to_string(circ.getArea()) + "cm";
                }
                else if (property == 2)
                {
                    output = "CIRCLE PERIMETER: " + to_string(circ.getPerimeter()) + "cm";
                }
            }
        }
        //If its a triangle
        else if(splitline[0]=="TRIANGLE")
        {
            if(splitline[1].empty()|| splitline[2].empty()||splitline[3].empty())
            {
                output = "Not enough information to calculate";
            }
            else
            {
                Triangle tri(stod(splitline[1]), stod(splitline[2]), stod(splitline[3]));
                if(property == 1)
                {
                    output = "TRIANGLE AREA: " + to_string(tri.getArea()) + "cm";
                }
                else if (property == 2)
                {
                    output = "TRIANGLE PERIMETER: " + to_string(tri.getPerimeter()) + "cm";
                }
            }
        }
        //invalid shape input
        else
        {
            output = "Error- Invalid shape input";
        }
        f << output << endl;
    }
    f.close();
    } else {
        cout << "Unable to find output file";
    }
    
    return 0;

}

