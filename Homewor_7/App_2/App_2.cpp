#include <iostream>
#include <set>
#include <algorithm>

void diff_set(std::set<int>* A, std::set<int>* B);
void printSet(std::set<int>* Set);

int main()
{
	std::set<int>* A = new std::set<int>, * B = new std::set<int>;

	int N;
	std::cout << "Enter lenth A: ";
	std::cin >> N;
	std::cout << "Enter set A elements: ";
	for (int i = 0; i < N; i++)
	{
		int a;
		std::cin >> a;
		A->insert(a);
	}

	std::cout << "Enter lenth B: ";
	std::cin >> N;
	std::cout << "Enter set B elements: ";
	for (int i = 0; i < N; i++)
	{
		int b;
		std::cin >> b;
		B->insert(b);
	}

	diff_set(A, B);

	delete A;
	delete B;

	return 0;
}

void diff_set(std::set<int>* A, std::set<int>* B)
{
	std::set<int>* C = new std::set<int>;

	std::set_difference(B->begin(), B->end(), A->begin(), A->end(), std::inserter(*C, C->end()));

	for (auto i = C->begin(); i != C->end(); i++)
	{
		if (*i >= 0) { C->erase(i); }
	}

	printSet(C);

	delete C;
}

void printSet(std::set<int>* Set)
{
	std::cout << "{";

	for (auto i = Set->begin(); i != Set->end(); i++)
	{
		std::cout << *i;
		if (std::next(i) != Set->end()) { std::cout << ", "; }
	}

	std::cout << "}\n";
}