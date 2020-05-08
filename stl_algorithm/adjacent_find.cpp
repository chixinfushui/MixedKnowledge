#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction_adjacent_find (int i, int j) {
	return (i==j);
}

int main1 () {
	int myints[] = {10,20,30,30,20,10,20,10};
	vector<int> myvector (myints,myints+8);
	vector<int>::iterator it;

	// using default comparison:
	it = adjacent_find (myvector.begin(), myvector.end());			//用==运算符比较 连续 的一对元素，返回迭代器
																	//指向相等元素的第一个。找不到时返回end.

	if (it!=myvector.end())
		cout << "the first consecutive repeated elements are: " << *it << endl;

	//using predicate comparison:
	it = adjacent_find (++it, myvector.end(), myfunction_adjacent_find);

	if (it!=myvector.end())
		cout << "the second consecutive repeated elements are: " << *it << endl;

	return 0;
}
