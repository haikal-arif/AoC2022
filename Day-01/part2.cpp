#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

int main(int argc, char argv[])
{
    using namespace std;

    ifstream input_file("input.txt");
    string stringbuffer;
    vector<int> most_calories = {0, 0, 0};

    int current_elf = 0;
    int current_calories = 0;
    while(getline(input_file, stringbuffer))
    {
        if(!all_of(stringbuffer.begin(), stringbuffer.end(), isspace)) // Check if it isn't a new elf
        {
            current_calories += stoi(stringbuffer);
            continue;
        }

        if(current_calories > most_calories[0])
        {
            most_calories[2] = most_calories[1];
            most_calories[1] = most_calories[0];
            most_calories[0] = current_calories;
        }

        else if(current_calories > most_calories[1])
        {
            most_calories[2] = most_calories[1];
            most_calories[1] = current_calories;
        }

        else if(current_calories > most_calories[2])
        {
            most_calories[2] = current_calories;
        }

        current_calories = 0;
    }

    int sum_of_calories = accumulate(most_calories.begin(), most_calories.end(), 0);

    for(int calories:most_calories){
        cout << calories << "\n";
    }
    
    cout << sum_of_calories << "\n";

    return 0;
}