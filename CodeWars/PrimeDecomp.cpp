/******************************************************************************
PrimeDecomp.cpp
Nathan Lyson

Given a positive number n > 1 find the prime factor decomposition of n. The result will be a string with the following form :

 "(p1**n1)(p2**n2)...(pk**nk)"
with the p(i) in increasing order and n(i) empty if n(i) is 1.

Example: n = 86240 should return "(2**5)(5)(7**2)(11)"
*******************************************************************************/

class PrimeDecomp
{
public:
    static std::string factors(int lst);
};

std::string PrimeDecomp::factors(int lst)
{ 
   int divisor = 2;
   int count = 0;
   std::string result = "";
  
   while (divisor < lst)
   {
      if (lst % divisor == 0)
      {
         lst /= divisor;
         count++;
      }
      else
      {
         if(count == 1)
         {
            result += "(" + std::to_string(divisor) + ")";
         }
         else if(count > 1)
         {
            result += "(" + std::to_string(divisor) + "**" + std::to_string(count) + ")"; 
         }
         divisor++;
         count = 0;
      }
   }
   result += "(" + std::to_string(divisor) + ")";
   return result;
}
