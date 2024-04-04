#include "pch.h"
#include "CppUnitTest.h"
#include "../StaticLibSet/Set.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StaticLibSetTest
{
	TEST_CLASS(StaticLibSetTest)
	{
	public:
		
		//Unite test
		TEST_METHOD(TestMethod1)
		{
			Set<int> set1 = { 1, 2, 3, 4, 5 };
			Set<int> set2 = { 4, 5, 6, 7, 8 };
			Set<int> set3 = set1.unite(set2);
			Assert::IsTrue(set3.size() == 8);
			Assert::IsTrue(set3.contains(1));
			Assert::IsTrue(set3.contains(2));
			Assert::IsTrue(set3.contains(3));
			Assert::IsTrue(set3.contains(4));
			Assert::IsTrue(set3.contains(5));
			Assert::IsTrue(set3.contains(6));
			Assert::IsTrue(set3.contains(7));
			Assert::IsTrue(set3.contains(8));
		}

		//Intersect test
		TEST_METHOD(TestMethod2)
		{
			Set<int> set1 = { 1, 2, 3, 4, 5 };
			Set<int> set2 = { 4, 5, 6, 7, 8 };
			Set<int> set3 = set1.intersect(set2);
			Assert::IsTrue(set3.size() == 2);
			Assert::IsTrue(set3.contains(4));
			Assert::IsTrue(set3.contains(5));
		}

		//Subtract test
		TEST_METHOD(TestMethod3)
		{
			Set<int> set1 = { 1, 2, 3, 4, 5 };
			Set<int> set2 = { 4, 5, 6, 7, 8 };
			Set<int> set3 = set1.subtract(set2);
			Assert::IsTrue(set3.size() == 3);
			Assert::IsTrue(set3.contains(1));
			Assert::IsTrue(set3.contains(2));
			Assert::IsTrue(set3.contains(3));
		}

		//Add test
		TEST_METHOD(TestMethod4)
		{
			Set<int> set1 = { 1, 2, 3, 4, 5 };
			set1.add(6);
			Assert::IsTrue(set1.size() == 6);
			Assert::IsTrue(set1.contains(6));
		}

		//Remove test
		TEST_METHOD(TestMethod5)
		{
			Set<int> set1 = { 1, 2, 3, 4, 5 };
			set1.remove(5);
			Assert::IsTrue(set1.size() == 4);
			Assert::IsTrue(!set1.contains(5));
		}

		//Contains test
		TEST_METHOD(TestMethod6)
		{
			Set<int> set1 = { 1, 2, 3, 4, 5 };
			Assert::IsTrue(set1.contains(5));
			Assert::IsTrue(!set1.contains(6));
		}

		//Size test
		TEST_METHOD(TestMethod7)
		{
			Set<int> set1 = { 1, 2, 3, 4, 5 };
			Assert::IsTrue(set1.size() == 5);
		}

		//Output test
		TEST_METHOD(TestMethod8)
		{
			Set<int> set1 = { 1, 2, 3, 4, 5 };
			std::stringstream ss;
			ss << set1;
			Assert::AreEqual(ss.str().c_str(), "{1, 2, 3, 4, 5}");
		}

		//Copy constructor test
		TEST_METHOD(TestMethod9)
		{
			Set<int> set1 = { 1, 2, 3, 4, 5 };
			Set<int> set2 = set1;
			Assert::IsTrue(set2.size() == 5);
			Assert::IsTrue(set2.contains(1));
			Assert::IsTrue(set2.contains(2));
			Assert::IsTrue(set2.contains(3));
			Assert::IsTrue(set2.contains(4));
			Assert::IsTrue(set2.contains(5));
		}

		//Move constructor test
		TEST_METHOD(TestMethod10)
		{
			Set<int> set1 = { 1, 2, 3, 4, 5 };
			Set<int> set2 = std::move(set1);
			Assert::IsTrue(set2.size() == 5);
			Assert::IsTrue(set2.contains(1));
			Assert::IsTrue(set2.contains(2));
			Assert::IsTrue(set2.contains(3));
			Assert::IsTrue(set2.contains(4));
			Assert::IsTrue(set2.contains(5));
		}

	};
}
