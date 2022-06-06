/******************************************************************************
MaxSubarraySum.cpp
Nathan Lyson

The maximum sum subarray problem consists in finding the maximum sum of a contiguous subsequence in an array or list of integers:

maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4});
//should be 6: {4, -1, 2, 1}
Easy case is when the list is made up of only positive numbers and the maximum sum is the sum of the whole array. If the list is made up of only negative numbers, return 0 instead.

Empty list is considered to have zero greatest sum. Note that the empty list or array is also a valid sublist/subarray.
*******************************************************************************/

#include <vector>

int maxSequence(const std::vector<int>& arr){

   // 0 if empty vector
   if(!arr.size()) {  return 0;  }
   
   int maxSum = 0;  // 0 is the minimum max sum per instructions
  
   // Use nested loop to iterate over all possible subarrays
   for(int i=0; i<arr.size(); i++)
   {
      int sum = arr[i];
      for(int j=i+1; j<arr.size(); j++)
      {
         sum += arr[j];
         if(sum > maxSum)
         {
            maxSum = sum;  
         }
      }  
   }
   
   return maxSum;
}
