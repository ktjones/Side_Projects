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

void increase (void* data, int psize);

//********************************
//
//  Main Program Section
//
//********************************

int main(int nNumberofArgs, char* pszArgs[])
{
	//*  Variable Declaration


	//*  Main Code

    char a = 'x';
    int b = 1602;
    increase (&a,sizeof(a));
    increase (&b,sizeof(b));
    cout << a << ", " << b << endl;
    return 0;

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

void increase (void* data, int psize)
{
  if (psize == sizeof(char))
    {
        char* pchar;
        pchar=(char*)data;
        ++(*pchar);
    }
  else if (psize == sizeof(int) )
    {
        int* pint;
        pint=(int*)data;
        ++(*pint);
    }
}



