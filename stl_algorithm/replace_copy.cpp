// replace_copy example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main44 () {
	int myints[] = { 10, 20, 30, 30, 20, 10, 10, 20 };

	vector<int> myvector (8);
	replace_copy (myints, myints+8, myvector.begin(), 20, 99);

	// 10 20 30 30 20 10 10 20		myints
	// 10 99 30 30 99 10 10 99		myvector
	cout << "myvector contains:";
	for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}
