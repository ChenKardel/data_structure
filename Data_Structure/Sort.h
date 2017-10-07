#pragma once
class Sort
{
public:
	Sort();
	~Sort();

	static void selectionSort(int a[],int length);
	static void InsertionSort(int a[], int length);
	static void mergeSort(int a[], int length);

	/*exchange the position of this two integer*/
	static void exch(int& a,int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
private:
	static int* aux;
	static void sort(int a[], int begin, int end);
	static void merge(int a[], int begin, int mid, int end);

};

