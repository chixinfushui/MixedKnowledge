// lexicographical_compare example
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

// a case-insensitive comparison function:
bool mycomp (char c1, char c2)
{ return tolower(c1)<tolower(c2); }
/*
	�Ƚ��������У���һ������С�ڵڶ������з���true�����ڵ��ڷ���false
*/
int main21 () {
	char first[]="Apple";         // 5 letters
	char second[]="apartment";    // 9 letters
	int aa = 'A';
	int bb = 'a';
	cout << "Using default comparison (operator<): ";
	if (lexicographical_compare(first,first+5,second,second+9))
		cout << first << " is less than " << second << endl;
	else
		if (lexicographical_compare(second,second+9,first,first+5))
			cout << first << " is greater than " << second << endl;
		else
			cout << first << " and " << second << " are equivalent\n";


	cout << "Using mycomp as comparison object: ";
	if (lexicographical_compare(first,first+5,second,second+9,mycomp))
		cout << first << " is less than " << second << endl;
	else
		if (lexicographical_compare(second,second+9,first,first+5,mycomp))
			cout << first << " is greater than " << second << endl;
		else
			cout << first << " and " << second << " are equivalent\n";

	return 0;
}
