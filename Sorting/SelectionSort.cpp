/******************************************************************************

Selection Sort
Nathan Lyson
6/5/2021

*******************************************************************************/

#include <iostream>

using namespace std;

void insertionSort(int arr[], int size)
{
    
    // We are going to increase the sorted portion of our array by 1 each go around.
    // We are going to "slide" the new element into it's correct place.
    for(int i=1; i<size; i++)
    {
        int temp = arr[i];
        int j = i;   // j is where our new guy should go
        
        // Keep moving j down until he is in his right place
        // Move all other elements down the list
        while(j > 0 && arr[j-1] > temp)
            arr[j] = arr[(j--)-1];
            
        arr[j] = temp;
        
    }
    
    
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
        
    cout << endl;
}

int main()
{
    int arr[]{8, 2, 3, 9, 1, 4, 0, 6, 7, 5};
    
    insertionSort(arr, 10);
    
    printArray(arr, 10);

    return 0;
}
