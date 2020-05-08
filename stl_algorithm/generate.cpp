// generate algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// function generator:
int RandomNumber () { return (rand()%100); }

// class generator:
struct c_unique {
	int current;
	c_unique() {current=0;}
	int operator()() {return ++current;}
} UniqueNumber;

/*
	与for_each()不同，for_each是对每个元素作为函数的参数。
	generate()无法在函数内访问序列的值。
*/
int main16 () {
	srand ( unsigned ( time(NULL) ) );		//srand通过参数seed改变系统提供的种子值，
						//从而可以使每次用rand函数生成的伪随机数序列不同，从而实现真正意义上的随机

	vector<int> myvector (8);
	vector<int>::iterator it;

	generate (myvector.begin(), myvector.end(), RandomNumber);

	cout << "myvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	generate (myvector.begin(), myvector.end(), UniqueNumber);

	cout << "\nmyvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;

	cout << endl;

	return 0;
}
