/*
Lea Frost
HW 1
CSCE 240
*/
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

struct Rectangle
{
    double length;
    double width;
};

struct Circle
{
    double radius;
};

struct Triangle
{
    double side1;
    double side2;
    double side3;
};


int coun;

string* readFile()
{
    string file_name = "../data/input.txt";
    string line;
    

    ifstream infile(file_name);
	if (infile.is_open()) {

        while(getline(infile, line))
        {
            coun++;
        }
        string* lines = new string[coun];
        for(int i = 0; i<coun; i++)
        {
            getline(infile, line);
            lines[i] = line;

        }
        return lines;
		infile.close();
	} else
    {
		cout << "Unable to find input file";
        return NULL;
    }
    

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
    string output;
    int property;
    cout << "Enter 1 for area and 2 for perimeter:";
    cin >> property;
    string* lines = new string[coun];
    lines = readFile();

    string file_name = "../data/output.txt";
    fstream outfile(file_name);

    if (outfile.is_open()) {

    for(int i = 0; i<coun; i++)
    {
        string* splitline = split(lines[i]);
        if(splitline[0]=="RECTANGLE")
        {
            if(splitline[1].empty() || splitline[2].empty())
            {
                output = "RECTANGLE: Not enough information to calculate";
            }
            
            else
            {
                Rectangle r = {stod(splitline[1]), stod(splitline[2])};  
                if(property == 1)
                {
                    output = "RECTANGLE AREA: " + to_string((r.length * r.width)) + "cm";
                }
                else if(property == 2)
                {
                    output = "RECTANGLE PERIMETER: " + to_string(2*(r.length+r.width)) + "cm";
                }
            }

            
        }
        else if(splitline[0]=="CIRCLE")
        {
            if(splitline[1].empty())
            {
                output = "CIRCLE: Not enough information to calculate";
            }
            else
            {
                Circle c = {stod(splitline[1])};
                if(property==1)
                {
                    output = "CIRCLE AREA: " + to_string(pow(c.radius, 2.0) * M_PI) + "cm";
                }
                else if (property == 2)
                {
                    output = "CIRCLE PERIMETER: " + to_string(2 * c.radius * M_PI) + "cm";
                }
            }
        }
        
        else if(splitline[0]=="TRIANGLE")
        {
            if(splitline[1].empty() || splitline[2].empty() || splitline[3].empty())
            {
                output = "TRIANGLE: Not enough information to calculate";
            }
            
            else
            {
                Triangle t = {stod(splitline[1]), stod(splitline[2]), stod(splitline[3])};
                if(property == 1)
                {
                    double s = (t.side1 + t.side2 + t.side3)/2;
                    output = "TRIANGLE AREA: " + to_string(sqrt(s*(s-t.side1)*(s-t.side2)*(s-t.side3))) + "cm";
                }
                else if (property == 2)
                {
                    output = "TRIANGLE PERIMETER: " + to_string(t.side1 + t.side2 + t.side3) + "cm";
                }
            }
            
        }

        else
        {
            output = "Error- Invalid shape input";
        }
        outfile << output << endl;
    }
    outfile.close();
    } else {
        cout << "Unable to find output file";
    }
    
    return 0;

    
    
    
}

