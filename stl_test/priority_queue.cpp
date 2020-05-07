// constructing priority queues
#include <iostream>
#include <queue>
#include <xfunctional>		//greater:内置类型从大到小排序  less：内置类型从小到大排序
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
		return a>b;		//最小优先
	}
};
struct cmp2
{
	bool operator () (int &a, int &b){
		return a<b;		//最大优先
	}
};
struct number1
{
	int x;
	bool operator < (const number1 &a) const
	{
		return x > a.x;			//最小优先
	}
};
struct number2
{
	int x;
	bool operator < (const number2 &a) const
	{
		return x < a.x;		//最大优先
	}
};
/************************************************************************/
/* 优先队列实质是堆。大顶堆或小顶堆。   是有排序的完全二叉树。
	push  时，1、将新元素放在完全二叉树最后。
			  2、新元素向上冒泡。
	pop   时，1、最后节点放入根节点
			  2、从根节点开始，与最大叶子元素交换
			  3、被交换的叶子接着作为根继续步骤2
*/
/************************************************************************/
int main9 ()
{
	{/************************************************************************/
		//priority_queue::priority_queue
		int myints[]= {10,60,50,20};

		priority_queue<int> first;
		priority_queue<int> second (myints,myints+3);		//大顶堆   comp : less
		priority_queue< int, vector<int>, greater<int> > third (myints,myints+3);		//小顶堆   comp  :  greater   greater<> >最好加空格， 区别右移符号

		// using mycomparison:
		priority_queue< int, vector<int>, mycomparison > fourth;

		typedef priority_queue<int,vector<int>,mycomparison> mypq_type;
		mycomparison aaa;
		mypq_type fifth (aaa);				//或mypq_type fifth (mycomparison(false));		//大顶堆
		mypq_type sixth (mycomparison(true));			//小顶堆
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
		priority_queue< number1, vector<number1>> seven3;		//改写结构number1和number2的 <方法，从而实现大小顶堆。 
		priority_queue< number2, vector<number2>> seven4;		//seven3和seven4优先队列的实质还是大顶堆  comp:less
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
		priority_queue<int> mypq;			//大顶堆  comp : less
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
