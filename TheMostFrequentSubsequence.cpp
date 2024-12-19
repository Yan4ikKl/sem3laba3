#include "TheMostFrequentSubsequences.h"
#include "Dictionary.h"

#include <string>

Dictionary<Key_Value> theMostFrequentSubsequences(std::string input, int lmin, int lmax)
{
	Dictionary<Key_Value> result;
	for (int i = 0; i < input.length(); i++)
	{
		for (int j = lmin; j <= lmax; j++)
		{
			if (i + j <= input.length())
			{
				std::string word = input.substr(i, j);
				if (result.containsKey(word) == true)
				{
					result.changeValue(word, result.getValue(word) + 1);
				}
				else
				{
					result.add(word, 1);
				}
			}
		}
	}
	return result;
}
