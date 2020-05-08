// min_element/max_element
#include <iostream>
#include <algorithm>
using namespace std;

bool myfn_min_element(int i, int j) { return i<j; }

struct myclass_min_element {
	bool operator() (int i,int j) { return i<j; }
} myobj;

int main28 () {
	int myints[] = {3,7,2,5,6,4,9};

	// using default comparison:
	cout << "The smallest element is " << *min_element(myints,myints+7) << endl;
	cout << "The largest element is " << *max_element(myints,myints+7) << endl;

	// using function myfn as comp:
	cout << "The smallest element is " << *min_element(myints,myints+7,myfn_min_element) << endl;
	cout << "The largest element is " << *max_element(myints,myints+7,myfn_min_element) << endl;

	// using object myobj as comp:
	cout << "The smallest element is " << *min_element(myints,myints+7,myobj) << endl;
	cout << "The largest element is " << *max_element(myints,myints+7,myobj) << endl;

	return 0;
}

