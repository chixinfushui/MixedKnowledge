// remove_if example
#include <iostream>
#include <algorithm>
using namespace std;

bool IsOdd_remove_if (int i) { return ((i%2)==1); }

int main42 () {
	int myints[] = {1,2,3,4,5,6,7,8,9};            // 1 2 3 4 5 6 7 8 9

	// bounds of range:
	int* pbegin = myints;                          // ^
	int* pend = myints+sizeof(myints)/sizeof(int); // ^                 ^

	//返回新的结束位置
	pend = remove_if (pbegin, pend, IsOdd_remove_if);        // 2 4 6 8 5 6 7 8 9
	// ^       ^
	cout << "range contains:";
	for (int* p=pbegin; p!=pend; ++p)
		cout << " " << *p;

	cout << endl;

	return 0;
}
