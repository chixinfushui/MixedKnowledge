// copy_backward example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main4 () {
	vector<int> myvector;
	vector<int>::iterator it;

	// set some values:
	for (int i=1; i<=5; i++)
		myvector.push_back(i*10);          // myvector: 10 20 30 40 50

	myvector.resize(myvector.size()+3);  // allocate space for 3 more elements

	copy_backward ( myvector.begin(), myvector.begin()+5, myvector.end() );

	cout << "myvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	vector<int> myvector2(8);
	copy_backward ( myvector.begin(), myvector.end(), myvector2.end() );

	cout << "myvector2 contains:";
	for (it=myvector2.begin(); it!=myvector2.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}
