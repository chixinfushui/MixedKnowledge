// next_permutation
#include <iostream>
#include <algorithm>
using namespace std;

int main30 () {
	int myints[] = {1,2,3};

	cout << "The 3! possible permutations with 3 elements:\n";

	sort (myints,myints+3);
	/*
		生成下一个序列的排列组合，默认使用 < 运算符。
		参数为定义序列的迭代器和一个返回布尔值的函数，这个函数在下一个排列大于上一个排列时，返回true。
	*/
	do {
		cout << myints[0] << " " << myints[1] << " " << myints[2] << endl;
	} while ( next_permutation (myints,myints+3) );

	return 0;
}
