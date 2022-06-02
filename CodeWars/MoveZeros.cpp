/******************************************************************************
MoveZeros.cpp
Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}
*******************************************************************************/

#include <vector>

std::vector<int> move_zeroes(const std::vector<int>& input) 
{
   std::vector<int> result;
   int numZeros = 0;
  
   // Add non-zeros to the new vector - keep track of number of 0s we come across.  Then, add that many 0s to the end.
   for(std::vector<int>::const_iterator it=input.begin(); it != input.end(); ++it)
   {
      if(*it == 0)
      {
         numZeros++;  
      }
      else
      {
         result.push_back(*it);
      }     
   }
   for(int i=0; i<numZeros; i++)
   {
      result.push_back(0);  
   }
   return result;
}
