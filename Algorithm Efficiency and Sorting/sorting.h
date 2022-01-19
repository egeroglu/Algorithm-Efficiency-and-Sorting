

/**
 * Title: Algorithm Efficiency and Sorting
 * Author: Erdem Ege Eroglu
 * ID: 21601636
 * Section: 3
 * Assignment: 1
 * Description: sorting.h file
 */

#ifndef sorting_h
#define sorting_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int findIndexofLargest( int *arr, int size);
void selectionSort(int *arr, const int size, int &compCount, int &moveCount);

void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, int size, int first, int last, int &compCount, int &moveCount);

void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
void quickSort(int *arr, int size, int &compCount, int &moveCount);
void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);

int findLargest( int *arr, int size);
void radixSort(int *arr, const int size);

void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);

void performanceAnalysis();
void findResults(int size, string *results);


#endif
