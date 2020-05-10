// nth_element example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction_nth_element (int i,int j) { return (i<j); }

int main31 () {
	vector<int> myvector;
	vector<int>::iterator it;

	// set some values:
	for (int i=1; i<10; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9

	random_shuffle (myvector.begin(), myvector.end());

	/*
		�����n��Ԫ�أ�ʹ��a[n-1]�ǵ�n���Ԫ�أ�ǰ��С��a[n-1]���������a[n-1]
	*/
	// using default comparison (operator <):
	nth_element (myvector.begin(), myvector.begin()+4, myvector.end());

	// using function as comp
	nth_element (myvector.begin(), myvector.begin()+5, myvector.end(),myfunction_nth_element);

	// print out content:
	cout << "myvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}
