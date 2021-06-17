/******************************************************************************

Nathan Lyson
ZerosToTheEnd.cpp

Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


std::vector<int> move_zeroes(const std::vector<int>& input) {
    
    std::vector<int> result{};
    
    int count = 0;
    
    
    // Push all non-zero elements to end of result vector
    for(int n : input)
        if(n != 0)
            result.push_back(n);
        else
            count++;
    
    // Push the number of zeros we counted
    for(int i=0; i<count; i++)
        result.push_back(0);
        
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
    printVector( move_zeroes({1, 0, 1, 2, 0, 1, 3}) );

    return 0;
}
