#include "SortedSequence.h"
#include "TestSortedSequence.h"

#include <cassert>
#include <string>

void TestSortedSequence::allTests()
{
	testConstructors();
	testGetLength();
	testIsEmpty();
	testGet();
	testGetFirst();
	testGetLast();
	testGetIndexOfKey();
	testGetIndexOfValue();
	testGetSubsequence();
	testAdd();
	testGetKeys();
	testGetValues();
}
void TestSortedSequence::testConstructors()
{
	SortedSequence<Key_Value> testSequence;
	assert(testSequence.getLength() == 0);
}
void TestSortedSequence::testGetLength()
{
	SortedSequence<Key_Value> testSequence1;
	assert(testSequence1.getLength() == 0);

	SortedSequence<Key_Value> testSequence2;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "cat";
	int value1 = 3;
	int value2 = 34;
	int value3 = 56;
	testSequence2.add(key1, value1);
	testSequence2.add(key2, value2);
	testSequence2.add(key3, value3);
	assert(testSequence2.getLength() == 3);
}
void TestSortedSequence::testIsEmpty()
{
	SortedSequence<Key_Value> testSequence1;
	assert(testSequence1.getIsEmpty() == 1);

	SortedSequence<Key_Value> testSequence2;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "cat";
	int value1 = 3;
	int value2 = 34;
	int value3 = 56;
	testSequence2.add(key1, value1);
	testSequence2.add(key2, value2);
	testSequence2.add(key3, value3);
	assert(testSequence2.getIsEmpty() == false);
}
void TestSortedSequence::testGet()
{
	SortedSequence<Key_Value> testSequence;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "cat";
	int value1 = 3;
	int value2 = 34;
	int value3 = 56;
	testSequence.add(key1, value1);
	testSequence.add(key2, value2);
	testSequence.add(key3, value3);
	int index1 = 0;
	int index2 = 1;
	int index3 = 2;
	assert(testSequence.get(index1).getValue() == 3);
	assert(testSequence.get(index1).getKey() == "autumn");
	assert(testSequence.get(index2).getValue() == 56);
	assert(testSequence.get(index2).getKey() == "cat");
	assert(testSequence.get(index3).getValue() == 34);
	assert(testSequence.get(index3).getKey() == "winter");
}
void TestSortedSequence::testGetFirst()
{
	SortedSequence<Key_Value> testSequence;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "cat";
	int value1 = 3;
	int value2 = 34;
	int value3 = 56;
	testSequence.add(key1, value1);
	testSequence.add(key2, value2);
	testSequence.add(key3, value3);
	assert(testSequence.getFirst().getKey() == "autumn");
	assert(testSequence.getFirst().getValue() == 3);
}
void TestSortedSequence::testGetLast()
{
	SortedSequence<Key_Value> testSequence;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "cat";
	int value1 = 3;
	int value2 = 34;
	int value3 = 56;
	testSequence.add(key1, value1);
	testSequence.add(key2, value2);
	testSequence.add(key3, value3);
	assert(testSequence.getLast().getKey() == "winter");
	assert(testSequence.getLast().getValue() == 34);
}
void TestSortedSequence::testGetIndexOfKey()
{
	SortedSequence<Key_Value> testSequence;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "cat";
	int value1 = 3;
	int value2 = 34;
	int value3 = 56;
	testSequence.add(key1, value1);
	testSequence.add(key2, value2);
	testSequence.add(key3, value3);
	assert(testSequence.indexOfKey(key1) == 0);
	assert(testSequence.indexOfKey(key2) == 2);
	assert(testSequence.indexOfKey(key3) == 1);
}
void TestSortedSequence::testGetIndexOfValue()
{
	SortedSequence<Key_Value> testSequence;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "cat";
	int value1 = 3;
	int value2 = 34;
	int value3 = 56;
	testSequence.add(key1, value1);
	testSequence.add(key2, value2);
	testSequence.add(key3, value3);
	assert(testSequence.indexOfValue(value1) == 0);
	assert(testSequence.indexOfValue(value2) == 2);
	assert(testSequence.indexOfValue(value3) == 1);
}
void TestSortedSequence::testGetSubsequence()
{
	SortedSequence<Key_Value> testSequence;
	std::string key1 = "house";
	std::string key2 = "home";
	std::string key3 = "autumn";
	std::string key4 = "hope";
	std::string key5 = "mouse";
	std::string key6 = "wolf";
	std::string key7 = "winter";
	std::string key8 = "bike";
	std::string key9 = "summer";
	std::string key10 = "clock";
	int value1 = 3; 
	int value2 = 34;
	int value3 = 56;
	int value4 = 24;
	int value5 = 12;
	int value6 = 78;
	int value7 = 56;
	int value8 = 5;
	int value9 = 67;
	int value10 = 56;
	testSequence.add(key1, value1);
	testSequence.add(key2, value2);
	testSequence.add(key3, value3);
	testSequence.add(key4, value4);
	testSequence.add(key5, value5);
	testSequence.add(key6, value6);
	testSequence.add(key7, value7);
	testSequence.add(key8, value8);
	testSequence.add(key9, value9);
	testSequence.add(key10, value10);
	int index1 = 2; 
	int index2 = 6;
	SortedSequence<Key_Value> result = testSequence.getSubsequence(index1, index2);
	assert(result.getLength() == 5);
	assert(result.get(0).getKey() == "clock");
	assert(result.get(1).getKey() == "home");
	assert(result.get(2).getKey() == "hope");
	assert(result.get(3).getKey() == "house");
	assert(result.get(4).getKey() == "mouse");
	assert(result.get(0).getValue() == 56);
	assert(result.get(1).getValue() == 34);
	assert(result.get(2).getValue() == 24);
	assert(result.get(3).getValue() == 3);
	assert(result.get(4).getValue() == 12);
}
void TestSortedSequence::testAdd()
{
	SortedSequence<Key_Value> testSequence;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "cat";
	int value1 = 3;
	int value2 = 34;
	int value3 = 56;
	testSequence.add(key1, value1);
	testSequence.add(key2, value2);
	testSequence.add(key3, value3);
	assert(testSequence.get(0).getKey() == "autumn");
	assert(testSequence.get(1).getKey() == "cat");
	assert(testSequence.get(2).getKey() == "winter");
	assert(testSequence.get(0).getValue() == 3);
	assert(testSequence.get(1).getValue() == 56);
	assert(testSequence.get(2).getValue() == 34);
}
void TestSortedSequence::testGetKeys()
{
	SortedSequence<Key_Value> testSequence;
	std::string key1 = "house";
	std::string key2 = "home";
	std::string key3 = "autumn";
	std::string key4 = "hope";
	std::string key5 = "mouse";
	std::string key6 = "wolf";
	std::string key7 = "winter";
	std::string key8 = "bike";
	std::string key9 = "summer";
	std::string key10 = "clock";
	int value1 = 3;
	int value2 = 34;
	int value3 = 56;
	int value4 = 24;
	int value5 = 12;
	int value6 = 78;
	int value7 = 58;
	int value8 = 5;
	int value9 = 67;
	int value10 = 56;
	testSequence.add(key1, value1);
	testSequence.add(key2, value2);
	testSequence.add(key3, value3);
	testSequence.add(key4, value4);
	testSequence.add(key5, value5);
	testSequence.add(key6, value6);
	testSequence.add(key7, value7);
	testSequence.add(key8, value8);
	testSequence.add(key9, value9);
	testSequence.add(key10, value10);
	DynamicArray<std::string> result = testSequence.getKeys();
	assert(result.getSize() == 10);
	assert(result.get(0) == "autumn");
	assert(result.get(1) == "bike");
	assert(result.get(2) == "clock");
	assert(result.get(3) == "home");
	assert(result.get(4) == "hope");
	assert(result.get(5) == "house");
	assert(result.get(6) == "mouse");
	assert(result.get(7) == "summer");
	assert(result.get(8) == "winter");
	assert(result.get(9) == "wolf");
}
void TestSortedSequence::testGetValues()
{
	SortedSequence<Key_Value> testSequence;
	std::string key1 = "house";
	std::string key2 = "home";
	std::string key3 = "autumn";
	std::string key4 = "hope";
	std::string key5 = "mouse";
	std::string key6 = "wolf";
	std::string key7 = "winter";
	std::string key8 = "bike";
	std::string key9 = "summer";
	std::string key10 = "clock";
	int value1 = 3;
	int value2 = 34;
	int value3 = 56;
	int value4 = 24;
	int value5 = 12;
	int value6 = 78;
	int value7 = 58;
	int value8 = 5;
	int value9 = 67;
	int value10 = 56;
	testSequence.add(key1, value1);
	testSequence.add(key2, value2);
	testSequence.add(key3, value3);
	testSequence.add(key4, value4);
	testSequence.add(key5, value5);
	testSequence.add(key6, value6);
	testSequence.add(key7, value7);
	testSequence.add(key8, value8);
	testSequence.add(key9, value9);
	testSequence.add(key10, value10);
	DynamicArray<int> result = testSequence.getValues();
	assert(result.get(0) == 56);
	assert(result.get(1) == 5);
	assert(result.get(2) == 56);
	assert(result.get(3) == 34);
	assert(result.get(4) == 24);
	assert(result.get(5) == 3);
	assert(result.get(6) == 12);
	assert(result.get(7) == 67);
	assert(result.get(8) == 58);
	assert(result.get(9) == 78);
}