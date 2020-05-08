#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction_binary_search (int i,int j) { return (i<j); }
/************************************************************************/
/* 二分查找，先sort
*/
/************************************************************************/
int main2 () {
	int myints[] = {1,2,3,4,5,4,3,2,1};
	vector<int> v(myints,myints+9);                         // 1 2 3 4 5 4 3 2 1

	// using default comparison:
	sort (v.begin(), v.end());

	cout << "looking for a 3... ";
	if (binary_search (v.begin(), v.end(), 3))
		cout << "found!\n"; else cout << "not found.\n";

	// using myfunction as comp:
	sort (v.begin(), v.end(), myfunction_binary_search);

	cout << "looking for a 6... ";
	if (binary_search (v.begin(), v.end(), 6, myfunction_binary_search))
		cout << "found!\n"; else cout << "not found.\n";

	return 0;
}
