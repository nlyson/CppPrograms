/******************************************************************************

Nathan Lyson
SortTheOdd.cpp

You will be given an array of numbers. You have to sort the odd numbers in ascending order while leaving the even numbers at their original positions.

Examples
[7, 1]  =>  [1, 7]
[5, 8, 6, 3, 4]  =>  [3, 8, 6, 5, 4]
[9, 8, 7, 6, 5, 4, 3, 2, 1, 0]  =>  [1, 8, 3, 6, 5, 4, 7, 2, 9, 0]

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Kata
{
public:
    static std::vector<int> sortArray(std::vector<int> array)
    {
        int size = array.size();
        
      
        // I am implementing a selection sort, but I am ignoring any even elements.
        for(int i=0; i<size-1; i++)
        {
            // Continue on to next iteration if this value is even
            if(array[i] % 2 == 0)   
                continue;
            
            // Find the smallest odd integer and swap it with the odd integer at our current spot
            int smallIndex = i;
            for(int j=i+1; j<size; j++)
            {
                if(array[j] % 2 == 1 && array[j] < array[smallIndex])
                    smallIndex = j;
            }
            
            if(smallIndex != i)
            {
                int temp = array[i];
                array[i] = array[smallIndex];
                array[smallIndex] = temp;
            }
            
        }
        
        return array;
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
    std::vector<int> test1{1, 7};
    std::vector<int> test2{5, 8, 6, 3, 4};
    std::vector<int> test3{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    
    printVector( Kata::sortArray(test1) );
    printVector( Kata::sortArray(test2) );
    printVector( Kata::sortArray(test3) );
    

    return 0;
}
