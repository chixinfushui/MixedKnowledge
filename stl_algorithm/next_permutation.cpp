// next_permutation
#include <iostream>
#include <algorithm>
using namespace std;

int main30 () {
	int myints[] = {1,2,3};

	cout << "The 3! possible permutations with 3 elements:\n";

	sort (myints,myints+3);
	/*
		������һ�����е�������ϣ�Ĭ��ʹ�� < �������
		����Ϊ�������еĵ�������һ�����ز���ֵ�ĺ����������������һ�����д�����һ������ʱ������true��
	*/
	do {
		cout << myints[0] << " " << myints[1] << " " << myints[2] << endl;
	} while ( next_permutation (myints,myints+3) );

	return 0;
}
