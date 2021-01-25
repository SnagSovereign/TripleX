#include <iostream>
#include <ctime>
#include <Windows.h>

void PrintIntroduction(int Difficulty)
{
    // print welcome messages
    std::cout << "\n\nYou are an online predator trying to gain access to a webcam, which has ";
    std::cout << "level " << Difficulty << " security...\nYou need to enter the correct codes to continue...\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // declare 3 number code
    int Code[3];
    for (int Index = 0; Index <= 2; Index++)
    {
        Code[Index] = rand() % Difficulty + Difficulty;
    }

    int CodeSum = 0;
    int CodeProduct = 1;

    for (int Num : Code) // for each int in code array
    {
        CodeSum += Num; // add each int to CodeSum
        CodeProduct *= Num; // multiply all ints to get CodeProduct
    }
    
    // display the CodeSum and CodeProduct
    std::cout << "\n* There are 3 numbers in the code";
    std::cout << "\n* The numbers add up to: " << CodeSum;
    std::cout << "\n* The numbers multiply to give: " << CodeProduct << "\n\n";

    //store player guess
    int Guess[3];
    for (int GuessIndex = 0; GuessIndex <= 2; GuessIndex++)
    {
        std::cin >> Guess[GuessIndex];
    }

    int GuessSum = 0;
    int GuessProduct = 1;

    for (int Num : Guess) // for each int in guess array
    {
        GuessSum += Num; // add each int to GuessSum
        GuessProduct *= Num; // multiply all ints to get GuessProduct
    }

    //Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        std::cout << "\nWell done! You gained access to a webcam! Keep going! :D\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        return true;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "\nYou entered the wrong code! You are actual trash! Try again!\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        return false;
    }
}

int main() 
{
    srand(time(NULL)); // create a new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clear any errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            LevelDifficulty++;
        }
    }
    std::cout << "\nYou did it creep. You now have access to all the webcams you desire!\n";
    return 0; 
}