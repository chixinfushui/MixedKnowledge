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
		将容器变为堆，第三个参数默认为less<>()大顶堆
		greater<int>()小顶堆， 头文件#include <functional>
	*/
	make_heap (v.begin(),v.end(), less<int>());		
	cout << "initial max heap   : " << v.front() << endl;

	/*
		用于将堆的第0个元素与最后元素交换位置，然后针对前n-1个元素调用make_heap（）
	*/
	pop_heap (v.begin(),v.end()); 
	v.pop_back();
	cout << "max heap after pop : " << v.front() << endl;

	/*
		用于数据插入堆，其意义与make_heap相同
	*/
	v.push_back(99); 
	push_heap (v.begin(),v.end());
	cout << "max heap after push: " << v.front() << endl;

	/*
		将堆进行排序，排序后，序列失去堆特性。
		大顶堆排序后是一个递增序列。小顶堆排序后是一个递减序列。
	*/
	sort_heap (v.begin(),v.end());

	cout << "final sorted range :";
	for (unsigned i=0; i<v.size(); i++) cout << " " << v[i];

	cout << endl;

	return 0;
}
