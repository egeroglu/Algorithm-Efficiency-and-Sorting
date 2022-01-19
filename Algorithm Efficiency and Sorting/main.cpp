
/**
 * Title: Algorithm Efficiency and Sorting
 * Author: Erdem Ege Eroglu
 * ID: 21601636
 * Section: 3
 * Assignment: 1
 * Description: Main file that include the testing sorting algorithms and performance analysis
 */
#include <iostream>
#include "sorting.h"
using namespace std;
int main() {

    // initial array
    int originalArray[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    cout << " \t Initial Array" << endl;
    displayArray(originalArray, 16);
    cout << endl;

    // start to algorithm test
    cout << " \t Algorithm Test" << endl;

    int compCount = 0;
    int moveCount = 0;
    // start to selection sort
    cout << "Selection Sort Test" << endl;
    int arraySelection[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    selectionSort(arraySelection, 16, compCount, moveCount);
    displayArray(arraySelection, 16);

    // start to merge sort
    compCount = 0;
    moveCount = 0;
    cout << "Merge Sort Test" << endl;
    int arrayMerge[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    mergeSort(arrayMerge, 16, compCount, moveCount);
    displayArray(arrayMerge, 16);

    // start to quick sort
    compCount = 0;
    moveCount = 0;
    cout << "Quick Sort Test" << endl;
    int arrayQuick[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    quickSort(arrayQuick, 16, compCount, moveCount);
    displayArray(arrayQuick, 16);

    // start to radix sort
    compCount = 0;
    moveCount = 0;
    cout << "Radix Sort Test" << endl;
    int arrayRadix[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    radixSort(arrayRadix, 16);
    displayArray(arrayRadix, 16);

    // start to performance analysis
    cout << "\n \t Performance Analysis" << endl;
    performanceAnalysis();


    return 0;
}
