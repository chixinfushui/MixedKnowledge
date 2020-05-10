// stable_sort example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare_as_ints (double i,double j)
{
	return (int(i)<int(j));
}

// print container content:
template <class T> void PrintCont ( T& cont )
{
	for (T::iterator it=cont.begin(); it!=cont.end(); ++it)
		cout << " " << *it;
	cout << endl;
}

int main60 () {
	double mydoubles[] = {3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58};

	vector<double> myvector;
	vector<double>::iterator it;

	myvector.assign(mydoubles,mydoubles+8);
	/*
		stable_sort使用归并排序，sort使用快速排序。一个稳定一个不稳定，一般sort比stable_sort快一点

		stable_sort遇到两个数相等时，不对其进行交换顺序。
		这个应用在数组中，不受影响。当函数参数传入的是结构体时。会发现两者的明显区别
	*/
	cout << "using default comparison:";
	stable_sort (myvector.begin(), myvector.end());
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	myvector.assign(mydoubles,mydoubles+8);

	cout << "\nusing 'compare_as_ints' :";
	stable_sort (myvector.begin(), myvector.end(), compare_as_ints);
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}

