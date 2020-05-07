#include <iostream>
#include <set>
using namespace std;

bool fncomp_multiset (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const int& lhs, const int& rhs) const
	{return lhs<rhs;}
};

int main7 ()
{
	{
		//multiset::multiset
		multiset<int> first;                          // empty multiset of ints

		int myints[]= {10,20,30,20,20};
		multiset<int> second (myints,myints+5);       // pointers used as iterators

		multiset<int> third (second);                 // a copy of second

		multiset<int> fourth (second.begin(), second.end());  // iterator ctor.

		multiset<int,classcomp> fifth;                // class as Compare

		bool(*fn_pt)(int,int) = fncomp_multiset;
		multiset<int,bool(*)(int,int)> sixth (fn_pt); // function pointer as Compare
	}
	{
		//multiset::begin
		//multiset::end
		int myints[] = {42,71,71,71,12};
		multiset<int> mymultiset (myints,myints+5);

		multiset<int>::iterator it;

		cout << "mymultiset contains:";
		for ( it=mymultiset.begin() ; it != mymultiset.end(); it++ )
			cout << " " << *it;

		cout << endl;
	}
	{
		//multiset::rbegin
		//multiset::rend
		int myints[] = {77,16,2,30,30};
		multiset<int> mymultiset (myints,myints+5);

		multiset<int>::reverse_iterator rit;

		cout << "mymultiset contains:";
		for ( rit=mymultiset.rbegin() ; rit != mymultiset.rend(); rit++ )
			cout << " " << *rit;

		cout << endl;
	}
	{
		//multiset::clear
		multiset<int> mymultiset;
		multiset<int>::iterator it;

		mymultiset.insert (11);
		mymultiset.insert (42);
		mymultiset.insert (11);

		cout << "mymultiset contains:";
		for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
			cout << " " << *it;

		mymultiset.clear();
		mymultiset.insert (200);
		mymultiset.insert (100);

		cout << "\nmymultiset contains:";
		for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
			cout << " " << *it;

		cout << endl;
	}
	{
		//multiset::count
		int myints[]={10,73,12,22,73,73,12};
		multiset<int> mymultiset (myints,myints+7);

		cout << "73 appears ";
		cout << (int) mymultiset.count(73);
		cout << " times in mymultiset." << endl;
	}
	{
		//multiset::empty
		multiset<int> mymultiset;

		mymultiset.insert(10);
		mymultiset.insert(20);
		mymultiset.insert(10);

		cout << "mymultiset contains:";
		while (!mymultiset.empty())
		{
			cout << " " << *mymultiset.begin();
			mymultiset.erase(mymultiset.begin());
		}
		cout << endl;
	}
	{
		//multiset::equal_range
		multiset<int>::iterator it;
		pair<multiset<int>::iterator,multiset<int>::iterator> ret;

		int myints[]= {77,30,16,2,30,30};
		multiset<int> mymultiset (myints, myints+6); // 2 16 30 30 30 77

		ret = mymultiset.equal_range(30);            //      ^        ^

		for (it=ret.first; it!=ret.second; )
			it = mymultiset.erase(it);                                   // 2 16 77

		cout << "mymultiset contains:";
		for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
			cout << " " << *it;
		cout << endl;
	}
	{
		//multiset::erase
		multiset<int> mymultiset;
		multiset<int>::iterator it;

		// insert some values:
		mymultiset.insert (40);                            // 40
		for (int i=1; i<7; i++) mymultiset.insert(i*10);   // 10 20 30 40 40 50 60

		it=mymultiset.begin();
		it++;                                              //    ^

		mymultiset.erase (it);                             // 10 30 40 40 50 60

		mymultiset.erase (40);                             // 10 30 50 60

		it=mymultiset.find (50);
		mymultiset.erase ( it, mymultiset.end() );         // 10 30

		cout << "mymultiset contains:";
		for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
			cout << " " << *it;
		cout << endl;
	}
	{
		//multiset::find
		multiset<int> mymultiset;
		multiset<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; i++) mymultiset.insert(i*10);   // 10 20 30 40 50

		it=mymultiset.find(20);
		mymultiset.erase (it);
		mymultiset.erase (mymultiset.find(40));

		cout << "mymultiset contains:";
		for (it=mymultiset.begin(); it!=mymultiset.end(); it++)
			cout << " " << *it;
		cout << endl;
	}
	{
		//multiset::get_allocator
		multiset<int> mymultiset;
		int * p;
		unsigned int i;

		// allocate an array of 5 elements using myset's allocator:
		p=mymultiset.get_allocator().allocate(5);

		// assign some values to array
		for (i=0; i<5; i++) p[i]=(i+1)*10;

		cout << "The allocated array contains:";
		for (i=0; i<5; i++) cout << " " << p[i];
		cout << endl;

		mymultiset.get_allocator().deallocate(p,5);

	}
	{
		//multiset::insert
		multiset<int> mymultiset;
		multiset<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; i++) mymultiset.insert(i*10);  // 10 20 30 40 50

		it=mymultiset.insert(25);

		it=mymultiset.insert (it,27);    // max efficiency inserting
		it=mymultiset.insert (it,29);    // max efficiency inserting
		it=mymultiset.insert (it,24);    // no max efficiency inserting (24<29)

		int myints[]= {5,10,15};
		mymultiset.insert (myints,myints+3);

		cout << "mymultiset contains:";
		for (it=mymultiset.begin(); it!=mymultiset.end(); it++)
			cout << " " << *it;
		cout << endl;
	}
	{
		//multiset::key_comp
		multiset<int> mymultiset;
		multiset<int>::key_compare mycomp;
		multiset<int>::iterator it;
		int i,highest;

		mycomp = mymultiset.key_comp();

		for (i=0; i<=5; i++) mymultiset.insert(i);
		mymultiset.insert(5);
		mymultiset.insert(5);
		cout << "mymultiset contains:";

		highest=*mymultiset.rbegin();
		it=mymultiset.begin();
		do {
			cout << " " << *it;
		} while ( mycomp(*it++,highest) ); //it !=set.end   what the fuck!!!

		cout << endl;
	}
	{
		//multiset::value_comp
		multiset<int> mymultiset;
		multiset<int>::value_compare mycomp;
		multiset<int>::iterator it;
		int i,highest;

		mycomp = mymultiset.value_comp();

		for (i=0; i<=5; i++) mymultiset.insert(i);
		mymultiset.insert(5);
		mymultiset.insert(5);
		cout << "mymultiset contains:";

		highest=*mymultiset.rbegin();
		it=mymultiset.begin();
		do {
			cout << " " << *it;
		} while ( mycomp(*it++,highest) );//it !=set.end   what the fuck!!!

		cout << endl;
	}
	{
		//multiset::lower_bound
		//multiset::upper_bound
		multiset<int> mymultiset;
		multiset<int>::iterator it,itlow,itup;

		for (int i=1; i<8; i++) mymultiset.insert(i*10); // 10 20 30 40 50 60 70

		itlow=mymultiset.lower_bound (30);               //       ^
		itup=mymultiset.upper_bound (40);                //              ^

		mymultiset.erase(itlow,itup);                    // 10 20 50 60 70

		cout << "mymultiset contains:";
		for (it=mymultiset.begin(); it!=mymultiset.end(); it++)
			cout << " " << *it;
		cout << endl;
	}
	{
		//multiset::max_size
		int i;
		multiset<int> mymultiset;

		if (mymultiset.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymultiset.insert(i);
			cout << "The multiset contains 1000 elements.\n";
		}
		else cout << "The multiset could not hold 1000 elements.\n";
	}
	{
		//multiset::operator=
		int myints[]={ 19,81,36,36,19 };
		multiset<int> first (myints,myints+5);   // multiset with 5 ints
		multiset<int> second;                    // empty multiset

		second=first;                            // now second contains the 5 ints
		first=multiset<int>();                   // and first is empty

		cout << "Size of first: " << int (first.size()) << endl;
		cout << "Size of second: " << int (second.size()) << endl;
	}
	{
		//multiset::size
		multiset<int> myints;
		cout << "0. size: " << (int) myints.size() << endl;

		for (int i=0; i<10; i++) myints.insert(i);
		cout << "1. size: " << (int) myints.size() << endl;

		myints.insert (5);
		cout << "2. size: " << (int) myints.size() << endl;

		myints.erase (5);
		cout << "3. size: " << (int) myints.size() << endl;
	}
	{
		//multiset::swap
		int myints[]={19,72,4,36,20,20};
		multiset<int> first (myints,myints+3);     // 4,19,72
		multiset<int> second (myints+3,myints+6);  // 20,20,36
		multiset<int>::iterator it;

		first.swap(second);

		cout << "first contains:";
		for (it=first.begin(); it!=first.end(); it++) cout << " " << *it;

		cout << "\nsecond contains:";
		for (it=second.begin(); it!=second.end(); it++) cout << " " << *it;

		cout << endl;
	}
	return 0;
}
