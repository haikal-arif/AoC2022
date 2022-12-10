#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <sstream>

using namespace std;

typedef tuple<int, int> sectionAssignment;

sectionAssignment getSectionAssignment(string input_line);
bool isFullyContainedPair(sectionAssignment& elf1, sectionAssignment& elf2);


int main(int argc, char* argv[])
{
    

    #ifdef _TEST
    ifstream input_file("test.txt");
    #else 
    ifstream input_file("input.txt");
    #endif

    string input_line;
    string elf1str;
    string elf2str;

    sectionAssignment elf1;
    sectionAssignment elf2;

    int num_fully_contained_pair = 0;
    while(getline(input_file, input_line))
    {
        stringstream inpstream(input_line); 
        getline(inpstream, elf1str, ',');
        getline(inpstream, elf2str, ',');
        
        elf1 = getSectionAssignment(elf1str);
        elf2 = getSectionAssignment(elf2str);        
        num_fully_contained_pair += isFullyContainedPair(elf1, elf2);

    }

    cout << "Total of fully contained pairs : " << num_fully_contained_pair << "\n";

    return EXIT_SUCCESS;
}

sectionAssignment getSectionAssignment(string input_line)
{
    sectionAssignment section({
            stoi(input_line.substr(0, input_line.find('-'))),
            stoi(input_line.substr(input_line.find('-')+1, input_line.size() - input_line.find('-')))
        });
    return section;
}

bool isFullyContainedPair(sectionAssignment& elf1, sectionAssignment& elf2)
{
    if ((get<0>(elf1) >= get<0>(elf2)) && (get<1>(elf1) <= get<1>(elf2)))
        return true;
    if ((get<0>(elf2) >= get<0>(elf1)) && (get<1>(elf2) <= get<1>(elf1)))
        return true;
    return false;
}