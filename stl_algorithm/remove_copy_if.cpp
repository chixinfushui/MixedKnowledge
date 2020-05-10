// remove_copy_if example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool IsOdd_remove_copy_if (int i) { return ((i%2)==1); }

int main41 () {
	int myints[] = {1,2,3,4,5,6,7,8,9};          
	vector<int> myvector (9);
	vector<int>::iterator it;

	remove_copy_if (myints,myints+9,myvector.begin(),IsOdd_remove_copy_if);		//2 4 6 8 0 0 0 0 0

	cout << "myvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}

