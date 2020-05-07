// constructing priority queues
#include <iostream>
#include <queue>
#include <xfunctional>		//greater:�������ʹӴ�С����  less���������ʹ�С��������
using namespace std;

class mycomparison
{
	bool reverse;
public:
	mycomparison(const bool& revparam=false)
	{reverse=revparam;}
	bool operator() (const int& lhs, const int&rhs) const
	{
		if (reverse) return (lhs>rhs);
		else return (lhs<rhs);
	}
};
struct cmp1
{
	bool operator () (int &a, int &b){
		return a>b;		//��С����
	}
};
struct cmp2
{
	bool operator () (int &a, int &b){
		return a<b;		//�������
	}
};
struct number1
{
	int x;
	bool operator < (const number1 &a) const
	{
		return x > a.x;			//��С����
	}
};
struct number2
{
	int x;
	bool operator < (const number2 &a) const
	{
		return x < a.x;		//�������
	}
};
/************************************************************************/
/* ���ȶ���ʵ���Ƕѡ��󶥶ѻ�С���ѡ�   �����������ȫ��������
	push  ʱ��1������Ԫ�ط�����ȫ���������
			  2����Ԫ������ð�ݡ�
	pop   ʱ��1�����ڵ������ڵ�
			  2���Ӹ��ڵ㿪ʼ�������Ҷ��Ԫ�ؽ���
			  3����������Ҷ�ӽ�����Ϊ����������2
*/
/************************************************************************/
int main9 ()
{
	{/************************************************************************/
		//priority_queue::priority_queue
		int myints[]= {10,60,50,20};

		priority_queue<int> first;
		priority_queue<int> second (myints,myints+3);		//�󶥶�   comp : less
		priority_queue< int, vector<int>, greater<int> > third (myints,myints+3);		//С����   comp  :  greater   greater<> >��üӿո� �������Ʒ���

		// using mycomparison:
		priority_queue< int, vector<int>, mycomparison > fourth;

		typedef priority_queue<int,vector<int>,mycomparison> mypq_type;
		mycomparison aaa;
		mypq_type fifth (aaa);				//��mypq_type fifth (mycomparison(false));		//�󶥶�
		mypq_type sixth (mycomparison(true));			//С����
		fifth.push(10);
		sixth.push(10);
		fifth.push(20);
		sixth.push(20);
		fifth.push(30);
		sixth.push(30);
		fifth.push(50);
		sixth.push(50);
		priority_queue< int, vector<int>,  cmp1> seven1;
		priority_queue< int, vector<int>,  cmp2> seven2;
		priority_queue< number1, vector<number1>> seven3;		//��д�ṹnumber1��number2�� <�������Ӷ�ʵ�ִ�С���ѡ� 
		priority_queue< number2, vector<number2>> seven4;		//seven3��seven4���ȶ��е�ʵ�ʻ��Ǵ󶥶�  comp:less
		seven1.push(10);
		seven1.push(20);
		seven1.push(30);
		seven2.push(10);
		seven2.push(20);
		seven2.push(30);
		seven2.push(40);
		number1 n1_1; n1_1.x = 10;
		number1 n1_2; n1_2.x = 20;
		number1 n1_3; n1_3.x = 30;
		number2 n2_1; n2_1.x = 10;
		number2 n2_2; n2_2.x = 20;
		number2 n2_3; n2_3.x = 30;
		number2 n2_4; n2_4.x = 40;
		seven3.push(n1_1);
		seven3.push(n1_2);
		seven3.push(n1_3);
		seven4.push(n2_1);
		seven4.push(n2_2);
		seven4.push(n2_3);
		seven4.push(n2_4);
	}
	{
		//priority_queue::empty
		//priority_queue::pop
		//priority_queue::push
		//priority_queue::top
		priority_queue<int> mypq;			//�󶥶�  comp : less
		int sum (0);

		for (int i=1;i<=10;i++) 
			mypq.push(i);

		while (!mypq.empty())
		{
			sum += mypq.top();
			mypq.pop();
		}

		cout << "total: " << sum << endl;
	}
	{
		//priority_size
		priority_queue<int> myints;
		cout << "0. size: " << (int) myints.size() << endl;

		for (int i=0; i<5; i++) myints.push(i);
		cout << "1. size: " << (int) myints.size() << endl;

		myints.pop();
		cout << "2. size: " << (int) myints.size() << endl;
	}
	return 0;
}
