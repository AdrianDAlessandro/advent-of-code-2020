#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> read_data(string file_path);

bool sled_policy(int min, int max, char letter, string password)
{
    int n = count(password.begin(), password.end(), letter);
    return (n >= min && n <= max);
}

bool toboggan_policy(int pos1, int pos2, char letter, string password)
{
    if (password[pos1 - 1] == letter && password[pos2 - 1] == letter)
        return false;
    if (password[pos1 - 1] == letter || password[pos2 - 1] == letter)
        return true;
    return false;
}

int count_valid_passwords(vector<string> data, string policy)
{
    int n, pos1, pos2, valid_passwords = 0;
    char letter;
    string password;

    for (string str : data)
    {
        pos1 = stoi(str.substr(0, str.find("-")));
        str.erase(0, str.find("-") + 1);
        pos2 = stoi(str.substr(0, str.find(" ")));
        str.erase(0, str.find(" ") + 1);

        letter = str[0];
        password = str.substr(str.find(": ") + 2);

        n = count(password.begin(), password.end(), letter);

        if (policy == "sled" && sled_policy(pos1, pos2, letter, password))
            valid_passwords++;
        else if (policy == "toboggan" && toboggan_policy(pos1, pos2, letter, password))
            valid_passwords++;
    }

    return valid_passwords;
}

void day2()
{
    vector<string> example_data = read_data("data/day2/example.txt");
    vector<string> input_data = read_data("data/day2/input.txt");

    int example_passwords = count_valid_passwords(example_data, "sled");
    int input_passwords = count_valid_passwords(input_data, "sled");

    cout << "Number of valid sled passwords (example) = " << example_passwords << endl;
    cout << "Number of valid sled passwords (input) = " << input_passwords << endl;

    example_passwords = count_valid_passwords(example_data, "toboggan");
    input_passwords = count_valid_passwords(input_data, "toboggan");

    cout << "Number of valid toboggan passwords (example) = " << example_passwords << endl;
    cout << "Number of valid toboggan passwords (input) = " << input_passwords << endl;
}
