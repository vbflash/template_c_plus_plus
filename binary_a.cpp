//////////////////////////////////////////////////////////////////////////
// name : jppark
// ÂüÁ¶ : http://blog.naver.com/itioma?Redirect=Log&logNo=40046289261
//////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

template <unsigned long N>
struct dec2bin;

template <unsigned long N>
struct dec2bin
{
	std::ostream & print(std::ostream & out ) const
	{		
		const int mask = 0x80000000;
		unsigned long n = N;
		int i =32;

		while(i--)
		{
			putchar((n&mask)== 0 ? '0':'1');
			if( (i%8)== 0) 
				putchar(' ');
			n<<=1;			
		}
		return out;
	}
};


template<>
struct dec2bin<1>
{
	std::ostream & print(std::ostream & out ) const
	{
		return out << "1";
	}
};


template<>
struct dec2bin<0>
{
	std::ostream & print(std::ostream & out) const
	{
		return out << "0";
	}
};


template <unsigned long N>
std::ostream & operator<< (std::ostream & out, const dec2bin<N> & desc )
{
	return desc.print(out);
};

int main()
{	
	std::cout << 0 << " : " << dec2bin<0>() << "\n";
	std::cout << 1 << " : " << dec2bin<1>() << "\n";
	std::cout << 2111165535 << " : " << dec2bin<2111165535>() << "\n";
	std::cout << 2147483647 << " : " << dec2bin<2147483647>() << "\n";
	std::cout << 2147483646 << " : " << dec2bin<2147483646>() << "\n";
	return 0;
}
