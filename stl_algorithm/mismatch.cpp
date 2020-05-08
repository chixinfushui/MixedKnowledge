// mismatch algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mypredicate_mismatch (int i, int j) {
	return (i==j);
}

int main29 () {
	/*
		mismatch 与equal都可以判断两个序列是否相等。
		mismatch可以判断不相等的位置
	*/
	vector<int> myvector;
	for (int i=1; i<6; i++) myvector.push_back (i*10); // myvector: 10 20 30 40 50

	int myints[] = {10,20,80,320,1024};                //   myints: 10 20 80 320 1024

	pair<vector<int>::iterator,int*> mypair;

	// using default comparison:
	mypair = mismatch (myvector.begin(), myvector.end(), myints);
	cout << "First mismatching elements: " << *mypair.first;
	cout << " and " << *mypair.second << endl;;

	mypair.first++; mypair.second++;

	// using predicate comparison:
	mypair = mismatch (mypair.first, myvector.end(), mypair.second, mypredicate_mismatch);
	cout << "Second mismatching elements: " << *mypair.first;
	cout << " and " << *mypair.second << endl;;

	return 0;
}
