// search_n example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mypredicate (int i, int j) {
	return (i==j);
}

int main52 () {
	int myints[]={10,20,30,30,20,10,10,20};
	vector<int> myvector (myints,myints+8);

	vector<int>::iterator it;

	// using default comparison:
	it = search_n (myvector.begin(), myvector.end(), 2, 30);
	//返回myvector 查找到的位置，2，  若未查找到，返回end
	if (it!=myvector.end())
		cout << "two 30s found at position " << int(it-myvector.begin()) << endl;
	else
		cout << "match not found" << endl;

	// using predicate comparison:
	it = search_n (myvector.begin(), myvector.end(), 2, 10, mypredicate);

	if (it!=myvector.end())
		cout << "two 10s found at position " << int(it-myvector.begin()) << endl;
	else
		cout << "match not found" << endl;

	return 0;
}
