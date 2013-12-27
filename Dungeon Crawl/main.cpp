//*******************************
//
//  C++ Template Program
//
//*******************************

//*******************************
//
//  Standard Header
//
//*******************************

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

//********************************
//
//  Function Declaration Section
//
//********************************

void displayInstructions (void);
void startGame (int nBoardArray[10][10], int nPlayerArray[100][3],int &nTotalMonsters, int &nTotalTraps, int &nTotalPlayers, int &nStartFlag);
void initializeBoard (int nBoardArray[10][10]);
void initializePlayers (int nPlayerArray[100][3]);
void displayBoard (int nBoardArray[10][10]);
void takeTurns (int nBoardArray[10][10],int nPlayerArray[100][3],int &nTotalPlayers, int &nGameFlag);


//********************************
//
//  Main Program Section
//
//********************************

int main(int nNumberofArgs, char* pszArgs[])
{
    for (;;)
    {
        //*  Variable Declaration
        int nDungeonCrawlBoardArray[10][10];
        int nDungeonCrawlPlayerArray[100][3];
        int nTotalNumberofMonsters = 0;
        int nTotalNumberofTraps = 0;
        int nTotalNumberofPlayers = 0;
        int nStartGameFlag = 0;
        int nGameStatusFlag = 0;
        char cNewGameFlag = '\n';

        //*  Main Code
        srand(time(NULL));

        displayInstructions();
        startGame (nDungeonCrawlBoardArray,nDungeonCrawlPlayerArray,nTotalNumberofMonsters,nTotalNumberofTraps,nTotalNumberofPlayers,nStartGameFlag);
        displayBoard(nDungeonCrawlBoardArray);

        for (;;)
        {
            takeTurns(nDungeonCrawlBoardArray,nDungeonCrawlPlayerArray,nTotalNumberofPlayers,nGameStatusFlag);
            displayBoard(nDungeonCrawlBoardArray);

            if (nGameStatusFlag != 0)
            {
                if (nGameStatusFlag == 1)
                {
                    cout << endl << endl << "You have WON the game! You found the exit!" << endl;
                }
                else if (nGameStatusFlag == 50)
                {
                    cout << endl << endl << "You have LOST the game!  You wandered into a monster." << endl;
                }
                else if (nGameStatusFlag == 51)
                {
                    cout << endl << endl << "You have LOST the game!  A monster wandered into you." << endl;
                }

                else if (nGameStatusFlag == 75)
                {
                    cout << endl << endl << "You have LOST the game!  A trap got you." << endl;
                }
                cout << endl << "Would you like to play again? (y) or (n)? ";
                cin >> cNewGameFlag;
                break;
            }
        }

        if (cNewGameFlag == 'n' || cNewGameFlag == 'N')
        {
            cout << endl << "Okay.  Thanks for playing.  Bye Bye..." << endl << endl;
                break;
        }
        else
        {
            cNewGameFlag = '\n';
            nStartGameFlag = 0;
            system ("CLS");
        }
    }

	//*  Program End
	//   - wait until user is ready before terminating program
	//   - to allow the user to see the program results

	system("PAUSE");
	return 0;
}

//********************************
//
//  Functions Begin Here
//
//********************************

//*  Function #1 - Display Instructions
//

void displayInstructions (void)
{
    //*  Variable Declaration

    //*  Main Code

    cout << "Instructions: " << endl;
    cout << "This game will create a dungeon game board, in which the player (P)" << endl;
    cout << "will have to find the exit (X), while avoiding monsters (M) and traps (T)." << endl;
    cout << endl;

    return;
}

