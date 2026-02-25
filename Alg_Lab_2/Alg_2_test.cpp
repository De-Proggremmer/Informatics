#include "pch.h"
#include "CppUnitTest.h"

#include "../Alg_2/Alg_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Alg2test
{
	TEST_CLASS(Alg2test)
	{
	public:
		
		TEST_METHOD(AccuracyTest_2)
		{
			double result = abs(simpson_rule(function_A, 3, 6, 2) - simpson_rule(function_B, 3, 6, 2));
			Assert::AreEqual(result, 187.50000, 0);
		}
		TEST_METHOD(AccuracyTest_4)
		{
			double result = abs(simpson_rule(function_A, 3, 6, 4) - simpson_rule(function_B, 3, 6, 4));
			Assert::AreEqual(result, 187.50000, 1);
		}
		TEST_METHOD(AccuracyTest_8)
		{
			double result = abs(simpson_rule(function_A, 3, 6, 8) - simpson_rule(function_B, 3, 6, 8));
			Assert::AreEqual(result, 187.50000, 2);
		}
		TEST_METHOD(AccuracyTest_16)
		{
			double result = abs(simpson_rule(function_A, 3, 6, 16) - simpson_rule(function_B, 3, 6, 16));
			Assert::AreEqual(result, 187.50000, 3);
		}
		TEST_METHOD(AccuracyTest_32)
		{
			double result = abs(simpson_rule(function_A, 3, 6, 32) - simpson_rule(function_B, 3, 6, 32));
			Assert::AreEqual(result, 187.5000, 4);
		}
		TEST_METHOD(AccuracyTest_64)
		{
			double result = abs(simpson_rule(function_A, 3, 6, 64) - simpson_rule(function_B, 3, 6, 64));
			Assert::AreEqual(result, 187.5000, 5);
		}
	};
}
