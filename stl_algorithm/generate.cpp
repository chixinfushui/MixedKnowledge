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
	��for_each()��ͬ��for_each�Ƕ�ÿ��Ԫ����Ϊ�����Ĳ�����
	generate()�޷��ں����ڷ������е�ֵ��
*/
int main16 () {
	srand ( unsigned ( time(NULL) ) );		//srandͨ������seed�ı�ϵͳ�ṩ������ֵ��
						//�Ӷ�����ʹÿ����rand�������ɵ�α��������в�ͬ���Ӷ�ʵ�����������ϵ����

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
