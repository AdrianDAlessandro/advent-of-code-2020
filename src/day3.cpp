#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> read_data(string file_path);

int count_trees(vector<string> data)
{
    int position = 0, number_of_trees = 0;
    int col_num = data[0].length();
    for (string str : data)
    {
        if (str[position] == '#')
            number_of_trees++;

        position += 3;
        if (position >= col_num)
            position -= col_num;
    }
    return number_of_trees;
}

void day3()
{
    vector<string> example_data = read_data("data/day3/example.txt");
    vector<string> input_data = read_data("data/day3/input.txt");

    cout << "Number of trees (example) = " << count_trees(example_data) << endl;
    cout << "Number of trees (input) = " << count_trees(input_data) << endl;
}
