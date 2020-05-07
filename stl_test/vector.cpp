#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main ()
{
	{
		//vector::vector
		unsigned int i;

		// constructors used in the same order as described above:
		vector<int> first;                                // empty vector of ints
		vector<int> second (4,100);                       // four ints with value 100
		vector<int> third (second.begin(),second.end());  // iterating through second
		vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		cout << "The contents of fifth are:";
		for (i=0; i < fifth.size(); i++)
			cout << " " << fifth[i];

		cout << endl;
	}
	{
		//vector::assign
		vector<int> first;
		vector<int> second;
		vector<int> third;

		first.assign (7,100);             // a repetition 7 times of value 100

		vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		cout << "Size of first: " << int (first.size()) << endl;
		cout << "Size of second: " << int (second.size()) << endl;
		cout << "Size of third: " << int (third.size()) << endl;
	}
	{
		//vector::at
		vector<int> myvector (10);   // 10 zero-initialized ints
		unsigned int i;

		// assign some values:
		for (i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		cout << "myvector contains:";
		for (i=0; i<myvector.size(); i++)
			cout << " " << myvector.at(i);

		cout << endl;
	}
	{
		//vector::operator[]
		vector<int> myvector (10);   // 10 zero-initialized elements
		unsigned int i;

		vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		cout << "myvector contains:";
		for (i=0; i<sz; i++)
			cout << " " << myvector[i];

		cout << endl;
	}
	{
		//vector::back
		vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			cout << " " << myvector[i];

		cout << endl;
	}
	{
		//vector::front
		vector<int> myvector;

		myvector.push_back(77);
		myvector.push_back(16);

		// now front equals 77, and back 16

		myvector.front() -= myvector.back();

		cout << "myvector.front() is now " << myvector.front() << endl;
	}
	{
		//vector::begin
		//vector::end
		vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		vector<int>::iterator it;

		cout << "myvector contains:";
		for ( it=myvector.begin() ; it < myvector.end(); it++ )
			cout << " " << *it;

		cout << endl;
	}
	{
		//vector::size			当前大小
		//vector::capacity		容器当前能容纳数量，当容器数量超过这个值后，重新分配存储器，重新分配内存，
								//vector 相关的  reference、pointer、iterator都失效
								//重新分配时很耗时。
								//解决思路：1、Reserve()。保留适当容量。   vector<int> v; v.reverse(200);
								//			2、构造函数创建足够空间       vector<int> v(200);
		//vector::max_size
		vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		cout << "size: " << (int) myvector.size() << "\n";
		cout << "capacity: " << (int) myvector.capacity() << "\n";
		cout << "max_size: " << (int) myvector.max_size() << "\n";
		vector<int>::iterator it = myvector.begin();
		for (int i=0; i<100; i++) myvector.push_back(i);
		//it 失效
	}
	{
		//vector::reserve			cout << hex		cout<<dec;
		vector<int> content;
		size_t filesize;

		ifstream file ("test.bin",ios::in|ios::ate|ios::binary);
		if (file.is_open())
		{
			filesize=file.tellg();

			content.reserve(filesize);

			file.seekg(0);
			while (!file.eof())
			{
				content.push_back( file.get() );
			}

			// print out content:
			vector<int>::iterator it;
			for (it=content.begin() ; it<content.end() ; it++)
				cout << hex << *it;
			cout<<dec;
		}
	}
	{
		//vector::clear
		unsigned int i;
		vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		cout << "myvector contains:";
		for (i=0; i<myvector.size(); i++) cout << " " << myvector[i];

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		cout << "\nmyvector contains:";
		for (i=0; i<myvector.size(); i++) cout << " " << myvector[i];

		cout << endl;
	}
	{
		//vector::empty
		vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		cout << "total: " << sum << endl;
	}
	{
		//vector::erase
		unsigned int i;
		vector<unsigned int> myvector;

		// set some values (from 1 to 10)
		for (i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		cout << "myvector contains:";
		for (i=0; i<myvector.size(); i++)
			cout << " " << myvector[i];
		cout << endl;
	}
	{
		//vector::get_allocator
		vector<int> myvector;
		int * p;
		unsigned int i;

		// allocate an array of 5 elements using vector's allocator:
		p=myvector.get_allocator().allocate(5);

		// assign some values to array
		for (i=0; i<5; i++) p[i]=i;

		cout << "The allocated array contains:";
		for (i=0; i<5; i++) cout << " " << p[i];
		cout << endl;

		myvector.get_allocator().deallocate(p,5);
	}
	{
		//vector::insert
		vector<int> myvector (3,100);
		vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			cout << " " << *it;
		cout << endl;
	}
	{
		//vector::operator=
		vector<int> first (3,0);
		vector<int> second (5,0);

		second=first;
		first=vector<int>();
		
		cout << "Size of first: " << int (first.size()) << endl;
		cout << "Size of second: " << int (second.size()) << endl;
	}
	{
		//vector::push_back
		//vector::pop_back
		vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}

		cout << "The elements of myvector summed " << sum << endl;
	}
	{
		//vector::rbegin
		//vector::rend
		vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		cout << "myvector contains:";
		vector<int>::reverse_iterator rit;
		for ( rit=myvector.rbegin() ; rit < myvector.rend(); ++rit )
			cout << " " << *rit;

		cout << endl;
	}
	{
		//vector::resize
		vector<int> myvector;

		unsigned int i;

		// set some initial content:
		for (i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		cout << "myvector contains:";
		for (i=0;i<myvector.size();i++)
			cout << " " << myvector[i];

		cout << endl;
	}
	{
		//vector::swap
		unsigned int i;
		vector<int> first (3,100);   // three ints with a value of 100
		vector<int> second (5,200);  // five ints with a value of 200

		first.swap(second);

		cout << "first contains:";
		for (i=0; i<first.size(); i++) cout << " " << (int)first[i];

		cout << "\nsecond contains:";
		for (i=0; i<second.size(); i++) cout << " " << (int)second[i];

		cout << endl;
	}
	return 0;
}
