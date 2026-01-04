#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <vector>


using namespace std;

int main()
{
    string line;
    ifstream studentFile("../data/input.csv");
    if (studentFile.is_open())
    {
        while(getline(studentFile, line))
        {
            studentFile.ignore(numeric_limits<streamsize>::max(), '\n');
            vector<string> sData;

            stringstream ss(line);
            string dataChunk;
            while (getline(ss, dataChunk, ','))
            {
                sData.push_back(dataChunk);
                cout << sData[0];
            }
            
        }
        studentFile.close();
    } else cout << "unable to open file";
 

    return 0;
}