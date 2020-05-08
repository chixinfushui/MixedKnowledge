// for_each example
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;
//对每个元素执行操作
void myfunction (int i) {
	cout << " " << i;
}

struct myclass {
	void operator() (int i) {cout << " " << i;}
} myobject;

void myfunction2 (pair<int,int>p) {
	cout << " " << p.first << " " << p.second;
}
struct myclass2 {
	void operator() (pair<int,int>p) {cout << " " << p.first << " " << p.second;}
} myobject2;
int main15 () {
	{
		deque<int> myvector;
		myvector.push_back(10);
		myvector.push_back(20);
		myvector.push_back(30);

		cout << "myvector contains:";
		for_each (myvector.begin(), myvector.end(), myfunction);

		// or:
		cout << "\nmyvector contains:";
		for_each (myvector.begin(), myvector.end(), myobject);

		cout << endl;
	}
	{
		map<int,int> myvector;
		myvector.insert(make_pair(1,11));
		myvector.insert(pair<int,int>(2,22));
		myvector.insert(make_pair(3,33));

		cout << "myvector contains:";
		for_each (myvector.begin(), myvector.end(), myfunction2);

		// or:
		cout << "\nmyvector contains:";
		for_each (myvector.begin(), myvector.end(), myobject2);

		cout << endl;
	}
	return 0;
}

