// range heap example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main23 () {
	int myints[] = {10,20,30,5,15};
	vector<int> v(myints,myints+5);
	vector<int>::iterator it;

	/*
		��������Ϊ�ѣ�����������Ĭ��Ϊless<>()�󶥶�
		greater<int>()С���ѣ� ͷ�ļ�#include <functional>
	*/
	make_heap (v.begin(),v.end(), less<int>());		
	cout << "initial max heap   : " << v.front() << endl;

	/*
		���ڽ��ѵĵ�0��Ԫ�������Ԫ�ؽ���λ�ã�Ȼ�����ǰn-1��Ԫ�ص���make_heap����
	*/
	pop_heap (v.begin(),v.end()); 
	v.pop_back();
	cout << "max heap after pop : " << v.front() << endl;

	/*
		�������ݲ���ѣ���������make_heap��ͬ
	*/
	v.push_back(99); 
	push_heap (v.begin(),v.end());
	cout << "max heap after push: " << v.front() << endl;

	/*
		���ѽ����������������ʧȥ�����ԡ�
		�󶥶��������һ���������С�С�����������һ���ݼ����С�
	*/
	sort_heap (v.begin(),v.end());

	cout << "final sorted range :";
	for (unsigned i=0; i<v.size(); i++) cout << " " << v[i];

	cout << endl;

	return 0;
}
