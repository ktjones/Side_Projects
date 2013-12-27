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

    int pancakeArray[10];
    int nMax = 0;
    int nNewMax = 0;
    int nIndex = 0;
    int i = 0;
    int j = 0;

 	//*  Main Code

    displayInstructions();

    //* Initialize the Array

    for (i=0;i<10;i++)
    {
        pancakeArray[i] = 0;
    }

    //* Input the numbers
    for (i=0;i<10;i++)
    {
        cout << "Person #" << i << ": ";
        cin >> pancakeArray[i];
    }

    //* Figure out which one is the highest - First Pass
    for (i=0;i<10;i++)
    {
        if (pancakeArray[i] > nMax)
        {
            nMax = pancakeArray[i];
            nIndex = i;
        }
    }

    cout << "Person #" << nIndex << " ate " << pancakeArray[nIndex] << " pancakes." << endl;

    //* Figure out the rest of the order - Remaining Passes
    for (i=0; i<9; i++)
    {
        nNewMax = 0;
        for (j=0; j<10; j++)
        {
            if (pancakeArray[j] < nMax)
            {
//                cout << "Pancake array " << j << ", " << pancakeArray[j] << ", is less than " << nMax << endl;
                if(pancakeArray[j] > nNewMax)
                {
                    nNewMax = pancakeArray[j];
                    nIndex = j;
//                    cout << "nNewMax = " << nNewMax << " ; inIndex = " << nIndex << endl;
                }
            }
        }
        nMax = nNewMax;
//        cout << nMax << endl;

        cout << "Person #" << nIndex  << " ate " << pancakeArray[nIndex] << " pancakes." << endl;
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

    cout << "This program will ask you to enter " << endl;
    cout << "the number of pancakes eaten by 10 " << endl;
    cout << "different people.  The program will then" << endl;
    cout << "Which person ate the most pancakes." << endl;
    cout << endl;

    return;
}






