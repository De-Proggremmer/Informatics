#include "pch.h"
#include "CppUnitTest.h"
#include "../Practice_1/Practice_1.cpp"

#include <map>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestp1
{
	TEST_CLASS(TimeTest)
	{
	public:
		
		TEST_METHOD(TestOperationTime_1)
		{
			std::map<int, int> dict;
			Assert::IsTrue(measure_execution_time(add_to_dict, dict, 10).second < std::pow(10, 2));
		}
		TEST_METHOD(TestOperationTime_2)
		{
			std::map<int, int> dict;
			Assert::IsTrue(measure_execution_time(add_to_dict, dict, 100).second < std::pow(10, 4));
		}
		TEST_METHOD(TestOperationTime_3)
		{
			std::map<int, int> dict;
			Assert::IsTrue(measure_execution_time(add_to_dict, dict, 1000).second < std::pow(10, 6));
		}
		TEST_METHOD(TestOperationTime_4)
		{
			std::map<int, int> dict;
			Assert::IsTrue(measure_execution_time(add_to_dict, dict, 10000).second < std::pow(10, 8));
		}
		TEST_METHOD(TestOperationTime_5)
		{
			std::map<int, int> dict;
			Assert::IsTrue(measure_execution_time(add_to_dict, dict, 100000).second < std::pow(10, 10));
		}
		TEST_METHOD(TestOperationTime_6)
		{
			std::map<int, int> dict;
			Assert::IsTrue(measure_execution_time(add_to_dict, dict, 1000000).second < std::pow(10, 12));
		}
		TEST_METHOD(TestOperationTime_7)
		{
			std::map<int, int> dict;
			Assert::IsTrue(measure_execution_time(add_to_dict, dict, 10000000).second < std::pow(10, 14));
		}
	};
}
