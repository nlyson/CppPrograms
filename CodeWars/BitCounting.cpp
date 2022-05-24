/******************************************************************************
BitCounting.cpp
Write a function that takes an integer as input, and returns the number of bits that are equal to one in the binary representation of that number. 
You can guarantee that input is non-negative.

Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this case
*******************************************************************************/

#include <iostream>
#include <vector>

unsigned int countBits(unsigned long long n){
  
   // Keep dividing by 2 and keep track of the times the remainder is 1
   // Example:  23 = 1 0111
   //  23 / 2 = 11 r 1
   //  11 / 2 = 5 r 1
   //  5 / 2 = 2 r 1
   //  2 / 2 = 1 r 0
   //  1 / 2 = 0 r 1            
   unsigned int count = 0;
   while(n != 0)
   {
      count += n % 2;
      n /= 2;
   }
   return count;
  
}
