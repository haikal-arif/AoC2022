#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>

typedef std::deque<char> cratestack;
typedef std::vector<cratestack> cratearray;

void parseLineIntoStack(std::string& input_str, cratearray& crate_array);
void parseCommand(std::string& input_str, cratearray& crate_array);

int main(int argc, char* argv[])
{
    #ifdef _TEST
    std::ifstream input_file("test.txt");
    size_t crate_array_size = 3;
    #else
    std::ifstream input_file("input.txt");
    size_t crate_array_size = 9;
    #endif

    std::string strbuffer;

    cratearray crate_array(crate_array_size, cratestack({}));

    while (std::getline(input_file, strbuffer))
    {
        if (isdigit(strbuffer[1]))
            break; // Stack config is ended
        parseLineIntoStack(strbuffer, crate_array);
    }

    int counter=0;
    while (std::getline(input_file, strbuffer))
    {
        parseCommand(strbuffer, crate_array);
        counter++;
    }
    
    std::cout << "Top most crate : " ;

    for(auto& stack: crate_array)
    {
        std::cout << stack.front() << "";
    }

    std::cout << "\n";

    return EXIT_SUCCESS;
}

void parseLineIntoStack(std::string& input_str, cratearray& crate_array)
{
    for (int crate_position=0; crate_position < crate_array.size(); crate_position++)
    {
        if (isalpha(input_str[crate_position*4 + 1]))
            crate_array[crate_position].push_back(input_str[crate_position*4 + 1]);
    }
}

void parseCommand(std::string& input_str, cratearray& crate_array)
{
    std::stringstream command(input_str);

    std::string instruction, from, to;
    int numcrates, source, destination;

    // Command structure "move <numcrates> from <source> to <destination>"
    command >> instruction >> numcrates >> from >> source >> to >> destination;

    if(instruction != std::string("move")) 
        return;

    for(int moved_crate = 0; moved_crate < numcrates; moved_crate++)
    {
        char crate = crate_array[source-1].front(); // array start from zero
        crate_array[source-1].pop_front();

        crate_array[destination-1].push_front(crate);
    }
    
}