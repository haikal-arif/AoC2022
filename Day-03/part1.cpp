#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

int getSumOfLinePriorities(std::string inputline);

int main(int argc, char* argv[])
{
    using namespace std;

    #ifdef _TEST
    ifstream input_file("test.txt");
    #else 
    ifstream input_file("input.txt");
    #endif

    string line_buffer;
    int sum_of_priorities = 0;

    while(getline(input_file, line_buffer))
    {
        sum_of_priorities += getSumOfLinePriorities(line_buffer);
    }

    cout << "Total of priorities : " << sum_of_priorities << "\n";
    return 0;


    return 0;
}

int getSumOfLinePriorities(std::string inputline)
{
    std::unordered_map<char, bool> compartment1;
    std::unordered_map<char, bool> compartment2;

    std::string::iterator item;
    for(item = inputline.begin(); item != (inputline.begin() + inputline.size()/2); ++item)
    {
        if (compartment1.find(*item) == compartment1.end())
        {
            compartment1.insert({*item, true});
        }
    }

    int priorities = 0;

    for(item; item != inputline.end(); ++item)
    {
        if (compartment1.find(*item) == compartment1.end()) // continue if doesn't contain
        {
            continue;
        }
        if (compartment2.find(*item) != compartment2.end()) // continue if it contains, meaning it already counted
        {
            continue;
        }

        compartment2.insert({*item, true});
        if(('a' <= *item) && (*item <= 'z'))
            priorities += (*item - 'a') + 1;
        else if(('A' <= *item) && (*item <= 'Z'))
            priorities += (*item - 'A') + 27;
    }

    return priorities;


}