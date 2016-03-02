/////////////////////////////////////////////////////////////////
// name : jppark 
// ÂüÁ¶ URL : http://www.google.com/codesearch?hl=ko&q=+lang:c%2B%2B+hanoi+template+show:hcNYnwTDD68:ixbNzLKgOr8:msOoP7flOVY&sa=N&cd=1&ct=rc&cs_p=http://www.info.uni-karlsruhe.de/lehre/2004SS/swk/uebung/blatt01-loesung.zip&cs_f=src/hanoi.cpp#l-4
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdlib.h>
using namespace std;

template<int beginPeg, int auxPeg, int endPeg, int n>
class Hanoi 
{
	public: static void move() 
	{
			if( n> 0 )
			{	
				Hanoi<beginPeg, endPeg, auxPeg, n-1>::move();		
				cout << beginPeg << " -> " << endPeg << endl;		
				Hanoi<auxPeg, beginPeg, endPeg, n-1>::move();		
			}
	}
};

template<int beginPeg, int endPeg, int auxPeg>
class Hanoi <beginPeg,endPeg, auxPeg, 0> 
{
	public: static void move() { }
};

int main() 
{
	cout << "Hanoi<1,2,3,5> : " << endl;
	Hanoi<1,2,3,10>::move();

	return 0;
}