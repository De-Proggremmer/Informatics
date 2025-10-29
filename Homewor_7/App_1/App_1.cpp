#include <iostream>

void count_below(int* A, int* B, int t);
void printArr(const int* Arr);

int main()
{
	int *A = new int[5], *B = new int[5];
	int t = 0;
	std::cout << "Enter arr elements: ";

	for (int i = 0; i < 5; i++)
	{
		std::cin >> A[i];
	}

	for (int i = 0; i < 5; i++)
	{
		std::cin >> B[i];
	}

	std::cout << "Enter t: ";
	std::cin >> t;

	count_below(A, B, t);

	delete A;
	delete B;

	return 0;
}

void count_below(int* A, int* B, int t)
{
	int cntA = 0, cntB = 0;
	for (int i = 0; i < 5; i++)
	{
		if (A[i] < t) { cntA++; }
	}

	for (int i = 0; i < 5; i++)
	{
		if (B[i] < t) { cntB++; }
	}

	if (cntA > cntB) { printArr(A); printArr(B); }
	else { printArr(B); printArr(A); }
}

void printArr(const int* Arr)
{
	std::cout << "[";

	for (int i = 0; i < 5; i++)
	{
		std::cout << Arr[i];
		if (i != 4) { std::cout << ", "; }
	}

	std::cout << "]\n";
}
