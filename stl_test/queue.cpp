#include <iostream>
#include <deque>
#include <list>
#include <queue>
using namespace std;

int main8 ()
{
	{
		//queue::queue
		deque<int> mydeck (3,100);   // deque with 3 elements
		list<int> mylist (2,200);    // list with 2 elements

		queue<int> first;            // empty queue
		queue<int> second (mydeck);  // queue initialized to copy of deque

		queue<int,list<int> > third; // empty queue with list as underlying container
		queue<int,list<int> > fourth (mylist);

		cout << "size of first: " << (int) first.size() << endl;
		cout << "size of second: " << (int) second.size() << endl;
		cout << "size of third: " << (int) third.size() << endl;
		cout << "size of fourth: " << (int) fourth.size() << endl;
	}
	{
		//queue::back
		//queue::front
		queue<int> myqueue;

		myqueue.push(12);
		myqueue.push(75);   // this is now the back

		myqueue.back() -= myqueue.front();

		cout << "myqueue.back() is now " << myqueue.back() << endl;
	}
	{
		//queue::empty
		//queue::pop
		//queue::push
		queue<int> myqueue;
		int sum (0);

		for (int i=1;i<=10;i++) myqueue.push(i);

		while (!myqueue.empty())
		{
			sum += myqueue.front();
			myqueue.pop();
		}

		cout << "total: " << sum << endl;
	}
	{
		//queue::size
		queue<int> myints;
		cout << "0. size: " << (int) myints.size() << endl;

		for (int i=0; i<5; i++) myints.push(i);
		cout << "1. size: " << (int) myints.size() << endl;

		myints.pop();
		cout << "2. size: " << (int) myints.size() << endl;
	}
	return 0;
}
