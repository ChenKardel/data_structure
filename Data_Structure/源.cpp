#include "SeqList.h"
int main() {
	SeqList<int> list(5);
	for (int i = 0; i < 5; i++) {
		list.insert(i-1, i);
	}
	list.display(cout);
	cout << list.getLength() << endl;
	cout << list[4] << endl;
	list.remove(3);
	list.display(cout);
	int i = 10;
	list.search(i);
}