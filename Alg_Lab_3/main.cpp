#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>  
#include <xutility>

using namespace std;

void radix_sort(vector<int>& arr);
void bubble_sort(vector<int>& arr);
void quick_sort(vector<int>& arr, int low, int high);


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

	vector<int> arr1 = randVec(20, 100);
	vector<int> arr2 = randVec(20, 100);
	vector<int> arr3 = randVec(20, 100);

	for (int i = 0; i < 20; i++)
	{
		cout << arr1[i] << "   " << arr2[i] << "   " << arr3[i] << endl;
	}

	radix_sort(arr1);
	bubble_sort(arr2);
	quick_sort(arr3, 0, 19);

	cout << "\n --- sorted --- \n";

	for (int i = 0; i < 20; i++)
	{
		cout << arr1[i] << "   " << arr2[i] << "   " << arr3[i] << endl;
	}

	return 0;
}


// ------------------ Поразрядная сортировка ------------------------

vector<int> merge_buckets(vector<vector<int>> buckets)
{
	vector<int> merged;

	for (auto bucket : buckets)
	{
		merged.insert(merged.end(), bucket.begin(), bucket.end());
	}

	return merged;
}


void sort_by_rad(vector<int>& arr, int rad)
{
	vector<vector<int>> buckets(10);

	for (int i : arr)
	{
		int bucket_ind = (i / rad) % 10;
		buckets[bucket_ind].push_back(i);
	}

	arr = merge_buckets(buckets);
}

void radix_sort(vector<int>& arr)
{
	if (arr.empty()) { return; }
	int mx = *max_element(arr.begin(), arr.end());
	int rad = 1;

	while (mx / rad > 0)
	{
		sort_by_rad(arr, rad);
		rad *= 10;
	}

}

// --------------------- Пузырьковая сортировка ----------------------

void bubble_sort(vector<int>& arr)
{
	const int N = arr.size();

	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < N - 1 - i; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

// ----------------------- Быстрая сортировка ---------------------------

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
	swap(arr[i+1], arr[high]);

	return i + 1;
}

void quick_sort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pivo = divide(arr, low, high);
		quick_sort(arr, low, pivo-1);
		quick_sort(arr, pivo+1, high);
	}
}