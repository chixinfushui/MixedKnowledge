
#include "stdio.h"
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main1()
{
	{
		// bitset:bitset
		std::bitset<10> first;
		bitset<10> second(121ul);		//unsigned long		1111001     [0] = 1   [1] = 0   [2] = 0  [3] = 1 ...
		bitset<12> third(string("01011"));
		bitset<32> four(string("01011"));
		bitset<33> five(string("01011"));
		int size1 = sizeof(first);
		int size2 = sizeof(second);
		int size3 = sizeof(third);
		int size4 = sizeof(four);		//size4 = 4;      4 Byte inc.   4 Byte   32bit
		int size5 = sizeof(five);		//size5 = 8;      8 Byte 33 bit
	}
	{
		//bitset operators
		bitset<4> first (string("1001"));
		bitset<4> second (string("0011"));

		cout << first << endl;
		cout << (first^=second) << endl;          // 1010 (XOR,assign)
		cout << (first&=second) << endl;          // 0010 (AND,assign)
		cout << (first|=second) << endl;          // 0011 (OR,assign)

		cout << (first<<=2) << endl;              // 1100 (SHL,assign)
		cout << (first>>=1) << endl;              // 0110 (SHR,assign)

		cout << (~second) << endl;                // 1100 (NOT)
		cout << (second<<1) << endl;              // 0110 (SHL)
		cout << (second>>1) << endl;              // 0001 (SHR)

		cout << (first==second) << endl;          // false (0110==0011)
		cout << (first!=second) << endl;          // true  (0110!=0011)

		cout << (first&second) << endl;           // 0010
		cout << (first|second) << endl;           // 0111
		cout << (first^second) << endl;           // 0101
	}
	{
		//bitset::operator[]
		bitset<4> mybits;
		mybits[1]=1;             // 0010
		mybits[2]=mybits[1];     // 0110
		cout << "mybits: " << mybits << endl; 
	}
	{
		//bitset::any
		bitset<16> mybits;

		cout << "enter a binary number: ";
		//cin >> mybits;		//123    ->   0000000000000001
		mybits = 0x55;
		if (mybits.any())
			cout << "mybits has " << (int)mybits.count() << " bits set.\n" << mybits << endl;
		else cout << "mybits has no bits set.\n";
	}
	{
		//bitset::count
		bitset<8> myset (string("10110011"));

		cout << "myset has " << int(myset.count()) << " ones ";
		cout << "and " << int(myset.size()-myset.count()) << " zeros.\n";
	}
	{
		//bitset::flip			改变原有值
		bitset<4> mybits (string("0001"));

		cout << mybits.flip(2) << endl;     // 0101		反转右边从0开始第几位
		cout << mybits.flip() << endl;      // 1010		所有都反转。
		cout << mybits << endl;
	}
	{
		//bitset::none
		bitset<16> mybits;

		cout << "enter a binary number: ";
		//cin >> mybits;
		mybits = 0;

		if (mybits.none())		//0 == true
			cout << "mybits has no bits set.\n";
		else
			cout << "mybits has " << (int)mybits.count() << " bits set.\n";
	}
	{
		//bitset::reset			//与flip类似
		bitset<4> mybits (string("1011"));

		cout << mybits.reset(1) << endl;    // 1001
		cout << mybits.reset() << endl;    // 0000
	}
	{
		//bitset::set
		bitset<4> mybits;
		mybits = 0;
		cout << mybits.set() << endl;       // 1111
		cout << mybits.set(2,0) << endl;    // 1011
		cout << mybits.set(2) << endl;      // 1111
	}
	{
		//bitset::size
		const unsigned int ii = 8;
		bitset<ii> first;
		bitset<3> second;

		cout << "first.size() is " << (int) first.size() << endl;
		cout << "second.size() is " << (int) second.size() << endl;
	}
	{
		//bitset::test
		bitset<5> mybits (string("01011"));

		cout << "mybits contains:\n";
		cout << "before cout<<boolalpha:" << true << endl;
		cout << boolalpha;
		cout << "after cout<<boolalpha:" << true << endl;
		cout << noboolalpha;
		cout << "after cout<<noboolalpha:" << true << endl;
		cout << boolalpha;
		for (size_t i=0; i<mybits.size(); ++i)
			cout << mybits.test(i) << endl;
	}
	{
		//bitset::to_string
		string mystring;
		bitset<4> mybits;     // mybits: 0000

		mybits.set();         // mybits: 1111

		mystring=mybits.to_string<char,char_traits<char>,allocator<char> >();
		//mystring = mybits.to_string();    或
		cout << "mystring: " << mystring << endl;
	}
	{
		//bitset::to_ulong
		bitset<4> mybits;     // mybits: 0000

		mybits.set();         // mybits: 1111

		cout << mybits << " as an integer is: " << mybits.to_ulong() << endl;
	}
	return 0;
}