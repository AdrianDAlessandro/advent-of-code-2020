#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> read_data(std::string file_path)
{
    std::string line;
    std::vector<int> data;
    std::ifstream myfile(file_path);

    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            data.push_back(std::stoi(line));
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    return data;
}

int find_and_multiply(std::vector<int> data, bool three_times = false)
{
    for (int x : data)
        for (int y : data)
        {
            if (three_times)
            {
                for (int z : data)
                {
                    if ((x + y + z) == 2020)
                        return x * y * z;
                }
            }
            else if ((x + y) == 2020)
                return x * y;
        }
    return 0;
}

int main()
{
    std::vector<int> ex_data = read_data("data/day1/example.txt");
    std::vector<int> input_data = read_data("data/day1/input.txt");

    std::cout << "example = " << find_and_multiply(ex_data) << std::endl;
    std::cout << "input = " << find_and_multiply(input_data) << std::endl;

    std::cout << "example part2 = " << find_and_multiply(ex_data, true) << std::endl;
    std::cout << "input part2 = " << find_and_multiply(input_data, true) << std::endl;

    return 0;
}
