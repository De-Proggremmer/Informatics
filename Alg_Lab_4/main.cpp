#include <vector>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>  


using namespace std;


void quick_sort(vector<int>& arr, int low, int high);
void quick_sort_parallel(vector<int>& arr, int low, int high, int num_threads);


vector<int> randVec(int len, int Up)
{
	vector<int> vec(len);

	for (int i = 0; i < len; i++)
	{
		vec[i] = rand() % Up;
	}

	return vec;
}


int main()
{
	srand(time(0));

	vector<int> sizes = { 1000000, 2000000, 3000000, 4000000,
					 5000000, 6000000, 7000000, 8000000,
					 9000000, 10000000 };

	for (int N : sizes) {
		vector<int> arr0 = randVec(N, 100000);


		vector<int> arr1 = arr0;
		vector<int> arr2 = arr0;
		vector<int> arr3 = arr0;
		vector<int> arr4 = arr0;

		auto now = chrono::high_resolution_clock::now();
		quick_sort(arr1, 0, N - 1);
		cout << (chrono::duration_cast<std::chrono::milliseconds>(chrono::high_resolution_clock::now() - now)).count() << "   ";
		now = chrono::high_resolution_clock::now();
		quick_sort_parallel(arr2, 0, N - 1, 2);
		cout << (chrono::duration_cast<std::chrono::milliseconds>(chrono::high_resolution_clock::now() - now)).count() << "   ";
		now = chrono::high_resolution_clock::now();
		quick_sort_parallel(arr3, 0, N - 1, 4);
		cout << (chrono::duration_cast<std::chrono::milliseconds>(chrono::high_resolution_clock::now() - now)).count() << "   ";
		now = chrono::high_resolution_clock::now();
		quick_sort_parallel(arr4, 0, N - 1, 8);
		cout << (chrono::duration_cast<std::chrono::milliseconds>(chrono::high_resolution_clock::now() - now)).count() << endl;
	}


	return 0;
}


// normal sort
int divide(vector<int>& arr, int low, int high)
{
	int pivo = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivo)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);

	return i + 1;
}

void quick_sort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pivo = divide(arr, low, high);
		quick_sort(arr, low, pivo - 1);
		quick_sort(arr, pivo + 1, high);
	}
}


// parallel sort
void quick_sort_parallel(vector<int>& arr, int low, int high, int num_threads)
{
	if (num_threads <= 1 || high - low < 100000) {
		quick_sort(arr, low, high);
		return;
	}

	int pivo = divide(arr, low, high);

	thread L(quick_sort_parallel, ref(arr), low, pivo - 1, num_threads / 2);
	thread H(quick_sort_parallel, ref(arr), pivo + 1, high, num_threads / 2);

	L.join();
	H.join();
}