#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> read_data(string file_path)
{
    string line;
    vector<string> data;
    ifstream myfile(file_path);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            data.push_back(line);
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";

    return data;
}
