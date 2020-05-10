// stable_partition example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool IsOdd_stable_partition (int i) { return (i%2)==1; }

int main59 () {
	vector<int> myvector;
	vector<int>::iterator it, bound;

	// set some values:
	for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9
	myvector.push_back(13);
	myvector.push_back(11);
	myvector.push_back(0);
	/*
		序列分割  子序列相对位置改变  stable_partition 子序列相对位置不变
	*/
	bound = stable_partition (myvector.begin(), myvector.end(), IsOdd_stable_partition);

	// print out content:
	cout << "odd members:";
	for (it=myvector.begin(); it!=bound; ++it)
		cout << " " << *it;

	cout << "\neven members:";
	for (it=bound; it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}
