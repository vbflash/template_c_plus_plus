//////////////////////////////////////////////////////////////////////////
// 학번 : 20041548
// 이름 : 박정필
// 분반 : E13
// 문제 : Binary ( 십진수 -> 이진수)
// 시간 : 
// 참조 : http://blog.naver.com/itioma?Redirect=Log&logNo=40046289261 의 알고리즘과
//        문제 4번의 출력방식을 이용하였습니다.
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
				putchar(' ');	// 보기 쉽도록 1바이트(8비트) 단위로 띄어쓰기
			n<<=1;				// 왼쪽으로 1비트 shift
		}
		return out;
	}
};

// 1 일때
template<>
struct dec2bin<1>
{
	std::ostream & print(std::ostream & out ) const
	{
		return out << "1";
	}
};

// 0 일때
template<>
struct dec2bin<0>
{
	std::ostream & print(std::ostream & out) const
	{
		return out << "0";
	}
};

//출력
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
