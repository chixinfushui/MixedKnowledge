#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

int main10 ()
{
	{
		//stack::stack
		deque<int> mydeque (3,100);     // deque with 3 elements
		vector<int> myvector (2,200);   // vector with 2 elements

		stack<int> first;               // empty stack
		stack<int> second (mydeque);    // stack initialized to copy of deque

		stack<int,vector<int> > third;  // empty stack using vector
		stack<int,vector<int> > fourth (myvector);

		cout << "size of first: " << (int) first.size() << endl;
		cout << "size of second: " << (int) second.size() << endl;
		cout << "size of third: " << (int) third.size() << endl;
		cout << "size of fourth: " << (int) fourth.size() << endl;
	}
	{
		//stack::empty			first int last out
		//stack::pop
		//stack::push
		//stack::top
		stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		cout << "total: " << sum << endl;
	}
	{
		//stack::size
		stack<int> myints;
		cout << "0. size: " << (int) myints.size() << endl;

		for (int i=0; i<5; i++) myints.push(i);
		cout << "1. size: " << (int) myints.size() << endl;

		myints.pop();
		cout << "2. size: " << (int) myints.size() << endl;

	}
	return 0;
}
