#include "SeqList.h"
#include "Sort.h"
#include <cmath>
int main() {
	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = rand();
	Sort::mergeSort(a, 10);
	for (int i = 0; i < 10; i++)
		cout <<a[i] << " ";
}
