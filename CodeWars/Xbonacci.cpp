/******************************************************************************

Xbonacci.cpp
Nathan Lyson

If you have completed the Tribonacci sequence kata, you would know by now that mister Fibonacci has at least a bigger brother. 
If not, give it a quick look to get how things work.

Well, time to expand the family a little more: think of a Quadribonacci starting with a signature of 4 elements 
and each following element is the sum of the 4 previous, a Pentabonacci 
(well Cinquebonacci would probably sound a bit more italian, but it would also sound really awful) 
with a signature of 5 elements and each following element is the sum of the 5 previous, and so on.

Well, guess what? You have to build a Xbonacci function that takes a signature of X elements - and remember 
each next element is the sum of the last X elements - and returns the first n elements of the so seeded sequence.

xbonacci {1,1,1,1} 10 = {1,1,1,1,4,7,13,25,49,94}
xbonacci {0,0,0,0,1} 10 = {0,0,0,0,1,1,2,4,8,16}
xbonacci {1,0,0,0,0,0,1} 10 = {1,0,0,0,0,0,1,2,3,6}
xbonacci {1,1} produces the Fibonacci sequence

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

std::vector<int> xbonacci(std::vector<int> signature, int n)
{
    int size = signature.size();

    // If n is smaller than our intial vector, resize it and we are done!
    if(size > n)
    {
        signature.resize(n);
        return signature;
    }
    
    vector<int> result;
    
    // Copy over our inital vector into our result
    for(int i=0; i<size; i++)
        result.push_back(signature[i]);
        
    // All of the remaining elements will be the sum of the previous 'size' elements.
    for(int i=size; i<n; i++)
    {
        // Sum up previous 'sum' elements
        int sum = 0;
        for(int j=i-size; j<i; j++)
            sum += result[j];
            
        result.push_back(sum);
    }
    
    return result;
}


void printVector(vector<int> v)
{
    for(int n : v)
        cout << n << " ";
        
    cout << endl;
}

int main()
{
    // Test cases
    printVector( xbonacci({1,1,1,1}, 10) );
    printVector( xbonacci({0,0,0,0,1}, 10) );
    

    return 0;
}
