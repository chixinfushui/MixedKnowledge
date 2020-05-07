#include "stdio.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }


// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
class is_odd
{
public:
	bool operator() (const int& value) {return (value%2)==1; }
};

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
class is_near
{
public:
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};


// comparison, not case sensitive.
bool compare_nocase (string first, string second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		unsigned char a = tolower(first[i]);
		unsigned char b = tolower(second[i]);
		if (a < b) 
			return true;
		if (b < a)
			return false;
		++i;
	}
	if (first.length()<second.length()) return true;
	else return false;
}


int main3()
{
	{
		// constructors used in the same order as described above:
		list<int> first;                                // empty list of ints
		list<int> second (4,100);                       // four ints with value 100
		list<int> third (second.begin(),second.end());  // iterating through second
		list<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		cout << "The contents of fifth are: ";
		for (list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
			cout << *it << " ";

		cout << endl;
	}
	{
		//list::assign
		list<int> first;
		list<int> second;

		first.assign (7,100);                      // 7 ints with value 100

		second.assign (first.begin(),first.end()); // a copy of first

		int myints[]={1776,7,4};
		first.assign (myints,myints+3);            // assigning from array

		cout << "Size of first: " << int (first.size()) << endl;
		cout << "Size of second: " << int (second.size()) << endl;
	}
	{
		//list::back
		list<int> mylist;

		mylist.push_back(10);

		while (mylist.back() != 0)
		{
			mylist.push_back ( mylist.back() -1 );
		}

		cout << "mylist contains:";
		for (list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
			cout << " " << *it;

		cout << endl;
	}
	{
		//list::front
		list<int> mylist;

		mylist.push_back(77);
		mylist.push_back(16);

		// now front equals 77, and back 16

		mylist.front() -= mylist.back();

		cout << "mylist.front() is now " << mylist.front() << endl;
	}
	{
		//list::begin
		int myints[] = {75,23,65,42,13};
		list<int> mylist (myints,myints+5);

		list<int>::iterator it;

		cout << "mylist contains:";
		for ( it=mylist.begin() ; it != mylist.end(); it++ )
			cout << " " << *it;

		cout << endl;
	}
	{
		//list::end
		int myints[] = {75,23,65,42,13};
		list<int> mylist (myints,myints+5);

		list<int>::iterator it;

		cout << "mylist contains:";
		for ( it=mylist.begin() ; it != mylist.end(); it++ )
			cout << " " << *it;

		cout << endl;
	}
	{
		//list::clear
		list<int> mylist;
		list<int>::iterator it;

		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			cout << " " << *it;

		mylist.clear();
		mylist.push_back (1101);
		mylist.push_back (2202);

		cout << "\nmylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			cout << " " << *it;

		cout << endl;
	}
	{
		//erase
		unsigned int i;
		list<unsigned int> mylist;
		list<unsigned int>::iterator it1,it2;

		// set some values:
		for (i=1; i<10; i++) mylist.push_back(i*10);

		// 10 20 30 40 50 60 70 80 90
		it1 = it2 = mylist.begin(); // ^^
		advance (it2,6);            // ^                 ^		it2 ++    6次
		++it1;                      //    ^              ^

		it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90    erase返回下一个位置。  等同于mylist.erase(it1++);
		//    ^           ^

		it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
		//    ^           ^

		++it1;                      //       ^        ^
		--it2;                      //       ^     ^

		mylist.erase (it1,it2);     // 10 30 60 80 90
		//        ^

		cout << "mylist contains:";
		for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
			cout << " " << *it1;
		cout << endl;
	}
	{
		//list::get_allocator
		list<int> mylist;
		int * p;
		unsigned int i;

		// allocate an array of 5 elements using mylist's allocator:
		p=mylist.get_allocator().allocate(5);

		// assign some values to array
		for (i=0; i<5; i++) p[i]=i;

		cout << "The allocated array contains:";
		for (i=0; i<5; i++) cout << " " << p[i];
		cout << endl;

		mylist.get_allocator().deallocate(p,5);
	}
	{//******************************************************************
		//list::insert
		list<int> mylist;
		list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; i++) mylist.push_back(i); // 1 2 3 4 5

		it = mylist.begin();
		++it;       // it points now to number 2           ^

		mylist.insert (it,10);                        // 1 10 2 3 4 5

		// "it" still points to number 2                      ^
		mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

		--it;       // it points now to the second 20            ^

		vector<int> myvector (2,30);
		mylist.insert (it,myvector.begin(),myvector.end());
		// 1 10 20 30 30 20 2 3 4 5
		//               ^
		cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); it++)
			cout << " " << *it;
		cout << endl;
	}
	{
		//list::max_size
		unsigned int i;
		list<int> mylist;

		cout << "Enter number of elements: \n";
		i = 5;
		cout << "max_size: " << mylist.max_size() << endl;
		if (i < mylist.max_size()) mylist.resize(i);
		else cout << "That size exceeds the limit.\n";
	}
	{//******************************************************************
		//list::merge
		list<double> first, second;

		first.push_back (3.1);
		first.push_back (2.2);
		first.push_back (2.9);

		second.push_back (3.7);
		second.push_back (7.1);
		second.push_back (1.4);

		first.sort();
		second.sort();

		first.merge(second);		//必须有序

		second.push_back (2.1);

		first.merge(second,mycomparison);		//比较方法写的是int类型转换

		cout << "first contains:";
		for (list<double>::iterator it=first.begin(); it!=first.end(); ++it)
			cout << " " << *it;
		cout << endl;
	}
	{
		//list::operator=
		list<int> first (3);      // list of 3 zero-initialized ints
		list<int> second (5);     // list of 5 zero-initialized ints

		second=first;
		first=list<int>();

		cout << "Size of first: " << int (first.size()) << endl;
		cout << "Size of second: " << int (second.size()) << endl;
	}
	{
		//list::push_back
		//list::pop_back
		//list::push_front
		//list::pop_front
		//list::size
	}
	{//******************************************************************
		//list::rbegin
		list<int> mylist;
		for (int i=1; i<=5; i++) mylist.push_back(i);

		cout << "mylist contains:";
		list<int>::reverse_iterator rit;		//reverse_iterator
		for ( rit=mylist.rbegin() ; rit != mylist.rend(); ++rit )
			cout << " " << *rit;

		cout << endl;
	}
	{//******************************************************************
		//list::rend
		list<int> mylist;
		for (int i=1; i<=5; i++) mylist.push_back(i);

		cout << "mylist contains:";
		list<int>::reverse_iterator rit;
		for ( rit=mylist.rbegin() ; rit != mylist.rend(); ++rit )
			cout << " " << *rit;

		cout << endl;
	}
	{//******************************************************************
		//list::remove
		int myints[]= {17,89,7,14};
		list<int> mylist (myints,myints+4);

		mylist.remove(89);
		mylist.remove(88);					//不影响
		cout << "mylist contains:";
		for (list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			cout << " " << *it;
		cout << endl;
	}
	{//******************************************************************
		//list::remove_if
		int myints[]= {15,36,7,17,20,39,4,1};
		list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

		mylist.remove_if (single_digit);      // 15 36 17 20 39

		mylist.remove_if (is_odd());          // 36 20

		cout << "mylist contains:";
		for (list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			cout << " " << *it;
		cout << endl;
	}
	{
		//list::resize
		list<int> mylist;

		unsigned int i;

		// set some initial content:
		for (i=1;i<10;i++) mylist.push_back(i);

		mylist.resize(5);
		mylist.resize(8,100);
		mylist.resize(12);

		cout << "mylist contains:";
		for (list<int>::iterator it=mylist.begin();it!=mylist.end();++it)
			cout << " " << *it;

		cout << endl;
	}
	{
		//list::reverse
		list<int> mylist;
		list<int>::iterator it;

		for (int i=1; i<10; i++) mylist.push_back(i);

		mylist.reverse();

		cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			cout << " " << *it;

		cout << endl;
	}
	{//******************************************************************
		//list::sort
		list<string> mylist;
		list<string>::iterator it;
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");

		mylist.sort();

		cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			cout << " " << *it;
		cout << endl;

		mylist.sort(compare_nocase);		//排序算法

		cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			cout << " " << *it;
		cout << endl;
	}
	{//******************************************************************
		//list::splice
		list<int> mylist1, mylist2;
		list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; i++)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; i++)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                         // points to 2

		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
		// mylist2 (empty)
		// "it" still points to 2 (the 5th element)

		mylist2.splice (mylist2.begin(),mylist1, it);
		// mylist1: 1 10 20 30 3 4
		// mylist2: 2
		// "it" is now invalid.
		it = mylist1.begin();
		advance(it,3);                // "it" points now to 30

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
		// mylist1: 30 3 4 1 10 20

		cout << "mylist1 contains:";
		for (it=mylist1.begin(); it!=mylist1.end(); it++)
			cout << " " << *it;

		cout << "\nmylist2 contains:";
		for (it=mylist2.begin(); it!=mylist2.end(); it++)
			cout << " " << *it;
		cout << endl;
	}
	{
		//list::swap
		list<int> first (3,100);   // three ints with a value of 100
		list<int> second (5,200);  // five ints with a value of 200
		list<int>::iterator it;

		first.swap(second);

		cout << "first contains:";
		for (it=first.begin(); it!=first.end(); it++) cout << " " << *it;

		cout << "\nsecond contains:";
		for (it=second.begin(); it!=second.end(); it++) cout << " " << *it;

		cout << endl;
	}
	{
		//list::unique
		double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
			12.77, 73.35, 72.25, 15.3,  72.25 };
		list<double> mylist (mydoubles,mydoubles+10);

		mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
		// 15.3,  72.25, 72.25, 73.0,  73.35

		mylist.unique();           //  2.72,  3.14, 12.15, 12.77
		// 15.3,  72.25, 73.0,  73.35

		mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
		// 15.3,  72.25, 73.0

		mylist.unique (is_near());           //  2.72, 12.15, 72.25

		cout << "mylist contains:";
		for (list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			cout << " " << *it;
		cout << endl;
	}
	return 0;
}