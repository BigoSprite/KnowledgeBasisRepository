/*
* sort algorithm header
*
* Github: https://github.com/BigoSprite/sortAlgoCode
* Email: bigosprite@163.com
* by bigosprite
*/
#ifndef _SORT_H_
#define _SORT_H_

// ð������
void bubbleSort(int A[], int N);
void bubbleSort_Ex(int A[], int N);

// ѡ������
void selectionSort(int A[], int N);

// ��������
void insertSort(int A[], int N);

// ϣ������
void shellSort(int A[], int N);

// ��������
int QSort(int A[], int N);// ��������
void quickSort(int A[], int N);

// �鲢����
void MergeArray(int A[], int left, int right, int center, int Tmp[]);
void MSort(int A[], int left, int right, int Tmp[]);
void mergeSort(int A[], int N);

// ������
void up();
void down();
void buildHeap();
void heapSort();



#endif // _SORT_H_