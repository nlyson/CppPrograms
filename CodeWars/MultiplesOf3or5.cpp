/******************************************************************************
MultiplesOf3or5.cpp

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in. Additionally, if the number is negative, return 0 (for languages that do have them).

Note: If the number is a multiple of both 3 and 5, only count it once.

Courtesy of projecteuler.net (Problem 1)
*******************************************************************************/

int MultiplesOf3or5(int number) 
{
   int sum =0;
   
   // Add up all multiples of 3
   for(int i=3; i<number; i+=3)
   {
      sum += i;  
   }
   
   // Add up all multiples of 5 that are not a multiple of 3
   for(int i=5; i<number; i+=5)
   {
      if(i % 3 != 0)
      {
         sum += i;  
      }
   }

   return sum;
}
