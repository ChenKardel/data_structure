#ifndef SEQLIST_h
#define SEQLIAT_h
#include "List.h"
template <class T>

class SeqList :public List<T>
{
private:
	int maxLength; //数组最大长度
	T* array;//指向数组首元素的指针
	int length;
public:
	SeqList(int size)
	{
		maxLength = size;
		array = new T[maxLength];
		length = 0;
	}

	~SeqList()
	{
		delete[] array;
		array = NULL;
	}
	int getLength() const
	{
		return length;
	}

	bool isEmpty() const override
	{
		if (length == 0) return false;
		return true;
	}

	bool clear() override
	{
		length = 0;
		return true;
	}


	int search(T& x) const override
	{
		for (int i = 0; i < length; i++)
		{
			if (array[i] == x) return i;
		}
	
		cout << "can not found" << endl;
		return -1;
		
	}

	bool insert(int i, T& x) override
	{
		if (i <-1 || i >length - 1) {
			cerr << "out of bound" << endl;
			return false;
		}
		for (int j = length - 1; j > i; --j)
		{
			array[j + 1] = array[j];
		}
		array[i+1] = x;
		++length;
		return true;
	}
	bool remove(int i) override
	{
		if (i<-1 || i>/*List<T>::*/length - 1) {
			cerr << "out of bound" << endl;
			return false;
		}
		for (int j = i;j < length-1;j++) {
			array[j] = array[j + 1];
			return true;
		}
		length--;
		return false;
	}
	bool change(int i, T& x) override
	{
		array[i] = x;
		return true;
	}

	void display(ostream& out) const override
	//只用与build-in 类型和String，不适用类对象
	{
		for (int i = 0; i < length; i++)
		{
			out << array[i] << " ";
		}
	}

	T& operator[](int i) 
	{
		if(i>-1||i<= length-1)
		{
			return array[i];
		}
		else
		{
			cerr << "Out Of Bound" << endl;
			exit(0);
		}
		
	}
};



#endif