//*  Function #2 - Start Game
//
void startGame (int nBoardArray[10][10], int nPlayerArray[30][3],int &nTotalMonsters, int &nTotalTraps, int &nTotalPlayers, int &nStartFlag)
{
    //*  Variable Declaration
    int i = 0;
    int j = 0;
    int nRow = 0;
    int nColumn = 0;
    int nDuplicateFlag = 0;

    //*  Main Code
    if (nStartFlag == 1)
    {
        return;
    }

    // Clear the boards
    initializeBoard(nBoardArray);
    initializePlayers(nPlayerArray);

    // Ask the player for some info
    cout << endl;
    cout << "# of (M)onsters (no more than 15, please): ";
    cin >> nTotalMonsters;
    cout << "# of (T)raps (no more than 15, please): ";
    cin >> nTotalTraps;
    cout << endl;
    cout << "Thanks, now to begin the game...." << endl << endl;
    system("PAUSE");
    cout << endl;

    nTotalPlayers = nTotalMonsters + nTotalTraps + 2;
    cout << endl;

    // Determine initial positions for each Player
    for (i=0;i<nTotalPlayers;i++)
    {
            for (;;)
            {
                nDuplicateFlag = 0;

                if (i == 0)
                {
                    nPlayerArray[i][0] = 1;
                }
                else if (i == 1)
                {
                    nPlayerArray[i][0] = 2;
                }
                else if (i > 1 && i < nTotalMonsters+2)
                {
                    nPlayerArray[i][0] = 50;
                }
                else if (i >= nTotalMonsters+2 && i < nTotalPlayers)
                {
                    nPlayerArray[i][0] = 75;
                }
                if (i == 0)
                {
                    nPlayerArray[i][1] = 9;
                    nPlayerArray[i][2] = 9;
                }
                else if (i == 1)
                {
                    nPlayerArray[i][1] = 0;
                    nPlayerArray[i][2] = 0;
                }
                else if (i > 1)
                {
                    nRow = rand()%10;
                    nColumn = rand()%10;
                    nPlayerArray[i][1] = nRow;
                    nPlayerArray[i][2] = nColumn;
                }

                for (j=0;j<i;j++)
                {
                    if(nPlayerArray[i][1] == nPlayerArray[j][1] && nPlayerArray[i][2] == nPlayerArray[j][2])
                    {
                        nDuplicateFlag = 1;
                    }
                }

                if (nDuplicateFlag == 0)
                {
                  break;
                }
            }
    }

    // Set those positions on the board
    for (i=0;i<nTotalPlayers;i++)
    {
        nBoardArray[nPlayerArray[i][1]][nPlayerArray[i][2]] = nPlayerArray[i][0];
    }

    nStartFlag = 1;
    return;
}

//*  Function #3a - Initializing - Board
//
void initializeBoard (int nBoardArray[10][10])
{

    //*  Variable Declaration
    int i;
    int j;

    //*  Main Code
    for (i=0; i<10 ;i++)
    {
        for (j=0; j<10; j++)
        {
            nBoardArray[i][j] = 0;
        }
    }

    return;

}

//*  Function #3b - Initializing - Players
//
void initializePlayers(int nPlayerArray[30][3])
{

    //*  Variable Declaration
    int i;
    int j;

    //*  Main Code
    for (i=0; i<30 ;i++)
    {
        for (j=0; j<3; j++)
        {
            nPlayerArray[i][j] = 0;
        }
    }

    return;

}

//*  Function #4 - Printing The Board
//

void displayBoard (int nBoardArray[10][10])
{
    //*  Variable Declaration
    int i;
    int j;

    //*  Main Code
    system("CLS");
    cout << "    " << "DUNGEON CRAWL" << endl << endl;

    for (i=0; i<10; i++)
    {
        cout << "     ";
        for (j=0; j<10; j++)
        {
            if (nBoardArray[i][j] == 0)
            {
                cout << ".";
            }
            else if (nBoardArray[i][j] == 1)
            {
                cout << "X";
            }
            else if (nBoardArray[i][j] == 2)
            {
                cout << "P";
            }
            else if (nBoardArray[i][j] == 50)
            {
                cout << "M";
            }
            else if (nBoardArray[i][j] == 75)
            {
                cout << "T";
            }
        }
        cout << endl;
    }
    cout << endl;

    return;

}

//*  Function #5 - Take Turns
//

