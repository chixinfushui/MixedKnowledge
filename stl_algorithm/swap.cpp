// swap algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main61 () {

	int x=10, y=20;                         // x:10 y:20
	swap(x,y);                              // x:20 y:10

	vector<int> first (4,x), second (6,y);  // first:4x20 second:6x10
	swap(first,second);                     // first:6x10 second:4x20

	cout << "first contains:";
	for (vector<int>::iterator it=first.begin(); it!=first.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}

