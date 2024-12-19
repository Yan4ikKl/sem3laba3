#include "Test.h"
#include "TestSortedSequence.h"
#include "TestAlphabeticalIndex.h"
#include "TestTheMostFrequentSequences.h"
#include "TestDictionary.h"

void Test::allTests()
{
	testSortedSequence();
	testAlphabeticalIndex();
	testTheMostFrequentSequences();
	testDictionary();
}
void Test::testSortedSequence()
{
	TestSortedSequence testSortedSequence;
	testSortedSequence.allTests();
}
void Test::testAlphabeticalIndex()
{
	TestAlphabeticalIndex testAlphabeticalIndex;
	testAlphabeticalIndex.allTests();
}
void Test::testTheMostFrequentSequences()
{
	TestTheMostFrequentSequences testTheMostFrequentSequences;
	testTheMostFrequentSequences.allTests();
}
void Test::testDictionary()
{
	TestDictionary testDictionary;
	testDictionary.allTests();
}