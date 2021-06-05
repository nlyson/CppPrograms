/******************************************************************************

Nathan Lyson
Iterative Binary Search
6/5/21

*******************************************************************************/

#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int left, int right, int target)
{
    
            
    while(right+1 > left)
    {
        int mid = (left+right) / 2;
        
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            right = mid-1;
        else
            left = mid+1;
    }
    
    return -1;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

int main()
{
    // Create a test array filled with random ints from 1 - 20
    srand(time(0));
    int arr[10];
    
    for(int i=0; i<10; i++)
        arr[i] = (rand()%20) + 1;
    
    sort(arr, arr+10);
    
    printArray(arr, 10);
  
    cout << "Index of 1: " << binarySearch(arr, 0, 10, 1) << endl;
    cout << "Index of 5: " << binarySearch(arr, 0, 10, 5) << endl;
    cout << "Index of 7: " << binarySearch(arr, 0, 10, 7) << endl;
    cout << "Index of 19: " << binarySearch(arr, 0, 10, 19) << endl;


    return 0;
}
