#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <vector>
#include "student.h"

using namespace std;


vector<STUDENT> parser()
{
    vector<STUDENT> studentData;
    string line, xline;
    //reading the input
    ifstream studentFile("../data/input.csv");
    if (studentFile.is_open())
    {
        //ignoring one line
        getline(studentFile, xline);
        while(getline(studentFile, line))
        {
            //loop that reads each line
            vector<string> tokenData;
            stringstream ss(line);
            string dataChunk;
            //on each line read its added to the temp data vector thats used to create a single student object
            while (getline(ss, dataChunk, ','))
            {
                tokenData.push_back(dataChunk);
            }
            //validating that all fields are present
            if (tokenData.size() != 4)
            {
                continue;
            }
            //creating a student object
            STUDENT s;
            s.ID = stoi(tokenData[0]);
            s.name = tokenData[1];
            s.age = stoi(tokenData[2]);
            s.program = tokenData[3];
            //appending it to the return vector going to the main
            studentData.push_back(s);
            
        }
        studentFile.close();
    } else cout << "unable to open file";
 
    return studentData;
}