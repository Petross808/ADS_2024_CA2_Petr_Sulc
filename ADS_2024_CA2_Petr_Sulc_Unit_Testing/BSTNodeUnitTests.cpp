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
			static std::wstring ToString<BSTNode<int>>(const BSTNode<int>& t)
			{ 
				return L"BSTNode<int> value";
			}

			template<>
			static std::wstring ToString<BSTNode<int>>(const BSTNode<int>* t)
			{
				return L"BSTNode<int> const pointer";
			}

			template<>
			static std::wstring ToString<BSTNode<int>>(BSTNode<int>* t)
			{
				return L"BSTNode<int> pointer";
			}
		}
	}
}

namespace BSTNodeUnitTests
{
	TEST_CLASS(BSTNodeTestClass)
	{
	public:

		TEST_METHOD(EmptyConstructorTest)
		{
			BSTNode<int> node;
			Assert::AreEqual(node.getItem(), 0);
			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());
			Assert::IsNull(node.getParent());
		}

		TEST_METHOD(SetItem1Test)
		{
			int value = 135;
			BSTNode<int> node;

			node.setItem(value);
			Assert::AreEqual(node.getItem(), value);
		}

		TEST_METHOD(SetItem2Test)
		{
			int value = 0;
			BSTNode<int> node;

			node.setItem(value);
			Assert::AreEqual(node.getItem(), value);
		}

		TEST_METHOD(SetItem3Test)
		{
			int value = -356;
			BSTNode<int> node;

			node.setItem(value);
			Assert::AreEqual(node.getItem(), value);
		}

		TEST_METHOD(SetLeftTest)
		{
			BSTNode<int> node;
			BSTNode<int>* node2 = new BSTNode<int>();

			node.setLeft(node2);
			Assert::AreSame(*node.getLeft(), *node2);
		}

		TEST_METHOD(SetRightTest)
		{
			BSTNode<int> node;
			BSTNode<int>* node2 = new BSTNode<int>();

			node.setRight(node2);
			Assert::AreSame(*node.getRight(), *node2);
		}

		TEST_METHOD(DataParentConstructorTest)
		{
			int value = 135;
			BSTNode<int>* node2 = new BSTNode<int>();
			BSTNode<int> node(value, node2);

			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());
			Assert::AreEqual(node.getItem(), value);
			Assert::AreSame(*node.getParent(), *node2);
		}

		TEST_METHOD(AddLowerTest)
		{
			int value = -456;
			BSTNode<int> node;

			node.add(value);
			Assert::AreEqual(node.getLeft()->getItem(), value);
			Assert::IsNull(node.getRight());
		}

		TEST_METHOD(AddSameTest)
		{
			int value = 0;
			BSTNode<int> node;

			node.add(value);
			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());
		}

		TEST_METHOD(AddBiggerTest)
		{
			int value = 135;
			BSTNode<int> node;

			node.add(value);
			Assert::AreEqual(node.getRight()->getItem(), value);
			Assert::IsNull(node.getLeft());
		}

		TEST_METHOD(CountEmptyTest)
		{
			BSTNode<int> node;
			Assert::AreEqual(node.count(), 1);
		}

		TEST_METHOD(Count1Test)
		{
			int value = 135;
			BSTNode<int> node;

			node.add(value);
			Assert::AreEqual(node.count(), 2);
		}

		TEST_METHOD(Count2Test)
		{
			int value1 = 135;
			int value2 = 16;
			BSTNode<int> node;

			node.add(value1);
			node.add(value2);
			Assert::AreEqual(node.count(), 3);
		}

		TEST_METHOD(Count3Test)
		{
			int value1 = 135;
			int value2 = 16;
			int value3 = -35;
			BSTNode<int> node;

			node.add(value1);
			node.add(value2);
			node.add(value3);
			Assert::AreEqual(node.count(), 4);
		}

		TEST_METHOD(CopyConstructorTest)
		{
			int value1 = 135;
			int value2 = 16;
			int value3 = -35;
			BSTNode<int> node;

			node.add(value1);
			node.add(value2);
			node.add(value3);

			BSTNode<int> node2(node);

			Assert::AreEqual(node.count(), node2.count());
			Assert::AreSame(*node.getRight()->getLeft()->getParent()->getParent(), node);
		}

		TEST_METHOD(AssignmentOverloadTest)
		{
			int value1 = 135;
			int value2 = 16;
			int value3 = -35;
			BSTNode<int> node;
			BSTNode<int> node2;

			node.add(value1);
			node.add(value2);
			node.add(value3);

			node2 = node;

			Assert::AreNotSame(node, node2);
			Assert::AreEqual(node.count(), node2.count());
			Assert::AreSame(*node.getRight()->getLeft()->getParent()->getParent(), node);
		}

		TEST_METHOD(AssignmentOverloadSameTest)
		{
			int value1 = 135;
			int value2 = 16;
			int value3 = -35;
			BSTNode<int> node;

			node.add(value1);
			node.add(value2);
			node.add(value3);

			node = node;

			Assert::AreSame(node, node);
		}
	};
}
