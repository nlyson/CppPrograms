/******************************************************************************

CountTheDigit.cpp
Nathan Lyson

Take an integer n (n >= 0) and a digit d (0 <= d <= 9) as an integer.

Square all numbers k (0 <= k <= n) between 0 and n.

Count the numbers of digits d used in the writing of all the k**2.

Call nb_dig (or nbDig or ...) the function taking n and d as parameters and returning this count.

Examples:
n = 10, d = 1 
the k*k are 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100
We are using the digit 1 in: 1, 16, 81, 100. The total count is then 4.

nb_dig(25, 1) returns 11 since
the k*k that contain the digit 1 are:
1, 16, 81, 100, 121, 144, 169, 196, 361, 441.
So there are 11 digits 1 for the squares of numbers between 0 and 25.
Note that 121 has twice the digit 1.

*******************************************************************************/

#include <iostream>

using namespace std;

class CountDig
{
    public:
        static int nbDig(int n, int d);
};

int CountDig::nbDig(int n, int d)
{
    int count = 0;
    
    // We need to count the first square (0*0) when d is 0.
    if(d == 0)
        ++count;
    
  
    for(int i=0; i<=n; i++)
    {
        int square = i*i;
        
        // For each square, we "peel off" the digits and see if they match d.
        // Count the number of times we find a match.
        while(square != 0)
        {
            
            if( square % 10 == d )
                ++count;
            
            square /= 10;
        }
    }
    
    return count;
}


int main()
{
    // Test cases
    cout << CountDig::nbDig(10, 1) << endl;     // 4
    cout << CountDig::nbDig(25, 1) << endl;     // 11

    return 0;
}
