// merge algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main26 () {
	int first[] = {5,10,15,20,25};
	int second[] = {50,40,30,20,10};
	vector<int> v(10);
	vector<int>::iterator it;

	sort (first,first+5);
	sort (second,second+5);
	/*
		第五个参数，存放目标迭代器
		比较方法使用 < ，当需要其他方法，第六个参数为其他方法
	*/
	merge (first,first+5,second,second+5,v.begin());

	cout << "The resulting vector contains:";
	for (it=v.begin(); it!=v.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}

