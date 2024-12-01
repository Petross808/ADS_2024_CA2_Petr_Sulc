#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2024_CA2_Petr_Sulc/TreeMap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<>
			static std::wstring ToString<TreeMap<int, string>>(const TreeMap<int, string>& t)
			{
				return L"TreeMap<int, string> value";
			}

			template<>
			static std::wstring ToString<TreeMap<int, string>>(const TreeMap<int, string>* t)
			{
				return L"TreeMap<int, string> const pointer";
			}

			template<>
			static std::wstring ToString<TreeMap<int, string>>(TreeMap<int, string>* t)
			{
				return L"TreeMap<int, string> pointer";
			}
		}
	}
}

namespace TreeMapUnitTests
{
	TEST_CLASS(TreeMapTestClass)
	{
	public:
		TEST_METHOD(PutTest)
		{
			TreeMap<int, string> map;
			map.put(1, "test");
			
			string actual = map.get(1);
			string expected = "test";

			Assert::AreEqual(1, map.size());
			Assert::AreEqual(expected, actual);
		}
		
		TEST_METHOD(PutExistingTest)
		{
			TreeMap<int, string> map;
			map.put(1, "test");
			map.put(1, "test2");

			string actual = map.get(1);
			string expected = "test";

			Assert::AreEqual(1, map.size());
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetExistTest)
		{
			TreeMap<int, string> map;
			map.put(1, "test");

			string actual = map.get(1);
			string expected = "test";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetNonExistTest)
		{
			TreeMap<int, string> map;
			map.put(1, "test");

			string actual = map.get(2);
			string expected = "";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetEmptyTest)
		{
			TreeMap<int, string> map;

			string actual = map.get(2);
			string expected = "";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SizeEmptyTest)
		{
			TreeMap<int, string> map;

			Assert::AreEqual(0, map.size());
		}

		TEST_METHOD(Size1Test)
		{
			TreeMap<int, string> map;
			map.put(1, "test");

			Assert::AreEqual(1, map.size());
		}

		TEST_METHOD(Size2Test)
		{
			TreeMap<int, string> map;
			map.put(1, "test");
			map.put(2, "test2");

			Assert::AreEqual(2, map.size());
		}

		TEST_METHOD(Size3Test)
		{
			TreeMap<int, string> map;
			map.put(1, "test");
			map.put(2, "test2");
			map.put(3, "test3");

			Assert::AreEqual(3, map.size());
		}

		TEST_METHOD(ContainsKeyTrueTest)
		{
			TreeMap<int, string> map;
			map.put(5, "test");

			Assert::IsTrue(map.containsKey(5));
		}

		TEST_METHOD(ContainsKeyFalseTest)
		{
			TreeMap<int, string> map;
			map.put(5, "test");

			Assert::IsFalse(map.containsKey(3));
		}

		TEST_METHOD(ContainsKeyEmptyTest)
		{
			TreeMap<int, string> map;

			Assert::IsFalse(map.containsKey(5));
		}

		TEST_METHOD(ClearFullTest)
		{
			TreeMap<int, string> map;
			map.put(1, "test");
			map.put(2, "test");
			map.put(3, "test");
			map.put(4, "test");
			map.put(5, "test");
			map.put(6, "test");
			
			map.clear();

			Assert::AreEqual(0, map.size());
		}

		TEST_METHOD(ClearEmptyTest)
		{
			TreeMap<int, string> map;
			map.clear();

			Assert::AreEqual(0, map.size());
		}

		TEST_METHOD(KeySetTest)
		{
			TreeMap<int, string> map;
			map.put(5, "test");
			map.put(2, "test");
			map.put(4, "test");
			map.put(6, "test");
			map.put(1, "test");
			map.put(7, "test");
			map.put(3, "test");

			int* arr = map.keySet().toArray();

			Assert::AreEqual(1, arr[0]);
			Assert::AreEqual(2, arr[1]);
			Assert::AreEqual(3, arr[2]);
			Assert::AreEqual(4, arr[3]);
			Assert::AreEqual(5, arr[4]);
			Assert::AreEqual(6, arr[5]);
			Assert::AreEqual(7, arr[6]);
		}

		TEST_METHOD(KeySetEmptyTest)
		{
			TreeMap<int, string> map;

			int* arr = map.keySet().toArray();

			Assert::IsNull(arr);
		}

		TEST_METHOD(RemoveKeyExistsTest)
		{
			TreeMap<int, string> map;
			map.put(5, "test");
			map.put(2, "test");
			map.put(4, "test");
			map.put(6, "test");
			map.put(1, "test");
			map.put(7, "test");
			map.put(3, "test");

			bool removed = map.removeKey(5);

			int* arr = map.keySet().toArray();

			Assert::IsTrue(removed);
			Assert::AreEqual(6, map.size());
			Assert::AreEqual(1, arr[0]);
			Assert::AreEqual(2, arr[1]);
			Assert::AreEqual(3, arr[2]);
			Assert::AreEqual(4, arr[3]);
			Assert::AreEqual(6, arr[4]);
			Assert::AreEqual(7, arr[5]);
		}

		TEST_METHOD(RemoveKeyNonExistsTest)
		{
			TreeMap<int, string> map;
			map.put(5, "test");
			map.put(2, "test");
			map.put(4, "test");
			map.put(6, "test");
			map.put(1, "test");
			map.put(7, "test");
			map.put(3, "test");

			bool removed = map.removeKey(9);

			int* arr = map.keySet().toArray();

			Assert::IsFalse(removed);
			Assert::AreEqual(7, map.size());
			Assert::AreEqual(1, arr[0]);
			Assert::AreEqual(2, arr[1]);
			Assert::AreEqual(3, arr[2]);
			Assert::AreEqual(4, arr[3]);
			Assert::AreEqual(5, arr[4]);
			Assert::AreEqual(6, arr[5]);
			Assert::AreEqual(7, arr[6]);
		}

		TEST_METHOD(RemoveKeyEmptyTest)
		{
			TreeMap<int, string> map;

			bool removed = map.removeKey(8);

			Assert::AreEqual(0, map.size());
			Assert::IsFalse(removed);
		}

		TEST_METHOD(SquareBracketOperatorExistsTest)
		{
			TreeMap<int, string> map;
			map.put(5, "test1");
			map.put(2, "test2");
			map.put(4, "test3");
			map.put(6, "test4");
			map.put(1, "test5");
			map.put(7, "test6");
			map.put(3, "test7");

			string actual = map[6];
			string expected = "test4";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SquareBracketOperatorNonExistsTest)
		{
			TreeMap<int, string> map;
			map.put(5, "test1");
			map.put(2, "test2");
			map.put(4, "test3");
			map.put(6, "test4");
			map.put(1, "test5");
			map.put(7, "test6");
			map.put(3, "test7");

			string actual = map[9];
			string expected = "";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SquareBracketOperatorEmptyTest)
		{
			TreeMap<int, string> map;

			string actual = map[6];
			string expected = "";

			Assert::AreEqual(expected, actual);
		}

	};
}
