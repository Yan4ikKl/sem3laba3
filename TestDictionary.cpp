#include "TestDictionary.h"
#include "Dictionary.h"

#include <cassert>

void TestDictionary::allTests()
{
	testConstructor();
	testGetCount();
	testGetValue();
	testContainsKey();
	testAdd();
	testRemove();
}
void TestDictionary::testConstructor()
{
	Dictionary<Key_Value> testDict;
	assert(testDict.getCount() == 0);
}
void TestDictionary::testGetCount()
{
	Dictionary<Key_Value> testDict1;
	assert(testDict1.getCount() == 0);

	Dictionary<Key_Value> testDict2;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "capasity";
	int value1 = 34;
	int value2 = 12;
	int value3 = 89;
	testDict2.add(key1, value1);
	testDict2.add(key2, value2);
	testDict2.add(key3, value3);
	assert(testDict2.getCount() == 3);
}
void TestDictionary::testGetValue()
{
	Dictionary<Key_Value> testDict;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "capasity";
	int value1 = 34;
	int value2 = 12;
	int value3 = 89;
	testDict.add(key1, value1);
	testDict.add(key2, value2);
	testDict.add(key3, value3);
	assert(testDict.getValue(key1) == value1);
	assert(testDict.getValue(key2) == value2);
	assert(testDict.getValue(key3) == value3);
}
void TestDictionary::testContainsKey()
{
	Dictionary<Key_Value> testDict;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "capasity";
	int value1 = 34;
	int value2 = 12;
	int value3 = 89;
	testDict.add(key1, value1);
	testDict.add(key2, value2);
	testDict.add(key3, value3);
	std::string testString = "father";
	assert(testDict.containsKey(key1) == true);
	assert(testDict.containsKey(key2) == true);
	assert(testDict.containsKey(key3) == true);
	assert(testDict.containsKey(testString) == false);
}
void TestDictionary::testAdd()
{
	Dictionary<Key_Value> testDict;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "capasity";
	int value1 = 34;
	int value2 = 12;
	int value3 = 89;
	testDict.add(key1, value1);
	testDict.add(key2, value2);
	testDict.add(key3, value3);
	assert(testDict.getCount() == 3);
	assert(testDict.containsKey(key1) == true);
	assert(testDict.containsKey(key2) == true);
	assert(testDict.containsKey(key3) == true);
}
void TestDictionary::testRemove()
{
	Dictionary<Key_Value> testDict;
	std::string key1 = "autumn";
	std::string key2 = "winter";
	std::string key3 = "capasity";
	int value1 = 34;
	int value2 = 12;
	int value3 = 89;
	testDict.add(key1, value1);
	testDict.add(key2, value2);
	testDict.add(key3, value3);
	testDict.remove(key1);
	assert(testDict.getCount() == 2);
	assert(testDict.containsKey(key1) == false);
}
