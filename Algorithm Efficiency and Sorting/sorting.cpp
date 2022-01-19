
/**
 * Title: Algorithm Efficiency and Sorting
 * Author: Erdem Ege Eroglu
 * ID: 21601636
 * Section: 3
 * Assignment: 1
 * Description: sorting.cpp file
 */
#include "sorting.h"
using namespace std;
void displayArray(const int *arr, const int size)
{
    for(int i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void selectionSort(int *arr, const int size, int &compCount, int &moveCount)
{
    int largest = 0;
    for(int i = size - 1; i >= 1; i--)
    {
        largest = findIndexofLargest(arr,i+1);
        std::swap(arr[largest],arr[i]);
    }
}
int findIndexofLargest( int *arr, int size)
{
    int indexSoFar = 0; // Index of largest entry found so far
    for ( int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        if (arr[currentIndex] > arr[indexSoFar])
            indexSoFar = currentIndex;
    }
    return indexSoFar; // Index of largest entry
}
void merge(int *arr, int size, int first, int mid, int last, int &compCount, int &moveCount)
{
    int tempArray[size]; // Temporary array
    int first1 = first; // Beginning of first subarray
    int last1 = mid; // End of first subarray
    int first2 = mid + 1; // Beginning of second subarray
    int last2 = last; // End of second subarray
    int index = first1; // Next available location in tempArray

    while ((first1 <= last1) && (first2 <= last2))
    {
        if (arr[first1] <= arr[first2])
        {
            tempArray[index] = arr[first1];
            first1++;
        }
        else
        {
            tempArray[index] = arr[first2];
            first2++;
        }
        index++;
        moveCount++;
        compCount++;
    }
    while (first1 <= last1)
    {
        tempArray[index] = arr[first1];
        first1++;
        index++;
        moveCount++;
    }
    while (first2 <= last2)
    {
        tempArray[index] = arr[first2];
        first2++;
        index++;
        moveCount++;
    }
    for (index = first; index <= last; index++)
    {
        arr[index] = tempArray[index];
        moveCount++;
    }
    delete [] tempArray;
}
void mergeSort(int *arr, const int size, int &compCount, int &moveCount)
{
    mergeSort(arr, size, 0, size-1, compCount, moveCount);
}
void mergeSort(int *arr, int size, int first, int last, int &compCount, int &moveCount)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;
        mergeSort(arr, size, first, mid, compCount, moveCount);
        mergeSort(arr, size, mid + 1, last, compCount, moveCount);
        merge(arr, size, first, mid, last, compCount, moveCount);
    } // end if
}
void quickSort(int *arr, int size, int &compCount, int &moveCount)
{
    quickSort( arr, 0, size-1, compCount, moveCount);
}
void quickSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    int pivotIndex;
    if (first < last)
    {
        // create the partition: S1, pivot, S2
        partition(arr, first, last, pivotIndex, compCount, moveCount);

        // sort regions S1 and S2
        quickSort(arr, first, pivotIndex-1, compCount, moveCount);
        quickSort(arr, pivotIndex+1, last, compCount, moveCount);
    }
}
void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount)
{
    moveCount++; // one data move for assigning pivot
    int pivot = arr[first]; // copy pivot
    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown)
    {
        compCount++;
        if (arr[firstUnknown] < pivot)    	// belongs to S1
        {
            ++lastS1;
            std::swap(arr[firstUnknown], arr[lastS1]); // 3 data move
            moveCount = moveCount + 3;
        }	// else belongs to S2

    }
    // place pivot in proper position and mark its location
    std::swap(arr[first], arr[lastS1]); // 3 data move
    moveCount = moveCount + 3;
    pivotIndex = lastS1;
}
int findLargest( int *arr, int size)
{
    int indexSoFar = 0;
    for ( int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        if (arr[currentIndex] > arr[indexSoFar])
            indexSoFar = currentIndex;
    }
    return arr[indexSoFar];
}
void radixSort(int *arr, const int size)
{
    int maxNumber = findLargest(arr, size);
    int k = 0;
    int place = 0; // Place theArray[i] at the end of group k
    int currentPlace = 0;
    for (int i = 0; i < maxNumber ; i++)
    {
        int radix2DArray[10][size]; // Initialize 10 groups to empty
        int counterArray[10] = {0}; // Initialize a counter for each group to 0
        for (int j = 0; j < size; j++)
        {
            k  = ((int)(arr[j]/pow(10, i)))%10;
            place = counterArray[((int)(arr[j]/pow(10, i)))%10];
            counterArray[(int)(arr[j]/pow(10, i))%10] = place+1;
            radix2DArray[ k ][place] = arr[j];
        }
        // Replace the items in theArray with all the items in
        // group 0, followed by all the items in group 1, and so on
        int currentPlace = 0;
        for (int k = 0; k < 10; k++)
        {
            for(int l = 0; l < counterArray[k]; l++)
                arr[currentPlace++] = radix2DArray[k][l];
        }
    }
}

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    for (int i = 0; i < size; i++)
    {
        int randNum = rand() % size + 1 ;
        arr1[i] = randNum;
        arr2[i] = randNum;
        arr3[i] = randNum;
        arr4[i] = randNum;
    }
}

void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    int oldNum = 0;
    int i = 0;
    while(i < size){
        int randNum = rand() % size + 1 ;
        if(oldNum <= randNum)
        {
            oldNum = randNum;
            arr1[i] = oldNum;
            arr2[i] = oldNum;
            arr3[i] = oldNum;
            arr4[i] = oldNum;
            i++;
        }
    }
}
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    int oldNum = 100000;
    int i = 0;
    while(i < size){
        int randNum = rand() % size + 1 ;
        if(oldNum >= randNum)
        {
            oldNum = randNum;
            arr1[i] = oldNum;
            arr2[i] = oldNum;
            arr3[i] = oldNum;
            arr4[i] = oldNum;
            i++;
        }
    }
}
void performanceAnalysis(){
    int sizeList[7] ={6000, 10000, 14000, 18000, 22000, 26000, 30000};
    string resultTable[7][4];
    for(int i= 0; i<7;i++){
        string results[4];
        findResults(sizeList[i],results);
        for(int j =0;j<4;j++)
            resultTable[i][j] = results[j];
    }
}
void findResults(int size, string *results){
    int *arr1 = new int[size];
    int *arr2 =  new int[size];
    int *arr3 =  new int[size];
    int *arr4 =  new int[size];
    createRandomArrays(arr1,arr2,arr3,arr4,size); // Random
    //createAscendingArrays(arr1,arr2,arr3,arr4,size); // Ascending
    //createDescendingArrays(arr1,arr2,arr3,arr4,size); // Descending

}


