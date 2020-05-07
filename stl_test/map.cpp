#include "stdio.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cctype>
#include <cmath>
#include <map>
using namespace std;

bool fncomp_map (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

int main4()
{
	{
		//map::map
		map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;

		map<char,int> second (first.begin(),first.end());

		map<char,int> third (second);

		map<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp_map;
		map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	}
	{
		//map::begin
		//map::end
		map<char,int> mymap;
		map<char,int>::iterator it;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for ( it=mymap.begin() ; it != mymap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;
	}
	{
		//map::rbegin
		//map::rend
		map<char,int> mymap;
		map<char,int>::reverse_iterator rit;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		for ( rit=mymap.rbegin() ; rit != mymap.rend(); rit++ )
			cout << rit->first << " => " << rit->second << endl;
	}
	{
		//map::clear
		map<char,int> mymap;
		map<char,int>::iterator it;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		cout << "mymap contains:\n";
		for ( it=mymap.begin() ; it != mymap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		cout << "mymap contains:\n";
		for ( it=mymap.begin() ; it != mymap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;
	}
	{
		//map::count
		map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			cout << c;
			if (mymap.count(c)>0)
				cout << " is an element of mymap.\n";
			else 
				cout << " is not an element of mymap.\n";
		}
	}
	{
		//map::empty
		map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			cout << mymap.begin()->first << " => ";
			cout << mymap.begin()->second << endl;
			mymap.erase(mymap.begin());
		}
	}
	{/*****************************************/
		//map::equal_range
		map<char,int> mymap;
		pair<map<char,int>::iterator,map<char,int>::iterator> ret;

		mymap['a']=10;
		mymap['b']=20;
		mymap['b']=25;
		mymap['c']=30;

		ret = mymap.equal_range('b');

		cout << "lower bound points to: ";
		cout << ret.first->first << " => " << ret.first->second << endl;

		cout << "upper bound points to: ";
		cout << ret.second->first << " => " << ret.second->second << endl;
	}
	{/*****************************************/
		//map::erase
		map<char,int> mymap;
		map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('x');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for ( it=mymap.begin() ; it != mymap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;
	}
	{
		//map::find
		map<char,int> mymap;
		map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it=mymap.find('b');
		mymap.erase (it);
		mymap.erase (mymap.find('d'));

		// print content:
		cout << "elements in mymap:" << endl;
		cout << "a => " << mymap.find('a')->second << endl;
		cout << "c => " << mymap.find('c')->second << endl;
	}
	{
		//map::get_allocator
		int psize;
		map<char,int> mymap;
		pair<const char,int>* p;

		// allocate an array of 5 elements using mymap's allocator:
		p=mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = (int) sizeof(map<char,int>::value_type)*5;

		cout << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p,5);
	}
	{/*****************************************/
		//map::insert
		map<char,int> mymap;
		map<char,int>::iterator it;
		pair<map<char,int>::iterator,bool> ret;

		// first insert function version (single parameter):
		mymap.insert ( pair<char,int>('a',100) );
		//mymap.insert ( pair<char,int>('z',200) );
		mymap.insert ( make_pair('z',200) );
		ret=mymap.insert (pair<char,int>('z',500) ); 
		if (ret.second==false)
		{
			cout << "element 'z' already existed";
			cout << " with a value of " << ret.first->second << endl;
		}
		mymap['z'] = 300;
		// second insert function version (with hint position):
		it=mymap.begin();
		mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		cout << "mymap contains:\n";
		for ( it=mymap.begin() ; it != mymap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;

		cout << "anothermap contains:\n";
		for ( it=anothermap.begin() ; it != anothermap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;
	}
	{/*****************************************/
		//map::key_comp
		map<char,int> mymap;
		map<char,int>::key_compare mycomp;
		map<char,int>::iterator it;
		char highest;

		mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		cout << "mymap contains:\n";

		highest=mymap.rbegin()->first;     // key value of last element

		it=mymap.begin();
		do {
			cout << (*it).first << " => " << (*it).second << endl;
		} while ( mycomp((*it++).first, highest) );

		cout << endl;
	}
	{/*****************************************/
		//map::value_comp
		map<char,int> mymap;
		map<char,int>::iterator it;
		pair<char,int> highest;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		cout << "mymap contains:\n";

		highest=*mymap.rbegin();          // last element

		it=mymap.begin();
		do {
			cout << (*it).first << " => " << (*it).second << endl;
		} while ( mymap.value_comp()(*it++, highest) );	//最后退出是，it == map.end
	}
	{/*****************************************/
		//map::lower_bound
		//map::upper_bound
		map<char,int> mymap;
		map<char,int>::iterator it,itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for ( it=mymap.begin() ; it != mymap.end(); it++ )
			cout << (*it).first << " => " << (*it).second << endl;
	}
	{
		//map::max_size
		int i;
		map<int,int> mymap;
		long x = mymap.max_size();
		if (mymap.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
			cout << "The map contains 1000 elements.\n";
		}
		else cout << "The map could not hold 1000 elements.\n";
	}
	{
		//map::operator=
		map<char,int> first;
		map<char,int> second;

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;           // second now contains 3 ints
		//first=map<char,int>();  // and first is now empty
		first.clear();		//相同效果
		cout << "Size of first: " << int (first.size()) << endl;
		cout << "Size of second: " << int (second.size()) << endl;
	}
	{
		//map::operator[]
		map<char,string> mymap;
		map<char,string>::iterator it;

		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];

		cout << "mymap['a'] is " << mymap['a'] << endl;
		cout << "mymap['b'] is " << mymap['b'] << endl;
		cout << "mymap['c'] is " << mymap['c'] << endl;
		cout << "mymap['d'] is " << mymap['d'] << endl;

		cout << "mymap now contains " << (int) mymap.size() << " elements." << endl;
	}
	{
		//map::size
		map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		cout << "mymap.size() is " << (int) mymap.size() << endl;
	}
	{
		//map::swap
		map<char,int> foo;
		map<char,int> bar;
		map<char,int>::iterator it;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

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