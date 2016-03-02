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
			// 가장작은 숫자
		}
	}
	return index_of_min;
}


// 기본 - 함수를 호출하기 시작
template<typename T, int N>
class SelectionSort
{
	public: static void sort( T a[] ) 
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
	int i;

	//////////////////////////////////////////////////////////////////////////
	int arr1[10] = { 10, 4, 11, 6, 7, 9, 1, 32, 9, 64 };	
	for (i=0;i<10;i++) 
		cout << arr1[i] << " "; 
	cout << endl;
	SelectionSort<int, 10>::sort(arr1);
	for (i=0;i<10;i++) 
		cout << arr1[i] << " "; 
	cout << endl;

	//////////////////////////////////////////////////////////////////////////
	double arr2[20] =
	{ 10., 14.3, 11.23, 6.65, 777., 90.1, 1.111, 32.5, 9.12, 64.,
	1.11, 2.33, 50., 34.11, 15.22, 3.4, 11.1, 218., 999., 21. };

	for (i=0;i<20;i++) 
		cout << arr2[i] << " "; 
	cout << endl;
	SelectionSort<double, 20>::sort(arr2);
	for (i=0;i<20;i++) 
		cout << arr2[i] << " "; 
	cout << endl;

	//////////////////////////////////////////////////////////////////////////
	char arr3[7] = { 'D', 'o', 'N', 'g', 'S', 'e', 'O' };
	for (i=0;i<7;i++) 
		cout << arr3[i] << " "; 
	cout << endl;
	SelectionSort<char, 7>::sort(arr3);
	for (i=0;i<7;i++) 
		cout << arr3[i] << " "; 
	cout << endl;

	return 0;
}