void takeTurns (int nBoardArray[10][10],int nPlayerArray[30][3],int &nTotalPlayers, int &nGameFlag)
{

    //*  Variable Declaration
    int i;
    int nPlayerBadHorizMoveFlag = 0;
    int nPlayerBadVertMoveFlag = 0;
    int nPlayerMoveVert = 0;
    int nPlayerMoveHoriz = 0;
    int nMonsterMove = 0;
    int nMonsterMoveVert = 0;
    int nMonsterMoveHoriz = 0;
    int nMonsterBadMoveFlag = 0;
    int nMonsterBadHorizMoveFlag = 0;
    int nMonsterBadVertMoveFlag = 0;
    int nMonsterMoveLoopCount = 0;

    char cPlayerMove = '\n';

    //*  Main Code

    // Player makes a move...
    for(;;)
    {
        for (;;)
        {
            cout << "Player, please make a move: (u)p, (d)own, (l)eft, (r)ight? ";
            cin >> cPlayerMove;

            if (cPlayerMove == 'u')
            {
                nPlayerMoveHoriz = 0;
                nPlayerMoveVert = -1;
                break;
            }
            else if (cPlayerMove == 'd')
            {
                nPlayerMoveHoriz = 0;
                nPlayerMoveVert = 1;
                break;
            }
            else if (cPlayerMove == 'l')
            {
                nPlayerMoveHoriz = -1;
                nPlayerMoveVert = 0;
                break;
            }
            else if (cPlayerMove == 'r')
            {
                nPlayerMoveHoriz = 1;
                nPlayerMoveVert = 0;
                break;
            }
            cout << endl << "That is not a valid option.  Try again." << endl;
        }

        //...and then the move is checked for quality...

        if(nPlayerArray[1][2]+nPlayerMoveHoriz < 0 || nPlayerArray[1][2]+nPlayerMoveHoriz >9)
        {
            nPlayerBadHorizMoveFlag = 1;
        }
        else if(nPlayerArray[1][1]+nPlayerMoveVert < 0 || nPlayerArray[1][1]+nPlayerMoveVert >9)
        {
            nPlayerBadVertMoveFlag = 1;
        }

        if (nPlayerBadHorizMoveFlag == 1 || nPlayerBadVertMoveFlag == 1)
        {
            cout << endl << "You can't move that way!" << endl;
            nPlayerBadHorizMoveFlag = 0;
            nPlayerBadVertMoveFlag = 0;
        }
        else
        {
            break;
        }
    }

    //...and we need to see if the player can move, won, or lost by monster or trap...
    if(nBoardArray[nPlayerArray[1][1]+nPlayerMoveVert][nPlayerArray[1][2]+nPlayerMoveHoriz] == 0)
    {
        nBoardArray[nPlayerArray[1][1]+nPlayerMoveVert][nPlayerArray[1][2]+nPlayerMoveHoriz] = 2;
        nBoardArray[nPlayerArray[1][1]][nPlayerArray[1][2]] = 0;
        nPlayerArray[1][1] = nPlayerArray[1][1]+nPlayerMoveVert;
        nPlayerArray[1][2] = nPlayerArray[1][2]+nPlayerMoveHoriz;

    }
    else if (nBoardArray[nPlayerArray[1][1]+nPlayerMoveVert][nPlayerArray[1][2]+nPlayerMoveHoriz] == 1)
    {
        nBoardArray[nPlayerArray[1][1]+nPlayerMoveVert][nPlayerArray[1][2]+nPlayerMoveHoriz] = 2;
        nBoardArray[nPlayerArray[1][1]][nPlayerArray[1][2]] = 0;
        nPlayerArray[1][1] = nPlayerArray[1][1]+nPlayerMoveVert;
        nPlayerArray[1][2] = nPlayerArray[1][2]+nPlayerMoveHoriz;
        nGameFlag = 1;
    }
    else if (nBoardArray[nPlayerArray[1][1]+nPlayerMoveVert][nPlayerArray[1][2]+nPlayerMoveHoriz] == 50)
    {
        nBoardArray[nPlayerArray[1][1]+nPlayerMoveVert][nPlayerArray[1][2]+nPlayerMoveHoriz] = 2;
        nBoardArray[nPlayerArray[1][1]][nPlayerArray[1][2]] = 0;
        nPlayerArray[1][1] = nPlayerArray[1][1]+nPlayerMoveVert;
        nPlayerArray[1][2] = nPlayerArray[1][2]+nPlayerMoveHoriz;
        nGameFlag = 50;
    }
    else if (nBoardArray[nPlayerArray[1][1]+nPlayerMoveVert][nPlayerArray[1][2]+nPlayerMoveHoriz] == 75)
    {
        nBoardArray[nPlayerArray[1][1]+nPlayerMoveVert][nPlayerArray[1][2]+nPlayerMoveHoriz] = 2;
        nBoardArray[nPlayerArray[1][1]][nPlayerArray[1][2]] = 0;
        nPlayerArray[1][1] = nPlayerArray[1][1]+nPlayerMoveVert;
        nPlayerArray[1][2] = nPlayerArray[1][2]+nPlayerMoveHoriz;
        nGameFlag = 75;
    }

    // Now it is the Monster's turn to makes a move...

    if (nGameFlag == 0)
    {
        for (i=0;i<nTotalPlayers;i++)
        {
            if (nPlayerArray[i][0] == 50)
            {
                for (;;)
                {
                    nMonsterMoveLoopCount++;
                    if (nMonsterMoveLoopCount > 100)
                    {
                        break;
                    }

                    nMonsterMove = rand()%4+1;

                    if (nMonsterMove == 1)
                    {
                        nMonsterMoveHoriz = 0;
                        nMonsterMoveVert = -1;
                    }
                    else if (nMonsterMove == 2)
                    {
                        nMonsterMoveHoriz = 0;
                        nMonsterMoveVert = 1;
                    }
                    else if (nMonsterMove == 3)
                    {
                        nMonsterMoveHoriz = -1;
                        nMonsterMoveVert = 0;
                    }
                    else if (nMonsterMove == 4)
                    {
                        nMonsterMoveHoriz = 1;
                        nMonsterMoveVert = 0;
                    }

                    //...and then the move is checked for quality...

                    if(nPlayerArray[i][2]+nMonsterMoveHoriz < 0 || nPlayerArray[i][2]+nMonsterMoveHoriz >9)
                    {
                        nMonsterBadHorizMoveFlag = 1;
                    }
                    else if(nPlayerArray[i][1]+nMonsterMoveVert < 0 || nPlayerArray[i][1]+nMonsterMoveVert >9)
                    {
                        nMonsterBadVertMoveFlag = 1;
                    }
                    else if (nBoardArray[nPlayerArray[i][1]+nMonsterMoveVert][nPlayerArray[i][2]+nMonsterMoveHoriz] == 1)
                    {
                        nMonsterBadMoveFlag = 1;
                    }
                    else if (nBoardArray[nPlayerArray[i][1]+nMonsterMoveVert][nPlayerArray[i][2]+nMonsterMoveHoriz] == 50)
                    {
                        nMonsterBadMoveFlag = 1;
                    }
                    else if (nBoardArray[nPlayerArray[i][1]+nMonsterMoveVert][nPlayerArray[i][2]+nMonsterMoveHoriz] == 75)
                    {
                        nMonsterBadMoveFlag = 1;
                    }

                    if (nMonsterBadHorizMoveFlag == 1 || nMonsterBadVertMoveFlag == 1 || nMonsterBadMoveFlag == 1)
                    {
                        nMonsterBadHorizMoveFlag = 0;
                        nMonsterBadVertMoveFlag = 0;
                        nMonsterBadMoveFlag = 0;
                    }
                    else
                    {
                         break;
                    }
                }

                //...and we need to see if the Monster can move, or found the player...
                if(nBoardArray[nPlayerArray[i][1]+nMonsterMoveVert][nPlayerArray[i][2]+nMonsterMoveHoriz] == 0)
                {
                    nBoardArray[nPlayerArray[i][1]+nMonsterMoveVert][nPlayerArray[i][2]+nMonsterMoveHoriz] = 50;
                    nBoardArray[nPlayerArray[i][1]][nPlayerArray[i][2]] = 0;
                    nPlayerArray[i][1] = nPlayerArray[i][1]+nMonsterMoveVert;
                    nPlayerArray[i][2] = nPlayerArray[i][2]+nMonsterMoveHoriz;
                }
                else if (nBoardArray[nPlayerArray[i][1]+nMonsterMoveVert][nPlayerArray[i][2]+nMonsterMoveHoriz] == 2)
                {
                    nBoardArray[nPlayerArray[i][1]+nMonsterMoveVert][nPlayerArray[i][2]+nMonsterMoveHoriz] = 50;
                    nBoardArray[nPlayerArray[i][1]][nPlayerArray[i][2]] = 0;
                    nPlayerArray[i][1] = nPlayerArray[i][1]+nMonsterMoveVert;
                    nPlayerArray[i][2] = nPlayerArray[i][2]+nMonsterMoveHoriz;
                    nGameFlag = 51;
                }
            }
        }
    }

    return;
}


