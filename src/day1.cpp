#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> read_data(string file_path);

int find_and_multiply(vector<string> data, bool three_times = false)
{
    for (string x_str : data)
    {
        int x = stoi(x_str);
        for (string y_str : data)
        {
            int y = stoi(y_str);
            if (three_times)
            {
                for (string z_str : data)
                {
                    int z = stoi(z_str);
                    if ((x + y + z) == 2020)
                        return x * y * z;
                }
            }
            else if ((x + y) == 2020)
                return x * y;
        }
    }
    return 0;
}

int main()
{
    vector<string> ex_data = read_data("data/day1/example.txt");
    vector<string> input_data = read_data("data/day1/input.txt");

    cout << "example = " << find_and_multiply(ex_data) << endl;
    cout << "input = " << find_and_multiply(input_data) << endl;

    cout << "example part2 = " << find_and_multiply(ex_data, true) << endl;
    cout << "input part2 = " << find_and_multiply(input_data, true) << endl;

    return 0;
}
