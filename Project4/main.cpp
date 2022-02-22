#include <iostream>
#include <ctime>
#include "windows.h"
using namespace std;

void Introduction(int LevelDifficulty) {
    cout << "\n\t-You have three chances to break into a secure server room...\n";
    Sleep(3000);
    cout << "\n\t-We shouldn't screw up this time...\n";
    Sleep(3000);
    cout << "\n\t-Just enter the correct code to hack all levels of the bank's security system and deal with it...";
    Sleep(4000);
    system("cls");
}

bool PlayGame(int LevelDifficulty)
{

    int CodeA = rand() % LevelDifficulty + LevelDifficulty + 1;
    int CodeB = rand() % LevelDifficulty + LevelDifficulty + 1;
    int CodeC = rand() % LevelDifficulty + LevelDifficulty + 1;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    cout << "\n\tDon't forget about the rules:\n";
    cout << "\t + There are three numbers in the code\n";
    cout << "\t + The codes add-up to: " << CodeSum << endl;
    cout << "\t + The codes multiply to give: " << CodeProduct << endl << endl;
    Sleep(3000);

    int GuessA, GuessB, GuessC;
    
    cout << "\tEnter the code: ";
    cin >> GuessA >> GuessB >> GuessC;
    cout << "\n\tCode checking...";
    Sleep(4000);
    system("cls");

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        cout << "\n\t-Well done! We managed to download $" << (LevelDifficulty*LevelDifficulty)*1000 << " from the bank account! Keep going!";
        Sleep(4000);
        system("cls");
        return true;
    }
    else {
        cout << "\n\t-You entered the wrong code! Be careful!";
        Sleep(4000);
        system("cls");
        return false;
    }
}

int main()
{
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficultyLevel = 10;
    long AoSM = 0;
    int Lives = 3;

    Introduction(LevelDifficulty);

    while (LevelDifficulty <= MaxDifficultyLevel)
    {
        cout << "\n\t-You're on a " << LevelDifficulty << " level of security system...\n";
        if (Lives == 1) {
            cout << "\n\t-You have the last chance, don't let us down...\n";
        }
        else {
            cout << "\n\t-You have only " << Lives << " attempts to crack the code...\n";
        }
        
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();

        if (bLevelComplete) {
            AoSM += (LevelDifficulty * LevelDifficulty) * 1000;
            ++LevelDifficulty;
        }
        else {
            --LevelDifficulty;
            --Lives;
            if (LevelDifficulty < 1 || Lives == 0) {
                cout << "\n\n\t-Oops...";
                Sleep(2000);
                cout << "\n\n\t-The police traced your location! Run away!!!\n\n";
                goto endGame;
            }
        }
    }

    cout << "\n\t-Great work! We transferred $" << AoSM << " from the bank to our account! Now get out of there!!!";
    Sleep(5000);
    system("cls");
    endGame:
    return 0;
}