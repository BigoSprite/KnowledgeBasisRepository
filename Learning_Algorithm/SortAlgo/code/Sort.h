/*
* sort algorithm header
*
* Github: https://github.com/BigoSprite/sortAlgoCode
* Email: bigosprite@163.com
* by bigosprite
*/
#ifndef _SORT_H_
#define _SORT_H_

// √∞≈›≈≈–Ú
void bubbleSort(int A[], int N);
void bubbleSort_Ex(int A[], int N);

// —°‘Ò≈≈–Ú
void selectionSort(int A[], int N);

// ≤Â»Î≈≈–Ú
void insertSort(int A[], int N);

// œ£∂˚≈≈–Ú
void shellSort(int A[], int N);

// øÏÀŸ≈≈–Ú
int QSort(int A[], int N);// «˝∂Ø≥Ã–Ú
void quickSort(int A[], int N);

// πÈ≤¢≈≈–Ú
void MergeArray(int A[], int left, int right, int center, int Tmp[]);
void MSort(int A[], int left, int right, int Tmp[]);
void mergeSort(int A[], int N);

// ∂—≈≈–Ú
void up();
void down();
void buildHeap();
void heapSort();



#endif // _SORT_H_