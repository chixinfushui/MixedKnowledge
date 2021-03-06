// rotate algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main49 () {
	vector<int> myvector;
	vector<int>::iterator it;

	// set some values:
	for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

	rotate(myvector.begin(),myvector.begin()+3,myvector.end());
	// 4 5 6 7 8 9 1 2 3

	// print out content:
	cout << "myvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}

