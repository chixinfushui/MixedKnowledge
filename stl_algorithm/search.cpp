// search algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mypredicate_search (int i, int j) {
	return (i==j);
}

int main51 () {
	vector<int> myvector;
	vector<int>::iterator it;

	// set some values:        myvector: 10 20 30 40 50 60 70 80 90
	for (int i=1; i<10; i++) myvector.push_back(i*10);


	// using default comparison:
	int match1[] = {40,50,60,70};
	it = search (myvector.begin(), myvector.end(), match1, match1+4);
	//返回myvector 查找到的位置，3，  若未查找到，返回end
	if (it!=myvector.end())
		cout << "match1 found at position " << int(it-myvector.begin()) << endl;
	else
		cout << "match1 not found" << endl;

	// using predicate comparison:
	int match2[] = {20,30,50};
	it = search (myvector.begin(), myvector.end(), match2, match2+3, mypredicate_search);

	if (it!=myvector.end())
		cout << "match2 found at position " << int(it-myvector.begin()) << endl;
	else
		cout << "match2 not found" << endl;

	return 0;
}
