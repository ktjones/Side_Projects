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
void printBoard (int nboardArray[4][4]);
void takeTurn (int nboardArray[4][4], int &nStartGameFlag, int &nEndGameFlag, int &nGameWonFlag, char &cTurnFlag, char &cPlayerSign, char &cComputerSign, char &cNumberofPlayersCount);
void keepingScore(int nboardArray[4][4], int &nGameWonFlag);
void clearTheBoard (int nboardArray[4][4]);
void computersMove (int nboardArray[4][4], char &cTurnFlag);
int moveChecker(int nboardArray[4][4], int &nRowCheck, int &nColumnCheck);

//********************************
//
//  Main Program Section
//
//********************************

int main(int nNumberofArgs, char* pszArgs[])
{
	//*  Variable Declaration

    int nticTacToeArray[4][4] = {{0,1,2,3},{1,0,0,0},{2,0,0,0},{3,0,0,0}};
    int nStartGame = 0;
    int nGameWon = 0;
    int nEndGame = 0;
    char cPlayer = '\n';
    char cComputer = '\n';
    char cTurn = '\n';
    char cNumberofPlayers = '\n';

   	//*  Main Code

    //* Provide Instructions
    displayInstructions();

    //* Play the Game

    for (;;)
    {

        printBoard(nticTacToeArray);
        keepingScore(nticTacToeArray, nGameWon);
        takeTurn(nticTacToeArray, nStartGame, nEndGame, nGameWon, cTurn, cPlayer, cComputer,cNumberofPlayers);

        if (nEndGame == 1)
        {
            cout << endl << endl << "Bye bye!  Thanks for playing!" << endl << endl;

            break;
        }
    }

   	//*  Program End
	//   - wait until user is ready before terminating program
	//   - to allow the user to see the program results

    cout << endl;
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

    cout << "This program will be playing Tic Tac Toe." << endl;
    cout << endl;

    return;
}

//*  Function #2 - Print Board
//

void printBoard (int nboardArray[4][4])
{
    //*  Variable Declaration
    int i = 0;
    int j = 0;


    //*  Main Code
    system("CLS");
    cout << endl;

    for (i=0; i<4; i++)
    {
        for (j=0;j<4;j++)
        {
            if (i == 0)
            {
                cout << "| " << j << " |";
            }
            else if (j == 0)
            {
                cout << "| " << i << " |";
            }
            else if (nboardArray[i][j] == 1)
            {
                cout << "| x |";
            }
            else if (nboardArray[i][j] == -1)
            {
                cout << "| o |";
            }
            else
            {
                cout << "|   |";
            }
        }
        cout << endl;
        cout << "---------------------";
        cout << endl;

    }
    return;
}

//*  Function #3 - Taking Turns
//

