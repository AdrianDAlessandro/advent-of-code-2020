#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> read_data(string file_path);

int count_trees(vector<string> data, int right_step, int down_step)
{
    int position = 0, number_of_trees = 0;
    int col_num = data[0].length();
    string str;
    for (int row = 0; row < data.size(); row += down_step)
    {
        str = data[row];
        if (str[position] == '#')
            number_of_trees++;

        position += right_step;
        if (position >= col_num)
            position -= col_num;
    }
    return number_of_trees;
}

void tree_tallies(vector<string> data)
{
    int right_down_pairs[5][2] = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};
    int right_step, down_step, number_of_trees;
    unsigned int multiple = 1;

    for (int i = 0; i < 5; i++)
    {
        right_step = right_down_pairs[i][0];
        down_step = right_down_pairs[i][1];
        number_of_trees = count_trees(data, right_step, down_step);
        multiple *= number_of_trees;
        cout << "Right " << right_step << "; Down " << down_step << ": "
             << number_of_trees << endl;
    }
    cout << "\tMultiple = " << multiple << endl;
}

void day3()
{
    cout << "Numbers of trees (example):" << endl;
    tree_tallies(read_data("data/day3/example.txt"));
    cout << "Numbers of trees (input):" << endl;
    tree_tallies(read_data("data/day3/input.txt"));
}
