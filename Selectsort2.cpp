/////////////////////////////////////////////////////////////////
// name : jppark 
/////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

template<class T>
void swap_values( T& variable1, T& variable2 )
{
	T temp;
	temp = variable1;
	variable1 = variable2;
	variable2 = temp;
}

// 가장작은 숫자를 검색하여 반환
template<class BaseType>
int index_of_smailest( const BaseType a[], int start_index, int number_used )
{
	BaseType min = a[start_index];
	int index_of_min = start_index;

	for( int index = start_index+1; index < number_used; index++ )
	{
		if( a[index] < min )
		{
			min = a[index];
			index_of_min = index;			
		}
	}
	return index_of_min;
}

// 기본 - 함수를 호출하기 시작
template<int N>
class SelectionSort
{
	public: static void sort( int a[] ) 
	{
		int index_of_next_smallest;
		if( N > 0 )
		{
			for( int index=0; index<N-1; index++ )
			{
				index_of_next_smallest = index_of_smailest( a, index, N );
				swap_values( a[index], a[index_of_next_smallest]);
			}			
		}
	}
};

int main()
{
	int arr1[10] = { 10, 4, 11, 6, 7, 9, 1, 32, 9, 64 };
	for (int i=0;i<10;i++) 
		cout << arr1[i] << " "; 		
	cout << endl;

	SelectionSort<10>::sort(arr1);

	for (int i=0;i<10;i++) 
		cout << arr1[i] << " "; 
	cout << endl;

	return 0;
}