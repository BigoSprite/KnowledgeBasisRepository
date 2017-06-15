#include <iostream>
#include "Sort.h"


void main()
{
	int A[] = { 9, 1, 5, 8, 3, 7, 4, 6, 2 };
	//selectionSort(A, 9);
	insertSort(A, 9);

	for (int i = 0; i < 9; ++i){
		std::cout << A[i] << " ";
	}


	std::cin.get();
}