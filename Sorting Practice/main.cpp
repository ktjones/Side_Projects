///*******************************
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
#include <math.h>
using namespace std;

//********************************
//
//  Function Declaration Section
//
//********************************

void displayInstructions (void);


//********************************
//
//  Main Program Section
//
//********************************

int main(int nNumberofArgs, char* pszArgs[])
{
	//*  Variable Declaration

    int nGuess = 0;
    int nGuessPrev = 0;
    int nGuessDelta = 0;
    int nGuessCounter = 0;
    char cResponse;

  	//*  Main Code

    displayInstructions();

    //* Set the initial guess

    nGuessPrev = 100;
    nGuess = 50;

    //* Start the iterations.
    for (;;)
    {

        cout << "The Number is " << nGuess << endl;
        cout << "Am I (H)igh, (L)ow, or (C)orrect? ";
        cin >> cResponse;
        cout << endl;

        nGuessCounter++;

        if (cResponse == 'H'|| cResponse == 'h')
        {
            cout << "High, huh? Ok. I will try again." << endl << endl;
            nGuessDelta = abs(nGuessPrev - nGuess);
            nGuessPrev = nGuess;
            nGuess = nGuess - ((nGuessDelta+1)/2);
        }
        else if (cResponse == 'L' || cResponse == 'l')
        {
            cout << "Low, huh? Ok.  I will try again." << endl << endl;
            nGuessDelta = abs(nGuessPrev - nGuess);
            nGuessPrev = nGuess;
            nGuess = nGuess + ((nGuessDelta+1)/2);
        }
        else if (cResponse == 'C' || cResponse == 'c')
        {
            cout << "Woohoo!!! I am the man...er...computer!!!" << endl;
            cout << "And I did it in " << nGuessCounter << " tries!" << endl <<endl;
            break;
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

    cout << "You come up with a number from 1 to 100." << endl;
    cout << "The computer will try and guess the number." << endl;
    cout << endl;

    return;
}






