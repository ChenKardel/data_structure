#pragma once
#include <iostream>
using namespace std;
template <class T>
class List
{
public:
	virtual ~List() = default;
	virtual bool isEmpty() const = 0;
	virtual int search(T& x) const = 0;//寻找X元素，若找到返回下标，没找到返回-1
	virtual bool insert(int i, T& x) = 0;
	virtual bool remove(int i) = 0;
	virtual bool clear() = 0;
	virtual bool change(int i, T& x) = 0;
	virtual void display(ostream& out) const = 0;
};