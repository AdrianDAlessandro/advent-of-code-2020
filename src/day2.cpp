#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> read_data(string file_path);

int count_valid_passwords(vector<string> data)
{
    int n, min, max, valid_passwords = 0;
    char letter;
    string password;

    for (string str : data)
    {
        min = stoi(str.substr(0, str.find("-")));
        str.erase(0, str.find("-") + 1);
        max = stoi(str.substr(0, str.find(" ")));
        str.erase(0, str.find(" ") + 1);

        letter = str[0];
        password = str.substr(str.find(": ") + 2);

        n = count(password.begin(), password.end(), letter);

        if (n >= min && n <= max)
            valid_passwords++;
    }

    return valid_passwords;
}

int main()
{
    int example_passwords = count_valid_passwords(read_data("data/day2/example.txt"));
    int input_passwords = count_valid_passwords(read_data("data/day2/input.txt"));

    cout << "Number of valid passwords (example) = " << example_passwords << endl;
    cout << "Number of valid passwords (input) = " << input_passwords << endl;

    return 0;
}
