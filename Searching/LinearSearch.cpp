/******************************************************************************

Linear Search
Nathan Lyson
6/5/21

*******************************************************************************/

#include <iostream>
#include <time.h>

using namespace std;

int linearSearch(int arr[], int size, int target)
{
    // If we find target, return the index where we found it.
    for(int i=0; i<size; i++)
        if(arr[i] == target)
            return i;
            
    // If we got this far, target wasn't there.  Return -1.
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
    
    
        
    printArray(arr, 10);
    cout << "Index of 5 is " << linearSearch(arr, 10, 5);

    return 0;
}
