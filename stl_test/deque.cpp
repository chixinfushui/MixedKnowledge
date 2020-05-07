#include "stdio.h"
#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int main2()
{
	//deque   double ended queue	双端队列
	{
		//deque::deque
		unsigned int i;

		// constructors used in the same order as described above:
		deque<int> first;                                // empty deque of ints
		deque<int> second (4,100);                       // four ints with value 100
		deque<int> third (second.begin(),second.end());  // iterating through second
		deque<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		deque<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		cout << "The contents of fifth are:";
		for (i=0; i < fifth.size(); i++)
			cout << " " << fifth[i];

		cout << endl;
	}
	{
		//deque::assign
		deque<int> first;
		deque<int> second;
		deque<int> third;

		first.assign (7,100);             // a repetition 7 times of value 100

		deque<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		cout << "Size of first: " << int (first.size()) << endl;
		cout << "Size of second: " << int (second.size()) << endl;
		cout << "Size of third: " << int (third.size()) << endl;

	}
	{
		//deque::at
		deque<int> mydeque (10);   // 10 zero-initialized ints
		unsigned int i;

		// assign some values:
		for (i=0; i<mydeque.size(); i++)
			mydeque.at(i)=i;

		cout << "mydeque contains:";
		for (i=0; i<mydeque.size(); i++)
			cout << " " << mydeque.at(i);

		cout << endl;

	}
	{
		//deque::back
		deque<int> mydeque;

		mydeque.push_back(10);

		while (mydeque.back() != 0)
		{
			mydeque.push_back ( mydeque.back() -1 );
		}

		cout << "mydeque contains:";
		for (unsigned i=0; i<mydeque.size() ; i++)
			cout << " " << mydeque[i];

		cout << endl;
	}
	{
		//deque::front
		deque<int> mydeque;

		mydeque.push_front(77);
		mydeque.push_back(16);

		mydeque.front() -= mydeque.back();

		cout << "mydeque.front() is now " << mydeque.front() << endl;
	}
	{
		//dequeue::begin

		deque<int> mydeque;
		deque<int>::iterator it;

		for (int i=1; i<=5; i++) mydeque.push_back(i);

		cout << "mydeque contains:";

		it = mydeque.begin();

		while (it != mydeque.end())
			cout << " " << *it++;		//*it   迭代器加*表示内容

		cout << endl;
	}
	{
		//dequeue::end
		deque<int> mydeque;
		deque<int>::iterator it;

		for (int i=1; i<=5; i++) mydeque.insert(mydeque.end(),i);

		cout << "mydeque contains:";

		it = mydeque.begin();

		while (it != mydeque.end() )
			cout << " " << *it++;

		cout << endl;
	}
	{
		//deque::clear
		unsigned int i;
		deque<int> mydeque;
		mydeque.push_back (100);
		mydeque.push_back (200);
		mydeque.push_back (300);

		cout << "mydeque contains:";
		for (i=0; i<mydeque.size(); i++) cout << " " << mydeque[i];

		mydeque.clear();
		mydeque.push_back (1101);
		mydeque.push_back (2202);

		cout << "\nmydeque contains:";
		for (i=0; i<mydeque.size(); i++) cout << " " << mydeque[i];

		cout << endl;
	}
	{
		//deque::empty
		deque<int> mydeque;
		int sum (0);

		for (int i=1;i<=10;i++) mydeque.push_back(i);

		while (!mydeque.empty())
		{
			sum += mydeque.front();
			mydeque.pop_front();
		}

		cout << "total: " << sum << endl;
	}
	{
		//deque::erase
		unsigned int i;
		deque<unsigned int> mydeque;

		// set some values (from 1 to 10)
		for (i=1; i<=10; i++) mydeque.push_back(i);

		// erase the 6th element
		mydeque.erase (mydeque.begin()+5);

		// erase the first 3 elements:
		mydeque.erase (mydeque.begin(),mydeque.begin()+3);

		cout << "mydeque contains:";
		for (i=0; i<mydeque.size(); i++)
			cout << " " << mydeque[i];
		cout << endl;
	}
	{
		//deque::get_allocator		内存分配器	是给容器进行内存管理的。一般不用。
		deque<int> mydeque;
		int * p;
		unsigned int i;

		// allocate an array of 5 elements using deque's allocator:
		p=mydeque.get_allocator().allocate(5);

		// assign some values to array
		for (i=0; i<5; i++) p[i]=i;

		cout << "The allocated array contains:";
		for (i=0; i<5; i++) cout << " " << p[i];
		cout << endl;

		mydeque.get_allocator().deallocate(p,5);
	}
	{
		//deque::insert
		deque<int> mydeque;
		deque<int>::iterator it;

		// set some initial values:
		for (int i=1; i<6; i++) mydeque.push_back(i); // 1 2 3 4 5

		it = mydeque.begin();
		++it;

		it = mydeque.insert (it,10);                  // 1 10 2 3 4 5
		// "it" now points to the newly inserted 10

		mydeque.insert (it,2,20);                     // 1 20 20 10 2 3 4 5
		// "it" no longer valid!

		it = mydeque.begin()+2;

		vector<int> myvector (2,30);
		mydeque.insert (it,myvector.begin(),myvector.end());
		// 1 20 30 30 20 10 2 3 4 5

		cout << "mydeque contains:";
		for (it=mydeque.begin(); it<mydeque.end(); ++it)
			cout << " " << *it;
		cout << endl;
	}
	{
		//deque::max_size
		unsigned int i;
		deque<int> mydeque;

		//cout << "Enter number of elements: ";
		//cin >> i;
		i = 10;
		unsigned long size = mydeque.max_size();	//size = 1073741823
		if (i<mydeque.max_size()) 
			mydeque.resize(i);
		else 
			cout << "That size exceeds the limit.\n";
	}
	{
		//deque::operator=
		deque<int> first (3);      // deque with 3 zero-initialized ints
		deque<int> second (5);     // deque with 5 zero-initialized ints

		second=first;
		first=deque<int>();

		cout << "Size of first: " << int (first.size()) << endl;
		cout << "Size of second: " << int (second.size()) << endl;
	}
	{
		//deque::operator[]
		deque<int> mydeque (10);   // 10 zero-initialized elements
		unsigned int i;

		deque<int>::size_type sz = mydeque.size();

		// assign some values:
		for (i=0; i<sz; i++) mydeque[i]=i;

		// reverse order of elements using operator[]:
		for (i=0; i<sz/2; i++)
		{
			int temp;
			temp = mydeque[sz-1-i];
			mydeque[sz-1-i]=mydeque[i];
			mydeque[i]=temp;
		}

		cout << "mydeque contains:";
		for (i=0; i<sz; i++)
			cout << " " << mydeque[i];

		cout << endl;
	}
	{
		//deque::pop_back
		//deque::pop_front
		//deque::push_back
		//deque::push_front	略
	}
	{
		//deque::rbegin
		deque<int> mydeque;
		deque<int>::reverse_iterator rit;		//reverse_iterator  与 iterator

		for (int i=1; i<=5; i++) mydeque.push_back(i);

		cout << "mydeque contains:";

		rit = mydeque.rbegin();

		while ( rit < mydeque.rend() )		// < 很微妙
		{
			cout << " " << *rit;
			++rit;
		}

		cout << endl;
	}
	{
		//deque::resize
		deque<int> mydeque;
		deque<int>::iterator it;

		unsigned int i;

		// set some initial content:
		for (i=1;i<10;i++) mydeque.push_back(i);

		mydeque.resize(5);
		mydeque.resize(8,100);			//100填充
		mydeque.resize(12);

		cout << "mydeque contains:";
		for (it=mydeque.begin(); it<mydeque.end(); ++it)
			cout << " " << *it;

		cout << endl;
	}
	{
		//deque::size
		deque<int> myints;
		cout << "0. size: " << (int) myints.size() << endl;

		for (int i=0; i<5; i++) myints.push_back(i);
		cout << "1. size: " << (int) myints.size() << endl;

		myints.insert (myints.begin(),5,100);				
		cout << "2. size: " << (int) myints.size() << endl;

		myints.pop_back();
		cout << "3. size: " << (int) myints.size() << endl;
	}
	{
		//deque::swap
		unsigned int i;
		deque<int> first (3,100);   // three ints with a value of 100
		deque<int> second (5,200);  // five ints with a value of 200

		first.swap(second);

		cout << "first contains:";
		for (i=0; i<first.size(); i++) cout << " " << first[i];

		cout << "\nsecond contains:";
		for (i=0; i<second.size(); i++) cout << " " << second[i];

		cout << endl;
	}
	return 0;
}