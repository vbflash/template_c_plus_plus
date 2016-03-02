/////////////////////////////////////////////////////////////////
// name : jppark 
// 참조 : //http://blog.naver.com/blue7red?Redirect=Log&logNo=100042183231
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstddef>

template <typename T>
struct type_printer;

// 포인터형
template<typename T>
struct type_printer<T *>
{
	std::ostream & print(std::ostream & out ) const
	{
		return out << type_printer<T>() << " *";
	}
};

// 참조형
template<typename T>
struct type_printer<T &>
{
	std::ostream & print(std::ostream & out ) const
	{
		return out << type_printer<T>() << " &";
	}
};

// 배열
template<typename T, std::size_t N>
struct type_printer<T[N]>
{
	std::ostream & print(std::ostream & out ) const
	{
		return out << type_printer<T>() << " [" << N << "]";
	}

};

template<typename T>
struct type_printer<const T>
{
	std::ostream & print(std::ostream & out ) const
	{
		return out << type_printer<T>() << " const";
	}
};

template<typename T>
struct type_printer<volatile T>
{
	std::ostream & print(std::ostream & out ) const
	{
		return out << type_printer<T>() << " volatile";
	}
};

template<>
struct type_printer<int>
{
	std::ostream & print(std::ostream & out ) const
	{
		return out << "int";
	}
};

template<>
struct type_printer<char>
{
	std::ostream & print(std::ostream & out ) const
	{
		return out << "char";
	}
};

template<>
struct type_printer<long>
{
	std::ostream & print(std::ostream & out ) const
	{
		return out << "long";
	}
};

template<>
struct type_printer<short>
{
	std::ostream & print(std::ostream & out ) const
	{
		return out << "short";
	}
};

//출력
template<typename T>
std::ostream & operator<< (std::ostream & out, const type_printer<T> & desc )
{
	return desc.print(out);
};

int main()
{
	std:: cout	<< type_printer<int>()					<< "\n"
				<< type_printer<char *>()				<< "\n"
				<< type_printer<long const * &>()		<< "\n"
				<< type_printer<short[10]>()			<< "\n"
				<< type_printer<volatile int>()			<< "\n";
	return 0;
}


