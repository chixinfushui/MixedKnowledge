// generate_n example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int current(0);
int UniqueNumber () { return ++current; }

int main17 () {
	vector<int> myvector (9);
	vector<int>::iterator it;

	generate_n (myvector.begin() + 1, 5, UniqueNumber);

	cout << "myvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}
