#include <iostream>
#include <string>


void Display(const std::string& str)
{
    std::cout << " " << str[0] << " | " << str[1] << " | " << str[2] << "\n";
    std::cout << "-----------\n";
    std::cout << " " << str[3] << " | " << str[4] << " | " << str[5] << "\n";
    std::cout << "-----------\n";
    std::cout << " " << str[6] << " | " << str[7] << " | " << str[8] << "\n";
}


char CheckWinner(const std::string& str)
{
    if (str[0] == str[1] && str[1] == str[2] && str[0] != '-') return str[0];
    if (str[3] == str[4] && str[4] == str[5] && str[3] != '-') return str[3];
    if (str[6] == str[7] && str[7] == str[8] && str[6] != '-') return str[6];

    if (str[0] == str[3] && str[3] == str[6] && str[0] != '-') return str[0];
    if (str[1] == str[4] && str[4] == str[7] && str[1] != '-') return str[1];
    if (str[2] == str[5] && str[5] == str[8] && str[2] != '-') return str[2];

    if (str[0] == str[4] && str[4] == str[8] && str[0] != '-') return str[0];
    if (str[2] == str[4] && str[4] == str[6] && str[2] != '-') return str[2];

    return '-';
}

int main()
{
    std::string str(9, '-'); 
    int Player;
    char winner = '-';

    for (int i = 0; i < 9; i++)
    {
       
        system("cls");

        Display(str);

      
        std::cout << "\nPlayer " << ((i % 2 == 0) ? 'O' : 'X') << ", choose position (0-8): ";
        std::cin >> Player;

       
        if (str[Player] != '-')
        {
            std::cout << "Spot already taken! Try again.\n";
            i--; 
            continue;
        }

        
        str[Player] = (i % 2 == 0) ? 'O' : 'X';

        
        winner = CheckWinner(str);
        if (winner != '-')
        {
            system("cls");
            Display(str);
            std::cout << "\nPlayer " << winner << " wins!\n";
            return 0;
        }
    }

    system("cls");
    Display(str);
    std::cout << "\nIt's a draw!\n";
    return 0;
}