void takeTurn (int nboardArray[4][4], int &nStartGameFlag, int &nEndGameFlag, int &nGameWonFlag, char &cTurnFlag, char &cPlayerSign, char &cComputerSign, char &cNumberofPlayersCount)
{
    //*  Variable Declaration
    int nRow = 0;
    int nColumn = 0;
    int nMoveCheckerFlag = 0;
    char cNewGameFlag = '\n';


    //*  Main Code

    //* Check to see if a game was just ended
    if (nGameWonFlag == 1 || nGameWonFlag == 100)
    {
            cout << endl << "Would you like to play again?" << endl << endl;
            cout << "Please enter (y) or (n): ";
            cin >> cNewGameFlag;

            if (cNewGameFlag == 'y')
            {
                nStartGameFlag = 0;
                nEndGameFlag = 0;
                nGameWonFlag = 0;
                clearTheBoard(nboardArray);
                printBoard(nboardArray);
            }
            else if (cNewGameFlag == 'n')
            {
                nEndGameFlag = 1;
            }
    }

    //* Begin a New Game...
    if (nStartGameFlag == 0 && nEndGameFlag != 1)
    {
        cout << endl << "Will this be a (1) or (2) Player Game? " << endl << endl;
        cout << "Please enter (1), (2), or (q) to end the game: ";
        cin >> cNumberofPlayersCount;
    }

    //* Check to see if the player is a quitter!
    if (cNumberofPlayersCount == 'q' && nEndGameFlag != 1)
    {
        nEndGameFlag = 1;
    }
    //* Start a 1 Player Game.
    else if (cNumberofPlayersCount == '1' && nEndGameFlag != 1 && nStartGameFlag == 0)
    {
        cout << endl << "Who will the Player be? " << endl << endl;
        cout << "Please enter (x) or (o):";
        cin >> cPlayerSign;
        nStartGameFlag = 1;

        if (cPlayerSign == 'x')
        {
            cComputerSign = 'o';
            cout << endl << "Then the computer will be (" << cComputerSign << ")." << endl;
        }
        else if (cPlayerSign == 'o')
        {
            cComputerSign = 'x';
            cout << endl << "Then the computer will be (" << cComputerSign << ")." << endl;
        }

        cout << endl << "Which player will go first?" << endl << endl;
        cout << "Please enter (x) or (o): ";
        cin >> cTurnFlag;
    }
    //* Continue Taking Turns in a 1 Player Game.
    else if (cNumberofPlayersCount == '1' && nEndGameFlag != 1 && nStartGameFlag == 1)
    {
        if (cTurnFlag == cPlayerSign)
        {
            for (;;)
            {
                cout << endl << "Player '" << cTurnFlag << "'?" << endl << endl;
                cout << "Enter the row.   (1,2, or 3): ";
                cin >> nRow;
                cout << "Enter the column (1,2, or 3): ";
                cin >> nColumn;
                nMoveCheckerFlag = moveChecker(nboardArray,nRow,nColumn);
                if (nMoveCheckerFlag == 1)
                {
                    break;
                }
                else if (nMoveCheckerFlag == 0)
                {
                    cout << endl << endl << "That move is illegal.  Try again." << endl << endl;
                }
            }

            if (cTurnFlag == 'x')
            {
                nboardArray[nRow][nColumn] = 1;
                cTurnFlag = 'o';
            }
            else if (cTurnFlag == 'o')
            {
                nboardArray[nRow][nColumn] = -1;
                cTurnFlag = 'x';
            }
        }
        else if (cTurnFlag == cComputerSign)
        {
            computersMove(nboardArray, cTurnFlag);
        }
    }
    //* Start a 2 Player Game.
    else if (cNumberofPlayersCount == '2' && nEndGameFlag != 1 && nStartGameFlag == 0)
    {
        cout << endl << "Which player will go first?" << endl << endl;
        cout << "Please enter (x) or (o): ";
        cin >> cTurnFlag;
        nStartGameFlag = 1;
    }
    //* Continue Taking Turns in a 2 Player Game.
    else if (cNumberofPlayersCount == '2' && nEndGameFlag != 1 && nStartGameFlag == 1)
    {
        for (;;)
        {
            cout << endl << "Player '" << cTurnFlag << "'?" << endl << endl;
            cout << "Enter the row.   (1,2, or 3): ";
            cin >> nRow;
            cout << "Enter the column (1,2, or 3): ";
            cin >> nColumn;

            nMoveCheckerFlag = moveChecker(nboardArray,nRow,nColumn);
            if (nMoveCheckerFlag == 1)
            {
                break;
            }
            else if (nMoveCheckerFlag == 0)
            {
                cout << endl << endl << "That move is illegal.  Try again" << endl << endl;
            }
        }

        if (cTurnFlag == 'x')
        {
            nboardArray[nRow][nColumn] = 1;
            cTurnFlag = 'o';
        }
            else if (cTurnFlag == 'o')
        {
            nboardArray[nRow][nColumn] = -1;
            cTurnFlag = 'x';
        }
    }

    return;
}

//*  Function #4 - Keeping Score
//

