#include "Sort.h"



Sort::Sort()
{
}


Sort::~Sort()
{
}

void Sort::selectionSort(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		int min = i;
		for (int j = i+1; j < length; j++)
		{
			if (a[j] < a[min]) min = j;
		}
		exch(a[i], a[min]);
	}
}

void Sort::InsertionSort(int a[], int length)
{
	for(int i = 0;i < length;i++)
	{
		for(int j = i;j >0;j--)
		{
			if (a[j] < a[j - 1])
				exch(a[j], a[j - 1]);
		}
	}
}

void Sort::mergeSort(int a[], int length)
{
	aux = new int[length];
	sort(a, 0,length - 1);
}

void Sort::sort(int a[], int begin, int end)
{
	if (begin <= end) return;
	int mid = begin + (end - begin) / 2;
	sort(a, begin, mid);
	sort(a, mid, end);
	merge(a, begin, mid, end);

}

void Sort::merge(int a[], int begin, int mid, int end)
{
	int i = begin;
	int j = mid + 1;
	for (int k = 0; k <= end; k++)
		aux[k] = a[k];
	for (int k = 0; k < end; k++)
	{
		if (j > mid) a[k] = aux[j++];
		else if (j > end) a[k] = aux[i++];
		else if (aux[j] < aux[i]) a[k] = aux[j++];
		else a[k] = aux[i++];
	}
}
