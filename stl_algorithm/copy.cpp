// copy algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main3 () {
	int myints[]={10,20,30,40,50,60,70};
	vector<int> myvector;
	vector<int>::iterator it;

	myvector.resize(7);   // allocate space for 7 elements

	copy ( myints, myints+7, myvector.begin() );

	cout << "myvector contains:";
	for (it=myvector.begin(); it!=myvector.end(); ++it)
		cout << " " << *it;
	cout << endl;

	int myints2[7];
	copy ( myvector.begin() , myvector.end(), myints2);
	cout << "myints2 contains:";
	for (int i = 0; i < 7; i ++)
		cout << " " << myints2[i];

	cout << endl;

	return 0;
}
