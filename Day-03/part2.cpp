#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

int getSumOfLinePriorities(std::string line1, std::string line2, std::string line3);

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

    vector<string> threelinebuffer;
    threelinebuffer.resize(3);

    int counter = 0;
    while(getline(input_file, line_buffer))
    {
        threelinebuffer[counter%3] = line_buffer;
        if(counter%3 == 2)
            sum_of_priorities += getSumOfLinePriorities(threelinebuffer[0], threelinebuffer[1], threelinebuffer[2]);
        counter++;
    }

    cout << "Total of priorities : " << sum_of_priorities << "\n";
    return 0;


    return 0;
}



int getSumOfLinePriorities(std::string line1, std::string line2, std::string line3)
{
    std::unordered_map<char, bool> compartment1;
    std::unordered_map<char, bool> compartment2;
    std::unordered_map<char, bool> compartment3;

    std::string::iterator item;
    for(auto item : line1)
    {
        if (compartment1.find(item) == compartment1.end())
        {
            compartment1.insert({item, true});
        }
    }

    int priorities = 0;

    for(auto item : line2)
    {
        if (compartment1.find(item) == compartment1.end()) // continue if doesn't contain
            continue;
        
        if (compartment2.find(item) != compartment2.end()) // continue if it contains, meaning it already counted
            continue;
        compartment2.insert({item, true});
    }

    for(auto item : line3)
    {
        if (compartment2.find(item) == compartment2.end()) // continue if doesn't contain
            continue;
        
        if (compartment3.find(item) != compartment3.end()) // continue if it contains, meaning it already counted
            continue;
        compartment3.insert({item, true});
        
        if(('a' <= item) && (item <= 'z'))
            priorities += (item - 'a') + 1;
        else if(('A' <= item) && (item <= 'Z'))
            priorities += (item - 'A') + 27;
    }
    return priorities;


}