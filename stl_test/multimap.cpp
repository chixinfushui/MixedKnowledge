#include <iostream>
#include <map>
using namespace std;

bool fncomp_multimap (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

int main5 ()
{
	{
		//multimap::multimap
		multimap<char,int> first;

		first.insert(pair<char,int>('a',10));
		first.insert(pair<char,int>('b',15));
		first.insert(pair<char,int>('b',20));
		first.insert(pair<char,int>('c',25));

		multimap<char,int> second (first.begin(),first.end());

		multimap<char,int> third (second);

		multimap<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp_multimap;
		multimap<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as comp
	}
	{
		//multimap::begin
		//multimap::end
		multimap<char,int> mymultimap;
		multimap<char,int>::iterator it;

		mymultimap.insert (pair<char,int>('a',10));
		mymultimap.insert (pair<char,int>('b',20));
		mymultimap.insert (pair<char,int>('b',150));

		// show content:
		for ( it=mymultimap.begin() ; it != mymultimap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;
	}
	{
		//multimap::rbegin
		//multimap::rend
		multimap<char,int> mymultimap;
		multimap<char,int>::reverse_iterator rit;

		mymultimap.insert (pair<char,int>('x',10));
		mymultimap.insert (pair<char,int>('y',20));
		mymultimap.insert (pair<char,int>('y',150));
		mymultimap.insert (pair<char,int>('z',9));

		// show content:
		for ( rit=mymultimap.rbegin() ; rit != mymultimap.rend(); rit++ )
			cout << rit->first << " => " << rit->second << endl;
	}
	{
		//multimap::clear
		multimap<char,int> mymultimap;
		multimap<char,int>::iterator it;

		mymultimap.insert(pair<char,int>('b',80));
		mymultimap.insert(pair<char,int>('b',120));
		mymultimap.insert(pair<char,int>('q',360));

		cout << "mymultimap contains:\n";
		for ( it=mymultimap.begin() ; it != mymultimap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;

		mymultimap.clear();

		mymultimap.insert(pair<char,int>('a',11));
		mymultimap.insert(pair<char,int>('x',22));

		cout << "mymultimap contains:\n";
		for ( it=mymultimap.begin() ; it != mymultimap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;
	}
	{
		//multimap::count
		multimap<char,int> mymm;
		multimap<char,int>::iterator it;
		char c;

		mymm.insert(pair<char,int>('x',50));
		mymm.insert(pair<char,int>('y',100));
		mymm.insert(pair<char,int>('y',150));
		mymm.insert(pair<char,int>('y',200));
		mymm.insert(pair<char,int>('z',250));
		mymm.insert(pair<char,int>('z',300));

		for (c='x'; c<='z'; c++)
		{
			cout << "There are " << (int)mymm.count(c);
			cout << " elements with key " << c << ":";
			for (it=mymm.equal_range(c).first; it!=mymm.equal_range(c).second; ++it)
				cout << " " << (*it).second;
			cout << endl;
		}
	}
	{
		//multimap::empty
		multimap<char,int> mymultimap;

		mymultimap.insert (pair<char,int>('b',101));
		mymultimap.insert (pair<char,int>('b',202));
		mymultimap.insert (pair<char,int>('q',505));

		while (!mymultimap.empty())
		{
			cout << mymultimap.begin()->first << " => ";
			cout << mymultimap.begin()->second << endl;
			mymultimap.erase(mymultimap.begin());
		}
	}
	{/*****************************************************/
		//multimap::equal_range
		multimap<char,int> mymm;
		multimap<char,int>::iterator it;
		pair<multimap<char,int>::iterator,multimap<char,int>::iterator> ret;

		mymm.insert(pair<char,int>('a',10));
		mymm.insert(pair<char,int>('b',20));
		mymm.insert(pair<char,int>('b',30));
		mymm.insert(pair<char,int>('b',40));
		mymm.insert(pair<char,int>('c',50));
		mymm.insert(pair<char,int>('c',60));
		mymm.insert(pair<char,int>('d',60));

		cout << "mymm contains:\n";
		for (char ch='a'; ch<='d'; ch++)
		{
			cout << ch << " =>";
			ret = mymm.equal_range(ch);
			for (it=ret.first; it!=ret.second; ++it)
				cout << " " << (*it).second;
			cout << endl;
		}
	}
	{/*****************************************************/
		//multimap::find
		multimap<char,int> mymm;
		multimap<char,int>::iterator it;

		mymm.insert (pair<char,int>('x',10));
		mymm.insert (pair<char,int>('y',20));
		mymm.insert (pair<char,int>('z',30));
		mymm.insert (pair<char,int>('z',40));

		it=mymm.find('x');
		mymm.erase (it);
		mymm.erase (mymm.find('z'));

		// print content:
		cout << "elements in mymm:" << endl;
		cout << "y => " << mymm.find('y')->second << endl;
		cout << "z => " << mymm.find('z')->second << endl;
	}
	{/*****************************************************/
		//multimap::erase
		multimap<char,int> mymultimap;
		multimap<char,int>::iterator it;

		// insert some values:
		mymultimap.insert(pair<char,int>('a',10));
		mymultimap.insert(pair<char,int>('b',20));
		mymultimap.insert(pair<char,int>('b',30));
		mymultimap.insert(pair<char,int>('c',40));
		mymultimap.insert(pair<char,int>('d',50));
		mymultimap.insert(pair<char,int>('d',60));
		mymultimap.insert(pair<char,int>('e',70));
		mymultimap.insert(pair<char,int>('f',80));

		it=mymultimap.find('b');
		mymultimap.erase (it);                     // erasing by iterator (1 element)

		mymultimap.erase ('d');                    // erasing by key (2 elements)

		it=mymultimap.find ('e');
		mymultimap.erase ( it, mymultimap.end() ); // erasing by range

		// show content:
		for ( it=mymultimap.begin() ; it != mymultimap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;
	}
	{
		//multimap::get_allocator
		int psize;
		multimap<char,int> mymultimap;
		pair<const char,int>* p;

		// allocate an array of 5 elements using mymap's allocator:
		p=mymultimap.get_allocator().allocate(5);

		// assign some values to array
		psize = (int) sizeof(multimap<char,int>::value_type)*5;

		cout << "The allocated array has a size of " << psize << " bytes.\n";

		mymultimap.get_allocator().deallocate(p,5);

	}
	{
		//multimap::insert
		multimap<char,int> mymultimap;
		multimap<char,int>::iterator it;

		// first insert function version (single parameter):
		mymultimap.insert ( pair<char,int>('a',100) );
		mymultimap.insert ( pair<char,int>('z',150) ); 
		it=mymultimap.insert ( pair<char,int>('b',75) );

		// second insert function version (with hint position):
		mymultimap.insert (it, pair<char,int>('c',300));  // max efficiency inserting
		mymultimap.insert (it, pair<char,int>('z',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		multimap<char,int> anothermultimap;
		anothermultimap.insert(mymultimap.begin(),mymultimap.find('c'));

		// showing contents:
		cout << "mymultimap contains:\n";
		for ( it=mymultimap.begin() ; it != mymultimap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;

		cout << "anothermultimap contains:\n";
		for ( it=anothermultimap.begin() ; it != anothermultimap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;
	}
	{/*****************************************************/
		//multimap::key_comp
		multimap<char,int> mymultimap;
		multimap<char,int>::key_compare mycomp;
		multimap<char,int>::iterator it;
		char highest;

		mycomp = mymultimap.key_comp();

		mymultimap.insert (pair<char,int>('a',100));
		mymultimap.insert (pair<char,int>('b',200));
		mymultimap.insert (pair<char,int>('b',211));
		mymultimap.insert (pair<char,int>('c',300));
		mymultimap.insert (pair<char,int>('c',400));
		cout << "mymultimap contains:\n";

		highest=mymultimap.rbegin()->first;     // key value of last element

		it=mymultimap.begin();
		do {
			cout << (*it).first << " => " << (*it).second << endl;
		} while ( mycomp((*it++).first, highest) );    //it   ==  (c, 400)     != map.end

		cout << endl;
	}
	{/*****************************************************/
		//multimap::value_comp
		multimap<char,int> mymultimap;
		multimap<char,int>::iterator it;
		pair<char,int> highest;

		mymultimap.insert(pair<char,int>('x',101));
		mymultimap.insert(pair<char,int>('y',202));
		mymultimap.insert(pair<char,int>('y',252));
		mymultimap.insert(pair<char,int>('z',303));
		mymultimap.insert(pair<char,int>('z',403));
		mymultimap.insert(pair<char,int>('z',203));
		cout << "mymultimap contains:\n";

		highest=*mymultimap.rbegin();          // last element

		it=mymultimap.begin();
		do {
			cout << (*it).first << " => " << (*it).second << endl;
		} while ( mymultimap.value_comp()(*it++, highest) ); //it   ==  (z, 403)     != map.end
															//what the fuck!
	}
	{/*****************************************************/
		//multimap::lower_bound
		//multimap::upper_bound
		multimap<char,int> mymultimap;
		multimap<char,int>::iterator it,itlow,itup;

		mymultimap.insert(pair<char,int>('a',10));
		mymultimap.insert(pair<char,int>('b',121));
		mymultimap.insert(pair<char,int>('c',1001));
		mymultimap.insert(pair<char,int>('c',2002));
		mymultimap.insert(pair<char,int>('d',11011));
		mymultimap.insert(pair<char,int>('e',44));

		itlow=mymultimap.lower_bound ('b');  // itlow points to b
		itup=mymultimap.upper_bound ('d');   // itup points to e (not d)

		// print range [itlow,itup):
		for ( it=itlow ; it != itup; it++ )
			cout << (*it).first << " => " << (*it).second << endl;
	}
	{
		//multimap::max_size
		int i;
		multimap<int,int> mymultimap;
		long x = mymultimap.max_size();
		if (mymultimap.max_size()>1000)
		{
			for (i=0; i<1000; i++)
				mymultimap.insert(pair<int,int>(i,0));
			cout << "The multimap contains 1000 elements.\n";
		}
		else cout << "The multimap could not hold 1000 elements.\n";
	}
	{
		//multimap::operator=
		multimap<char,int> first;
		multimap<char,int> second;

		first.insert(pair<char,int>('x',32));
		first.insert(pair<char,int>('y',64));
		first.insert(pair<char,int>('y',96));
		first.insert(pair<char,int>('z',128));

		second=first;                // second now contains 4 ints
		first=multimap<char,int>();  // and first is now empty

		cout << "Size of first: " << int (first.size()) << endl;
		cout << "Size of second: " << int (second.size()) << endl;
	}
	{
		//multimap::size
		multimap<char,int> mymultimap;

		mymultimap.insert(pair<char,int>('x',100));
		mymultimap.insert(pair<char,int>('y',200));
		mymultimap.insert(pair<char,int>('y',350));
		mymultimap.insert(pair<char,int>('z',500));

		cout << "mymultimap.size() is " << (int) mymultimap.size() << endl;
	}
	{
		//multimap::swap
		multimap<char,int> foo;
		multimap<char,int> bar;
		multimap<char,int>::iterator it;

		foo.insert(pair<char,int>('x',100));
		foo.insert(pair<char,int>('y',200));

		bar.insert(pair<char,int>('a',11));
		bar.insert(pair<char,int>('b',22));
		bar.insert(pair<char,int>('a',55));

		foo.swap(bar);

		cout << "foo contains:\n";
		for ( it=foo.begin() ; it != foo.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;

		cout << "bar contains:\n";
		for ( it=bar.begin() ; it != bar.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;
	}
	return 0;
}
