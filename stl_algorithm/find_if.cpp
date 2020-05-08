// find_if example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool IsOdd_find_if (int i) {
	return ((i%2)==1);
}
//”Îcount_if¿‡À∆
int main14 () {
	vector<int> myvector;
	vector<int>::iterator it;

	myvector.push_back(10);
	myvector.push_back(25);
	myvector.push_back(40);
	myvector.push_back(55);

	it = find_if (myvector.begin(), myvector.end(), IsOdd_find_if);
	cout << "The first odd value is " << *it << endl;

	return 0;
}
