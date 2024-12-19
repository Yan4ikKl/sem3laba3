#include "TestTheMostFrequentSequences.h"
#include "TheMostFrequentSubsequences.h"
#include "Dictionary.h"

#include <string>
#include <cassert>

void TestTheMostFrequentSequences::allTests()
{
	test1();
}
void TestTheMostFrequentSequences::test1()
{
	std::string testString = "ababab";
	int lmin = 2;
	int lmax = 3;
	Dictionary<Key_Value> result = theMostFrequentSubsequences(testString, lmin, lmax);
	assert(result.get(0).getKey() == "ab");
	assert(result.get(0).getValue() == 3);
	assert(result.get(1).getKey() == "aba");
	assert(result.get(1).getValue() == 2);
	assert(result.get(2).getKey() == "ba");
	assert(result.get(2).getValue() == 2);
	assert(result.get(3).getKey() == "bab");
	assert(result.get(3).getValue() == 2);

}