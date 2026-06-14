#include "pch.h"
#include "CppUnitTest.h"

#include <vector>
#include <algorithm>

#include "../HW3/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace SortingTests
{
    // ---------------- bubble_sort -----------------------
    TEST_CLASS(BubbleSortTests)
    {
    public:

        TEST_METHOD(EmptyArray)
        {
            vector<int> arr = {};
            vector<int> expected = {};
            bubble_sort(arr);
            Assert::IsTrue(arr == expected);
        }

        TEST_METHOD(SingleElement)
        {
            vector<int> arr = { 42 };
            vector<int> expected = { 42 };
            bubble_sort(arr);
            Assert::IsTrue(arr == expected);
        }

        TEST_METHOD(MultiElement)
        {
            vector<int> arr = { 5, 3, 8, 1, 2 };
            vector<int> expected = { 1, 2, 3, 5, 8 };
            bubble_sort(arr);
            Assert::IsTrue(arr == expected);
        }
    };

    // ------------------ radix_sort -------------------
    TEST_CLASS(RadixSortTests)
    {
    public:

        TEST_METHOD(EmptyArray)
        {
            vector<int> arr = {};
            vector<int> expected = {};
            radix_sort(arr);
            Assert::IsTrue(arr == expected);
        }

        TEST_METHOD(SingleElement)
        {
            vector<int> arr = { 7 };
            vector<int> expected = { 7 };
            radix_sort(arr);
            Assert::IsTrue(arr == expected);
        }

        TEST_METHOD(MultiElement)
        {
            vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
            vector<int> expected = { 2, 24, 45, 66, 75, 90, 170, 802 };
            radix_sort(arr);
            Assert::IsTrue(arr == expected);
        }
    };

    // ---------------------- Тесты для quick_sort ----------------------
    TEST_CLASS(QuickSortTests)
    {
    public:

        TEST_METHOD(EmptyArray)
        {
            vector<int> arr = {};
            vector<int> expected = {};
            quick_sort(arr, 0, arr.size()-1);
            Assert::IsTrue(arr == expected);
        }

        TEST_METHOD(SingleElement)
        {
            vector<int> arr = { 100 };
            vector<int> expected = { 100 };
            quick_sort(arr, 0, arr.size() - 1);
            Assert::IsTrue(arr == expected);
        }

        TEST_METHOD(MultiElement)
        {
            vector<int> arr = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 6 };
            vector<int> expected = { 2, 3, 5, 6, 7, 9, 10, 11, 12, 14 };
            quick_sort(arr, 0, arr.size() - 1);
            Assert::IsTrue(arr == expected);
        }
    };
}
