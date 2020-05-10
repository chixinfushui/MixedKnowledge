// remove algorithm example
#include <iostream>
#include <algorithm>
using namespace std;

int main39 () {
	int myints[] = {10,20,30,30,20,10,10,20};      // 10 20 30 30 20 10 10 20

	// bounds of range:
	int* pbegin = myints;                          // ^
	int* pend = myints+sizeof(myints)/sizeof(int); // ^                       ^

	/* �����µ��߼��յ� */
	pend = remove (pbegin, pend, 20);              // 10 30 30 10 10 10 10 20
	// ^              ^
	cout << "range contains:";
	for (int* p=pbegin; p!=pend; ++p)
		cout << " " << *p;

	cout << endl;

	return 0;
}
