// unique algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction_unique (int i, int j) {
	return (i==j);
}

int main64 () {
	int myints[] = {10,20,20,20,30,30,20,20,10};    // 10 20 20 20 30 30 20 20 10
	vector<int> myvector (myints,myints+9);
	vector<int>::iterator it;

	// using default comparison:
	it = unique (myvector.begin(), myvector.end()); // 10 20 30 20 10 30 20 20 10
													//                ^

	myvector.resize( it - myvector.begin() );       // 10 20 30 20 10

	// using predicate comparison:
	unique (myvector.begin(), myvector.end(), myfunction_unique);   // (no changes)

	// print out content:
	cout << "myvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}
