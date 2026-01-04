#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <vector>
#include "student.h";

using namespace std;

vector<STUDENT> studentData;

vector<STUDENT> parser()
{
    string line, xline;
    ifstream studentFile("../data/input.csv");
    if (studentFile.is_open())
    {
        getline(studentFile, xline);
        while(getline(studentFile, line))
        {
            vector<string> tokenData;
            stringstream ss(line);
            string dataChunk;
            while (getline(ss, dataChunk, ','))
            {
                tokenData.push_back(dataChunk);
            }
            
        }
        studentFile.close();
    } else cout << "unable to open file";
 
    return studentData;
}