#include <iostream>
#include <set>
using namespace std;

bool fncomp_set (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const int& lhs, const int& rhs) const
	{return lhs<rhs;}
};

int main6 ()
{
	{
		//set::set
		set<int> first;                           // empty set of ints

		int myints[]= {10,20,30,40,50};
		set<int> second (myints,myints+5);        // pointers used as iterators

		set<int> third (second);                  // a copy of second

		set<int> fourth (second.begin(), second.end());  // iterator ctor.

		set<int,classcomp> fifth;                 // class as Compare

		bool(*fn_pt)(int,int) = fncomp_set;
		set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
	}
	{/*******************************************/
		//set::begin
		//set::end
		int myints[] = {75,23,65,42,13};
		set<int> myset (myints,myints+5);				//ÓÐÐò£¡£¡£¡

		set<int>::iterator it;

		cout << "myset contains:";
		for ( it=myset.begin() ; it != myset.end(); it++ )
			cout << " " << *it;

		cout << endl;
	}
	{
		//set::rbegin
		//set::rend
		int myints[] = {78,21,64,49,17};
		set<int> myset (myints,myints+5);

		set<int>::reverse_iterator rit;

		cout << "myset contains:";
		for ( rit=myset.rbegin() ; rit != myset.rend(); rit++ )
			cout << " " << *rit;

		cout << endl;
	}
	{
		//set::clear
		set<int> myset;
		set<int>::iterator it;

		myset.insert (100);
		myset.insert (200);
		myset.insert (300);

		cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			cout << " " << *it;

		myset.clear();
		myset.insert (1101);
		myset.insert (2202);

		cout << "\nmyset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			cout << " " << *it;

		cout << endl;
	}
	{
		//set::count
		set<int> myset;
		int i;

		// set some initial values:
		for (i=1; i<5; i++) myset.insert(i*3);    // set: 3 6 9 12

		for (i=0;i<10; i++)
		{
			cout << i;
			if (myset.count(i)>0)
				cout << " is an element of myset.\n";
			else 
				cout << " is not an element of myset.\n";
		}
	}
	{
		//set::empty
		set<int> myset;

		myset.insert(20);
		myset.insert(30);
		myset.insert(10);

		cout << "myset contains:";
		while (!myset.empty())
		{
			cout << " " << *myset.begin();
			myset.erase(myset.begin());
		}
		cout << endl;
	}
	{
		//set::equal_range
		set<int> myset;
		pair<set<int>::iterator,set<int>::iterator> ret;

		for (int i=1; i<=5; i++) myset.insert(i*10);   // set: 10 20 30 40 50

		ret = myset.equal_range(30);

		cout << "lower bound points to: " << *ret.first << endl;
		cout << "upper bound points to: " << *ret.second << endl;
	}
	{
		//set::erase
		set<int> myset;
		set<int>::iterator it;

		// insert some values:
		for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

		it=myset.begin();
		it++;                                         // "it" points now to 20

		myset.erase (it);

		myset.erase (40);

		it=myset.find (60);
		myset.erase ( it, myset.end() );

		cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			cout << " " << *it;
		cout << endl;
	}
	{
		//set::find
		set<int> myset;
		set<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

		it=myset.find(20);
		myset.erase (it);
		myset.erase (myset.find(40));

		cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); it++)
			cout << " " << *it;
		cout << endl;
	}
	{
		//set::get_allocator
		set<int> myset;
		int * p;
		unsigned int i;

		// allocate an array of 5 elements using myset's allocator:
		p=myset.get_allocator().allocate(5);

		// assign some values to array
		for (i=0; i<5; i++) p[i]=(i+1)*10;

		cout << "The allocated array contains:";
		for (i=0; i<5; i++) cout << " " << p[i];
		cout << endl;

		myset.get_allocator().deallocate(p,5);
	}
	{
		//set::insert
		set<int> myset;
		set<int>::iterator it;
		pair<set<int>::iterator,bool> ret;

		// set some initial values:
		for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

		ret = myset.insert(20);               // no new element inserted

		if (ret.second==false) it=ret.first;  // "it" now points to element 20

		myset.insert (it,25);                 // max efficiency inserting
		myset.insert (it,24);                 // max efficiency inserting
		myset.insert (it,26);                 // no max efficiency inserting

		int myints[]= {5,10,15};              // 10 already in set, not inserted
		myset.insert (myints,myints+3);

		cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); it++)
			cout << " " << *it;
		cout << endl;
	}
	{
		//set::key_comp
		set<int> myset;
		set<int>::key_compare mycomp;
		set<int>::iterator it;
		int i,highest;

		mycomp = myset.key_comp();

		for (i=0; i<=5; i++) myset.insert(i);

		cout << "myset contains:";

		highest=*myset.rbegin();
		it=myset.begin();
		do {
			cout << " " << *it;
		} while ( mycomp(*it++,highest) );	//it = myset.end

		cout << endl;
	}
	{
		//set::value_comp
		set<int> myset;
		set<int>::value_compare mycomp;
		set<int>::iterator it;
		int i,highest;

		mycomp = myset.value_comp();

		for (i=0; i<=5; i++) myset.insert(i);

		cout << "myset contains:";

		highest=*myset.rbegin();
		it=myset.begin();
		do {
			cout << " " << *it;
		} while ( mycomp(*it++,highest) );		//it = myset.end

		cout << endl;
	}
	{
		//set::lower_bound
		//set::upper_bound
		set<int> myset;
		set<int>::iterator it,itlow,itup;

		for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

		itlow=myset.lower_bound (30);                //       ^
		itup=myset.upper_bound (60);                 //                   ^

		myset.erase(itlow,itup);                     // 10 20 70 80 90

		cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); it++)
			cout << " " << *it;
		cout << endl;
	}
	{
		//set::max_size
		int i;
		set<int> myset;

		if (myset.max_size()>1000)
		{
			for (i=0; i<1000; i++) myset.insert(i);
			cout << "The set contains 1000 elements.\n";
		}
		else cout << "The set could not hold 1000 elements.\n";
	}
	{
		//set::operator
		int myints[]={ 12,82,37,64,15 };
		set<int> first (myints,myints+5);   // set with 5 ints
		set<int> second;                    // empty set

		second=first;                       // now second contains the 5 ints
		first=set<int>();                   // and first is empty

		cout << "Size of first: " << int (first.size()) << endl;
		cout << "Size of second: " << int (second.size()) << endl;
	}
	{
		//set::size
		set<int> myints;
		cout << "0. size: " << (int) myints.size() << endl;

		for (int i=0; i<10; i++) myints.insert(i);
		cout << "1. size: " << (int) myints.size() << endl;

		myints.insert (100);
		cout << "2. size: " << (int) myints.size() << endl;

		myints.erase(5);
		cout << "3. size: " << (int) myints.size() << endl;
	}
	{
		//set::swap
		int myints[]={12,75,10,32,20,25};
		set<int> first (myints,myints+3);     // 10,12,75
		set<int> second (myints+3,myints+6);  // 20,25,32
		set<int>::iterator it;

		first.swap(second);

		cout << "first contains:";
		for (it=first.begin(); it!=first.end(); it++) cout << " " << *it;

		cout << "\nsecond contains:";
		for (it=second.begin(); it!=second.end(); it++) cout << " " << *it;

		cout << endl;
	}
	return 0;
}