void keepingScore (int nboardArray[4][4], int &nGameWonFlag)
{
    //*  Variable Declaration
    int nWinnerFlag = 0;
    int nRow = 0;
    int nColumn = 0;
    int nDiag1 = 0;
    int nDiag2 = 0;
    int i = 0;
    int j = 0;
    int nCatsGameCounter = 0;

    //*  Main Code

    //* Check Each Row for a WIN
    for (i=1; i<4; i++)
    {
        for (j=1; j<4; j++)
        {
            nRow = nRow + nboardArray[i][j];
        }

        if (nRow == 3)
        {
            nWinnerFlag = 1;
        }
        else if (nRow == -3)
        {
            nWinnerFlag = -1;
        }

        nRow = 0;
    }

    //* Check Each Column for a WIN
    for (i=1; i<4; i++)
    {
        for (j=1; j<4; j++)
        {
            nColumn = nColumn + nboardArray[j][i];
        }

        if (nColumn == 3)
        {
            nWinnerFlag = 1;
        }
        else if (nColumn == -3)
        {
            nWinnerFlag = -1;
        }
        nColumn = 0;
    }

    //* Check Each Diagonal for a WIN
    nDiag1 = nboardArray[1][1] + nboardArray[2][2] + nboardArray[3][3];
    nDiag2 = nboardArray[1][3] + nboardArray[2][2] + nboardArray[3][1];

    if (nDiag1 == 3 || nDiag2 == 3)
    {
        nWinnerFlag = 1;
    }
    else if (nDiag1 == -3 || nDiag2 == -3)
    {
        nWinnerFlag = -1;
    }

    //* Declare a winner if there is one
    if (nWinnerFlag == 1)
    {
        cout << endl << endl << "Player (x) has won the game." << endl << endl;
        nGameWonFlag = 1;
    }
    else if (nWinnerFlag == -1)
    {
        cout << endl << endl << "Player (o) has won the game." << endl << endl;
        nGameWonFlag = 1;
    }

    //* Check for a Cats Game


        for (i=1; i<4; i++)
        {
            for (j=1; j<4; j++)
            {
                if (nboardArray[i][j] != 0)
                {
                    nCatsGameCounter = nCatsGameCounter + 1;
                }
            }
        }

    if (nGameWonFlag != 1 && nCatsGameCounter == 9)
    {
        cout << endl << endl << "This was a CATS game!" << endl << endl;
        nGameWonFlag = 100;
    }

    return;
}

//*  Function #6 - Reset the Board
//
void clearTheBoard (int nboardArray[4][4])
{
    //*  Variable Declaration
    int i = 0;
    int j = 0;

    //*  Main Code

    for (i=1; i<4; i++)
    {
        for (j=1; j<4; j++)
        {
            nboardArray[i][j] = 0;
        }
    }

    return;

}

//*  Function #7 - Computers Move
//
void computersMove (int nboardArray[4][4], char &cTurnFlag)
{
    //*  Variable Declaration
    int nRowRandom = 0;
    int nColumnRandom = 0;
    int nMoveCheckerFlag = 0;

    //*  Main Code
    srand(time(NULL));

    //* Generate the random numbers
    for (;;)
    {
        nRowRandom = rand()%3 + 1;
        nColumnRandom = rand()%3 +1;
        cout << endl << endl << nRowRandom << endl;
        cout << nColumnRandom << endl << endl;

    //* Check to see if it's a valid move
        nMoveCheckerFlag = moveChecker(nboardArray,nRowRandom,nColumnRandom);

        if (nMoveCheckerFlag == 1)
        {
            break;
        }
    }

    if (cTurnFlag == 'x')
    {
        nboardArray[nRowRandom][nColumnRandom] = 1;
        cTurnFlag = 'o';
    }
    else if (cTurnFlag == 'o')
    {
        nboardArray[nRowRandom][nColumnRandom] = -1;
        cTurnFlag = 'x';
    }

    return;
}


//*  Function #8 - Move check
//
int moveChecker(int nboardArray[4][4], int &nRowCheck, int &nColumnCheck)
{
    //*  Variable Declaration
    int nCheckMoveFlag = 0;

    //*  Main Code
    if (nRowCheck < 0 || nRowCheck > 3)
    {
        //* Checking to see if the Row entry is lower than 1 or higher than 3
        nCheckMoveFlag = 0;
        return nCheckMoveFlag;
    }
    else if (nColumnCheck < 0 || nColumnCheck > 3)
    {
        //* Checking to see if the Column entry is lower than 1 or higher than 3
        nCheckMoveFlag = 0;
        return nCheckMoveFlag;
    }
    else if (nboardArray[nRowCheck][nColumnCheck] == 1)
    {
        //* Unsuccessful move
        nCheckMoveFlag = 0;
        return nCheckMoveFlag;
    }
    else if (nboardArray[nRowCheck][nColumnCheck] == 0)
    {
        //* Successful move
        nCheckMoveFlag = 1;
        return nCheckMoveFlag;
    }
}

