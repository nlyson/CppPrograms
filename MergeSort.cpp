/******************************************************************************

Merge Sort implemented in C++.

Nathan Lyson
6/5/2021

*******************************************************************************/

#include <iostream>

using namespace std;

void printArray(int[], int);

void merge(int arr[], int left, int right, int mid)
{
    
    
    // Fill up left and right sides
    int leftSize = mid - left;
    int rightSize = right - mid;
    int leftArr[leftSize];
    int rightArr[rightSize];
    
    int k=left;
    for(int i=0; i<leftSize; i++)
        leftArr[i] = arr[k++];
    for(int i=0; i<rightSize; i++)
        rightArr[i] = arr[k++];
        
        
        
        
    int i=0;
    int j=0;
    k=left;
    
    // Compare and copy over while there are still elements in both lists
    while(i < leftSize && j < rightSize)
    {
        if(leftArr[i] < rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    
    // Any leftovers in left 
    while(i < leftSize)
        arr[k++] = leftArr[i++];
        
    // Any leftowvers in right 
    while(j < rightSize)
        arr[k++] = rightArr[j++];
    
}


void mergeSort(int arr[], int left, int right)
{
    // We are done here if there is only one element
    if(right - 1 <= left )
        return;
        
    // Find the middle - recursively call mergeSort on both sides
    int mid = (left + right) / 2;
    
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    
    // Merge the two sorted sides together
    merge(arr, left, right, mid);
    

}



void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
        
    cout << endl;
}


int main()
{
    // Test cases
    int arr[10]{1, 2, 8, 9, 3, 5, 4, 6, 8, 7};
    
    mergeSort(arr, 0, 10);
    
    printArray(arr, 10);

    return 0;
}
