#include "pch.h"
#include "CppUnitTest.h"
#include "..\list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LR1UT
{
	TEST_CLASS(LR1UT)
	{
	public:
		
		TEST_METHOD(TestPushBack)
		{
			list l;
			l.pushBack("temp 1");
			Assert::IsTrue(l.at(1) == "temp 1"); // Testing how pushBack works if the list initially was empty

			l.pushBack("temp 2");
			Assert::IsTrue(l.at(2) == "temp 2"); // Testing how pushBack works if the list initially had only 1 element

			l.pushBack("temp 3");
			Assert::IsTrue(l.at(3) == "temp 3"); // Testing how pushBack works if the list initially had more than 1 element
		}

		TEST_METHOD(TestPushFront)
		{
			list l;
			l.pushFront("temp 3");
			Assert::IsTrue(l.at(1) == "temp 3"); // Testing how pushFront works if the list initially was empty

			l.pushFront("temp 2");
			Assert::IsTrue(l.at(1) == "temp 2"); // Testing how pushFront works if the list initially had only 1 element

			l.pushFront("temp 1");
			Assert::IsTrue(l.at(1) == "temp 1"); // Testing how pushFront works if the list initially had more than 1 element
		}

		TEST_METHOD(TestPopBack)
		{
			list l;
			l.pushBack("temp 1");
			l.popBack();
			Assert::IsTrue(l.isEmpty()); // Testing how popBack works if the list initially had only 1 element

			l.clear();
			l.pushBack("temp 2");
			l.pushFront("temp 1");
			l.popBack();
			Assert::IsTrue(l.getSize() == 1 && l.at(1) == "temp 1"); // Testing how popBack works if the list initially had 2 elements

			l.clear();
			l.pushBack("temp 1");
			l.pushBack("temp 2");
			l.pushBack("temp 3");
			l.popBack();
			Assert::IsTrue(l.getSize() == 2 && l.at(2) == "temp 2"); // Testing how popBack works if the list initially had more than 2 elements
		}

		TEST_METHOD(TestPopFront)
		{
			list l;
			l.pushFront("temp 1");
			l.popFront();
			Assert::IsTrue(l.isEmpty()); // Testing how popFront works if the list initially had only 1 element

			l.clear();
			l.pushBack("temp 2");
			l.pushFront("temp 1");
			l.popFront();
			Assert::IsTrue(l.getSize() == 1 && l.at(1) == "temp 2"); // Testing how popFront works if the list initially had 2 elements

			l.clear();
			l.pushBack("temp 3");
			l.pushFront("temp 2");
			l.pushFront("temp 1");
			l.popFront();
			Assert::IsTrue(l.getSize() == 2 && l.at(1) == "temp 2"); // Testing how popFront works if the list initially had more than 2 elements
		}

		TEST_METHOD(TestAt)
		{
			// Creating a list of 3 elements
			list l;
			l.pushBack("temp 1");
			l.pushBack("temp 2");
			l.pushBack("temp 3");

			Assert::IsTrue(l.at(1) == "temp 1" && l.at(2) == "temp 2" && l.at(3) == "temp 3"); // Testing if method 'at' works as intended
		}

		TEST_METHOD(TestInsert)
		{
			// Creating a list of 3 elements
			list l;
			l.pushBack("temp 1");
			l.pushBack("temp 2");
			l.pushBack("temp 3");
			
			l.insert("insert", 3); // Inserting a new element before the 3rd element of the initial list
			Assert::IsTrue(l.at(3) == "insert"); // Testing if method 'insert' works as intended
		}

		TEST_METHOD(TestRemove)
		{
			// Creating a list of 3 elements
			list l;
			l.pushBack("temp 1");
			l.pushBack("temp 2");
			l.pushBack("temp 3");

			l.insert("insert", 3); // Inserting a new element before the 3rd element of the initial list
			l.remove(3); // Removing an element we just inserted
			Assert::IsTrue(l.at(3) == "temp 3"); // Testing if method 'remove' works as intended
		}

		TEST_METHOD(TestGetSize)
		{
			list l;
			for (int i = 1; i <= 7; i++) // Creating a list of 7 elements		
				l.insert("t" + std::to_string(i), i);
			
			Assert::IsTrue(l.getSize() == 7); // Testing if method 'getSize' works as intended
		}

		TEST_METHOD(TestIsEmpty)
		{
			list l;
			l.pushFront("1"); // Adding an element to the front
			l.pushBack("2"); // Adding an element to the back
			Assert::IsTrue(!l.isEmpty()); // If everything worked correctly then 'l' isn't empty and the condition will be met
			l.popFront(); // Removing the first element
			l.popBack(); // Removing the remaining element
			Assert::IsTrue(l.isEmpty()); // If everything worked correctly then 'l' is empty and the condition will be met
		}

		TEST_METHOD(TestClear)
		{
			list l;
			for (int i = 1; i <= 7; i++) // Creating a list of 7 elements			
				l.insert("t" + std::to_string(i), i);

			// If our 'clear' worked then our list should be empty
			l.clear();
			Assert::IsTrue(l.isEmpty());
		}

		TEST_METHOD(TestSet)
		{
			// Creating a list of 3 elements
			list l;
			l.pushBack("temp 1");
			l.pushBack("temp 2");
			l.pushBack("temp 3");

			l.set("new thing", 2); // Changing the second element
			Assert::IsTrue(l.at(2) == "new thing"); // Testing if method 'set' works as intended
		}

		// Testing inserting a sublist at the start of the main list
		TEST_METHOD(TestInsertSubList1)
		{
			list l1, l2;

			l1.pushFront("1 t1");
			l2.pushFront("2 t1");
			l1.insertSubList(l2, 0);
			Assert::IsTrue(l1.getSize() == 2 && l1.at(1) == "2 t1" && l1.at(2) == "1 t1"); // Testing how the function works when we insert one 1-element list at the start of another 1-element list

			l1.clear();
			l2.clear();
			l1.pushFront("1 t1");
			l1.pushBack("1 t2");
			l2.pushFront("2 t1");
			l1.insertSubList(l2, 0);
			Assert::IsTrue(l1.getSize() == 3 && l1.at(1) == "2 t1" && l1.at(3) == "1 t2"); // Testing how the function works when we insert a 1-element list at the start of a 2-element list

			l1.clear();
			l2.clear();
			l2.pushFront("2 t1");
			l2.pushBack("2 t2");
			l1.pushFront("1 t1");
			l1.insertSubList(l2, 0);
			Assert::IsTrue(l1.getSize() == 3 && l1.at(1) == "2 t1" && l1.at(3) == "1 t1"); // Testing how the function works when we insert a 2-element list at the start of a 1-element list

			l1.clear();
			l2.clear();
			l1.pushFront("1 t1");
			l1.pushBack("1 t2");
			l2.pushFront("2 t1");
			l2.pushBack("2 t2");
			l1.insertSubList(l2, 0);
			Assert::IsTrue(l1.getSize() == 4 && l1.at(1) == "2 t1" && l1.at(4) == "1 t2"); // Testing how the function works when we insert one 2-element list at the start of another 2-element list

		}
		// Testing inserting a sublist in the middle of the main list
		TEST_METHOD(TestInsertSubList2)
		{
			list l1, l2;

			l1.pushFront("1 t1");
			l1.pushBack("1 t2");
			l2.pushFront("2 t1");
			l1.insertSubList(l2, 1);
			Assert::IsTrue(l1.getSize() == 3 && l1.at(2) == "2 t1"); // Testing how the function works when we insert a 1-element list in the middle of a 2-element list

			l1.clear();
			l2.clear();
			l1.pushFront("1 t1");
			l1.pushBack("1 t2");
			l2.pushFront("2 t1");
			l2.pushBack("2 t2");
			l1.insertSubList(l2, 1);
			Assert::IsTrue(l1.getSize() == 4 && l1.at(2) == "2 t1" && l1.at(3) == "2 t2"); // Testing how the function works when we insert one 2-element list in the middle of another 2-element list
		}
		// Testing inserting a sublist at the end of the main list
		TEST_METHOD(TestInsertSubList3)
		{
			list l1, l2;

			l1.pushFront("1 t1");
			l2.pushFront("2 t1");
			l1.insertSubList(l2, 1);
			Assert::IsTrue(l1.getSize() == 2 && l1.at(1) == "1 t1" && l1.at(2) == "2 t1"); // Testing how the function works when we insert one 1-element list at the end of another 1-element list

			l1.clear();
			l2.clear();
			l1.pushFront("1 t1");
			l1.pushBack("1 t2");
			l2.pushFront("2 t1");
			l1.insertSubList(l2, 2);
			Assert::IsTrue(l1.getSize() == 3 && l1.at(1) == "1 t1" && l1.at(3) == "2 t1"); // Testing how the function works when we insert a 1-element list at the end of a 2-element list

			l1.clear();
			l2.clear();
			l2.pushFront("2 t1");
			l2.pushBack("2 t2");
			l1.pushFront("1 t1");
			l1.insertSubList(l2, 1);
			Assert::IsTrue(l1.getSize() == 3 && l1.at(1) == "1 t1" && l1.at(3) == "2 t2"); // Testing how the function works when we insert a 2-element list at the end of a 1-element list

			l1.clear();
			l2.clear();
			l1.pushFront("1 t1");
			l1.pushBack("1 t2");
			l2.pushFront("2 t1");
			l2.pushBack("2 t2");
			l1.insertSubList(l2, 2);
			Assert::IsTrue(l1.getSize() == 4 && l1.at(1) == "1 t1" && l1.at(4) == "2 t2"); // Testing how the function works when we insert one 2-element list at the end of another 2-element list
		}
	};
}
