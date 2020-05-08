// find_end example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction_find_end (int i, int j) {
	return (i==j);
}
//匹配最后一个匹配项
int main12 () {
	int myints[] = {1,2,3,4,5,1,2,3,4,5};
	vector<int> myvector (myints,myints+10);
	vector<int>::iterator it;

	int match1[] = {1,2,3};

	// using default comparison:
	it = find_end (myvector.begin(), myvector.end(), match1, match1+3);

	if (it!=myvector.end())
		cout << "match1 last found at position " << int(it-myvector.begin()) << endl;

	int match2[] = {4,5,1};

	// using predicate comparison:
	it = find_end (myvector.begin(), myvector.end(), match2, match2+3, myfunction_find_end);

	if (it!=myvector.end())
		cout << "match2 last found at position " << int(it-myvector.begin()) << endl;

	return 0;
}
