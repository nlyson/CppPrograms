/******************************************************************************

Nathan Lyson
SquareInRect.cpp

Can you translate this drawing into an algorithm?

You will be given two dimensions

a positive integer length
a positive integer width
You will return a collection or a string (depending on the language; Shell bash, PowerShell, Pascal and Fortran return a string) with the size of each of the squares.

Examples in general form:
(depending on the language)

  sqInRect(5, 3) should return [3, 2, 1, 1]
  sqInRect(3, 5) should return [3, 2, 1, 1]
  
  You can see examples for your language in **"SAMPLE TESTS".**
Notes:
lng == wdth as a starting case would be an entirely different problem and the drawing is planned to be interpreted with lng != wdth. (See kata, Square into Squares. Protect trees! http://www.codewars.com/kata/54eb33e5bc1a25440d000891 for this problem).

When the initial parameters are so that lng == wdth, the solution [lng] would be the most obvious but not in the spirit of this kata so, in that case, return None/nil/null/Nothing or return {} with C++, Array() with Scala, [] with Raku.

In that case the returned structure of C will have its sz component equal to 0.

Return the string "nil" with Bash, PowerShell, Pascal and Fortran.
Beware: r must be without duplicates.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SqInRect
{
  public:
  static std::vector<int> sqInRect(int lng, int wdth)
  {
      
        // Per instructions, return empty vector if length equals width
        if(lng == wdth)
            return {};
        
        std::vector<int> result{};


        // We are going to keep taking squares out until either width or length == 1 
        // This will mean that we are left with a row of 1X1 squares
        while(lng > 1 && wdth > 1)
        {
            int smaller = std::min(lng, wdth);
            result.push_back(smaller);
            
            if(lng == smaller)
                wdth -= smaller;
            else
                lng -= smaller;
            
        }
        
        
        // This is the number of 1x1 squares we have left.  Put them in our result.
        int leftOvers = lng*wdth;
        
        for(int i=0; i<leftOvers; i++)
            result.push_back(1);
        
        return result;
     
  }
};

void printVector(vector<int> v)
{
    for(int n : v)
        cout << n << " ";
    
    cout << endl;
}

int main()
{
    // Test cases
    printVector( SqInRect::sqInRect(5, 3) );

    return 0;
}
