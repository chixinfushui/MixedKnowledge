// partial_sort_copy example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction_partial_sort_copy (int i,int j) { return (i<j); }

int main33 () {
	int myints[] = {9,8,7,6,5,4,3,2,1};
	vector<int> myvector (5);
	vector<int>::iterator it;

	/*
		¿‡À∆partial_sort
	*/
	// using default comparison (operator <):
	partial_sort_copy (myints, myints+9, myvector.begin(), myvector.end());

	// using function as comp
	partial_sort_copy (myints, myints+9, myvector.begin(), myvector.end(), myfunction_partial_sort_copy);

	// print out content:
	cout << "myvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}

