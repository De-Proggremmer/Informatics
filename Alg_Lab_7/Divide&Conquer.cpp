#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int low, int pivo, int high)
{
    int n1 = pivo - low + 1;
    int n2 = high - pivo;

    vector<int> lowArr(n1);
    vector<int> highArr(n2);

    for (int i = 0; i < n1; i++) 
    {
        lowArr[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        highArr[j] = arr[pivo + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && lowArr[i] < 0)
    {
        arr[k] = lowArr[i];
        k++; i++;
    }

    while (j < n2 && highArr[j] < 0) 
    {
        arr[k] = highArr[j];
        k++; j++;
    }

    while (i < n1 && lowArr[i] >= 0) 
    {
        arr[k] = lowArr[i];
        k++; i++;
    }

    while (j < n2 && highArr[j] >= 0)
    {
        arr[k] = highArr[j];
        k++; j++;
    }
}

void DivideAndConquer(vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pivo = low + (high - low) / 2;

        DivideAndConquer(arr, low, pivo);
        DivideAndConquer(arr, pivo + 1, high);

        merge(arr, low, pivo, high);
    }
}

int main() 
{
    vector<int> arr = { 1, -2, 3, -4, 5, -6, 7, -8 };

    DivideAndConquer(arr, 0, arr.size()-1);

    for (int i : arr) 
    {
        cout << i << " ";
    }

    return 0;
}