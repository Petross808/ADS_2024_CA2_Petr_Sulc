#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2024_CA2_Petr_Sulc/BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<>
			static std::wstring ToString<BinaryTree<int>>(const BinaryTree<int>& t)
			{
				return L"BinaryTree<int> value";
			}

			template<>
			static std::wstring ToString<BinaryTree<int>>(const BinaryTree<int>* t)
			{
				return L"BinaryTree<int> const pointer";
			}

			template<>
			static std::wstring ToString<BinaryTree<int>>(BinaryTree<int>* t)
			{
				return L"BinaryTree<int> pointer";
			}
		}
	}
}

namespace BinaryTreeUnitTests
{
	TEST_CLASS(BinaryTreeTestClass)
	{
	public:

		TEST_METHOD(EmptyConstructorTest)
		{
			BinaryTree<int> tree;
			Assert::IsNull(tree.root);
		}

		TEST_METHOD(AddWhenEmptyTest)
		{
			int a = 5;
			BinaryTree<int> tree;
			tree.add(a);
			Assert::AreEqual(tree.root->getItem(), a);
		}

		TEST_METHOD(AddNotEmptyTest)
		{
			int a = 5;
			int b = 8;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			Assert::AreEqual(tree.count(), 2);
			Assert::AreEqual(tree.root->getItem(), a);
			Assert::AreEqual(tree.root->getRight()->getItem(), b);
		}

		TEST_METHOD(AddExistingTest)
		{
			int a = 5;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(a);
			Assert::AreEqual(tree.count(), 1);
			Assert::AreEqual(tree.root->getItem(), a);
		}

		TEST_METHOD(CountEmptyTest)
		{
			BinaryTree<int> tree;
			Assert::AreEqual(tree.count(), 0);
		}

		TEST_METHOD(Count1Test)
		{
			BinaryTree<int> tree;
			tree.root = new BSTNode<int>(1, nullptr);
			Assert::AreEqual(tree.count(), 1);
		}

		TEST_METHOD(Count2Test)
		{
			int a = 5;
			int b = 8;
			int c = 6;
			int d = 7;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			Assert::AreEqual(tree.count(), 4);
		}

		TEST_METHOD(ClearEmptyTest)
		{
			BinaryTree<int> tree;
			tree.clear();
			Assert::IsNull(tree.root);
		}

		TEST_METHOD(ClearTest)
		{
			int a = 5;
			int b = 8;
			int c = 6;
			int d = 7;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);

			tree.clear();
			Assert::IsNull(tree.root);
		}

		TEST_METHOD(GetExisitingTest)
		{
			int a = 5;
			int b = 8;
			int c = 6;
			int d = 7;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			
			BSTNode<int>* found = tree.get(d);

			Assert::AreEqual(d, found->getItem());
		}

		TEST_METHOD(GetNonExisitingTest)
		{
			int a = 5;
			int b = 8;
			int c = 6;
			int d = 7;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);

			BSTNode<int>* found = tree.get(d);

