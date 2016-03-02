//////////////////////////////////////////////////////////////////////////
// 학번 : 20041548
// 이름 : 박정필
// 분반 : E13
// 문제 : Binary ( 이진수 -> 십진수)
// 시간 : 
// 참조 : [Book] C++ Template Metaprogramming
//////////////////////////////////////////////////////////////////////////
#include <iostream>

template <unsigned long N>
struct bin2dec
{
	static unsigned const value = bin2dec<N/10>::value *2 + N%10;
};

template<>
struct bin2dec<0>
{
	static unsigned const value = 0;
};

int main()
{
	std::cout << "0" << " : " << bin2dec<0>::value << "\n";
	std::cout << "1" << " : " << bin2dec<1>::value << "\n";
	std::cout << "111" << " : " << bin2dec<111>::value << "\n";
	std::cout << "110011" << " : " << bin2dec<110011>::value << "\n";
	std::cout << "1100111" << " : " << bin2dec<1100111>::value << "\n";
	return 0;
}