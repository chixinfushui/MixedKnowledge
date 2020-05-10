// replace_copy_if example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool IsOdd (int i) { return ((i%2)==1); }

int main45 () {
	vector<int> first,second;
	vector<int>::iterator it;

	// set some values:
	for (int i=1; i<10; i++) first.push_back(i);          // 1 2 3 4 5 6 7 8 9

	second.resize(first.size());   // allocate space
	replace_copy_if (first.begin(), first.end(), second.begin(), IsOdd, 0);
	// 1 2 3 4 5 6 7 8 9		first
	// 0 2 0 4 0 6 0 8 0		second

	cout << "second contains:";
	for (it=second.begin(); it!=second.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}

