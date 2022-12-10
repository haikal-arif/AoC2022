#include <iostream>
#include <fstream>
#include <string>

enum rps
{
    ROCK,
    PAPER,
    SCISSOR
};

rps chartorps(char inp)
{
    if(inp == 'A' || inp == 'X')
        return rps::ROCK;
    if(inp == 'B' || inp == 'Y')
        return rps::PAPER;
    if(inp == 'C' || inp == 'Z')
        return rps::SCISSOR;
}

int do_rps(rps player, rps enemy)
{
    if (player == enemy)
        return 3;
    if (((int)player - (int)enemy == 1) || ((int)player - (int)enemy == -2)) // Winning
        return 6;
    else
        return 0;
}

int getlinescore(std::string line)
{
    rps player, enemy;
    player = chartorps(line[2]);
    enemy = chartorps(line[0]);

    int score = do_rps(player, enemy) + (int) player + 1; // 1 for rock offset

    return score;
}


int main(int argc, char* argv[])
{
    using namespace std;

    #ifdef _TEST
    fstream input_file("test.txt");
    #else
    fstream input_file("input.txt");
    #endif
    string input_line;
    int total_points = 0;

    while(getline(input_file, input_line))
    {
        total_points += getlinescore(input_line);
    }
        
    cout << "Predicted points : " << total_points << "\n" ;

    return 0;
}