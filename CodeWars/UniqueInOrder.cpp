/******************************************************************************

Nathan Lyson
UniqueInOrder.cpp

Implement the function unique_in_order which takes as argument a sequence and returns a list of items 
without any elements with the same value next to each other and preserving the original order of elements.

For example:

uniqueInOrder("AAAABBBCCDAABBB") == {'A', 'B', 'C', 'D', 'A', 'B'}
uniqueInOrder("ABBCcAD")         == {'A', 'B', 'C', 'c', 'A', 'D'}
uniqueInOrder([1,2,2,3,3])       == {1,2,3}

*******************************************************************************/

#include <string>
#include <vector>
#include <iostream>


template <typename T> 
std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
    //your code here
    
    T current = iterable[0];
    
    std::vector<T> result{iterable[0]};
    
    
    // Don't add another element until we find one that is different
    // Rinse and repeat
    for(int i=1; i<(int)iterable.size(); i++)
    {
        if(iterable[i] != current)
        {
            result.push_back(iterable[i]);
            current = iterable[i];
        }
    }
    
   return result;
  
}

std::vector<char> uniqueInOrder(const std::string& iterable){

  // If it's not empty, convert this string to a vector<char> and let the above method
  // do the work.
  if( iterable != "" )
    return uniqueInOrder( std::vector<char>(iterable.begin(), iterable.end()));
  
  return {};
}

template <typename T>
void printVector(std::vector<T> v)
{
    for(T n : v)
        std::cout << n << " ";
        
    std::cout << std::endl;
}

int main()
{
    // Test cases
    
    printVector(uniqueInOrder( std::vector<int>{1, 1, 2, 3}));
    printVector(uniqueInOrder( std::vector<char>{'A', 'A', 'B', 'C', 'C', 'C', 'A', 'A'}));
    
    printVector(uniqueInOrder("hello"));
    printVector(uniqueInOrder(""));
   
    
    
    return 0;
}
