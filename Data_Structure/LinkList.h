#pragma once
#include "List.h"
#include <iostream>
using namespace std;

template <class T>
class LinkList :
	public List<T>
{
	/* class Node*/
private:
	template <class T>
	class Node{
		
	private:
		T data;
		Node<T>* next;
	public:
		Node() :next(nullptr) { ; }
		Node(const T& value) :data(value), next(nullptr) {}
		~Node() {}
		Node<T>* nextNode()
		{
			return next;
		}

		static Node<T>* create(const T& item, Node<T>* link = nullptr)
		{
			Node<T> node = new Node<T>(item);
			node->next = link;
			return node;
		}

		bool insertAfter(const Node<T>& node)
		{
			node->next = next;
			next = node;
			return true;

		}

		bool removeAfter()
		{
			Node<T>* temp = this->next;
			this->next = temp->next;
			delete temp;
			temp = NULL;
			return true;
		}

	};



private:
	Node<T>* first;
	Node<T>* last;
public:

	/*construct a list by a T-type value*/
	LinkList(const T& item )
	{
		first = last = new Node<T>(item);
	}

	~LinkList()
	{
		makeEmpty();
		delete first;
		first = NULL;
	}

	/*clear the list*/
	void makeEmpty()
	{
		Node<T>* q;//working pointer
		while(first->next != NULL)
		{
			q = first->next;
			first->next = q->next;
			delete q;
		}
		last = first;
	}

	/*return the length od the list*/
	int length() const
	{
		int count = 0;
		Node<T>* p = first->next;
		while(p!= NULL)
		{
			p = p->next;
			count++;
		}
		return count;
	}

	/*search a value in the list
	 * return the node whos data equals value
	 * if we can find value, return NULL
	 */
	Node<T>* find(T value) const
	{
		Node<T>* p = first->next;
		while (p != NULL && p->data != value)
			p = p->next;
		return p;
	}

	/*find the i-th node,return its address
	 * the index -1 refer to pointer first
	 */
	Node<T>* find(int i) const
	{
		if (i < -1) return NULL;
		if (i == -1) return first;
		auto p = first->next;
		int j = 0;
		while(p != NULL && j < i)
		{
			p = p->next;
			j++;
		}
		return p;
	}

	/*insert a new node(value) before the i-th node in the list*/
	bool insert(T& value,int i)
	{
		Node<T>* p = find(i - 1);
		if (p == NULL) return false;
		Node<T>* newNode = Node<T>::create(value, p->next);
		if (p->next == NULL) last = newNode;
		p->next = newNode;
		return true;
	}

	/*remove the i-th node of the list
	 * if the i-th node is removede successfully, return true;
	 * if we cannot find the i-th node(out of bound or invalid index), return false;
	 */
	bool remove(int i) override
	{
		Node<T>* p = find(i - 1);
		if (p == NULL || p->next == NULL)
			return false;
		auto temp = p->next;
		p->next = temp->next;
		delete temp;
		if (p->next == NULL)
			last = p->next;
		return true;
	}

	/*get the i-th node,return the reference of its value */
	T& get(int i)
	{
		auto p = find(i);
		if (p == NULL || p == first)
			return NULL;
		return p->data;
	}
	
};