			Assert::IsNull(found);
		}

		TEST_METHOD(RemoveEmptyTest)
		{
			int a = 5;
			BinaryTree<int> tree;

			bool removed = tree.remove(a);

			Assert::IsFalse(removed);
			Assert::AreEqual(0, tree.count());
		}

		TEST_METHOD(RemoveNonExistingTest)
		{
			int a = 5;
			int b = 8;
			int c = 6;
			int d = 7;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);

			bool removed = tree.remove(d);

			Assert::IsFalse(removed);
			Assert::AreEqual(3, tree.count());
		}

		TEST_METHOD(RemoveExistingNoChildrenTest)
		{
			int a = 5;
			int b = 8;
			int c = 6;
			int d = 7;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);

			bool removed = tree.remove(d);
			int* arr = tree.toArray();

			Assert::IsTrue(removed);
			Assert::AreEqual(3, tree.count());
			Assert::AreEqual(5, arr[0]);
			Assert::AreEqual(6, arr[1]);
			Assert::AreEqual(8, arr[2]);
		}

		TEST_METHOD(RemoveExistingOneChildTest)
		{
			int a = 5;
			int b = 3;
			int c = 7;
			int d = 8;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);

			bool removed = tree.remove(c);
			int* arr = tree.toArray();

			Assert::IsTrue(removed);
			Assert::AreEqual(3, tree.count());
			Assert::AreEqual(3, arr[0]);
			Assert::AreEqual(5, arr[1]);
			Assert::AreEqual(8, arr[2]);
		}

		TEST_METHOD(RemoveExistingTwoChildrenTest)
		{
			int a = 5;
			int b = 7;
			int c = 6;
			int d = 8;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);

			bool removed = tree.remove(b);
			int* arr = tree.toArray();

			Assert::IsTrue(removed);
			Assert::AreEqual(3, tree.count());
			Assert::AreEqual(5, arr[0]);
			Assert::AreEqual(6, arr[1]);
			Assert::AreEqual(8, arr[2]);
		}

		TEST_METHOD(RemoveExistingComplexTest)
		{
			int a = 5;
			int b = 3;
			int c = 9;
			int d = 7;
			int e = 11;
			int f = 6;
			int g = 8;
			int h = 10;
			int i = 12;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);
			tree.add(f);
			tree.add(g);
			tree.add(h);
			tree.add(i);

			bool removed = tree.remove(c);
			int* arr = tree.toArray();

			Assert::IsTrue(removed);
			Assert::AreEqual(8, tree.count());
			Assert::AreEqual(3, arr[0]);
			Assert::AreEqual(5, arr[1]);
			Assert::AreEqual(6, arr[2]);
			Assert::AreEqual(7, arr[3]);
			Assert::AreEqual(8, arr[4]);
			Assert::AreEqual(10, arr[5]);
			Assert::AreEqual(11, arr[6]);
			Assert::AreEqual(12, arr[7]);
		}

		TEST_METHOD(RemoveExistingComplex2Test)
		{
			int a = 5;
			int b = 9;
			int c = 7;
			int d = 11;
			int e = 8;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);

			bool removed = tree.remove(a);
			int* arr = tree.toArray();

			Assert::IsTrue(removed);
			Assert::AreEqual(4, tree.count());
			Assert::AreEqual(7, arr[0]);
			Assert::AreEqual(8, arr[1]);
			Assert::AreEqual(9, arr[2]);
			Assert::AreEqual(11, arr[3]);
		}

		TEST_METHOD(RemoveRootOneChildTest)
		{
			int a = 5;
			int b = 3;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);


			bool removed = tree.remove(a);
			int* arr = tree.toArray();

			Assert::IsTrue(removed);
			Assert::AreEqual(1, tree.count());
			Assert::AreEqual(3, arr[0]);
		}

		TEST_METHOD(RemoveRootNoChildrenTest)
		{
			int a = 5;
			BinaryTree<int> tree;
			tree.add(a);


			bool removed = tree.remove(a);

			Assert::IsTrue(removed);
			Assert::AreEqual(0, tree.count());
			Assert::IsNull(tree.root);
		}


		TEST_METHOD(CopyConstructorTest)
		{
			int value1 = 135;
			int value2 = 16;
			int value3 = -35;
			BinaryTree<int> tree;

			tree.add(value1);
			tree.add(value2);
			tree.add(value3);

			BinaryTree<int> tree2(tree);

			Assert::AreEqual(tree.count(), tree2.count());
		}

		TEST_METHOD(AssignmentOverloadTest)
		{
			int value1 = 135;
			int value2 = 16;
			int value3 = -35;
			BinaryTree<int> tree;
			BinaryTree<int> tree2;

			tree.add(value1);
			tree.add(value2);
			tree.add(value3);

			tree2 = tree;

			Assert::AreNotSame(tree, tree2);
			Assert::AreEqual(tree.count(), tree2.count());
		}

		TEST_METHOD(AssignmentOverloadSameTest)
		{
			int value1 = 135;
			int value2 = 16;
			int value3 = -35;
			BinaryTree<int> tree;

			tree.add(value1);
			tree.add(value2);
			tree.add(value3);

			tree = tree;

			Assert::AreSame(tree, tree);
		}

		TEST_METHOD(ToArrayTest)
		{
			int a = 5;
			int b = 8;
			int c = 6;
			int d = 7;
			int e = 9;
			int f = 3;
			int g = 4;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);
			tree.add(f);
			tree.add(g);

			int* arr = tree.toArray();

			Assert::AreEqual(3, arr[0]);
			Assert::AreEqual(4, arr[1]);
			Assert::AreEqual(5, arr[2]);
			Assert::AreEqual(6, arr[3]);
			Assert::AreEqual(7, arr[4]);
			Assert::AreEqual(8, arr[5]);
			Assert::AreEqual(9, arr[6]);
		}

		TEST_METHOD(ToArrayPreOrderTest)
		{
			int a = 5;
			int b = 8;
			int c = 6;
			int d = 7;
			int e = 9;
			int f = 3;
			int g = 4;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);
			tree.add(f);
			tree.add(g);

			int* arr = tree.toArrayPreOrder();

			Assert::AreEqual(5, arr[0]);
			Assert::AreEqual(3, arr[1]);
			Assert::AreEqual(4, arr[2]);
			Assert::AreEqual(8, arr[3]);
			Assert::AreEqual(6, arr[4]);
			Assert::AreEqual(7, arr[5]);
			Assert::AreEqual(9, arr[6]);
		}

		TEST_METHOD(ToArrayEmptyTest)
		{

			BinaryTree<int> tree;


			int* arr = tree.toArray();

			Assert::IsNull(arr);
		}

		TEST_METHOD(PrintInOrderTest)
		{
			int a = 5;
			int b = 8;
			int c = 6;
			int d = 7;
			int e = 9;
			int f = 3;
			int g = 4;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);
			tree.add(f);
			tree.add(g);

			stringstream ss;
			tree.printInOrder(ss);

			string output = ss.str();
			string expected = "3 4 5 6 7 8 9 \n";

			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PrintPreOrderTest)
		{
			int a = 5;
			int b = 8;
			int c = 6;
			int d = 7;
			int e = 9;
			int f = 3;
			int g = 4;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);
			tree.add(f);
			tree.add(g);

			stringstream ss;
			tree.printPreOrder(ss);

			string output = ss.str();
			string expected = "5 3 4 8 6 7 9 \n";

			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PrintPostOrderTest)
		{
			int a = 5;
			int b = 8;
			int c = 6;
			int d = 7;
			int e = 9;
			int f = 3;
			int g = 4;
			BinaryTree<int> tree;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);
			tree.add(f);
			tree.add(g);

			stringstream ss;
			tree.printPostOrder(ss);

			string output = ss.str();
			string expected = "4 3 7 6 9 8 5 \n";

			Assert::AreEqual(expected, output);
		}
	};

}
