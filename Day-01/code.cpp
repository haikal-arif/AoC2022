#include <iostream>
#include <fstream>
#include <deque>
#include <string>
#include <algorithm>

int main(int argc, char* argv[])
{
    using namespace std;
    deque<int> elfs_calories;
    elfs_calories.push_back(0);
    
    string stringbuffer;
    int most_caloried_elf = 0;
    int most_calory = 0;

    ifstream input_file("input.txt");

    int current_elf = 0; 
    while(getline(input_file, stringbuffer))
    {
        if(!all_of(stringbuffer.begin(), stringbuffer.end(), isspace))
        {
            int current_calories = stoi(stringbuffer);
            elfs_calories[current_elf] += current_calories;
            continue;
        }

        if(elfs_calories[current_elf] > most_calory)
        {
            most_calory = elfs_calories[current_elf];
            most_caloried_elf = current_elf;
        }
        elfs_calories.push_back(0);
        current_elf += 1;        
        
    }
    cout << "Most Caloried Elf : " << most_caloried_elf << "\n";
    cout << "It's Calories : " << most_calory << "\n";
        
    return 0;
}